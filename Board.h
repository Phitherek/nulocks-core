#ifndef _BOARD_H
#define _BOARD_H
#include "Block.h"

namespace Nulocks {
        namespace Core {
                class Board {
                private:
                        Block** _board;
                        int _score;
                        int _status;
                        int _winpower;
                        void startNextTurn();
                public:
                        Board(int size=4, int winpower=11);
                        ~Board();
                        Board(const Board& cpy);
                        void moveUp();
                        void moveDown();
                        void moveLeft();
                        void moveRight();
                        bool gameInProgress();
                        bool gameWon();
                        bool gameFailed();
                        int getScore();
                        int getWinPower();
                };
        }
}
