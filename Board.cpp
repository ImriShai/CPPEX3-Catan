#include "Board.hpp"
using namespace std;
namespace ariel{
    void Board::printBoard(){
        for(Tile* t : tiles){
            cout<<t->getTileType()<<" ";
        }
        cout<<endl;
    }
    const vector<Tile*> &Board::getTiles() {
        return tiles;
    }
    void Board::init(){
        for(size_t i = 0; i < 19; i++){
            tiles.push_back(&Tile('A'+i)); //initialize tiles vector, 
        }
        for(size_t i =1;i<=54;i++){
            settelments.push_back(make_unique<Settelment>(i)); //initialize settlements vector
        }
        for(size_t i =1;i<=72;i++){
            roads.push_back(make_unique<Road>(i)); //initialize roads vector
        }
    }
    const Tile* Board::getTile(char id){
        if(id<'A' || id>'S'){
            throw invalid_argument("id must be between A and S");
        }
        return tiles[id-'A'];
    }
}