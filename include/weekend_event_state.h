#pragma once
#include "character.h"
//! \brief various progress values for weekend_event state tracking
namespace weekend_event_state {
    //! \brief struct containing weekend_event progress values
    struct weekend_event_state {
        //! \brief track the next story available for a character
        int story_progress[character::COUNT];
        //! \brief track the next emergency available for a character
        int emergency_progress[character::COUNT];
        //! \brief initialize the struct
        void init() {
            for (auto c : character::characters) {
                story_progress[c] = 0;
                emergency_progress[c] = 0;
            }
        }
        //! \brief convenience function to print the story progress
        bn::string<8> story_progress_string(character::CHAR_ENUM c) {
            return FMT_8("{}/{}", story_progress[c], 4);
        }
        //! \brief convenience function to print the emergency progress
        bn::string<8> emergency_progress_string(character::CHAR_ENUM c) {
            return FMT_8("{}/{}", emergency_progress[c], 4);
        }
    };
}