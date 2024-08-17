#pragma once
#include "util.h"
//! \brief characters available in the game
namespace character {
    //! \brief there are four characters
    constexpr int COUNT = 4;
    //! \brief the character enum
    enum CHAR_ENUM {
        INO = 0,
        KANADE = 1,
        RIKA = 2,
        RIN = 3,
        GENERIC = 4
    };
    //! \brief conviences array used in loop structures
    const CHAR_ENUM characters[] = {INO, KANADE, RIKA, RIN};
    //! \brief convert character enum to string
    bn::string<6> string(CHAR_ENUM c);
    //! \brief convert character enum to string padded with space
    bn::string<6> string_padded(CHAR_ENUM c);
    //! \brief convert character enum to two letters
    bn::string<4> string_short(CHAR_ENUM c);
}