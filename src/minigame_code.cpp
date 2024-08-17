#include "minigame_code.h"
#define INO_INC_GOOD state::st.rel_state.modify_relation(character::INO, relationship_state::GOOD);
#define SUCCESSES state::st.mg_state.successes[minigame_state::CODE]

namespace minigame_code {
    //! \brief perform the operation stored in char, returning 0 if no supported operation found
    int calc(int x, char op, int y) {
        switch(op) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            default:
                return 0;
        }
    }

    //! \brief hack to avoid using std library
    bn::string<8> itos(int i) {
        return FMT_8("{}", i);
    }

    //! \brief convenience to convert char to string
    bn::string<1> opToStr(char op) {
        switch(op) {
            case '+':
                return "+";
            case '-':
                return "-";
            case '*':
                return "*";
            default:
                return "?";
        }
    }

    //! \brief random number generator used for rounds
    bn::random rng;
    //! \brief internal global to support reference from lambdas
    bool successfully_answered;

    void game() {
        FREE
        BG_CODE
        if(state::st.day == 0) {
            MC("hmm this must be", "the programming task")
            MC("looks like I just", "need to operate on", "these numbers")
        } else {
            MC("guess no one", "else wants to", "do this...")
        }
        int level = SUCCESSES / 5;
        int min = 1;
        int x_limit = 1;
        int y_limit = 1;
        int op = '+';
        if(level == 0) {
            min = 1;
            x_limit = 9;
            y_limit = 9;
        } else if (level == 1) {
            min = 7;
            x_limit = 9;
            y_limit = 9;
        } else if (level == 2) {
            min = 11;
            x_limit = 20;
            y_limit = 15;
            op = '*';
        } else if (level == 3) {
            min = 101;
            x_limit = 130;
            y_limit = 199;
            op = '*';
        }
        int x = rng.get_int(min, x_limit);
        int y = rng.get_int(min, y_limit);
        int ans = calc(x, op, y);
        int ans1_modifier = -1 * rng.get_int(1,4);
        int ans2_modifier = rng.get_int(1,4);
        if (level == 2) {
            ans1_modifier = -1 * rng.get_int(10, 20);
            ans2_modifier = rng.get_int(16, 30);
        } else if (level == 3) {
            ans1_modifier = rng.get_int(50, 200);
            ans2_modifier = rng.get_int(201, 400);
        }
        bn::string<8> not_ans_1 = itos(ans + ans1_modifier);
        bn::string<8> not_ans_2 = itos(ans + ans2_modifier);
        bn::string<8> ans_s = itos(ans);
        if(state::st.runtime_state.mg_mode == runtime_state::HINT) {
            ans_s += " <<";
        }
        vnlib::SayOptions options;
        options.enable_fastforward = false;
        options.disable_blocking = true;
        vnlib::say("?", {FMT_24("{} {} {}", x, opToStr(op), y)}, options);
        auto na1 = CHOICE(not_ans_1, [](){
            successfully_answered = false;
        });
        auto na2 = CHOICE(not_ans_2, [](){
            successfully_answered = false;
        });
        auto ca = CHOICE(ans_s, [](){
            successfully_answered = true;
        });
        // pseudo shuffle
        if(state::st.runtime_state.mg_mode == runtime_state::AUTOWIN) {
            EMPTY("a magical force", "crunches the numbers")
            successfully_answered = true;
        }
        else if (rng.get_int(0, 100) < 33) {
            OPTION_MENU(na1,ca,na2)
        } else if (rng.get_int(0, 100) < 50) {
            OPTION_MENU(ca,na1,na2)
        } else {
            OPTION_MENU(na2,na1,ca)
        }
        // increase relationship on success
        if(successfully_answered) {
            SP_HEART_BASIC
            MC("NICE! I got it!")
            INO_INC_GOOD
            state::st.mg_state.on_success(minigame_state::CODE);
            instant_message::thank_you(character::INO);
        } else {
            MC("I need to do better.")
            state::st.mg_state.on_failure(minigame_state::CODE);
        }
    }

}