#ifndef MAGIC_H
#define MAGIC_H

#include <cstdint>

using Bitboard = uint64_t;

struct MagicEntry{
    Bitboard mask;
    uint64_t magic;
    uint8_t index_bits;
};

#endif