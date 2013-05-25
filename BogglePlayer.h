#ifndef BOGGLEPLAYER_H
#define BOGGLEPLAYER_H
#include "BaseBogglePlayer.h"

const int STRING_WIDTH = 5;

class BogglePlayer : private BaseBogglePlayer {
    public:
        BogglePlayer();
        ~BogglePlayer();

        virtual void setBoard(unsigned int rows, unsigned int cols, string **diceArray);
        void printBoard() const;

    private:
        void nukeBoard();

        string **cp_diceArray;
        unsigned int rows;
        unsigned int cols;
};

BogglePlayer::BogglePlayer() :  cp_diceArray(nullptr), rows(0), cols(0) {}


BogglePlayer::~BogglePlayer() {
    nukeBoard();
}

void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, string **diceArray) {
    nukeBoard();

    this->rows = rows;
    this->cols = cols;
    if(diceArray) {
        //make a deep copy of original
        cp_diceArray = new string*[rows];
        for(unsigned int i = 0; i < rows; ++i) {
            cp_diceArray[i] = new string[cols];

            //create a copy of contents in diceArray rows to cp_diceArray
            for(unsigned int j = 0; i < cols; ++j) {
                cp_diceArray[i][j] = diceArray[i][j];
            }
        }
    } else
        cp_diceArray = nullptr;
}

void BogglePlayer::nukeBoard() {
    if(cp_diceArray != nullptr) {
        for(unsigned int i = 0; i < rows; ++i){
            delete cp_diceArray[i];
        }
    }
}

void BogglePlayer::printBoard() const {
    if(cp_diceArray != nullptr) {
        for(unsigned int i = 0; i < rows; ++i) {
            for(unsigned int j = 0; j < cols; ++j) {
                std::cout << std::setw(STRING_WIDTH) << cp_diceArray[i][j];
            }
            std::cout << std::endl;
        }
    }
}


#endif // BOGGLEPLAYER_H
