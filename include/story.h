#pragma once
#include "includes.h"

/*!
\brief Daytime story progression. Happens before work.

this story is not dependent on relationship and can be viewed as the "main"
story. it mostly involves adding items to backlog and exploring bits about characters
*/
namespace story {
    //! \brief holds various task unlock events
    namespace unlocks {
        //! \brief playtest individual unlock events
        void playtest();
    }

    /*!
    \brief maybe run a cutscene before work starts for the day
    */
    bool maybe_handle_story();

    //! \brief manipulate the day and test various parts of the story
    void playtest();
}