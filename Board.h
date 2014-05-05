#ifndef _BOARD_H
#define _BOARD_H
#include "Block.h"
/// \file Board.h
/// \brief A file that contains main core engine class of Nulocks - modular and customizable clone of 2048 game.
/// \author Phitherek_
/// \date 2014
/// \version 0.1

/// \namespace Nulocks
/// \brief A global namespace for all Nulocks game components.
namespace Nulocks {
	/// \namespace Nulocks::Core
	/// \brief A namespace for Nulocks core game engine.
        namespace Core {
        	/// \class Board
        	/// \brief A class that represents Nulocks board.
                class Board {
                private:
                        Block** _board;
                        int _score;
                        int _status;
                        int _winpower;
                        int _size;
                        void startNextTurn();
                        void startFirstTurn();
                public:
                        Board(int size=4, int winpower=11); ///< \brief Initializes the board for the new game.
                        ///< \param size Size of the board, defaults to 4 as in original 2048.
                        ///< \param winpower Power of 2 to get to win the game. Defaults to 11, as in original 2048 game.
                        ~Board(); ///< Destroys the board, frees the memory.
                        Board(const Board& cpy); ///< \brief A copy constructor.
                        ///< \param cpy A Board object to be copied.
                        void moveUp(); ///< Performs a move upwards and starts new turn.
                        void moveDown(); ///< Performs a move downwards and starts new turn.
                        void moveLeft(); ///< Performs a move to the left and starts new turn.
                        void moveRight(); ///< Performs a move to the right and starts new turn.
                        bool gameInProgress(); ///< \brief Checks if game is in progress.
                        ///< \return True if game is in progress, false otherwise.
                        bool gameWon(); ///< \brief Checks if game has been won.
                        ///< \return True if game has been won, false otherwise.
                        bool gameLost(); ///< \brief Checks if game has been lost.
                        ///< \return True if game has been lost, false otherwise.
                        int getScore(); ///< \brief Returns the current score.
                        ///< \return Current score of the player.
                        int getWinPower(); ///< \brief Returns the power of 2 required to win the game.
                        ///< \return Power of 2 to get to win the game.
                        int getSize(); ///< \brief Returns size of the board.
                        ///< \return Size of the board.
                        void getRepresentation(int*** repr); ///< \brief Returns representation of the board as an array of integers.
                        ///< \param[in,out] repr Takes address of a two-dimensional array of integers with the same size as the board. Returns integer representation of the board to this array. Memory allocation and freeing must be handled outside this method.
                };
        }
}
#endif
