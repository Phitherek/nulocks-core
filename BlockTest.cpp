#include "Block.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
using namespace Nulocks::Core;

int main() {
        cout << "Nulocks::Core Tests - Block v. 0.1" << endl << "(c) 2014 by Phitherek_" << endl << endl;
        int successcount = 0;
        int failcount = 0;
        cout << "Block(): ";
        Block b;
        if(b.getValue() == 0 && b.wasMoved() == false) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.getValue() << ", " << b.wasMoved() << endl;
                failcount++;
        }
        cout << "setMoved(): ";
        b.setMoved();
        if(b.wasMoved() == true) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.wasMoved() << endl;
                failcount++;
        }
        cout << "unsetMoved(): ";
        b.unsetMoved();
        if(b.wasMoved() == false) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.wasMoved() << endl;
                failcount++;
        }
        cout << "wasMoved(): ";
        b.setMoved();
        if(b.wasMoved() == true) {
                b.unsetMoved();
                if(b.wasMoved() == false) {
                        cout << "SUCCESS!" << endl;
                        successcount++;
                } else {
                        cout << "FAILURE: " << b.wasMoved() << endl;
                        failcount++;
                }
        } else {
                cout << "FAILURE: " << b.wasMoved() << endl;
                failcount++;
        }
        cout << "getValue(): ";
        b.levelUp();
        if(b.getValue() == 2) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.getValue() << endl;
                failcount++;
        }
        cout << "getLevel(): ";
        if(b.getLevel() == 1) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.getLevel() << endl;
                failcount++;
        }
        cout << "levelUp(): ";
        b.levelUp();
        if(b.getValue() == 4 && b.getLevel() == 2) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.getValue() << ", " << b.getLevel() << endl;
                failcount++;
        }
        cout << "empty(): ";
        b.empty();
        if(b.isEmpty() == true) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.isEmpty() << endl;
                failcount++;
        }
        cout << "isEmpty(): ";
        if(b.isEmpty() == true) {
                b.levelUp();
                if(b.isEmpty() == false) {
                        cout << "SUCCESS!" << endl;
                        successcount++;
                } else {
                        cout << "FAILURE: " << b.isEmpty() << endl;
                        failcount++;
                }
        } else {
                cout << "FAILURE: " << b.isEmpty() << endl;
                failcount++;
        }
        cout << "setLevel(): ";
        b.setLevel(4);
        if(b.getValue() == 16 && b.getLevel() == 4) {
                cout << "SUCCESS!" << endl;
                successcount++;
        } else {
                cout << "FAILURE: " << b.getValue() << ", " << b.getLevel() << endl;
                failcount++;
        }
        cout << endl << "Tests finished!" << endl << endl << successcount << " successful, " << failcount << " failures" << endl;
        if(failcount == 0) {
                return EXIT_SUCCESS;
        } else {
                return EXIT_FAILURE;
        }
}
