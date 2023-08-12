#include <cstdint>
#include "bitboards.h"
#include <vector>

using Bitboard = uint64_t;


//Rook masks
Bitboard NS_rook_mask(int origin){
    return 0x101010101010101 << ((origin % 8));
}

Bitboard EW_rook_mask(int origin){
    return 0xffULL << (8 * (origin / 8));
}
//Making rook and bishop non-blocking move gen

Bitboard rookPseudoGen(Board& board, int origin){
    return 0;
}