#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <string>
#include <cstdint>

namespace Bitboards {

    using Bitboard = uint64_t;

    //Bitboards::init() will be used to initialize all bitboards needed for the game
    //Global objects will be initialized in this header file
    void init();

    //Bitboards for files and ranks used later
    constexpr Bitboard FileA = 0x101010101010101ULL;
    constexpr Bitboard FileB = FileA << 1;
    constexpr Bitboard FileC = FileA << 2;
    constexpr Bitboard FileD = FileA << 3;
    constexpr Bitboard FileE = FileA << 4;
    constexpr Bitboard FileF = FileA << 5;
    constexpr Bitboard FileG = FileA << 6;
    constexpr Bitboard FileH = FileA << 7;

    constexpr Bitboard Rank1 = 0xFF;
    constexpr Bitboard Rank2 = Rank1 << (8*1);
    constexpr Bitboard Rank3 = Rank1 << (8*2);
    constexpr Bitboard Rank4 = Rank1 << (8*3);
    constexpr Bitboard Rank5 = Rank1 << (8*4);
    constexpr Bitboard Rank6 = Rank1 << (8*5);
    constexpr Bitboard Rank7 = Rank1 << (8*6);
    constexpr Bitboard Rank8 = Rank1 << (8*7);

    //Declare piece type bitboards
    extern Bitboard whitePawns;
    extern Bitboard whiteKnights;
    extern Bitboard whiteBishops;
    extern Bitboard whiteRooks;
    extern Bitboard whiteQueens;
    extern Bitboard whiteKing;

    extern Bitboard blackPawns;
    extern Bitboard blackKnights;
    extern Bitboard blackBishops;
    extern Bitboard blackRooks;
    extern Bitboard blackQueens;
    extern Bitboard blackKing;


    extern Bitboard occupied;
    extern void updateOccupied();

    //Enum squares for better readability
    //SQ_A1 = 0, SQ_B1 = 1...
    enum Square : int {
        SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
        SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
        SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
        SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
        SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
        SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
        SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
        SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8
    };

    //Side to move
    enum Side : std::uint8_t {
        WHITE,
        BLACK
    };

    extern Side sideToMove;
    extern void updateSide();
}
#endif