#pragma once
#include "includes.h"
#include "minigame_bugs.h"

/*! \brief various weekend event functions
 *
 * these will reveal information about each character (along with the mc)
 * it will establish preferences that will eventually
 * culminate in a confession.
*/
namespace weekend_event {
    //! \brief maybe handle a weekend event
    void handle_event();
    //! \brief playtest menu for each story
    void playtest_event();
    //! \brief playtest menu for each emergency
    void playtest_emergency();
}