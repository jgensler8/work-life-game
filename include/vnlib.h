#pragma once
#include <functional>
#include <initializer_list>
#include "util.h"
#include "bn_core.h"
#include "bn_optional.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_item.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_animate_actions.h"
#include "bn_blending.h"
#include "bn_timer.h"
#include "bn_sound_item.h"
#include "bn_sound_actions.h"

#include "common_variable_8x8_sprite_font.h"
#include "common_fixed_8x8_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"

/*! \brief visual-novel library
 *
 * this includes common game components and state management.
 *
 * just enough to get started with the most basic of games.
 * though advanced games will use it more like a library
 * than a framework.
*/
namespace vnlib {
    /*! \brief a function used to store part of a story
     *
     * can be defined in-line using lambdas (common for a vnlib::choice)
     * or as a normal named function.
     *
     * example lambda: `vnlib::story_fx my_story = [](){ vnlib::say("MyChar", {"inside lambda"}); }`
     *
     * given that games will reference a global game state, lambdas can avoid
     * using the capture clause (the `[]` part) and the args (the `()` part).
     * more information on lambdas: https://en.cppreference.com/w/cpp/language/lambda
    */
    typedef void (*story_fx)();

    //! \brief struct passed to a vnlib::menu
    struct MenuChoice {
        //! \brief text to display
        bn::string_view option;
        //! \brief option callback, usually specified with lambda: `[](){ vnlib::say(); }`
        void (*story)();
    };
    //! \brief struct pass to vnlib::menu
    struct MenuOptions {
        // ** text options **
        //! \brief text, top-left x
        bn::fixed choice_x;
        //! \brief text, top-left y
        bn::fixed choice_y;
        //! \brief variable/fixed font
        bool use_variable_width;
        // ** cursor options **
        //! \brief cursor, top-left x
        bn::fixed cursor_x;
        //! \brief cursor, top-left y
        bn::fixed cursor_y;
        // ** background options **
        //! \brief use the default menu background
        bool use_bg;
        //! \brief top-left bg x
        bn::fixed bg_x;
        //! \brief top-left bg y
        bn::fixed bg_y;
        //! \brief background width
        bn::fixed bg_width;
        // ** selection options **
        //! \brief default selection to hover/render
        int default_selection;
        //! \brief store the eventual selection into passed struct's default_selection
        bool store_selection_as_default;
        // ** grid options **
        //! \brief columns to use in an ani grid
        int cols;
        //! \brief x inc between both animations, text, cursor
        bn::fixed ani_x_inc;
        //! \brief y inc between both animations, text, cursor
        bn::fixed ani_y_inc;

        //! \brief set the choice_x
        MenuOptions* with_choice_x(bn::fixed x) { choice_x = x; return this; }
        //! \brief set the choice_y
        MenuOptions* with_choice_y(bn::fixed y) { choice_y = y; return this; }
        //! \brief set the cursor_x
        MenuOptions* with_cursor_x(bn::fixed x) { cursor_x = x; return this; }
        //! \brief set the cursor_y
        MenuOptions* with_cursor_y(bn::fixed y) { cursor_y = y; return this; }     
        //! \brief set the cols
        MenuOptions* with_cols(int c) { cols = c; return this; }        
        //! \brief set the use_bg
        MenuOptions* with_use_bg(bool u) { use_bg = u; return this; }
    };
    //! \brief options passed to vnlib::say
    struct SayOptions {
        //! \brief if b key is pressed, skip rendering (disabled during ??)
        bool enable_fastforward;
        //! \brief enable to skip waiting for a/b key press (used in minigames)
        bool disable_blocking;
    };
    //! \brief animation slot to save to (workaround vector of animation bug)
    enum AnimationSlot {
        SLOT_8_1 = 0,
        SLOT_8_2 = 1,
        SLOT_8_3 = 2,
        SLOT_8_4 = 3,
        SLOT_8_5 = 4,
        SLOT_8_6 = 5,
        SLOT_8_7 = 6,
        SLOT_8_8 = 7,
        SLOT_8_9 = 8,
        SLOT_8_10 = 9,
        SLOT_32_1 = 24,
        SLOT_32_2 = 25,
    };
    //! \brief type of ending. these options may or may not stop gameplay
    enum EndingType {
        //! \brief BAD ending, some decisions made depply conflit with the character
        BAD_END = 0,
        //! \brief GOOD ending, you progressed normally and are on good terms with the character
        GOOD_END = 1,
        //! \brief PERFECT ending, you chose the right options and are a good match for hte character
        PERFECT_END = 2
    };
    //! \brief called when an end happens. should queue or reset gameplay
    typedef void (*end_fx)(EndingType);

    //! \brief show a bg. see \ref sprite-sizes
    void bg(bn::regular_bg_item item);
    //! \brief bg => black
    void fade_out_to_black();
    //! \brief black => bg
    void fade_in_from_black();
    //! \brief show a person stored in bg. see \ref sprite-sizes
    void show(bn::regular_bg_item who);
    //! \brief hide a person if shown
    void hide();
    //! \brief queue a list of musical sounds
    void play_music(std::initializer_list<bn::sound_item> items);
    //! \brief stop all music instantly
    void stop_music();
    //! \brief say function using default SayOptions
    void say(bn::string_view who, std::initializer_list<bn::string_view> what);
    /*! \brief open the textbox with "who" as heading and "what" lines
     *
     * usually used like the following:
     * ```
     * vnlib::say("MyChar", {"this is line 1", "this is line 2"});
     * ```
     * example preprocessor define for readability:
     * ```
     * #define MYCHAR(...) vnlib::say("MyChar", {__VA_ARGS__});
     * 
     * void some_story() {
     *   MYCHAR("this is line 1", "this is line 2")
     * }
     * ```
    */
    void say(bn::string_view who, std::initializer_list<bn::string_view> what, SayOptions options);
    //! \brief hide the dialog box
    void hide_say();
    /*! \brief convenience factory function for menu options
     *
     * usually constructed with the following:
     * ```
     * vnlib::choice(
     *   "choice a",
     *    [](){
     *      vnlib::say("MyChar", {"you chose A!"});
     *    }
     * );
     * ```
     * example preprocessor define for readability:
     * ```
     * #define CHOICE(who, story_fx) vnlib::choice(who, story_fx)
     * ```
    */
    MenuChoice choice(bn::string_view option, story_fx);
    MenuOptions default_MenuOptions();
    MenuOptions dense_MenuOptions();
    //! \brief prompt the player for a menu choice (menu options on screen)
    void menu(std::initializer_list<MenuChoice> choices);
    //! \brief prompt the player for a menu choice, toggling various options (menu options on screen)
    void menu(std::initializer_list<MenuChoice> choices, MenuOptions* options);
    //! \brief prompt the player for text input (keyboard on screen)
    bn::string<8> keyboard_input_8();
    //! \brief prompt the player for text input starting from the string provided
    bn::string<8> keyboard_input_8(bn::string<8> starting_from);
    //! \brief ad-hoc text display
    void text(bn::string_view text, bn::fixed x, bn::fixed y);
    //! \brief ad-hoc sprite display
    void sprite(bn::sprite_item item, bn::fixed x, bn::fixed y);
    //! \brief ad-hoc sprite display using 8 frames
    void animate_8(bn::sprite_item item, bn::fixed x, bn::fixed y, AnimationSlot slot, int,int,int,int,int,int,int,int);
    //! \brief ad-hoc sprite display using 32 frames
    void animate_32(bn::sprite_item item, bn::fixed x, bn::fixed y, AnimationSlot slot,
        int,int,int,int,int,int,int,int,
        int,int,int,int,int,int,int,int,
        int,int,int,int,int,int,int,int,
        int,int,int,int,int,int,int,int
    );
    //! \brief destroy animation at slot
    void free(AnimationSlot slot);
    //! \brief end the story run
    void end(EndingType type);
    //! \brief destroy all element in the scene manage by vnlib
    void free();
    //! \brief trigger the save/load screen where a selection should persist data from Global Game State => Global Save State => SRAM
    bool wait_save_screen();
    //! \brief trigger the save/load screen where a selection should load data from SRAM => Global Save State => Global Game State
    bool wait_load_screen();

    //! \brief used when save/load. see \ref sprite-sizes
    void set_save_screen(bn::regular_bg_item bg_save_screen_item);
    //! \brief textbox used when displaying dialog. see \ref sprite-sizes
    void set_bg_textbox(bn::regular_bg_item bg_textbox_item);
    //! \brief keyboard used when prompting for keyboard input. see \ref sprite-sizes
    void set_keyboard(bn::regular_bg_item bg_keyboard_item);
    //! \brief cursor used for main menu, keyboard, save screen, and in-game menu prompts. see \ref sprite-sizes
    void set_cursor(bn::sprite_item cursor_item);
    //! \brief set sprite behind menu options (left) see \ref sprite-sizes
    void set_menu_option_left(bn::sprite_item menu_option_item);
    //! \brief set sprite behind menu options (right) see \ref sprite-sizes
    void set_menu_option_right(bn::sprite_item menu_option_item);
    //! \brief set the story called when game is initialized (usually a title or splash screen)
    void set_story_init(story_fx);
    //! \brief callback function used to read all save functions from SRAM (read SRAM into global save state)
    void set_read_all_saves(void (*read_all_saves)());
    //! \brief callback function used when a save slot is selected (load slot into global game state)
    void set_save_slot_selected(void (*save_slot_selected)(int slot));
    //! \brief callback function used when a slot is selected to write to (global game state => global save state => SRAM)
    void set_write_to_slot(void (*write_to_slot)(int slot));
    //! \brief callback function used to paint the save slot on Save Screen. x and y are used to denote top-left corner of save slot
    void set_render_save_slot(void (*render)(int slot, bn::fixed x, bn::fixed y, bn::sprite_text_generator gen, bn::vector<bn::sprite_ptr, 96>* sprites));
    //! \brief set the end_fx when vnlib::end is called
    void set_end_fx(end_fx);
    //! \brief control the global fade count when fading in or out
    void set_fade_times(int times);
    //! \brief if global end state is set, run the end_fx
    void maybe_handle_ending();
    //! \brief control loop that will run the #story_fx stored in vnlib::next
    void main();
    //! \brief queue the next story function onto a size-1 stack. will overwrite if a value exists!
    void next(story_fx);
}