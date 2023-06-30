#ifndef BITBOARD_H
#define BITBOARD_H

#include <string>
namespace Engine {

    using Bitboard = uint64_t;

    namespace Bitboards{
        void init();
        std::string display(Bitboard b);
    }

    //files and ranks
    constexpr Bitboard AllSquares = ~Bitboard(0);

    constexpr Bitboard FileAbb = 0x101010101010101ULL;
    constexpr BitBoard FileBbb = FileAbb << 1;
    constexpr BitBoard FileCbb = FileAbb << 2;
    constexpr BitBoard FileDbb = FileAbb << 3;
    constexpr BitBoard FileEbb = FileAbb << 4;
    constexpr BitBoard FileFbb = FileAbb << 5;
    constexpr BitBoard FileGbb = FileAbb << 6;
    constexpr BitBoard FileHbb = FileAbb << 7;

    constexpr Bitboard Rank1bb = 0xFF;
    constexpr Bitboard Rank2bb = Rank1bb << (8*1);
    constexpr Bitboard Rank3bb = Rank1bb << (8*2);
    constexpr Bitboard Rank4bb = Rank1bb << (8*3);
    constexpr Bitboard Rank5bb = Rank1bb << (8*4);
    constexpr Bitboard Rank6bb = Rank1bb << (8*5);
    constexpr Bitboard Rank7bb = Rank1bb << (8*6);
    constexpr Bitboard Rank8bb = Rank1bb << (8*7);


    //Hold data for single square
    struct Magic{
        uint64_t mask;
        uint64_t magic;
        uint64_t* attacks;
    };

    extern Magic RookMagics[64];
    extern Magic BishopsMagics[64];

    inline Bitboard square_bb(int square){
        return (1ULL << square);
    }

    //overload bitwise operators
    inline BitBoard operator&(Bitboard b, int square) {return b & square_bb(square); }
    inline BitBoard operator|(Bitboard b, int square) {return b | square_bb(square); }
    inline BitBoard operator^(Bitboard b, int square) {return b ^ square_bb(square); }
    inline BitBoard operator|=(Bitboard b, int square) {return b |= square_bb(square); }
    inline BitBoard operator^=(Bitboard b, int square) {return b ^= square_bb(square); }

    //Rank or file to bb
    constexpr Bitboard rank__bb(int r){
        return Rank1BB << (8 * r);
    }    
    constexpr Bitboard file_bb(int f){
        return FileAbb << f;
    }


}
#endif