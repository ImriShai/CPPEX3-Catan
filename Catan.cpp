#include "Catan.hpp"
using namespace std;
namespace ariel{
        Catan(Player p1, Player p2, Player p3){
            if(p1.getName() == p2.getName() || p1.getName() == p3.getName() || p2.getName() == p3.getName()){
                throw invalid_argument("Players must have different names");
            }
            players.push_back(p1);
            players.push_back(p2);
            players.push_back(p3);
            sort(players.begin(), players.end(), [](const Player& a, const Player& b) { // sort players by age using lambda
                return a.getAge() < b.getAge();
            });
            currentPlayer = 0;
        }
        void ChooseStartingPlayer(){
            cout<<"The starting player is: "<<players[0].getName()<<endl;
        }
       const Board &getBoard(){
            return board;
        }
        void printBoard(){
            board.printBoard();
        }
        void start();
        bool checkWin(){
            for(Player p : players){
                if(p.getVictoryPoints() >= 10 &&){
                    cout<<"The winner is: "<<p.getName()<<endl;
                    return true;
                }
            }
            return false;
        }
        const Player& getCurrentPlayer() {
            return players[currentPlayer];
        }
        void init(){
            board = Board();
            board.init();
            
        }
}
        
    
