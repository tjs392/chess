#include "display.h"
#include <iostream>


void displayBoard(Board& board) {
    std::cout << "  A B C D E F G H" << std::endl;
    std::cout << "  _ _ _ _ _ _ _ _" << std::endl;

    Bitboard current = Bitboards::FileA & Bitboards::Rank8;
    for (int rank = 8; rank >= 1; rank--) {
        std::cout << rank << "|";
        int shift = 8 - rank;
        for (int file = 0; file < 8; file++) {
            Bitboard current = 1ULL << (rank * 7) + (file - shift);
            if (board.occupied & current) {
                bool is_white = (board.white_pawns & current)
                    || (board.white_knights & current)
                    || (board.white_bishops & current)
                    || (board.white_rooks & current)
                    || (board.white_queens & current)
                    || (board.white_king & current);

                // Upper case for white, lower case for black
                char piece_symbol;
                if (is_white) {
                    if (board.white_pawns & current) {
                        piece_symbol = 'P';
                    } else if (board.white_knights & current) {
                        piece_symbol = 'N';
                    } else if (board.white_bishops & current) {
                        piece_symbol = 'B';
                    } else if (board.white_rooks & current) {
                        piece_symbol = 'R';
                    } else if (board.white_queens & current) {
                        piece_symbol = 'Q';
                    } else if (board.white_king & current) {
                        piece_symbol = 'K';
                    }
                } else {
                    if (board.black_pawns & current) {
                        piece_symbol = 'p';
                    } else if (board.black_knights & current) {
                        piece_symbol = 'n';
                    } else if (board.black_bishops & current) {
                        piece_symbol = 'b';
                    } else if (board.black_rooks & current) {
                        piece_symbol = 'r';
                    } else if (board.black_queens & current) {
                        piece_symbol = 'q';
                    } else if (board.black_king & current) {
                        piece_symbol = 'k';
                    }
                }

                std::cout << piece_symbol << " ";
            } else {
                std::cout << ". ";
            }

            current <<= 1;  // Move to the next file
        }

        std::cout << "|" << rank << std::endl;
    }

    std::cout << "  - - - - - - - -" << std::endl;
    std::cout << "  A B C D E F G H" << std::endl;
}



