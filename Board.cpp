#include "Board.hpp"
using namespace std;
namespace ariel{
    Board::Board(){
        init();
    }
    void Board::printBoard(size_t mode){
        // for(Tile* t : tiles){
        //     cout<<t->getTileType()<<" ";
        // }
        // cout<<endl;
    }
    const Road* Board::getRoad(size_t id){
        if(id<1 || id>72){
            throw invalid_argument("id must be between 1 and 72");
        }
        return roads[id-1];
    }
    const Settlement* Board::getSettlement(size_t id){
        if(id<1 || id>54){
            throw invalid_argument("id must be between 1 and 54");
        }
        return settlements[id-1];
    }
   
    void Board::init(){
        
        for(int i=0; i<19; i++){
            tiles[i] = new Tile(i+1);
        }
        for(int i=0; i<54; i++){
            settlements[i] = new Settlement(i+1);
        }
        for(int i=0; i<72; i++){
            roads[i] = new Road(i+1);
        }
        
        
    
    }
    const Tile* Board::getTile(char id){
        if(id<'A' || id>'S'){
            throw invalid_argument("id must be between A and S");
        }
        return tiles[id-'A'];
    }
    Board::~Board(){
      for(int i=0; i<19; i++){
            delete tiles[i];
        }
        for(int i=0; i<54; i++){
            delete settlements[i];
        }
        for(int i=0; i<72; i++){
            delete roads[i];
        }
    
    }
}