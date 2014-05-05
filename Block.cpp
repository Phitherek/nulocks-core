#include "Block.h"
#include <cmath>

Nulocks::Core::Block::Block() {
        _value = 0;
        _movedThisTurn = false;
}

Nulocks::Core::Block::~Block() {
        _value = 0;
        _movedThisTurn = false;
}

void Nulocks::Core::Block::setMoved() {
        _movedThisTurn = true;
}

void Nulocks::Core::Block::unsetMoved() {
        _movedThisTurn = false;
}

bool Nulocks::Core::Block::wasMoved() {
        return _movedThisTurn;
}

int Nulocks::Core::Block::getValue() {
        return _value;
}

int Nulocks::Core::Block::getLevel() {
        if(_value == 0) {
                return 0;
        } else {
                return log2(_value);
        }
}

void Nulocks::Core::Block::levelUp() {
        if(_value == 0) {
                _value = 2;
        } else {
                _value = _value*2;
        }
}

void Nulocks::Core::Block::empty() {
        _value = 0;
}

bool Nulocks::Core::Block::isEmpty() {
        return _value == 0;
}

void Nulocks::Core::Block::setLevel(int level) {
        _value = pow(2, level);
}
