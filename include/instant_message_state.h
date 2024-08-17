#pragma once
#include "character.h"
//! \brief state used in instant_message.h
namespace instant_message_state {
    //! \brief various state components when sending messages
    struct im_state {
        //! \brief the progress into each instant message array
        unsigned int progress[character::COUNT];
        //! \brief internal counter for various "thank you" functions
        unsigned int thank_you[character::COUNT];
        //! \brief initialze the struct
        void init() {
            for(auto c : character::characters) {
                progress[c] = 0;
                thank_you[c] = 0;
            }
        }
    };
}