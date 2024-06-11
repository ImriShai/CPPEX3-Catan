#include "doctest.h"
#include "../Catan.hpp"
#include <sstream> // for ostringstream, to check << operator

/**
 * @brief Test cases for the Graph class and the Algorithms class
 */
using namespace std;
using namespace ariel;

Player player1("Alice", 20);
Player player2("Bob", 21);
Player player3("Charlie", 22);
Catan game(player1, player2, player3);
void initGame()
{
    game.ChooseStartingPlayer();
    game.getBoard().placeSettlement(14, &player1);
    game.getPlayer(0).buySettlement(14, true);
    game.getBoard().placeRoad(14, &player1);
    game.getPlayer(0).buyRoad(14, true);
    game.getBoard().placeSettlement(35, &player2);
    game.getPlayer(1).buySettlement(35, true);
    game.getBoard().placeRoad(42, &player2);
    game.getPlayer(1).buyRoad(42, true);
    game.getBoard().placeSettlement(26, &player3);
    game.getPlayer(2).buySettlement(26, true);
    game.getBoard().placeRoad(31, &player3);
    game.getPlayer(2).buyRoad(31, true);
    game.getBoard().placeSettlement(25, &player3);
    game.getPlayer(2).buySettlement(25, true);
    game.getBoard().placeRoad(29, &player3);
    game.getPlayer(2).buyRoad(29, true);
    game.getBoard().placeSettlement(34, &player2);
    game.getPlayer(1).buySettlement(34, true);
    game.getBoard().placeRoad(40, &player2);
    game.getPlayer(1).buyRoad(40, true);
    game.getBoard().placeSettlement(36, &player1);
    game.getPlayer(0).buySettlement(36, true);
    game.getBoard().placeRoad(44, &player1);
    game.getPlayer(0).buyRoad(44, true);
}
void resetGame(Catan &game)
{
    game = Catan(player1, player2, player3);
}
TEST_CASE("Test Catan")
{
    SUBCASE("Test checkValidLocation")
    {
        SUBCASE("Test same location")
        {
            initGame();
            CHECK_FALSE(game.getBoard().checkValidLocation(14, Consts::BUILD_SETTLEMENT, &player1));
            CHECK_FALSE(game.getBoard().checkValidLocation(14, Consts::BUILD_ROAD, &player1));
            CHECK(game.getBoard().checkValidLocation(35, Consts::BUILD_CITY, &player2));
            CHECK_FALSE(game.getBoard().checkValidLocation(35, Consts::BUILD_SETTLEMENT, &player2));
            CHECK_FALSE(game.getBoard().checkValidLocation(35, Consts::BUILD_ROAD, &player2));
            CHECK_FALSE(game.getBoard().checkValidLocation(26, Consts::BUILD_CITY, &player1));
            CHECK_FALSE(game.getBoard().checkValidLocation(26, Consts::BUILD_SETTLEMENT, &player3));
            CHECK_FALSE(game.getBoard().checkValidLocation(26, Consts::BUILD_ROAD, &player3));
        }
        SUBCASE("Build city")
        {
            CHECK_FALSE(game.getBoard().checkValidLocation(35, Consts::BUILD_CITY, &player1));
            CHECK_EQ(game.getBoard().checkValidLocation(14, Consts::BUILD_CITY, &player1), true);
        }
        SUBCASE("Build settlement adjacent to other settlement")
        {
            CHECK_FALSE(game.getBoard().checkValidLocation(20, Consts::BUILD_SETTLEMENT, &player3));
            CHECK_FALSE(game.getBoard().checkValidLocation(25, Consts::BUILD_ROAD, &player3));
            CHECK_EQ(game.getBoard().checkValidLocation(20, Consts::BUILD_SETTLEMENT, &player2), false);
        }
        SUBCASE("Valid City")
        {
            CHECK(game.getBoard().checkValidLocation(35, Consts::BUILD_CITY, &player2));
            CHECK_EQ(game.getBoard().checkValidLocation(14, Consts::BUILD_CITY, &player1), true);
        }
        SUBCASE("Valid Road")
        {
            CHECK(game.getBoard().checkValidLocation(15, Consts::BUILD_ROAD, &player1));
            CHECK_EQ(game.getBoard().checkValidLocation(51, Consts::BUILD_ROAD, &player2), true);
        }
        SUBCASE("Invalid Road")
        {
            CHECK_FALSE(game.getBoard().checkValidLocation(15, Consts::BUILD_ROAD, &player2));
            CHECK_FALSE(game.getBoard().checkValidLocation(51, Consts::BUILD_ROAD, &player1));
        }
    }

    SUBCASE("Check Win")
    {

        SUBCASE("Player 1 wins")
        {
            game.getPlayer(0).addVictoryPoints(9);
            CHECK(game.checkWin());
            game.getPlayer(0).setVictoryPoints(2);
        }
        SUBCASE("Player 2 wins")
        {

            game.getPlayer(1).addVictoryPoints(9);
            CHECK(game.checkWin());
            game.getPlayer(1).setVictoryPoints(2);
        }
        SUBCASE("Player 3 wins")
        {
            game.getPlayer(2).addVictoryPoints(9);
            CHECK(game.checkWin());
            game.getPlayer(2).setVictoryPoints(2);
        }
        SUBCASE("No one wins")
        {

            CHECK_FALSE(game.checkWin());
        }
    }
    SUBCASE("Test ChooseStartingPlayer")
    {
        game.ChooseStartingPlayer();
        CHECK_EQ(game.getCurrentPlayer().getName(), "Alice");
    }
    SUBCASE("Test Development cards")
    {
        SUBCASE("Test buy")
        {
            game.getPlayer(0).addResource(Consts::ORE, 1);
            game.getPlayer(0).addResource(Consts::WHEAT, 1);
            game.getPlayer(0).addResource(Consts::SHEEP, 1);
            game.buyDevelopmentCard();
            CHECK_EQ(game.getPlayer(0).getDevelopmentCards().size(), 1);
            game.buyDevelopmentCard();
            CHECK_EQ(game.getPlayer(0).getDevelopmentCards().size(), 1);
            for (size_t i = 0; i < 13; i++)
            {
                game.getPlayer(0).addResource(Consts::ORE, 1);
                game.getPlayer(0).addResource(Consts::WHEAT, 1);
                game.getPlayer(0).addResource(Consts::SHEEP, 1);
                game.buyDevelopmentCard();
            }
            CHECK_EQ(game.getPlayer(0).getDevelopmentCards().size(), 14);
            game.getPlayer(0).printDevelopmentCards();
            game.getPlayer(0).addResource(Consts::ORE, 1);
            game.getPlayer(0).addResource(Consts::WHEAT, 1);
            game.getPlayer(0).addResource(Consts::SHEEP, 1);
            ostringstream os;
            auto cout_buf = cout.rdbuf();
            cout.rdbuf(os.rdbuf());
            game.buyDevelopmentCard();
            cout.rdbuf(cout_buf);
            CHECK_EQ(os.str(), ("No more development cards\n"));
            game.getPlayer(0).removeResource(Consts::ORE, 1);
            game.getPlayer(0).removeResource(Consts::WHEAT, 1);
            game.getPlayer(0).removeResource(Consts::SHEEP, 1);
        }
        SUBCASE("Use cards")
        {
            SUBCASE("Monopoly")
            {
                game.getPlayer(1).addResource(Consts::BRICK, 5);
                game.getPlayer(2).addResource(Consts::BRICK, 5);
                game.getPlayer(1).addResource(Consts::WOOD, 5);
                std::istringstream simulatedInput("0");
                auto cin_buf = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput

                // Perform the operation that reads from std::cin
                game.getPlayer(0).getDevelopmentCards()[3]->useCard(game.getPlayer(0), game);

                // Restore std::cin
                std::cin.rdbuf(cin_buf); // Reset to standard input again
                CHECK_EQ(game.getPlayer(0).getResources()[Consts::BRICK], 10);
                CHECK_EQ(game.getPlayer(1).getResources()[Consts::BRICK], 0);
                CHECK_EQ(game.getPlayer(2).getResources()[Consts::BRICK], 0);
                CHECK_EQ(game.getPlayer(1).getResources()[Consts::WOOD], 5);
                game.getPlayer(0).removeResource(Consts::BRICK, 10);
                game.getPlayer(1).removeResource(Consts::WOOD, 5);
                                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[3]->useCard(game.getPlayer(0), game));

            }
            SUBCASE("Knight")
            {
                game.getPlayer(1).addResource(Consts::BRICK, 5);
                std::istringstream simulatedInput("1");
                auto cin_buf = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput
                game.getPlayer(0).printDevelopmentCards();
                // Perform the operation that reads from std::cin
                game.getPlayer(0).getDevelopmentCards()[5]->useCard(game.getPlayer(0), game);

                // Restore std::cin
                std::cin.rdbuf(cin_buf); // Reset to standard input again
                CHECK_EQ(game.getPlayer(0).getResources()[Consts::BRICK], 1);
                CHECK_EQ(game.getPlayer(1).getResources()[Consts::BRICK], 4);
                
                game.getPlayer(0).removeResource(Consts::BRICK, 1);
                game.getPlayer(1).removeResource(Consts::BRICK, 4);
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[5]->useCard(game.getPlayer(0), game));
                std::istringstream simulatedInput1("0");
                auto cin_buf1 = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput1.rdbuf()); // Redirect std::cin to simulatedInput
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[12]->useCard(game.getPlayer(0), game));
                // Restore std::cin
                std::cin.rdbuf(cin_buf1); // Reset to standard input again

                std::istringstream simulatedInput2("1");
                auto cin_buf2 = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput2.rdbuf()); // Redirect std::cin to simulatedInput
                game.getPlayer(0).addResource(Consts::BRICK, 5);
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[12]->useCard(game.getPlayer(0), game));
                // Restore std::cin
                std::cin.rdbuf(cin_buf2); // Reset to standard input again
                game.getPlayer(0).removeResource(Consts::BRICK, 5); 


            }
            SUBCASE("Victory Point")
            {
                CHECK_EQ(game.getPlayer(0).getVictoryPoints(), 2);
                game.getPlayer(0).getDevelopmentCards()[0]->useCard(game.getPlayer(0), game);
                CHECK_EQ(game.getPlayer(0).getVictoryPoints(),3);
                game.getPlayer(0).setVictoryPoints(2);
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[0]->useCard(game.getPlayer(0), game));
            }
            SUBCASE("Road Building")
            {
                CHECK_FALSE(game.getPlayer(0).canBuyRoad());
                std::istringstream simulatedInput("15 16");
                auto cin_buf = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput
                game.getPlayer(0).getDevelopmentCards()[1]->useCard(game.getPlayer(0), game);
                std::cin.rdbuf(cin_buf); // Reset to standard input again
                CHECK_EQ(game.getPlayer(0).getRoads().size(), 4);
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[1]->useCard(game.getPlayer(0), game));
            }
            SUBCASE("Year of Plenty")
            {
                CHECK_FALSE(game.getPlayer(0).canBuyRoad());
                std::istringstream simulatedInput("1 1 0 0 0");
                auto cin_buf = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput
                game.getPlayer(0).getDevelopmentCards()[11]->useCard(game.getPlayer(0), game);
                std::cin.rdbuf(cin_buf); // Reset to standard input again
                CHECK_EQ(game.getPlayer(0).getResources()[Consts::BRICK], 1);
                CHECK_EQ(game.getPlayer(0).getResources()[Consts::WOOD], 1);
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[11]->useCard(game.getPlayer(0), game));
                game.getPlayer(0).removeResource(Consts::BRICK, 1);
                game.getPlayer(0).removeResource(Consts::WOOD, 1);
                std::istringstream simulatedInput3("1 1 1 1 1");
                auto cin_buf3 = std::cin.rdbuf();        // Save old buf
                std::cin.rdbuf(simulatedInput3.rdbuf()); // Redirect std::cin to simulatedInput
                CHECK_THROWS(game.getPlayer(0).getDevelopmentCards()[11]->useCard(game.getPlayer(0), game));
                std::cin.rdbuf(cin_buf3); // Reset to standard input again
            }
        }
    }
    SUBCASE("Rolled7"){
        game.getPlayer(0).addResource(Consts::BRICK, 5);
        CHECK_NOTHROW(game.rolledSeven());
        game.getPlayer(0).addResource(Consts::WOOD, 5);
        std::istringstream simulatedInput("0 0 0 0 0 8 0 0 0 0 5 0 0 0 0");
        auto cin_buf = std::cin.rdbuf();        // Save old buf
        std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput
        game.rolledSeven();
        std::cin.rdbuf(cin_buf); // Reset to standard input again
        CHECK_EQ(game.getPlayer(0).getNumResources(), 5);
        CHECK_EQ(game.getPlayer(1).getNumResources(), 0);
        CHECK_EQ(game.getPlayer(2).getNumResources(), 0);
        CHECK_EQ(game.getPlayer(0).getResources()[Consts::BRICK], 0);
        CHECK_EQ(game.getPlayer(0).getResources()[Consts::WOOD], 5);
        game.getPlayer(0).removeResource(Consts::WOOD, 5);
    }

    SUBCASE("Trade cards"){
        cout<<"\n\nTrade cards"<<endl;
        game.getPlayer(0).addResource(Consts::BRICK, 5);
        game.getPlayer(1).addResource(Consts::WOOD, 5);
        game.getPlayer(1).printResources();
        game.getPlayer(0).printResources();
        std::istringstream simulatedInput("Bob 0 1 0 0 0 2 0 0 0 0 1");
        auto cin_buf = std::cin.rdbuf();        // Save old buf
        std::cin.rdbuf(simulatedInput.rdbuf()); // Redirect std::cin to simulatedInput
        game.tradeResources();
        std::cin.rdbuf(cin_buf); // Reset to standard input again
        CHECK_EQ(game.getPlayer(0).getResources()[Consts::BRICK], 3);
        CHECK_EQ(game.getPlayer(1).getResources()[Consts::BRICK], 2);
        CHECK_EQ(game.getPlayer(1).getResources()[Consts::WOOD], 4);
        CHECK_EQ(game.getPlayer(0).getResources()[Consts::WOOD], 1);
        game.getPlayer(0).removeResource(Consts::BRICK, 3);
        game.getPlayer(1).removeResource(Consts::BRICK, 2);
        game.getPlayer(1).removeResource(Consts::WOOD, 4);
        game.getPlayer(0).removeResource(Consts::WOOD, 1);
    }


}
TEST_CASE("Player tests")
{
    SUBCASE("Test canBuy")
    {
        SUBCASE("canBuySettlement")
        {
            CHECK_FALSE(game.getPlayer(0).canBuySettelement());
            game.getPlayer(0).addResource(Consts::BRICK, 1);
            game.getPlayer(0).addResource(Consts::WOOD, 1);
            game.getPlayer(0).addResource(Consts::WHEAT, 1);
            game.getPlayer(0).addResource(Consts::SHEEP, 1);
            CHECK(game.getPlayer(0).canBuySettelement());
            game.getPlayer(0).removeResource(Consts::BRICK, 1);
            CHECK_FALSE(game.getPlayer(0).canBuySettelement());
            CHECK_THROWS(game.getPlayer(0).removeResource(Consts::BRICK, 1));
            game.getPlayer(0).removeResource(Consts::WOOD, 1);
            game.getPlayer(0).removeResource(Consts::WHEAT, 1);
            game.getPlayer(0).removeResource(Consts::SHEEP, 1);
        }
        SUBCASE("canBuyCity")
        {
            CHECK_FALSE(game.getPlayer(0).canBuyCity());
            game.getPlayer(0).addResource(Consts::ORE, 3);
            game.getPlayer(0).addResource(Consts::WHEAT, 2);
            CHECK(game.getPlayer(0).canBuyCity());
            game.getPlayer(0).removeResource(Consts::ORE, 3);
            CHECK_FALSE(game.getPlayer(0).canBuyCity());
            CHECK_THROWS(game.getPlayer(0).removeResource(Consts::ORE, 3));
            game.getPlayer(0).removeResource(Consts::WHEAT, 2);
        }
        SUBCASE("canBuyRoad")
        {
            CHECK_FALSE(game.getPlayer(0).canBuyRoad());
            game.getPlayer(0).addResource(Consts::BRICK, 1);
            game.getPlayer(0).addResource(Consts::WOOD, 1);
            CHECK(game.getPlayer(0).canBuyRoad());
            game.getPlayer(0).removeResource(Consts::BRICK, 1);
            CHECK_FALSE(game.getPlayer(0).canBuyRoad());
            CHECK_THROWS(game.getPlayer(0).removeResource(Consts::BRICK, 1));
            game.getPlayer(0).removeResource(Consts::WOOD, 1);
        }
        SUBCASE("canBuyDevelopmentCard")
        {
            CHECK_FALSE(game.getPlayer(0).canBuyDevelopmentCard());
            game.getPlayer(0).addResource(Consts::ORE, 1);
            game.getPlayer(0).addResource(Consts::WHEAT, 1);
            game.getPlayer(0).addResource(Consts::SHEEP, 1);
            CHECK(game.getPlayer(0).canBuyDevelopmentCard());
            game.getPlayer(0).removeResource(Consts::ORE, 1);
            CHECK_FALSE(game.getPlayer(0).canBuyDevelopmentCard());
            CHECK_THROWS(game.getPlayer(0).removeResource(Consts::ORE, 1));
            game.getPlayer(0).removeResource(Consts::WHEAT, 1);
            game.getPlayer(0).removeResource(Consts::SHEEP, 1);
        }
    }
}
TEST_CASE("Test Consts"){
    SUBCASE("Test parseResource")
    {
        vector<size_t> res;
        CHECK_EQ(Consts::parseResource("0 0 0 0 0").size(), 5);
        CHECK_THROWS(Consts::parseResource("BRICK WOOD WHEAT SHEEP ORE"));
        res = Consts::parseResource("1 2 3 4 5");
        CHECK_EQ(res[0], 1);
        CHECK_EQ(res[1], 2);
        CHECK_EQ(res[2], 3);
        CHECK_EQ(res[3], 4);
        CHECK_EQ(res[4], 5);
        CHECK_THROWS(Consts::parseResource("1 2 3 4 5 6"));
        CHECK_THROWS(Consts::parseResource("1 2 3 4"));
        CHECK_THROWS(Consts::parseResource("1 2 3 4 -5"));
    }

    SUBCASE("Test getResourceIndex")
    {
        CHECK_EQ(Consts::getResourceIndex("BRICK"), Consts::RESOURCE::BRICK);
        CHECK_EQ(Consts::getResourceIndex("WOOD"), Consts::RESOURCE::WOOD);
        CHECK_EQ(Consts::getResourceIndex("WHEAT"), Consts::RESOURCE::WHEAT);
        CHECK_EQ(Consts::getResourceIndex("SHEEP"), Consts::RESOURCE::SHEEP);
        CHECK_EQ(Consts::getResourceIndex("ORE"), Consts::RESOURCE::ORE);
        CHECK_EQ(Consts::getResourceIndex("DESERT"), Consts::RESOURCE::DESERT);
        
    }
}
