#include <cstdint>
#include "bitboards.h"
#include <array>

using Bitboard = uint64_t;

namespace Sliding{
    
    //Store precomputed diagonal attacks
    
    std::vector<Bitboard> main_diagonal(64);
    std::vector<Bitboard> anti_diagonal(64);


    //On demand diagonal
    Bitboard diagonal_magic_mask(int origin) {
        Bitboard mask = 0;

        int file = origin % 8;
        int rank = origin / 8;
        int start = origin - (std::min(rank, file) * 9);

        for (int i = start; i < 64; i+=9){
            mask |= (1ULL << (i));
            if (i % 8 == 7 || i / 8 == 7){
                break;
            }
        }
        return mask & (~Bitboards::Rank1 & ~Bitboards::Rank8 & ~(1ULL << origin))
                    & (~Bitboards::FileA & ~Bitboards::FileH & ~(1ULL << origin));
    }

    Bitboard diagonal_move_mask(int origin) {
        Bitboard mask = 0;

        int file = origin % 8;
        int rank = origin / 8;
        int start = origin - (std::min(rank, file) * 9);

        for (int i = start; i < 64; i+=9){
            mask |= (1ULL << (i));
            if (i % 8 == 7 || i / 8 == 7){
                break;
            }
        }
        return mask;
    }

    //bishop masks ignoring edge and origin squares
    Bitboard anti_diagonal_magic_mask(int origin) {
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
        return mask & (~Bitboards::Rank1 & ~Bitboards::Rank8 & ~(1ULL << origin))
                    & (~Bitboards::FileA & ~Bitboards::FileH & ~(1ULL << origin));
    }

    Bitboard anti_diagonal_move_mask(int origin) {
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

    //move masks for available squares, magic masks for magic calculations
    Bitboard NS_move_mask(int origin){
        return 0x101010101010101 << (origin % 8);
    }

    Bitboard NS_magic_mask(int origin){

        Bitboard column_mask = 0x101010101010101 << (origin % 8);

        return (column_mask) & ~Bitboards::Rank1 & ~Bitboards::Rank8 & ~(1ULL << origin);
    }

    Bitboard EW_move_mask(int origin){
        return 0xffULL << (8 * (origin / 8));
    }

    Bitboard EW_magic_mask(int origin){
        Bitboard rank_mask = 0xffULL << (8 * (origin / 8));
        return (rank_mask) & ~Bitboards::FileA & ~Bitboards::FileH & ~(1ULL << origin);
    }





    //Making sliding piece non-blocking move gen

    Bitboard rookPseudoGen(int origin){
        return NS_magic_mask(origin) | EW_magic_mask(origin);
    }

    Bitboard bishopPseudoGen(int origin){
        return diagonal_magic_mask(origin) | anti_diagonal_magic_mask(origin);
    }

    Bitboard queenPseudoGen(int origin){
        return rookPseudoGen(origin) | bishopPseudoGen(origin);
    }
}