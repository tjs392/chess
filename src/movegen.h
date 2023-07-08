#ifndef MOVEGEN_H
#define MOVEGEN_H

#include "bitboards.h"
#include <vector>
#include <map>
#include <cstdint>

using Bitboard = uint64_t;

enum PawnMoveType{
    SINGLE,
    DOUBLE,
    CAPTURE,
    PROMOTION
};

//Simple move structure to store origin and target squares
struct Move {
    Square origin;
    Square target;
};


//Generate moves for each piece
//General move gen functions
std::vector<Move> genPawnMoves() {
    std::vector<Move> moves;

    Bitboard pawns = (Bitboards::sideToMove == Bitboards::WHITE) ? Bitboards::whitePawns : Bitboards::blackPawns;

    //Empty bitboard for pawn moves
    Bitboard pawnMoves = 0ULL;

    if (Bitboards::sideToMove == Bitboards::WHITE){
        Bitboard singleForward = (pawns << 8) & ~Bitboards::occupied;
        Bitboard doubleForward = ((singleForward & Bitboards::Rank3) << 8) & ~Bitboards::occupied;
        pawnMoves |= singleForward | doubleForward;

        //pawn captures
        Bitboard leftCapture = ((pawns & ~Bitboards::FileA) << 7);
        Bitboard rightCapture = ((pawns & ~Bitboards::FileH) << 9);
        Bitboard pawnCaptures = leftCapture | rightCapture;
        pawnMoves |= pawnCaptures;

        //ignore promotions for now, will be checking for promotion on demand
        //do not worry about rank 8 and 1, because pawns will be instantly promoted
        //and removed from pawn bitboard
    }

    //for black
    else{
        Bitboard singleForward = (pawns >> 8) & ~Bitboards::occupied;
        Bitboard doubleForward = ((singleForward & Bitboards::Rank6) >> 8) & ~Bitboards::occupied;
        pawnMoves |= singleForward | doubleForward;

        Bitboard leftCapture = ((pawns & ~Bitboards::FileH) >> 7);
        Bitboard rightCapture = ((pawns & ~Bitboards::FileA >> 9));
        Bitboard pawnCaptures = leftCapture | rightCapture;
        pawnMoves |= pawnCaptures;
    }

    //Populate vector::moves with move objects
    for (int square = SQ_A1; square < SQ_65; square++){
        //check if pawn is on the square
        if (pawns & (1ULL << square)){
            Move move;
        }
    }
    

}


#endif