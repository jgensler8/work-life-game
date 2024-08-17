#include "vnlib.h"
#define GBA_WIDTH 240
#define GBA_HEIGHT 160
#define BG_WIDTH 256
#define BG_HEIGHT 256
#define TEXTBOX_HEIGHT 64
#define TEXTBOX_WIDTH 144
#define TOP_LEFT_COORD_X_BG(true_x) true_x - (GBA_WIDTH / 2) + (BG_WIDTH/2)
#define TOP_LEFT_COORD_Y_BG(true_y) true_y - (GBA_HEIGHT / 2) + (BG_HEIGHT/2)
#define TEXT_HEIGHT 8
#define TEXT_MARGIN 2
#define TOP_LEFT_COORD_X_ZERO(true_x) true_x - (GBA_WIDTH / 2)
#define TOP_LEFT_COORD_Y_ZERO(true_y) true_y - (GBA_HEIGHT / 2)
#define TOP_LEFT_COORD_X_TEXT(true_x) true_x - (GBA_WIDTH / 2)
#define TOP_LEFT_COORD_Y_TEXT(true_y) true_y - (GBA_HEIGHT / 2) + (TEXT_HEIGHT / 2)
#define TOP_LEFT_COORD_X_CURSOR(true_x) true_x - (GBA_WIDTH / 2)
#define TOP_LEFT_COORD_Y_CURSOR(true_y) true_y - (GBA_HEIGHT / 2) + (16 / 2)
#define TOP_LEFT_COORD_X_SPRITE(true_x) true_x - (GBA_WIDTH / 2) + (64 / 2)
#define TOP_LEFT_COORD_Y_SPRITE(true_y) true_y - (GBA_HEIGHT / 2) + (64 / 2)
#define TOP_LEFT_COORD_X_SPRITE_16(true_x) true_x - (GBA_WIDTH / 2) + (16 / 2)
#define TOP_LEFT_COORD_Y_SPRITE_16(true_y) true_y - (GBA_HEIGHT / 2) + (16 / 2)

namespace vnlib {
    //! \cond DO_NOT_DOCUMENT
    constexpr bn::fixed text_y_inc = TEXT_HEIGHT + TEXT_MARGIN;
    constexpr bn::fixed title_text_x = TOP_LEFT_COORD_X_TEXT(100);
    constexpr bn::fixed title_text_y = TOP_LEFT_COORD_Y_TEXT(100);
    constexpr bn::fixed title_cursor_x = title_text_x - 10;
    constexpr bn::fixed title_cursor_y = title_text_y;
    constexpr bn::fixed bg_x = TOP_LEFT_COORD_X_BG(0);
    constexpr bn::fixed bg_y = TOP_LEFT_COORD_Y_BG(0);
    constexpr bn::fixed textbox_x = TOP_LEFT_COORD_X_BG(0);
    constexpr bn::fixed textbox_y = TOP_LEFT_COORD_Y_BG(GBA_HEIGHT - TEXTBOX_HEIGHT);
    constexpr bn::fixed who_x = TOP_LEFT_COORD_X_BG(TEXTBOX_WIDTH);
    constexpr bn::fixed who_y = TOP_LEFT_COORD_Y_BG(0);
    constexpr bn::fixed say_x_name = TOP_LEFT_COORD_X_TEXT(12);
    constexpr bn::fixed say_y_name = TOP_LEFT_COORD_Y_TEXT(GBA_HEIGHT - TEXTBOX_HEIGHT + 2);
    constexpr bn::fixed say_x_text = say_x_name;
    constexpr bn::fixed say_y_text = say_y_name + 14;
    constexpr bn::fixed save_screen_x = TOP_LEFT_COORD_X_TEXT(32);
    constexpr bn::fixed save_screen_y = TOP_LEFT_COORD_Y_TEXT(TEXT_HEIGHT + TEXT_MARGIN);
    constexpr bn::fixed save_screen_margin = TEXT_HEIGHT + TEXT_MARGIN;
    constexpr bn::fixed save_screen_y_inc = 4*(TEXT_HEIGHT + TEXT_MARGIN);
    constexpr bn::fixed save_screen_back_x = save_screen_x;
    constexpr bn::fixed save_screen_back_y = TOP_LEFT_COORD_Y_TEXT(GBA_HEIGHT - 20);
    constexpr bn::fixed keyboard_x = TOP_LEFT_COORD_X_TEXT(14);
    constexpr bn::fixed keyboard_y = TOP_LEFT_COORD_Y_TEXT(10);
    constexpr bn::fixed keyboard_output_x = TOP_LEFT_COORD_X_TEXT(46);
    constexpr bn::fixed keyboard_output_y = TOP_LEFT_COORD_Y_TEXT(85);
    constexpr bn::fixed keyboard_y_inc = 2*TEXT_HEIGHT;
    constexpr bn::fixed keyboard_cursor_offset_x = 8;

    bn::optional<bn::regular_bg_ptr> _bg;
    bn::vector<bn::sprite_ptr, 32> _title_items;
    bn::optional<bn::regular_bg_item> _bg_save_screen_item;
    bn::optional<bn::regular_bg_ptr> _bg_save_screen;
    bn::vector<bn::sprite_ptr, 96> _save_screen_items;
    bn::vector<bn::sound_item, 32> _bg_music;
    bn::optional<bn::sound_handle> _bg_music_current;
    bn::optional<bn::regular_bg_item> _bg_textbox_item;
    bn::optional<bn::regular_bg_ptr> _bg_textbox;
    bn::optional<bn::regular_bg_item> _bg_keyboard_item;
    bn::optional<bn::regular_bg_ptr> _bg_keyboard;
    bn::optional<bn::sprite_item> _bg_menu_left_sp_item;
    bn::optional<bn::sprite_item> _bg_menu_right_sp_item;
    bn::optional<bn::sprite_ptr> _sp;
    bn::optional<bn::regular_bg_ptr> _sp_bg;
    bn::vector<bn::sprite_ptr, 64> _adhoc_text;
    bn::vector<bn::sprite_ptr, 32> _menu_options;
    bn::vector<bn::sprite_ptr, 32> _text;
    bn::vector<bn::sprite_ptr, 32> _keyboard_input;
    bn::vector<bn::sprite_ptr, 32> _keyboard_output;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_1;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_2;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_3;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_4;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_5;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_6;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_7;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_8;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_9;
    bn::optional<bn::sprite_animate_action<8>> _animated_sprite_8_10;
    bn::optional<bn::sprite_animate_action<32>> _animated_sprite_32_1;
    bn::optional<bn::sprite_animate_action<32>> _animated_sprite_32_2;
    bn::optional<bn::sprite_item> _cursor_item;
    bn::optional<bn::sprite_ptr> _cursor;
    bn::optional<bn::sprite_animate_action<24>> _cursor_animate_action;
    bn::optional<story_fx> _next_story;
    bn::optional<story_fx> _story_init;
    bn::optional<EndingType> _end_state;
    bn::optional<end_fx> _end_handler;
    bn::optional<void (*)()> _read_all_saves;
    bn::optional<void (*)(int)> _save_slot_selected;
    bn::optional<void (*)(int)> _write_to_slot;
    bn::optional<void (*)(int, bn::fixed, bn::fixed, bn::sprite_text_generator, bn::vector<bn::sprite_ptr, 96>*)> _render_save_slot;
    int _fade_times = 5;
    //! \endcond
    //! \brief global alpha for tracking fading state
    bn::fixed alpha = 0;

    void free() {
        _bg.reset();
        _bg_textbox.reset();
        _bg_save_screen.reset();
        _bg_keyboard.reset();
        _save_screen_items.clear();
        _title_items.clear();
        _sp.reset();
        _sp_bg.reset();
        _adhoc_text.clear();
        _menu_options.clear();
        _text.clear();
        _keyboard_input.clear();
        _keyboard_output.clear();
        _animated_sprite_8_1.reset();
        _animated_sprite_8_2.reset();
        _animated_sprite_8_3.reset();
        _animated_sprite_8_4.reset();
        _animated_sprite_8_5.reset();
        _animated_sprite_8_6.reset();
        _animated_sprite_8_7.reset();
        _animated_sprite_8_8.reset();
        _animated_sprite_8_9.reset();
        _animated_sprite_8_10.reset();
        _animated_sprite_32_1.reset();
        _animated_sprite_32_2.reset();
        _cursor.reset();
        _cursor_animate_action.reset();
    }

#define MAYBE_ANIMATE_ITEM(i) if(i.has_value()) {i.value().update();}
    //! \brief maybe advance animation frames
    void maybe_animate() {
        MAYBE_ANIMATE_ITEM(_cursor_animate_action)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_1)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_2)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_3)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_4)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_5)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_6)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_7)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_8)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_9)
        MAYBE_ANIMATE_ITEM(_animated_sprite_8_10)
        MAYBE_ANIMATE_ITEM(_animated_sprite_32_1)
        MAYBE_ANIMATE_ITEM(_animated_sprite_32_2)
    }

    //! \brief global variable used for music
    int music_index = 0;
    //! \brief max volume level
    constexpr int max_volume_level = 1.0;
    //! \brief volume level music should start at
    constexpr bn::fixed init_volume_level = max_volume_level;
    //! \brief maybe play running music
    void maybe_play_queue() {
        if(_bg_music.size() > 0) {
            if(!_bg_music_current.has_value()) {
                music_index = 0;
                _bg_music_current = _bg_music[music_index].play(init_volume_level);
            } else {
                // queue next
                if(!_bg_music_current.value().active()) {
                    music_index += 1;
                    if(music_index < _bg_music.size()) {
                        _bg_music_current = _bg_music[music_index].play(max_volume_level);
                    } else {
                        _bg_music_current.reset();
                    }
                }
            }
        }
    }

    //! \brief wait a variable amount
    void wait_times(int times) {
        for(int i = 0; i < times; i++) {
            maybe_animate();
            maybe_play_queue();
            bn::core::update();
        }
    }

    //! \brief internal function to wait until a key not held
    void wait_for_a_not_held(bool enable_fastforward) {
        while(bn::keypad::a_held()){
            if(enable_fastforward && bn::keypad::b_held()) {
                break;
            }
            wait_times(1);
        };
    }

    //! \brief internal function to wait until a key is held
    void wait_for_key_press(bool enable_fastforward) {
        wait_for_a_not_held(enable_fastforward);
        while(! bn::keypad::a_pressed())
        {
            if(enable_fastforward && bn::keypad::b_held()) {
                break;
            }
            wait_times(1);
        }
    }

    //! \brief internal function to wait until a menu item is selected
    int wait_for_menu_item(int item_count, void (*render)(int)) {
        int selection = 0;
        wait_for_a_not_held(false);
        while(! bn::keypad::a_pressed()) {
            if(bn::keypad::down_pressed()) {
                selection = util::min(selection + 1, item_count-1);
            } else if (bn::keypad::up_pressed()) {
                selection = util::max(selection - 1, 0);
            }
            render(selection);
            wait_times(1);
        }
        return selection;
    }

    //! \brief internal function to wait until the final item in a grid is selected
    int wait_for_grid_any(int item_count, int cols, int selection, void(*render)(int)) {
        wait_for_a_not_held(false);
        while(true) {
            if(bn::keypad::left_pressed()) {
                selection -= 1;
            } else if (bn::keypad::right_pressed()) {
                selection += 1;
            } else if (bn::keypad::up_pressed()) {
                selection -= cols;
            } else if (bn::keypad::down_pressed()) {
                selection += cols;
            } else if (bn::keypad::a_pressed()) {
                return selection;
            }
            selection = util::clamp(selection, 0, item_count-1);
            render(selection);
            wait_times(1);
        }
    }

    //! \brief internal function to wait until the final item in a grid is selected
    void wait_for_grid_last(int item_count, int cols, void(*render)(int), void(*pressed)(int)) {
        int selection = 0;
        while(true) {
            selection = wait_for_grid_any(item_count, cols, selection, render);
            if (selection == (item_count-1)) {
                break;
            }
            pressed(selection);
        }
    }

    void bg(bn::regular_bg_item item) {
        _bg = item.create_bg(bg_x, bg_y);
        _bg.value().set_blending_enabled(true);
    }

    //! \brief global alpha_index to record if faded in/out
    int alpha_index = 0;
    //! \brief alpha levels per _fade_times
    bn::fixed alphas[] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0};

    void fade_out_to_black() {
        for(; alpha_index < 5; alpha_index += 1) {
            bn::blending::set_fade_alpha(alphas[alpha_index]);
            wait_times(_fade_times);
        }
        bn::blending::set_fade_alpha(alphas[alpha_index]);
    }

    void fade_in_from_black() {
        for(; alpha_index > 0; alpha_index -= 1) {
            bn::blending::set_fade_alpha(alphas[alpha_index]);
            wait_times(_fade_times);
        }
        bn::blending::set_fade_alpha(alphas[alpha_index]);
    }

    void show(bn::regular_bg_item who) {
        _sp_bg = who.create_bg(who_x, who_y);
    }

    void hide() {
        _sp_bg.reset();
    }

    void play_music(std::initializer_list<bn::sound_item> items) {
        stop_music();
        // replace music vector
        for(auto item : items) {
            _bg_music.push_back(item);
        }
    }

    void stop_music() {
        _bg_music.clear();
        _bg_music_current.reset();
        bn::sound::stop_all();
    }

    MenuChoice choice(bn::string_view option, story_fx story) {
        MenuChoice mc;
        mc.option = option;
        mc.story = story;
        return mc;
    }

    //! \brief create and store the cursor sprite
    void create_cursor() {
        _cursor = _cursor_item.value().create_sprite(0,0);
        _cursor_animate_action = bn::create_sprite_animate_action_forever(_cursor.value(), 4, _cursor_item.value().tiles_item(),
            0,0,0,0, 0,0,0,0, 0,0,0,0,
            3,2,2,3, 0,0,3,2, 2,3,0,0);
    }
    //! \brief free cursor and animation
    void free_cursor() {
        _cursor.reset();
        _cursor_animate_action.reset();
    }

    //! \brief default MenuOptions
    MenuOptions default_MenuOptions() {
        MenuOptions d;
        // text options
        d.choice_x = 16;
        d.choice_y = 16;
        d.use_variable_width = true;
        // cursor options
        d.cursor_x = 0;
        d.cursor_y = 13;
        // bg options
        d.use_bg = true;
        d.bg_x = 0;
        d.bg_y = 0;
        d.bg_width = 64;
        // selection options
        d.default_selection = 0;
        d.store_selection_as_default = false;
        // grid options
        d.cols = 1;
        d.ani_x_inc = 46;
        d.ani_y_inc = text_y_inc;
        return d;
    }
    //! brief dense MenuOptions (used for playtest menus)
    MenuOptions dense_MenuOptions() {
        MenuOptions d = default_MenuOptions();
        d.choice_x = 8;
        d.choice_y = 0;
        d.cursor_x = 0;
        d.cursor_y = 0;
        d.use_bg = false;
        d.cols = 4;
        d.ani_x_inc = 42;
        return d;
    }

    //! \brief internal
    MenuOptions menu_options;
    //! \brief render the cursor when a menu is prompted and when menu choice changes
    void render_menu_cursor(int selection) {
        int col = selection % menu_options.cols;
        int row = selection / menu_options.cols;
        _cursor.value().set_x(TOP_LEFT_COORD_X_SPRITE_16(menu_options.cursor_x) + col*menu_options.ani_x_inc);
        _cursor.value().set_y(TOP_LEFT_COORD_Y_SPRITE_16(menu_options.cursor_y) + row*menu_options.ani_y_inc);
    }

    void menu(std::initializer_list<MenuChoice> choices, MenuOptions* options) {
        menu_options = *options;
        if(menu_options.use_bg) {
            // render menu bg first so z is behind
            _menu_options.push_back(
                _bg_menu_left_sp_item.value().create_sprite(
                    TOP_LEFT_COORD_X_SPRITE(menu_options.bg_x),
                    TOP_LEFT_COORD_Y_SPRITE(menu_options.bg_y)));
            _menu_options.push_back(
                _bg_menu_right_sp_item.value().create_sprite(
                    TOP_LEFT_COORD_X_SPRITE(menu_options.bg_x)+menu_options.bg_width,
                    TOP_LEFT_COORD_Y_SPRITE(menu_options.bg_y)));
        }
        // reder choices
        auto font = common::variable_8x8_sprite_font;
        if(!menu_options.use_variable_width) {
            font = common::fixed_8x8_sprite_font;
        }
        bn::sprite_text_generator choice_text_gen(font);
        choice_text_gen.set_left_alignment();
        int ci = 0;
        for(auto c : choices) {
            int col = ci % menu_options.cols;
            int row = ci / menu_options.cols;
            auto choice_x = TOP_LEFT_COORD_X_TEXT(menu_options.choice_x) + col*menu_options.ani_x_inc;
            auto choice_y = TOP_LEFT_COORD_Y_TEXT(menu_options.choice_y) + row*menu_options.ani_y_inc;
            choice_text_gen.generate(choice_x, choice_y, c.option, _menu_options);
            ci++;
        }
        // render cursor
        create_cursor();
        render_menu_cursor(menu_options.default_selection);
        // user selects item
        int selection = wait_for_grid_any(choices.size(), menu_options.cols, menu_options.default_selection, vnlib::render_menu_cursor);
        if(options->store_selection_as_default) {
            options->default_selection = selection;
        }
        // hide menu
        free_cursor();
        _menu_options.clear();
        // advance story
        int cc = 0;
        for(auto choice : choices) {
            if(cc == selection) { choice.story(); return; }
            cc++;
        }
    }

    void menu(std::initializer_list<MenuChoice> choices) {
        auto options = default_MenuOptions();
        menu(choices, &options);
    }

    void say(bn::string_view who, std::initializer_list<bn::string_view> whats, SayOptions options) {
        bn::sprite_text_generator who_text_gen(common::fixed_8x16_sprite_font);
        who_text_gen.set_left_alignment();
        // bn::sprite_text_generator what_text_gen(common::fixed_8x8_sprite_font);
        bn::sprite_text_generator what_text_gen(common::variable_8x8_sprite_font);
        what_text_gen.set_left_alignment();
        // create textbox + namebox
        if (_bg_textbox_item.has_value()) {
            _bg_textbox = _bg_textbox_item.value().create_bg(textbox_x, textbox_y);
        }
        // clear old text and free pointers
        _text.clear();
        wait_times(1);
        // render who
        who_text_gen.generate(say_x_name, say_y_name, who, _text);
        // render what
        bn::fixed y_offset = 0;
        for(bn::string_view what : whats) {
            what_text_gen.generate(say_x_text, say_y_text + y_offset, what, _text);
            y_offset += text_y_inc;
        }
        // short circuit
        if(options.disable_blocking) { wait_times(1); return; }
        wait_for_key_press(options.enable_fastforward);
    }

    void say(bn::string_view who, std::initializer_list<bn::string_view> whats) {
        SayOptions defaultOptions;
        defaultOptions.enable_fastforward = true;
        defaultOptions.disable_blocking = false;
        say(who, whats, defaultOptions);
    }

    void hide_say() {
        _text.clear();
        _bg_textbox.reset();
    }

    //! \brief render the cursor when a keyboard input changes
    void render_keyboard_cursor(int selection) {
        // 1-26 alphabet
        // 27 delete
        // 28 confirm
        int row = selection / 8;
        int col = selection % 8;
        // empty space (8px) + one letter (8px) == 8px*2
        _cursor.value().set_x(keyboard_x-keyboard_cursor_offset_x + (8*2)*col);
        _cursor.value().set_y(keyboard_y + keyboard_y_inc*row);
        if (selection == 26) {
            _cursor.value().set_x(keyboard_x-keyboard_cursor_offset_x + 8*5);
        } else if (selection == 27) {
            _cursor.value().set_x(keyboard_x-keyboard_cursor_offset_x + 8*10);
        }
    };

    //! \brief render keyboard and cursor and wait for input
    void keyboard_input(void (*selected)(int)) {
        bn::sprite_text_generator keyboard_gen(common::fixed_8x16_sprite_font);
        keyboard_gen.set_left_alignment();
        keyboard_gen.generate(keyboard_x, keyboard_y,                    "A B C D E F G H", _keyboard_input);
        keyboard_gen.generate(keyboard_x, keyboard_y + keyboard_y_inc,   "I J K L M N O P", _keyboard_input);
        keyboard_gen.generate(keyboard_x, keyboard_y + 2*keyboard_y_inc, "Q R S T U V W X", _keyboard_input);
        keyboard_gen.generate(keyboard_x, keyboard_y + 3*keyboard_y_inc, "Y Z  DEL  DONE ", _keyboard_input);
        create_cursor();
        render_keyboard_cursor(0);
        wait_for_grid_last(28, 8, render_keyboard_cursor, selected);
    }

    //! \brief alphabet used for keyboard input
    const char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //! \brief global variable used for keyboard input
    bn::string<8> output_8;
    //! \brief global variable used for keyboard input
    int write_pos;
    //! \brief render keyboard cursor selection change
    void keyboard_input_8_selection(int selection) {
        if(selection <= 25) {
            output_8[write_pos] = alphabet[selection];
            write_pos = util::min(write_pos + 1, 7);
        } else if (selection == 26) {
            // if write_pos is empty, delete means char before this
            // otherwise, we are at the output limit, write_pos should stay
            // the same but we still need to overwrite the last letter
            if(output_8[write_pos] == '_') {
                write_pos = util::max(write_pos - 1, 0);
            }
            output_8[write_pos] = '_';
        }
        // render input
        _keyboard_output.clear();
        bn::sprite_text_generator output_gen(common::fixed_8x16_sprite_font);
        output_gen.set_left_alignment();
        output_gen.generate(keyboard_output_x, keyboard_output_y, output_8, _keyboard_output);
    }

    //! \brief render keyboard and wait for 8 characters of input
    bn::string<8> keyboard_input_8(bn::string<8> starting_from) {
        _bg_keyboard = _bg_keyboard_item.value().create_bg(TOP_LEFT_COORD_X_BG(0),TOP_LEFT_COORD_Y_BG(0));
        output_8 = starting_from;
        // fill with underscores
        for(int c = starting_from.size(); c < 8; c++) {
            output_8 += '_';
        }
        write_pos = starting_from.size();
        keyboard_input_8_selection(27); // no action, render
        keyboard_input(keyboard_input_8_selection);
        if(output_8[write_pos] == '_') {
            output_8[write_pos] = '\0';
        }
        // remove keyboard
        _keyboard_input.clear();
        _keyboard_output.clear();
        _bg_keyboard.reset();
        free_cursor();
        return output_8;
    }

    bn::string<8> keyboard_input_8() {
        return keyboard_input_8("");
    }

    void text(bn::string_view text, bn::fixed x, bn::fixed y) {
        bn::sprite_text_generator adhoc_gen(common::variable_8x8_sprite_font);
        adhoc_gen.set_left_alignment();
        adhoc_gen.generate(TOP_LEFT_COORD_X_TEXT(x), TOP_LEFT_COORD_Y_TEXT(y), text, _adhoc_text);
    }

    void sprite(bn::sprite_item item, bn::fixed x, bn::fixed y) {
        auto s_x = TOP_LEFT_COORD_X_ZERO(x) + (item.shape_size().width() / 2);
        auto s_y = TOP_LEFT_COORD_Y_ZERO(y) + (item.shape_size().height() / 2);
        auto sp = item.create_sprite(s_x, s_y);
        _adhoc_text.push_back(sp);
    }

    void animate_8(bn::sprite_item item, bn::fixed x, bn::fixed y, AnimationSlot slot, int f0, int f1, int f2, int f3, int f4, int f5, int f6, int f7) {
        auto s_x = TOP_LEFT_COORD_X_ZERO(x) + (item.shape_size().width() / 2);
        auto s_y = TOP_LEFT_COORD_Y_ZERO(y) + (item.shape_size().height() / 2);
        auto sp = item.create_sprite(s_x, s_y);
        auto a = bn::create_sprite_animate_action_forever(sp, 8, item.tiles_item(), f0,f1,f2,f3,f4,f5,f6,f7);
        switch(slot) {
        case SLOT_8_1: _animated_sprite_8_1 = a; break;
        case SLOT_8_2: _animated_sprite_8_2 = a; break;
        case SLOT_8_3: _animated_sprite_8_3 = a; break;
        case SLOT_8_4: _animated_sprite_8_4 = a; break;
        case SLOT_8_5: _animated_sprite_8_5 = a; break;
        case SLOT_8_6: _animated_sprite_8_6 = a; break;
        case SLOT_8_7: _animated_sprite_8_7 = a; break;
        case SLOT_8_8: _animated_sprite_8_8 = a; break;
        case SLOT_8_9: _animated_sprite_8_9 = a; break;
        case SLOT_8_10: _animated_sprite_8_10 = a; break;
        default: break;
        }
    }

    void animate_32(bn::sprite_item item, bn::fixed x, bn::fixed y, AnimationSlot slot,
        int f0, int f1, int f2, int f3, int f4, int f5, int f6, int f7,
        int f8, int f9, int f10, int f11, int f12, int f13, int f14, int f15,
        int f16, int f17, int f18, int f19, int f20, int f21, int f22, int f23,
        int f24, int f25, int f26, int f27, int f28, int f29, int f30, int f31
    ) {
        auto s_x = TOP_LEFT_COORD_X_ZERO(x) + (item.shape_size().width() / 2);
        auto s_y = TOP_LEFT_COORD_Y_ZERO(y) + (item.shape_size().height() / 2);
        auto sp = item.create_sprite(s_x, s_y);
        auto a = bn::create_sprite_animate_action_forever(sp, 8, item.tiles_item(),
            f0,f1,f2,f3,f4,f5,f6,f7,
            f8,f9,f10,f11,f12,f13,f14,f15,
            f16,f17,f18,f19,f20,f21,f22,f23,
            f24,f25,f26,f27,f28,f29,f30,f31
        );
        switch(slot) {
        case SLOT_32_1: _animated_sprite_32_1 = a; break;
        case SLOT_32_2: _animated_sprite_32_2 = a; break;
        default: break;
        }
    }

    void free(AnimationSlot slot) {
        switch(slot) {
        case SLOT_8_1: _animated_sprite_8_1.reset(); break;
        case SLOT_8_2: _animated_sprite_8_2.reset(); break;
        case SLOT_8_3: _animated_sprite_8_3.reset(); break;
        case SLOT_8_4: _animated_sprite_8_4.reset(); break;
        case SLOT_8_5: _animated_sprite_8_5.reset(); break;
        case SLOT_8_6: _animated_sprite_8_6.reset(); break;
        case SLOT_8_7: _animated_sprite_8_7.reset(); break;
        case SLOT_8_8: _animated_sprite_8_8.reset(); break;
        case SLOT_8_9: _animated_sprite_8_9.reset(); break;
        case SLOT_8_10: _animated_sprite_8_10.reset(); break;
        default: break;
        }
    }

    //! \brief render cursor when choosing save/load slots
    void render_save_cursor(int choice) {
        if (choice == 3) {
            _cursor.value().set_x(save_screen_back_x-10);
            _cursor.value().set_y(save_screen_back_y);
        } else {
            _cursor.value().set_x(save_screen_x -10);
            _cursor.value().set_y(save_screen_y + save_screen_y_inc*choice);
        }
    }

    //! \brief generic render and wait for the save and load screen
    int wait_save_load_screen() {
        free();
        _bg_save_screen = _bg_save_screen_item.value().create_bg(TOP_LEFT_COORD_X_BG(0),TOP_LEFT_COORD_Y_BG(0));
        _bg_save_screen.value().set_blending_enabled(true);
        fade_in_from_black();
        create_cursor();
        render_save_cursor(0);

        bn::sprite_text_generator gen(common::variable_8x8_sprite_font);
        gen.set_left_alignment();
        auto sprites = gen.generate<32>(save_screen_back_x, save_screen_back_y, "back");
        for(auto s : sprites) {
            _save_screen_items.push_back(s);
        }

        _read_all_saves.value()();
        bn::fixed x = save_screen_x;
        bn::fixed y = save_screen_y;
        for(int slot = 0; slot < 3; slot++) {
            _render_save_slot.value()(slot, x, y, gen, &_save_screen_items);
            y += save_screen_y_inc;
        }

        int selection = wait_for_menu_item(4, render_save_cursor);
        fade_out_to_black();
        return selection;
    }

    bool wait_save_screen() {
        int selection = wait_save_load_screen();
        if(selection != 3) {
            _write_to_slot.value()(selection);
            return true;
        }
        return false;
    }

    bool wait_load_screen() {
        int selection = wait_save_load_screen();
        if(selection != 3) {
            _save_slot_selected.value()(selection);
            return true;
        }
        return false;
    }

    //! \brief render credits and wait for input to close
    void wait_credits_screen() {

    }

    //! \brief render cursor when at the title screen
    void render_title_cursor(int choice) {
        _cursor.value().set_x(title_cursor_x);
        _cursor.value().set_y(title_cursor_y + text_y_inc*choice);
    }

    void set_save_screen(bn::regular_bg_item bg_save_screen_item) {
        _bg_save_screen_item = bg_save_screen_item;
    }

    void set_bg_textbox(bn::regular_bg_item bg_textbox_item) {
        _bg_textbox_item = bg_textbox_item;
    }

    void set_keyboard(bn::regular_bg_item bg_keyboard_item) {
        _bg_keyboard_item = bg_keyboard_item;
    }

    void set_cursor(bn::sprite_item cursor_item) {
        _cursor_item = cursor_item;
    }

    void set_menu_option_left(bn::sprite_item item) {
        _bg_menu_left_sp_item = item;
    }

    void set_menu_option_right(bn::sprite_item item) {
        _bg_menu_right_sp_item = item;
    }
    
    void set_story_init(story_fx init) {
        _story_init = init;
    }

    void next(story_fx story) {
        _next_story = story;
    }

    void end(EndingType end) {
        _end_state = end;
    }

    void set_read_all_saves(void (*read_all_saves)()) {
        _read_all_saves = read_all_saves;
    }

    void set_save_slot_selected(void (*save_slot_selected)(int)) {
        _save_slot_selected = save_slot_selected;
    }

    void set_write_to_slot(void (*write_to_slot)(int)) {
        _write_to_slot = write_to_slot;
    }

    void set_render_save_slot(void (*render_save_slot)(int, bn::fixed, bn::fixed, bn::sprite_text_generator, bn::vector<bn::sprite_ptr, 96>*)) {
        _render_save_slot = render_save_slot;
    }

    void set_end_fx(end_fx fx) {
        _end_handler = fx;
    }

    void set_fade_times(int times) {
        _fade_times = times;
    }

    void maybe_handle_ending() {
        if(_end_state.has_value()) {
            auto value = _end_state.value();
            _end_state.reset();
            _end_handler.value()(value);
        }
    }

    void main() {
        bn::core::init();
        next(_story_init.value());
        while(_next_story.has_value())
        {
            // advance scene
            auto story = _next_story.value();
            _next_story.reset();
            story();
        }
    }
}