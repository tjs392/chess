#include "bitboards.h"
#include "display.h"
#include <iostream>
#include "lazygen.h"
#include <chrono>

int main() {
    Board board;
    board.init();
    displayBoard(board);

    

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<PawnMove> move = genPawnMove(board, 9, board.whiteToMove);
    

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_taken = end - start;
    std::cout << "Time taken by program is: " << time_taken.count() << " sec" << std::endl;

    return 0;
}
