#include "character.h"

namespace character {
    bn::string<6> string(CHAR_ENUM c){
        switch(c){
        case INO: return "Ino";
        case KANADE: return "Kanade";
        case RIKA: return "Rika";
        case RIN: return "Rin";
        default: return "???";
        }
    }
    bn::string<6> string_padded(CHAR_ENUM c){
        switch(c){
        case INO: return    "Ino   ";
        case KANADE: return "Kanade";
        case RIKA: return   "Rika  ";
        case RIN: return    "Rin   ";
        default: return     "??????";
        }
    }
    bn::string<4> string_short(CHAR_ENUM c){
        switch(c){
        case INO: return    "In";
        case KANADE: return "Ka";
        case RIKA: return   "Rk";
        case RIN: return    "Rn";
        default: return     "??";
        }
    }
}