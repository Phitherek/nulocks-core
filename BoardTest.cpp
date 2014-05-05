#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
using namespace Nulocks::Core;

int main() {
        cout << "Nulocks::Core Tests - Board v. 0.1" << endl << "(c) 2014 by Phitherek_" << endl << endl;
        int successcount = 0;
        int failcount = 0;
        cout << "Board(): ";
        Board b1;
        bool ok = true;
        int** repr;
        if(b1.getSize() != 4 || b1.getWinPower() != 11 || b1.getScore() != 0 || b1.gameInProgress() == false) {
                ok = false;
        } else {
                repr = new int*[b1.getSize()];
                for(int i = 0; i < b1.getSize(); i++) {
                        repr[i] = new int[b1.getSize()];
                }
                b1.getRepresentation(&repr);
                for(int i = 0; i < b1.getSize(); i++) {
                        for(int j = 0; j < b1.getSize(); j++) {
                                if(repr[i][j] != 0 && repr[i][j] != 2 && repr[i][j] != 4) {
                                        ok = false;
                                }
                        }
                }
                for(int i = 0; i < b1.getSize(); i++) {
                        delete[] repr[i];
                }
                delete[] repr;
        }
        Board b2(8, 9);
        if(b2.getSize() != 8 || b2.getWinPower() != 9 || b2.getScore() != 0 || b2.gameInProgress() == false) {
                ok = false;
        } else {
                repr = new int*[b2.getSize()];
                for(int i = 0; i < b2.getSize(); i++) {
                        repr[i] = new int[b2.getSize()];
                }
                b2.getRepresentation(&repr);
                for(int i = 0; i < b2.getSize(); i++) {
                        for(int j = 0; j < b2.getSize(); j++) {
                                if(repr[i][j] != 0 && repr[i][j] != 2 && repr[i][j] != 4) {
                                        ok = false;
                                }
                        }
                }
        }
        if(ok) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE" << endl;
                failcount++;
        }
        cout << "Board = Board: ";
        Board b3 = b2;
        if(b3.getSize() == b2.getSize() && b3.getWinPower() == b2.getWinPower() && b3.getScore() == b2.getScore() && b3.gameInProgress() == b2.gameInProgress() && b3.gameWon() == b2.gameWon() && b3.gameLost() == b2.gameLost()) {
                repr = new int*[b2.getSize()];
                for(int i = 0; i < b2.getSize(); i++) {
                        repr[i] = new int[b2.getSize()];
                }
                int** repr2 = new int*[b3.getSize()];
                for(int i = 0; i < b3.getSize(); i++) {
                        repr2[i] = new int[b3.getSize()];
                }
                b2.getRepresentation(&repr);
                b3.getRepresentation(&repr2);
                ok = true;
                for(int i = 0; i < b2.getSize(); i++) {
                        for(int j = 0; j < b2.getSize(); j++) {
                                if(repr[i][j] != repr2[i][j]) {
                                        ok = false;
                                        break;
                                }
                        }
                }
                for(int i = 0; i < b2.getSize(); i++) {
                        delete[] repr[i];
                }
                delete[] repr;
                for(int i = 0; i < b3.getSize(); i++) {
                        delete[] repr2[i];
                }
                delete[] repr2;
                if(!ok) {
                        cout << "FAILURE" << endl;
                        failcount++;
                } else {
                        cout << "SUCCESS!" << endl;
                        successcount++;
                }
        } else {
                cout << "FAILURE: " << b3.getSize() << ", " << b3.getWinPower() << ", " << b3.getScore() << endl;
                failcount++;
        }
        cout << endl << "Tests finished!" << endl << endl << successcount << " successful, " << failcount << " failures" << endl;
        if(failcount == 0) {
                return EXIT_SUCCESS;
        } else {
                return EXIT_FAILURE;
        }
}
