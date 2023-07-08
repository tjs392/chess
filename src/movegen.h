#ifndef MOVEGEN_H
#define MOVEGEN_H

#include "bitboards.h"
#include <vector>
#include <cstdint>

using Bitboard = uint64_t;


struct Move {
    int origin;
    int target;

};


//Generate moves for each piece
//General move gen functions
std::vector<Bitboard> genPawnMoves(Square square){
    std::vector<Move> moves;

    Bitboard pawns = (Bitboards::sideToMove == Bitboards::WHITE) ? Bitboards::whitePawns : Bitboards::blackPawns;

    //Empty bitboard for pawn moves
    Bitboard pawnMoves = 0ULL;

    if (Bitboards::sideToMove == Bitboards::WHITE){
        Bitboard singleForward = (pawns << 8) & ~Bitboards::occupied;
        Bitboard doubleForward = ((singleForward & Bitboards::Rank3) << 8) * ~Bitboards::occupied;
        pawnMoves |= singleForward | doubleForward;

        //pawn captures
        //NOT FINISHED
        Bitboard leftCapture = ((pawns & ~Bitboards::FileA) << 7)
    }
    

}


#endif