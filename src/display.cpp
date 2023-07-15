#include "display.h"
#include <iostream>


void displayBoard(Board& chess_board) {
    std::cout << "  A B C D E F G H" << std::endl;
    std::cout << "  _ _ _ _ _ _ _ _" << std::endl;

    Bitboard current = Bitboards::FileA & Bitboards::Rank8;
    for (int rank = 8; rank >= 1; rank--) {
        std::cout << rank << "|";
        int shift = 8 - rank;
        for (int file = 0; file < 8; file++) {
            Bitboard current = 1ULL << (rank * 7) + (file - shift);
            if (chess_board.occupied & current) {
                bool is_white = (chess_board.white_pawns & current)
                    || (chess_board.white_knights & current)
                    || (chess_board.white_bishops & current)
                    || (chess_board.white_rooks & current)
                    || (chess_board.white_queens & current)
                    || (chess_board.white_king & current);

                // Print the piece symbol
                char piece_symbol;
                if (is_white) {
                    if (chess_board.white_pawns & current) {
                        piece_symbol = 'P';
                    } else if (chess_board.white_knights & current) {
                        piece_symbol = 'N';
                    } else if (chess_board.white_bishops & current) {
                        piece_symbol = 'B';
                    } else if (chess_board.white_rooks & current) {
                        piece_symbol = 'R';
                    } else if (chess_board.white_queens & current) {
                        piece_symbol = 'Q';
                    } else if (chess_board.white_king & current) {
                        piece_symbol = 'K';
                    }
                } else {
                    if (chess_board.black_pawns & current) {
                        piece_symbol = 'p';
                    } else if (chess_board.black_knights & current) {
                        piece_symbol = 'n';
                    } else if (chess_board.black_bishops & current) {
                        piece_symbol = 'b';
                    } else if (chess_board.black_rooks & current) {
                        piece_symbol = 'r';
                    } else if (chess_board.black_queens & current) {
                        piece_symbol = 'q';
                    } else if (chess_board.black_king & current) {
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



