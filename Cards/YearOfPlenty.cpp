#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel{
    YearOfPlenty::YearOfPlenty(){
        this->discription = "Year Of Plenty";
        this->used = false;
        this->type = 4;
        this->value = 0;
    }
     void YearOfPlenty::useCard(Player& player, Catan& game){
        if(used){
            throw invalid_argument("You already used this card");
        }
        if(&player != &game.getCurrentPlayer()){
            throw invalid_argument("You can only use this card on your turn");
        }
        cout<<"Choose 2 cards from the bank, Enter a vector of the cards you want, the oreder is: Brick, Wood, Wheat, Sheep, Ore "<<endl;
        cout<<"Enter the first card: ";
        string input;
        cin>>input;
        vector<size_t> cards = Consts::parseResource(input);
        if( (cards[0]+cards[1]+cards[2]+cards[3]+cards[4]) > 2){
            throw invalid_argument("You can only choose 2 cards, you entered more than 2 cards");
        }
        else{
            for(size_t i= 0;i<cards.size();i++){
                player.addResource(i,cards[i]); //Adding the resources
            }
            used = true;
        }
    }
}