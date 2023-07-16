#ifndef LAZYGEN_H
#define LAZYGEN_H

#include "bitboards.h"
#include <vector>

//Lazy gen will be used for knights and pawns, which have easy move gen
//Move generation will be on-demand for these

enum PawnMoveType{
    SINGLE,
    DOUBLE,
    CAPTURE,
    ENPASSANT,
    PROMOTION
};
//Move structure for target-origin
struct PawnMove{
    int target;
    int origin;
    PawnMoveType moveType;
};

//Generation for pseudo-legal pawn moves
//Generation for pawn moves will be on-demand
//IE moves will not be all generated at once at the start of the turn

std::vector<PawnMove> genPawnMove(Board& board, int origin, bool whiteToMove){

    std::vector<PawnMove> moves;

    //Reserve 6 for memory (make sure to moves.clear() at the end of usage)
    moves.reserve(6);

    Bitboard origin_BB = 1ULL << origin;

    Bitboard single_forward = (whiteToMove) ? (origin_BB << 8) & board.occupied : origin_BB >> 8 & board.occupied;
    if (single_forward != 0){
        PawnMove single;
        single.target = (whiteToMove) ? (origin + 8) : (origin - 8);
        single.origin = origin;
        single.moveType = SINGLE;
        moves.push_back(single);

        bool canDouble = (whiteToMove) ? (origin_BB & Bitboards::Rank2) : (origin_BB & Bitboards::Rank7);
        if (canDouble){
            Bitboard double_forward = (whiteToMove) ? (single_forward << 8) & board.occupied : (single_forward >> 8) & board.occupied;
            if (double_forward != 0){
                PawnMove double_m;
                double_m.target = (whiteToMove) ? (single.target + 8) : (single.target - 8);
                double_m.origin = origin;
                double_m.moveType = DOUBLE;
                moves.push_back(double_m);
            }
        }
    }

};


#endif