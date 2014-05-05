#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
using namespace Nulocks::Core;

int main() {
        cout << "Nulocks::Core Tests - Board Moves v. 0.1" << endl << "(c) 2014 by Phitherek_" << endl << endl;
        cout << "Initializing board...";
        Board b(4, 6);
        cout << " DONE!" << endl;
        char c;
        int** repr;
        repr = new int*[b.getSize()];
        for(int i = 0; i < b.getSize(); i++) {
                repr[i] = new int[b.getSize()];
        }
        do {
                cout << "Game status: ";
                if(b.gameInProgress()) {
                        cout << "In progress" << endl;
                } else if(b.gameWon()) {
                        cout << "Won" << endl;
                } else if(b.gameLost()) {
                        cout << "Lost" << endl;
                }
                cout << "Score: " << b.getScore() << endl << endl;
                b.getRepresentation(&repr);
                for(int i = 0; i < b.getSize(); i++) {
                        for(int j = 0; j < b.getSize(); j++) {
                                cout << repr[i][j] << " ";
                        }
                        cout << endl;
                }
                cout << endl;
                cout << "Select action: (u)p, (d)own, (l)eft, (r)ight, (q)uit: ";
                cin >> c;
                if(c == 'u') {
                        b.moveUp();
                } else if(c == 'd') {
                        b.moveDown();
                } else if(c == 'l') {
                        b.moveLeft();
                } else if(c == 'r') {
                        b.moveRight();
                }
        } while(c != 'q');
        for(int i = 0; i < b.getSize(); i++) {
                delete[] repr[i];
        }
        delete[] repr;
        return EXIT_SUCCESS;
}
