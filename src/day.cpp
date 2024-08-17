#include "day.h"

namespace day {
    //! \brief play a different tune each weekday. play weekend tune on Saturday and Sunday
    void play_daily_music() {
        switch(state::st.day % 7) {
        case 0: PLAY_BG_MUSIC_MONDAY break;
        case 1: PLAY_BG_MUSIC_TUESDAY break;
        case 2: PLAY_BG_MUSIC_WEDNESDAY break;
        case 3: PLAY_BG_MUSIC_THURSDAY break;
        case 4: PLAY_BG_MUSIC_FRIDAY break;
        case 5: PLAY_BG_MUSIC_WEEKEND break;
        case 6: PLAY_BG_MUSIC_WEEKEND break;
        default: break;
        }
    }

    void day_starting() {
        play_daily_music();
        if(state::st.is_workday()) {
            // depending on various state elements,
            // advance a side story. otherwise, just desk work
            story::maybe_handle_story();
            NEXT(day::desk_work)
        } else {
            // maybe a weekend event happens
            weekend_event::handle_event();
            NEXT(day_ending)
        }
        // check for ended story
        vnlib::maybe_handle_ending();
    }

    void day_ending() {
        FREE
        BG_HOME_DESK
        SP_DAY_TRANSITION
        SP_MOON_TRANSITION
        PLAY_BG_MUSIC_DAY_END
        FADE_IN
        // inc day
        auto extra = "";
        auto yesterday = state::st.day_name();
        if(state::st.is_saturday() && EMERGENCIES_ARE_ON_SATURDAY) {
            // skip sunday
            state::st.day += 2;
        } else {
            state::st.day += 1;
        }
        // day changed, handle new week on monday
        if(state::st.day % 7 == 0) {
            extra = "(a new week!)";
            state::st.mg_state.weekly_reset();
        }
        auto today = state::st.day_name();
        vnlib::SayOptions say_options;
        say_options.enable_fastforward = false;
        say_options.disable_blocking = false;
        vnlib::say("day end", {
            yesterday,
            "-->",
            today,
            extra
        }, say_options);
        NEXT(day_starting)
        FADE_OUT
    }

    void desk_work_options();

    //! \brief default MenuOptions for grid menu on BG_DESKTOP
    vnlib::MenuOptions desktop_grid_menu_options() {
        auto options = vnlib::default_MenuOptions();
        int top_left_x = 14;
        int top_left_y = 26;
        // text is at bottom, animations are 16 px
        options.choice_x = top_left_x;
        options.choice_y = top_left_y + 18;
        // cursor is over the animations
        options.cursor_x = top_left_x - 8;
        options.cursor_y = top_left_y + 2;
        options.cols = 3;
        options.use_bg = false;
        // x inc is mostly variable width text ~ 6*8 = 48
        options.ani_x_inc = 48;
        // aniation + buffer + text + margin
        options.ani_y_inc = 16 + 2 + 8 + 8;
        return options;
    }

    //! \brief default MenuOptions for single column menu on BG_DESKTOP
    vnlib::MenuOptions desktop_list_menu_options() {
        auto options = vnlib::default_MenuOptions();
        options.use_bg = false;
        options.choice_x = 14;
        options.choice_y = 26;
        options.cursor_x = -4;
        options.cursor_y = 24;
        options.store_selection_as_default = true;
        return options;
    }

    //! \brief add a space of padding to single digit numbers
    bn::string<4> desk_work_progress_pad(int n) {
        if(n < 10) {
            return FMT_24(" {}", n);
        }
        return FMT_24("{}", n);
    }

    //! \brief format progress string for a character
    bn::string<48> desk_work_progress_str(character::CHAR_ENUM c) {
        return FMT_48("{}: {}  {} {}",
            character::string_padded(c),
            desk_work_progress_pad(state::st.rel_state.rels[c]),
            desk_work_progress_pad(state::st.wke_state.story_progress[c]),
            desk_work_progress_pad(state::st.wke_state.emergency_progress[c])
        );
    }

#define DESK_WORK_TERNARY(name, is_unlocked, task) (is_unlocked ? CHOICE(name, [](){ task ; NEXT(day::desk_work_complete) }) : not_unlocked )
#define DESK_WORK_BACK_FX [](){ NEXT(desk_work) }
#define DESK_WORK_BACK CHOICE("back", DESK_WORK_BACK_FX)
#define DESK_WORK_PROGRESS(c) CHOICE(desk_work_progress_str(c), DESK_WORK_BACK_FX)
    void desk_work() {
        FREE
        BG_DESKTOP_WITH_WIDGETS(true)
        SP_CODE
        if(UNLOCKED_MARKETING) { SP_PAPER } else { SP_PAPER_LOCK }
        if(UNLOCKED_SALES) { SP_CALLS } else { SP_CALLS_LOCK }
        if(UNLOCKED_SECURITY) { SP_BUGS } else { SP_BUGS_LOCK }
        SP_PROGRESS
        SP_OPTIONS
        SP_SAVE
        SP_LOAD
        FADE_IN
        auto not_unlocked = CHOICE("<lock>", DESK_WORK_BACK_FX);
        auto code_choice = DESK_WORK_TERNARY("code", true, minigame_code::game() );
        auto mkt_choice = DESK_WORK_TERNARY("paper", UNLOCKED_MARKETING, minigame_paperwork::game() );
        auto sales_choice = DESK_WORK_TERNARY("calls", UNLOCKED_SALES, minigame_calls::game() );
        auto bugs_choice = DESK_WORK_TERNARY("bugs", UNLOCKED_SECURITY, minigame_bugs::game() );
        auto options = desktop_grid_menu_options();
        vnlib::menu(
        {
            code_choice,
            mkt_choice,
            sales_choice,
            bugs_choice,
            CHOICE("prog", [](){
                FREE
                BG_DESKTOP_WITH_WIDGETS(true);
                auto progress_menu_options = desktop_list_menu_options();
                progress_menu_options.use_variable_width = false;
                vnlib::menu({
                    CHOICE("stat  : rel wk em", DESK_WORK_BACK_FX),
                    CHOICE(FMT_32("max   : {}   {}  {}", relationship_state::REL_MAX, 4, 4), DESK_WORK_BACK_FX),
                    DESK_WORK_PROGRESS(character::INO),
                    DESK_WORK_PROGRESS(character::KANADE),
                    DESK_WORK_PROGRESS(character::RIKA),
                    DESK_WORK_PROGRESS(character::RIN),
                    DESK_WORK_BACK
                }, &progress_menu_options);
            }),
            CHOICE("option", [](){
                NEXT(desk_work_options);
            }),
            CHOICE("save", [](){
                FADE_OUT
                vnlib::wait_save_screen();
                NEXT(desk_work);
            }),
            CHOICE("load", [](){
                FADE_OUT
                bool loaded = vnlib::wait_load_screen();
                if(!loaded) {
                    NEXT(desk_work);
                }
            })
        }, &options);
        FADE_OUT
    }

#define RUNTIME_TOGGLE(option) [](){runtime_state::toggle(option); NEXT(desk_work_options)}
    //! \brief global option menu MenuOptions to save selection between renders
    vnlib::MenuOptions desk_work_options_options = desktop_list_menu_options();
    //! \brief set various toggles in runtime_state::runtime_state
    void desk_work_options() {
        FREE
        BG_DESKTOP_WITH_WIDGETS(true);
        FADE_IN
        auto mg_mode_str = FMT_48("Minigame Mode: {}", runtime_state::to_str(state::st.runtime_state.mg_mode));
        auto skip_weekly_progress_str = FMT_48("Require Weekly Progress: {}", state::st.runtime_state.require_weekly_progress);
        auto emergency_day_str = FMT_48("Emergency Day: {}", runtime_state::to_str(state::st.runtime_state.em_day));
        // auto options = desktop_list_menu_options();
        vnlib::menu({
            CHOICE(mg_mode_str, RUNTIME_TOGGLE(&state::st.runtime_state.mg_mode)),
            CHOICE(skip_weekly_progress_str, RUNTIME_TOGGLE(&state::st.runtime_state.require_weekly_progress)),
            CHOICE(emergency_day_str, RUNTIME_TOGGLE(&state::st.runtime_state.em_day)),
            CHOICE("reset to Default", [](){
                auto reset_options = desktop_list_menu_options();
                vnlib::menu({
                    CHOICE("back", [](){
                        NEXT(desk_work_options)
                    }),
                    CHOICE("confirm reset", [](){
                        state::st.runtime_state.init();
                        NEXT(desk_work_options)
                    })
                }, &reset_options);
            }),
            CHOICE("reset to Casual", [](){
                auto reset_options = desktop_list_menu_options();
                vnlib::menu({
                    CHOICE("back", [](){
                        NEXT(desk_work_options)
                    }),
                    CHOICE("confirm reset", [](){
                        state::st.runtime_state.reset_to_casual();
                        NEXT(desk_work_options)
                    })
                }, &reset_options);
            }),
            CHOICE("save", [](){
                FADE_OUT
                vnlib::wait_save_screen();
                NEXT(desk_work_options);
            }),
            CHOICE("back", [](){
                NEXT(desk_work)
            })
        }, &desk_work_options_options);
        FADE_OUT
    }

    void desk_work_complete() {
        NEXT(work_life)
    }

#define WL_BACK [](){NEXT(work_life)}
#define WL_LOCKED CHOICE("<locked>", WL_BACK)
// note: some issues with using FMT_X in functions and falling out of scope (UTF-8 error)
// note: also some issues with lambda scope potentially needing to capture 'c'
#define WL_IM_DO(c) [](){instant_message::send_message(c); NEXT(day::work_life_complete)}
#define WL_OFFLINE(c) CHOICE(FMT_32("{} <offline>", character::string(c)), WL_BACK)
#define WL_ONLINE(c) CHOICE(FMT_32("{}", character::string(c)), WL_IM_DO(c))
#define WL_BUSY(c) CHOICE(FMT_32("{} <busy>", character::string(c)), WL_BACK)
#define WL_IM_STATUS(c) instant_message::status(c)
#define WL_IM_UNLOCKED(c) (WL_IM_STATUS(c) == instant_message::OFFLINE ? WL_OFFLINE(c) : (WL_IM_STATUS(c) == instant_message::BUSY ? WL_BUSY(c) : WL_ONLINE(c)) )
#define WL_IM_CHOICE(c) (state::st.unlock_state.is_unlocked[c] ? WL_IM_UNLOCKED(c) : WL_LOCKED)

    void work_life() {
        FREE
        BG_DESKTOP_WITH_WIDGETS(false)
        SP_IM
        SP_SKIP
        FADE_IN
        auto skip = CHOICE("skip", [](){ NEXT(work_life_complete) });
        if(state::st.day == 0) {
            skip = WL_LOCKED;
        }
        auto options = desktop_grid_menu_options();
        vnlib::menu({
            CHOICE("IM", [](){
                FREE
                BG_DESKTOP_WITH_WIDGETS(false)
                auto im_options = desktop_list_menu_options();
                vnlib::menu({
                    WL_IM_CHOICE(character::INO),
                    WL_IM_CHOICE(character::KANADE),
                    WL_IM_CHOICE(character::RIKA),
                    WL_IM_CHOICE(character::RIN),
                    CHOICE("back", WL_BACK)
                }, &im_options);
            }),
            skip
        }, &options);
        FADE_OUT
    }

    void work_life_complete() {
        NEXT(day_ending);
    }
}