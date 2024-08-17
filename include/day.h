#pragma once
#include "includes.h"
#include "minigame_code.h"
#include "minigame_paperwork.h"
#include "minigame_calls.h"
#include "minigame_bugs.h"
#include "instant_message.h"
#include "story.h"
#include "weekend_event.h"
#include "widgets.h"

/*! \brief control loop of game built on top of vnlib::next
 *
 * workday: always handle work/life tasks
 * weekend: possibly handle special weekend event
*/
namespace day {
    //! \brief first function called in the day. determines weekday/weekend
    void day_starting();
    //! \brief last function called in the day. used to advance day variable and run cutscene
    void day_ending();
    //! \brief the morning task
    void desk_work();
    //! \brief run after the morning task
    void desk_work_complete();
    //! \brief the afternoon task
    void work_life();
    //! \brief run after the afternoon task
    void work_life_complete();
}