#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel{

    /**
     * @bried Constructs a new Year Of Plenty card
    */
    YearOfPlenty::YearOfPlenty(){
        this->description = "Year Of Plenty";
        this->used = false;
        this->type = 4;
        this->value = 0;
    }
    /**
     * @brief This method allows the player to use the Year Of Plenty card
     * @param player - the player who uses the card
     * @param game - the game that the player is playing
     * @throw invalid_argument if the player is not the current player or if the card has already been used, or if the player tries to choose more than 2 cards
    */
     void YearOfPlenty::useCard(Player& player, Catan& game){
        if(used){ //Checking if the card was already used, if it was, throw an exception
            throw invalid_argument("You already used this card");
        }
        if(&player != &game.getCurrentPlayer()){ //Checking if the player is the current player, if not, throw an exception
            throw invalid_argument("You can only use this card on your turn");
        } 
        //Choosing the 2 cards from the bank
        cout<<"Choose 2 cards from the bank, Enter a vector of the cards you want, the oreder is: Brick, Wood, Wheat, Sheep, Ore "<<endl;
        string input;
        string input1;
        string input2;
        string input3;
        string input4;
        string input5;
        cin>>input1 >> input2 >> input3 >> input4 >> input5;
        input = input1 + " " + input2 + " " + input3 + " " + input4 + " " + input5;
        vector<size_t> cards = Consts::parseResource(input); //Parsing the input
        if( (cards[0]+cards[1]+cards[2]+cards[3]+cards[4]) != 2){
            throw invalid_argument("You can only choose exactly 2 cards!"); //Checking if the player chose exactly 2 cards, if not throw an exception
        }
        else{
            for(size_t i= 0;i<cards.size();i++){ //Iterating over the cards
                player.addResource(i,cards[i]); //Adding the resources
            }
            used = true;
            description = "Year Of Plenty (used)"; //Setting the card as used
            cout<< "You have successfully used the Year Of Plenty card!"<<endl;
        }
    }
}