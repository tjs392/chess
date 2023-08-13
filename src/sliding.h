#include <cstdint>
#include "bitboards.h"
#include <array>
\
using Bitboard = uint64_t;

namespace Sliding{
    
    //Store precomputed diagonal attacks
    
    std::vector<Bitboard> main_diagonal(64);
    std::vector<Bitboard> anti_diagonal(64);


    //On demand diagonal
    Bitboard diagonal_mask(int origin) {
        Bitboard mask = 0;

        int file = origin % 8;
        int rank = origin / 8;
        int start = origin - (std::min(rank, file) * 9);

        for (int i = start; i < 64; i+=9){
            mask |= (1ULL << (i));
            if (i % 8 == 7 || i / 8 == 7){return mask;}
        }
        return -1;
    }

    Bitboard anti_diagonal_mask(int origin) {
        Bitboard mask = 0;

        int file = origin % 8;
        int rank = origin / 8;
        int start = origin - (std::min(rank, 7 - file) * 7);

        for (int i = start; i < 64; i += 7) {
            mask |= (1ULL << i);
            if (i % 8 == 0 || i / 8 == 7) {
                break;
            }
        }
        return mask;
    }
    // On demand North-South and East_West masks
    Bitboard NS_mask(int origin){
        return 0x101010101010101 << ((origin % 8));
    }

    Bitboard EW_mask(int origin){
        return 0xffULL << (8 * (origin / 8));
    }




    //Making sliding piece non-blocking move gen

    Bitboard rookPseudoGen(int origin){
        return NS_mask(origin) | EW_mask(origin);
    }

    Bitboard bishopPseudoGen(int origin){
        return diagonal_mask(origin) | anti_diagonal_mask(origin);
    }

    Bitboard queenPseudoGen(int origin){
        return NS_mask(origin) | EW_mask(origin) | diagonal_mask(origin) | anti_diagonal_mask(origin);
    }
}