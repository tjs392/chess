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

//Targets and origins will also be stored as ints for simplicity sake
std::vector<PawnMove> genPawnMove(Board& board, int origin, bool whiteToMove){

    
    std::vector<PawnMove> moves;

    //Reserve 6 for memory (make sure to moves.clear() at the end of usage)
    moves.reserve(6);

    Bitboard origin_BB = 1ULL << origin;

    //Single and double forward moves
    Bitboard single_forward = (whiteToMove) ? (origin_BB << 8) & ~board.occupied : origin_BB >> 8 & ~board.occupied;
    if (single_forward){
        PawnMove single;
        single.target = (whiteToMove) ? (origin + 8) : (origin - 8);
        single.origin = origin;
        single.moveType = SINGLE;
        moves.push_back(single);

        bool canDouble = (whiteToMove) ? (origin_BB & Bitboards::Rank2) : (origin_BB & Bitboards::Rank7);
        if (canDouble){
            Bitboard double_forward = (whiteToMove) ? (single_forward << 8) & ~board.occupied : (single_forward >> 8) & ~board.occupied;
            if (double_forward){
                PawnMove double_m;
                double_m.target = (whiteToMove) ? (single.target + 8) : (single.target - 8);
                double_m.origin = origin;
                double_m.moveType = DOUBLE;
                moves.push_back(double_m);
            }
        }
    }
    //Left and right capture
    Bitboard left_capture = (whiteToMove) ? (origin_BB << 7) & board.occupied : (origin_BB >> 7) & board.occupied;
    Bitboard right_capture = (whiteToMove) ? (origin_BB << 9) & board.occupied : (origin_BB >> 9) & board.occupied;

    if (left_capture){
        PawnMove left_cap;
        left_cap.target = (whiteToMove) ? (origin + 7) : (origin - 7);
        left_cap.origin = origin;
        left_cap.moveType = CAPTURE;
        moves.push_back(left_cap);
    }
    if (right_capture){
        PawnMove right_cap;
        right_cap.target = (whiteToMove) ? (origin + 9) : (origin - 9);
        right_cap.origin = origin;
        right_cap.moveType = CAPTURE;
        moves.push_back(right_cap);
    }

    return moves;

    //Deal with promotion and en passant later, I will need something to store previous moves** :)
}


#endif