#include "bitboards.h"
#include "display.h"
#include <iostream>

int main(){
    Board board;
    board.init();
    displayBoard(board);

    return 0;
}