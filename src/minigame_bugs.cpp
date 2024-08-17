#include "minigame_bugs.h"
#define UP bn::keypad::key_type::UP
#define DOWN bn::keypad::key_type::DOWN
#define LEFT bn::keypad::key_type::LEFT
#define RIGHT bn::keypad::key_type::RIGHT
#define SUCCESSES state::st.mg_state.successes[minigame_state::BUGS]
#define MULTIROUND(successes, ...) else if (SUCCESSES == successes) { successfully_answered = multi_round(__VA_ARGS__); }
#define RIN_INC_GOOD state::st.rel_state.modify_relation(character::RIN, relationship_state::GOOD);

namespace minigame_bugs {
    //! \brief spin until no are held
    void wait_for_not_held(bn::vector<bn::keypad::key_type, 12> keys) {
        bool held = true;
        while(held) {
            held = false;
            for(auto k : keys) {
                held = held || bn::keypad::held(k);
            }
            bn::core::update();
        }
    }

    //! \brief spin until either a set of good keys are held or bad keys are held. return true on good and false on bad. 
    bool wait_for_directional(bn::vector<bn::keypad::key_type, 12> good_keys, bn::vector<bn::keypad::key_type, 12> bad_keys) {
        bn::vector<bn::keypad::key_type, 12> all;
        for(auto k : good_keys) {
            all.push_back(k);
        }
        for(auto k : bad_keys) {
            all.push_back(k);
        }
        wait_for_not_held(all);
        while(true) {
            for(auto k : good_keys) {
                if (bn::keypad::held(k)) { return true; }
            }
            for(auto k : bad_keys) {
                if (bn::keypad::held(k)) { return false; }
            }
            bn::core::update();
        }
        return false;
    }

    //! \brief vector of directional keys
    bn::vector<bn::keypad::key_type, 12> directionals() {
        bn::vector<bn::keypad::key_type, 12> directionals;
        directionals.push_back(UP);
        directionals.push_back(DOWN);
        directionals.push_back(LEFT);
        directionals.push_back(RIGHT);
        return directionals;
    }

    //! \brief one round of input (wait for no directional held, then evaluating good/bad)
    bool round(bn::keypad::key_type good_key) {
        bn::vector<bn::keypad::key_type, 12> good_keys;
        good_keys.push_back(good_key);
        bn::vector<bn::keypad::key_type, 12> bad_keys;
        for(auto d : directionals()) {
            if(d != good_key){ bad_keys.push_back(d); }
        }
        return wait_for_directional(good_keys, bad_keys);
    }

    //! \brief internal function used to format key for printing
    bn::string<2> key_short(bn::keypad::key_type key) {
        switch(key){
        case UP: return " U";
        case DOWN: return " D";
        case LEFT: return " L";
        case RIGHT: return " R";
        default: return " ?";
        }
    }

    //! \brief when a key is pressed, render the total number of correct keys pressed
    void render_success(int successes, bn::vector<bn::keypad::key_type, 8> rounds) {
        bn::string<20> out;
        for(int s = 0; s < successes; s++) {
            out += key_short(rounds[s]);
        }
        for(int s = successes; s < rounds.size(); s++) {
            out += " _";
        }
        vnlib::text(out, 60, 60);
    }

    //! \brief play the game using each element for a round of input. return true on success and false on failure
    bool multi_round(bn::vector<bn::keypad::key_type, 8> rounds) {
        int successes = 0;
        bn::string<20> prompt;
        for(auto r : rounds) {
            prompt += key_short(r);
        }
        vnlib::SayOptions options;
        options.enable_fastforward = false;
        options.disable_blocking = true;
        for(auto r : rounds) {
            // re-render desktop so vnlib::text is cleared between rounds
            FREE
            BG_DESKTOP
            render_success(successes, rounds);
            vnlib::say("squash!", {prompt}, options);
            bool passed = false;
            if(state::st.runtime_state.mg_mode == runtime_state::HINT) {
                // skip all but last round
                if(successes < rounds.size() - 1) {
                    passed = true;
                } else {
                    passed = round(r);
                }
            } else {
                passed = round(r);
            }
            if(!passed) {
                return false;
            } else {
                successes += 1;
                render_success(successes, rounds);
            }
        }
        return true;
    }

    //! \brief convience wrapper to convert initializer_list to vector
    bool multi_round(std::initializer_list<bn::keypad::key_type> rounds) {
        bn::vector<bn::keypad::key_type, 8> bn_rounds;
        for(auto r : rounds) {
            bn_rounds.push_back(r);
        }
        return multi_round(bn_rounds);
    }

    //! \brief internal global variable to allow reference from lambdas
    bool successfully_answered;

    void game() {
        FREE
        BG_BUGS
        MC("time to squash", "some bugs!");
        if(state::st.runtime_state.mg_mode == runtime_state::AUTOWIN) {
            EMPTY("a magical force", "squashes the bugs")
            successfully_answered = true;
        }
        // 4
        MULTIROUND(0, {UP, DOWN, UP, DOWN})
        MULTIROUND(1, {UP, UP, DOWN, DOWN})
        MULTIROUND(2, {LEFT, RIGHT, UP, DOWN})
        MULTIROUND(3, {UP, UP, LEFT, LEFT})
        // 6
        MULTIROUND(4, {LEFT, RIGHT, LEFT, RIGHT, LEFT, RIGHT})
        MULTIROUND(5, {UP, DOWN, UP, DOWN, UP, RIGHT})
        MULTIROUND(6, {UP, LEFT, RIGHT, DOWN, LEFT, UP})
        MULTIROUND(7, {LEFT, RIGHT, LEFT, UP, RIGHT, DOWN})
        MULTIROUND(8, {DOWN, DOWN, LEFT, LEFT, DOWN, LEFT})
        MULTIROUND(9, {RIGHT, DOWN, RIGHT, LEFT, UP, RIGHT})
        // 8
        MULTIROUND(10, {UP, DOWN, RIGHT, LEFT, UP, DOWN, RIGHT, LEFT})
        MULTIROUND(11, {LEFT, LEFT, RIGHT, LEFT, DOWN, UP, LEFT, DOWN})
        MULTIROUND(12, {RIGHT, LEFT, UP, DOWN, DOWN, UP, LEFT, RIGHT})
        MULTIROUND(13, {DOWN, DOWN, LEFT, RIGHT, DOWN, RIGHT, UP, LEFT})
        MULTIROUND(14, {LEFT, UP, DOWN, RIGHT, LEFT, UP, RIGHT, DOWN})
        MULTIROUND(15, {UP, UP, DOWN, LEFT, DOWN, RIGHT, UP, UP})
        MULTIROUND(16, {RIGHT, LEFT, UP, UP, DOWN, DOWN, LEFT, UP})
        MULTIROUND(17, {RIGHT, UP, RIGHT, LEFT, DOWN, RIGHT, UP, UP})
        MULTIROUND(18, {DOWN, LEFT, DOWN, RIGHT, UP, DOWN, LEFT, UP})
        MULTIROUND(19, {DOWN, LEFT, LEFT, RIGHT, RIGHT, UP, UP, UP})
        MULTIROUND(20, {RIGHT, RIGHT, RIGHT, RIGHT, RIGHT, RIGHT, RIGHT, UP})
        else {
            MC("guess they are out", "of tasks...")
            successfully_answered = true;
        }

        if(successfully_answered) {
            SP_HEART_BASIC
            RIN_INC_GOOD
            state::st.mg_state.on_success(minigame_state::BUGS);
            MC("phew, got it!")
        } else {
            MC("darn, maybe next time")
            state::st.mg_state.on_failure(minigame_state::BUGS);
        }
    }
}