#pragma once
#include "character.h"
#include "vnlib.h"
#include "state.h"
#include "bn_random.h"
// bg
#include "bn_regular_bg_items_title_screen.h"
#define BG_TITLE_SCREEN vnlib::bg(bn::regular_bg_items::title_screen);
#include "bn_regular_bg_items_bg_end_bad.h"
#define BG_BAD_END vnlib::bg(bn::regular_bg_items::bg_end_bad);
#include "bn_regular_bg_items_bg_end_good.h"
#define BG_GOOD_END vnlib::bg(bn::regular_bg_items::bg_end_good);
#include "bn_regular_bg_items_bg_end_perfect.h"
#define BG_PERFECT_END vnlib::bg(bn::regular_bg_items::bg_end_perfect);
#include "bn_regular_bg_items_bg_desktop.h"
#define BG_DESKTOP vnlib::bg(bn::regular_bg_items::bg_desktop);
#define BG_DESKTOP_WITH_WIDGETS(morning) BG_DESKTOP widgets::all(morning);
#define BG_MG_WIDGETS widgets::render_calendar_widget(); widgets::render_im_widget(); widgets::render_weekly_progress_widget();
#define BG_CODE BG_DESKTOP BG_MG_WIDGETS
#define BG_PAPERWORK BG_DESKTOP BG_MG_WIDGETS
#define BG_CALLS BG_DESKTOP BG_MG_WIDGETS
#define BG_BUGS BG_DESKTOP BG_MG_WIDGETS
#include "bn_regular_bg_items_bg_options.h"
#define BG_OPTIONS vnlib::bg(bn::regular_bg_items::bg_options);
#include "bn_regular_bg_items_bg_plain.h"
#define BG_PLAIN vnlib::bg(bn::regular_bg_items::bg_plain);
#include "bn_regular_bg_items_bg_home_desk.h"
#define BG_HOME_DESK vnlib::bg(bn::regular_bg_items::bg_home_desk);
#include "bn_regular_bg_items_bg_park.h"
#define BG_PARK vnlib::bg(bn::regular_bg_items::bg_park);
#include "bn_regular_bg_items_bg_office_desk.h"
#define BG_OFFICE_DESK vnlib::bg(bn::regular_bg_items::bg_office_desk);
#include "bn_regular_bg_items_bg_im.h"
#define BG_IM vnlib::bg(bn::regular_bg_items::bg_im);
#include "bn_regular_bg_items_bg_ino_room.h"
#define BG_INO_ROOM vnlib::bg(bn::regular_bg_items::bg_ino_room);
#include "bn_regular_bg_items_bg_cafe.h"
#define BG_CAFE vnlib::bg(bn::regular_bg_items::bg_cafe);
#include "bn_regular_bg_items_bg_convenience.h"
#define BG_CONVENIENCE vnlib::bg(bn::regular_bg_items::bg_convenience);
#include "bn_regular_bg_items_bg_pizza_place.h"
#define BG_PIZZA_PLACE vnlib::bg(bn::regular_bg_items::bg_pizza_place);
#include "bn_regular_bg_items_bg_bar.h"
#define BG_BAR vnlib::bg(bn::regular_bg_items::bg_bar);
#include "bn_regular_bg_items_bg_concert_hall.h"
#define BG_CONCERT_HALL vnlib::bg(bn::regular_bg_items::bg_concert_hall);
#include "bn_regular_bg_items_bg_vet_office.h"
#define BG_VET_OFFICE vnlib::bg(bn::regular_bg_items::bg_vet_office);
#include "bn_regular_bg_items_bg_library_park.h"
#define BG_LIBRARY_PARK vnlib::bg(bn::regular_bg_items::bg_library_park);
#include "bn_regular_bg_items_bg_library_inside.h"
#define BG_LIBRARY_INSIDE vnlib::bg(bn::regular_bg_items::bg_library_inside);
#define BG_BOOKSTORE vnlib::bg(bn::regular_bg_items::bg_library_inside);
#include "bn_regular_bg_items_bg_batting_range.h"
#define BG_BATTING_RANGE vnlib::bg(bn::regular_bg_items::bg_batting_range);
#include "bn_regular_bg_items_bg_train_station.h"
#define BG_TRAIN_STATION vnlib::bg(bn::regular_bg_items::bg_train_station);
#include "bn_regular_bg_items_bg_flower_city.h"
#define BG_FLOWER_CITY vnlib::bg(bn::regular_bg_items::bg_flower_city);
#include "bn_regular_bg_items_bg_ino_parents_house.h"
#define BG_INO_PARENTS_HOUSE vnlib::bg(bn::regular_bg_items::bg_ino_parents_house);
#include "bn_regular_bg_items_bg_grocery_store.h"
#define BG_GROCERY_STORE vnlib::bg(bn::regular_bg_items::bg_grocery_store);
#include "bn_regular_bg_items_bg_street.h"
#define BG_STREET vnlib::bg(bn::regular_bg_items::bg_street);
#include "bn_regular_bg_items_bg_kanade_room.h"
#define BG_KANADES_ROOM vnlib::bg(bn::regular_bg_items::bg_kanade_room);
#include "bn_regular_bg_items_bg_kanades_kitchen.h"
#define BG_KITCHEN vnlib::bg(bn::regular_bg_items::bg_kanades_kitchen);
#include "bn_regular_bg_items_bg_kanades_living_room.h"
#define BG_LIVING_ROOM vnlib::bg(bn::regular_bg_items::bg_kanades_living_room);
#include "bn_regular_bg_items_bg_diner.h"
#define BG_DINER vnlib::bg(bn::regular_bg_items::bg_diner);
#include "bn_regular_bg_items_bg_warehouse.h"
#define BG_WAREHOUSE vnlib::bg(bn::regular_bg_items::bg_warehouse);
#include "bn_regular_bg_items_bg_rins_apartment_door.h"
#define BG_RINS_APARTMENT_DOOR vnlib::bg(bn::regular_bg_items::bg_rins_apartment_door);
#include "bn_regular_bg_items_bg_rins_room.h"
#define BG_RINS_ROOM vnlib::bg(bn::regular_bg_items::bg_rins_room);
#include "bn_regular_bg_items_bg_gardening_store.h"
#define BG_GARDENING_STORE vnlib::bg(bn::regular_bg_items::bg_gardening_store);
#include "bn_regular_bg_items_bg_rikas_garden.h"
#define BG_RIKAS_GARDEN vnlib::bg(bn::regular_bg_items::bg_rikas_garden);
#include "bn_regular_bg_items_bg_game_store.h"
#define BG_GAME_STORE vnlib::bg(bn::regular_bg_items::bg_game_store);
#include "bn_regular_bg_items_bg_internet_cafe.h"
#define BG_INTERNET_CAFE vnlib::bg(bn::regular_bg_items::bg_internet_cafe);
#include "bn_regular_bg_items_bg_forest.h"
#define BG_FOREST vnlib::bg(bn::regular_bg_items::bg_forest);
#include "bn_regular_bg_items_bg_lake.h"
#define BG_LAKE vnlib::bg(bn::regular_bg_items::bg_lake);
#include "bn_regular_bg_items_bg_karaoke.h"
#define BG_KARAOKE vnlib::bg(bn::regular_bg_items::bg_karaoke);
#include "bn_regular_bg_items_bg_karaoke_hallway.h"
#define BG_KARAOKE_HALLWAY vnlib::bg(bn::regular_bg_items::bg_karaoke_hallway);
#include "bn_regular_bg_items_bg_card_shop.h"
#define BG_CARD_SHOP vnlib::bg(bn::regular_bg_items::bg_card_shop);
#include "bn_regular_bg_items_bg_sports_shop.h"
#define BG_SPORTS_SHOP vnlib::bg(bn::regular_bg_items::bg_sports_shop);
#include "bn_regular_bg_items_bg_dollar_shop.h"
#define BG_DOLLAR_SHOP vnlib::bg(bn::regular_bg_items::bg_dollar_shop);
#include "bn_regular_bg_items_bg_pottery_shop.h"
#define BG_POTTERY_SHOP vnlib::bg(bn::regular_bg_items::bg_pottery_shop);
#include "bn_regular_bg_items_bg_clothing_shop.h"
#define BG_CLOTHING_SHOP vnlib::bg(bn::regular_bg_items::bg_clothing_shop);
// TODO: maybe rika's house (table with game)
#define BG_RIKAS_HOUSE BG_INO_PARENTS_HOUSE
// sp
#include "bn_sprite_items_sp_leaf.h"
#define SP_LEAF vnlib::animate_8(bn::sprite_items::sp_leaf, 24,24, vnlib::SLOT_8_1, 0,1,2,3, 4,5,6,7);
#include "bn_sprite_items_sp_emergency_phone.h"
#define SP_EMERGENCY_PHONE vnlib::animate_8(bn::sprite_items::sp_emergency_phone, 115,80, vnlib::SLOT_8_10, 0,0,0,0,1,2,3,4);
#define SP_EMERGENCY_PHONE_FREE vnlib::free(vnlib::SLOT_8_10);
#define SP_GRID_X 14
#define SP_GRID_Y 26
#define SP_GRID_X_EXTRA 4
#define SP_OFFSET_X 50
#define SP_OFFSET_Y 34
#define SP_COORDS(x, y) SP_GRID_X+SP_GRID_X_EXTRA+(x*SP_OFFSET_X),SP_GRID_Y+(y*SP_OFFSET_Y)
#include "bn_sprite_items_sp_lock.h"
#include "bn_sprite_items_sp_code.h"
#define SP_CODE vnlib::animate_8(bn::sprite_items::sp_code, SP_COORDS(0,0), vnlib::SLOT_8_1, 0,1,2,1, 2,1,0,0);
#include "bn_sprite_items_sp_paper.h"
#define SP_PAPER vnlib::animate_8(bn::sprite_items::sp_paper, SP_COORDS(1,0), vnlib::SLOT_8_2, 3,3,3,3, 0,1,2,3);
#define SP_PAPER_LOCK vnlib::animate_8(bn::sprite_items::sp_lock, SP_COORDS(1,0), vnlib::SLOT_8_2, 0,0,0,0, 0,0,0,0);
#include "bn_sprite_items_sp_calls.h"
#define SP_CALLS vnlib::animate_8(bn::sprite_items::sp_calls, SP_COORDS(2,0), vnlib::SLOT_8_3, 0,0,0,0, 0,1,2,3);
#define SP_CALLS_LOCK vnlib::animate_8(bn::sprite_items::sp_lock, SP_COORDS(2,0), vnlib::SLOT_8_3, 0,0,0,0, 0,0,0,0);
#include "bn_sprite_items_sp_bugs.h"
#define SP_BUGS vnlib::animate_8(bn::sprite_items::sp_bugs, SP_COORDS(0,1), vnlib::SLOT_8_4, 1,0,1,2, 1,1,1,1);
#define SP_BUGS_LOCK vnlib::animate_8(bn::sprite_items::sp_lock, SP_COORDS(0,1), vnlib::SLOT_8_4, 0,0,0,0, 0,0,0,0);
#include "bn_sprite_items_sp_progress.h"
#define SP_PROGRESS vnlib::animate_8(bn::sprite_items::sp_progress, SP_COORDS(1,1), vnlib::SLOT_8_5, 4,4,0,1, 2,3,4,4);
#include "bn_sprite_items_sp_options.h"
#define SP_OPTIONS vnlib::animate_8(bn::sprite_items::sp_options, SP_COORDS(2,1), vnlib::SLOT_8_6, 0,1,2,3, 0,1,2,3);
#include "bn_sprite_items_sp_save.h"
#define SP_SAVE vnlib::animate_8(bn::sprite_items::sp_save, SP_COORDS(0,2), vnlib::SLOT_8_7, 0,0,0,0, 1,2,3,4);
#include "bn_sprite_items_sp_load.h"
#define SP_LOAD vnlib::animate_8(bn::sprite_items::sp_load, SP_COORDS(1,2), vnlib::SLOT_8_8, 0,0,1,2, 3,4,0,0);
#include "bn_sprite_items_sp_im.h"
#define SP_IM vnlib::animate_8(bn::sprite_items::sp_im, SP_COORDS(0,0), vnlib::SLOT_8_1, 0,1,2,3, 4,3,2,1);
#include "bn_sprite_items_sp_skip.h"
#define SP_SKIP vnlib::animate_8(bn::sprite_items::sp_skip, SP_COORDS(1,0), vnlib::SLOT_8_2, 0,1,2,3, 4,5,6,7);
#include "bn_sprite_items_sp_im_widget.h"
#define SP_IM_WIDGET vnlib::sprite(bn::sprite_items::sp_im_widget, 175,95);
#include "bn_sprite_items_sp_im_widget_online.h"
#include "bn_sprite_items_sp_im_widget_busy.h"
#include "bn_sprite_items_sp_im_widget_offline.h"
#include "bn_sprite_items_sp_calendar_cursor.h"
#include "bn_sprite_items_sp_calendar_items_1.h"
#include "bn_sprite_items_sp_calendar_items_2.h"
#include "bn_sprite_items_sp_calendar_items_3.h"
#include "bn_sprite_items_sp_calendar_items_4.h"
#include "bn_sprite_items_sp_calendar_items_5.h"
#include "bn_sprite_items_sp_calendar.h"
#define SP_CALENDAR vnlib::sprite(bn::sprite_items::sp_calendar, 180,40);
#include "bn_sprite_items_sp_weather_morning.h"
#define SP_WEATHER_MORNING vnlib::sprite(bn::sprite_items::sp_weather_morning, 100,105);
#include "bn_sprite_items_sp_weather_evening.h"
#define SP_WEATHER_EVENING vnlib::sprite(bn::sprite_items::sp_weather_evening, 100,105);
#define SP_TITLE_COORDS(x, y) 35+(x*SP_OFFSET_X),100
#include "bn_sprite_items_sp_how_to.h"
#define SP_HOW_TO_TITLE vnlib::animate_8(bn::sprite_items::sp_how_to, SP_TITLE_COORDS(0,0), vnlib::SLOT_8_1, 0,1,2,3, 2,4,2,1);
#include "bn_sprite_items_sp_new_game.h"
#define SP_NEW_GAME_TITLE vnlib::animate_8(bn::sprite_items::sp_new_game, SP_TITLE_COORDS(1,0), vnlib::SLOT_8_2, 0,1,2,1, 0,0,0,0);
#define SP_LOAD_TITLE vnlib::animate_8(bn::sprite_items::sp_load, SP_TITLE_COORDS(2,0), vnlib::SLOT_8_3, 0,0,1,2, 3,4,0,0);
#define SP_CREDITS_TITLE vnlib::animate_8(bn::sprite_items::sp_paper, SP_TITLE_COORDS(3,0), vnlib::SLOT_8_4, 3,0,1,2, 3,3,3,3);
#include "bn_sprite_items_sp_heart_basic.h"
#define SP_HEART_BASIC vnlib::animate_32(bn::sprite_items::sp_heart_basic, 140,100, vnlib::SLOT_32_1, 0,1,2,3,4,5,6,7, 8,9,10,11,12,13,14,15, 16,17,18,19,20,21,22,23, 24,25,26,27,28,29,30,31);
#include "bn_sprite_items_sp_weekly_progress_widget.h"
#define SP_WEEKLY_PROGRESS vnlib::sprite(bn::sprite_items::sp_weekly_progress_widget, 175,5);
#include "bn_sprite_items_sp_day_transition.h"
#define SP_DAY_TRANSITION vnlib::animate_32(bn::sprite_items::sp_day_transition, 28,46, vnlib::SLOT_32_1, 0,1,2,3,4,5,6,7, 8,9,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0);
#include "bn_sprite_items_sp_moon_transition.h"
#define SP_MOON_TRANSITION vnlib::animate_32(bn::sprite_items::sp_moon_transition, 140,20, vnlib::SLOT_32_2, 0,1,2,3,4,5,6,7, 8,9,10,11,12,13,14,15, 16,17,18,19,20,21,22,23, 24,25,26,27,28,29,30,31);
// music
#include "bn_sound_items.h"
#define MUSIC(day, part) bn::sound_items::jazz_##day##part
#define MUSIC_MO(part) MUSIC(monday_, part)
#define MUSIC_TU(part) MUSIC(tuesday_, part)
#define MUSIC_WE(part) MUSIC(wednesday_, part)
#define MUSIC_TH(part) MUSIC(thursday_, part)
#define MUSIC_FR(part) MUSIC(friday_, part)
#define MUSIC_SA(part) MUSIC(saturday_, part)
#define MUSIC_DAY_END(part) MUSIC(day_end_, part)
#define PLAY_BG_MUSIC_MONDAY vnlib::play_music({MUSIC_MO(000),MUSIC_MO(001),MUSIC_MO(002),MUSIC_MO(003),MUSIC_MO(004),MUSIC_MO(005)});
#define PLAY_BG_MUSIC_TUESDAY vnlib::play_music({MUSIC_TU(000),MUSIC_TU(001),MUSIC_TU(002),MUSIC_TU(003),MUSIC_TU(004)});
#define PLAY_BG_MUSIC_WEDNESDAY vnlib::play_music({MUSIC_WE(000),MUSIC_WE(001),MUSIC_WE(002),MUSIC_WE(003)});
#define PLAY_BG_MUSIC_THURSDAY vnlib::play_music({MUSIC_TH(000),MUSIC_TH(001),MUSIC_TH(002),MUSIC_TH(003),MUSIC_TH(004)});
#define PLAY_BG_MUSIC_FRIDAY vnlib::play_music({MUSIC_FR(000),MUSIC_FR(001),MUSIC_FR(002),MUSIC_FR(003),MUSIC_FR(004),MUSIC_FR(005)});
#define PLAY_BG_MUSIC_LOBBY PLAY_BG_MUSIC_MONDAY
#define PLAY_BG_MUSIC_SATURDAY vnlib::play_music({MUSIC_SA(000),MUSIC_SA(001),MUSIC_SA(002),MUSIC_SA(003),MUSIC_SA(004),MUSIC_SA(005),MUSIC_SA(006),MUSIC_SA(007)});
#define PLAY_BG_MUSIC_WEEKEND PLAY_BG_MUSIC_SATURDAY
#define PLAY_BG_MUSIC_DAY_END vnlib::play_music({MUSIC_DAY_END(000),MUSIC_DAY_END(001),MUSIC_DAY_END(002),MUSIC_DAY_END(002),MUSIC_DAY_END(002),MUSIC_DAY_END(002)});
// chars
#include "bn_regular_bg_items_char_kanade_normal.h"
#define SHOW_KANADE_NORMAL vnlib::show(bn::regular_bg_items::char_kanade_normal);
#include "bn_regular_bg_items_char_kanade_happy.h"
#define SHOW_KANADE_HAPPY vnlib::show(bn::regular_bg_items::char_kanade_happy);
#include "bn_regular_bg_items_char_kanade_sick.h"
#define SHOW_KANADE_SICK vnlib::show(bn::regular_bg_items::char_kanade_sick);
#define SHOW_KANADE_ANGRY SHOW_KANADE_NORMAL
#include "bn_regular_bg_items_char_ino_normal.h"
#define SHOW_INO_NORMAL vnlib::show(bn::regular_bg_items::char_ino_normal);
#include "bn_regular_bg_items_char_ino_happy.h"
#define SHOW_INO_HAPPY vnlib::show(bn::regular_bg_items::char_ino_happy);
#define SHOW_INO_SCARED SHOW_INO_NORMAL
#include "bn_regular_bg_items_char_rika_normal.h"
#define SHOW_RIKA_NORMAL vnlib::show(bn::regular_bg_items::char_rika_normal);
#include "bn_regular_bg_items_char_rika_happy.h"
#define SHOW_RIKA_HAPPY vnlib::show(bn::regular_bg_items::char_rika_happy);
#include "bn_regular_bg_items_char_selene.h"
#define SHOW_RIKAS_SISTER vnlib::show(bn::regular_bg_items::char_selene);
#include "bn_regular_bg_items_char_rin_normal.h"
#define SHOW_RIN_NORMAL vnlib::show(bn::regular_bg_items::char_rin_normal);
#include "bn_regular_bg_items_char_rin_happy.h"
#define SHOW_RIN_HAPPY vnlib::show(bn::regular_bg_items::char_rin_happy);
#include "bn_regular_bg_items_char_stella.h"
#define SHOW_STELLA vnlib::show(bn::regular_bg_items::char_stella);
#include "bn_regular_bg_items_char_irene.h"
#define SHOW_IRENE vnlib::show(bn::regular_bg_items::char_irene);
// say
#define KANADE(...) vnlib::say("Kanade", {__VA_ARGS__});
#define INO(...) vnlib::say("Ino", {__VA_ARGS__});
#define RIKA(...) vnlib::say("Rika", {__VA_ARGS__});
#define RIN(...) vnlib::say("Rin", {__VA_ARGS__});
#define MC(...) vnlib::say(state::st.mc_name, {__VA_ARGS__});
#define MCF(fmts) FMT_32(fmts, state::st.mc_name)
#define MCOP(options, ...) vnlib::say(state::st.mc_name, {__VA_ARGS__}, options);
#define COMPUTER(...) vnlib::say("computer", {__VA_ARGS__});
#define EMPTY(...) vnlib::say("", {__VA_ARGS__});

// lib
#include "bn_regular_bg_items_save_screen.h"
#include "bn_regular_bg_items_textbox_small.h"
#include "bn_regular_bg_items_keyboard.h"
#include "bn_sprite_items_cursor.h"
#include "bn_sprite_items_sp_menu_item_left.h"
#include "bn_sprite_items_sp_menu_item_right.h"
#define FREE vnlib::free();
#define NEXT(n) vnlib::next(n);
#define MENU(...) vnlib::menu({__VA_ARGS__});
#define OPTION_MENU(...) vnlib::menu({__VA_ARGS__}, vnlib::default_MenuOptions().with_use_bg(false)->with_choice_y(40)->with_cursor_y(40));
#define CHOICE(what, fx) vnlib::choice(what, fx)
#define HIDE vnlib::hide();
#define FADE_IN vnlib::fade_in_from_black();
#define FADE_OUT vnlib::fade_out_to_black();
#define SCENE_END HIDE vnlib::hide_say(); FADE_OUT FREE