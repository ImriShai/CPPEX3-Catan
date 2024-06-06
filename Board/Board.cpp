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
    const Road* Board::getRoad(size_t id) const{
        if(id<1 || id>72){
            throw invalid_argument("id must be between 1 and 72");
        }
        return roads[id-1];
    }
    const Settlement* Board::getSettlement(size_t id) const{
        if(id<1 || id>54){
            throw invalid_argument("id must be between 1 and 54");
        }
        return settlements[id-1];
    }
   
    void Board::init(){
        
        for(size_t i=0; i<19; i++){
            tiles[i] = new Tile(i+1);
        }
        for(size_t i=0; i<54; i++){
            settlements[i] = new Settlement(i+1);
        }
        for(size_t i=0; i<72; i++){
            roads[i] = new Road(i+1);
        }
        
        
    
    }
    const Tile* Board::getTile(char id) const{
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
    void Board::placeRoad(size_t id, Player* owner) const{
       if(!checkValidLocation(id, Consts::BUILD_ROAD, owner)){
           throw invalid_argument("Invalid location");
        roads[id-1]->setOwner(owner);
    }
    }
    void Board::placeSettlement(size_t id, Player* owner) const{
        if(!checkValidLocation(id, Consts::BUILD_SETTLEMENT, owner)){
            throw invalid_argument("Invalid location");
        }
        settlements[id-1]->setOwner(owner);
    }
    bool Board::checkValidLocation(size_t id, size_t mode, Player* owner) const{
        switch (mode)
        {
        case Consts::BUILD_SETTLEMENT:
            if(id<1 || id>54){
                return false;
            }
            if(settlements[id-1]->getOwner() != nullptr){
                return false;
            }
            return true;
            break;
        case Consts::BUILD_ROAD:
            if(id<1 || id>72){
                return false;
            }
            if(roads[id-1]->getOwner() != nullptr){
                return false;
            }
            return true;
        case Consts::BUILD_CITY:
            if(id<1 || id>54){
                return false;
            }
            if(settlements[id-1]->getOwner() != owner){
                return false;
            }
            return true;
            break;
        default:
            throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }

}