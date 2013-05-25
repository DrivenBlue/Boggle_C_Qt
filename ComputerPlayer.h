#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "BaseBogglePlayer.h"

class ComputerPlayer : private BaseBogglePlayer {
    public:
        ComputerPlayer();
        ~ComputerPlayer();

        virtual setBoard(unsigned int rows, unsigned int cols, string **diceArray);
    private:
        string **diceArray;
        unsigned int rows;
        unsigned int cols;
};

ComputerPlayer::ComputerPlayer() : rows(0), cols(0), diceArray(nullptr) {}


ComputerPlayer::~ComputerPlayer() {
    if(diceArray) {
        for(int i = 0; i < cols; ++i){
            delete this->diceArray[i];
        }
    }
}

ComputerPlayer::setBoard(unsigned int rows, unsigned int cols, string **diceArray) {
    this->rows = rows;
    this->cols = cols;

    this->diceArray = new string*[cols];
    for(int i = 0; i < cols; ++i) {
        this->diceArray = new string[rows];
    }

}



#endif // COMPUTERPLAYER_H
