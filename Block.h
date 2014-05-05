#ifndef _BLOCK_H
#define _BLOCK_H
/// \file Block.h
/// \brief A file that contains the class representing a block on the game board.
/// \author Phitherek_
/// \date 2014
/// \version 0.1

/// \namespace Nulocks
/// \brief A global namespace for all Nulocks game components.
namespace Nulocks {
	/// \namespace Nulocks::Core
	/// \brief A namespace for Nulocks core game engine.
        namespace Core {
        	/// \class Block
        	/// \brief A class representing a block on the game board.
                class Block {
                private:
                        int _value;
                        bool _movedThisTurn;
                public:
                        Block(); ///< Construct an empty block.
                        ~Block(); ///< Destroy the block.
                        void setMoved(); ///< Indicate the block as moved this turn.
                        void unsetMoved(); ///< Indicate the block as not moved this turn.
                        bool wasMoved(); ///< \brief Check if the block was moved this turn.
                        ///< \return True if block was moved this turn, false otherwise.
                        int getValue(); ///< \brief Get block value.
                        ///< \return Value of the block.
                        int getLevel(); ///< \brief Get block level.
                        ///< \return Level of the block.
                        void levelUp(); ///< Increase level of the block.
                        void empty(); ///< Make the block empty.
                        bool isEmpty(); ///< \brief Check if the block is empty.
                        ///< \return True if the block is empty, false otherwise.
                        void setLevel(int level); ///< \brief Set level of the block.
                        ///< \param level Level of the block.
                };
        }
}
#endif
