#include "main_character_state.h"

namespace main_character_state {
    bn::string<24> to_string(preference p) {
        switch(p) {
        // items
        case none: return "none";
        case croissant: return "croissant";
        case cinnamon_roll: return "cinnamon roll";
        case chocolate_item: return "chocolate";
        case kaiju_for_lunch: return "Kaiju for Lunch";
        case weekend_at_darlenes: return "Weekend at Darlene's";
        case cooking_fury: return "Cooking Fury";
        case hamburgers: return "hamburgers";
        case crispy_chicken: return "crispy chicken";
        case mushrooms: return "mushrooms";
        case ridgeline_ale: return "Ridgeline Ale";
        case blitz_ipa: return "Blitz IPA";
        case summer_hefe: return "Summar Hefe";
        case cheese_pizza: return "cheese pizza";
        case meat_lovers_pizza: return "meat lovers pizza";
        case slice_of_the_day: return "the slice of the day";
        case trail_mix: return "trail mix";
        case chocolate_cookies: return "chocolate cookies";
        case bbq_chips: return "bbq chips";

        // hobbies
        case pizza_place: return "pizza place";
        case bar: return "bar";
        case convenience: return "convenience store";
        default: return "?";
        }
    }
}