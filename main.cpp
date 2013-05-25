#include "BogglePlayer.h"
#include "boggleboard.h"

const int MAX_ROWS = 4;
const int MAX_COLS = 4;

int main(int argc, char *argv[]) {
    GUIBoggleBoard Skynet = GUIBoggleBoard(NULL, MAX_ROWS, MAX_COLS);
    BogglePlayer T100 = BogglePlayer();
    Skynet.initRandomBoard();

    T100.setBoard(MAX_ROWS, MAX_COLS, Skynet.board);
    T100.printBoard();
}
