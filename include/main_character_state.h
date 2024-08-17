#pragma once
#include "util.h"

//! \brief state representing main character choices and preferences
namespace main_character_state {
    //! \brief generic struct used to represent various preferences
    enum preference {
        none = 0,
        //******************************************************
        //************************ ITEMS ***********************
        //******************************************************
        //! \brief see mc_state.mc_cafe_item_preference
        croissant = 1,
        //! \brief see mc_state.mc_cafe_item_preference
        cinnamon_roll = 2,
        //! \brief see mc_state.mc_cafe_item_preference
        chocolate_item = 3,
        //! \brief see mc_state.ino_pizza_place_food
        sausage_pizza = 4,
        //! \brief see mc_state.ino_pizza_place_food
        veggie_pizza = 5,
        //! \brief see mc_state.ino_pizza_place_food
        salad = 6,
        //! \brief see mc_state.ino_pizza_place_drink and mc_state.rin_alcohol_prep
        beer = 7,
        //! \brief see mc_state.ino_pizza_place_drink
        water = 8,
        //! \brief see mc_state.ino_convenience_drink
        waterade = 9,
        //! \brief see mc_state.ino_convenience_drink
        green_tea = 10,
        //! \brief see mc_state.ino_convenience_drink
        coffee = 11,
        //! \brief see mc_state.kanade_book_sale_book
        kaiju_for_lunch = 12,
        //! \brief see mc_state.kanade_book_sale_book
        weekend_at_darlenes = 13,
        //! \brief see mc_state.kanade_book_sale_book
        cooking_fury = 14,
        //! \brief see mc_state.ino_grill_item
        hamburgers = 15,
        //! \brief see mc_state.ino_grill_item
        crispy_chicken = 16,
        //! \brief see mc_state.ino_grill_item
        mushrooms = 17,
        //! \brief see mc_state.ino_family_beer
        ridgeline_ale = 18,
        //! \brief see mc_state.ino_family_beer
        blitz_ipa = 19,
        //! \brief see mc_state.ino_family_beer
        summer_hefe = 20,
        //! \brief see mc_state.ino_family_beer
        dads_favorite = 21,
        //! \brief see mc_state.kanade_ingredient_1
        brown_sugar = 22,
        //! \brief see mc_state.kanade_ingredient_1
        powdered_sugar = 23,
        //! \brief see mc_state.kanade_ingredient_1
        granulated_sugar = 24,
        //! \brief see mc_state.kanade_ingredient_2
        tamarind_extract = 25,
        //! \brief see mc_state.kanade_ingredient_2
        vanilla_bean_extract = 26,
        //! \brief see mc_state.kanade_ingredient_2
        coffee_bean_extract = 27,
        //! \brief see mc_state.kanade_sick_item
        frozen_pizza = 28,
        //! \brief see mc_state.kanade_sick_item
        soup = 29,
        //! \brief see mc_state.kanade_sick_item
        mac_and_cheese = 30,
        //! \brief see mc_state.rin_triangle_chip
        cheezy_triangles = 31,
        //! \brief see mc_state.rin_triangle_chip
        cool_triangles = 32,
        //! \brief see mc_state.rin_triangle_chip
        fire_triangles = 33,
        //! \brief see mc_state.rin_alcohol_prep
        vodka = 34,
        //! \brief see mc_state.rin_pizza
        everything_pizza = 35,
        //! \brief see mc_state.rin_pizza
        cheese_pizza = 36,
        //! \brief see mc_state.rin_pizza
        meat_lovers_pizza = 37,
        //! \brief see mc_state.kanade_ingredient_3
        banana = 38,
        //! \brief see mc_state.kanade_ingredient_3
        blueberries = 39,
        //! \brief see mc_state.kanade_ingredient_3
        strawberries = 40,
        //! \brief see mc_state.kanade_ingredient_4
        butter_and_eggs = 41,
        //! \brief see mc_state.kanade_ingredient_4
        heavy_whipping_cream_eggs = 42,
        //! \brief see mc_state.kanade_ingredient_4
        chocolate_milk_eggs = 43,
        //! \brief see mc_state.kanade_post_book_place_item
        slice_of_the_day = 44,
        //! \brief see mc_state.kanade_post_book_place_item
        trail_mix = 45,
        //! \brief see mc_state.kanade_post_book_place_item
        chocolate_cookies = 46,
        //! \brief see mc_state.kanade_post_book_place_item
        bbq_chips = 47,



        //******************************************************
        //*********************** HOBBIES **********************
        //******************************************************
        //! \brief see mc_state.mc_music_talent
        does_not_make_music = 101,
        //! \brief see mc_state.mc_music_talent
        sings = 101,
        //! \brief see mc_state.mc_music_talent
        part_of_band = 103,
        //! \brief see mc_state.mc_music_preference
        punk_rock = 104,
        //! \brief see mc_state.mc_music_preference
        rnb = 105,
        //! \brief see mc_state.mc_music_preference
        shoegaze = 106,
        //! \brief see mc_state.kanade_post_book_place
        pizza_place = 107,
        //! \brief see mc_state.kanade_post_book_place
        bar = 108,
        //! \brief see mc_state.kanade_post_book_place
        convenience = 109,
        //! \brief see mc_state.kanade_weekend_activity
        cleaning = 110,
        //! \brief see mc_state.kanade_weekend_activity
        fancy_meal = 111,
        //! \brief see mc_state.kanade_weekend_activity
        watching_anime = 112,
        //! \brief see mc_state.mc_volunteering_state
        does_not_enjoy_volunteering = 113,
        //! \brief see mc_state.mc_volunteering_state
        ate_the_chips = 114,
        //! \brief see mc_state.mc_volunteering_state
        saved_the_chips = 115,
        //! \brief see mc_state.rika_basketball_team
        same_team = 116,
        //! \brief see mc_state.rika_basketball_team
        other_team = 117,
        //! \brief see mc_state.rin_game_selection
        fighting_game = 118,
        //! \brief see mc_state.rin_game_selection
        racing_game = 119,
        //! \brief see mc_state.rin_game_selection
        casual_game = 120,
        //! \brief see mc_state.rika_sister_question
        learned_sister_hobbies = 121,
        //! \brief see mc_state.rika_sister_question
        learned_sister_jobs = 122
    };

    //! \brief convert item into text. may not always have translation
    bn::string<24> to_string(preference i);

    //! \brief state struct containing various stateful item preferences
    struct mc_state {
        //! \brief see weekend_event::ino_emergency_0
        preference mc_music_talent;
        //! \brief see weekend_event::ino_emergency_0
        preference mc_music_preference;
        //! \brief see weekend_event::ino_emergency_1
        preference ino_convenience_drink;
        //! \brief see weekend_event::ino_emergency_2
        preference ino_pizza_place_food;
        //! \brief see weekend_event::ino_emergency_2
        preference ino_pizza_place_drink;
        //! \brief see weekend_event::ino_weekend_0
        preference mc_cafe_item_preference;
        //! \brief see weekend_event::kanade_emergency_1
        preference kanade_book_sale_book;
        //! \brief see weekend_event::kanade_emergency_2
        preference kanade_post_book_place;
        //! \brief see weekend_event::ino_weekend_3
        preference ino_grill_item;
        //! \brief see weekend_event::ino_weekend_3
        preference ino_family_beer;
        //! \brief see weekend_event::kanade_weekend_0
        preference kanade_weekend_activity;
        //! \brief see weekend_event::kanade_weekend_0
        preference kanade_ingredient_1;
        //! \brief see weekend_event::kanade_weekend_0
        preference kanade_ingredient_2;
        //! \brief see weekend_event::kanade_weekend_1
        preference kanade_sick_item;
        //! \brief see weekend_event::kanade_weekend_2
        preference mc_volunteering_state;
        //! \brief see weekend_event::kanade_weekend_3
        preference kanade_ingredient_3;
        //! \brief see weekend_event::kanade_weekend_3
        preference kanade_ingredient_4;
        //! \brief see weekend_event::rin_emergency_0 and weekend_event::rin_emergency_3
        preference rin_triangle_chip;
        //! \brief see weekend_event::rin_emergency_0
        preference rin_alcohol_prep;
        //! \brief see weekend_event::rin_emergency_0
        preference rin_maybe_eat_chips;
        //! \brief see weekend_event::rin_emergency_1 and weekend_event::rin_emergency_3
        preference rin_pizza;
        //! \brief see weekend_event::rin_emergency_2
        preference rin_alcohol_prep_2;
        //! \brief see weekend_event::rika_emergency_0
        preference rika_basketball_team;
        //! \brief see weekend_event::kanade_emergency_2
        preference kanade_post_book_place_item;
        //! \brief see weekend_event::rin_emergency_0
        preference rin_game_selection;
        //! \brief see weekend_event::rika_weekend_2;
        preference rika_sister_question;

        //! \brief initialize the struct
        void init() {
            mc_music_talent = none;
            mc_music_preference = none;
            ino_convenience_drink = none;
            ino_pizza_place_food = none;
            ino_pizza_place_drink = none;
            mc_cafe_item_preference = none;
            kanade_book_sale_book = none;
            kanade_post_book_place = none;
            ino_grill_item = none;
            ino_family_beer = none;
            kanade_weekend_activity = none;
            kanade_ingredient_1 = none;
            kanade_ingredient_2 = none;
            kanade_sick_item = none;
            mc_volunteering_state = none;
            kanade_ingredient_3 = none;
            kanade_ingredient_4 = none;
            rin_triangle_chip = none;
            rin_alcohol_prep = none;
            rin_maybe_eat_chips = none;
            rin_pizza = none;
            rin_alcohol_prep_2 = none;
            rika_basketball_team = none;
            rika_sister_question = none;
        }
    };
}