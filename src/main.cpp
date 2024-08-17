#include "vnlib.h"
#include "playtest.h"
#include "save_state.h"
#define HOWTO(...) vnlib::say("How-To", {__VA_ARGS__});

void story_init();

//! \brief introduction to game mechanics
void tutorial() {
    FREE
    BG_PLAIN
    FADE_IN
    HOWTO("Welcome!")
    HOWTO("You play as a", "new hire at a", "software company", "named WidgetCorp")
    HOWTO("Your objective is", "to work!", "You've got this!")
    HOWTO("While you complete", "tasks, you'll earn", "reputation from", "various team members")
    HOWTO("Work hard enough and", "you'll trigger a", "weekend event!")
    SP_EMERGENCY_PHONE
    HOWTO("But be careful!", "Your co-workers will", "have emergencies", "during these events")
    HOWTO("You'll see this icon", "when an emergency is", "happening")
    HOWTO("Take care when choosing", "who to respond to!", "Not everyone pardons", "the interrupts...")
    SP_EMERGENCY_PHONE_FREE
    HOWTO("and thats it!", "Welcome to WidgetCorp!")
    NEXT(story_init)
    FADE_OUT
}

//! \brief entrypoint on new game or loading empty save slot
void story_new() {
    FREE
    BG_PLAIN
    FADE_IN
    state::st.initialize();
    // set name
    vnlib::SayOptions options;
    options.enable_fastforward = false;
    options.disable_blocking = true;
    vnlib::say("(intro)", {"what is your name?"}, options);
    bn::string<8> name = vnlib::keyboard_input_8();
    for(int i =0 ; i < GAME_NAME_LEN; i++ ) { state::st.mc_name[i] = name[i]; }
    state::st.mc_name[GAME_NAME_LEN] = '\0'; // null terminate extra slot
    // set difficulty
    vnlib::say("(intro)", {"which difficulty?", "you can also change", "these later in the", "'options' screen"}, options);
    vnlib::text("Casual:", 100, 10);
    vnlib::text("* Emergency on Sunday", 100, 20);
    vnlib::text("* Game Mode = Hint", 100, 30);
    vnlib::text("* Progress Check = None", 100, 40);
    vnlib::text("Default:", 100, 55);
    vnlib::text("* Emergency on Saturday", 100, 65);
    vnlib::text("* Game Mode = Normal", 100, 75);
    vnlib::text("* Progress Check = Friday", 100, 85);
    vnlib::MenuOptions mo = vnlib::default_MenuOptions();
    mo.use_bg = false;
    vnlib::menu({
        CHOICE("casual", [](){
            state::st.runtime_state.reset_to_casual();
            NEXT(day::day_starting)
        }),
        CHOICE("default", [](){
            // defaults already set
            NEXT(day::day_starting)
        }),
        CHOICE("playtest", [](){
            NEXT(playtest::loop)
        })
    }, &mo);
    FADE_OUT
}

//! \brief credits screen (code/music/art)
void credits() {
    FREE
    BG_PLAIN
    FADE_IN
    // music
    vnlib::text("\"Airport Lounge\" Kevin MacLeod", 10, 2);
    vnlib::text("  (incompetech.com)", 10, 10);
    vnlib::text("Licensed under Creative Commons: ", 10, 18);
    vnlib::text(" By Attribution 4.0 License", 10, 26);
    vnlib::text("http://creativecommons.org/licenses/by/4.0/", 2, 34);
    // butano
    vnlib::text("butano library", 10,50);
    vnlib::text("license: zlib", 10,58);
    vnlib::text("see github.com/GValiente/butano/licenses", 2,66);
    // gnu libstdc++
    vnlib::text("GNU libstdc++", 10,86);
    vnlib::text("license: GNU GPLv3", 10,94);
    vnlib::text("https://www.gnu.org/licenses/", 2, 102);
    // vnlib::text("gcc.gnu.org/git/?p=gcc.git;a=blob;f=COPYING;", 2, 102);
    // code/art
    vnlib::text("other code / assets", 10,118);
    vnlib::text("license: CC BY-NC 4.0", 10,126);
    auto options = vnlib::default_MenuOptions();
    options.use_bg = false;
    options.choice_y = 140;
    options.cursor_y = 140;
    vnlib::menu({
        CHOICE("back", [](){})
    }, &options);

    NEXT(story_init)
    FADE_OUT
}

//! \brief MenuOptions for the title screen
vnlib::MenuOptions init_MenuOptions() {
    auto options = vnlib::default_MenuOptions();
    options.choice_x = 30;
    options.choice_y = 120;
    options.cursor_x = 25;
    options.cursor_y = 105;
    options.cols = 4;
    options.use_bg = false;
    options.store_selection_as_default = true;
    return options;
}

//! \brief global init menu options. see init_MenuOptions
vnlib::MenuOptions init_menu_options = init_MenuOptions();

//! \brief the title screen
void story_init() {
    FREE
    SP_HOW_TO_TITLE
    SP_NEW_GAME_TITLE
    SP_LOAD_TITLE
    SP_CREDITS_TITLE
    BG_TITLE_SCREEN
    FADE_IN
    vnlib::menu({
        CHOICE("how-to", [](){
            NEXT(tutorial)
        }),
        CHOICE("  new", [](){
            NEXT(story_new)
        }),
        CHOICE("  load", [](){
            FADE_OUT
            if(!vnlib::wait_load_screen()) {
                NEXT(story_init)
            }
        }),
        CHOICE(" credits", [](){
            NEXT(credits);
        })
    }, &init_menu_options);
    FADE_OUT
}

//! \brief menu options for all end screens
vnlib::MenuOptions end_menu_options() {
    auto options = vnlib::default_MenuOptions();
    options.choice_x = 70;
    options.choice_y = 140;
    options.cursor_x = 60;
    options.cursor_y = 140;
    options.cols = 2;
    options.use_bg = false;
    options.ani_x_inc = 70;
    return options;
}

//! \brief handle various ending types
void handle_ending(vnlib::EndingType type) {
    FREE
    auto options = end_menu_options();
    switch(type) {
    case vnlib::BAD_END:
        BG_BAD_END
        // menu to pause on the screen
        vnlib::menu({CHOICE("home", [](){})}, &options);
        NEXT(story_init)
        return;
    case vnlib::GOOD_END:
        BG_GOOD_END
        break;
    case vnlib::PERFECT_END:
        BG_PERFECT_END
        break;
    default:
        break;
    }
    FADE_IN
    vnlib::menu({
        CHOICE("continue?", [](){
            // as end handler is called during the
            // normal day loop, we don't need to do
            // anything
        }),
        CHOICE("home", [](){
            NEXT(story_init)
        })
    }, &options);
    FADE_OUT
}

//! \brief the is the main
int main()
{
    PLAY_BG_MUSIC_LOBBY
    vnlib::set_save_screen(bn::regular_bg_items::save_screen);
    vnlib::set_bg_textbox(bn::regular_bg_items::textbox_small);
    vnlib::set_keyboard(bn::regular_bg_items::keyboard);
    vnlib::set_cursor(bn::sprite_items::cursor);
    vnlib::set_menu_option_left(bn::sprite_items::sp_menu_item_left);
    vnlib::set_menu_option_right(bn::sprite_items::sp_menu_item_right);
    vnlib::set_story_init(story_init);
    vnlib::set_read_all_saves(save_state::read_all_saves);
    vnlib::set_save_slot_selected(save_state::save_slot_selected);
    vnlib::set_write_to_slot(save_state::write_to_slot);
    vnlib::set_render_save_slot(save_state::render_save_slot);
    vnlib::set_end_fx(handle_ending);
    vnlib::set_fade_times(5);
    vnlib::main();
}
