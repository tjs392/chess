#ifndef MAGIC_H
#define MAGIC_H

#include <cstdint>
#include "sliding.h"

using Bitboard = uint64_t;

//Magic number generation for bishops and rooks

//Blocker mask contains all squares that can block a piece, no edge (magic mask)
//Blocker board contains occupied squares & blocker mask
//Move board contains all possible moves (move mask)

Bitboard genBlockerBoard(int index, Bitboard blocker_mask){
    Bitboard blocker_board = blocker_mask;
    uint8_t bit_index = 0;

    for (uint8_t i = 0; i < 64; i++){
        if (blocker_mask & (1ULL << i)){
            if (!(index & (1 << bit_index))){
                blocker_board &= ~(1ULL << i);
            }
            bit_index++;
        }
    }
    return blocker_board;
}

#endif