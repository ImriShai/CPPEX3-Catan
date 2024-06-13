# Exercise 3 - Catan
## Author
- [Imri Shai](https://github.com/ImriShai)
- Email: imrish149@gmail.com
##

## Project Sructure
The project has a main demo to run the game, a directory for `Board` and it's pieces and a `Factory` to create them, one for `Development cards`, and one for Tests. 
Besides that, there is the `Catan` class, the main class of the project that responsible for the game logic, the `Player` class that represents a player and it's methods, and a class for game `Constants` and usefull methods, that needed for all classes.
##

## Execute
To run the game, download or clone the repository, then run `make`.
After that, execute the runnable file, by using `./demo` , the instructions for the rest of the usage will pop up in the terminal as the game flow.
##

## Classes
  ### Consts - 
  This class represent the constants for the game. It has Enums and other static data      members and function such as ANSI Escape colors, to color the players pieces etc..
   #### Methods
`parseResource(string resource)` - this method get a string that represent a 
vector of resources, if it's a valid input, it returns a vector of how much from each resource, else throws an error. 

`getResourceIndex(string)` - given a string, the method returns the correct index  of the resource type in the resource vector. If no such type exist, an error is 
     thrown.
  ####
  ###
  ### Catan - 
  This class is the main class of the project. It handle the entire game logic.
  It has the Players the Board and a vector of Development Cards - a Deck to draw from.
  #### Public methods
  The only public methods are the Constructor, the Destructor, and a method named `startGame()` that being called from the main file to start the game.
  ####
  #### Private methods
  `build()` - The method is being called every time a player want to build a piece. Then the player choose the type of piece he want to build and where, and the function check if it's possible and build it if valid.
  
  `trade()` - Similar to build but for trades. The method is being called every time a player want to trade resources or Development cards. Then the player chooses the kind of trade he wants, and the method `tradeResources()` or `tradeDevelopmentCards()` is being called respectivly. In both mehtods the player entering the cards he want, and the player to trade with entering the cards he want's and if agreed on both, they enter 1 and the trade is completed.
  
  `endTurn()` - The method end the current turn, and moving the turn to the next player.
  
  `rollDice()` - The method rolls 2 independent dices uniformly at random and calls `collectResources(sum)` or `rolledSeven()` with respect to the sum.
  
  `buyDevelopmentCard()` - The method checks if the current player has enough resources to buy a card. If so, and there are still cards to buy, it draws a card from the top of the deck  increment the deck, and addes the card to the player hand. 
 
  `playDevelopmentCard()` - The method ask the player which cards he wish to use. If exist and unused, the card is activated.
  
  `rolledSeven()` - If `rollDice()` returns 7, then this method will be called. The method checks if a player has more than 7 cards. If so, it forces the player to discard half of them.
  
  `shuffleVector(vector, seed)` - This method is only called once to shuffle the DevelopmentCard deck at the begining of the game.
  
  `buildFirstRound() buildFirstRoundHelper(i)` - These method are being called at the begining of the game. They let the players to build their first 2 settelments and roads for free.
  
`collectResources(diceRoll)` - This method is being called after every dice roll that is different from 7. The method uses the map in the `Consts` class to get the id's of the `Tile`s that has that number on them, then for each tile we check for it's settelments if it has an owner, if so, we give this owner the `Tile` resource by the amount it should get.

`printResouces()` - This method prints the resources of the current player playing.

`checkWin()` - This method checks if one of the players has 10 or more victory points. If so, the method returns true and the game stops.

`getPlayerInput()` - This method parse the current player input from the terminal and play the choosen act. If the player chooses to end his turn, the method will return true, so the next player could play.

`playRound()` - This method is responsible for playing a round of the game. While the player didn't choose to end his turn, the method will ask him for input to play a move.

`printBoard(mode)` - This method prints the board with respect to the mode choosen(Regular, BuildRoad, BuildCity, BuildSett).

Besides those method there are getters and setters.
####
###

### Player - 
This class represents a player in the game. Each player has name, age, settelments, roads, cities, resources, victory points, color and development cards.
#### Private methods
`findCard(type)` - This method goes through the player hand, finds the first development cards that meet the type given as parameter and returns it's index.
####
#### Public methods 
`canBuySettelment()` - The methods checks if the player has enough resources to buy a Settelment. If so it returns true, otherwise false.

`buySettelment(id, firstRound)` - This method buys the actual settelment. If it's not the first round, it subtracts the resources required to build, and add the id of the Settelment to the Settelments vector of the player.

`canBuyRoad()` - The methods checks if the player has enough resources to buy a Road. If so it returns true, otherwise false.

`buyRoad(id, firstRound)` - This method buys the actual Road. If it's not the first round, it subtracts the resources required to build, and add the id of the Road to the Roads vector of the player.

`canBuyCity()` - The methods checks if the player has enough resources to buy a City. If so it returns true, otherwise false.

`buyCity(id)` - This method buys the actual City.It subtracts the resources required to build.

`canBuyDevelpmentCard()` - This method checks if the player has enough resouces to buy a card. If so returns true, otherwise false.

`buyDevelopmentCard(*card)` - The method subtract the resources required and adds the card to the player hand.

`addResource(type, amount)` - The methods add the resources to the player.

`removeResource(type, amount)` - The methods removes the resources from the player. If the player dosen't have enough resources to remove, an error will be thrown.

`addVictoryPoint(amount) getVictoryPoints()` - These methods add and calculates the number of points of the player, with Victory Point cards, and the longest Army.

`getNumResources()` - Returns the number of resources the player has.

`stealRandomResource()` - Used for the Knight card. the method steals a random resource from the player, and returns the string representing the resource.

`stealResource(type)` - Used for Monopoly card. The method steals all the resource of type "type" and returns the amount of cards stolen.

`tradeResources\devCards(player, toGive, toTake)` - This method trades cards with the player given. If one of the player dosen't have enough cards to trade, an error will be thrown.

`printResources\devCards()` - This method prints the cards of the player.

`hasLongestArmy()` - This method checks if the player has the longest army card. If he has more than 3 activated Knights, a true value is returned.

The class has also getters and setters for the members.
####
###
### Board - 
This class represent the Board. It holds the Tiles the Settelments and the Roads.
#### Public methods
`printBoard(mode, player)` - Prints the Board to the terminal by the mode and player that asked to print.

`checkValidLocation(id, buildingMode, player, firstRound)` - The method checks if the given player can build at the given position by id, according to the game rules.

`placeRoad(id, owner)` - The method places the Road on the board and changes it color and owner with respect to the given player. 

`placeSettelment(id, owner)` - The method places the Settelment on the board and changes it color and owner with respect to the given player. 


`placeCity(id, owner)` - The method places the City on the board and changes it color and owner with respect to the given player. 

The class also has getters that returns a const refernce to the objects.
####
###
### Tile - 
This class represents a Tile in the game.
Each Tile has a number, an id, an emoji represents the resource, the resource as a string, and the Settelments on the Tile.
The only method are getters for the members.
###
### Road - 
This class represents a Road in the game.
Each Road has a type, an id, an owner and it's adjacent Settelments.
#### Public methods
`toString(mode, builder)` - Returns the String representaion required to the printing based on the player building and the mode of building.

The class also has getters and setters for the members.
####
###
### Settelment - 
This class represents a Settelment in the game.
Each Settelment has a type, an id, an owner and it's adjacent Settelments and adjacent Roads.
#### Public methods
`toString(mode, builder)` - Returns the String representaion required to the printing based on the player building and the mode of building.

The class also has getters and setters for the members.
####
###
### PiecesFactory - 
This class implements the Singelton design pattern and the Factory design pattern. The class is responsible for the creating of the Tile's, Settlment's and Roads. 
#### Public methods
`getInstance()` - The methods returns the Singleton instance of the Factory.

`createSettelment(id)` - Given an id the method will return a pointer to the object created. 

`createRoad(id)` - Given an id the method will return a pointer to the object created. 

`createTile(id)` - Given an id the method will return a pointer to the object created. 
####
###
### Cards - 
This class is an abstract class used for the Development Cards to inheirte from.
Each card has a description, type, value, and a flag to indicates if the card has already been used.
There are getters and setters for the members, and a pure virtual function `uscard(player, game)` that each card implements differently.
#### Knight
This class represents the Knigh card. When used, a player is choosen to steal a resource from him. The resource stolen then removed from one player and added to the player activated the card.
####
#### Monopoly
This class represents the Monopoly card. When used, a resource is choosen to steal from every player. Then, each player losses all the resources he has from that type, and those are added to the player activated the card.
####
#### RoadBuilding
This class represents the Road Building card. When used, the player who activated the card chooses 2 location to build roads for free. If the first location is valid and the second is not, the card is activated anyway, only one road will placed, and an error message will be thrown. If both are invalid, the card stays inactive and an error message will be thrown.
Otherwise, the card will actviated, and both Road will placed.
####
#### VictoryPoint
This class represents the Victory Point card. When used, a victory point is added to the player holding the card.
####
#### YearOfPlenty
This class represents the Year Of Plenty card. When used the player who used the card is asked to choose 2 resource to get from the bank, to his choice. If the player chooses more or less than 2 resources an error message will be thrown and thee card will remain inactive.
Otherwise, the resources will be added to the player, and the cards will be mark as used.
####













  
    
          









