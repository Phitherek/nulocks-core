#include "Board.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

Nulocks::Core::Board::Board(int size, int winpower) {
        _board = new Nulocks::Core::Block*[size];
        for(int i = 0; i < size; i++) {
                _board[i] = new Nulocks::Core::Block[size];
        }
        _score = 0;
        _status = 0;
        _size = size;
        _winpower = winpower;
        startFirstTurn();
}

Nulocks::Core::Board::~Board() {
        if(_board != NULL) {
                for(int i = 0; i < _size; i++) {
                        delete[] _board[i];
                }
                delete[] _board;
        }
        _board = NULL;
        _score = 0;
        _size = 0;
        _status = 0;
        _winpower = 0;
}

Nulocks::Core::Board::Board(const Nulocks::Core::Board& cpy) {
        _board = NULL;
        if(cpy._board != NULL) {
        _board = new Nulocks::Core::Block*[cpy._size];
                for(int i = 0; i < cpy._size; i++) {
                        _board[i] = new Nulocks::Core::Block[cpy._size];
                }
                for(int i = 0; i < cpy._size; i++) {
                        for(int j = 0; j < cpy._size; j++) {
                               _board[i][j] = cpy._board[i][j]; 
                        }
                }                        
        }
        _score = cpy._score;
        _size = cpy._size;
        _status = cpy._status;
        _winpower = cpy._winpower;
}

void Nulocks::Core::Board::startNextTurn() {
        srand(time(NULL));
        bool anythingEmpty = false;
        for(int i = 0; i < _size; i++) {
               for(int j = 0; j < _size; j++) {
                       _board[i][j].unsetMoved();
                       if(_board[i][j].isEmpty()) {
                               anythingEmpty = true;
                       }
                       if(_board[i][j].getLevel() == _winpower) {
                               _status = 1;
                       }
               }
        }
        if(anythingEmpty) {
                int x, y;
                do {
                        x = rand()%_size;
                        y = rand()%_size;
                } while(!_board[x][y].isEmpty());
                _board[x][y].levelUp();
        } else {
                if(_status == 0) {
                        _status = 2;
                }
        }
}

void Nulocks::Core::Board::startFirstTurn() {
        srand(time(NULL));
        int x, y;
        do {
                x = rand()%_size;
                y = rand()%_size;
        } while(!_board[x][y].isEmpty());
        _board[x][y].levelUp();
        do {
                x = rand()%_size;
                y = rand()%_size;
        } while(!_board[x][y].isEmpty());
        int det = rand()%8;
        _board[x][y].levelUp();
        if(det == 4) {
                _board[x][y].levelUp();
        }
}

void Nulocks::Core::Board::moveUp() {
        for(int j = 0; j < _size; j++) {
                for(int i = 0; i < _size; i++) {
                        int curx = i;
                        int cury = j;
                        if(!_board[curx][cury].isEmpty()) {
                                bool done = false;
                                while(!done) {
                                        if(curx-1 < 0) {
                                                done = true;
                                        } else if(_board[curx-1][cury].isEmpty()) {
                                                _board[curx-1][cury].setLevel(_board[curx][cury].getLevel());
                                                _board[curx][cury].empty();
                                                curx--;
                                        } else if(_board[curx-1][cury].getLevel() == _board[curx][cury].getLevel() && !_board[curx][cury].wasMoved() && !_board[curx-1][cury].wasMoved()) {
                                                _board[curx-1][cury].levelUp();
                                                _board[curx-1][cury].setMoved();
                                                _board[curx][cury].empty();
                                                _score += _board[curx-1][cury].getValue();
                                        } else {
                                                done = true;
                                        }
                                }
                        }
                }
        }
        startNextTurn();
}

void Nulocks::Core::Board::moveDown() {
        for(int j = 0; j < _size; j++) {
                for(int i = _size-1; i >= 0; i--) {
                        int curx = i;
                        int cury = j;
                        if(!_board[curx][cury].isEmpty()) {
                                bool done = false;
                                while(!done) {
                                        if(curx+1 >= _size) {
                                                done = true;
                                        } else if(_board[curx+1][cury].isEmpty()) {
                                                _board[curx+1][cury].setLevel(_board[curx][cury].getLevel());
                                                _board[curx][cury].empty();
                                                curx++;
                                        } else if(_board[curx+1][cury].getLevel() == _board[curx][cury].getLevel() && !_board[curx][cury].wasMoved() && !_board[curx+1][cury].wasMoved()) {
                                                _board[curx+1][cury].levelUp();
                                                _board[curx+1][cury].setMoved();
                                                _board[curx][cury].empty();
                                                _score += _board[curx+1][cury].getValue();
                                        } else {
                                                done = true;
                                        }
                                }
                        }
                }
        }
        startNextTurn();
}

void Nulocks::Core::Board::moveLeft() {
        for(int i = 0; i < _size; i++) {
                for(int j = 0; j < _size; j++) {
                        int curx = i;
                        int cury = j;
                        if(!_board[curx][cury].isEmpty() && !_board[curx][cury].wasMoved()) {
                                bool done = false;
                                while(!done) {
                                        if(cury-1 < 0) {
                                                done = true;
                                        } else if(_board[curx][cury-1].isEmpty()) {
                                                _board[curx][cury-1].setLevel(_board[curx][cury].getLevel());
                                                _board[curx][cury].empty();
                                                cury--;
                                        } else if(_board[curx][cury-1].getLevel() == _board[curx][cury].getLevel() && !_board[curx][cury].wasMoved() && !_board[curx][cury-1].wasMoved()) {
                                                _board[curx][cury-1].levelUp();
                                                _board[curx][cury-1].setMoved();
                                                _board[curx][cury].empty();
                                                _score += _board[curx][cury-1].getValue();
                                        } else {
                                                done = true;
                                        }
                                }
                        }
                }
        }
        startNextTurn();
}

void Nulocks::Core::Board::moveRight() {
        for(int i = 0; i < _size; i++) {
                for(int j = _size-1; j >= 0; j--) {
                        int curx = i;
                        int cury = j;
                        if(!_board[curx][cury].isEmpty() && !_board[curx][cury].wasMoved()) {
                                bool done = false;
                                while(!done) {
                                        if(cury+1 >= _size) {
                                                done = true;
                                        } else if(_board[curx][cury+1].isEmpty()) {
                                                _board[curx][cury+1].setLevel(_board[curx][cury].getLevel());
                                                _board[curx][cury].empty();
                                                cury++;
                                        } else if(_board[curx][cury+1].getLevel() == _board[curx][cury].getLevel() && !_board[curx][cury].wasMoved() && !_board[curx][cury+1].wasMoved()) {
                                                _board[curx][cury+1].levelUp();
                                                _board[curx][cury+1].setMoved();
                                                _board[curx][cury].empty();
                                                _score += _board[curx][cury+1].getValue();
                                        } else {
                                                done = true;
                                        }
                                }
                        }
                }
        }
        startNextTurn();
}

bool Nulocks::Core::Board::gameInProgress() {
        return _status == 0;
}

bool Nulocks::Core::Board::gameWon() {
        return _status == 1;
}

bool Nulocks::Core::Board::gameLost() {
        return _status == 2;
}

int Nulocks::Core::Board::getScore() {
        return _score;
}

int Nulocks::Core::Board::getWinPower() {
        return _winpower;
}

int Nulocks::Core::Board::getSize() {
        return _size;
}

void Nulocks::Core::Board::getRepresentation(int*** repr) {
        for(int i = 0; i < _size; i++) {
                for(int j = 0; j < _size; j++) {
                        (*repr)[i][j] = _board[i][j].getValue();
                }
        }
}
