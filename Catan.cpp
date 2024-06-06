#include "Catan.hpp"
using namespace std;
namespace ariel
{
    Catan::Catan(Player &p1, Player &p2, Player &p3)
    {
        players.push_back(p1);
        players.push_back(p2);
        players.push_back(p3);
        sort(players.begin(), players.end(), [](const Player &a, const Player &b) { // sort players by age using lambda
            return a.getAge() < b.getAge();
        });
        currentPlayer = 0;
        players[0].setColor(Consts::RED);
        players[1].setColor(Consts::BLUE);
        players[2].setColor(Consts::ORANGE);
        initDevelopmentCards();
    }
    void Catan::ChooseStartingPlayer()
    {
        cout << "The starting player is: " << players[0].getName() << endl;
        this->currentPlayer = 0;
    }
    const Board &Catan::getBoard()
    {
        return board;
    }
    void Catan::printBoard(size_t mode)
    {
        board.printBoard(mode);
    }

    void Catan::buildFirstRound()
    {
        for (size_t i = 0; i < 3; i++)
        {
            buildFirstRoundHelper(i);
        }
        for(size_t i = 2; i>=0;i--)
        {
            buildFirstRoundHelper(i);
        }
        for(size_t i = 2; i<=12;i++){
            collectResources(i);
        }
    }
    void Catan::buildFirstRoundHelper(size_t i){
         cout << players[i].getName() << " choose a location for your first settlement" << endl;
            board.printBoard(Consts::BUILD_SETTLEMENT);
            size_t id;
            bool first = true;
            bool notValid = true;
            while (cin.fail() || notValid)
            {
                cin.clear();
                if(!first){
                    cin.ignore(1000, '\n');
                    cout << "Invalid input, please enter a valid id" << endl;
                }
                cin >> id;
                first = false;
                try
                {
                    notValid = !board.checkValidLocation(id, Consts::BUILD_SETTLEMENT, &players[i],true);
                    
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            board.placeSettlement(id, &players[i]);
            players[i].buySettlement(id, true);
            cout << players[i].getName() << " choose a location for your first road" << endl;
            board.printBoard(Consts::BUILD_ROAD);
            
            notValid = true;
            first = true;
            while (cin.fail() || notValid)
            {
                cin.clear();
                if(!first){
                    cin.ignore(1000, '\n');
                    cout << "Invalid input, please enter a valid id" << endl;
                }
                cin >> id;
                first = false;
                try
                {
                    notValid = !board.checkValidLocation(id, Consts::BUILD_ROAD, &players[i],true);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            board.placeRoad(id, &players[i]);
            players[i].buyRoad(id, true);
    }

    void Catan::PlayGame()
    {
        ChooseStartingPlayer();
        cout << "The game has started" << endl;
        buildFirstRound();
        while (!checkWin())
        {
            playRound();
        }
    }

    Player &Catan::getPlayer(size_t index)
    {
        if (index < 0 || index > 2)
            throw invalid_argument("Index must be between 0 and 2");
        return players[index];
    }
    bool Catan::checkWin()
    {
        for (Player p : players)
        {
            if (p.getVictoryPoints() >= 10)
            {
                cout << "The winner is: " << p.getName() << std::endl;
                return true;
            }
        }
        return false;
    }
    const Player &Catan::getCurrentPlayer()
    {
        return players[currentPlayer];
    }

    void Catan::initDevelopmentCards()
    {
        for (int i = 0; i < 3; i++)
        {
            developmentCards.push_back(new Knight());
        }
        for (int i = 0; i < 2; i++)
        {
            developmentCards.push_back(new Monopoly());
            developmentCards.push_back(new RoadBuilding());
            developmentCards.push_back(new YearOfPlenty());
        }
        for (int i = 0; i < 5; i++)
        {
            developmentCards.push_back(new VictoryPoint());
        }
        shuffleVector(developmentCards);
        cardCounter = 0;
    }

    Catan::~Catan()
    {
        for (size_t i = 0; i < developmentCards.size(); i++)
        {
            delete developmentCards[i];
        }
    }

    void Catan::roolDice()
    {
        size_t dice1 = (size_t)(rand() % 6 + 1);
        size_t dice2 = (size_t)(rand() % 6 + 1);
        size_t sum = dice1 + dice2;
        cout << "You rolled " << sum << endl;
        if (sum == 7)
            rolledSeven();
        else
        {
            collectResources(sum);
        }
    }
    void Catan::collectResources(size_t diceRoll){
        vector<char> tilesId = Consts::resourceTiles.at(diceRoll);
            for (char id : tilesId)
            {
                Tile *tile = board.getTile(id);
                vector<size_t> settlements = tile->getSettelments();
                for (size_t i : settlements)
                {
                    Settlement *settlement = board.getSettlement(i);
                    if (settlement->getOwner() != nullptr)
                    {
                        settlement->getOwner()->addResource(Consts::getResourceIndex(tile->getResource()), settlement->getValue());
                    }
                }
            }
    }
    void Catan::rolledSeven()
    {
        string choice;
        for (Player p : players)
        {
            if (p.getNumResources() > 7)
            {
                cout << p.getName() << " you have more than 7 resources, you need to discard half of them" << endl;
                size_t numToDiscard = p.getNumResources() / 2;
                cout << "You need to choose " << numToDiscard << " resources to discard" << endl;
                cout << "Enter a vector of the resources you want to discard, in the following order: BRICK WOOD WHEAT SHEEP ORE " << endl;
                cin >> choice;
                vector<size_t> resources;
                bool validChoice = false;
                while (choice.size() != 5 && validChoice)
                {
                    try
                    {
                        cin >> choice;
                        resources = Consts::parseResource(choice); // would handle the exception
                        size_t sum = 0;
                        for (size_t i : resources)
                        {
                            sum += i;
                        }
                        if (sum != numToDiscard)
                        {
                            cout << "You need to discard exactly " << numToDiscard << " resources" << endl;
                        }
                        else if (p.getResources()[Consts::BRICK] < resources[Consts::BRICK] || p.getResources()[Consts::WOOD] < resources[Consts::WOOD] || p.getResources()[Consts::WHEAT] < resources[Consts::WHEAT] || p.getResources()[Consts::SHEEP] < resources[Consts::SHEEP] || p.getResources()[Consts::ORE] < resources[Consts::ORE])
                        {
                            cout << "You don't have enough resources to discard" << endl;
                        }
                        else
                        {
                            for (size_t i = 0; i < 5; i++)
                            {
                                p.removeResource(i, resources[i]);
                            }
                            validChoice = true;
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }
            }
        }
    }

    void Catan::playRound()
    {
        bool end = false;
        roolDice();
        while (!end)
        {
            end = getPlayerInput();
        }
    }

    bool Catan::getPlayerInput()
    {
        cout << "It's " << players[currentPlayer].getName() << "'s turn" << endl;
        cout << "Choose an action:" << endl;
        cout << "1. Build" << endl;
        cout << "2. Trade" << endl;
        cout << "3. Buy Development Card" << endl;
        cout << "4. Play Development Card" << endl;
        cout << "5. End Turn" << endl;
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 5 || cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            build();
            return false;
        case 2:
            trade();
            return false;
        case 3:
            buyDevelopmentCard();
            return false;
        case 4:
            playDevelopmentCard();
            return false;
        case 5:
            endTurn();
            return true;
        default:
            return false;
        }
    }

    void Catan::build()
    {
        cout << "Choose an action:" << endl;
        cout << "1. Place Settlement" << endl;
        cout << "2. Place City" << endl;
        cout << "3. Place Road" << endl;
        cout << "4. Back" << endl;
        int choice;
        cin >> choice;
        size_t id;
        while (choice < 1 || choice > 4 || cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            board.printBoard(Consts::BUILD_SETTLEMENT);
            cout << "Enter the id of the settlement you want to build" << endl;
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            try
            {
                bool hasResources = players[currentPlayer].canBuySettelement();
                if (hasResources)
                { // the actual placement of the settlement is done in the board class
                    if (board.checkValidLocation(id, Consts::BUILD_SETTLEMENT, &players[currentPlayer]))
                    {
                        board.placeSettlement(id, &players[currentPlayer]);
                        players[currentPlayer].buySettlement(id);
                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 2:
            board.printBoard(Consts::BUILD_CITY);
            cout << "Enter the id of the city you want to build" << endl;
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            try
            {
                bool hasResources = players[currentPlayer].canBuyCity();
                if (hasResources)
                { // the actual placement of the city is done in the board class
                    if (board.checkValidLocation(id, Consts::BUILD_CITY, &players[currentPlayer]))
                    {
                        board.placeCity(id, &players[currentPlayer]);
                        players[currentPlayer].buyCity(id);
                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 3:
            board.printBoard(Consts::BUILD_ROAD);
            cout << "Enter the id of the road you want to build" << endl;
            cin >> id;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            try
            {
                bool hasResources = players[currentPlayer].canBuyRoad();
                if (hasResources)
                { // the actual placement of the road is done in the board class
                    if (board.checkValidLocation(id, Consts::BUILD_ROAD, &players[currentPlayer]))
                    {
                        board.placeRoad(id, &players[currentPlayer]);
                        players[currentPlayer].buyRoad(id);
                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            cout << "Returning to main menu" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    void Catan::buyDevelopmentCard()
    { // TODO
        if (cardCounter == developmentCards.size())
        {
            cout << "No more development cards" << endl;
            return;
        }
        if (players[currentPlayer].canBuyDevelopmentCard() == false)
        {
            return;
        }
        players[currentPlayer].buyDevelopmentCard(developmentCards[cardCounter++]);
    }
    void Catan::playDevelopmentCard()
    {
        players[currentPlayer].printDevelopmentCards();
        cout << "Enter the index of the card you want to play" << endl;
        size_t index;
        cin >> index;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        if (index < 0 || index >= players[currentPlayer].getDevelopmentCards().size())
        {
            cout << "Invalid id" << endl;
            return;
        }
        try
        {
            players[currentPlayer].getDevelopmentCards()[index]->useCard(players[currentPlayer], *this);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    void Catan::trade()
    { // TODO
        cout << "Choose an action:" << endl;
        cout << "1. Trade resources with player" << endl;
        cout << "2. Trade development cards with player" << endl;
        cout << "3. Back" << endl;
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 3 || cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            tradeResources();
            break;
        case 2:
            tradeDevelopmentCards();
            break;
        case 3:
            cout << "Returning to main menu" << endl;
            break;
        }
    }

    void Catan::endTurn()
    {
        currentPlayer = (currentPlayer + 1) % 3;
    }
    void Catan::shuffleVector(std::vector<DevelopmentCard *> &vec)
    {
        // Obtain a time-based seed:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));
    }
    void Catan::tradeResources()
    {
        cout << "Enter the name of the player you want to trade with" << endl;
        string name;
        cin >> name;
        Player *player = nullptr;
        for (Player p : players)
        {
            if (p.getName() == name)
            {
                player = &p;
                break;
            }
        }
        if (player == nullptr)
        {
            cout << "Player not found" << endl;
            return;
        }
        if (player == &players[currentPlayer])
        {
            cout << "You can't trade with yourself" << endl;
            return;
        }
        cout << "You have the following resources: " << endl;
        players[currentPlayer].printResources();
        cout << "Enter the resources you want to get, in the following order: BRICK WOOD WHEAT SHEEP ORE" << endl;
        string resources;
        cin >> resources;
        vector<size_t> resourcesToGet;
        try
        {
            resourcesToGet = Consts::parseResource(resources);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        cout << player->getName() << " You have the following resources: " << endl;
        player->printResources();
        cout << "Enter the resources you want to get, in the following order: BRICK WOOD WHEAT SHEEP ORE" << endl;
        cin >> resources;
        vector<size_t> resourcesToGive;
        try
        {
            resourcesToGive = Consts::parseResource(resources);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        cout << "Press 1 to confirm the trade, any other key to cancel" << endl;
        int confirm;
        cin >> confirm;
        if (confirm != 1)
        {
            cout << "Trade canceled" << endl;
            return;
        }
        try
        {
            players[currentPlayer].tradeResources(player, resourcesToGive, resourcesToGet);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

    void Catan::tradeDevelopmentCards()
    {
        cout << "Enter the name of the player you want to trade with" << endl;
        string name;
        cin >> name;
        Player *player = nullptr;
        for (Player p : players)
        {
            if (p.getName() == name)
            {
                player = &p;
                break;
            }
        }
        if (player == nullptr)
        {
            cout << "Player not found" << endl;
            return;
        }
        if (player == &players[currentPlayer])
        {
            cout << "You can't trade with yourself" << endl;
            return;
        }
        cout << "You have the following development cards: " << endl;
        players[currentPlayer].printDevelopmentCards();
        cout << "Enter the vector of the cards you want to get in the following order: Knight VictoryPoint RoadsBuilding Monopoly YearOfPlenty" << endl;
        string choice;
        cin >> choice;
        vector<size_t> cardsToGive;
        try
        {
            cardsToGive = Consts::parseResource(choice);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }

        cout << player->getName() << " You have the following development cards: " << endl;
        player->printDevelopmentCards();
        cout << "Enter the vector of the cards you want to get in the following order: Knight VictoryPoint RoadsBuilding Monopoly YearOfPlenty" << endl;
        cin >> choice;
        vector<size_t> cardsToGet;
        try
        {
            cardsToGet = Consts::parseResource(choice);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        cout << "Press 1 to confirm the trade, any other key to cancel" << endl;
        int confirm;
        cin >> confirm;
        if (confirm != 1)
        {
            cout << "Trade canceled" << endl;
            return;
        }
        try
        {
            players[currentPlayer].tradeDevelopmentCards(player, cardsToGive, cardsToGet);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

} // namespace ariel
