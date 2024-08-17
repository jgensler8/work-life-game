#include "minigame_calls.h"
#define RIKA_INC_GOOD state::st.rel_state.modify_relation(character::RIKA, relationship_state::GOOD);
#define SUCCESSES state::st.mg_state.successes[minigame_state::CALLS]

namespace minigame_calls {
    //! \brief keyboard input for sales call question
    bool wait_for_answer(std::initializer_list<bn::string_view> question, bn::string_view answer) {
        vnlib::SayOptions options;
        options.enable_fastforward = false;
        options.disable_blocking = true;
        vnlib::say("system", question, options);
        bn::string<8> prefill = "";
        if(state::st.runtime_state.mg_mode == runtime_state::HINT) {
            prefill = answer;
            prefill.shrink(answer.size() - 1);
        }
        auto ans = vnlib::keyboard_input_8(prefill);
        return ans.starts_with(answer);
    }

    //! \brief wrapper for say and wait_for_answer
    bool round(std::initializer_list<bn::string_view> conversation, std::initializer_list<bn::string_view> question, bn::string_view answer) {
        vnlib::say("customer", conversation);
        return wait_for_answer(question, answer);
    }

    //! \brief have the customer say two paragraphs, then wait_for_answer
    bool multiround(std::initializer_list<bn::string_view> c1, std::initializer_list<bn::string_view> c2, std::initializer_list<bn::string_view> question, bn::string_view answer) {
        vnlib::say("customer (1/2)", c1);
        vnlib::say("customer (2/2)", c2);
        return wait_for_answer(question, answer);
    }

    void game() {
        FREE
        BG_CALLS
        MC("time to make some", "money!!", "(sales calls)")

        bool successfully_answered = false;
        if(state::st.runtime_state.mg_mode == runtime_state::AUTOWIN) {
            EMPTY("a magical force", "calls the customer")
            successfully_answered = true;
        }
        else if (SUCCESSES == 0) { successfully_answered = round({"hello? Hi I would like", "you to make the button", "BLUE and the confirm", "text SMALLER, please"}, {"what color should the", "button be?"}, "BLUE"); }
        else if (SUCCESSES == 1) { successfully_answered = round({"yes, please make the font", "YELLOW and the zoom", "function SMALLER", "than before"}, {"what should the zoom", "function be?"}, "SMALLER"); }
        else if (SUCCESSES == 2) { successfully_answered = round({"good evening, please", "sell me FIFTY first-gen", "widgets and FOURTY", "second-gen widgets"}, {"how many second-gen?"}, "FOURTY"); }
        else if (SUCCESSES == 3) { successfully_answered = round({"yo, I really need", "you to fix the BUTTON!", "don't mess with the", "right PANEL!"}, {"what should be fixed?"}, "BUTTON"); }
        else if (SUCCESSES == 4) { successfully_answered = round({"hello? you've DELETED", "the data and RUINED", "the user interface"}, {"what happened to the", "data?"}, "DELETED"); }
        // three
        else if (SUCCESSES == 5) { successfully_answered = round({"uhm, now that you're HERE", "please fix the BUTTON, it", "is way too SMALL!"}, {"what is the button", "too much of?"}, "SMALL"); }
        else if (SUCCESSES == 6) { successfully_answered = round({"I want TEN red widgets", ", ELEVEN white ones", "and TWELVE blue ones"}, {"how many white ones?"}, "TWELVE"); }
        else if (SUCCESSES == 7) { successfully_answered = round({"say it ain't SO!", "just what I wanted", "to HEAR! a WidgetCorp", "WORKER!"}, {"say it ain't?"}, "SO"); }
        // four
        else if (SUCCESSES == 8) { successfully_answered = round({"I heard your SALES were", "up TWENTY percent. is", "that TRUE? sounds", "a bit FAKE to me"}, {"how many percent did", "they say sales are up?"}, "TWENTY"); }
        else if (SUCCESSES == 9) { successfully_answered = round({"oh, wonderful! why don't", "you FIX the MOBILE app?", "it doesn't OPEN on", "my phone. AAAA!"}, {"what should we do", "to the mobile app?"}, "FIX"); }
        else if (SUCCESSES == 10) { successfully_answered = round({"yes, sell me ONE hundred", "widgets! I am VERY serious.", "I have a lot of ", "MONEY in the BANK."}, {"where is the money?"}, "BANK"); }
        else if (SUCCESSES == 11) { successfully_answered = round({"this isn't playtime, kid", "I NEED TWENTY WIDGETS!", "right now! this", "very moment!"}, {"how many widgets?"}, "TWENTY"); }
        else if (SUCCESSES == 12) { successfully_answered = round({"yes, WidgetCorp? Hello!", "how is your DAY going?", "is it GOOD? I HOPE", "it is going WELL"}, {"they asked about our", "what?"}, "DAY"); }
        else if (SUCCESSES == 13) { successfully_answered = round({"you call yourself a", "SALES team? back in my DAY,", "we had to WALK to", "our customer's HOUSE"}, {"back in their what?"}, "DAY"); }
        else if (SUCCESSES == 14) { successfully_answered = round({"hello? wait this isn't", "the PIZZA store? aww", "come ON!, not AGAIN!", "how did THIS happen?"}, {"what store did they", "want to call?"}, "PIZZA"); }
        // four, two rounds
        else if (SUCCESSES == 15) { successfully_answered = multiround({"frankly, I find", "it a bit insulting", "that you haven't BUILT", "a menu BAR yet"}, {"don't you find that", "a bit WEIRD?", "like you are COMPANY", "right?"}, {"what menu item hasn't", "been built?"}, "BAR"); }
        else if (SUCCESSES == 16) { successfully_answered = multiround({"is this the WIDGET department?", "please, I am BEGGING you", "please sell me FOURTY", "widgets! you have"}, {"no idea how long", "I've waited for this", "CALL! I can hardly", "sit still!"}, {"which department did", "they want?"}, "WIDGET"); }
        else if (SUCCESSES == 17) { successfully_answered = multiround({"listen, if you FIX", "the font size, I'll buy", "TWO hundred widgets", "right now!"}, {"I'm serious! Do it", "NOW and I'll even", "send you a hand-written", "LETTER! cool, ya?"}, {"what will they", "send us?"}, "LETTER"); }
        else if (SUCCESSES == 18) { successfully_answered = multiround({"sales team? more like", "FAILS team! I mean,", "do you even work", "HARD? I've sold"}, {"thousands of APPS and", "look what it got me:", "a big HOUSE, a nice", "CAR, and three FISH!"}, {"what did they sell", "thousands of?"}, "APPS"); }
        else if (SUCCESSES == 19) { successfully_answered = multiround({"wait, so you aren't", "the CEO? who the", "**** am I talking", "with? give me"}, {"ONE good reason not", "to hang up the PHONE", "right now! ONE!"}, {"what aren't we?"}, "CEO"); }
        else if (SUCCESSES == 20) { successfully_answered = multiround({"oh, WidgetCorp? I", "LOVE your products.", "In fact, send me", "FIFTY more widgets!"}, {"hmm, wait, make that", "SIXTY widgets!", "yes, yes, yes...", "SIXTY MUHAHAHAHA"}, {"what was their", "revised widget number?"}, "SIXTY"); }
        // else if (SUCCESSES == ) { successfully_answered = round({""}, {"?"}, ""); }
        else {
            MC("guess they ran out", "of tasks...")
            successfully_answered = true;
        }

        if(successfully_answered) {
            SP_HEART_BASIC
            MC("nice!", "I got it right!")
            RIKA_INC_GOOD
            state::st.mg_state.on_success(minigame_state::CALLS);
            instant_message::thank_you(character::RIKA);
        } else {
            MC("drat!")
            state::st.mg_state.on_failure(minigame_state::CALLS);
        }

    }
}