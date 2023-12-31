#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <cstdint>
#include <vector>
#include <limits>

using Bitboard = uint64_t;

//Holds piece and game data for a single game instance
struct Board {
    Bitboard white_pawns;
    Bitboard white_knights;
    Bitboard white_bishops;
    Bitboard white_rooks;
    Bitboard white_queens;
    Bitboard white_king;

    Bitboard black_pawns;
    Bitboard black_knights;
    Bitboard black_bishops;
    Bitboard black_rooks;
    Bitboard black_queens;
    Bitboard black_king;

    Bitboard white_occupied;
    Bitboard black_occupied;
    Bitboard occupied;

    bool whiteToMove;
    void init();
    void clear();
    void fill(Bitboard pieceMask, bool whitePiece, int pieceType);
    std::vector<Bitboard*> pieces = {&white_pawns, &white_knights, &white_bishops, &white_rooks, &white_queens, &white_king,
                                    &black_pawns, &black_knights, &black_bishops, &black_rooks, &black_queens, &black_king};
};

//Constants for files and ranks on the bitboard for easier calculation
namespace Bitboards {

    constexpr Bitboard FileA = 0x101010101010101ULL;
    constexpr Bitboard FileB = FileA << 1;
    constexpr Bitboard FileC = FileA << 2;
    constexpr Bitboard FileD = FileA << 3;
    constexpr Bitboard FileE = FileA << 4;
    constexpr Bitboard FileF = FileA << 5;
    constexpr Bitboard FileG = FileA << 6;
    constexpr Bitboard FileH = FileA << 7;

    constexpr Bitboard Rank1 = 0xFF;
    constexpr Bitboard Rank2 = Rank1 << (8 * 1);
    constexpr Bitboard Rank3 = Rank1 << (8 * 2);
    constexpr Bitboard Rank4 = Rank1 << (8 * 3);
    constexpr Bitboard Rank5 = Rank1 << (8 * 4);
    constexpr Bitboard Rank6 = Rank1 << (8 * 5);
    constexpr Bitboard Rank7 = Rank1 << (8 * 6);
    constexpr Bitboard Rank8 = Rank1 << (8 * 7);

};

enum PieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

#endif
