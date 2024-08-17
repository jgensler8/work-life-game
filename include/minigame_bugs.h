#pragma once
#include "includes.h"
#include "widgets.h"

/*! \brief the security team's minigame where you "squash" buttons in the correct order
 *
 * This could have also been a rhythm game or a cursor-based clicking game
 * where bugs of certain color need to be squashed in order
*/
namespace minigame_bugs {
    //! \brief used in the minigame_bugs::game and in weekend_event::kanade_weekend_2
    bool round(bn::keypad::key_type good_key);
    //! \brief security team's mini-game
    void game();
}