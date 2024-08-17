#include "widgets.h"

namespace widgets {
    void render_im_widget() {
        SP_IM_WIDGET
        constexpr bn::fixed x_start = 175;
        constexpr bn::fixed y_start = 95;
        constexpr bn::fixed y_inc = 14;
        constexpr bn::fixed text_x = x_start + 40;
        bn::fixed text_y = y_start + 10;
        constexpr bn::fixed sprite_x = text_x + 14;
        for(auto c : character::characters) {
            if(state::st.unlock_state.is_unlocked[c]) {
                vnlib::text(character::string_short(c), text_x, text_y);
            } else {
                vnlib::text("?", text_x, text_y);
            }
            switch(instant_message::status(c)){
            case instant_message::OFFLINE:
                vnlib::sprite(bn::sprite_items::sp_im_widget_offline, sprite_x, text_y);
                break;
            case instant_message::BUSY:
                vnlib::sprite(bn::sprite_items::sp_im_widget_busy, sprite_x, text_y);
                break;
            case instant_message::ONLINE:
                vnlib::sprite(bn::sprite_items::sp_im_widget_online, sprite_x, text_y);
                break;
            default: break;
            }
            text_y += y_inc;
        }
    }
    
    void render_weather_widget(bool morning) {
        if(morning) {
            SP_WEATHER_MORNING
        } else {
            SP_WEATHER_EVENING
        }
    }

    void render_calendar_widget() {
        SP_CALENDAR
        int days_passed = state::st.day % 28;
        constexpr bn::fixed sp_x = 180 + 3;
        constexpr bn::fixed sp_y = 40 + 8;
        // render red X on days passed
        bn::fixed x = sp_x;
        bn::fixed y = sp_y;
        bn::fixed y_inc = 10;
        while(days_passed > 0) {
            if(days_passed == 1) {
                vnlib::sprite(bn::sprite_items::sp_calendar_items_1, x, y);
            } else if (days_passed == 2) {
                vnlib::sprite(bn::sprite_items::sp_calendar_items_2, x, y);
            } else if (days_passed == 3) {
                vnlib::sprite(bn::sprite_items::sp_calendar_items_3, x, y);
            } else if (days_passed == 4) {
                vnlib::sprite(bn::sprite_items::sp_calendar_items_4, x, y);
            } else {
                vnlib::sprite(bn::sprite_items::sp_calendar_items_5, x, y);
            }
            days_passed -= 7;
            y += y_inc;
        }
        // only capable of four weeks shown
        int week = (state::st.day % 28) / 7;
        int weekday = state::st.day % 7;
        bn::fixed today_x = sp_x + (weekday * 8) + 1;
        bn::fixed today_y = sp_y + (week * y_inc) + 1;
        // render cursor on today
        vnlib::sprite(bn::sprite_items::sp_calendar_cursor, today_x, today_y);
    }

    void render_weekly_progress_widget() {
        SP_WEEKLY_PROGRESS
        vnlib::text("TODO:", 175 + 5, 5 + 9);
        bn::fixed sp_x = 175 + 4;
        constexpr bn::fixed sp_y = 25;
        for(int i = 0; i < 3; i++, sp_x += 14) {
            if(state::st.mg_state.weekly_successes > i) {
                vnlib::sprite(bn::sprite_items::sp_im_widget_online, sp_x, sp_y);
            } else {
                vnlib::sprite(bn::sprite_items::sp_im_widget_offline, sp_x, sp_y);
            }
        }
    }

    void all(bool morning) {
        render_im_widget();
        render_weather_widget(morning);
        render_calendar_widget();
        render_weekly_progress_widget();
    }
}