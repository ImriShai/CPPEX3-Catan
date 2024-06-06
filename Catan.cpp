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
    void Catan::start()
    {
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
                cout << "The winner is: " << p.getName() << endl;
                return true;
            }
        }
        return false;
    }
    const Player &Catan::getCurrentPlayer()
    {
        return players[currentPlayer];
    }
    void Catan::init()
    {
        board = Board();
        board.init();
        initDevelopmentCards();
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
    }

    Catan::~Catan()
    {
        for (size_t i = 0; i < developmentCards.size(); i++)
        {
            delete developmentCards[i];
        }
    }

    void Catan::roolDice(){
        size_t dice1 = rand() % 6 + 1;
        size_t dice2 = rand() % 6 + 1;
        size_t sum = dice1 + dice2;
        cout << "You rolled " << sum << endl;
        if(sum==7) rolledSeven();
        else{
            vector<char> tilesId = Consts::resourceTiles.at(sum);
            for(char id : tilesId){
                const Tile* tile = board.getTile(id);
                vector<size_t> settlements = tile->getSettelments();
                for(size_t i : settlements){
                    Settlement* settlement = board.getSettlement(i);
                    if(settlement->getOwner() != nullptr){
                        settlement->getOwner()->addResource(Consts::getResourceIndex(tile->getResource()), settlement->getValue());
                    }
                }
            }
           
        }
        
            
        

    }

    void Catan::playRound(){
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
            size_t id;
            board.printBoard(Consts::BUILD_SETTLEMENT);
            cout << "Enter the id of the settlement you want to place" << endl;
            cin >> id;
            try
            {
                players[currentPlayer].placeSettelement(id);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 2:
            board.printBoard(Consts::BUILD_CITY);
            size_t id;
            cout << "Enter the id of the city you want to place" << endl;
            cin >> id;
            try
            {
                players[currentPlayer].placeCity(id);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 3:
            board.printBoard(Consts::BUILD_ROAD);
            size_t id;
            cout << "Enter the id of the road you want to place" << endl;
            cin >> id;
            try
            {
                players[currentPlayer].placeRoad(id);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            cout << "Returning to main menu" << endl;
            break;
        }
    }

}
