#pragma once
#include "util.h"
//! \brief various minigame state structs
namespace minigame_state {
    //! \brief enum for each minigame
    enum minigame_game {
        CODE = 0,
        PAPERWORK = 1,
        CALLS = 2,
        BUGS = 3 
    };
    //! \brief max number of minigame_type
    constexpr unsigned int minigame_count = 4;
    //! \brief convenience array of minigames
    const minigame_game games[] = {CODE, PAPERWORK, CALLS, BUGS};

    //! \brief encapsulated minigame state
    struct minigame_state {
        //! \brief meter used to measure progress in a minigame. used to represent difficulty
        int successes[minigame_count];
        //! \brief absolute successes in a minigame. could be used to determine if zero work was completed
        int totals[minigame_count];
        //! \brief minigame total successes that is reset every week. used to display expectation during the week
        int weekly_successes;
        //! \brief initialize the struct
        void init() {
            for(auto game : games) {
                successes[game] = 0;
                totals[game] = 0;
            }
            weekly_successes = 0;
        }
        //! \brief called when a minigame is completed successfully
        void on_success(minigame_game game) {
            successes[game] += 1;
            totals[game] += 1;
            weekly_successes += 1;
        }
        //! \brief called when a minigame is failed
        void on_failure(minigame_game game) {
            successes[game] = util::max(successes[game] - 1, 0);
        }
        //! \brief called when the week changes
        void weekly_reset() {
            weekly_successes = 0;
        }
    };
}