#pragma once
#define GAME_NAME_LEN 8
#include "vnlib.h"
#include "runtime_state.h"
#include "main_character_state.h"
#include "relationship_state.h"
#include "instant_message_state.h"
#include "minigame_state.h"
#include "weekend_event_state.h"
#define UNLOCKED_MARKETING state::st.unlock_state.is_unlocked[character::KANADE]
#define UNLOCKED_SALES state::st.unlock_state.is_unlocked[character::RIKA]
#define UNLOCKED_SECURITY state::st.unlock_state.is_unlocked[character::RIN]

/*! \brief global game state
 *
 * values are loaded into the the global variable state::st when
 * a player loads from a save file. otherwise, they are modified when
 * a new game starts. individual game components are encapsulated in
 * their own respective structs, though gameplayer will frequently
 * reference state of other components.
*/
namespace state {
    //! \brief magic value used to tell if a save slot is initialized
    constexpr char initialized_char = '@';
    //! \brief store if character is unlocked. see story::unlocks
    struct lock_state {
        //! \brief locks per character (true = unlocked, false = locked)
        bool is_unlocked[character::COUNT];
        //! \brief story the progression counter for unlock dialog
        int progression[character::COUNT];
        //! \brief last character to initiate an unlock event with
        character::CHAR_ENUM last;
        //! \brief initialize the struct
        void init() {
            last = character::GENERIC;
            for(auto c : character::characters) {
                lock(c);
                progression[c] = 0;
            }
            unlock(character::INO);
        }
        //! \brief ensure that character is in locked state
        void lock(character::CHAR_ENUM c) {
            is_unlocked[c] = false;
        }
        //! \brief ensure that character is in unlocked state
        void unlock(character::CHAR_ENUM c) {
            is_unlocked[c] = true;
        }
    };

    //! \brief encapsulated game state
    struct GameState {
    public:
        //! \brief char to indicate if this memory region is initialized
        char initialized;
        //! \brief day counter in game, starts at 0
        int day;
        //! \brief the main character's name. input at story start
        char mc_name[GAME_NAME_LEN + 1]; // extra slot to ensure NULL termination
        //! \brief store if character is locked/unlocked
        lock_state unlock_state;
        //! \brief various runtime settings
        runtime_state::runtime_state runtime_state;
        //! \brief various relationship settings
        relationship_state::relationship_state rel_state;
        //! \brief various character preferences
        main_character_state::mc_state mc_state;
        //! \brief various instant_message settings
        instant_message_state::im_state im_state;
        //! \brief various minigame settings
        minigame_state::minigame_state mg_state;
        //! \brief various weekend event settings
        weekend_event_state::weekend_event_state wke_state;
        //! \brief initialize the struct
        void initialize() {
            if(is_initialized()) {
                return;
            }
            initialized = initialized_char;
            mc_name[0] = 'U';
            mc_name[1] = '\0';
            day = 0;
            unlock_state.init();
            runtime_state.init();
            rel_state.init();
            mc_state.init();
            im_state.init();
            mg_state.init();
            wke_state.init();
        }
        //! \brief check if this memory region was inintialized, used when reading from SRAM
        bool is_initialized() {
            return initialized == initialized_char;
        }
        //! \brief convenience function to tell if its a workday (could technically support holidays)
        bool is_workday() {
            return day % 7 <= 4;
        }
        //! \brief is the day Saturday
        bool is_saturday() {
            return day % 7 == 5;
        }
        //! \brief is the day Sunday
        bool is_sunday() {
            return day % 7 == 6;
        }
        //! \brief convenience function to get the normalized week count (starting at 1)
        int week() {
            return (day / 7) + 1;
        }
        //! \brief convenience function used when printing the day of the week
        bn::string<10> day_name() {
            switch(day % 7) {
            case 0:
                return "Monday";
            case 1:
                return "Tuesday";
            case 2:
                return "Wednesday";
            case 3:
                return "Thursday";
            case 4:
                return "Friday";
            case 5:
                return "Saturday";
            case 6:
                return "Sunday";
            default:
                return "";
            }
        }
        //! \brief convenience function uesd when printing the day of the week
        bn::string<2> short_day_name() {
            switch(day % 7) {
            case 0:
                return "Mo";
            case 1:
                return "Tu";
            case 2:
                return "We";
            case 3:
                return "Th";
            case 4:
                return "Fr";
            case 5:
                return "Sa";
            case 6:
                return "Su";
            default:
                return "";
            }
        }
    };
    //! \brief the singular global game state
    extern GameState st;
}
