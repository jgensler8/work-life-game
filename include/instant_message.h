#pragma once
#include "includes.h"
#include "widgets.h"

/*! \brief MC can sometimes message at the end of the day

depending on who is online, the MC can message a character
and learn more about them. they also increase relationship
based on having these conversations.
*/
namespace instant_message {
    //! \brief state to represent if we can message them
    enum online_state {
        //! \brief character is not online at all; no task thanks, no im story
        OFFLINE = 0,
        //! \brief character is online; task thanks, im story
        ONLINE = 1,
        //! \brief character is partially online; task thanks, no im story
        BUSY = 2
    };

    //! \brief indicates the state of the character. depends on relationship_state
    online_state status(character::CHAR_ENUM c);
    //! \brief initiate a conversation with a character
    void send_message(character::CHAR_ENUM c);
    //! \brief trigger a "thank you" scene from character c
    void thank_you(character::CHAR_ENUM c);
    //! \brief playtest various prompts
    void playtest();
}