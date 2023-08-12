#include "bitboards.h"

void Board::init() {

    white_pawns = Bitboards::Rank2;
    white_knights = (Bitboards::FileB | Bitboards::FileG) & Bitboards::Rank1;
    white_bishops = (Bitboards::FileC | Bitboards::FileF) & Bitboards::Rank1;
    white_rooks = (Bitboards::FileA | Bitboards::FileH) & Bitboards::Rank1;
    white_queens = Bitboards::FileD & Bitboards::Rank1;
    white_king = Bitboards::FileE & Bitboards::Rank1;

    black_pawns = Bitboards::Rank7;
    black_knights = (Bitboards::FileB | Bitboards::FileG) & Bitboards::Rank8;
    black_bishops = (Bitboards::FileC | Bitboards::FileF) & Bitboards::Rank8;
    black_rooks = (Bitboards::FileA | Bitboards::FileH) & Bitboards::Rank8;
    black_queens = Bitboards::FileD & Bitboards::Rank8;
    black_king = Bitboards::FileE & Bitboards::Rank8;

    white_occupied = white_pawns | white_knights | white_bishops | white_rooks | white_queens | white_king;
    black_occupied = black_pawns | black_knights | black_bishops | black_rooks | black_queens | black_king;
    occupied = white_occupied | black_occupied;

    whiteToMove = true;


}

void Board::clear() {
    for (int i = 0; i < pieces.size(); i++) {
        *(pieces[i]) = 0;
    }
    black_occupied = 0;
    white_occupied = 0;
    occupied = 0;
}

void Board::fill(Bitboard pieceMask, bool whitePiece, int pieceType) {
    white_occupied |= pieceMask;
    black_occupied |= pieceMask;

    switch (pieceType) {
        case PieceType::PAWN:
            (whitePiece) ? white_pawns |= pieceMask : black_pawns |= pieceMask;
            break;
        case PieceType::KNIGHT:
            (whitePiece) ? white_knights |= pieceMask : black_knights |= pieceMask;
            break;
        case PieceType::BISHOP:
            (whitePiece) ? white_bishops |= pieceMask : black_bishops |= pieceMask;
            break;
        case PieceType::ROOK:
            (whitePiece) ? white_rooks |= pieceMask : black_rooks |= pieceMask;
            break;
        case PieceType::QUEEN:
            (whitePiece) ? white_queens |= pieceMask : black_queens |= pieceMask;
            break;
        case PieceType::KING:
            (whitePiece) ? white_king |= pieceMask : black_king |= pieceMask;
            break;
    }
    occupied = white_occupied | black_occupied;
}