#include "story.h"
#define PAPER(...) vnlib::say("paper", {__VA_ARGS__});
#define CODE_TOTAL state::st.mg_state.totals[minigame_state::CODE]
#define MARKETING_TOTAL state::st.mg_state.totals[minigame_state::PAPERWORK]

namespace story {
    //! \brief expected successful tasks completed per week (Fr,Mo,Tu,We,Th)
    constexpr bn::fixed TASKS_PER_WEEK = 3;

    namespace unlocks {
        //! \brief kanade first unlock
        void kanade_unlock_0() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            MC("OK work seems", "to be going well")
            SHOW_KANADE_NORMAL
            KANADE("hello there!", "have we met before?")
            MC("hello!", "No, I don't believe", "we have met")
            MC(MCF("I'm {}"), "what is your name?")
            /*! \kanade is in marketing */
            KANADE("I'm Kanade", "I work in the", "marketing department")
            MC("nice to meet you,", "Kanade!")
            MENU(
                CHOICE("for how long?", [](){
                    MC("How long have", "you worked here?")
                    KANADE("oh, hmm...")
                    KANADE("...")
                    /*! \kanade_maybe is in her second year of work */
                    KANADE("I'm just about to", "complete my second year")
                    MC("oh nice")
                }),
                CHOICE("do you enjoy it?", [](){
                    MC("Do you like working", "in marketing?")
                    KANADE("well, it's alright...")
                    /*! \kanade_maybe is thinking of changing careers */
                    KANADE("I have thought", "about switching", "careers, actually")
                    KANADE("but I don't really", "know what else I", "could do...")
                })
            )

            KANADE("oh, that reminds", "me!")
            KANADE("do you think", "you could help", "out our team?")
            KANADE("we need some help", "filling out some", "marketing paperwork.")
            KANADE("it really doesn't", "take very long.")
            KANADE("you should still", "have time for", "programming tasks")
            KANADE("what do you think?")
            MENU(
                CHOICE("I'll help", [](){
                    MC("well my current", "tasks aren't", "too difficult")
                    MC("I should be able", "to help out a", "bit")
                    KANADE("thank you,", MCF("{}!"))
                    KANADE("I'll get you", "permission to", "access the work")
                    KANADE("don't worry about", "the difficulty")
                    KANADE("we can give", "you something", "small")
                    KANADE("but if that gets", "too easy or boring...")
                    KANADE("there are always", "more difficult tasks!")
                    MC("alright, I'll", "take a look and", "see what I can do")
                    UNLOCKED_MARKETING = true; //! \story_unlocks marketing first unlock
                }),
                CHOICE("NO WAY!", [](){
                    MC("Sorry, Kanade")
                    MC("There is no way", "I'll be able to", "fit them in")
                    MC("Maybe I can try", "sometime next", "week?")
                    KANADE("sure, next week", "could work too...")
                    UNLOCKED_MARKETING = false;
                })
            )
            KANADE("well then...", "it was nice meeting you", MCF("{}!"))
            KANADE("I'll see you", "around!")
            MC("nice to meet you", "too!")
            SCENE_END
            if(UNLOCKED_MARKETING) {
                MC("(hmm)")
                MC("I should take", "a look at the", "marketing tasks")
            }
        }
        //! \brief kanade second unlock
        void kanade_unlock_1() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_KANADE_NORMAL
            KANADE(MCF("Hey, {}!"), "How is it going?")
            MC("oh hey Kanade, great", "to be back in the", "office")
            KANADE("say...", "about last week...")
            KANADE("have you had time", "to catch up on your", "programming tasks?")
            MENU(
                CHOICE("yes!", [](){
                    KANADE("oh wonderful!", "do you think you", "could add some", "marketing tasks?")
                    MENU(
                        CHOICE("absolutely!", [](){
                            MC("Sure, I can help!", "I think I have", "a better understanding", "of how thing work")
                            KANADE("yay! this is great!", "Thank you!")
                            UNLOCKED_MARKETING = true; //! \story_unlocks marketing second unlock
                        }),
                        CHOICE("uhm...", [](){
                            MC("Well, I am not", "really sure I", "would enjoy working", "on marketing paperwork")
                            MC("I'm sorry, I", "would really rather", "stick to programming", "")
                            KANADE("oh I think I", "understand...")
                            KANADE("well, at least I", "tried!")
                            UNLOCKED_MARKETING = false;
                        })
                    )
                }),
                CHOICE("sorry, no", [](){
                    MC("unfortunately, I haven't.", "I'd like to think", "that I'm making", "a difference but")
                    MC("I'm not so sure.", "the work keeps piling", "up!")
                    KANADE("ahh I'm sorry", "to hear that...")
                    KANADE("I'll leave you to","it, then!")
                    KANADE("(at least", "I tried!)")
                    UNLOCKED_MARKETING = false;
                })
            )
            SCENE_END
            MC("now then...", "where was I...")
        }
        //! \brief kanade third unlock
        void kanade_unlock_2() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            MC("ok finally some", "peace...")
            SHOW_KANADE_NORMAL
            KANADE(MCF("hey {}"), "uhm...", "there isn't an easy", "way to put this...")
            KANADE("and I know this is the", "third time that I've", "bothered you, but...")
            KANADE("OUR TEAM IS REALLY", "BEHIND. LIKE VERY", "VERY FAR BEHIND.")
            KANADE("I've gone to every", "other team and they're", "all busy too.")
            KANADE("at this point, I don't", "really know what to do.", "so...")
            KANADE("could you help?", "even something small?")
            MENU(
                CHOICE("sign me up!", [](){
                    KANADE(MCF("{}!"), "you're the best!")
                    KANADE("I'll get you access", "in just a bit!")
                    MC("ok, I'll", "take a look")
                    UNLOCKED_MARKETING = true; //! \story_unlocks marketing third unlock
                }),
                CHOICE("negative", [](){
                    MC("negative, Kanade", "I'm in the same position", "as everyone else")
                    KANADE("...fine")
                    SCENE_END
                    MC("(is this going to", "end well?)")
                    UNLOCKED_MARKETING = false;
                })
            )
            SCENE_END
        }
        //! \brief kanade force unlock
        void kanade_force_unlock() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_INO_NORMAL
            INO(MCF("{}, this"), "is urgent")
            INO("As you may know", "the marketing department", "is in a rought", "spot")
            INO("If it was up to me", "I would hire someone new", "to fill the gap")
            INO("well, to be honest", "that's what we were", "hoping you would", "do.")
            INO("and, well...", "I guess hope is the", "right word here...")
            INO(MCF("Listen, {}"), "we need you to pick", "up these tasks")
            INO("and if it isn't you", "then we will be forced", "to find someone else...")
            MENU(
                CHOICE("I can do it", [](){
                    MC("you're right, I", "need to step it up.")
                    MC("give me acess and", "I'll have something", "to show by next week")
                    INO("alright, we're counting", "on you!")
                    UNLOCKED_MARKETING = true; //! \story_unlocks final marketing unlock
                    SCENE_END
                }),
                CHOICE("nah", [](){
                    MC("nah, I don't think", "I want to do that")
                    INO("fine, do things", "your way. we don't", "need that attitude here")
                    INO("good luck at your", "next job.")
                    HIDE
                    MC("oops")
                    vnlib::end(vnlib::BAD_END);
                })
            )
        }
        //! \brief unlock events for kanade
        const vnlib::story_fx KANADE_UNLOCKS[] = {kanade_unlock_0, kanade_unlock_1, kanade_unlock_2, kanade_force_unlock};

        //! \brief rika first unlock
        void rika_unlock_0() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            RIKA("yo!")
            SHOW_RIKA_NORMAL
            MC("hello", "I don't think we've", "met yet. I'm", MCF("{}"))
            RIKA("nice to meet you!", "I'm Rika!")
            RIKA("this may be a bit", "abrupt... but...", "I really could use", "some help")
            //! \rika is in sales
            RIKA("well, the sales team", "could use some help")
            RIKA("As you may have heard,", "WidgetCorp is a a bit", "short on staff")
            RIKA("and the sales team", "is no exception")
            RIKA("so, want to help us", "out?")
            RIKA("you would need to", "make a few calls", "and remember customer", "requests.")
            RIKA("is that something", "you could help with?")
            MENU(
                CHOICE("sure", [](){
                    MC("sure, I can help out!")
                    RIKA("wonderful!")
                    RIKA("I'll send you", "some information to get", "started!")
                    MC("Awesome!")
                    UNLOCKED_SALES = true; //! \story_unlocks sales first unlock
                }),
                CHOICE("NO NO NO", [](){
                    MC("well, I am still", "learning how things", "work here.")
                    MC("maybe a week or so")
                    RIKA("fair enough", "I'll check in next week!")
                    UNLOCKED_SALES = false;
                })
            )
            SCENE_END
        }
        //! \brief rika second unlock
        void rika_unlock_1() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIKA_NORMAL
            RIKA(MCF("Hey, {}!"))
            MC("oh hey Rika")
            RIKA("Have you though about", "helping out sales yet?")
            MENU(
                CHOICE("I'll help!", [](){
                    MC("Sure! I was getting", "used to the flow", "of things")
                    MC("I think I can", "now comfortably take", "on some more work")
                    RIKA("wonderful! I'll get", "you access to our", "how-to guide.")
                    RIKA("after that, you should", "be all set to call", "a few customers and", "get requirements")
                    RIKA("don't worry if you", "fail a few times! Most", "of our customers are", "pretty understanding.")
                    MC("ok, I'll do my best!")
                    UNLOCKED_SALES = true; //! \story_unlocks sales second unlock
                }),
                CHOICE("Sorry, no", [](){
                    MC("Sorry Rika, I", "am quite busy with my", "current tasks")
                    RIKA("oh, ok...")
                    HIDE
                    MC("(I should seriously", "consider helping", "next time!)")
                    UNLOCKED_SALES = false;
                })
            )
            SCENE_END
        }
        //! \brief rika third unlock
        void rika_unlock_2() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIKA_NORMAL
            RIKA("hey, though I would", "try one last time")
            RIKA("talking with people", "all day, well, I've", "seen it all")
            RIKA("ya know, maybe people", "get a bit worried if", "things happen too", "quickly")
            RIKA("but it's always worth", "checking again!")
            RIKA("so, want to help", "us out?")
            MENU(
                CHOICE("I'm ready!", [](){
                    MC("sure, count me in!")
                    RIKA("alright!", "it won't take long", "for me to give you", "access")
                    RIKA("let me know if you", "have questions. I'm around", "most days!")
                    MC("sounds good!")
                    UNLOCKED_SALES = true; //! \story_unlocks sales third unlock
                }),
                CHOICE("not for me", [](){
                    MC("I still don't think", "now is a good time.")
                    MC("I am actually quite", "comfortable with the", "tasks I have now!")
                    RIKA("understandable!", "well...")
                    RIKA("it was worth a try...")
                    HIDE
                    MC("...", "Rika?")
                    UNLOCKED_SALES = false;
                })
            )
            SCENE_END
        }
        //! \brief rika force unlock
        void rika_force_unlock() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_INO_NORMAL
            INO(MCF("{}"), "lets talk for a bit")
            INO("Rika mentioned to", "me that their team", "is really behind", "on their backlog")
            INO("Now, I know you've", "been helping both", "on programming and", "marketing")
            INO("but if you can handle", "both of those, adding", "in a sales call", "shouldn't be hard")
            INO("so?")
            MENU(
                CHOICE("sure", [](){
                    MC("sure, sign me up.")
                    INO("ok, I'll give you access", "to sales")
                    UNLOCKED_SALES = true; //! \story_unlocks final sales unlock
                    SCENE_END
                }),
                CHOICE("ehh", [](){
                    MC("ehh i don't think", "so. I'm happy with", "the work I have now")
                    INO("wrong answer")
                    vnlib::end(vnlib::BAD_END);
                })
            )
        }
        //! \brief unlock events for rika
        const vnlib::story_fx RIKA_UNLOCKS[] = {rika_unlock_0, rika_unlock_1, rika_unlock_2, rika_force_unlock};

        //! \brief rin first unlock
        void rin_unlock_0() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIN_NORMAL
            RIN("hey, quick question")
            //! \rin likes to ask questions when she meets us
            RIN("whats the shortest path", "between two points?")
            MENU(
                CHOICE("hypotenuse", [](){
                    MC("it's the hypotenuse", "obviously!")
                    RIN("is that the only", "math word you know?")
                    //! \rin_maybe is bound to get fired for saying this. right?
                    RIN("*sigh*", "guess we hire", "anyone these days...")
                    HIDE
                    MC("uhm...")
                    UNLOCKED_SECURITY = false;
                }),
                CHOICE("segment", [](){
                    MC("if I recall correctly,", "that is called a segment")
                    RIN("ok now that I've", "verified that you", "are have a few", "braincells...")
                    RIN("how about taking on", "a new task.", "this isn't for the", "fainthearted, by the way")
                    MENU(
                        CHOICE("sign me up", [](){
                            MC("sign me up!")
                            RIN("yea... sure...", "we'll see if that", "attitude holds up", "for long")
                            HIDE
                            MC("hmm... a bit odd...")
                            UNLOCKED_SECURITY = true; //! \story_unlocks security first unlock
                        }),
                        CHOICE("you seem...", [](){
                            MC("sorry, you seem a", "bit... obtuse")
                            RIN("really?", "am I supposed", "to laugh?")
                            RIN("well HA HA.", "guess I'll do", "the work myself...")
                            UNLOCKED_SECURITY = false;
                        })
                    )
                }),
                CHOICE("shortcut", [](){
                    MC("I call those shortcuts!")
                    RIN("reasonable, but", "not good enough")
                    RIN("*sigh*", "more work for me...")
                    HIDE
                    MC("weird...")
                    UNLOCKED_SECURITY = false;
                })
            )
            SCENE_END
        }
        //! \brief rin second unlock
        void rin_unlock_1() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIN_NORMAL
            RIN("hey are you doing", "anything important?")
            MC("well... yea")
            RIN("ok, what email", "authentication method", "prevents forged sender", "addresses?")
            MENU(
                CHOICE("DKIM", [](){
                    MC("easy, its DKIM")
                    UNLOCKED_SECURITY = true;
                    RIN("he...", "not bad. I'll get", "you access to the", "security team's backlog")
                    RIN("I look forward to", "seeing your work...")
                    MC(MCF("I'm {}"))
                    RIN(MCF("{}..."), "right...")
                    RIN("well, get to it")
                    HIDE
                    MC("'get to it'?", "I already have", "so much to do...")
                }),
                CHOICE("DNS", [](){
                    MC("isn't it DNS?")
                    RIN("err! wrong!", "try again next week...")
                    UNLOCKED_SECURITY = false;
                }),
                CHOICE("SSH", [](){
                    MC("it has to be SSH", "right?")
                    RIN("err! wrong!", "try again next week...")
                    UNLOCKED_SECURITY = false;
                })
            )
            SCENE_END
        }
        //! \brief rin third unlock
        void rin_unlock_2() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIN_NORMAL
            RIN("here's a question:", "which ciphersuite", "offers the largest", "key length?")
            RIN("choices are:", "ECDHE-RSA-AES256-SHA384", "DHE-RSA-AES128-SHA256", "ECDHE-RSA-DES-CBC3-SHA")
            MENU(
                CHOICE("ECDHE-RSA-AES256-SHA384", [](){
                    MC("simple, its the first")
                    RIN("not bad...", "I'll get you access", "to our backlog")
                    RIN("give us some help", "when you're done with", "your programming tasks")
                    MC("sure...")
                    RIN("OR ELSE")
                    HIDE
                    MC("uhm...")
                    UNLOCKED_SECURITY = true;
                }),
                CHOICE("DHE-RSA-AES128-SHA256", [](){
                    MC("its the second one, right?")
                    RIN("wrong, again. *sigh*")
                    RIN("you get one more", "chance to prove yourself")
                    HIDE
                    MC("oh no...")
                    UNLOCKED_SECURITY = false;
                }),
                CHOICE("ECDHE-RSA-DES-CBC3-SHA", [](){
                    MC("isn't it the last one?")
                    RIN("wrong, again. *sigh*")
                    RIN("you get one more", "chance to prove yourself")
                    HIDE
                    MC("oh no...")
                    UNLOCKED_SECURITY = false;
                })
            )
            SCENE_END
        }
        //! \brief rin force unlock
        void rin_force_unlock() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_RIN_NORMAL
            RIN("listen...", "maybe I've been a", "bit tough on you")
            RIN("our team could really", "use the help and", "I'm sure we can find", "something that...")
            RIN("fits your abilities")
            RIN("are you interested?")
            MENU(
                CHOICE("sure", [](){
                    MC("sure, I'll try and", "help out")
                    RIN("alright, I'll get you", "access in a bit")
                    RIN("try not to let me", "down, you hear?")
                    MC("I got it!")
                    HIDE
                    UNLOCKED_SECURITY = true;
                }),
                CHOICE("no thanks", [](){
                    RIN("fine. but you may", "come to regret that")
                    RIN("some decisions are", "permanent")
                    MC("I think I'll be", "with the work from", "the other teams")
                    MC("after all, there is", "no shortage of tasks", "to do")
                    RIN("yea, sure.", "good luck with that")
                    HIDE
                    UNLOCKED_SECURITY = false;
                })
            )
            SCENE_END
        }
        //! \brief unused unlock for rin
        void rin_empty_unlock() {
            state::st.unlock_state.progression[character::RIN] -= 1;
        }
        //! \brief unlock events for rin
        const vnlib::story_fx RIN_UNLOCKS[] = {rin_unlock_0, rin_unlock_1, rin_unlock_2, rin_force_unlock, rin_empty_unlock};

        //! \brief cycle through unlocked departments (true = acted, false = nothing)
        bool unlock_next() {
            if(UNLOCKED_MARKETING
                && UNLOCKED_SALES
                && UNLOCKED_SECURITY) {
                return false;
            }
            // prioritize marketing > sales > security
            for(auto c : character::characters) {
                if(state::st.unlock_state.is_unlocked[c]
                    || state::st.unlock_state.last == c) {
                    continue;
                }
                bool acted = false;
                switch(c) {
                case character::KANADE:
                    KANADE_UNLOCKS[state::st.unlock_state.progression[c]]();
                    acted = true;
                    break;
                case character::RIKA:
                    RIKA_UNLOCKS[state::st.unlock_state.progression[c]]();
                    acted = true;
                    break;
                case character::RIN:
                    RIN_UNLOCKS[state::st.unlock_state.progression[c]]();
                    acted = true;
                    break;
                default:
                    continue;
                }
                if(acted) {
                    state::st.unlock_state.last = c;
                    state::st.unlock_state.progression[c] += 1;
                    return true;
                }
            }
            state::st.unlock_state.last = character::GENERIC;
            return false;
        }

#define PLAYTEST_UNLOCKS_CHOICE(ch, ch_enum, unlocks, num) CHOICE(#ch#num, [](){ unlocks [num](); })
#define PLAYTEST_UNLOCKS_CHOICES(ch, ch_enum, unlocks) PLAYTEST_UNLOCKS_CHOICE(ch, ch_enum, unlocks, 0),PLAYTEST_UNLOCKS_CHOICE(ch, ch_enum, unlocks, 1),PLAYTEST_UNLOCKS_CHOICE(ch, ch_enum, unlocks, 2),PLAYTEST_UNLOCKS_CHOICE(ch, ch_enum, unlocks, 3),
        void playtest() {
            BG_PLAIN
            auto options = vnlib::dense_MenuOptions();
            vnlib::menu({
                PLAYTEST_UNLOCKS_CHOICES(kanade, character::KANANDE, KANADE_UNLOCKS)
                PLAYTEST_UNLOCKS_CHOICES(rika, character::RIKA, RIKA_UNLOCKS)
                PLAYTEST_UNLOCKS_CHOICES(rin, character::RIN, RIN_UNLOCKS)
                CHOICE("back", [](){})
            }, &options);
        }
    }

    //! \brief holds various progress report events
    namespace progress_report {
        //! \brief early game reminder oh how progress should be treated
        void progress_report_0() {
            FREE
            BG_OFFICE_DESK
            if(CODE_TOTAL == 0) {
                MC("I should try completing", "a code task correctly")
                MC("Imagine I get fired", "my first month!", "gah!")
            } else if (UNLOCKED_MARKETING && MARKETING_TOTAL == 0) {
                MC("I said I would help", "marketing yet I've", "made no progress")
                MC("I really need to", "step it up!")
            } else {
                int total = CODE_TOTAL + MARKETING_TOTAL;
                MC("Nice! First week is", "almost over and I", FMT_24("already have {}", total), "tasks done!")
                if(total < TASKS_PER_WEEK) {
                    MC("maybe I should try", FMT_24("for {}", TASKS_PER_WEEK))
                }
            }
        }

        //! \brief the first report setting expectations
        void progress_report_1() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            SHOW_INO_NORMAL
            INO(MCF("hey {}"), "I wanted to set", "expectations so we're", "clear about your role")
            INO("I know you've just", "started so I'm sure", "you've taken your time", "to settle in")
            INO("next week, I expect you", "to work at full", "capacity!")
            INO(FMT_24("ther means {}", TASKS_PER_WEEK), "tasks per week!")
            MC("what happens if I", "I can't complete that", "many tasks?")
            INO("we... can talk", "about it when we get", "there")
            INO("but we're a busy", "group and we can't", "tolerate those that", "can't help out")
            MC("right, got it")
            INO("good luck!")
            HIDE
            MC("sheesh! I better not", "mess this up!")
        }

        //! \brief the subsequent report giving us warnings
        void progress_report_generic() {
            SCENE_END
            BG_OFFICE_DESK
            FADE_IN
            if(!state::st.runtime_state.require_weekly_progress) {
                EMPTY("(a mysterious force", "skips your weekly", "progress check)")
                SCENE_END
                return;
            }
            SHOW_INO_NORMAL
            if(state::st.mg_state.weekly_successes >= 3) {
                INO(MCF("hey {}"), "I saw you completed", FMT_24("{} tasks this week.", state::st.mg_state.weekly_successes), "nice work!")
                MC("thanks Ino!")
            } else {
                INO(MCF("uhm {}..."), "so we need to talk")
                MC("oh?")
                if(state::st.mg_state.weekly_successes == 0) {
                    INO("I thought we went", "over the expectations", "but maybe you need", "a reminder")
                    INO(FMT_24("I expect {} tasks per", TASKS_PER_WEEK), "week. no exceptions")
                    INO("can you handle it?")
                    MENU(
                        CHOICE("yes", [](){
                            MC("yes, it won't give", "me any issues")
                            INO("wonderful, I'll", "be keeping an eye", "out so don't hesitate", "to ask questions")
                            MC("will do!")
                        }),
                        CHOICE("uhm...", [](){
                            MC("uhm...", "is there any way to", "lower the requirement?")
                            INO("no. exceptions.", "we've kept the same", "expectation for all", "employees")
                            MC("alright, I understand")
                            INO("so you'll meet", "the requirements next", "week?")
                            MC("yes, I'll give it", "everything I've got!")
                            // TODO: reset minigame difficulty
                        })
                    )
                } else if(state::st.mg_state.weekly_successes == 1) {
                    INO("I did see you", "got one task done", "this week. Is everything", "ok?")
                    MENU(
                        CHOICE("fine", [](){
                            MC("yes, everything is", "fine. It's probably", "just a lack of sleep")
                            INO("alright... well I'll", "be keeping an eye", "out. Let me know", "if you have questions")
                            INO("good luck")
                            MC("thanks!", "I'll do my best!")
                        }),
                        CHOICE("not fine", [](){
                            MC("uhm...")
                            // TODO: reset minigame difficulty
                        })
                    )
                } else if (state::st.mg_state.weekly_successes == 2) {
                    INO("I did see that you", "completed two tasks")
                    INO("that's... better", "than nothing but it's", "still below expectations")
                    INO("you think you can", "handle it next week?")
                    MENU(
                        CHOICE("fine", [](){

                        }),
                        CHOICE("not fine", [](){
                            // TODO: reset minigame difficulty
                        })
                    )
                }
                SCENE_END
                EMPTY("(progress warning 1/3)")
            }
        }
    }

    //! \brief holds various episode events
    namespace episodes {
        //! \brief a snake is in the break room
        void episode_snake() {
            FREE
            BG_OFFICE_DESK
            MC("honestly, I am", "surprised things", "aren't so bad")
            MC("don't people complain", "more about their jobs?")
            SHOW_INO_SCARED
            INO(MCF("{}!"), "TO THE BREAK ROOM!", "COME QUICK!")
            MC("!!!")
            MC("HOLY HECK!")
            MC("IS THAT A SNAKE?")
            /*! \ino is afraid of snakes */
            INO("WHAT SHOULD WE DO?")
            MENU(
                CHOICE("I'LL FIGHT IT!", [](){
                    MC("I've trained for this!", "Let me fight it!")
                }),
                CHOICE("leave it be", [](){
                    MC("maybe we should just", "leave it be.", "it doesn't look like", "it is hurting anyone")
                }),
                CHOICE("its a rat snake!", [](){
                    MC("first, let's calm down!", "This is a rat snake.")
                    INO("THERE ARE", "RATS TOO??")
                    MC("no...","well...","maybe...")
                    MC("ANYWAY")
                    MC("I think I can handle", "it. I have watched", "enough OooTube to", "be safe.")
                })
            )
            INO("OK I AM WAITING", "OUTSIDE")
            HIDE
            MC("alright, you", "stay safe over", "there. I'll.. uhm...")
            SHOW_KANADE_ANGRY
            KANADE("What on earth", "is going on over here?")
            /*! \kanade is not afraid of snakes */
            KANADE("oh a rat snake!", "My brother has", "one just like it!")
            KANADE("Poor fella!", "There aren't any", "rats in this office!")
            KANADE("let me call animal", "control. they'll be able", "to safely move and house", "it!")
            KANADE("I'll take it from", "here. You two can head", "back to work!")
        }

        //! \brief kanade bakes some muffins
        void episode_muffins() {
            FREE
            BG_OFFICE_DESK
            MC("hmm...", "what is that smell?")
            MC("...")
            MC("maybe bread?", "or cake?", "muffins?")
            //! \kanade likes baking things (like muffins)
            SHOW_KANADE_HAPPY
            KANADE(MCF("hey {}!"), "look what I brought!", "MUFFINS!")
            MC("ooo!", "wonderful!")
            SHOW_INO_HAPPY
            INO("I put mine in the", "microwave for a bit.", "pretty good!")
            INO("nothing beats a warm", "breakfast")
            SHOW_KANADE_HAPPY
            KANADE("ha ha ha", "not bad, if I do", "say so myself")
            SHOW_KANADE_NORMAL
            KANADE("here, try one!")
            MC("sure!")
            MC("*you take a bite*")
            MC("(well, it is", "delicous. I think it", "is blueberry flavored)")
            MENU(
                CHOICE("delicous!", [](){
                    MC("wow, this is amazing!")
                    KANADE(MCF("thank you, {}!"), "they didn't take", "too long to make")
                    MC("they didn't take too", "long to eat either!")
                    KANADE("haha")
                }),
                CHOICE("one more?", [](){
                    MC("do you have any", "more of them?")
                    KANADE("sorry, I don't think", "enough of them")
                    KANADE("but maybe I can bring", "more again soon")
                    MC("yes please!")
                    INO("yes please!")
                }),
                CHOICE("not for me", [](){
                    MC("well it's not bad!", "but I don't think", "this flavor is for me")
                    KANADE("aww. bummer...")
                    KANADE("was it the flavor?", "maybe something other", "than blueberry?")
                    MENU(
                        CHOICE("pineapple", [](){
                            MC("have you ever made", "pineapple bread?")
                            KANADE("pineapple... bread?", "can't say I've thought", "of that...")
                            
                        }),
                        CHOICE("rasin", [](){
                            MC("I like rasins in my", "muffins")
                            KANADE("hmm.", "well to each their", "own!")
                        }),
                        CHOICE("cookies", [](){
                            MC("I dislike all muffics", "equally")
                            MC("Cookies are the superior", "snack option!")
                            KANADE("oh I can make", "those too!")
                        })
                    )
                })
            )
            KANADE("well thank you again", "for trying them.", "This week is a bit", "busy but maybe I can")
            KANADE("make something new next", "week!")
            MC("nice!")
        }
    }

    /*!
     * \brief the first day in the office
     *
     * we are introduced to Ino and learn she wants to get things done
    */
    void office_w1_d1() {
        SCENE_END
        BG_OFFICE_DESK
        FADE_IN
        MC("...")
        MC("was I just sleeping?")
        MC("...")
        MC("where am I?", "...", "am I at work?")
        MC("let's see, here are", "some papers...")
        PAPER("WidgetCorp class of '24", "\"Welcome New Hires!\"", "This is your onboarding", "packet!")
        PAPER("Enclosed, you'll find", "a description of your", "team and a few links", "to important documents")
        PAPER("Don't be a stranger!", "Get to know your", "co-workers!")
        PAPER("We are a small company", "so you may need to", "work in roles outside", "your hired specialty")
        PAPER("There is plenty to do!", "Best of luck and", "have fun!", "- Boss")
        MC("wonderful. haha...", "\"have fun\"...", "is that some sort", "of joke?")
        SHOW_INO_NORMAL
        INO(MCF("hey, {}!"), "...", "wait...")
        INO("you don't look so well", "...", "were you just sleeping?")
        MENU(
            CHOICE("sorry, yes", [](){
                MC("sorry! I guess I", "didn't get enough", "sleep last night")
                INO("well, maybe try again", "tonight!")
            }),
            CHOICE("definitely not!", [](){
                MC("I was definitely not", "sleeping!")
                MC("however, I am feeling", "a bit sick. Maybe", "I had something bad", "for lunch...")
                INO("I'd say 10AM is", "a bit early for lunch...")
                INO("but who I am I", "to judge...")
                INO("anyway, try to get", "some good rest tonight")
            })
        )
        INO("hopefully you'll", "feel better tomorrow!")
        MC("sure.", "so...", "uhm...", "who... are you?")
        INO(MCF("gosh, {}!"), "that nap really did", "a number on you...")
        /*! \ino is our manager */
        INO("I'm Ino, your manager")
        INO("Hopefully you were", "paying attention during", "the onboarding last", "week...")
        INO("But if you weren't,", "this is a friendly", "reminder that you are", "on the programming team")
        INO("~our~", "programming team!")
        INO("Now, have you taken", "a look at our backlog", "yet?")
        MC("hmm...", "our backlog...")
        MC("Sorry, I haven't seen", "that yet")
        INO("The link to it", "should already be", "on your desktop.")
        INO("Open it and see", "if you can find", "something small.")
        INO("I'll message you later", "and see how you", "are doing")
        MC("I'll do that!")
        INO("Good luck!")
        SCENE_END
        MC("*phew*")
        MC("guess I should ", "take a look around...");
    }

    /*! \brief second day in the office: ino checks in to see how we are feeling
     *
     * she also covers:
     * 1. that tasks get more difficult
     * 2. that characters aren't always available every day
    */
    void office_w1_d2() {
        SCENE_END
        BG_OFFICE_DESK
        FADE_IN
        MC("alright", "the second day!")
        MC("well, technically", "I've already had", "on-boarding")
        MC("so maybe this", "is my second", "week?")
        MC("it all feels", "so hazy")
        SHOW_INO_NORMAL
        INO("good morning,", MCF("{}!"))
        INO("are you feeling", "better?")
        MENU(
            CHOICE("still hazy", [](){
                MC("I am still", "a bit hazy")
                MC("bu-","but that shouldn't", "impact my work")
                MC("I promise!")
                INO("promise accepted!")
            }),
            CHOICE("great!", [](){
                MC("actually a full", "night of rest", "really helped")
                INO("well, that's good", "to hear.", "keep it up!")
            })
        )
        INO("oh by the way...")
        INO("WidgetCorp is a bit", "low on funding...")
        INO("Obviously, we have", "enough to make payroll")
        INO("But you may be", "asked to help out", "in addtional roles")
        /*! \ino is reassuring */
        INO("It is ok to", "take on some extra", "work outside of", "programming")
        INO("Just don't let our", "backlog get out of", "control!")
        MC("okay, I understand!")
        MC("oh...")
        MC("I do have one", "question")
        MC("do you know when", "I can work on", "more difficult items?")
        INO("I will assign", "you work based", "on performance")
        INO("Complete the tasks", "as their given.")
        INO("if you complete the", "task correctly then I'll", "assign you something", "more difficult!")
        INO("oh, one more thing")
        INO("I am usually available", "in the afternoon for", "a quick chat")
        INO("Though Monday and ", "Thursday are the", "best days to talk")
        MC("sounds good, I'll", "keep that in mind")
        INO("ok, talk to you", "later!")
        MC("see ya!")
        SCENE_END
        MC("so Ino won't be", "around later. maybe", "I can head home", "early...")
    }

#define WEEK_DAY(w, d, fx) else if(state::st.day == (7*(w-1) + (d-1))){ fx(); }
    bool maybe_handle_story() {
        if(false){}
        WEEK_DAY(1,1, office_w1_d1)
        WEEK_DAY(1,2, office_w1_d2)
        else if ((state::st.day % 7) == 0 || (state::st.day % 7) == 3) {
            unlocks::unlock_next();
        }
        WEEK_DAY(1,5, story::progress_report::progress_report_0)
        WEEK_DAY(2,5, story::progress_report::progress_report_1)
        WEEK_DAY(3,2, episodes::episode_snake)
        else if ((state::st.day % 7) == 4) {
            story::progress_report::progress_report_generic();
        }
        WEEK_DAY(4,2, episodes::episode_muffins)
        return false;
    }

    //! \brief internal
    bool playtest_loop;
    //! \brief internal
    vnlib::MenuOptions playtest_menu_options = vnlib::default_MenuOptions();
    void playtest() {
        playtest_loop = true;
        playtest_menu_options.store_selection_as_default = true;
        playtest_menu_options.use_bg = false;
        while(playtest_loop) {
            vnlib::menu({
                CHOICE(FMT_24("{} {}", state::st.day, state::st.day_name()), [](){}),
                CHOICE("month +1", [](){ state::st.day += 7*4; }),
                CHOICE("month -1", [](){ state::st.day -= 7*4; }),
                CHOICE("week +1", [](){ state::st.day += 7; }),
                CHOICE("week -1", [](){ state::st.day -= 7; }),
                CHOICE("day +1", [](){ state::st.day += 1; }),
                CHOICE("day -1", [](){ state::st.day -= 1; }),
                CHOICE("run", [](){
                    maybe_handle_story();
                    playtest_loop = false;
                }),
                CHOICE("back", [](){
                    playtest_loop = false;
                })
            }, &playtest_menu_options);
        }
    }
}