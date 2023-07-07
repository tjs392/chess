#include "bitboards.h"

void Bitboards::init(){

    //Starting position for each piece
    Bitboard whitePawns = Rank2;
    Bitboard whiteKnights = (FileB | FileG) & Rank1;
    Bitboard whiteBishops = (FileC | FileF) & Rank1;
    Bitboard whiteRooks = (FileA | FileH) & Rank1;
    Bitboard whiteQueens = FileD & Rank1;
    Bitboard whiteKing = FileE & Rank1;

    Bitboard blackPawns = Rank7;
    Bitboard blackKnights = (FileB | FileG) & Rank7;
    Bitboard blackBishops = (FileC | FileF) & Rank7;
    Bitboard blackRooks = (FileA | FileH) & Rank7;
    Bitboard blackQueens = FileD & Rank7;
    Bitboard blackKing = FileE & Rank7;

    Bitboard occupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing | blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;

    Side sideToMove = WHITE;
}

void Bitboards::updateOccupied(){
    occupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing | blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
}

void Bitboards::updateSide(){
    sideToMove = (sideToMove==WHITE) ? BLACK : WHITE;
}

