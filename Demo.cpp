/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board/Board.hpp"
using namespace std;
using namespace ariel;

/**
 * @brief Main function to run the game
 * @return int
 */
int main()
{
//    string name;
//    size_t age;
//    cout << "Enter First player name: "<< endl;
//    cin >> name;
//    cout << "Enter First player age: "<< endl;
//    cin >> age;
//    while(age < 0 || age > 120 || cin.fail()){
//                cin.clear();
//                cin.ignore(1000, '\n');
//        cout << "Invalid age, please enter a valid age: "<< endl;
//        cin >> age;
//        cout << endl;
//    }
//    Player player1(name, age);
//    cout << "Enter Second player name: "<< endl;
//    cin >> name;
//    cout << "Enter Second player age: " << endl;
//    cin >> age;
//    while(age < 0 || age > 120 || cin.fail()){
//                cin.clear();
//                cin.ignore(1000, '\n');
//        cout << "Invalid age, please enter a valid age: "<< endl;
//        cin >> age;
//        cout << endl;
//    }
//    Player player2(name, age);
//    cout << "Enter Third player name: "<< endl;
//    cin >> name;
//    cout << "Enter Third player age: "<< endl;
//    cin >> age;
//    while(age < 0 || age > 120 || cin.fail()){
//                cin.clear();
//                cin.ignore(1000, '\n');
//        cout << "Invalid age, please enter a valid age: "<< endl;
//        cin >> age;
//        cout << endl;
//    }
//    Player player3(name, age);
    Player player1("Alice", 20);
    Player player2("Bob", 21);
    Player player3("Charlie", 22);

    Catan game(player1, player2, player3);
    game.PlayGame();
    cout << "Game Over!" << endl;
    return 0;
}