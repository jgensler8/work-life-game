#pragma once
#include "bn_string.h"
#include "bn_format.h"
#define FMT_8(fmt, ...) bn::string<8>(bn::format<8>(fmt, __VA_ARGS__).data())
#define FMT_24(fmt, ...) bn::string<24>(bn::format<24>(fmt, __VA_ARGS__).data())
#define FMT_32(fmt, ...) bn::string<32>(bn::format<32>(fmt, __VA_ARGS__).data())
#define FMT_48(fmt, ...) bn::string<48>(bn::format<48>(fmt, __VA_ARGS__).data())

namespace util {
    int min(int, int);
    int max(int, int);
    int clamp(int, int, int);
}