/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board/Board.hpp"
using namespace std;
using namespace ariel;

int main()
{
    Player p1("A", 1);
    cout<<p1.getName()<<endl;
    Player p2("B", 2);
    Player p3("C", 3);
    Catan game(p1, p2, p3);
    cout << "Starting game" << endl;

}