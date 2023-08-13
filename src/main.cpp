#include "bitboards.h"
#include "display.h"
#include <iostream>
#include "lazygen.h"
#include <chrono>
#include <bitset>
#include "sliding.h"
#include <string>

int main() {
    Board board;
    board.init();
    board.clear();
    //board.fill(Sliding::bishopPseudoGen(1), true, BISHOP);
    //displayBoard(board);
    //board.fill(EW_rook_mask(0), true, ROOK);
    //board.fill(NS_rook_mask(53), true, ROOK);
    /*for (int i = 63; i >= 0; i--){
        board.fill(Sliding::bishopPseudoGen(i), true, BISHOP);
        //std::cout << (Sliding::diagonal_mask(i)) << std::endl;
        displayBoard(board);
        board.clear();
    }*/
    //std::cout << (Sliding::diagonal_mask(i)) << std::endl;
    

    int input;

    while (true) {
        std::cout << "Enter an index (0-63) or '-1' to exit: ";
        std::cin >> input;
        
        if (input == -1) {
            break;
        }
        

        if (input >= 0 && input < 64) {
            board.fill(Sliding::queenPseudoGen(input), true, BISHOP);
            
            std::cout << "Mask for Index " << input << ":" << std::endl;
            displayBoard(board);
        
        } else {
            std::cout << "Invalid input. Please enter an index between 0 and 63." << std::endl;
        }
        board.clear();
    }

    

    /*auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> time_taken = end - start;
    std::cout << "Time taken by program is: " << time_taken.count() << " sec" << std::endl;
    */
   
    return 0;
}
