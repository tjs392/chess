#include "bitboards.h"

void Board::init() {

    white_pawns = Bitboards::Rank2;
    white_knights = (Bitboards::FileB | Bitboards::FileG) & Bitboards::Rank1;
    white_bishops = (Bitboards::FileC | Bitboards::FileF) & Bitboards::Rank1;
    white_rooks = (Bitboards::FileA | Bitboards::FileH) & Bitboards::Rank1;
    white_queens = Bitboards::FileD & Bitboards::Rank1;
    white_king = Bitboards::FileE & Bitboards::Rank1;

    black_pawns = Bitboards::Rank7;
    black_knights = (Bitboards::FileB | Bitboards::FileG) & Bitboards::Rank8;
    black_bishops = (Bitboards::FileC | Bitboards::FileF) & Bitboards::Rank8;
    black_rooks = (Bitboards::FileA | Bitboards::FileH) & Bitboards::Rank8;
    black_queens = Bitboards::FileD & Bitboards::Rank8;
    black_king = Bitboards::FileE & Bitboards::Rank8;

    white_occupied = white_pawns | white_knights | white_bishops | white_rooks | white_queens | white_king;
    black_occupied = black_pawns | black_knights | black_bishops | black_rooks | black_queens | black_king;
    occupied = white_occupied | black_occupied;

    whiteToMove = true;
}