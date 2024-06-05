#include "Catan.hpp"
using namespace std;
namespace ariel{
        Catan::Catan(Player &p1, Player &p2, Player &p3){
            players.push_back(p1);
            players.push_back(p2);
            players.push_back(p3);
            sort(players.begin(), players.end(), [](const Player& a, const Player& b) { // sort players by age using lambda
                return a.getAge() < b.getAge();
            });
            currentPlayer = 0;
            players[0].setColor(Consts::RED);
            players[1].setColor(Consts::BLUE);
            players[2].setColor(Consts::ORANGE);

        }
        void Catan::ChooseStartingPlayer(){
            cout<<"The starting player is: "<<players[0].getName()<<endl;
        }
       const Board& Catan::getBoard(){
            return board;
        }
        void Catan::printBoard(size_t mode){
            board.printBoard(mode);
        }
        void Catan::start(){

        }
        bool Catan::checkWin(){
            for(Player p : players){
                if(p.getVictoryPoints() >= 10 ){
                    cout<<"The winner is: "<<p.getName()<<endl;
                    return true;
                }
            }
            return false;
        }
        const Player& Catan::getCurrentPlayer() {
            return players[currentPlayer];
        }
        void Catan::init(){
            board = Board();
            board.init();
            initDevelopmentCards();
            
        }
        void Catan::initDevelopmentCards(){
            for(int i=0; i<3; i++){
                developmentCards.push_back(new Knight());
            }
            for(int i=0; i<2; i++){
                developmentCards.push_back(new Monopoly());
                developmentCards.push_back(new RoadBuilding());
                developmentCards.push_back(new YearOfPlenty());
            }
            for(int i=0; i<5; i++){
                developmentCards.push_back(new VictoryPoint());
            }
        }

        Catan::~Catan(){
            for(size_t i =0; i<developmentCards.size(); i++){
                delete developmentCards[i];
            }
        }
        
}
        
    
