#pragma once
#include "util.h"
#define EMERGENCIES_ARE_ON_SATURDAY (state::st.runtime_state.em_day == runtime_state::EMERGENCIES_ON_SATURDAY)
#define EMERGENCIES_ARE_ON_SUNDAY (state::st.runtime_state.em_day == runtime_state::EMERGENCIES_ON_SUNDAY)

//! \brief various settings that can be changed at runtime
namespace runtime_state {
    //! \brief toggle the way minigames should be played
    enum minigame_mode {
        //! \brief play the game without any help (default)
        PLAY = 0,
        //! \brief play the game with a hint
        HINT = 1,
        //! \brief do not play the game and have a magical force complete the task
        AUTOWIN = 2
    };
    //! \brief toggle the day when emergencies should happen
    enum emergency_day {
        //! \brief emergencies should happen on Saturday (default)
        EMERGENCIES_ON_SATURDAY = 0,
        //! \brief emergencies should happen on Sunday (see weekend_event::generic_event and weekend_event::generic_emergency)
        EMERGENCIES_ON_SUNDAY = 1
    };
    //! \brief struct to bundle runtime toggles
    struct runtime_state {
        //! \brief the minigame_mode option
        minigame_mode mg_mode;
        //! \brief the require_weekly_progress option
        bool require_weekly_progress;
        //! \brief the emergency_day option
        emergency_day em_day;

        //! \brief initialize the struct
        void init() {
            mg_mode = PLAY;
            require_weekly_progress = true;
            em_day = EMERGENCIES_ON_SATURDAY;
        }
        //! \brief re-inintialize the struct to casual difficulty. chosen both at game start and in options screen
        void reset_to_casual() {
            mg_mode = HINT;
            require_weekly_progress = false;
            em_day = EMERGENCIES_ON_SUNDAY;
        }
    };
    //! \brief toggle a generic boolean option
    void toggle(bool* option);
    //! \brief toggle the minigame_mode
    void toggle(minigame_mode* option);
    //! \brief toggle the emergency_day
    void toggle(emergency_day* option);
    //! \brief convert the minigame_mode to a string
    bn::string<8> to_str(minigame_mode option);
    //! \brief convert the emergency_day to a string
    bn::string<8> to_str(emergency_day option);
}