#include "Catan.hpp"
using namespace std;
namespace ariel
{  
    /**
     * @brief Construct a new Catan:: Catan object
     * @param p the players
     * The constructor initializes the game with the players, the board and the development cards, and sorts the players by age
     */
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
    /**
     * @brief Choose the starting player
     * The function chooses the starting player by lookiong at the players sorted by age and choosing the first one
     * The function prints the starting player
     * The function sets the current player to be the starting player
     */
    void Catan::ChooseStartingPlayer()
    {
        cout << "The starting player is: " << players[0].getName() << endl;
        this->currentPlayer = 0;
    }

    /**
     * @brief Get the Board object
     * @return const Board& the board
     */
    const Board &Catan::getBoard()
    {
        return board;
    }

    /**
     * @brief Print the board
     * @param mode the mode to print the board in
     */
    void Catan::printBoard(size_t mode)
    {
        board.printBoard(mode, &players[currentPlayer]);
    }

/**
 * @brief Playing the first round of the game, where each player need to choose 2 locations for a settlement and a road
 */
    void Catan::buildFirstRound()
    {
        for (size_t i = 0; i < 3; i++)
        {
            buildFirstRoundHelper(i); // each player chooses a location for a settlement and a road, start from the youngest player
        }
        for(int i = 2; i>=0;i--)
        {
            buildFirstRoundHelper((size_t)i); // each player chooses a location for a settlement and a road, then start from the oldest player
        }
        cout<< "finished first build round"<<endl;
        board.printBoard(Consts::REGULAR, &players[currentPlayer]); 
        for(size_t i = 2; i<=12;i++){
            collectResources(i); // collect resources for each player
        }
    }
    /**
     * @brief Helper function for the first round, where each player chooses a location for a settlement and a road
     * @param i the index of the player 
     * The function prints the board and asks the player to choose a location for a settlement and a road
     * The function checks if the location is valid and places the settlement and the road on the board
     * The function places the settlement and the road for the player
     */
    void Catan::buildFirstRoundHelper(size_t i){
         cout << players[i].getName() << " choose a location for your first settlement" << endl;
            board.printBoard(Consts::BUILD_SETTLEMENT, &players[i]);
            size_t id;
            bool first = true;
            bool notValid = true;
            while (cin.fail() || notValid) //while the settelment is not valid, ask the player to choose again
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
                    notValid = !board.checkValidLocation(id, Consts::BUILD_SETTLEMENT, &players[i],true); // check if the location is valid, if not, ask the player to choose again A flag is used to indicate that this is the first round, so that the
                    // function will not check if the player has a road nearby, and will not check if the player has enough resources
                    
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            board.placeSettlement(id, &players[i]); // place the settlement on the board
            players[i].buySettlement(id, true);// buy the settlement, a flag is used to indicate that this is the first round, so that the function will not check if the player has enough resources
            cout << players[i].getName() << " choose a location for your first road" << endl;
            board.printBoard(Consts::BUILD_ROAD, &players[i]);
            
            notValid = true;
            first = true;
            while (cin.fail() || notValid) // same as above, but for the road
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
                    notValid = !board.checkValidLocation(id, Consts::BUILD_ROAD, &players[i],true); // check if the location is valid, if not, ask the player to choose again. A flag is used to indicate that this is the first round, so that the
                    // function will not check if the player enough resources
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            board.placeRoad(id, &players[i]); // place the road on the board
            players[i].buyRoad(id, true); // buy the road, a flag is used to indicate that this is the first round, so that the function will not check if the player has enough resources
    }


/**
 * @brief Play the game, this is the main function that runs the game
 * This is the only public function in the class, and it is called from the main when the game starts
 * The function chooses the starting player, plays the first round, and then plays the game until a player wins, or until one of the players quits
 * The function prints the winner when the game ends
 * The function catches exceptions that are thrown during the game
 */
    void Catan::PlayGame()
    {
        ChooseStartingPlayer(); // choose the starting player
        cout << "The game has started" << endl;
        buildFirstRound(); // play the first round
        while (!checkWin()) // while no player has won, play a round
        {
            try{
            playRound(); // play a round
            }
            catch(const std::exception &e){
                std::cerr << e.what() << '\n';
                return;
            }
        }
    }

/**
 * @brief Get the player object
 * @param index the index of the player
 * @return Player& the player
 * @throw invalid_argument if the index is invalid
 */
    Player &Catan::getPlayer(size_t index)
    {
        if (index < 0 || index > 2)
            throw invalid_argument("Index must be between 0 and 2");
        return players[index];
    }

/**
 * @brief Check if a player has won the game
 * @return true if a player has won, false otherwise
 * The function goes through all the players and checks if any of them has 10 or more victory points
 * If a player has won, the function prints the winner
    */
    bool Catan::checkWin()
    {
        for (Player p : players) // go through all the players
        {
            if (p.getVictoryPoints() >= 10) // if a player has 10 or more victory points, print the winner and return true
            {
                cout << "The winner is: " << p.getName() << std::endl;
                return true;
            }
        }
        return false;
    }
    /**
     * @brief Get the current player
     * @return const Player& the current player
     */
    const Player &Catan::getCurrentPlayer()
    {
        return players[currentPlayer];
    }


/**
 * @brief Initialize the development cards and shuffle them, then sets the drawed card counter to 0 .The function is called in the constructor
 */
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
/**
 * @brief Destroy the Catan:: Catan object
 * The destructor deletes all the development cards
 */
    Catan::~Catan()
    {
        for (size_t i = 0; i < developmentCards.size(); i++)
        {
            delete developmentCards[i];
        }
    }

/**
 * @brief Roll the dice and collect resources, if the sum is 7, the function calls rolledSeven(). 
 * Notice that for now, in order to be able to test well, no seed is used for the random function, can be added later if needed.
 */

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
    /**
     * @brief Collect resources for each player, based on the dice roll
     * @param diceRoll the sum of the dice roll
     * The function goes through all the tiles and checks if the dice roll matches the number on the tile
     */
    void Catan::collectResources(size_t diceRoll){
        if(diceRoll == 7){ //If the dice roll is 7, the function does not collect resources
            return;
        }
        vector<char> tilesId = Consts::resourceTiles.at(diceRoll);// get the tiles that produce resources for the dice roll, using the map in Consts
            for (char id : tilesId) // go through all the tiles that produce resources for the dice roll
            {
                Tile *tile = board.getTile(id); // get the tile
                vector<size_t> settlements = tile->getSettelments();// get the settlements on the tile
                
                for (size_t i : settlements) // go through all the settlements on the tile
                {
                    Settlement *settlement = board.getSettlement(i); // get the settlement
                    if (settlement->getOwner() != nullptr) // if the settlement has an owner, give the owner the resources. 
                    {
                        cout<< "Player "<< settlement->getOwner()->getName() << " got " << settlement->getValue() << " " << tile->getResourceType() << endl; // print the resources the player got
                        cout<< "Current resource: "<< Consts::getResourceIndex(tile->getResourceType()) << endl;
                        settlement->getOwner()->addResource(Consts::getResourceIndex(tile->getResourceType()), settlement->getValue());// add the resources to the player
                    }
                }
            }
    }

    /**
     * @brief If the sum of the dice roll is 7, the function is called. The function goes through all the players and checks if any of them has more than 7 resources. If a player has more than 7 resources, the function asks the player to discard half of them
     * The function goes through all the resources and asks the player to choose the resources to discard, and then discards them
     */
    void Catan::rolledSeven()
    {
        string choice;
        string choice1;
        string choice2;
        string choice3;
        string choice4;
        string choice5;
        for (size_t i = 0;i<Consts::NUM_OF_PLAYERS;i++) // go through all the players
        {
            Player &p = players[i];
            if (p.getNumResources() > 7)// if a player has more than 7 resources, ask the player to discard half of them
            {
                cout << p.getName() << " you have more than 7 resources, you need to discard half of them" << endl; //prints to the player that he needs to discard half of his resources
                size_t numToDiscard = p.getNumResources() / 2;
                cout << "You need to choose " << numToDiscard << " resources to discard" << endl; //prints to the player how many resources he needs to discard
                p.printResources();
                cout << "Enter a vector of the resources you want to discard, in the following order: BRICK WOOD WHEAT SHEEP ORE " << endl; //asks the player to enter the resources he wants to discard
                vector<size_t> resources;
                bool validChoice = false;
                while (!validChoice) // while the player does not enter a valid choice, ask the player to enter a valid choice
                {
                    try
                    {
                        cin >> choice1 >> choice2 >> choice3 >> choice4 >> choice5;
                        choice = choice1 + " " + choice2 + " " + choice3 + " " + choice4 + " " + choice5;
                        resources = Consts::parseResource(choice); // parse the resources using the Consts class
                        size_t sum = 0;
                        for (size_t i : resources) //count the sum of the resources, if the sum is not equal to the number of resources the player needs to discard, ask the player to enter a valid choice
                        {
                            sum += i;
                        }
                        if (sum != numToDiscard)
                        {
                            cout << "You need to discard exactly " << numToDiscard << " resources" << endl;
                            p.printResources();
                        }
                        else if (p.getResources()[Consts::BRICK] < resources[Consts::BRICK] || p.getResources()[Consts::WOOD] < resources[Consts::WOOD] || p.getResources()[Consts::WHEAT] < resources[Consts::WHEAT] || p.getResources()[Consts::SHEEP] < resources[Consts::SHEEP] || p.getResources()[Consts::ORE] < resources[Consts::ORE])
                        { //if the player tries to discard more resources than he has, ask the player to enter a valid choice
                            cout << "You don't have enough resources to discard" << endl;
                            p.printResources();
                        }
                        else
                        {
                            for (size_t i = 0; i < 5; i++) //if it is a valid choice, remove the resources from the player
                            {
                                p.removeResource(i, resources[i]);
                            }
                            validChoice = true; //set the flag to true
                            cout << "Resources discarded" << endl;
                            cout << "Current resources: " << endl;
                            p.printResources();
                        }
                    }
                    catch (const std::exception &e) //if an excetprion is thrown from parseResource, we catch it and try again
                    {
                        std::cerr << e.what() << '\n';
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }
            }
        }
    }


/**
 * @brief Play a round of the game
 * The function prints the board, rolls the dice, and then and asks the current player to choose an action
 */
    void Catan::playRound()
    {
        bool end = false;
        printBoard(Consts::REGULAR);
        roolDice();
        printResources();
        while (!end) // while the player does not choose to end the turn, ask the player to choose an action
        {
            end = getPlayerInput();
        }
    }

/**
 * @brief Get the player input, and based on the input, call the appropriate function
 * @return true if the player chooses to end the turn, false otherwise
 * The function prints the current player, and asks the player to choose an action
 * The function then calls the appropriate function based on the player's choice
    */
    bool Catan::getPlayerInput()
    {
        cout << "It's " << players[currentPlayer].getName() << "'s turn" << endl; //prints the current player, and the options the player has
        cout << "Choose an action:" << endl;
        cout << "1. Build" << endl;
        cout << "2. Trade" << endl;
        cout << "3. Buy Development Card" << endl;
        cout << "4. Play Development Card" << endl;
        cout << "5. Print Resources"<<endl;
        cout << "6. View Board" << endl;
        cout << "7. Show Victory Points" << endl;
        cout << "8. End Turn" << endl;
        cout << "9. Quit" << endl;
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 9 || cin.fail()) //if the player enters an invalid choice, ask the player to enter a valid choice
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice) //based on the player's choice, call the appropriate function
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
            printResources();
            return false;
        case 6:
            printBoard(Consts::REGULAR);
            return false;
        case 7: 
            cout<< "Victory Points: "<< players[currentPlayer].getVictoryPoints()<<endl;
            return false;
        case 8:
            endTurn(); //end the turn and return true, so that the game will move to the next player
            return true;
        case 9: //if the player chooses to quit, ask the player to confirm
            cout << "Are you sure you want to quit?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            int quit;
            cin >> quit;
            while (quit < 1 || quit > 2 || cin.fail()) //if the player enters an invalid choice, ask the player to enter a valid choice
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice, please enter a valid choice" << endl;
                cin >> quit;
            }
            if (quit == 1)
            {
                throw invalid_argument("Game ended, one of the players quit"); //if the player chooses to quit, throw an exception that playGme will catch, so the game will end
            }
            return false;
        }
        return false; //wont reach here, but needed to avoid warning
    }



/**
 * @brief Build function, the function asks the player to choose an action, and based on the action, calls the appropriate function
 * The function prints the board, and asks the player to choose an action
 * The function then calls the appropriate function based on the player's choice
 * The function catches exceptions that are thrown during the game
 */
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
        while (choice < 1 || choice > 4 || cin.fail()) //if the player enters an invalid choice, ask the player to enter a valid choice
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            board.printBoard(Consts::BUILD_SETTLEMENT, &players[currentPlayer]);
            cout << "Enter the id of the settlement you want to build" << endl;
            cin >> id;
            if (cin.fail() || id>54 || id<1) //if the id is invalid, ask the player to enter a valid id
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid id" << endl;
                return;
            }
            try
            {
                bool hasResources = players[currentPlayer].canBuySettelement(); //check if the player has enough resources to buy a settlement
                if (hasResources)
                { // the actual placement of the settlement is done in the board class
                    if (board.checkValidLocation(id, Consts::BUILD_SETTLEMENT, &players[currentPlayer])) //check if the location is valid in terms of the rules of the game
                    {
                        board.placeSettlement(id, &players[currentPlayer]); //place the settlement on the board
                        players[currentPlayer].buySettlement(id); //buy the settlement (remove the resources from the player and add the settlement to the player settlements)
                        board.printBoard(Consts::REGULAR, &players[currentPlayer]); //print the board
                    }
                }
                else{
                    cout<< "You don't have enough resources to build a settlement"<<endl;
                }
            }
            catch (const invalid_argument &e) //if an exception is thrown, catch it and print the error
            {
                cout << e.what() << endl;
            }
            break;
        case 2: //same as above, but for the city, with city specific checks
            board.printBoard(Consts::BUILD_CITY, &players[currentPlayer]); 
            cout << "Enter the id of the city you want to build" << endl;
            cin >> id;
            if (cin.fail() || id>54 || id<1)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid id" << endl;
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
                        board.printBoard(Consts::REGULAR, &players[currentPlayer]);

                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 3: //same as above, but for the road, with road specific checks
            board.printBoard(Consts::BUILD_ROAD, &players[currentPlayer]);
            cout << "Enter the id of the road you want to build" << endl;
            cin >> id;
            if (cin.fail() || id>72 || id<1)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<< "Invalid id"<<endl;
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
                                                board.printBoard(Consts::REGULAR, &players[currentPlayer]);

                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4://if the player chooses to go back, print a message and return
            cout << "Returning to main menu" << endl;
            break;
        default: //wont reach here, but needed to avoid warning
            cout << "Invalid choice" << endl;
            break;
        }
    }

    /**
     * @brief Print the resources of the current player
     * The function prints the resources of the current player
     * The function catches exceptions that are thrown during the game
     */
    void Catan::printResources(){
        players[currentPlayer].printResources();
    }


    /**
     * @brief Buy a development card
     * The function checks if the player can buy a development card, and if so, buys a development card for the player
     */
    void Catan::buyDevelopmentCard()
    { // TODO
        if (cardCounter >= developmentCards.size()) //if there are no more development cards, print a message and return
        {
            cout << "No more development cards" << endl;
            return;
        }
        if (players[currentPlayer].canBuyDevelopmentCard() == false) //if the player dosen't have enough resources to buy a development card, print a message and return
        {
            return;
        }
        try{
        players[currentPlayer].buyDevelopmentCard(developmentCards[cardCounter]); //buy a development card for the player, and increase the card counter. The actual buying of the card is done in the player class
        //and the card is added to the player's development cards. The card is taken from the development cards deck vector.
        cardCounter++;
        }
        catch(const std::exception &e) //catch the exception that might be thrown by buyDevelopmentCard
        {
            std::cerr << e.what() << '\n';
        }
    }

    /**
     * @brief Play a development card
     * The function asks the player to choose a development card to play, and then plays the card
     */
    void Catan::playDevelopmentCard()
    {
        players[currentPlayer].printDevelopmentCards(); //print the development cards of the player, and ask the player to choose a card to play
        cout << "Enter the index of the card you want to play" << endl;
        size_t index;
        cin >> index;
        if (cin.fail()) //if cin failed to read the index, clean the buffer and return
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        if (index < 0 || index >= players[currentPlayer].getDevelopmentCards().size()) //if the index is invalid, print a message and return
        {
            cout << "Invalid id" << endl;
            return;
        }
        try
        {
            players[currentPlayer].getDevelopmentCards()[index]->useCard(players[currentPlayer], *this); //play the card, the actual playing of the card is done in the card class
        }
        catch (const std::exception &e) //catch the exception that might be thrown by useCard
        {
            std::cerr << e.what() << '\n';
        }
    }

    /**
     * @brief Trade function, the function asks the player to choose an action, and based on the action, calls the appropriate function
     * The function prints the board, and asks the player to choose an action
     * The function then calls the appropriate function based on the player's choice
     * The function catches exceptions that are thrown during the game
     */
    void Catan::trade()
    {
        cout << "Choose an action:" << endl; //Let the player choose a trade action, resources or development cards
        cout << "1. Trade resources with player" << endl;
        cout << "2. Trade development cards with player" << endl;
        cout << "3. Back" << endl;
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 3 || cin.fail()) //if the player enters an invalid choice, ask the player to enter a valid choice
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter a valid choice" << endl;
            cin >> choice;
        }
        switch (choice) //based on the player's choice, call the appropriate function
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

    /**
     * @brief End the turn, and move to the next player
     * The function increases the current player by 1, and if the current player after increment is 3, sets the current player to 0
     */
    void Catan::endTurn()
    {
        currentPlayer = (currentPlayer + 1) % 3;
    }

    /**
     * @brief Shuffle a vector
     * @param vec the vector to shuffle
     * @param seed the seed to use for the shuffle, this has default value of 0, that is used for now to avoid using a seed, for tests purposes
     * The function shuffles the vector using the seed
     * 
     */
    void Catan::shuffleVector(std::vector<DevelopmentCard *> &vec, size_t seed)
    {
        // Obtain a time-based seed:
        // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed)); //use the seed to shuffle the vector by using the shuffle function from the algorithm library
    }

    /**
     * @brief Trade resources with another player
     * The function asks the player to choose the resources he wants to get and give, and then trades the resources with the other player
     * The function catches exceptions that are thrown during the game
     */
    void Catan::tradeResources()
    {
        cout << "Enter the name of the player you want to trade with" << endl;
        string name;
        cin >> name;
        Player *player = nullptr;
        for (size_t i=0; i<Consts::NUM_OF_PLAYERS;i++) //the player chooses a player to trade with, and the function finds the player
        {
            if (players[i].getName() == name)
            {
                player = &players[i];
                break;
            }
        }
        if (player == nullptr) //if the player is not found, print a message and return
        {
            cout << "Player not found" << endl;
            return;
        }
        if (player == &players[currentPlayer]) //if the player tries to trade with himself, print a message and return
        {
            cout << "You can't trade with yourself" << endl;
            return;
        }
        cout << "You have the following resources: " << endl;
        players[currentPlayer].printResources();
        cout << "Enter the resources you want to get, in the following order: BRICK WOOD WHEAT SHEEP ORE" << endl; //the player chooses the resources he wants to get
        string resources;
        string resource1;
        string resource2;
        string resource3;
        string resource4;
        string resource5;
        cin >> resource1 >> resource2 >> resource3 >> resource4 >> resource5;
        resources = resource1 + " " + resource2 + " " + resource3 + " " + resource4 + " " + resource5;
        vector<size_t> resourcesToGet;
        try
        {
            resourcesToGet = Consts::parseResource(resources); //parse the resources using the Consts class
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        cout << player->getName() << " You have the following resources: " << endl; //the player who's being trade with chooses the resources he wants to give
        player->printResources();
        cout << "Enter the resources you want to get, in the following order: BRICK WOOD WHEAT SHEEP ORE" << endl;
        cin >> resource1 >> resource2 >> resource3 >> resource4 >> resource5;
        resources = resource1 + " " + resource2 + " " + resource3 + " " + resource4 + " " + resource5;
        vector<size_t> resourcesToGive;
        try
        {
            resourcesToGive = Consts::parseResource(resources); //parse the resources using the Consts class
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        cout << "Press 1 to confirm the trade, any other key to cancel" << endl;  //if the player confirms the trade, trade the resources
                int confirm;
        cin >> confirm;
        if (confirm != 1)
        {
            cout << "Trade canceled" << endl;
            return;
        }
        try
        {
            players[currentPlayer].tradeResources(player, resourcesToGive, resourcesToGet); //the actual trading of the resources is done in the player class. If one of the players tries to trade with cards that he doesn't have, an exception will be thrown
            cout<< "Trade completed"<<endl;
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

/**
 * @brief Trade development cards with another player
 * The function asks the player to choose the development cards he wants to get and give, and then trades the development cards with the other player
 * The function catches exceptions that are thrown during the game
 * The function is similar to tradeResources, but for development cards
 */
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
        string choice1;
        string choice2;
        string choice3;
        string choice4;
        string choice5;
        cin >> choice1 >> choice2 >> choice3 >> choice4 >> choice5;
        choice = choice1 + " " + choice2 + " " + choice3 + " " + choice4 + " " + choice5;
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
        cin >> choice1 >> choice2 >> choice3 >> choice4 >> choice5;
        choice = choice1 + " " + choice2 + " " + choice3 + " " + choice4 + " " + choice5;
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
