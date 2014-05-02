#ifndef _BLOCK_H
#define _BLOCK_H
namespace Nulocks {
        namespace Core {
                class Block {
                private:
                        int _value;
                        bool _movedThisTurn;
                public:
                        Block();
                        ~Block();
                        void setMoved();
                        void unsetMoved();
                        bool wasMoved();
                        int getValue();
                        int getLevel();
                        void levelUp();
                        void empty();
                        bool isEmpty();
                        void setLevel(int level);
                };
        }
}
#endif
