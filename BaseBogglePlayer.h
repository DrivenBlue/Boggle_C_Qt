#ifndef BASEBOGGLEPLAYER_H
#define BASEBOGGLEPLAYER_H
#include <iostream>

using std::vector;
using std::set;
using std::string;

class BaseBogglePlayer {
public:
    virtual void setBoard(unsigned int rows, unsigned int cols, string **diceArray) = 0;
    virtual void ~BaseBogglePlayer(){}
};

#endif // BASEBOGGLEPLAYER_H
