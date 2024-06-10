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
        string input;
        string input1;
        string input2;
        string input3;
        string input4;
        string input5;
        cin>>input1 >> input2 >> input3 >> input4 >> input5;
        input = input1 + " " + input2 + " " + input3 + " " + input4 + " " + input5;
        vector<size_t> cards = Consts::parseResource(input);
        if( (cards[0]+cards[1]+cards[2]+cards[3]+cards[4]) != 2){
            throw invalid_argument("You can only choose exactly 2 cards!");
        }
        else{
            for(size_t i= 0;i<cards.size();i++){
                player.addResource(i,cards[i]); //Adding the resources
            }
            used = true;
            cout<< "You have successfully used the Year Of Plenty card!"<<endl;
        }
    }
}