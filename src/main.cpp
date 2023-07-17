#include "bitboards.h"
#include "display.h"
#include <iostream>
#include "lazygen.h"

int main(){
    Board board;
    board.init();
    displayBoard(board);

    std::vector<PawnMove> moves = genPawnMove(board, 10, board.whiteToMove);

    for (int i = 0; i < moves.size(); i++){
        std::cout << moves[i].target << std::endl;
    }

    std::cout << moves.size() << std::endl;

    return 0;
}