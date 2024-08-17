#include "minigame_paperwork.h"
#define MG_PAPERWORK_SUCCESS(choice) CHOICE(choice, [](){ successfully_answered = true; })
#define MG_PAPERWORK_FAILURE(choice) CHOICE(choice, [](){ successfully_answered = false; })
#define KANADE_INC_GOOD state::st.rel_state.modify_relation(character::KANADE, relationship_state::GOOD);
#define SUCCESSES state::st.mg_state.successes[minigame_state::PAPERWORK]

namespace minigame_paperwork {
    //! \brief internal global to support reference from lambdas
    bool successfully_answered = false;

    //! \brief one round supporting one correct answer and two false answers
    void round(std::initializer_list<bn::string_view> question, bn::string_view correct_answer, bn::string_view ans_two, bn::string_view ans_three) {
        vnlib::SayOptions options;
        options.enable_fastforward = false;
        options.disable_blocking = true;
        vnlib::say("Fill the blank", question, options);
        auto correct_w_hint = FMT_24("{}{}", correct_answer, state::st.runtime_state.mg_mode == runtime_state::HINT ? " <<" : "");
        OPTION_MENU(
            MG_PAPERWORK_FAILURE(ans_two),
            MG_PAPERWORK_SUCCESS(correct_w_hint),
            MG_PAPERWORK_FAILURE(ans_three)
        )
    }

    void game() {
        FREE
        BG_PAPERWORK
        MC("marketing needs", "me to fill in", "some documents")

        if(state::st.runtime_state.mg_mode == runtime_state::AUTOWIN) {
            EMPTY("a magical force", "completes the paperwork")
            successfully_answered = true;
        }
        else if (SUCCESSES == 0) { round({"We had __ sales!"}, "twenty", "gold", "absymal"); }
        else if (SUCCESSES == 1) { round({"The best __ widget!"}, "blue", "move", "toot"); }
        else if (SUCCESSES == 2) { round({"__, like none other"}, "WidgetCorp", "BrokenHat", "OldHotdog"); }
        else if (SUCCESSES == 3) { round({"Always __, Never small"}, "big", "park", "leave"); }
        else if (SUCCESSES == 4) { round({"We had record __ last", "month. This is up", "__ percent since", "last year!"}, "sales / twenty", "code / orange", "birds / thirty"); }
        else if (SUCCESSES == 5) { round({"Several features are new:", "* __ button", "* big text", "* a __ hyperlink color"}, "blue / new", "woo / rue", "shoe / doodoo"); }
        else if (SUCCESSES == 6) { round({"Ino's team is shipping", "at an __ rate!"}, "astonishing", "gregarious", "highfalutin"); }
        else if (SUCCESSES == 7) { round({"WidgetCorp hit record", "sales, with __ new", "customers. __ of which", "are in Westalis!"}, "twenty / ten", "ten / twenty", "three / five"); }
        else if (SUCCESSES == 8) { round({"Our sales team is", "ready to __ to your", "feedback! We love", "__ customers."}, "listen / our", "regurgitate / every", "cry / blue"); }
        else if (SUCCESSES == 9) { round({"Regret your widget?", "Call within __ days and", "receive a voucher for", "a free __ ."}, "twenty / refund", "zero / pen", "one million / game bub advance"); }
        else if (SUCCESSES == 10) { round({"We've seen it all!", "No bug gets past the", "__ team. We're watching", ", we're __ ."}, "security / squashing", "parking / parking", "sailing / swimming"); }
        else if (SUCCESSES == 11) { round({"Their backlog: __", "Our backlog: __"}, "could hardly start / work of art", "paper / digital", "something else / something worse"); }
        else if (SUCCESSES == 12) { round({"Come see us at", "WidgetShow '24! We've", "got __ and __!"}, "widgets / smiles", "money / power", "egg / salad"); }
        else if (SUCCESSES == 13) { round({"We've heard your", "feedback: the button", "is now __ and the", "text is __"}, "blue / bigger", "smaller / illegible", "salad / egg"); }
        else if (SUCCESSES == 14) { round({"Got time? We'd love to", "hear your __! Let us", "know in the __ below"}, "feedback / box", "rude remarks / ocean", "life story / frying pan"); }
        else if (SUCCESSES == 15) { round({"From our __ to", "yours! It isn't farm-", "to-table but the features", "are still __!"}, "family / fresh", "hands / in the backlog", "pockets / expensive"); }
        else if (SUCCESSES == 16) { round({"Is the grass greener?", "Find out in version", "__! This is our", "best __ yet!"}, "2.0 / widget", "v1.2.3 / muffin", "zero / backlog"); }
        else if (SUCCESSES == 17) { round({"Many, many mornings:", "we've been __ and", "we're ready to __", "our new product..."}, "cookin' / reveal", "shakin' / destroy", "puffin' / exalt"); }
        else if (SUCCESSES == 18) { round({"Don't leave us!", "We will __ any price", "and __ any issues"}, "match / fix", "raise / cause", "lower / ignore"); }
        else if (SUCCESSES == 19) { round({"You rock! Our", "__ is helping you", "rock the __ world"}, "jam / widget", "sock / shoe", "basalt / quarry"); }
        else if (SUCCESSES == 20) { round({"When could be better", "than __? First class", "__ service!", "We won't let you down!"}, "gold / customer", "egg / salad", "heaven / fan"); }
        // else if (SUCCESSES == ) { round({}, "", "", ""); }
        else {
            MC("hmm... guess they ran", "out of work...")
            successfully_answered = true;
        }

        if(successfully_answered) {
            SP_HEART_BASIC
            MC("woo!, I did it!")
            KANADE_INC_GOOD
            state::st.mg_state.on_success(minigame_state::PAPERWORK);
            instant_message::thank_you(character::KANADE);
        } else {
            MC("darn. that doesn't", "look right...")
            state::st.mg_state.on_failure(minigame_state::PAPERWORK);
        }
    }
}