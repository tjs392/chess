#include "bitboards.h"
#include "display.h"
#include <iostream>
#include "lazygen.h"
#include <chrono>
#include <bitset>

int main() {
    Board board;
    board.init();
    displayBoard(board);

    

    auto start = std::chrono::high_resolution_clock::now();

    Bitboard targets = genKnightMoves(board, 1, board.whiteToMove);
    std::cout << std::bitset<64>(targets) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> time_taken = end - start;
    std::cout << "Time taken by program is: " << time_taken.count() << " sec" << std::endl;

    return 0;
}
