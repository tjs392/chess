#include "bitboards.h"
#include "display.h"
#include <iostream>
#include "lazygen.h"
#include <chrono>
#include <bitset>
#include "sliding.h"

int main() {
    Board board;
    board.init();
    board.clear();
    //board.fill(EW_rook_mask(0), true, ROOK);
    //board.fill(NS_rook_mask(53), true, ROOK);
    displayBoard(board);

    

    /*auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> time_taken = end - start;
    std::cout << "Time taken by program is: " << time_taken.count() << " sec" << std::endl;
    */
   
    return 0;
}
