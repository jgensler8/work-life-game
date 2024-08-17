#include "playtest.h"

namespace playtest {
    void loop() {
        FREE
        BG_PLAIN
        FADE_IN
        auto options = vnlib::dense_MenuOptions();
        options.cols = 1;
        vnlib::menu({
            CHOICE("story::unlocks", [](){
                story::unlocks::playtest();
                vnlib::maybe_handle_ending();
            }),
            CHOICE("story", [](){
                story::playtest();
                vnlib::maybe_handle_ending();
            }),
            CHOICE("im", [](){
                instant_message::playtest();
            }),
            CHOICE("progress check", [](){

            }),
            CHOICE("weekend", [](){
                weekend_event::playtest_event();
                vnlib::maybe_handle_ending();
            }),
            CHOICE("emergency", [](){
                weekend_event::playtest_emergency();
                vnlib::maybe_handle_ending();
            })
        }, &options);
        NEXT(loop)
    }
}