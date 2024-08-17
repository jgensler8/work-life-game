#include "weekend_event.h"
#define CELL_PHONE_BUZZ vnlib::say("cell phone", {"*buzz buzz*"});
#define GENERIC_TEXT_MESSAGE(...) vnlib::say("*spam*", {__VA_ARGS__});
#define INO_TEXT(...) vnlib::say("Ino (txt)", {__VA_ARGS__});
#define KANADE_TEXT(...) vnlib::say("Kanade (txt)", {__VA_ARGS__});
#define RIKA_TEXT(...) vnlib::say("Rika (txt)", {__VA_ARGS__});
#define RIN_TEXT(...) vnlib::say("Rin (txt)", {__VA_ARGS__});
#define RUDOLPH(...) vnlib::say("Rudolph", {__VA_ARGS__});
#define RADIO(...) vnlib::say("*radio*", {__VA_ARGS__});
#define WAREHOUSE_SUPERVISOR(...) vnlib::say("Supervisor", {__VA_ARGS__});
#define WAREHOUSE_TEAM_LEAD(...) vnlib::say("Team Lead", {__VA_ARGS__});
#define WAREHOUSE_INSTRUCTIONS(...) vnlib::say("*paper*", {__VA_ARGS__}, no_block_options);
#define INOS_FATHER(...) vnlib::say("Ino's Father", {__VA_ARGS__});
#define INOS_MOTHER(...) vnlib::say("Ino's Mother", {__VA_ARGS__});
#define KANADES_BROTHER(...) vnlib::say("Brother", {__VA_ARGS__});
#define KANADES_FATHER(...) vnlib::say("K-Papa", {__VA_ARGS__});
#define KANADES_MOTHER(...) vnlib::say("K-Mama", {__VA_ARGS__});
#define COOKING_INSTRUCTIONS(...) vnlib::say("*cooking*", {__VA_ARGS__}, no_block_options);
#define GARDENING_INSTRUCTIONS(...) vnlib::say("*gardening*", {__VA_ARGS__}, no_block_options);
#define TEAM_CAPTAIN(...) vnlib::say("captain", {__VA_ARGS__});
#define ORGANIZER(...) vnlib::say("organizer", {__VA_ARGS__});
#define RIKAS_FRIEND_1(...) vnlib::say("Friend 1", {__VA_ARGS__});
#define RIKAS_FRIEND_2(...) vnlib::say("Friend 2", {__VA_ARGS__});
#define RIKAS_SISTER(...) vnlib::say("Selene", {__VA_ARGS__});
#define STORE_WORKER(...) vnlib::say("Store Worker", {__VA_ARGS__});
#define DOG(...) vnlib::say("Dog", {__VA_ARGS__});
#define DOG_OWNER(...) vnlib::say("Dog Owner", {__VA_ARGS__});
#define STELLA(...) vnlib::say("Stella", {__VA_ARGS__});
#define IRENE(...) vnlib::say("Irene", {__VA_ARGS__});
#define GAME(...) vnlib::say("", {__VA_ARGS__}, no_block_options);
#define STORY_PROGRESS state::st.wke_state.story_progress
#define HANDLE_EMERGENCY if(handle_emergency(saturday_emergency_excuse)){ return; }
#define EMERGENCY_PROGRESS state::st.wke_state.emergency_progress
#define HOBBY_MUSIC_TALENT state::st.mc_state.mc_music_talent
#define HOBBY_MUSIC_PREFERENCE state::st.mc_state.mc_music_preference
#define CAFE_ITEM_PREFERENCE state::st.mc_state.mc_cafe_item_preference
#define CONVENIENCE_DRINK state::st.mc_state.ino_convenience_drink
#define PIZZA_PLACE_FOOD state::st.mc_state.ino_pizza_place_food
#define PIZZA_PLACE_DRINK state::st.mc_state.ino_pizza_place_drink
#define BOOK_SALE_BOOK  state::st.mc_state.kanade_book_sale_book
#define KANADE_POST_BOOK_PLACE  state::st.mc_state.kanade_post_book_place
#define GRILL_ITEM state::st.mc_state.ino_grill_item
#define INO_FAMILY_BEER state::st.mc_state.ino_family_beer
#define KANADE_WEEKEND_ACTIVITY state::st.mc_state.kanade_weekend_activity
#define KANADE_INGREDIENT_1 state::st.mc_state.kanade_ingredient_1
#define KANADE_INGREDIENT_2 state::st.mc_state.kanade_ingredient_2
#define KANADE_SICK_ITEM state::st.mc_state.kanade_sick_item
#define MC_VOLUNTEERING_STATE state::st.mc_state.mc_volunteering_state
#define RIN_TRIANGLE_CHIP state::st.mc_state.rin_triangle_chip
#define RIN_ALCOHOL_PREP state::st.mc_state.rin_alcohol_prep
#define RIN_MAYBE_EAT_CHIPS state::st.mc_state.rin_maybe_eat_chips
#define RIN_PIZZA state::st.mc_state.rin_pizza
#define RIN_ALCOHOL_PREP_2 state::st.mc_state.rin_alcohol_prep_2
#define KANADE_INGREDIENT_3 state::st.mc_state.kanade_ingredient_3
#define KANADE_INGREDIENT_4 state::st.mc_state.kanade_ingredient_4
#define RIKA_BASKETBALL_TEAM state::st.mc_state.rika_basketball_team
#define KANADE_POST_BOOK_PLACE_ITEM state::st.mc_state.kanade_post_book_place_item
#define RIN_GAME_SELECTION state::st.mc_state.rin_game_selection
#define RIKA_SISTER_QUESTION state::st.mc_state.rika_sister_question

namespace weekend_event {
    //! \brief point increase needed between weekend events
    constexpr int WEEKEND_REL_PROGRESS_MULTIPLIER = 9;
    //! \brief point increase needed between weekend events
    constexpr int EMERGENCY_REL_PROGRESS_MULTIPLIER = 6;
    //! \brief array bounds for various weekend event arrays
    constexpr int MAX_STORY_COUNT = 4;
    //! \brief array bounds for various weekend emergency arrays
    constexpr int MAX_EMERGENCY_COUNT = 4;
    //! \brief set when a weekend event starts
    character::CHAR_ENUM original_story;
    //! \brief set when a weekend event starts and overridden when emergency starts
    character::CHAR_ENUM current_story;
    //! \brief global state recording if an emergency was helped or not
    bool helped = false;
    //! \brief function to create non-blocking, skippable options
    vnlib::SayOptions diable_block_options() {
        vnlib::SayOptions options;
        options.enable_fastforward = true;
        options.disable_blocking = true;
        return options;
    }
    //! \brief global options to avoid blocking. used for various game prompts
    const vnlib::SayOptions no_block_options = diable_block_options();

    //! \brief pass control to the main character to decide how to handle the emergency (yes/no)
    void emergency_response() {
        MENU(
            CHOICE("do not help", [](){helped = false;}),
            CHOICE("help", [](){helped = true;})
        )
    }

    /*
     * Ino Emergency
     */
    //! \brief ino needs help with microwave
    void ino_emergency_prompt_0() {
        INO_TEXT("hey, it's Ino. I am", "having some trouble with", "my microwave.")
        INO_TEXT("you wouldn't happen to", "have some time to help?")
    }
    //! \brief her microwave is fine (either park or room conversation)
    void ino_emergency_0() {
        SCENE_END
        MC("Ino, could you send", "over your address?")
        INO_TEXT("oh... right!", "The address is 123", "West Palm Ave")
        MC("alright, be there", "in a bit!")
        EMPTY("(you make your way", "over to Ino's place)")
        SCENE_END
        BG_INO_ROOM
        FADE_IN
        SHOW_INO_NORMAL
        INO("hey, welcome over!")
        MC("hey there!")
        MENU(
            CHOICE("where is the microwave", [](){
                MC("so where is the", "microwave in", "question?")
                INO("oh actually I was", "able to get it working", "again...")
            }),
            CHOICE("i know nothing", [](){
                MC("actually, I don't know", "anything about repairing", "")
                INO("that's alright, I", "was able to get it", "working again!")
            })
        )
        INO("well, sort-of...", "It is working but I", "really just plugged it", "in again")
        INO("not much of a fix", "but it works for now!")
        MC("is that... safe?")
        INO("yea, it's safe enough!")
        MENU(
            CHOICE("I'll head back", [](){
                MC("fair enough!", "well, I guess I'll", "head back")
                INO("woah woah! you've", "only just got here.")
                INO("maybe we can take", "a walk in the park?")
                MENU(
                    CHOICE("works for me", [](){
                        MC("sure, lets head out")
                        SCENE_END
                        BG_PARK
                        FADE_IN
                        SHOW_INO_NORMAL
                        INO("ahh nice!", "I love this place.", "the open space makes", "it easy to think")
                        MC("you think so?")
                        INO("sure. do you not", "get out much?")
                        MENU(
                            CHOICE("not really", [](){
                                MC("not really, I hardly ever", "leave my apartment.")
                                MC("the fresh air is nice", "and all...")
                                MC("but, I can just open", "a window")
                                INO("haha taking a walk", "is much better!")
                                INO("it's even better when you", "bring other people!")
                                MC("hmm...")
                            }),
                            CHOICE("yes", [](){
                                MC("I do. I usually go", "to a park close to", "my house on the", "weekends")
                                MC("sometimes I read a", "book or listen to music.")
                                MC("it is nice to be", "outside. well,", "on the good days!")
                                INO("haha agreed!", "today's a pretty nice", "day isn't it?")
                                MC("it is!")
                            })
                        )
                        INO("so I don't think I", "know much about how", "you ended up at", "WidgetCorp...")
                        INO("was there one thing", "that stood out to you?")
                        MENU(
                            CHOICE("the tech", [](){
                                MC("I am a here for", "the tech! I did", "some research on", "a few companies")
                                MC("that used the same", "langugaes as my", "homework assignments")
                                MC("I was thinking that", "I would be the most", "prepared and ready", "to make a mark")
                                MC("if I found a place", "that overlapped with", "what I already know")
                                INO("that does make", "sense. although...")
                                INO("I think there is always", "so much that is unknown.")
                                INO("soon, the languages will", "become the easy part!")
                                INO("As long as you're", "comfortable adapting to", "change, then you'll fit", "in anywhere")
                                MC("hmm I suppose you're", "right...")
                            }),
                            CHOICE("the people", [](){
                                MC("well I took my time", "looking for the right", "people")
                                MC("I had worked on a", "few group projects in", "university and I", "always had problems")
                                MC("when the group didn't", "work well together.", "it felt that", "everything was")
                                MC("a hundred time harder!", "so I figured", "I should focus on", "finding the best people!")
                                INO("I hear you on that.", "I think WidgetCorp is", "a bit small so", "I am surprised")
                                INO("you even found any", "information on us", "at all!")
                                MC("well, that part wasn't", "easy. I needed to call", "a few people to get", "the inside information")
                                INO("wow, that is impressive!")
                            })
                        )
                        MC("so...")
                        MENU(
                            CHOICE("promotion?", [](){
                                MC("do you think you'll", "ever get promoted?")
                                MC("like become the", "CEO one day?")
                                INO("HAHAHA", "oh...")
                                INO("well, I guess", "it is possible.", "certainly isn't", "something I've considered")
                                INO("I mean, if I had", "to think...")
                                INO("...")
                                INO("well, I guess I would", "do it!", "I mean, I am", "capable of leading")
                                INO("but I am not sure", "I would want so", "much stress")
                                INO("keeping so many people", "employed and happy...")
                                INO("I don't think I could", "easily focus on so many", "things.")
                                INO("but maybe it isn't", "so different from", "what I do now")
                                MC("I mean, I don't know", "anything about being a", "CEO so you're guess", "is as good as mine")
                                INO("haha, the grass isn't", "always greener, eh?")
                                MC("grass...", "yea...")
                            }),
                            CHOICE("thought of quitting?", [](){
                                MC("have you ever thought", "of quitting WidgetCorp?")
                                INO("hmm, that is an", "interesting question...")
                                //! \ino_maybe is tough (quitting is easy)
                                INO("I don't think quitting", "is the correct word.", "everyone gets", "frustrated at work")
                                INO("quitting always seemed", "like the 'easy'", "route in my mind")
                                INO("I would like to think", "that I'm a bit tougher", "than that!")
                                INO("well then...")
                            })
                        )
                        EMPTY("(you walk around the park", "for a bit longer)")
                        MC("*phew*")
                        INO("that was a good walk.", "I'm going to head back", "home")
                        INO("thanks for coming with,", MCF("{}!"))
                        INO("and sorry about the whole", "microwave thing. I guess", "I should have been", "more patient")
                        MC("oh it's no problem.", "I had a fun time!")
                        MC("I'll see you at work!")
                        SCENE_END
                        MC("(that went well!)")
                    }),
                    CHOICE("I really have to go", [](){
                        MC("actually, I've really", "got to leave")
                        INO("hmm...", "alright then", "see you at work")
                        SCENE_END
                        MC("(that could have", "gone better...)")
                    })
                )
            }),
            CHOICE("what are those?", [](){
                MC("are those guitars?")
                INO("oh yea!", "yup, I've had them", "forever!")
                INO("let see...", "at least middle school.", "my dad also played")
                INO("so it didn't take", "long for me to want", "to try")
                INO("it did take some time", "but I've learned", "enough to create my", "own stuff")
                INO("I guess you could", "call me a an artist", "though it does sound", "presumptuous")
                MC("it isn't really", "presumptuous. everyone", "has to start", "somewhere!")
                MENU(
                    CHOICE("how many songs?", [](){
                        MC("how many song have", "you written?")
                        INO("maybe a dozen", "or so. I do have", "hundreds of half", "baked ideas!")
                        MC("haha I have those", "too!")
                    }),
                    CHOICE("could you play a song?", [](){
                        MC("could you play a", "song now?")
                        INO("well... I am usually", "pretty open about things", "but this is the one")
                        INO("thing I keep to myself", "so not today...", "but maybe another time!")
                    })
                )
                INO("Do you also make", "music?")
                MENU(
                    CHOICE("not really", [](){
                        MC("no, nothing special", "here. I just listen")
                        INO("which genre do you", "listen to the most?")
                        HOBBY_MUSIC_TALENT = main_character_state::does_not_make_music;
                    }),
                    CHOICE("I sing", [](){
                        MC("I do sing a bit", "though mostly for", "fun.")
                        MC("can't say I've", "ever considered a band")
                        INO("a band can be", "just two people!", "every heard of singer", "/songwriter?")
                        INO("they are popular at", "open mic nights")
                        MC("open mic nights?")
                        INO("yea a cozy community", "event where people", "can play their songs")
                        INO("its a pretty good place", "for practicing and", "having fun!")
                        INO("which genre do you", "sing?")
                        HOBBY_MUSIC_TALENT = main_character_state::sings;
                    }),
                    CHOICE("part of a band", [](){
                        MC("I am part of a band!")
                        INO("no way!", "which intstrument?")
                        MENU(
                            CHOICE("bass guitar", [](){
                                MC("I play the bass", "guitar!")
                                INO("oh sick!", "I used to own", "one of those")
                            }),
                            CHOICE("drums", [](){
                                MC("I play the drums!")
                                INO("oh neat!", "I've never tried", "those")
                            })
                        )
                        INO("Which genre do you", "perfrom?")
                        HOBBY_MUSIC_TALENT = main_character_state::part_of_band;
                    })
                )
                MENU(
                    CHOICE("punk rock", [](){
                        MC("punk rock music", "I tried a few", "other genres but this", "one feels the best!")
                        INO("right on!", "I love that stuff!")
                        HOBBY_MUSIC_PREFERENCE = main_character_state::punk_rock;
                    }),
                    CHOICE("RnB/Soul", [](){
                        MC("mostly RnB and Soul", "music")
                        INO("oh very cool!", "I don't know much", "about that genre")
                        INO("but it fun to", "listen to new things.", "creativity comes", "from anywhere!")
                        HOBBY_MUSIC_PREFERENCE = main_character_state::rnb;
                    }),
                    CHOICE("shoegaze", [](){
                        MC("oh uhm...", "well shoegaze.", "have you heard", "of it?")
                        INO("haha yes I have", "absolutely heard of", "it!")
                        INO("it is definitely", "a vibe.")
                        HOBBY_MUSIC_PREFERENCE = main_character_state::shoegaze;
                    })
                )
                INO("well...", "I am feeling", "a bit tired.")
                INO("that was a good", "conversation. Thanks for", "coming over!")
                MC("agreed, It was fun!", "I'll see you at", "work!")
                INO("see ya!")
                SCENE_END
                MC("(that went well!)")
            })
        )
    }
    //! \brief ino wants to play tennis
    void ino_emergency_prompt_1() {
        INO_TEXT("hey I was thinking", "of getting outside", "today. want to play", "some tennis?")
    }
    //! \brief tennis goes well (convience store)
    void ino_emergency_1() {
        SCENE_END
        MC("sure, where should I", "meet you?")
        INO_TEXT("there is a park by work.", "try to get there by 3pm.")
        INO_TEXT("oh! and don't worry", "about the equipment!")
        MC("ok, see you there!")
        SCENE_END
        BG_PARK
        FADE_IN
        SHOW_INO_NORMAL
        MC("hey Ino")
        INO(MCF("welcome, {}!"), "glad you could make", "it!")
        INO("alright, then!", "let's get to it!", "have you played before?")
        MENU(
            CHOICE("high school team", [](){
                MC("well, I was on our", "team in high school")
                MC("but I haven't played in", "gosh...", "maybe four years?")
                MC("hopefully it will", "all come back to me.", "just need a bit of", "warming up")
                INO("oh wonderful! ")
            }),
            CHOICE("only in gym", [](){
                MC("only in gym class...", "which was about", "four years ago...")
                MC("at least I can hit the", "ball back!")
                INO("I like your attitude!", "Don't worry about the", "score.")
                INO("I'm excited to get", "outside and play with", "someone new")
            })
        )
        INO("Alright, let's get", "started with some back", "and forth to warmup")
        MC("alright!")
        INO("*hit*")
        MC("          *hit*")
        INO("", "*hit*")
        MC("", "          *hit*")
        INO("", "", "*hit*")
        MC("", "", "          *miss*")
        MC("oh darn!")
        INO("that's alright", MCF("{}!"), "keep it up!")
        INO("*hit*")
        MC("          *hit*")
        INO("", "*hit*")
        MC("", "      *powerful hit*")
        EMPTY("(Ino runs and...)")
        INO("", "", "*smack*")
        EMPTY("(the ball hits the net)")
        INO("darn!", "looks like you're getting", "into the swing of", "things! haha")
        MC("haha looks like it!", "", "(oh Ino...)")
        INO("good thing I'm", "just warming up.", "No more easy mode!")
        MC("haha let's see it!")
        EMPTY("(a half hour passes)")
        MC("*huff huff*", "ok that... is...", "enough.. for...", "me...")
        INO("*phew* yea that was", "a good workout!")
        INO("want to head over", "to the convenience store?", "Looks like I've run", "out of water")
        MENU(
            CHOICE("too tired", [](){
                MC("actually that match", "did a number on me.")
                MC("I'm going to head back", "home and take a nap")
                MC("well... after a shower", "of course")
                INO("ok, sounds good.", "thanks for the match!")
                MC("see you!")
            }),
            CHOICE("sure!", [](){
                MC("sure, I'd love to", "get something too")
                INO("alright, let's go!")
                SCENE_END
                BG_CONVENIENCE
                FADE_IN
                SHOW_INO_NORMAL
                MC("ahh its so cold in", "here!")
                INO("darn, this feels good!")
                INO("Looks like the drinks", "are in the back...")
                EMPTY("(you head to the drink", "aisle)")
                MC("now, what do I feel", "like getting today?")
                MENU(
                    CHOICE("WaterAde", [](){
                        MC("chilled WaterAde sounds", "great. let's do that.")
                        INO("good choice")
                        CONVENIENCE_DRINK = main_character_state::waterade;
                    }),
                    CHOICE("Green Tea", [](){
                        MC("Green tea should hit", "the spot!")
                        INO("oh nice pick")
                        CONVENIENCE_DRINK = main_character_state::green_tea;
                    }),
                    CHOICE("Coffee", [](){
                        MC("COFFEE! my beloved")
                        INO("haha, you like", "coffee that much?")
                        MC("hehe... yea...")
                        CONVENIENCE_DRINK = main_character_state::coffee;
                    })
                )
                MC("what did you get,", "Ino?")
                INO("oh just some boring", "water... and this", "granola bar")
                //! \ino_maybe is not picky with food
                MC("pretty utilitarian")
                INO("I guess I'm not so", "picky when it comes", "to food.")
                MC("well, it's hard to be", "picky when it's this hot", "out")
                INO("true")
                INO("ok, let's head back", "to the park to enjoy", "these")
                SCENE_END
                BG_PARK
                FADE_IN
                SHOW_INO_NORMAL
                MC("ahh this breeze is", "nice!")
                INO("still nothing like that", "air conditioning at the", "store!")
                MENU(
                    CHOICE("any other sports?", [](){
                        MC("do you play any other", "sports?")
                        //! \ino_maybe played badminton in college
                        INO("not at the moment", "though I did play", "badminton in college")
                        MC("oh that is a cool", "sport! I also played", "a bit, though that", "was high school")
                        INO("ahh! That would explain", "why you're so good", "at tennis")
                        MC("haha well not ~that good")
                        INO("hey, if you can", "hit the ball back,", "that's counts as", "good to me")
                        INO("besides, I had", "a lot of fun today.", "let me know if", "you want to play again.")
                        MC("sure!")
                    }),
                    CHOICE("tennis?", [](){
                        MC("so how long have you", "played tennis for?")
                        INO("let's see...", "maybe four years or so?")
                        INO("actually it was a", "previous programming team", "member that recommended", "I try it out")
                        INO("so we played a bit and", "I decided to stick with", "it.")
                        INO("there is a summer league", "so I decided to join", "that as a way to", "motivate myself to train")
                        MC("do you like the", "competition?")
                        //! \ino_maybe likes pressure and staying focused
                        INO("hmm...", "well I do enjoy a bit", "of pressure I suppose")
                        INO("so the competition really", "gets me to focus. training", "on the weeks leading up", "to the match")
                        INO("and then focusing on", "the match itself.")
                        //! \ino_maybe doesn't mind losing
                        INO("I don't even mind", "losing all that much.")
                        //! \ino_maybe likes working hard
                        INO("mostly just working hard", "and seeing if I can", "make something happen!")
                        MC("I see... you know,", "not many people have that", "fighting spirit!")
                        INO("fighting spirit? hmm...", "I guess that is one way", "to put it...")
                    })
                )
                EMPTY("(you finish your drinks", "and chat a bit longer)")
                INO("I think it's time for", "me to head back.", "See ya later!")
                MC("thank you for the", "invitiation. see you!")
            }),
            CHOICE("go to bar?", [](){
                MC("actually, I was thinking", "of something else...")
                INO("hmm like something to", "eat?")
                MC("something to... drink.", "like alcohol")
                INO("alcohol!? HAHAHA")
                INO("alcohol...")
                INO("...")
                INO("you know, that does", "sound quite refreshing")
                INO("and they would also", "have water...")
                INO("I can't decide.", "let me flip a coin!")
                EMPTY("(Ino pulls out a coin)")
                INO("heads: bar", "tails: convenience store")
                EMPTY("*flips in air*")
                MC("HEADS! PLEASE!")
                EMPTY("(Ino catches the coin)")
                INO("TAILS!")
                //! \ino_maybe is not superstitious and respects rules
                INO("well, I'm not very", "superstitious but I do", "respect the rules")
                INO("you have fun at", "the bar, I'm going to", "grab some water at the", "store")
                INO("let's meet again soon,", "I had fun today!")
                MC("I did too.", "I'll catch you later!")
            })
        )
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Ino wants to get some pizza
    void ino_emergency_prompt_2() {
        INO_TEXT("Hey, are you free?", "I was going to grab", "some pizza, want to", "tag along?")   
    }
    //! \brief head to pizza place, make some choices
    void ino_emergency_2() {
        SCENE_END
        MC("which pizza place", "should I meet you at?")
        INO_TEXT("123 pizza street", "I'll be there in an", "hour or so! see you!")
        MC("got it!")
        SCENE_END
        BG_PIZZA_PLACE
        FADE_IN
        MC("looks like I got", "here a bit early")
        MC("hmm lets see what", "they have...")
        SHOW_INO_NORMAL
        INO(MCF("hey, {}!"), "how is it going?", "sorry for being a", "bit late")
        MC("Hey, Ino!", "oh I'm doing well", "just taking a look", "at the menu")
        INO("anything looking good?")
        //! \ino loves veggie pizza
        MENU(
            CHOICE("sausage", [](){
                MC("I usually get", "sausage pizza.", "do you like that", "too?")
                //! \ino_maybe Ino prefers pepperoni to sausage
                INO("well, if I had to", "pick a meat, I woud", "go pepperoni")
                INO("but I usually just get", "the veggie pizza instead")
                PIZZA_PLACE_FOOD = main_character_state::sausage_pizza;
            }),
            CHOICE("veggie", [](){
                MC("I am thinking I'll", "get a slice of the", "veggie pizza")
                //! \ino_maybe Ino loves veggie pizza
                INO("mmm I love veggie", "pizza! I rarely ever", "get anything else")
                INO("let's see, this one", "has mushrooms and", "olives... nice nice!")
                PIZZA_PLACE_FOOD = main_character_state::veggie_pizza;
            }),
            CHOICE("salad", [](){
                MC("I think I'll just", "get salad today.")
                INO("not a fan of pizza?")
                MENU(
                    CHOICE("fan, not hungry", [](){
                        MC("well I do enjoy it", "but I guess I am", "not really in the", "mood today")
                        MC("usually I have it", "at parties or weekend", "events.")
                        MC("today, I want something", "a smaller. I think", "a salad will do")
                        INO("ok that makes", "sense")
                    }),
                    CHOICE("not fan", [](){
                        MC("I think it is the", "oil-y-ness. I would", "rather something a", "more raw")
                        MC("salad looks like the", "best option here for", "that")
                        INO("ahh ok", "sure, I guess they", "have something for", "everyone")
                    })
                )
                PIZZA_PLACE_FOOD = main_character_state::salad;
            })
        )
        INO("oh, did you know", "they serve alcohol", "here?")
        MC("no I did not.", "this is my first time", "here")
        INO("shall I get us some?")
        MENU(
            CHOICE("not for me", [](){
                MC("ehh, not today.", "maybe just some water.")
                INO("hey, water is a healthy", "choice! let me get you", "that instead")
                PIZZA_PLACE_DRINK = main_character_state::water;
            }),
            CHOICE("yes", [](){
                MC("sure, why not")
                INO("alright, two cold", "ones coming right up")
                PIZZA_PLACE_DRINK = main_character_state::beer;
            }),
            CHOICE("YES", [](){
                MC("oh absolutely!!!")
                INO("haha maybe I", "should let you get", "it if you're so", "excited!")
                PIZZA_PLACE_DRINK = main_character_state::beer;
            })
        )
        INO("looks like our", "food will be ready", "in a minute or so")
        INO("want to sit at", "this table here?")
        MC("sure")
        MENU(
            CHOICE("ask about tennis", [](){
                MC("so no tennis match", "this weekend?")
                INO("no not today. I do", "have a match scheduled", "tomorrow, though")
                INO("but it is for", "practice and isn't part", "of the league I'm in")
                MC("won't it rain tomorrow?")
                INO("I did see that...", "lets's hope it doesn't", "I'd really love to", "get out and play")
            }),
            CHOICE("ask about music", [](){
                MC("so any music playing", "this weekend?")
                INO("not this weekend. but", "there is a concert", "coming up in a few", "weeks")
                INO("I'll keep my eye on", "prices. sometimes you", "can get really low", "prices the day of.")
                MC("sure, that sounds", "interesting")
            })
        )
        INO("oh! it's ready!", "let me go grab that")
        EMPTY("(Ino heads to", "the counter for the", "food and drink)")
        INO("here it is!", "enjoy!")
        if(PIZZA_PLACE_DRINK == main_character_state::water) {
            if(PIZZA_PLACE_FOOD == main_character_state::salad) {
                MC("hmm this is alright...")
                INO("maybe you should", "have chose something", "more flavorful!")
                //! \ino_maybe is not picky
                INO("I'm no culinary", "expert but even I know", "that you gotta eat", "delicous food")
                INO("maybe try something", "more substantial next", "time.")
                INO("even garlic bread would", "give a bit of...", "depth?")
                MC("haha listen to", "you! Fine dining", "at the pizza shop!")
                INO("hahaha what", "can I say...")
            } else {
                MC("this pizza is pretty", "good!")
                INO("mm", "*nom nom*")
                INO("you know, the water", "kinda makes the", "pizza taste better")
                INO("maybe its a hot", "and cold sort of thing")
                MC("hmm now that you", "say that, it does", "make sense...")
            }
        } else {
            MC("ahh this beer is", "refreshing")
            if(PIZZA_PLACE_FOOD == main_character_state::salad) {
                MC("can't say it goes well", "with salad, though...")
                INO("haha anything can", "go well with beer!")
                INO("maybe you haven't", "had enough beer yet?")
                MC("yet??")
                INO("ahahahaha", "oh chill out!")
            } else {
                //! \ino_maybe loves beer
                SHOW_INO_HAPPY
                INO("*sigh*", "I love it!")
                SHOW_INO_NORMAL
                INO("I am going to get", "another slice of the", "veggie. do you want", "half?")
                MENU(
                    CHOICE("sure", [](){ MC("Sure, I'll take half") }),
                    CHOICE("full", [](){ MC("no thanks, I'm pretty", "full") })
                )
                INO("ok, sounds good")
            }
        }
        EMPTY("(you and Ino finish", "your food)")
        INO("*phew* what a meal!")
        MC("this was a pretty", "tasty option. thanks", "for the invite!")
        SHOW_INO_HAPPY
        INO("any time! thank", "you for coming with!", MCF("see ya, {}!"))
        SHOW_INO_NORMAL
        MC("bye, Ino!")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Ino wants to see some music (favorite genre concert)
    void ino_emergency_prompt_3() {
        INO_TEXT("hey sorry for the", "short notice. are you", "interested in seeing", "some music?")
    }
    //! \brief concert (default rock) + ??
    void ino_emergency_3() {
        SCENE_END
        if(PIZZA_PLACE_DRINK == main_character_state::water) {
            INO_TEXT("hey meet me at", "the pizza place around", "5:15pm")
            MC("ok, see you there")
            SCENE_END
            BG_PIZZA_PLACE
        } else {
            INO_TEXT("hey meet me at", "the bar around", "5:15pm")
            MC("ok, see you there")
            SCENE_END
            BG_BAR
        }
        FADE_IN
        SHOW_INO_NORMAL
        INO("hey nice to", "see you!")
        MC("hey Ino! so which", "band are we seeing?")
        if(HOBBY_MUSIC_TALENT == main_character_state::sings) {
            INO("I wanted to find", "something with a", "great vocal performance")
            INO("the first thing that", "came to mind was an", "opera.")
            INO("but I don't know if", "you can drink at those", "sorts of places...")
            INO("all I could think of", "was something soulful.", "and what could be more", "soulful than folk music!")
            INO("the band name is", "called Pleasant Crew")
            INO("its a mix of", "country and bluegrass", "but they still have", "a few upbeat ones")
            MC("oh interesting", "choice! I don't", "think I've heard", "that before")
        } else if(HOBBY_MUSIC_PREFERENCE == main_character_state::rnb) {
            INO("I remember you saying", "you enjoy RnB...")
            INO("but I don't really know", "much about the genre...")
            INO("so the next best thing", "I thought was a jazz band")
            INO("I was able to find", "a jazz trio here", "in town. Their stuff", "is really creative")
            INO("so I thought you might", "enjoy it")
            MC("oh that sounds wonderful!")
        } else if(HOBBY_MUSIC_PREFERENCE == main_character_state::shoegaze) {
            INO("well it was a bit", "hard to find, but", "I was able to", "find a place")
            INO("with some shoegaze!")
            MC("no way! in", "this town?")
            INO("yea! I couldn't", "believe it either. still,", "I was able to find", "a place")
        } else {
            if(HOBBY_MUSIC_PREFERENCE == main_character_state::punk_rock) {
                INO("well you mentioned", "you like punk rock", "so it was pretty easy", "to find something")
                INO("I've been to a few", "of these shows and", "its always full of", "energy")
            } else {
                INO("I wasn't sure what", "you'd be into, so I", "found a rock band", "that I've seen")
                INO("a few times.")
            }
            INO("I've been listening", "to them the past", "few years so why", "not see 'em live?")
            MC("ok, neat!")
        }
        if(PIZZA_PLACE_DRINK == main_character_state::water) {
            INO("Let's grab some water", "before we go. It", "might be hard to get", "at the venue")
            MC("sure, let get some")
            INO("I'll also get some", "fries. I'm feeling a", "bit hungry")
            EMPTY("(ino gets the drinks", "and the food)")
            INO("you are welcome to", "help yourself")
        } else {
            INO("ok before we head", "out to the venue", "do you want to", "grab something to drink?")
            INO("things always seem", "to be more expensive", "at the concert hall")
            MENU(
                CHOICE("not really", [](){
                    MC("my stomach isn't", "feeling well today.", "I'll take a pass")
                    INO("ok. I'll get something", "small, then")
                    EMPTY("(Ino gets her drink)")
                }),
                CHOICE("yes please!", [](){
                    MC("sure, I'll take one")
                    INO("right on, let", "me ask for two")
                    EMPTY("(Ino gets the drinks)")
                })
            )
        }
        INO("we've got some time", "before we need to", "leave...")
        INO("let's play a game!")
        MENU(
            CHOICE("riddle", [](){
                // https://parade.com/947956/parade/riddles/
                MC("I've got one!")
                MC("What is full of holes", "but still holds water?")
                INO("oh I know!", "one of the squeegee", "things for a car!")
                INO("don't they have", "a hole pattern?")
                MC("well the answer was", "sponge but yes that", "is also a sponge")
                INO("NICE!")
                INO("ok here is one:", "What has legs,", "but doesn't walk?")
                MENU(
                    CHOICE("clock", [](){
                        MC("a clock!")
                        INO("BAHAHAHA THOSE", "ARE ARMS!")
                        MC("oh... right.")
                    }),
                    CHOICE("table", [](){
                        MC("a table!")
                        INO("bingo!", "that's one point for", MCF("{}!"))
                    })
                )
                MC("ok one more...")
            }),
            CHOICE("would you rather", [](){
                MC("maybe a would-you", "-rather?")
                MC("hmm...", "would you rather listen", "to music every minute", "you're awake...")
                MC("or never listen to", "music ever again?")
                INO("oh that just isn't", "fair...", "can't you think of", "a nice one?")
                MC("ok a nice one...", "hmm...")
                MC("would you rather have", "beer without pizza or", "pizza without beer?")
                INO("that...", "aren't those the", "same?")
                MC("ok I give up!", "let's see you", "try one")
                INO("ok ok...", "hmm...")
                INO("would you rather have", "100 acquaintances", "or 1 best friend?")
                MENU(
                    CHOICE("100 acquaintances", [](){
                        MC("I will go with the", "100 acquaintances")
                        MC("it sounds tough, but", "think of all of the", "possible activities", "available")
                        MC("100 people means", "at 3 hobbies per", "person means...")
                        INO("300 hobbies!", "hmm interesting", "way to look at", "it")
                    }),
                    CHOICE("1 best friend", [](){
                        MC("easy! one best", "friend!")
                        INO("you don't think", "that you'd get bored", "of one person after", "a while?")
                        MC("no, I mean isn't", "that why they are", "you're best friend?")
                        MC("if we've been together", "for several years...")
                        MC("I don't really see", "how that could come", "to and end")
                        INO("hmm...")
                    })
                )
                //! \ino_maybe would pick 100 acquaintances over 1 friend
                INO("yea I'd have to", "pick the 100", "acquaintances")
                INO("I think I would have", "so many more options", "on things to do")
                MC("you don't think you'd", "rather have someone", "closer?")
                //! \ino_maybe doesn't have anyone very close
                INO("ehh, I guess I don't", "have anyone that", "I'm close with now...")
                INO("maybe I don't know", "what I'm missing...")
            })
        )
        INO("well would look", "at the time!", "let's finish up", "here and head out")
        EMPTY("(you finish up and", "head to the concert hall)")
        SCENE_END
        BG_CONCERT_HALL
        FADE_IN
        SHOW_INO_NORMAL
        INO("yes! finally!", "are you excited?")
        MC("oh yea! I haven't", "see live music in", "ages")
        INO("whoo! let", "enjoy it!")
        EMPTY("(the concert begins)")
        INO("whoo!")
        MC("yea!")
        EMPTY("(the concert ends)")
        SHOW_INO_HAPPY
        INO("sheesh that was", "amazing!")
        MC("amazing! what", "a wonderful time!")
        SHOW_INO_NORMAL
        INO("I'm glad you", "enjoyed it! It wasn't", "the easiest to get", "tickets for...")
        MC("well I sincerely", "appreciate the effort")
        MC("and I'm glad I have", "someone like you to", "share the memories", "with")
        INO("aww...", "well, thanks again!")
        SCENE_END
        vnlib::end(vnlib::GOOD_END);
    }

    /*
     * Kanade Emergency
     */
    //! \brief Kanade's cat isn't feeling well
    void kanade_emergency_prompt_0() {
        KANADE_TEXT("sorry if this is a", "bad time. My cat isn't", "feeling well and I", "was wondering...")
        KANADE_TEXT("maybe we could head", "to the vet together?")
    }
    //! \brief Kanade's cat ends up fine
    void kanade_emergency_0() {
        SCENE_END
        MC("sure, I can help", "where should I go?")
        KANADE_TEXT("the address of the vet", "is 444 main street")
        //! \kanade has a cat named Chester
        KANADE_TEXT("I'll bring Chester and", "we can meet inside", "sound good?")
        MC("alright, I'll meet you", "there.")
        EMPTY("(you make your way", "to the veterinarian)")
        SCENE_END
        BG_VET_OFFICE
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE(MCF("hey, {}!"))
        MC("oh sorry looks like", "I'm a bit late")
        KANADE("that's alright, I've", "already brought Chester", "inside for them to", "start some checks")
        KANADE("he didn't seem", "very well this morning", "so I wanted to be", "sure that...")
        KANADE("it isn't something", "serious. he is", "a pretty healthy cat", "so we'll see.")
        //! \kanade sometimes thinks of the worst possible outcome
        KANADE("I am usually fine", "on my own but", "sometimes my mind", "thinks of the worst")
        KANADE("so thanks for", "keeping me company")
        MC("oh, I don't", "mind at all!")
        MENU(
            CHOICE("how long?", [](){
                MC("how long have you", "had Chester?")
                KANADE("hmm...", "I think around two and a", "half years")
                KANADE("I pickd him up from", "a shelter. I saw online", "that they were reaching", "capacity...")
                //! \kanade_maybe wants to help the animal shelter
                KANADE("so naturally I", "couldn't resist helping", "out")
                MC("we're you confident that", "you could take care", "of him?")
            }),
            CHOICE("dog?", [](){
                MC("do you have a", "dog too?")
                KANADE("I've thought about it", "but they seem like", "too much work")
                KANADE("cats are much cuter", "though they still", "require attention")
                MC("so you just have", "one cat, then?")
            })
        )
        KANADE("My family has had a", "few cats before")
        KANADE("but Chester is the", "only one alive now")
        MC("oh...")
        KANADE("haha its ok.", "normal parts life", "and all...")
        KANADE("do you have any pets", MCF("{}?"))
        MENU(
            CHOICE("none", [](){
                MC("nope, no pets for me")
                KANADE("oh, any reason why?")
                MENU(
                    CHOICE("allergies", [](){
                        MC("unfortunately, I", "have pretty bad", "allergies. I wish", "I didn't, though")
                        KANADE("oh I hear you", "I had a few friends", "growing up that", "refused to come")
                        KANADE("over because of", "their allergies", "*sigh*")
                    }),
                    CHOICE("too much work", [](){
                        MC("well I used to have", "a dog but it was", "way too much work")
                        MC("even my family helped", "out with the walks but", "it was just way too", "much for us")
                        MC("obviously it wasn't", "all bad but we were", "sure that pet care", "wasn't for us")
                        KANADE("aww well I think", "that it was worth", "the try!")
                    }),
                    CHOICE("like being alone", [](){
                        MC("honestly I like", "peace that comes", "from being alone")
                        MC("I think a pet", "would cause too much", "stress for someone", "like me")
                        KANADE("hmm...", "maybe you'll change", "your mind after", "meeting Chester!")
                    })
                )
            }),
            CHOICE("cat", [](){
                MC("yes! I also have a", "cat!")
                KANADE("ooh ooh!", "what's its name?")
                MENU(
                    CHOICE("charles", [](){
                        MC("his name is Charles")
                        KANADE("oh, I like it!")
                    }),
                    CHOICE("onion", [](){
                        MC("his name is Onion")
                        KANADE("hahaha haven't heard", "that one before!")
                    }),
                    CHOICE("reginald", [](){
                        MC("his name is Reginald")
                        KANADE("interesting. it seems a", "bit... old?")
                        MC("you think so? hmm...")
                    })
                )
                MC("anyways, he is also about", "to turn five")
                KANADE("congrats!")
            }),
            CHOICE("fish", [](){
                MC("I own a fish.", "I used to have", "a few more but", "they don't last")
                KANADE("are you feeding", "them??")
                MC("yes yes I did", "my research!")
                MC("They don't live very", "long lives. not sure", "I'll get any more", "after this batch")
            })
        )
        KANADE("oh looks like the", "doctor is all done.", "let me go check the", "results...")
        HIDE
        EMPTY("(Kanade heads to", "the desk)")
        SHOW_KANADE_NORMAL
        KANADE("*phew*", "it's nothing serious!", "the vet says he just", "ate something")
        MC("that is a relief!")
        KANADE("ok well I guess", "I'll head home from", "here.")
        KANADE("thank you again", "for the company!", "I'm glad everything", "worked out")
        MC("alright, see you", "at work, Kanade!")
        KANADE(MCF("bye, {}!"))
        SCENE_END
        MC("(that went well)")
    }
    //! \brief Kanade needs to return some library books
    void kanade_emergency_prompt_1() {
        KANADE_TEXT("Hey I need to swing", "by the library today.", "want to tag along?")
    }
    //! \brief Kanade talks in the park outside, you buy a book inside during the sale
    void kanade_emergency_1() {
        SCENE_END
        MC("sure, where should", "we meet?")
        KANADE_TEXT("meet me at", "333 main street!", "I'll be there in", "an hour!")
        MC("sounds good!")
        SCENE_END
        BG_LIBRARY_PARK
        FADE_IN
        MC("hmm seems I got here", "here a bit early...")
        MC("...")
        SHOW_KANADE_NORMAL
        KANADE("hello there!")
        MC("Hey Kanade")
        MC("Did you return the", "book yet?")
        KANADE("oh I'm not returning", "anything today! There", "is a book sale I", "wanted to check out")
        MC("hmm I've never been", "to one of those")
        KANADE("well the library is only", "so big...", "and some books aren't", "as popular as others")
        KANADE("so they hold a sale", "to get rid of the", "lesser-used ones")
        KANADE("some people will also", "swap books so you", "might find something", "interesting!")
        MC("which genre are you", "looking for?", "wait, let me guess!")
        MENU(
            CHOICE("sports", [](){
                MC("are you into books", "about sports? like", "biographies and such?")
                KANADE("hmm... not really")
                KANADE("I did try one", "before. It was...", "alright. Not really", "exciting enough")
                MC("oh. ok.")
            }),
            CHOICE("mystery", [](){
                MC("do you like mystery", "books? like solving", "crime or investigating", "paranormal houses?")
                //! \kanade_maybe was into occult stuff in middle school
                KANADE("haha I did have", "an occult phase in", "middle school!")
                KANADE("but nope, not really", "interested in that", "anymore!")
            }),
            CHOICE("romance", [](){
                MC("maybe it's romance?")
                KANADE("nice guess!")
            })
        )
        KANADE("if I had to pick", "one genre, it would", "be romance")
        MC("any particular reason", "why?")
        //! \kanade imagines herself in the stories
        KANADE("well most people", "imagine themselves in", "story, even if they", "won't admit it")
        KANADE("I think its what", "makes stories fun!")
        KANADE("if you make it real", "it becomes important!", "so read things you", "can imagine")
        MC("oh I see. I guess", "it could also work", "for movies and TV", "shows, too")
        KANADE("exactly! I think", "it's why the story", "can't be ~too good")
        KANADE("othersie it won't", "feel real and breaks", "the readers immersion")
        MC("ok ok.", "have you tried writing", "a story? sounds like", "you've got the formula")
        KANADE("I mean...")
        KANADE("I could try...", "but I don't think", "I have the patience")
        KANADE("maybe it isn't so", "different from the", "marketing paperwork...")
        KANADE("haha I'm sure they", "are VERY different!")
        KANADE("well...")
        KANADE("let's head inside and", "see the books they have!")
        EMPTY("(you head inside", "the library)")
        SCENE_END
        BG_LIBRARY_INSIDE
        FADE_IN
        SHOW_KANADE_NORMAL
        MC("oh it is nice", "and cool in here!")
        KANADE("I love it!", "let check out those", "shelves over there!")
        MC("hmm there are some", "interesting ones here...")
        MC("pipefitting for", "dummies? not in", "this life.")
        KANADE("keep looking! you'll", "find something!")
        MENU(
            CHOICE("Kaiju For Lunch", [](){
                MC("hmm maybe this", "one has some action:", "Kaiju For Lunch")
                MC("Kaiju attack San", "Francisco, but they", "only want one thing:", "a Michelangelo Star")
                MC("ya know...", "this could actually", "be kinda cute...")
                KANADE("haha look at that!", "you found one!")
                MC("I found...", "something...")
                KANADE("give it a try!")
                MC("ok, if you insist")
                BOOK_SALE_BOOK = main_character_state::kaiju_for_lunch;
            }),
            CHOICE("Weekend at Darlene's", [](){
                MC("Weekend at Darlene's", "every night the", "ground shakes vicously")
                MC("construction?", "aliens? old age?", "will you", "SUVIVE??")
                MC("well, it does have", "some suspense. I'll", "give it that...")
                KANADE("don't be a critic!", "you know how the saying", "goes!")
                MC("true. I guess I", "can give it a chance")
                BOOK_SALE_BOOK = main_character_state::weekend_at_darlenes;
            }),
            CHOICE("Cooking Fury", [](){
                MC("hmm Cooking Fury?", "wonder what this is.")
                MC("Charolette and Bosco", "find that their pizza", "was missing one", "ingredient: love")
                MC("I mean...", "is that even a", "story?")
                KANADE("oh oh let me see", "ahh...", "yes...", "YES!!!")
                KANADE("I've seen a few people", "talk about this one", "online")
                KANADE("Charolette is actually", "a ex-paramility operative", "and Bosco is, well", ", he's broke")
                KANADE("so its a cute", "push and pull about", "morals and business")
                KANADE("and there may be", "several extremely romatic", "scenes. NOT for the", "fainthearted!")
                MC("hmm not bad!", "I'll give it a try.")
                BOOK_SALE_BOOK = main_character_state::cooking_fury;
            })
        )
        KANADE("ok now that you've", "made your choice, its", "time to read!")
        KANADE("unfortunately, I need", "to cook dinner with my", "family so I'll be", "heading back")
        KANADE("maybe try reading here", "for a bit!")
        MC("ok I'll do that", "thanks for the help!", "see you!")
        KANADE("take care,", MCF("{}!"))
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Kanade is getting a limited time release
    void kanade_emergency_prompt_2() {
        KANADE_TEXT("hey I need to grab", "a new release from", "bookstore!")
        KANADE_TEXT("I don't think it", "last long! We gotta", "check it out!")
    }
    //! \brief We acommonpany Kanade for the book release, and get some food after
    void kanade_emergency_2() {
        SCENE_END
        MC("sure, where should", "I meet you?")
        KANADE_TEXT("meet me at 777 main", "street! and hurry!")
        MC("say less!", "I'll be there!")
        EMPTY("(you rush to the", "bookstore)")
        SCENE_END
        BG_BOOKSTORE
        FADE_IN
        MC("Kanade! I'm over", "here!")
        SHOW_KANADE_NORMAL
        KANADE(MCF("{}!"), "here come wait in", "line with me")
        MC("*phew*", "how long have you", "been here?")
        KANADE("only thirty minutes.", "gosh, look how many", "people there are!")
        MC("this line goes down", "the block. Honestly", "I am lucky to", "have found you")
        KANADE("you can say that", "again! Do you", "know what we're", "waiting for?")
        MC("nope! not a clue")
        KANADE("Well its a book signing", "for 'The Witch and", "the Wench'")
        KANADE("it's easily one of the", "best books of the decade")
        MC("the witch and the", "WHAT??")
        KANADE("ok ok chill out!", "It has a raunchy title", "but the book is pretty", "cute...")
        KANADE("it's about...", "nevermind! I won't", "spoil it. It's good!", "trust me on this.")
        MC("ok ok I trust you")
        MC("hmm so how much", "long do you think", "the wait will be?")
        MC("maybe I should have", "grabbed some snacks on", "the way here...")
        KANADE("oh not too much longer", "usually they open doors", "at the top of the hour")
        KANADE("so it should only be", "ten or twenty minutes", "more")
        KANADE("but if you are hungry,", "maybe we can get", "something after?")
        MC("sure, lets do that!")
        EMPTY("(twenty minutes pass)")
        KANADE("SWEET! looks like the", "line is moving!")
        MC("wonderful!", "", "(my legs! ahh!)")
        EMPTY("(the line moves along", "and Kanade finally gets", "her book signed)")
        KANADE("*phew*", "that was somethin'!")
        KANADE("Are you still hungry?", "I'm feeling kinda hunry", "myself...")
        MENU(
            CHOICE("pizza", [](){
                MC("honestly, I am pretty", "hungry. I mean, I", "would probably eat", "the table, too!")
                KANADE("that doesn't sound", "healthy OR tasty!")
                MC("well... anways", "want to get some pizza?", "I think the shop is", "around here")
                KANADE("sure, pizza sounds good", "to me. Let's go!")
                MC("ok let me look it", "up to double check.")
                EMPTY("(you search and make", "your way to the pizza", "place)")
                SCENE_END
                BG_PIZZA_PLACE
                FADE_IN
                SHOW_KANADE_NORMAL
                KANADE_POST_BOOK_PLACE = main_character_state::pizza_place;
                KANADE("ahh this smells amazing!", "now I REALLY want", "something to eat")
                MC("hmm what to get...")
                //! \kanade_maybe likes sausage pizza
                KANADE("hmm the slice of the day", "looks interesting:", "sausage and pepper")
                KANADE("sure, I'll try that", "one")
                MENU(
                    CHOICE("cheese", [](){
                        MC("I think I'll do the", "cheese slice")
                        KANADE("is the slice of the day", "not interesting?")
                        MC("well...", "I guess I want", "something simple today")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::cheese_pizza;
                    }),
                    CHOICE("meat lovers", [](){
                        MC("OO! looks like they", "have a meat lovers!", "I'll take two of", "those!")
                        KANADE("wow! no hesitation!")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::meat_lovers_pizza;
                    }),
                    CHOICE("slice of the day", [](){
                        MC("you know, the slice of", "the day does seem", "interesting")
                        KANADE("nice! you never know", "maybe it'll be your", "new favorite thing!")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::slice_of_the_day;
                    })
                )
                MC("let's sit over here")
                KANADE("sure, looks like just", "enough space for us")
                MC("time to enjoy!")
            }),
            CHOICE("bar", [](){
                MC("well, it's been a", "long weekend. Would you", "be interested in", "heading to a bar?")
                //! \kanade_maybe doesn't drink much alcohol
                KANADE("hmm... well I'm not", "a big alcohol drinker...")
                //! \kanade_maybe is willing to try new things
                KANADE("but I don't mind", "trying something new!")
                MC("ok let's go there and", "check it out. If", "it isn't for you", "then we'll head home")
                KANADE("ok, sounds good!")
                MC("I'll double check the", "location. It should be", "somewhere around here...")
                MC("ahh! I've found it!", "Let's head out")
                EMPTY("(you make your way", "to the bar)")
                SCENE_END
                BG_BAR
                FADE_IN
                SHOW_KANADE_NORMAL
                KANADE_POST_BOOK_PLACE = main_character_state::bar;
                MC("oh nice, plenty of space")
                MC("let's take this table")
                KANADE("oh this is much", "nicer than what I", "imagined")
                KANADE("I always think that bars", "are shady, run-down, gross,", "smelly, tin cans in the", "worst parts of town")
                MC("HAHA what stories have", "you been reading?")
                MC("most places are pretty", "welcoming! though, some", "are still a bit stinky...")
                MC("Let me see if I", "can get a pitcher.", "You can have as little", "or as much as you want")
                KANADE("ok, that sounds nice")
                EMPTY("(you head to the bar", "to grab the glasses", "and the pitcher)")
                MC("alright, here it is!")
                EMPTY("(you pour yourself", "a tall one and take", "sip)")
                KANADE("woah woah!", "no cheers? isn't that", "what people do?")
                MC("gah! right!", "I'm sorry. Feeling", "a bit distracted")
                KANADE("well better late", "than never!", MCF("cheers, {}!"))
                MC("cheers!")
                KANADE_POST_BOOK_PLACE_ITEM = main_character_state::beer;
            }),
            CHOICE("convinence store", [](){
                MC("well I'm feeling a", "bit tired, maybe something", "small...")
                MC("want to head to the", "convience store?")
                KANADE("sure, it's just around", "the block")
                MC("alright, let's go!")
                EMPTY("(you make your way", "to the store)")
                SCENE_END
                BG_CONVENIENCE
                FADE_IN
                SHOW_KANADE_NORMAL
                KANADE_POST_BOOK_PLACE = main_character_state::convenience;
                MC("oh, its quite chilly", "in here!")
                KANADE("do you know where the", "cookies are?")
                MC("let's take a look over", "here")
                EMPTY("(you head to the snack", "section)")
                MC("what should I grab?")
                MENU(
                    CHOICE("trail mix", [](){
                        MC("trail mix should do", "the trick!")
                        KANADE("oh it has little", "chocolate pieces! yum!")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::trail_mix;
                    }),
                    CHOICE("chocolate cookies", [](){
                        MC("ooh super-chocolate", "cookies! and they come", "in a four pack!")
                        KANADE("YES! great choice")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::chocolate_cookies;
                    }),
                    CHOICE("BBQ chips", [](){
                        MC("oh BBQ flavored", "chip! I love these!")
                        KANADE("oh those sound nice!", "definitely a fun flavor")
                        KANADE_POST_BOOK_PLACE_ITEM = main_character_state::bbq_chips;
                    })
                )
                KANADE("looks like there is", "some space by the window.", "let's sit there.")
            })
        )
        KANADE(MCF("so, {}"), "did you read the book?")
        MC("the book?")
        KANADE("you know, the one from", "the other week!", "the one from the library?")
        MC("oh! right,", main_character_state::to_string(BOOK_SALE_BOOK))
        MENU(
            CHOICE("a little", [](){
                MC("yea I've read the first", "few chapters.")
                KANADE("oh, not liking it?")
                MC("actually I have", "been enjoying it.")
                MC("I have too many", "distractions these days", "so it's hard to find", "a good hour or two")
                KANADE("that's alright. even", "a few pages every", "weekend can really", "add up!")
            }),
            CHOICE("halfway", [](){
                MC("I'm about halfway", "through! Definitely", "did not expect to", "like it so much")
                KANADE("nice, that is great", "to hear!")
                KANADE("they have sales pretty", "often. If you ever", "want to head back", "let me know!")
                MC("sure!")
            })
        )
        KANADE("so...")
        KANADE("I'm in a bit of", "a situation right now")
        MC("hmm ok...")
        KANADE("so my brother's birthday", "is coming up")
        KANADE("and I am not sure what", "to get him...")
        KANADE("He mostly stays inside", "and plays video games", "with his friends online")
        KANADE("but he doesn't ever", "get me anything for MY", "birthday!")
        KANADE("Should I ignore it", "it this year? maybe", "a sack of coal", "would be better")
        MC("did you get him anything", "last year?")
        KANADE("well...", "yes, I got him a", "new game that he had", "been yapping about")
        MC("that sounds nice!")
        KANADE("well OBVIOUSLY it's", "nice! nice for HIM!")
        KANADE("am I allowed to", "ignore it? what", "should I do this", "time?")
        MENU(
            CHOICE("nothing at all!", [](){
                MC("I think the easiest", "answer is to get him", "nothing at all!")
                MC("you can always say", "you were busy with work", "and that you forgot")
                KANADE("I mean I ~could", "do that, but don't you", "think that is lying?")
                //! \kanade_maybe doesn't like lying
                KANADE("I don't know, that", "option doesn't really", "feel right to me...")
            }),
            CHOICE("something small", [](){
                MC("If you are having somse", "reservations, maybe just", "get him something small")
                MC("maybe a sticker or", "a pen. It doesn't", "really need to have", "any meaning")
                KANADE("true, that could work.", "Maybe there is a sticker", "from one of his", "favorite games.")
            }),
            CHOICE("another game", [](){
                MC("well the safest thing", "to do is get him", "another game")
                MC("maybe you could find", "something used?", "are there small or", "off-brand games?")
                KANADE("yea I could go with", "something used...")
                KANADE("there are some indie", "studios that make smaller", "and cheaper games, too")
                KANADE("hmm...")
            })
        )
        KANADE("ok I'll keep thinking!", "It is nice to get", "a second opinion on", "things")
        MC("sure, anytime!")
        KANADE("*yawn*", "ahh looks like I am", "getting tired")
        KANADE("guess that means its", "time to head home")
        KANADE("Thanks for meeting up", MCF("{}!"), "I'm glad we could spend", "some time together")
        MC("thank you for the invite!", "I'll see you around")
        KANADE("ok, see you", MCF("{}!"))
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Kanade wants to practice some baseball (but she won't tell us!)
    void kanade_emergency_prompt_3() {
        KANADE_TEXT("I was thinking of", "trying something new!", "want to meet up?")
    }
    //! \brief internal
    bool kanade_emergency_3_leave_early;
    //! \brief Kanade is pretty good at baseball
    void kanade_emergency_3() {
        SCENE_END
        MC("so where are we", "meeting up, exactly?")
        KANADE_TEXT("come to 888 main street!", "I'm already here so look", "for me inside")
        MC("alright, I'll head over")
        SCENE_END
        EMPTY("(you make your way", "to the address)")
        MC("what is this place?", "Sport City?")
        BG_BATTING_RANGE
        FADE_IN
        KANADE("oi! over here!", MCF("{}!"), "over here!")
        SHOW_KANADE_NORMAL
        MC("oh wow, I never knew", "we had a batting range", "in town")
        KANADE("neither did I!", "there was a show on", "the radio where a few", "of the semi-pro players")
        KANADE("use this place to", "practice")
        KANADE("I'm not really an", "active person but", "it seemed like a fun", "thing to try")
        MC("wow! so you've", "never played baseball?", "and you still decided", "to try this place out?")
        KANADE("that's right!", "actually, I'm having", "a great time!")
        KANADE("well, when I hit", "it. I'm still working", "on the timing and", "technnique")
        MC("awesome! how long do", "you have the cage?", "it would be fun to", "try it out")
        KANADE("oh have you not", "been to the batting", "cage, either?")
        MENU(
            CHOICE("nope", [](){
                MC("nope, I don't think", "I've ever swung a", "baseball bat before")
                KANADE("well, you're in for", "a treat")
            }),
            CHOICE("back in the day", [](){
                MC("I did play a bit", "of baseball growing up.", "but that was maybe", "ten years ago")
                KANADE("alright, let's see it!")
            })
        )
        EMPTY("(Kanade hands you", "the bat)")
        KANADE("ok, stand near the plate", "on the ground", "and give it a swing!")
        MC("uhh ok", "here goes nothing")
        EMPTY("(you wait patiently", "for the loading machine", "to make the loading", "sound)")
        KANADE("here comes the next one!")
        EMPTY("(the machine hurls", "the ball!)")
        MC("*whoosh*")
        KANADE("aww darn!", "try it again!")
        MC("(I just need to", "make contact!)")
        EMPTY("(the machine loads", "the next ball)")
        MC("heee yaaaa!")
        EMPTY("*ping*", "", "(the ball smashes the", "side of the cage)")
        KANADE("hey not bad for your", "second swing!")
        MC("wow I actually hit it!")
        KANADE("ok one more try", "then I'll go for it")
        EMPTY("(the machine loads", "the next ball)")
        MC("*woosh*")
        MC("aww darn another miss!")
        KANADE("that's alright, just", "give it a bit of time")
        KANADE("let me show you", "how its done!")
        MC("alright, let see it!")
        EMPTY("(the machine loads", "the next ball)")
        KANADE("take this!", "", "*whoosh*")
        MC("uhm...")
        KANADE("don't worry!", "I'll get the next", "one, for sure!")
        EMPTY("(the machine loads", "the next ball)")
        EMPTY("*ping*", "", "(the ball hits the", "100 point wall target)")
        KANADE("did you see that!", "amazing! 100 points!")
        MC("nice job!", "I have to say", "I'm pretty jealous")
        KANADE("I'll try it a few", "more times. then we can", "switch")
        MC("let's do that!")
        EMPTY("(an hour passes", "at the batting range.", "Kanade get several", "hundred more points)")
        MC("wow, that was quite", "a workout!")
        KANADE("you got that right!")
        KANADE("so, overall, what", "do you think?", "did you like it?")
        MENU(
            CHOICE("not really", [](){
                MC("well, I didn't do so", "well. I'm not sure", "I'd come back...")
                KANADE("oh don't be such", "a sore loser. It's", "ok to lose from", "time to time")
            }),
            CHOICE("yes!", [](){
                MC("I had a blast!", "I though it would be", "much worse, but I", "beat my expectations")
                KANADE("wonderful, I'm glad", "you enjoyed it!")
            })
        )
        KANADE("well...")
        KANADE("what should we do", "next?")
        MC("maybe somewhere to sit", "down?")
        KANADE("what about...", FMT_24("the {}?", main_character_state::to_string(KANADE_POST_BOOK_PLACE)), "you know, the one", "from last time?")
        MC("yea, that works for me!")
        EMPTY("(you make your way", FMT_24("to the {})", main_character_state::to_string(KANADE_POST_BOOK_PLACE)) )
        switch(KANADE_POST_BOOK_PLACE) {
        case main_character_state::pizza_place:
            BG_PIZZA_PLACE
            SHOW_KANADE_NORMAL
            KANADE("you sit here, I can", "grab us something to eat")
            MC("sounds good!")
            EMPTY("(you go to find", "a seat)")
            KANADE("taa-daa!")
            MC("what did you get?")
            switch(KANADE_POST_BOOK_PLACE_ITEM) {
            case main_character_state::slice_of_the_day:
                KANADE("I figured you would be", "up for something new so", "I got the slice of the", "day!")
                KANADE("which is... wait", "oh right, today its", "a veggie delight!")
                MC("very cool, thank you!")
                break;
            default:
                KANADE("I got a slice of", main_character_state::to_string(KANADE_POST_BOOK_PLACE_ITEM))
                MC("awesome! that", "sounds great!")
                break;
            }
            break;
        case main_character_state::bar:
            BG_BAR
            SHOW_KANADE_NORMAL
            KANADE("you sit here, I can", "grab us something to drink")
            MC("sure!")
            EMPTY("(you find a seat in", "the corner)")
            KANADE("here! I got us a pitcher")
            MC("haha wonderful")
            break;
        case main_character_state::convenience:
            BG_CONVENIENCE
            SHOW_KANADE_NORMAL
            KANADE("you sit here, I can", "grab us some snacks")
            MC("ok!")
            EMPTY("(you wait by the window)")
            KANADE("look! I got us some ", main_character_state::to_string(KANADE_POST_BOOK_PLACE_ITEM))
            MC("oh nice. that'll be tasty")
            break;
        default: break;
        }
        MC("you think you'll go", "back to the batting cage", "next week?")
        KANADE("maybe not so soon...", "but yea I'd love to", "go back!")
        KANADE("I mean, if I had someone", "to go out with, I", "think I would")
        KANADE("you know, I spend a lot", "of time with my family")
        KANADE("but I don't really", "have many people to go", "out with...")
        SHOW_KANADE_HAPPY
        KANADE("so its nice to have", "you around!")
        SHOW_KANADE_NORMAL
        MC("I'm enjoying our time", "together!")
        MC("let me know if you", "ever need someone around")
        KANADE("ok!", "you can count on me!")
        FADE_OUT
        vnlib::end(vnlib::GOOD_END);
    }

    /*
     * Rika Emergency
     */
    //! \brief Rika's team is down a player
    void rika_emergency_prompt_0() {
        RIKA_TEXT("hey there!", "My basketball team", "is down a player", "want to play?")
    }
    //! \brief Rika invittes us to fill in her basketball team
    void rika_emergency_0() {
        RIKA_TEXT("We play at the park", "near the WidgetCorp", "office")
        RIKA_TEXT("meet us in thirty", "minutes. sound good?")
        MC("sounds good, I'll be", "there!")
        EMPTY("you make your way to", "the park")
        SCENE_END
        BG_PARK
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA(MCF("hey, {}!"), "glad you could make it")
        MC("well, I'm not really the", "best basketball player", "but I'll do my best")
        RIKA("did you play when you", "were growing up?")
        MENU(
            CHOICE("no", [](){
                MC("no I didn't play at", "all. But I did play", "in gym class")
                RIKA("alright, well you might", "have a hard time then")
                RIKA("but you're welcome", "to stick around, the", "choice is yours!")
                MC("oh I'm definitely staying!", "I didn't walk here for", "nothing!")
                RIKA("wonderful! I like the", "spirit!")
            }),
            CHOICE("yes", [](){
                MC("yup, I played on a", "travel team growing up.")
                MC("to be honest, I wasn't", "that great but it was", "still fun competing")
                RIKA("oh nice! I think", "you'll enjoy it here!")
            })
        )
        RIKA("let's head over", "and get the teams formed")
        TEAM_CAPTAIN(MCF("so {}"), "do you want to play", "against or team up", "with Rika?")
        MENU(
            CHOICE("team-up", [](){
                MC("let's team up", "what do you say, Rika?")
                RIKA("let's show em!")
                RIKA_BASKETBALL_TEAM = main_character_state::same_team;
            }),
            CHOICE("play against", [](){
                MC("play against!")
                RIKA("HAHA let's see", "how this goes!")
                RIKA_BASKETBALL_TEAM = main_character_state::other_team;
            })
        )
        auto same_team = RIKA_BASKETBALL_TEAM == main_character_state::same_team;
        TEAM_CAPTAIN("alright, its decided!", "Rika, you start", "with the ball first")
        TEAM_CAPTAIN("let's go!")
        if(same_team) {
            RIKA("here take it", MCF("{}!"))
            EMPTY("(Rika passes you the", "ball)")
            MENU(
                CHOICE("dribble", [](){
                    EMPTY("(you start to dribble", "to the net)")
                    int successes = 0;
                    for(int i = 0; i < 3; i++) {
                        GAME(FMT_24("dribble LEFT {}/3", i))
                        successes += minigame_bugs::round(bn::keypad::key_type::LEFT);
                        GAME(FMT_24("dribble RIGHT {}/3", i))
                        successes += minigame_bugs::round(bn::keypad::key_type::RIGHT);
                    }
                    if(successes == 6) {
                        MENU(
                            CHOICE("pass back to Rika", [](){
                                EMPTY("(you pass back to", "Rika)")
                                RIKA(MCF("thank {}"))
                                EMPTY("(she scores the three!)")
                                RIKA("WOO NICE!")
                            }),
                            CHOICE("take the shot", [](){
                                EMPTY("(you take the shot...)")
                                EMPTY("(and it goes in!)")
                                RIKA("WOO NICE SHOT!")
                            })
                        )
                    } else {
                        EMPTY("(you lose the ball", "to the captain)")
                        TEAM_CAPTAIN("ha take that!")
                    }
                }),
                CHOICE("three point", [](){
                    int successes = 0;
                    for(int i = 0; i < 3; i++) {
                        GAME("jump!")
                        GAME(FMT_24("jump UP {}/3", i))
                        successes += minigame_bugs::round(bn::keypad::key_type::UP);
                    }
                    if(successes == 3) {
                        EMPTY("(you take the shot...)")
                        EMPTY("(and it goes in!)")
                        RIKA("nice job!")
                    } else {
                        EMPTY("(you whif the shot!)")
                        MC("AWWW NO")
                        RIKA("thats alright, you'll", "get it next time!")
                    }
                })
            )
        } else {
            EMPTY("(Rika dribbles to", "the net.")
            MC("I'll block you!")
            int successes = 0;
            for(int i = 0; i < 3; i++) {
                GAME(FMT_24("jump! UP ({}/3)", i))
                successes += minigame_bugs::round(bn::keypad::key_type::UP);
            }
            if(successes == 3) {
                EMPTY("(you steal the ball)")
                TEAM_CAPTAIN("pass it!")
                GAME("pass the ball to", "the captain! (DOWN)")
                if(minigame_bugs::round(bn::keypad::key_type::DOWN)) {
                    TEAM_CAPTAIN("nice pass!")
                } else {
                    EMPTY("(Rika steals the ball!)")
                    RIKA("HA mine again!")
                    MC("aww no!")
                }
            } else {
                EMPTY("(Rika scores the", "layup)")
                RIKA("WOO not bad!")
                MC(":(")
            }
        }
        EMPTY("(the game continues", "for an hour)")
        MC("*phew* I am tired!", "darn, what a workout!")
        RIKA("sheesh not bad", MCF("{}!"))
        RIKA("want to hit up the", "convenience store?", "I could use some", "more water")
        MC("sure, lets check it out")
        EMPTY("(you head over to", "the store)")
        SCENE_END
        BG_CONVENIENCE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("want me to grab you", "you one?")
        MENU(
            CHOICE("sure", [](){
                MC("sure, I'll take one")
                RIKA("alright, two it is")
            }),
            CHOICE("nope", [](){
                MC("no, I'm alright")
                RIKA("sounds good")
            })
        )
        EMPTY("(Rika buys the water)")
        RIKA("(here, we can sit", "up here and cool off)")
        MC("so how often do", "you play with them?")
        RIKA("this group?", "oh maybe every other", "week or so")
        RIKA("we're all pretty well", "rounded so we switch", "up the event based", "on the seasons")
        MC("oh neat. what else", "do you play?")
        RIKA("hmm well its usually", "basketball or volleyball", "in the summer")
        RIKA("in fall and winter", "we usually head indoors.", "rock climbing is our", "go-to")
        MC("that's quite a selection!")
        RIKA("better than sitting inside", "alone! at least to me.",)
        RIKA("what about you,", MCF("{}?"), "do you have a group of", "friends for activities?")
        MENU(
            CHOICE("no", [](){
                MC("nope, no group right", "now...")
                RIKA("awww well you're", "welcome to hang out", "with us!")
                RIKA("I had fun playing", "so I hope we can", "make this happen again!")
                MC("sure, that'd be", "great!")
            }),
            CHOICE("yes", [](){
                MC("I do have a group!", "maybe we can have", "a larger game one", "of these weeks!")
                RIKA("oh rad!", "yea let's do it!")
                RIKA("mostly its just", "us six but it would", "be cool to see a", "larger game")
            })
        )
        MC("alright, I'm going to", "head back.")
        RIKA("sounds good! see you", "at work!")
        MC("see ya!")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Rika needs to buy a gift for a party
    void rika_emergency_prompt_1() {
        RIKA_TEXT(MCF("Hey {}"), "I need some help", "buying a gift for", "an old friend.")
        RIKA_TEXT("want to come with?")
    }
    //! \brief Rika is shopping for a card
    void rika_emergency_1() {
        SCENE_END
        MC("Hey Rika, so where", "exactly are we going?")
        RIKA_TEXT("oh right...", "meet at the downtown", "park in thirty minutes")
        RIKA_TEXT("I haven't yet", "decided where we need", "to shop, but there", "are a few choices")
        MC("Alright, I'll head over")
        EMPTY("(you head to the park", "a bit early)")
        SCENE_END
        BG_PARK
        FADE_IN
        MC("here, I'll sit at this", "bench for a bit")
        DOG("*woof woof*")
        MC("oh cool, a dog!", "wait...", "are you here alone?")
        MC("where is...")
        DOG("*woof*")
        MC("hmm well maybe you", "can wait here until", "your family finds you")
        SHOW_RIKA_NORMAL
        RIKA("*phew* sorry I'm a", "bit late, everything", "seems to be going", "wrong today")
        MC("oh hey Rika!", "sorry to hear that")
        RIKA("oh did you bring", "your dog with?")
        DOG("*woof woof*")
        RIKA("is that a no?")
        MENU(
            CHOICE("no, it's not mine", [](){
                MC("no, it isn't mine", "it was running around", "when I got here.")
                MC("I don't see anyone", "looking for one either", "so maybe it ran away", "from home")
                RIKA("aww... well maybe we", "can brainstorm a bit", "and wait for someone", "to show up")
                MC("sure, works for me")
            }),
            CHOICE("yup, its mine!", [](){
                MC("yup, this is mine!")
                RIKA("wait really??")
                MC("yea, I've had him", "for several years now!")
                RIKA("oh but...", "nevermind...")
                RIKA("before we head out,", "let's think of a few", "gift ideas...")
                RIKA("usually, I'm good at", "this sort of thing", "but I'm feeling", "a bit off today")
                MC("sure, let's give it", "some thought")
            })
        )
        RIKA("alright, so the person", "is a long time friend", "from college")
        RIKA("we don't really talk", "much anymore.")
        RIKA("Maybe that's a", "bit surprising for", "someone like me...")
        RIKA("but I think our", "interests grew apart", "over time")
        RIKA("despite that, it's", "still fun to see each", "other and catch up")
        MENU(
            CHOICE("how did you meet?", [](){
                MC("how did you two meet?")
                RIKA("we met at a badminton", "club. I'm not really", "a big fan of the", "sport but...")
                RIKA("I had a pretty", "busy schedule so the", "club meetings were", "easier to get to")
                RIKA("turns out, we we're", "both pretty bad at it", "but it made playing", "each other fun")
                MC("haha that's nice.", "so you met there and", "continued to meet", "outside the club?")
                RIKA("yea, we always tried", "to have something", "going on")
            }),
            CHOICE("common activities?", [](){
                MC("did you have any", "things you used to", "do together?")
                MC("maybe you can find", "something that reminds", "you both of the", "good times")
                RIKA("hmm, the good times...")
                RIKA("we didn't really have", "many options in college...")
            })
        )
        RIKA("our strategy was", "find anything that was", "free. we really found", "quite a few things, too")
        RIKA("concerts, festivals,", "running groups, bicycle", "rides.", "Even church groups!")
        RIKA("we really didn't hold", "back at all!")
        MC("oh is that why", "it's so hard to pick", "something?")
        RIKA("well, sort-of", "I can't really", "say there is any one", "reason...")
        RIKA("anyway, where do you", "think we should head", "first?")
        MC("well, first I need to", "find the owner of-")
        DOG_OWNER("JiJi! There you are!")
        RIKA("wait...")
        DOG_OWNER("JiJi! finally,", "I've found you!")
        DOG("*woof*")
        DOG_OWNER("Thank you for looking", "after JiJi, good heavens")
        MC("oh it was no problem", "at all. Glad you", "found your dog!")
        EMPTY("(the owner abruptly runs", "off with JiJi)")
        RIKA("well that was...", "where were we?")
        MC("oh I was thinking about", "a few places to start...")
        MENU(
            CHOICE("card", [](){
                MC("let's start with", "something simple. start", "with a card and", "go from there")
                RIKA("sure, let's take a look")
                EMPTY("(you head to the", "card shop)")
                SCENE_END
                BG_CARD_SHOP
                FADE_IN
                SHOW_RIKA_NORMAL
                MC("alright, let's see", "what they have...")
                MC("maybe something funny", "and lighthearted?")
                RIKA("sure, what do", "they have...")
                RIKA("hmm")
                MC("does your friend like", "food? maybe a food pun?")
                RIKA("sure, any good ones?")
                MENU(
                    CHOICE("batter", [](){
                        MC("here's one:", "life's batter with", "you!")
                    }),
                    CHOICE("fish", [](){
                        MC("here's one:", "thanks for being my", "friend, nothing fishy", "about it")
                    }),
                    CHOICE("roll", [](){
                        MC("here's one:", "let's roll with it!")
                    })
                )
                RIKA("haha sure, let's do it")
                EMPTY("(you head the the", "front to purchase the", "card)")
            }),
            CHOICE("sport item", [](){
                MC("well, you met playing", "sports, maybe there will", "be something at that", "store?")
                RIKA("sure, it's worth", "checking out. let's", "head over")
                SCENE_END
                BG_SPORTS_SHOP
                FADE_IN
                SHOW_RIKA_NORMAL
                RIKA("wow, this place is", "pretty big. You wouldn't", "really know from outside")
                MC("yea, I've never seen", "some of this equipment", "before")
                RIKA("alright, let's check", "out the badminton section")
                EMPTY("(you walk to the", "back of the store)")
                MC("wow these rackets", "are quite expensive")
                RIKA("yea, our club was", "lucky to have some in", "a storage room.", "sheesh...")
                STORE_WORKER("Hello, welcome to", "Sports World. Are", "you looking for", "badminton equipment?")
                RIKA("yea we were just", "taking a look...")
                RIKA("do you know if", "there are any rackets", "on sale?")
                STORE_WORKER("nothing in this section", "sorry")
                MC("bummer")
                STORE_WORKER("oh! we have a used", "section downstairs", "if you're lucky, there", "might be some there")
                RIKA("wow a downstairs", "area!", "this place is huge!")
                STORE_WORKER("great for finding", "what you want, tough", "to keep clean, though")
                RIKA("I hear ya!", MCF("let's go {}"), "cross your fingers!")
                EMPTY("(you head to the", "basement)")
                RIKA("alright, you take that", "side, I'll look over", "here")
                MC("sounds good")
                EMPTY("(you pick through", "the bins for a bit)")
                MC("where should I look", "next?")
                MENU(
                    CHOICE("check large bins", [](){
                        EMPTY("(you sift through", "the large bin)")
                    }),
                    CHOICE("check shelves", [](){
                        EMPTY("(you search the shelves)")
                    }),
                )
                MC("nothing over here...")
                RIKA("nothing here either...")
                EMPTY("(you search some more)")
                MC("darn...")
                RIKA("oh I think I", "found some!")
                MC("how many did you", "find?")
                RIKA("looks like there are", "two. neat! this will", "be fun!")
                EMPTY("(you head back upstairs", "to buy the rackets)")
            }),
            CHOICE("dollar store", [](){
                MC("maybe we can find", "something small at", "the dollar store?")
                MC("after all, if you", "always doing things", "that didn't cost", "money")
                MC("maybe you'll find", "something there that", "will remind you of", "a fun event")
                RIKA("sure, let's take a look")
                EMPTY("(you take a short walk", "to the dollar store)")
                SCENE_END
                BG_DOLLAR_SHOP
                FADE_IN
                SHOW_RIKA_NORMAL
                RIKA("ahh this brings back", "many memories")
                RIKA("let's see what seasonal", "items they have. There", "are always some", "interesting ones")
                MC("woah check these out!")
                RIKA("aww nice!", "these cups are kinda", "cool, like a tropical", "theme")
                RIKA("yea, let's get these", "maybe a few silly hats", "too")
                MC("haha! like a themed", "party")
                RIKA("yea, we went to a", "couple of those!", "this will work", "perfectly")
                EMPTY("(you head to the front", "to buy the items)")
            })
        )
        RIKA("alright, maybe we can", "look for something else?")
        RIKA("where should we go", "next?")
        MENU(
            CHOICE("pottery", [](){
                MC("what about pottery?", "like mugs and bowls?")
                RIKA("wouldn't be my", "first pick but lets", "take a look")
                EMPTY("(you make your way", "a few doors down)")
                SCENE_END
                BG_POTTERY_SHOP
                FADE_IN
                SHOW_RIKA_NORMAL
                MC("see anything good?")
                RIKA("maybe find something", "with a silly design.", "that or some animals")
                MC("any animals in", "particular?", "like dogs or cats?")
                RIKA("cats would be best")
                EMPTY("(you look a bit more)")
                MC("found one!", "here is one with", "some cats on it!")
                RIKA("oh that's a cute one", "let's get it")
                EMPTY("(you head of up front", "to buy the cat mug)")
            }),
            CHOICE("clothing", [](){
                MC("maybe some clothing?", "what about a new shirt?")
                RIKA("hmm...", "well we can take a", "peek. is there", "a thirft store near?")
                MC("good question...", "let me check")
                EMPTY("(you browser your", "phone for a bit)")
                MC("oh yea! there is", "one close by. though", "its in some alley", "I think")
                RIKA("alright let's check", "it out!")
                EMPTY("(you make your way", "over)")
                SCENE_END
                BG_CLOTHING_SHOP
                FADE_IN
                SHOW_RIKA_NORMAL
                RIKA("hmm let's take a look")
                MC("any particular colors", "or patterns?")
                RIKA("I think anything", "fun or inviting would", "be best")
                RIKA("something that would", "strike up a conversation!")
                MC("ahh got it!")
                EMPTY("(you look some more...)")
                MC("what about this one?", "it has some penguins", "on it")
                RIKA("haha! wonderful!")
                MC("wait...", "really?")
                RIKA("oh yes! we used to", "find silly stuff like", "this all the time")
                RIKA("let's go checkout")
                EMPTY("(you head up front to", "buy the penguin shirt)")
            }),
            CHOICE("chocolate", [](){
                MC("maybe something sweet?", "like chocolate?")
                RIKA("oh sure, easy", "enough. let's go to", "the convenience store")
                RIKA("that should have", "enough selection")
                SCENE_END
                BG_CONVENIENCE
                FADE_IN
                SHOW_RIKA_NORMAL
                MC("hmm, do you think a", "cookie would be better", "than a bar?")
                RIKA("oh man...", "this is hard...", "look how many options", "there are...")
                RIKA("I'm going to close", "my eyes. I'll spin", "around and we'll buy", "the first one I see")
                MC("interesting...", "I like it!")
                EMPTY("(Rika closes her eyes", "and spins around)")
                RIKA("THOSE ONES!")
                RIKA("huh? are these...", "protein bars?")
                MC("hahahahaha")
                RIKA("haha fine, let's just", "go with those!")
            })
        )
        RIKA("nice! I think my", "friend will really", "enjoy these!")
        RIKA("good thing we were", "able to find them this", "fast, looks like", "I gotta head out!")
        MC("wait you're meeting", "them today!?")
        RIKA("hehe...")
        MC("Rika...")
        RIKA("Thanks for your help", MCF("{}!"))
        MC("Thank you for the invite.", "I'll see you at work!")
        RIKA("later!")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Rika has billiards tournament at the bar
    void rika_emergency_prompt_2() {
        RIKA_TEXT(MCF("hey, {}!"), "I am running late", "for a billiard tournament")
        RIKA_TEXT("would you be able", "to fill in for me?")
    }
    //! \brief internal
    bool rika_emergency_2_leave_early;
    //! \brief head to the bar for the billiards game
    void rika_emergency_2() {
        SCENE_END
        MC("sure, so where should", "I go, exactly?")
        RIKA_TEXT("I'll send the address", "its a bar close to", "work")
        MC("alright, and who do", "I talk to when I", "get there?")
        RIKA_TEXT("You'll be looking for", "someone named Stella.")
        RIKA_TEXT("don't worry, she'll go", "easy if you want", "her to")
        RIKA_TEXT("but she's a real", "professional! I've warned", "you!")
        MC("haha sounds good.", "I'll head out now!")
        RIKA_TEXT(MCF("thanks {}!"), "I should get there", "in an hour. just busy", "with other things")
        MC("see you then!")
        EMPTY("(you make your way", "to the bar)")
        SCENE_END
        BG_BAR
        FADE_IN
        MC("ok, now to find Stella")
        EMPTY("(you take a look", "around, there aren't", "many people here)")
        SHOW_STELLA
        STELLA("hey there", MCF("are you {}?"))
        MC("oh hello", "yes, I am")
        MC("are you Stella?")
        STELLA("that's me!", "so you ready to play?")
        MENU(
            CHOICE("sort-of", [](){
                MC("uhm... sort-of")
                STELLA("oh, have you not", "played before?")
                MC("well, not a real game.", "just with friends a", "few times")
                STELLA("that's alright, I", "know Rika had some", "errands to run")
                STELLA("there isn't any", "pressure, by the way")
                STELLA("our league just needs", "scores and Rika mostly", "likes to talk, hehe")
                MC("haha sounds good", "let's get it started!")
            }),
            CHOICE("bring it on!", [](){
                MC("oh yea!", "bring it on!")
                STELLA("haha I like your", "style. let's see what", "you've got!")
            })
        )
        STELLA("First, hit this ball", "and try and get it", "close to the rail")
        STELLA("this is to see", "who gets to break")
        MC("here goes nothing...")
        MENU(
            CHOICE("direct hit", [](){
                EMPTY("(you smash the ball", "with most of your power)")
                STELLA("haha look at that!", "are you nervous?")
                MC("just getting some", "steam out before I", "need to focus")
            }),
            CHOICE("purposeful hit", [](){
                EMPTY("(you purposefully hit", "the ball...)")
                STELLA("pretty close!")
                MC("well, could have", "been worse...")
            }),
            CHOICE("dainty hit", [](){
                EMPTY("(you daitily hit the", "ball, it doesn't make", "it halfway)")
                STELLA("want to try again?")
                MC("no, that's alright...")
            })
        )
        STELLA("alright, looks like", "I'll break")
        EMPTY("(Stella racks the balls...)")
        EMPTY("(and sends out a powerful", "break)")
        STELLA("wow, I'm a bit off", "today.")
        STELLA("looks like I got", "one stipe in. That", "means you're solids")
        MC("got it")
        EMPTY("(Stella targets a", "ball across the table...")
        EMPTY("(...and the richochet", "barely misses the pocket!)")
        STELLA("sheesh look at me!", "washed up in the", "first game *sigh*")
        MC("now's my chance!")
        MENU(
            CHOICE("close ball", [](){
                MC("if the target ball is", "closer, I probably", "won't make a mistake")
                EMPTY("(you take aim)")
                MC("here goes nothing!")
                EMPTY("(you score it! nice!)")
                MC("whoo!")
                STELLA("hey not bad!", "let's see if you", "can keep it up!")
                MC("alright, just one", "more and I'll be", "on a roll!")
                EMPTY("(you take aim again)")
                MC("please!")
                EMPTY("(you barely miss the", "second shot)")
                STELLA(MCF("not bad, {}"))
            }),
            CHOICE("half table ball", [](){
                MC("that one is halfway", "maybe it'll set me", "up for the next play")
                EMPTY("(you take aim)")
                MC("this is it!")
                EMPTY("(you miss by a hair.", "darn!)")
                MC("oh no!")
                STELLA(MCF("next time, {}"))
            }),
            CHOICE("full table ball", [](){
                MC("there, the one all", "the way at the end")
                EMPTY("(you take aim)")
                MC("I've got this!")
                EMPTY("(you miss by an", "embarassing amout)")
                MC("OH NO!")
                STELLA("BAHAHA", "looks like there", "is still hope for me!")
            })
        )
        STELLA("alright, let's see", "what I can do")
        EMPTY("(Stella takes a look", "up and down the table)")
        STELLA("this one will work")
        EMPTY("(She takes aim and", "expertly sinks the second", "ball)")
        STELLA("whoo here we go!")
        EMPTY("(and hour passes and", "Stella beats you several", "games in a row")
        STELLA("what do you say", MCF("{}?"), "want to put some money", "on the next one?")
        MC("uhm...")
        RIKA("hold it!")
        MC("Rika!")
        SHOW_RIKA_NORMAL
        RIKA("do NOT bet against", "Stella. I've already", "lost enough over these", "years...")
        SHOW_STELLA
        STELLA("HAHAHA! and how many", "drinks have I bought", "you?")
        SHOW_RIKA_NORMAL
        RIKA("hey, it was my money", "so it's basically my", "drink")
        SHOW_STELLA
        STELLA("yea, WAS your money")
        SHOW_RIKA_NORMAL
        RIKA("*sigh*")
        RIKA("Thanks for filling", "in for me. Don't", "worry about the", "performance")
        RIKA("I'm glad you could", "make it. Hopefully", "it was a fun few", "games")
        MC("well...", "I'm learning!")
        SHOW_STELLA
        STELLA("that's the spirit!")
        STELLA("alright, Rika", "let's wrap this up.", "only two more games", "left in the set")
        SHOW_RIKA_NORMAL
        RIKA("alright, let's get", "it done!")
        EMPTY("(Rika and Stella wrap", "up the next two games.", "Rika is able to win", "only one of them)")
        RIKA("that's a wrap", "what was the final", "score?")
        SHOW_STELLA
        STELLA("4-1")
        SHOW_RIKA_NORMAL
        RIKA("well that's fine", "with me.")
        RIKA(MCF("{}, want"), "to hang around here", "a bit longer?")
        MENU(
            CHOICE("sure", [](){
                MC("sure, I'll stick", "around for a bit")
                SHOW_STELLA
                STELLA("well, I'M going to", "head out. Thanks for", MCF("the games, {}"))
                MC("thanks for letting", "me play, Stella.", "see you around")
                SHOW_RIKA_NORMAL
                RIKA("see ya, Stella")
                EMPTY("(Stella packs up", "her things and leaves)")
                rika_emergency_2_leave_early = false;
            }),
            CHOICE("no thanks", [](){
                MC("I am going to head", "back home. I am", "feeling a bit", "tired")
                RIKA("all good, thanks", "for filling in", "for me!")
                MC("take care, Rika", "see you, Stella!")
                SHOW_STELLA
                STELLA(MCF("see ya, {}"))
                rika_emergency_2_leave_early = true;
            })
        )
        if(rika_emergency_2_leave_early) {
            SCENE_END
            MC("(that went well)")
            return;
        }
        RIKA("alright, let me", "grab us some drinks")
        HIDE
        EMPTY("(Rika heads to the bar", "and returns with a", "pitcher of beer)")
        SHOW_RIKA_NORMAL
        RIKA("here's a glass for you.", "cheers!")
        MC("cheers!")
        RIKA(MCF("so {}..."))
        RIKA("the reason I was", "running late...")
        if(state::st.wke_state.story_progress[character::RIKA] >= 3) {
            RIKA("well, you already", "know about my sister", "right?")
            MC("yea, you told me", "the other week")
            RIKA("ahh ok. well she", "isn't doing very well", "at the moment")
            RIKA("I'm trying my best", "to help her out", "but it isn't easy...")
        } else {
            RIKA("so I have a younger", "sister...")
            RIKA("and...", "how should I put", "this...")
            RIKA("well she's living with", "me now. Basically", "she having a hard", "time getting work...")
            RIKA("she's had a few", "jobs over the past year", "but nothing seems to", "stick")
            RIKA("I'm trying my best", "to keep her hopes", "up but it really", "isn't easy")
        }
        RIKA("anyway, we don't have", "to get deep into it", "now...")
        MENU(
            CHOICE("I'm here if you need", [](){
                MC("If you ever need someone", "to talk to, even for", "something small, you", "can count on me")
                RIKA(MCF("thanks {}"))
                RIKA("I really want things", "to get better for her...")
                RIKA("but its easy to", "lose faith when things", "get bad...")
            }),
            CHOICE("what can I do?", [](){
                MC("is there any way", "I can help out?")
                if(state::st.wke_state.story_progress[character::KANADE] < 3
                    && state::st.wke_state.story_progress[character::KANADE] < 2
                    && state::st.wke_state.story_progress[character::RIN] < 1
                ) {
                    RIKA("well...", "maybe talk to others", "and see if they", "have ideas")
                    RIKA("I'm sure someone at", "work has had a", "a similar situation")
                    MC("ok, I'll keep a", "look out for any", "clues that might help")
                } else {
                    RIKA("nothing I can", "think of now.")
                    RIKA("I'll keep thinking and", "maybe something will", "come up...")
                }
            })
        )
        RIKA("well then...")
        RIKA("did you enjoy", "playing billiards?")
        MC("yea, it was alright", "though I am a bit", "sad I didn't win", "any of the games")
        RIKA("aww it's alright.", "we can practice if", "you're ever interested")
        RIKA("I'm not the best", "myself, but maybe I", "could show you a", "few things")
        RIKA("if you can beat Stella", "once, that's all that", "matters!")
        RIKA("the look on her", "face when she loses...", "hehe")
        MC("so she won some", "money off you earlier?")
        RIKA("oh... that...", "haha yea I'm a sore", "loser...")
        RIKA("and I think she found", "a way to exploit that...", "but its still fun")
        RIKA("I think it makes the", "game more interesting", "though it only works", "'cause I know her")
        MC("ahh I see. so you", "wouldn't bet with someone", "you didn't know?")
        RIKA("no, I don't think", "so... well...", "maybe?")
        MC("haha that's alright")
        EMPTY("(you and Rika hang", "out for a little while", "longer)")
        RIKA("alright, I'm going to", "head back home!", "I have some work I need", "to get back to")
        RIKA("thanks again!")
        MC("see ya Rika!")
        RIKA(MCF("later, {}!"))
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief Rika wants to have a game night with friends
    void rika_emergency_prompt_3() {
        RIKA_TEXT(MCF("yo {}"), "are you interested", "in a game night", "at my place?")
    }
    //! \brief We head over to hang out with Rika
    void rika_emergency_3() {
        SCENE_END
        MC("can you send your", "address over?")
        RIKA_TEXT("sure, give me a", "second")
        CELL_PHONE_BUZZ
        RIKA_TEXT("there you go!", "Try to come over in", "an hour or so")
        MC("got it, see you then!")
        EMPTY("(you wait a bit", "and then head over)")
        SCENE_END
        BG_RIKAS_HOUSE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA(MCF("hey {}"), "glad you could make it!")
        MC("thanks for the invite")
        MC("oh is that Stella?")
        SHOW_STELLA
        STELLA(MCF("oh hey {}"), "nice to see you again!")
        MC("finally!", "time for revenge!")
        STELLA("haha we'll see about", "that")
        SHOW_IRENE
        IRENE("Hello there", "I'm Irene!")
        MC("hey Irene!")
        MC("so how do you know", "Rika?")
        IRENE("oh from a long while", "back! we went to", "school together")
        IRENE("it's so easy to forget", "it feels like ages ago!")
        SHOW_RIKA_NORMAL
        RIKA("haha yea...")
        MC("oh! you're th-")
        RIKA("ALRIGHT! let's get", "this game night started!")
        RIKA("I borrowed a few games", "from someone in the", "office")
        RIKA("let's see...", "we've got...")
        RIKA("a social one and", "a dice one")
        RIKA("which one should we", "play?")
        MENU(
            CHOICE("social one", [](){
                MC("how about the social", "one?")
                MC("We don't really know", "much about each other.", "wouldn't that help", "break the ice?")
                SHOW_STELLA
                STELLA("you have a point", MCF("{}..."))
                SHOW_IRENE
                IRENE("I'm fine with either one")
                SHOW_RIKA_NORMAL
                RIKA("well, I guess that", "leaves me...")
                RIKA("let's play the dice", "game")
                RIKA("I think it will be", "easier to pick up")
                RIKA("plus, we're still talking", "so we don't really lose", "out on the social side", "of things")
                RIKA("well, unless Stella", "starts to lose, then", "we'll be down a person.", "hehe")
                SHOW_STELLA
                STELLA("if *I* lose??", "bring it on, Rika!", "I'll win at any game!", "even chance!")
                MC("hahaha")
                SHOW_IRENE
                IRENE(" haha")
                SHOW_RIKA_NORMAL
                RIKA("ok sounds like we're", "ok with the dice one")
            }),
            CHOICE("dice one", [](){
                MC("I vote for the dice", "one!")
                SHOW_STELLA
                STELLA("I second the vote", "for the dice one!")
                SHOW_IRENE
                IRENE("I'm ok with either", "one")
                SHOW_RIKA_NORMAL
                RIKA("alright then, the", "dice game it is!")
            })
        )
        RIKA("here is the gist of", "the game: you are trying", "to roll doubles")
        RIKA("there are these other", "dice that you roll, too")
        RIKA("they have a different", "effect on your score.", "some will double your", "score")
        RIKA("and some will subtract", "from your score")
        RIKA("I know it sounds", "complicated but there are", "only four special dice", "types")
        RIKA("you'll get the hang", "of it after a few rounds")
        SHOW_IRENE
        IRENE("can we have a practice", "round? or two?")
        SHOW_STELLA
        STELLA("are there teams? I", "don't want to get stuck", "with you, Rika")
        SHOW_RIKA_NORMAL
        RIKA("yes, we can have a", "practice round. and no,", "there aren't teams...")
        RIKA("though, I suppose we", "could take turns tossing", "the dice which almost", "works as a team")
        SHOW_IRENE
        IRENE("I'll be on", MCF("{}'s team!"))
        SHOW_STELLA
        STELLA("no way! I'll take", MCF("{}"))
        SHOW_STELLA
        RIKA("hold on!", MCF("{}, do"), "you have someone you", "want to pair with?")
        MC("oh I-")
        EMPTY("(a bedroom door creaks", "open)")
        EMPTY("(she pops her head", "over the door frame)")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("what-", "what is going on", "out here?")
        SHOW_RIKA_NORMAL
        RIKA("oh hey, Selene", "you want to join us?")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("uhm...")
        SHOW_STELLA
        STELLA("come on out!", "we're pretty cool,", "ya kno!")
        SHOW_IRENE
        IRENE("hello Selene")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("oh... hi")
        EMPTY("(Rika's sister comes", "out of her room)")
        SHOW_RIKA_NORMAL
        RIKA("oh! Selene knows", "how to play!")
        RIKA("how about this: Me and", "Irene against you three.", "sound fair?")
        SHOW_STELLA
        STELLA("well, it's only fair", "if I win!")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("... hehe")
        SHOW_RIKA_NORMAL
        RIKA("Stella... *sigh*")
        RIKA("alright, you're team", "can go first. Selene,", "do you want to", "roll first?")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("uhm... ok")
        EMPTY("(Selene rolls the dice)")
        SHOW_STELLA
        STELLA("so... did we win!?")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("no we...", "only got five points")
        SHOW_RIKA_NORMAL
        RIKA("we'll go next.", "here, give 'em a toss,","Irene")
        SHOW_IRENE
        IRENE("oh... I just throw", "them? on the table?")
        SHOW_RIKA_NORMAL
        RIKA("haha yes, shake 'em", "up and give 'em a toss!")
        SHOW_IRENE
        IRENE("here I go!")
        EMPTY("(the dice go everywhere)")
        SHOW_STELLA
        STELLA("did... did she win?")
        SHOW_RIKA_NORMAL
        RIKA("Stella! the game", "takes a few turns")
        SHOW_STELLA
        STELLA("r- right...")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("... hehe")
        SHOW_RIKA_NORMAL
        RIKA("I think we got...")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("twenty points")
        SHOW_RIKA_NORMAL
        RIKA("right... thank you!", "Your team's up!")
        SHOW_STELLA
        STELLA("let's see what a", "pro can do!")
        EMPTY("(Stella shakes the dice", "with heroic energy)")
        STELLA("HEEYAA")
        SHOW_RIKA_NORMAL
        RIKA("Oh. WOW!")
        SHOW_STELLA
        STELLA("WHA-", "DI- DID I WIN!?")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("uhm...")
        SHOW_RIKA_HAPPY
        RIKA("BAHAHAHA that's a", "minus one hundred")
        SHOW_STELLA
        STELLA("ONE HUNDRED!", "N- NO!", "H- How...?")
        SHOW_RIKA_NORMAL
        RIKA("I'll take those...")
        EMPTY("(Rika starts shaking", "the dice)")
        RIKA("here we... GO!")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("BAHAHAH")
        SHOW_STELLA
        STELLA("please, don't say...")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("maybe try a bit", "harder next time, Rika")
        SHOW_RIKA_NORMAL
        RIKA("*grr*")
        SHOW_IRENE
        IRENE("how much did we", "get?")
        SHOW_RIKA_NORMAL
        RIKA("*sigh*")
        RIKA("it's a minus two", "hundred")
        SHOW_IRENE
        IRENE("oh no! well...", "maybe next time!")
        SHOW_RIKA_NORMAL
        RIKA(MCF("alright, {}"), "you next")
        MC("alright, let's not", "mess this up!")
        SHOW_STELLA
        STELLA("maybe a quick prayer?")
        MENU(
            CHOICE("hum", [](){
                MENU(
                    CHOICE("wari", [](){
                        MENU(
                            CHOICE("rum", [](){}),
                            CHOICE("dum", [](){}),
                            CHOICE("woo", [](){})
                        )
                    }),
                    CHOICE("diddly", [](){
                        MENU(
                            CHOICE("dum", [](){}),
                            CHOICE("doo", [](){}),
                            CHOICE("bam", [](){})
                        )
                    }),
                    CHOICE("tum", [](){
                        MENU(
                            CHOICE("bah", [](){}),
                            CHOICE("tum", [](){}),
                            CHOICE("dum", [](){})
                        )
                    })
                )
            }),
            CHOICE("ooo", [](){
                MENU(
                    CHOICE("shaka", [](){
                        MENU(
                            CHOICE("rum", [](){}),
                            CHOICE("dum", [](){}),
                            CHOICE("woo", [](){})
                        )
                    }),
                    CHOICE("ooo", [](){
                        MENU(
                            CHOICE("dum", [](){}),
                            CHOICE("ooo", [](){}),
                            CHOICE("bam", [](){})
                        )
                    }),
                    CHOICE("toot", [](){
                        MENU(
                            CHOICE("ooo", [](){}),
                            CHOICE("toot", [](){}),
                            CHOICE("beep", [](){})
                        )
                    })
                )
            }),
            CHOICE("I", [](){
                MENU(
                    CHOICE("choose", [](){
                        MENU(
                            CHOICE("you", [](){}),
                            CHOICE("victory", [](){}),
                            CHOICE("this", [](){})
                        )
                    }),
                    CHOICE("will", [](){
                        MENU(
                            CHOICE("win", [](){}),
                            CHOICE("lose", [](){}),
                            CHOICE("...", [](){})
                        )
                    }),
                    CHOICE("uhm...", [](){
                        MENU(
                            CHOICE("...", [](){}),
                            CHOICE("...", [](){}),
                            CHOICE("...", [](){})
                        )
                    })
                )
            })
        )
        EMPTY("(you throw the dice", "on the table)")
        SHOW_RIKA_NORMAL
        RIKA("nice!")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("good job,", MCF("{}!"))
        MC("how did I do?")
        RIKAS_SISTER("fifty points!")
        MC("oh cool!")
        SHOW_STELLA
        STELLA("*scoff*", "I could'a done that!")
        SHOW_RIKA_NORMAL
        RIKA("alright, maybe we", "can take a break", "for a bit")
        RIKA("let me get us something", "to drink")
        SHOW_IRENE
        IRENE("oh, I can help!")
        SHOW_STELLA
        STELLA("I'm not letting a", "loser pick my drink")
        SHOW_RIKA_NORMAL
        RIKA("haha alright, let's see", "what we've got")
        HIDE
        EMPTY("(the group heads", "into the kitchen)")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("oh... hey", MCF("{}"))
        MC("hey Selene", "quite the game, right?")
        RIKAS_SISTER("oh.. yea")
        RIKAS_SISTER("hey... uhm...")
        RIKAS_SISTER("you talked with Rika", "about me recently, right?")
        MC("oh... yes she mentioned", "you were... uhm", "looking for work,", "was it?")
        RIKAS_SISTER("well... yes...", "sort of...")
        MC("I'll be honest, I'm", "not really sure I'm", "qualified to help")
        MC("I've only just graduated", "and am barely scraping", "by at work...")
        RIKAS_SISTER("well Rika mentioned", "that...")
        RIKAS_SISTER("she was glad she", "met you!")
        MC("!!!")
        MC("me?")
        RIKAS_SISTER(MCF("you're {},"), "right?")
        MC("well yes...")
        RIKAS_SISTER("then I am absolutely", "sure! she is really", "glad to have met you")
        RIKAS_SISTER("I overheard one of", "her conversations earlier")
        MC("isn't that-")
        RIKAS_SISTER("Rikas is....", "loud!")
        MC("oh haha", "I understand")
        RIKAS_SISTER("she was talking to", "someone...", "probably Irene...")
        RIKAS_SISTER("and I didn't quite", "understand the whole", "thing...")
        RIKAS_SISTER("but she made it sound", "like she has all this", "new energy")
        RIKAS_SISTER("'oh there is this", "cool new person at work'", "'it's like when we", "first met!'")
        MC("*sniff*")
        RIKAS_SISTER("I know my life isn't", "really put together...")
        RIKAS_SISTER("but talking and keeping", "Rika happy...", "well...")
        RIKAS_SISTER("it's just like helping", "me out! If she's happy,", "then I'm happy...")
        RIKAS_SISTER("so I wanted to thank", "you... for being there", "for Rika!")
        MENU(
            CHOICE("thank you", [](){
                MC("thank you for sharing", "that")
                MC("I don't really think", "twice about things with", "Rika...", "haha...")
                MC("I guess we just fit", "well together?")
            }),
            CHOICE("*sob*", [](){
                MC("*waaaaaaaah*", "*sniff*")
                RIKAS_SISTER("there there")
                EMPTY("(Selene embraces you)")
            })
        )
        SHOW_RIKA_NORMAL
        RIKA("hey, is everything", "alright in here?")
        RIKA(MCF("woah, {}"), "are you ok?")
        MC("yes I'm... fine.")
        MENU(
            CHOICE("non-confrontational", [](){
                MC("you're sister was", "telling me a funny", "story")
                RIKA("but... you look", "like you're crying?")
                MC("did I say funny?", "hahaha...", "oops")
                SHOW_RIKA_HAPPY
                RIKA("HAHAHA", MCF("oh {}"))
                RIKA("well, whatever it was", "I'm sure it was", "important")
                SHOW_RIKA_NORMAL
                RIKA("do you.. want to", "get back to playing,", MCF("{}?"))
                MC("oh, sure, yes")
            }),
            CHOICE("confrontational", [](){
                MC("well... Selene was", "saying she overheard you", "the other day")
                RIKA("Selene!")
                SHOW_RIKAS_SISTER
                RIKAS_SISTER("I'm sorry...", "you...", "talk loudly so it's", "hard to tune out")
                SHOW_RIKA_NORMAL
                RIKA("well... I'm not really", "one to keep secrets")
                RIKA("but yea, you've been", "on my mind a bit", MCF("{}"))
                RIKA("I was talking about", "it with Irene after", "the party...")
                RIKA("and I guess I never", "got around to telling", "you")
                SHOW_RIKA_HAPPY
                RIKA("but yea, things", "have been better with", "you around")
                RIKA("me, Selene, ...", "well, all of us!")
                MC("aww here I go again", "*sniff*")
                RIKA("haha just be yourself!")
                EMPTY("(Rika gives you a pat", "on the back)")
                SHOW_STELLA
                STELLA(MCF("woah {}"), "did you just lose", "against Selene?")
                SHOW_RIKA_NORMAL
                RIKA("no, you goofball...")
                SHOW_STELLA
                STELLA("looks like we need", "a little one versus one")
                SHOW_RIKA_NORMAL
                RIKA("want to get back", "to the game", MCF("{}?"))
                MC("sure... let's", "get back to it!")
            })
        )
        SCENE_END
        vnlib::end(vnlib::GOOD_END);
    }

    /*
     * Rin Emergency
     */
    //! \brief Rin is playing games, get her some snacks
    void rin_emergency_prompt_0() {
        RIN_TEXT("yo I could really", "use some chips", "could you fetch me", "some??")
    }
    //! \brief Rin plays some Bosco Party if you bring something over (alcohol or chips)
    void rin_emergency_0() {
        MC("first things first", "let me find out which", "brand Rin wants")
        MC("text: Rin, which brand", "would you like?")
        MC("I'll head to the store", "now and wait for a", "response...")
        EMPTY("(you head out...)")
        BG_CONVENIENCE
        MC("alright, let's see", "what she said...")
        MC("hmm...")
        MC("weird, maybe she didn't", "get a notification...")
        MC("I guess I'll give her", "a call")
        CELL_PHONE_BUZZ
        RIN("yes?")
        MC("hello, Rin?", "I'm at the store now", "do you-")
        RIN("ONE. SECOND.")
        MC("uhm-")
        RIN("I am really", "wrapped up in a", "game right now")
        RIN("so let's make this", "quick")
        MC("which chips, Rin?")
        RIN("triangles")
        MC("ok I'll get the", "triangle ones-")
        RIN("quick. quick. quick.")
        MC("text your address")
        RIN("done. done. done?")
        MC("yes. done")
        RIN("ok later")
        EMPTY("(Rin ends the call)")
        MC("...")
        MC("might as well see", "this through...")
        MC("ok, which triangles", "should I grab?")
        MENU(
            CHOICE("cheezy triangles", [](){
                MC("cheezy ones should do", "isn't this the most", "popular flavor?")
                RIN_TRIANGLE_CHIP = main_character_state::cheezy_triangles;
            }),
            CHOICE("cool triangles", [](){
                MC("the cool ones?", "these look pretty", "good")
                RIN_TRIANGLE_CHIP = main_character_state::cool_triangles;
            }),
            CHOICE("fire triangles", [](){
                MC("worst case she hates", "and I end up eating", "them... well not", "exactly ~that bad")
                RIN_TRIANGLE_CHIP = main_character_state::fire_triangles;
            })
        )
        MC("you know what...", "should I grab some", "alcohol while I'm at it?")
        MENU(
            CHOICE("no", [](){
                MC("nah... no way.", "no way that will make", "things better...")
                RIN_ALCOHOL_PREP = main_character_state::none;
            }),
            CHOICE("yes - beer", [](){
                MC("why not? this should", "do the trick if things", "turn ugly")
                RIN_ALCOHOL_PREP = main_character_state::beer;
            }),
            CHOICE("yes - vodka", [](){
                MC("hmm this might be", "the best and worst idea.", "sure!")
                RIN_ALCOHOL_PREP = main_character_state::vodka;
            })
        )
        MC("alright, lets buy", "these and head over")
        EMPTY("(you head up front", "to purchase the items.", "surprisingly, Rin sent", "you her address)")
        SCENE_END
        FADE_OUT
        BG_RINS_APARTMENT_DOOR
        FADE_IN
        MC("well there's no", "doorbell. time for the", "old fashioned knock")
        MC("(knock knock)", MCF("Rin? It's {}"), "are you there?")
        EMPTY("...")
        MC("I'll text her and", "wait here...")
        for(int i = 0; i < 10; i++) {
            EMPTY("(you wait)", FMT_24("{}/10", i))
        }
        MC("alright, well she's", "clearly busy...")
        MC("should I eat the", "chips?")
        MENU(
            CHOICE("no", [](){
                MC("ehh, on second thought", "let's skip that...")
                RIN_MAYBE_EAT_CHIPS = main_character_state::saved_the_chips;
            }),
            CHOICE("yes", [](){
                MC("yea I am just", "going to eat these", "things...")
                RIN_MAYBE_EAT_CHIPS = main_character_state::ate_the_chips;
            })
        )
        if(RIN_ALCOHOL_PREP != main_character_state::none) {
            MC("I am definitely going", "to crack this one", "open, too")
            EMPTY("(you take a swig", "of alcohol)")
        }
        MC("I guess the only", "thing left to do is", "play something on", "my phone...")
        EMPTY("(you open your phone", "and browse Zwitter", "for a bit)")
        MC("ok one more sip")
        EMPTY("*gulp*")
        EMPTY("(you go back to", "browsing Zwitter)")
        MC("hahahahaha there are", "some funny people on", "this app...")
        EMPTY("(the front door opens)")
        SHOW_RIN_NORMAL
        RIN("what...", "in the world are", "you doing here?")
        MC("Rin, you asked for", "some chips. Don't you", "remember?")
        RIN("oh some chips...", "did you get the", "triangle ones?")
        if(RIN_MAYBE_EAT_CHIPS == main_character_state::saved_the_chips) {
            MC("yea, I almost ate them.", "Good thing you decided", "to show up...")
            RIN("*hmph*")
            MC("here, take them")
            switch(RIN_TRIANGLE_CHIP) {
            case main_character_state::cheezy_triangles:
                RIN("yea I usually get", "the cool ones")
                RIN("but these cheezy ones", "will do...")
                break;
            case main_character_state::cool_triangles:
                RIN("how did you know I", "like the cool ones?")
                MC("I didn't know...", "just a good guess")
                RIN("*hmph*")
                break;
            case main_character_state::fire_triangles:
                RIN("the legendary fire", "triangles...", "ok, they'll do")
                RIN("not my first pick.", "the cool ones would", "have been better.")
                break;
            default: break;
            }
        } else {
            MC("well, I don't have", "them anymore.", "I think I dropped", "them on the way here")
            RIN("you 'dropped' them?", "is that what that", "empty bag is from?")
            MC("empty bag?", "oh...")
            if(RIN_ALCOHOL_PREP == main_character_state::none) {
                RIN("we'll if you're here", "empty handed, might", "as well head back", "home...")
                //! \rin_maybe doesn't have time for useless people
                RIN("I don't have time", "for useless people")
                EMPTY("(Rin goes back inside)")
                MC("...")
                state::st.rel_state.reset(character::RIN);
                return;
            } else if (RIN_ALCOHOL_PREP == main_character_state::beer) {
                RIN("how many more beers", "do you have?")
                MC("most of them")
                RIN("alright, give me one")
                MC("here...")
                EMPTY("(Rin cracks the beer can)")
                RIN("ahhh!", "(a rare sigh of relief)")
            } else if (RIN_ALCOHOL_PREP == main_character_state::vodka) {
                RIN("well, you did get one", "thing right...")
                RIN("give me that")
                MC("what?")
                EMPTY("(Rin takes the vodka", "from the ground,", "taking a swig)")
                RIN("BLEH", "is there something", "wrong with you??")
                MC("Rin, that bottle is", "clearly labelled...")
                EMPTY("(she takes another", "swig)")
                RIN("...")
                RIN("ahhh!", "(a rare sigh of relief)")
            }
        }
        RIN("alright, well you", "didn't come here for", "nothing...")
        RIN("come inside and we", "can play some games.", "but only for a", "half hour or so")
        MC("alright, let's go")
        EMPTY("(you make your way", "inside)")
        SCENE_END
        BG_RINS_ROOM
        FADE_IN
        SHOW_RIN_NORMAL
        MC("so what game are", "we playing?")
        RIN("well I have no idea", "how good you are", "at games. so probably", "something easy")
        RIN("here, let's try", "Bosco Party 5")
        MC("so... how good are", "you at this game?")
        RIN("well the game is", "based on chance so", "there isn't much I", "can do to win")
        //! \rin will destroy us at Bosco Party 5 mini-games
        RIN("but I will definitely", "destroy you at these", "mini-games")
        MC("alright, let's see", "about that")
        // game one: jump up the rop
        RIN("alright this first game", "is one where you jump", "up a big plant.")
        RIN("you hit the key on", "the side that the", "leaf is one")
        MC("... ok")
        RIN("alright, let's start!")
        MC("... but")
        int successes = 0;
        auto rng = bn::random();
        for(int i = 0; i < 10; i ++) {
            auto key = bn::keypad::key_type::LEFT;
            if(rng.get_unbiased_int(4) > 2) {
                key = bn::keypad::key_type::RIGHT;
                GAME(FMT_24("RIGHT! {}/10", i))
            } else {
                GAME(FMT_24("LEFT! {}/10", i))
            }
            if(minigame_bugs::round(key)) {
                successes += 1;
            }
        }
        if(successes == 10) {
            MC("wow I actually won!", "no way!")
            RIN("You little punk!", "You just got lucky.", "I'll wipe that smile", "off in no time.")
        } else {
            SHOW_RIN_HAPPY
            MC("darn, you won...")
            RIN("*hpmh*", "I'd expect nothing less")
            SHOW_RIN_NORMAL
        }
        RIN("alright, next game", "is one where you", "spin the stick", "as fast as you can")
        RIN("got it?", "let's start")
        auto timer = bn::timer();
        timer.restart();
        int times = 5;
        for(int i = 0; i < 5; i++) {
            GAME(FMT_24("UP! {}/{}", i, times))
            minigame_bugs::round(bn::keypad::key_type::UP);
            GAME(FMT_24("RIGHT! {}/{}", i, times))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
            GAME(FMT_24("DOWN! {}/{}", i, times))
            minigame_bugs::round(bn::keypad::key_type::DOWN);
            GAME(FMT_24("LEFT! {}/{}", i, times))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
        }
        auto ticks = timer.elapsed_ticks();
        // EMPTY(FMT_24("final time: {}", ticks))
        if(ticks <= 6) {
            MC("no way, did I just", "win?")
            RIN("did you play before", "you came here?", "*hmph*")
        } else {
            SHOW_RIN_HAPPY
            MC("darn, I was", "so close too!")
            RIN("HA HA", "eat dirt")
            SHOW_RIN_NORMAL
        }
        RIN("ok that's it for", "today, maybe we can play", "more some other time")
        MC("sure, that would", "be cool")
        if(RIN_MAYBE_EAT_CHIPS == main_character_state::saved_the_chips) {
            RIN("oh and...", "thanks for the chips")
            MC("you're welcome")
        } else {
            RIN("maybe try not to", "eat the chips next time")
            MC("ok, I'll save a few")
        }
        MC("alright, I'll catch", "you later")
        RIN("bye.")
        SCENE_END
        MC("(I think that went", "well. I can't tell", "with her...)")
    }
    //! \brief Rin is playing games, get her a slice of pizza
    void rin_emergency_prompt_1() {
        RIN_TEXT("yo, newbie!", "want to get me some", "pizza?")
    }
    //! \brief Pizza (Bosco Party but no mini games)
    void rin_emergency_1() {
        MC("Rin what toppings", "do you want?")
        RIN_TEXT("anything.")
        MC("...")
        MC("alright, guess I'll get", "one large anything", "pizza...", "*scoff*")
        EMPTY("(you head to the", "pizza place)")
        SCENE_END
        BG_PIZZA_PLACE
        FADE_IN
        MC("alright, let's see.", "what should I get?")
        MENU(
            CHOICE("everything", [](){
                MC("this is as close to", "'anything' as you", "can get")
                MC("I mean, you could", "pick things off that", "you don't like, right?")
                RIN_PIZZA = main_character_state::everything_pizza;
            }),
            CHOICE("cheese", [](){
                MC("I mean, it has the", "least amount of 'anything'")
                MC("but how can you ask", "for pizza and not", "want cheese?")
                RIN_PIZZA = main_character_state::cheese_pizza;
            }),
            CHOICE("meat lovers", [](){
                MC("she probably hasn't", "eaten anything all day.")
                MC("besides, this is", "basically an 'anything'", "pizza, right?")
                RIN_PIZZA = main_character_state::meat_lovers_pizza;
            })
        )
        EMPTY("(you head to the", "counter to order,", "and wait for the pizza)")
        MC("ok, pizza is all done", "let's head over")
        MC("I should text Rin so", "this thing doesn't get", "cold")
        EMPTY("(you head over to", "Rin's apartment)")
        SCENE_END
        BG_RINS_APARTMENT_DOOR
        FADE_IN
        MC("time to call...")
        EMPTY("*ring ring*")
        EMPTY(" *ring ring*")
        EMPTY("*ring ring*")
        EMPTY(" *ring ring*")
        MC("please...")
        EMPTY("*ring ring*")
        EMPTY(" *ring ring*")
        EMPTY("*ring ring*")
        EMPTY(" *ring ring*")
        MC("ok what the heck...")
        EMPTY("(you bang on the door)")
        MC("RIN YOUR PIZZA", "IS HERE")
        EMPTY("...")
        MC("RIN THE PI-")
        EMPTY("(the door opens)")
        SHOW_RIN_NORMAL
        RIN("yes. yes.", "I hear ya.", "come inside.")
        SCENE_END
        BG_RINS_ROOM
        FADE_IN
        SHOW_RIN_NORMAL
        RIN("so what topping", "did you get?")
        //! \rin always eats cheese pizza (family story)
        switch(RIN_PIZZA) {
        case main_character_state::everything_pizza:
            MC("I got an everything one", "do you like this", "one?")
            RIN("well it isn't bad", "but I prefer plain", "cheese")
            MC("you don't find cheese", "a bit boring?")
            RIN("*hmph* it's what", "I am used to, ok?")
            RIN("Plus, they wouldn't", "sell it if no one", "liked it...", "*scoff*")
            break;
        case main_character_state::cheese_pizza:
            MC("I knew I couldn't", "go wrong with cheese")
            RIN("well you definitely got", "lucky...", "I'll eat it.")
            MC("would you rather have", "one with, like, more", "flavor?")
            RIN("no. I've always", "had cheese. this is", "fine.")
            break;
        case main_character_state::meat_lovers_pizza:
            MC("I got the meat lovers.", "are you a fan?")
            RIN("A... 'fan'?", "I mean I'll eat it", "but I would rather", "the cheese one")
            MC("cheese? not even a", "single toppping?")
            RIN("listen, it's what I", "always eat. it's just", "as good as the other", "pizzas.")
            break;
        default: break;
        }
        RIN("nothing to drink", "this time?")
        MC("'nothing to drink\?\?'", "well if you mentioned", "it, I could have", "bought something")
        if(RIN_ALCOHOL_PREP == main_character_state::beer || RIN_ALCOHOL_PREP == main_character_state::vodka) {
            RIN("oh wait, I think I", "still have whatever", "you left last time")
        } else {
            RIN("well water is the only", "thing I have...")
        }
        RIN("I'll got fetch some", "glasses")
        EMPTY("(Rin heads to the", "kitchen for some glasses)")
        MC("so are we playing some", "more games today?")
        RIN("do you want to play", "more games today?")
        MENU(
            CHOICE("yes", [](){
                MC("yes, I think that", "would be fun")
                RIN("alright then...", "what do you want", "to play?")
                MENU(
                    CHOICE("Bosco Party 5", [](){
                        MC("what about the one", "we played last time?", "Bosco Party?")
                        RIN("yeah, I guess we", "could do that...", "*sigh*")
                    }),
                    CHOICE("Puzzles", [](){
                        MC("Do you have any puzzles?")
                        //! \rin_maybe does not enjoy puzzles
                        RIN("PUZZLES? what year is", "it? NO, I don't have", "any puzzles")
                        MC("OK just thought I", "would ask...")
                    }),
                    CHOICE("Fighting Game", [](){
                        MC("do you have any", "1v1 game? maybe a", "fighting game")
                        //! \rin_maybe is very good at fighting games
                        RIN("well I do have a", "few fighting games but", "I would absolutely", "dominate you")
                        RIN("so I see not reason", "to waste time on that")
                    })
                )
                MC("if we aren't playing", "games then what does", "that leave us with?", "any other options?")
                RIN("hmm...")
                MC("maybe we could bake", "a cake?")
                //! \rin_maybe does not like cooking
                RIN("HAHAAH", "there is no way", "you could sign me", "up for that")
                MC("ok what about a word", "game?")
                RIN("what do you mean?")
                MC("like I say a word", "and you say the first", "word that comes", "to mind")
                RIN("hmm... maybe not the", "worst idea.")
                RIN("ok I'll go first")
                RIN("pizza")
                MC("cheese")
                RIN("pizza")
                MC("Rin that is-")
                //! \rin_maybe is short-tempered and impatient
                RIN("yea this game", "definitely sucks")
            }),
            CHOICE("can we talk?", [](){
                MC("can we talk instead?")
                RIN("yea, sure, let's yap", "about something...")
                MC("so how did you end", "up on the security team?")
                RIN("yawn, next")
                MC("favorite game?")
                RIN("ok better, let me", "think. Probably one of", "the games I played", "with my family...")
                RIN("maybe Silvereye 64 or", "one of the Fast and", "Glorious games...")
                MC("have you seen any", "of the Fast and Glorious", "movies?")
                RIN("have I...", "what kind of question", "is that?")
                RIN("YES of course I", "have seen them.", "MULTIPLE times.")
                RIN("it sounds like you", "haven't becuase everyone", "who watched them was", "hooked")
                MC("no, I haven't seen them", "yet")
                RIN("*sigh*")
            })
        )
        RIN("let's just play", "Bosco Party again")
        MC("ok, works for me")
        EMPTY("(you play some more", "Bosco Party for a few", "hours)")
        RIN("I'm getting kinda", "tired.")
        MC("I'll get going", "then")
        RIN("come up with more", "game ideas. something", "challenging, please")
        MC("I'll do some research.", "bye, Rin")
        RIN("later")
        SCENE_END
        MC("(that went well.", "at least better than", "last time)")
    }
    //! \brief Rin is playing games, get her some alcohol from the convenience store
    void rin_emergency_prompt_2() {
        RIN_TEXT("hey Idiot have you", "completed your game", "research yet?")
        RIN_TEXT("also, I am all", "out of alcohol. so please", "bring some over")
    }
    //! \brief head to conveneince store for some alcohol, finally learn more about Rin (SuperCooked 2)
    void rin_emergency_2() {
        MC("alright, let's head to", "the store")
        SCENE_END
        BG_CONVENIENCE
        FADE_IN
        MC("alright, now which one", "should I get?")
        MENU(
            CHOICE("ridgeline ale", [](){
                MC("yea this one will", "be great!")
                RIN_ALCOHOL_PREP_2 = main_character_state::ridgeline_ale;
            }),
            CHOICE("blitz IPA", [](){
                MC("hmm, this might be", "a gamble...")
                RIN_ALCOHOL_PREP_2 = main_character_state::blitz_ipa;
            }),
            CHOICE("summer hefe", [](){
                MC("this sounds pleasant", "maybe she'll like it")
                RIN_ALCOHOL_PREP_2 = main_character_state::summer_hefe;
            }),
            CHOICE("vodka", [](){
                MC("well, maybe it'll work")
                RIN_ALCOHOL_PREP_2 = main_character_state::vodka;
            })
        )
        MC("ok ok")
        MC("SHOOT!")
        MC("I didn't do any", "game research...", "this can't go well")
        SCENE_END
        BG_RINS_APARTMENT_DOOR
        FADE_IN
        MC("ok I'll search the", "web now. with any luck...")
        MC("'best games to play", "with with fussy people'")
        MC("....")
        MC("hmm this one looks", "cool: SuperCooked 2.", "maybe she has that one?")
        EMPTY("(you knock on the door)")
        RIN("yes yes come in")
        SCENE_END
        BG_RINS_ROOM
        FADE_IN
        SHOW_RIN_NORMAL
        MC("here, Rin. I got some", "alcohol. Do you like", "this one?")
        RIN("let's see")
        EMPTY("(Rin opens the bag", "for a second)")
        RIN("yup, that's alcohol. It'll", "be fine.")
        MC("wait, do you not", "have a preference?", "I thought you'd be", "more fussy about it")
        RIN("MORE FUSSY?", "excuse you.")
        MC("I meant-")
        //! \rin sees herself as decisive
        RIN(MCF("{}, listen"), "I may be decisive", "and a bit 'prickly'")
        RIN("but I am definitely", "not fussy. I am only", "picky on things that", "matter")
        RIN("like projects at work", "or people to talk to")
        //! \rin knows she doesn't have lots of energy
        RIN("I don't have unlimited", "energy for a lot of", "things.")
        RIN("maybe it comes across", "weird... ")
        MC("so you really don't", "care about the alcohol?")
        RIN("no I just want to", "drink and play some games")
        RIN("speaking of...")
        RIN("did you do your research?", "find anything cool,", MCF("{}?"))
        MC("I was looking at game", "list on the way from", "the store. I found", "a co-op cooking game")
        MC("its called SuperCooked 2")
        SHOW_RIN_HAPPY
        RIN("HAHAHA I've never tried", "that one. but I have seen", "videos on Zwitter")
        MC("do you own it?")
        RIN("hmm I could get the shop", "I don't usually have", "anyone to play", "with so it isn't")
        RIN("something I would", "normally buy.")
        RIN("let's see...", "yea this isn't too", "expensive")
        SHOW_RIN_NORMAL
        RIN("alright, sit your", "butt down. we're beating", "this tonight")
        MC("beating it? you haven't", "even opened it yet.")
        RIN("I'M SERIOUS. this", "looks like a kids game.", "it should take no time", "at all")
        RIN("well, unless you hold me", "back.")
        RIN("I'm kicking you", "out if you don't pull", "your weight")
        MC("*gulp*", "uhm")
        EMPTY("(Rin slams the controller", "in your lap)")
        RIN("alright, the first", "customer order is in!", "grab the plate!")
        GAME("Grab the plate (RIGHT)")
        minigame_bugs::round(bn::keypad::key_type::RIGHT);
        RIN("now bring it to", "the table!")
        GAME("bring the plate (LEFT)")
        minigame_bugs::round(bn::keypad::key_type::LEFT);
        EMPTY("(the game continues", "as Rin commands", "the virtual kitchen", "to victory)")
        EMPTY("(you are gradually", "getting better, level", "after level!)")
        EMPTY("(an hour passess)")
        EMPTY("(until...)")
        RIN(MCF("{}!! WHAT ARE"), "YOU DOING? WE HAVE", "CUSTOMERS!! DON'T", "JUST STAND THERE")
        MC("I'M PRESSING BUT", "THE BUTTONS AREN'T", "WORKING")
        RIN("great now we", "have to re-do this", "one. just great.")
        MC("I think the controller", "is broken...")
        RIN("Let me see that!")
        RIN("...")
        RIN("oh... I guess", "it is broken...")
        MC("we'll I guess", "I'll head home, then")
        RIN("NO!", "I mean... no.")
        RIN("I don't usually", "get the chance to", "play games in person")
        RIN("at least not anymore...")
        MC("anymore?")
        RIN("well, I...")
        RIN("I used to play", "a lot growing up.")
        //! \rin has a big family
        RIN("I have a big family", "so there was always", "someone around to fight")
        RIN("but ever since college", "and work/life stuff", "started...")
        RIN("well, it isn't easy", "finding people that...", "I want to play with")
        //! \rin misses having people around to casually play with
        SHOW_RIN_HAPPY
        RIN("I guess this game", "made me remember the", "old days, you know?")
        MC("yea I kn-")
        SHOW_RIN_NORMAL
        RIN("here, let me look", "at the controller", "again.")
        MC("yea Rin I hea-")
        RIN("SEE! its the wire!", "you'll be all set.", "just don't move", "at all")
        MC("Rin, maybe we-")
        RIN("maybe we should", "get back to SuperCooked")
        EMPTY("(Rin turns her focus", "back to the and demands", "you serve more virtual", "pizza)")
        EMPTY("(This continues for", "two more hours until", "you nearly fall asleep)")
        MC("alright Rin I need", "to go back home", "I am feeling very tired")
        RIN("I really don't like", "that attitude")
        MC("Rin, I literally can't", "press buttons if I'm", "asleep!")
        RIN("that sounds like a", "skill issue")
        MC("I'll see you on Monday.", "Goodnight Rin.")
        RIN("...but", "ok fine. see you.")
        SCENE_END
        MC("(that went well.", "time to get home safely)")
    }
    //! \brief Rin is sick, cheer her up by buying the correct items
    void rin_emergency_prompt_3() {
        RIN_TEXT("hey I'm feeling a bit", "sick. could you bring", "some food over, please?")
    }
    //! \brief internal
    bool rin_emergency_3_confirmed;
    //! \brief chip confirmation loop
    void rin_emergency_3_chips_loop() {
        rin_emergency_3_confirmed = false;
        while(!rin_emergency_3_confirmed) {
            MC("which chips should I", "grab?")
            MENU(
                CHOICE("cheezy triangles", [](){
                    MC("the cheezy ones", "right?")
                    RIN_TRIANGLE_CHIP = main_character_state::cheezy_triangles;
                }),
                CHOICE("cool triangles", [](){
                    MC("the cool ones", "right?")
                    RIN_TRIANGLE_CHIP = main_character_state::cool_triangles;
                }),
                CHOICE("fire triangles", [](){
                    MC("the fire ones", "right?")
                    RIN_TRIANGLE_CHIP = main_character_state::fire_triangles;
                })
            )
            MENU(
                CHOICE("no", [](){
                    MC("alright, let me", "look again")
                    rin_emergency_3_confirmed = false;
                }),
                CHOICE("yes", [](){
                    MC("alright, we'll go", "with these ones")
                    rin_emergency_3_confirmed = true;
                })
            )
        }
    }
    //! \brief pizza confirmation loop
    void rin_emergency_3_pizza_loop() {
        rin_emergency_3_confirmed = false;
        while(!rin_emergency_3_confirmed) {
            MC("which pizza should I", "get?")
            MENU(
                CHOICE("everything", [](){
                    MC("I should get the", "everthing pizza, right?")
                    RIN_PIZZA = main_character_state::everything_pizza;
                }),
                CHOICE("cheese", [](){
                    MC("I should get the", "cheese pizza, right?")
                    RIN_PIZZA = main_character_state::cheese_pizza;
                }),
                CHOICE("meat lovers", [](){
                    MC("I should get the", "meat lovers pizza, right?")
                    RIN_PIZZA = main_character_state::meat_lovers_pizza;
                })
            )
            MENU(
                CHOICE("no", [](){
                    MC("alright, let me", "look again")
                    rin_emergency_3_confirmed = false;
                }),
                CHOICE("yes", [](){
                    MC("alright, we'll go", "with that one")
                    rin_emergency_3_confirmed = true;
                })
            )
        }
    }
    //! \brief Rin is sick, we head over to get our confession (Bosco Cart)
    void rin_emergency_3() {
        MC("let's grab some chips")
        EMPTY("(you head to the", "convenience store)")
        SCENE_END
        BG_CONVENIENCE
        FADE_IN
        rin_emergency_3_chips_loop();
        MC("alright, next stop is", "the pizza place.")
        EMPTY("(you head to the", "pizza place)")
        SCENE_END
        BG_PIZZA_PLACE
        FADE_IN
        rin_emergency_3_pizza_loop();
        MC("ok that is everything", "I'll let her know", "that I'm heading over")
        SCENE_END
        BG_RINS_APARTMENT_DOOR
        FADE_IN
        EMPTY("(you knock on the", "door)")
        CELL_PHONE_BUZZ
        RIN_TEXT("the front door", "should be open")
        MC("alright then")
        EMPTY("(you head inside)")
        SCENE_END
        BG_RINS_ROOM
        FADE_IN
        MC("knock knock Rin", "I'm here")
        SHOW_RIN_NORMAL
        RIN("oh wonderful")
        MC("oh you look...", "normal ish?")
        RIN("yea its just some", "stomach problems. maybe", "just a stress thing")
        MC("oh.", "well I got you some", "pizza.")
        bool correct_pizza = RIN_PIZZA == main_character_state::cheese_pizza;
        if(correct_pizza) {
            MC("its cheese")
            RIN("oh wow, you remembered")
        } else {
            RIN("hmm it smells...", "extra.")
            MC("oh did I get the", "wrong flavor?")
            RIN("I mean I'll eat it...", "but yes. get plain", "cheese next time")
            MC("aww sorry")
        }
        MC("I also got some of", "the triangle chips")
        auto correct_chip = RIN_TRIANGLE_CHIP == main_character_state::cool_triangles;
        if(correct_chip) {
            if(correct_pizza) {
                RIN("wow you remembered these", "too? impressive")
            } else {
                RIN("oh you remembered", "how kind")
            }
        } else {
            RIN("for future reference,", "I like the cool", "chips...")
            if(!correct_pizza) {
                RIN("also I am not in", "mood to get pissed off,", "so you get off easy", "today")
                MC("uhm... right...")
            }
        }
        MC("so anything planned?", "are you going to hang", "around here alone?")
        MC("or should I stay and", "keep you company?")
        RIN("well, bozo, I would", "have ordered delivery", "if I only wanted", "the food")
        MC("...right", "so...")
        MC("did you have a", "game in mind?")
        RIN("let's just play Bosco", "Cart... that shouldn't", "require too many", "braincells")
        MC("oh neat I haven't", "played that")
        RIN("yea, you and everyone", "one else in that office")
        MC("how do you know that?", "there has to be someone", "else in the office", "that plays games")
        RIN("nope, I've asked", "'em all")
        MC("maybe they know someone", "else that plays!")
        RIN("that's like saying you", "know someone with a name.", "of course they know", "someone who plays games!")
        MC("well...")
        RIN("here's the controller")
        RIN("use this one to steer", "and this one to", "accelerate")
        MC("ok easy enough")
        RIN("let's go!")
        for(int i = 0; i < 3; i++) {
            GAME(FMT_24("turn left! (LEFT {}/3)", i))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
        }
        for(int i = 0; i < 3; i++) {
            GAME(FMT_24("accelerate! (UP {}/3)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        for(int i = 0; i < 3; i++) {
            GAME(FMT_24("turn right! (RIGHT {}/3)", i))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
        }
        for(int i = 0; i < 3; i++) {
            GAME(FMT_24("accelerate! (UP {}/3)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        MC("ha I'm not doing too", "bad! look, there's", "no one near me!")
        RIN("that's 'cause they're", "all ahead of you!", "you're in last! HAHAHA")
        MC("oh...")
        EMPTY("(you finish the race", "in last place)")
        RIN("alright, I'll lower", "the difficulty. this'll", "slow the cars down too")
        MC("works for me")
        RIN("3..2..1...", "start!")
        for(int i = 0; i < 5; i++) {
            GAME(FMT_24("accelerate! (UP {}/5)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        for(int i = 0; i < 2; i++) {
            GAME(FMT_24("turn right! (RIGHT {}/2)", i))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
        }
        for(int i = 0; i < 2; i++) {
            GAME(FMT_24("turn left! (LEFT {}/2)", i))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
        }
        for(int i = 0; i < 10; i++) {
            GAME(FMT_24("accelerate! (UP {}/10)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        MC("hey not bad! 6th", "place is... well it's", "something!")
        RIN("congrats! actually not", "so bad for your second", "game")
        MC("woah woah woah", "did I just hear...", "a compliment?")
        RIN("YOU BETTER SHUT IT", "BEFORE I KICK YOU", "OUT")
        RIN("*hpmh*")
        EMPTY("(Rin continues to", "eat her pizza)")
        MC("alright, why are you", "so confrontational?", "don't you ever decide", "to be nice to people?")
        RIN("I AM NICE TO PEOPLE!")
        MC("when we met, you", "almost didn't talk to", "me because...")
        MC("I didn't answer", "your question", "correctly!")
        RIN("yea, and?")
        MC("that isn't normal!", "most people like", "meeting new people")
        MC("even if they don't", "like them, at least", "they're polite about it")
        RIN("ok well maybe", "I'm not normal??")
        MC("but if you're polite", "maybe you can meet", "more people to play", "games with, right?")
        RIN("...maybe")
        EMPTY("(you head to the", "bathroom for a momentary", "break)")
        MC("alright. maybe I-")
        RIN("no no", "you're right")
        RIN("I-", "I don't like being", "close to people")
        RIN("It feels...", "weird")
        MC("I think it's normal", "to feel that way.", "most people do at", "first")
        RIN("yea but...")
        RIN("oh whatever", "let's play some", "more")
        EMPTY("(Rin starts up", "another round)")
        for(int i = 0; i < 5; i++) {
            GAME(FMT_24("accelerate! (UP {}/5)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        for(int i = 0; i < 2; i++) {
            GAME(FMT_24("turn right! (RIGHT {}/2)", i))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
        }
        for(int i = 0; i < 2; i++) {
            GAME(FMT_24("turn left! (LEFT {}/2)", i))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
        }
        for(int i = 0; i < 10; i++) {
            GAME(FMT_24("accelerate! (UP {}/10)", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
        }
        EMPTY("(you get fifth place!)")
        MC("neat! I'm getting", "better!")
        RIN("well, I'm bored.", "let's...", "go for a walk")
        MC("works for me")
        SCENE_END
        BG_STREET
        FADE_IN
        SHOW_RIN_NORMAL
        RIN("so, you were", "saying...")
        RIN("about meeting other", "people...")
        RIN("that other people", "also feel weird?")
        MC("yea it is pretty", "normal when you meet", "people")
        MC("maybe you like them,", "maybe you don't", "most people are polite", "to ease that tension")
        RIN("we're you...", "did you feel that", "when you met me?")
        MENU(
            CHOICE("yes", [](){
                MC("yes, of course.", "I felt more uneasy", "when you asked a", "programming question")
                RIN("mm...")
            }),
            CHOICE("sort-of", [](){
                MC("well, sort-of.", "being a new hire", "at WidgetCorp means", "talk to new people")
                MC("so I guess I've gotten", "used to the feeling", "though it's still", "there")
                MC("though, I was a bit", "uneasy, when you asked", "a programming question")
            })
        )
        RIN("I guess I understand", "that... but I meet", "so many people that", "have no idea what")
        RIN("they are doing...", "it makes my blood", "boil!")
        MC("well, everyone isn't", "as skilled as you")
        MC("think of Bosco Cart:", "the developers made the", "hard levels for you")
        MC("and they made the", "medium levels for", "someone else!")
        RIN("mm...")
        MC("do you not like", "trusting other people?")
        RIN("ehh I mean", "I guess not...")
        MC("did you have some", "bad experiences with", "that before? like", "a group project?")
        RIN("well I grew up with", "a big family.", "bigger than most,", "I think...")
        RIN("so I guess I kept", "to myself a lot.")
        //! \rin had to fight with her brothers to play games
        RIN("plus I always had", "to fight my brothers", "to play games")
        RIN("so I learned that", "if I want something,", "I need to make up", "my mind and take it")
        //! \rin has always solved problems on her own
        RIN("and when you're alone,", "you kinda learn to", "solve things on your own")
        MC("did you have other", "friends growing up?")
        RIN("not really, just", "my annoying brothers")
        RIN("they were always bringing", "people around...", "it is hard to focus", "with all that noise")
        RIN("so I began to enjoy", "more time alone and", "basically gave up", "on making friends")
        MC("oh...")
        RIN("...", "do you think that's", "weird?")
        MENU(
            CHOICE("no", [](){
                MC("no, I don't think", "it's weird")
                MC("but isn't it nice", "at least having one", "or two people around?")
            }),
            CHOICE("yes", [](){
                MC("yes, I think it is", "pretty weird. but I", "think it makes you", "who you are")
                MC("so I don't think you", "should change.")
                MC("still, don't you", "think it would be", "nice to have at least", "one other person?")
            })
        )
        RIN("fine... maybe", "one would be ok...")
        if(correct_pizza && correct_chip) {
            RIN("I mean you remembered", "everything correctly.")
            MC("correct")
            RIN("so don't you think...")
            MC("... that I should be", "your 'one person'?")
            RIN("well, you're here", "now, right?", "isn't that what you", "mean??")
            MC("I mean...")
            MC("sure, I can be that")
            SHOW_RIN_HAPPY
            RIN("good, it's settled!")
            MC("*sigh*")
            SCENE_END
            vnlib::end(vnlib::PERFECT_END);
        } else {
            RIN("I know you aren't", "perfect, but you're", "basically good enough")
            MC("good enough??")
            RIN("you know... to be the", "'one person' I need")
            MC("oh, right...")
            MC("yes, I can be that")
            SHOW_RIN_HAPPY
            RIN("good, it's settled!")
            MC("*sigh*")
            SCENE_END
            vnlib::end(vnlib::GOOD_END);
        }
    }

    //! \brief ino's emergency prompts
    const vnlib::story_fx EMERGENCY_PROMPT_INO[] = {ino_emergency_prompt_0, ino_emergency_prompt_1, ino_emergency_prompt_2, ino_emergency_prompt_3};
    //! \brief kanade's emergency prompts
    const vnlib::story_fx EMERGENCY_PROMPT_KANADE[] = {kanade_emergency_prompt_0, kanade_emergency_prompt_1, kanade_emergency_prompt_2, kanade_emergency_prompt_3};
    //! \brief rika's emergency prompts
    const vnlib::story_fx EMERGENCY_PROMPT_RIKA[] = {rika_emergency_prompt_0, rika_emergency_prompt_1, rika_emergency_prompt_2, rika_emergency_prompt_3};
    //! \brief rin's emergency prompts
    const vnlib::story_fx EMERGENCY_PROMPT_RIN[] = {rin_emergency_prompt_0, rin_emergency_prompt_1, rin_emergency_prompt_2, rin_emergency_prompt_3};
    //! \brief get the latest emergency prompt per character. no bounds check
    vnlib::story_fx get_emergency_prompt(character::CHAR_ENUM c) {
        int progress = EMERGENCY_PROGRESS[c];
        switch(c) {
        case character::INO:
            return EMERGENCY_PROMPT_INO[progress];
        case character::KANADE:
            return EMERGENCY_PROMPT_KANADE[progress];
        case character::RIKA:
            return EMERGENCY_PROMPT_RIKA[progress];
        case character::RIN:
            return EMERGENCY_PROMPT_RIN[progress];
        default:
            return [](){};
        }
    }

    //! \brief ino's emergency stories
    const vnlib::story_fx EMERGENCY_STORY_INO[] = {ino_emergency_0, ino_emergency_1, ino_emergency_2, ino_emergency_3};
    //! \brief kanade's emergency stories
    const vnlib::story_fx EMERGENCY_STORY_KANADE[] = {kanade_emergency_0, kanade_emergency_1, kanade_emergency_2, kanade_emergency_3};
    //! \brief rika's emergency stories
    const vnlib::story_fx EMERGENCY_STORY_RIKA[] = {rika_emergency_0, rika_emergency_1, rika_emergency_2, rika_emergency_3};
    //! \brief rin's emergency stories
    const vnlib::story_fx EMERGENCY_STORY_RIN[] = {rin_emergency_0, rin_emergency_1, rin_emergency_2, rin_emergency_3};
    //! \brief get the latest emergency story per character. no bounds check
    vnlib::story_fx get_emergency_story(character::CHAR_ENUM c) {
        int progress = EMERGENCY_PROGRESS[c];
        switch(c) {
        case character::INO:
            return EMERGENCY_STORY_INO[progress];
        case character::KANADE:
            return EMERGENCY_STORY_KANADE[progress];
        case character::RIKA:
            return EMERGENCY_STORY_RIKA[progress];
        case character::RIN:
            return EMERGENCY_STORY_RIN[progress];
        default:
            return [](){};
        }
    }

    //! \brief excuse used on Saturday when handling a real emergency
    void saturday_emergency_excuse() {
        MC(FMT_24("Sorry, {}", character::string(original_story)), "something has come up!")
        switch(original_story) {
        case character::INO:
            INO("well, see you at", "work...", "(Ino strongly disliked", "your decision)")
            break;
        case character::KANADE:
            KANADE("oh...", "well, see you then", "(Kanade strongly disliked", "your decision)")
            break;
        case character::RIKA:
            RIKA("hmm ok. I'll catch", "you later!", "(Rika doesn't mind)")
            break;
        case character::RIN:
            RIN("gross...", "(Rin hates your", "decision)")
            break;
        default: break;
        }
    }

    /*! \brief a generic emergency prompt to keep the flow of text simple
     *
     * most weekend events will have some respones from the main character
     * after the emergency happens. example : "is everything alright?"
     * instead of adding a more complex emergency state, have a generic
     * emergency. This can potentially be used to create more content
     * for this type of runtime mode (runtime_state::EMERGENCIES_ON_SUNDAY)
    */
    void generic_emergency() {
        GENERIC_TEXT_MESSAGE("attention: your", "car's warranty is about", "to expire, call us", "to renew now!")
        // this is the embedded excuse
        MC("oh buzz off!")
    }

    //! \brief respond to character c with rejection
    void reject_excuse(character::CHAR_ENUM c) {
        switch(c) {
        case character::INO:
            MC("*text*", "sorry Ino.", "I'm busy at the moment")
            EMPTY("(Ino dislikes your", "decision)")
            break;
        case character::KANADE:
            MC("*text*", "sorry Kanade.", "I'm busy at the moment")
            EMPTY("(Kanade dislikes your", "decision)")
            break;
        case character::RIKA:
            MC("*text*", "hey Rika!", "Sorry, I've got something", "else going on.")
            EMPTY("(Rika doesn't mind", "your decision)")
            break;
        case character::RIN:
            MC("*text*", "Rin, it is", "impossible for me", "to help out")
            EMPTY("(Rin hates your", "decision)")
            break;
        default: break;
        }
    }

    /*! \brief call during a weekend event to prompt for emergency story
     *
     * characters are sorted by relationship decreasing so that the second
     * liked character invokes an emergency. The emergency progress does not
     * advance when ignoring. This means a character will have the same
     * emergency across multiple weekends. This is so players get the opportunity to
     * see all parts of an emergency path without needing relationship planning.
     * Note that the emergency decision will increase the relationship of the
     * chosen characters path and reduce the "ignored" character's path.
     */
    bool handle_emergency(vnlib::story_fx emergency_excuse) {
        // phone is managed here and falls out of scope when emergency is over
        SP_EMERGENCY_PHONE
        CELL_PHONE_BUZZ
        // ensure check emergency day
        auto is_and_meets_saturday = state::st.is_saturday() && EMERGENCIES_ARE_ON_SATURDAY;
        auto is_and_meets_sunday = state::st.is_sunday() && EMERGENCIES_ARE_ON_SUNDAY;
        if(!(is_and_meets_saturday || is_and_meets_sunday)) {
            // have a generic "emergency"
            // this is required as the story_fx calling this code assumes some disruption is happening
            generic_emergency();
            SP_EMERGENCY_PHONE_FREE
            return false;
        }
        // pick second char
        auto chars = state::st.rel_state.by_rel_desc();
        for(auto c : chars) {
            if(c == original_story) {
                continue;
            } else if (EMERGENCY_PROGRESS[c] >= MAX_EMERGENCY_COUNT) {
                continue;
            } else if (!state::st.unlock_state.is_unlocked[c]) {
                continue;
            } else if (state::st.rel_state.rels[c] < (EMERGENCY_PROGRESS[c]+1) * EMERGENCY_REL_PROGRESS_MULTIPLIER) {
                // emergencies only happen once you've reached high enough relation
                // unlock stories (which start at 0), emergencies should start at EMERGENCY_REL_PROGRESS_MULTIPLIER
                // if you tunnel one character. you will avoid emergencies entirely
                // in some ways, this is desirable as it makes emergencies the "harder" route
                // it also functoins as a way to balance attention, if you raise a second char
                // you'll naturally get emergencies from the first (and lose relationship for not helping)
                continue;
            }
            get_emergency_prompt(c)();
            emergency_response();
            if(helped) {
                // emergency from character c was accepted
                current_story = c;
                emergency_excuse();
                SP_EMERGENCY_PHONE_FREE
                get_emergency_story(c)();
                EMERGENCY_PROGRESS[c] += 1;
                if(state::st.is_saturday()) {
                    // only if leaving someone on Saturday
                    switch(original_story){
                        case character::INO:
                        case character::KANADE:
                            // Ino and Kanade hate being left
                            state::st.rel_state.modify_relation(original_story, relationship_state::REALLY_BAD);
                            break;
                        case character::RIKA:
                            // Rika doesn't mind being left
                            break;
                        case character::RIN:
                            // Rin takes serious offense to being left
                            state::st.rel_state.reset(original_story);
                            break;
                        default: break;
                    }
                }
                // TODO: maybe Rin only improves by GOOD
                state::st.rel_state.modify_relation(current_story, relationship_state::REALLY_GOOD);
                return true;
            } else {
                // emergency from character c was ignored
                reject_excuse(c);
                switch(c) {
                case character::INO:
                case character::KANADE:
                    // Ino and Kanade dislike being ignored
                    state::st.rel_state.modify_relation(c, relationship_state::BAD);
                    break;
                case character::RIKA:
                    // Rika doesn't care about being ignored
                    break;
                case character::RIN:
                    // Rin takes serious offense
                    state::st.rel_state.reset(c);
                    break;
                default: break;
                }
                SP_EMERGENCY_PHONE_FREE
                return false;
            }
        }
        generic_emergency();
        SP_EMERGENCY_PHONE_FREE
        return false;
    }

    //! \brief ino's first weekend (park + cafe)
    void ino_weekend_0() {
        MC("maybe I should head", "out for a bit")
        MC("I think there is a", "park close by...")
        MC("alright, let's go!")
        SCENE_END
        BG_PARK
        FADE_IN
        MC("ahh! this fresh", "air is quite nice")
        MC("some week, too...")
        MC("at least I was", "able to finish a few", "things")
        SHOW_INO_NORMAL
        INO(MCF("{}!"), "nice to see", "you here!")
        MC("hey Ino!", "what brings you here?")
        //! \ino like to exercise
        INO("Well this park is", "a bit far from my", "apartment but I", "wanted a bit of")
        INO("exercise today. Usually", "I'll pick some place", "closer")
        INO("were you also getting", "some exercise?")
        MENU(
            CHOICE("exercise", [](){
                MC("here to exercise", "of course!")
                MC("I just completed", "my third mile so I", "wanted to rest up", "a bit")
                INO("right on!", "maybe we should", "cross paths more", "often!")
            }),
            CHOICE("bird watching", [](){
                MC("I am a bird watcher!", "There isn't really a", "point...", "well..")
                MC("compared to exercising", "or playing a sport.", "It is closer to", "watching a movie")
                //! \ino_maybe doesn't watch movies
                INO("hmm bird watching...", "can't say I've tried", "it. I'm not really", "one to watch movies")
            }),
            CHOICE("vitamin D", [](){
                MC("I don't usually enjoy", "going outside. These", "days I convince myself", "that I need ")
                MC("more vitamin D, and", "the only way to do", "so is heading outside")
                MC("though, usually I'll", "bring a book or listen", "to some music")
                INO("hey, anything you", "do to take care of", "yourself is a fine way", "to spend time")
            })
        )
        INO("say, if you have some", "time now, why don't", "we head to grab", "something to eat")
        INO("would you be up", "for that?")
        HANDLE_EMERGENCY
        INO("everything good?")
        MC("yup all good.", "nothing urgent!")
        INO("alright, let's", "head out")
        SCENE_END
        BG_CAFE
        FADE_IN
        SHOW_INO_NORMAL
        INO("*phew*", "always feels good to", "get a reward after", "some work")
        MC("what do you", "normally get?")
        INO("I like eggs sandwich", "but they can be hard", "to come by")
        INO("if I can't get that,", "then a bagel with", "cream cheese will", "do")
        INO("do you have a", "'usual' cafe item?")
        MENU(
            CHOICE("croissant", [](){
                CAFE_ITEM_PREFERENCE = main_character_state::croissant;
                MC("if they have a", "buttery croissant,", "then I can't hold", "back.")
                MC("anything fluffy and", "warm has to be top", "tier")
                INO("respectable, can't", "say I know any", "croissant haters")
            }),
            CHOICE("cinnamon roll", [](){
                CAFE_ITEM_PREFERENCE = main_character_state::cinnamon_roll;
                MC("for me, its the", "cinnamon roll. could", "be a bit messy but", "worth every bite")
                MC("though, I usually limit", "myself to one a month")
                INO("one a month?", "if I limit anything", "to once a month,", "I would forget")
                INO("about it entirely!")
                //! \ino_maybe enjoys repition
                INO("I guess I enjoy", "repitition. or something", "I can depend on.")
            }),
            CHOICE("anything chocolate", [](){
                CAFE_ITEM_PREFERENCE = main_character_state::chocolate_item;
                MC("I will get anything", "chocolate flavored.", "cookies, muffins,...")
                MC("gosh just thinking about", "it...", "oh! and even", "hazelnut spread!")
                INO("that is pretty convincing!", "maybe I need to", "change my ways! haha")
            })
        )
        INO("with that said, I'd say", "today's a good day", "to try something new!")
        if(CAFE_ITEM_PREFERENCE == main_character_state::chocolate_item) {
            INO("lets see...", "what chocolate items", "do they have...")
            INO("hmm")
            INO("oh a chocolate cake!!", "would you like that?")
            MC("sure!")
            INO("two slices of chocolate", "cake, please!")
        } else {
            bn::string<16> item_name = main_character_state::to_string(CAFE_ITEM_PREFERENCE);
            INO("hey look!", "they do have", FMT_24("{}s!", item_name))
            INO(FMT_24("two {}s", item_name), "please!")
        }
        INO("AHH", "its delicous!", "definitely worth the", "visit.")
        MC("*mmm*", "", "(I should come back", "here!)")
        INO("well, I'm about done", "why don't we call it", "there?")
        MC("sure, works for me", "I'll see you at", "work!")
        INO(MCF("see ya, {}!"))
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief ino is taking care of a friends pet
    void ino_weekend_1() {
        MC("ahh Saturday!")
        MC("what should I do", "today?")
        MENU(
            CHOICE("TV", [](){
                MC("I could try out", "a new tv show...")
            }),
            CHOICE("Anime", [](){
                MC("well I could start", "a new season", "of anime...")
            })
        )
        CELL_PHONE_BUZZ
        INO_TEXT(MCF("hey, {}"), "are you free this", "weekend?");
        INO_TEXT("I have to take care", "of a friends pet", "but I'm not really", "good with these things")
        MC("sure, I can help out")
        INO_TEXT("ok let me send you", "my address. I'll see", "you soon")
        MC("ok, time to head over")
        EMPTY("(you make your way", "to Ino's place)")
        SCENE_END
        BG_INO_ROOM
        FADE_IN
        SHOW_INO_NORMAL
        INO(MCF("hey, {}!"), "glad you could make", "it. This here is", "Rudolph")
        RUDOLPH("*woof!*")
        MC("well, hello there!")
        INO("so, like I said", "I'm not really sure", "what to do with him")
        INO("I really wanted to", "be a good friend but", "maybe this was a", "bad idea...")
        MC("Ino, you might be", "overthinking this.")
        MC("did your friend leave", "any dog food?")
        INO("yes, yes! It's", "that large bag", "over there!")
        INO("Will Rudolph eat the", "whole thing? Do I need", "to get more?")
        MC("haha that bag will", "be more than enough!", "It's common to buy food", "in bulk like that")
        INO("oh got it. *sigh*")
        MC("so you've really", "never had a pet before?")
        INO("no, I was rowdy enough", "as a kid. I don't", "think my parents wanted", "anything else that")
        INO("could run around and", "trash the place?")
        MC("oh gosh. were you", "a pain for your", "parents?")
        INO("well I never thought so", "... but I was a bit", "loud, I suppose")
        //! \ino was a loud, opinionated kid
        INO("I wasn't really mean", "or anything. I just", "let them know when", "I didn't like things")
        MC("well that's fair", "maybe it catches people", "by surprise but they", "grow to understand")
        //! \ino is a bit worried about being approachable
        INO("yea I grew out of", "that after some time.", "Hopefully, I am bit", "more approachable")
        MC("I think either way", "is fine. As long as", "you are comfortable!")
        INO("thank you, that's", "nice to hear")
        INO("so don't dogs need", "to walk? and, you", "know, ...")
        MC("yes, if you haven't", "taken Rudolph out yet,", "we should do that")
        MC("If you have a plastic", "bag, that will also", "help keep the", "neighborhood clean")
        INO("sure, there are some", "under the sink")
        MC("ok I'll hold on", "to those and we can", "head to the park")
        INO("alright, let go", "Rudolph!")
        RUDOLPH("*woof! woof!*")
        SCENE_END
        BG_PARK
        FADE_IN
        SHOW_INO_NORMAL
        MC("alright let's walk", "around this path a", "few times.")
        HANDLE_EMERGENCY
        INO("all good?")
        MC("yup, just something", "that can wait")
        INO("so you seem pretty", "knowledgable on the", "whole dog-care thing")
        INO("did you used to", "have one?")
        MENU(
            CHOICE("yes, family", [](){
                MC("yes, my family had", "one growing up", "That was definitely", "a learning experience")
                MC("they are a lot of", "work. you can leave", "them alone for part", "of the day...")
                MC("but there is always", "a sense of worry if", "you aren't around them")
                INO("oh I see")
            }),
            CHOICE("friends dog", [](){
                MC("we'll I never had", "one of my own.", "but I did take care", "of a friend's dog")
                MC("they used to travel", "quite frequently so", "I'd help out a few", "times a year")
                INO("oh thats nice!", "kinda like what I'm", "doing now!")
                MC("exactly!")
            })
        )
        INO("Any scary stories?")
        MC("like of the dog", "or in general?")
        INO("haha I guess either", "works!")
        MENU(
            CHOICE("dog story", [](){
                MC("well, not extremely", "scary but I did have", "a dog attack my", "backpack before")
                INO("oh that sounds", "pretty scary to me!")
                MC("I couldn't understand", "why it was doing that.", "it all happened quite", "quickly")
                INO("so did you let the", "dog have your bag?")
                MC("I did play tug-of-", "-war for a bit trying", "to get it back")
                MC("after a minute or so", "the dog gave up.")
                INO("nice!")
            }),
            CHOICE("spooky story", [](){
                MC("I think the spookiest", "thing to happen was", "during one of my", "part-time jobs")
                MC("I used to work at", "a convenience store", "and there was a", "back area for storage")
                MC("so we had certain", "piles of items waiting", "to be stocked")
                MC("and I SWEAR that", "these boxes would be", "in different piles", "everytime I checked.")
                INO("we're you the only", "one working?")
                MC("yes!")
                INO("are you sure that", "you're... ok?")
                MC("yes, yes. I don't", "think anything was", "haunted. Probably just", "me imagining things")
                INO("hmm...")
            })
        )
        RUDOLPH("*woof!*")
        MC("...")
        INO("...", "what did he say?")
        MC("I'm not sure but", "probably time to head", "back")
        MC("my guess is that Rudolph", "is hungry or wants", "something to drink")
        INO("ok let's head back")
        SCENE_END
        BG_INO_ROOM
        FADE_IN
        SHOW_INO_NORMAL
        INO("ok once you show me", "the food amount I think", "I'll be all set")
        MC("sure! It looks like", "your friend included the", "serving cup")
        MC("just fill it up to", "here. I think that amount", "twice a day should", "be fine")
        INO("got it")
        MC("alright, I think that", "is enough adventure for", "me. I'm going", "to head back")
        SHOW_INO_HAPPY
        INO("sounds good! thanks", "again for the help!")
        MC("good luck!", "see you on Monday!")
        INO("see ya")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief ino is heading to an open mic at the bar
    void ino_weekend_2() {
        MC("another lonely wekend")
        CELL_PHONE_BUZZ
        INO_TEXT("hey I was going to", "head to the bar", "for an open mic", "want to join?")
        MC("sure, count me in")
        INO_TEXT("ok be there at 1pm")
        MC("sound good, see you", "then!")
        EMPTY("(you wait until 1pm)")
        SCENE_END
        BG_BAR
        FADE_IN
        SHOW_INO_NORMAL
        INO(MCF("welcome, {}!"))
        MC("oh hey Ino!", "so you are performing a", "song today?")
        INO("yup! I've been practicing", "these last few weeks!")
        MC("nice, I'm excited to", "hear it. What did you", "end up writing about?")
        INO("oh nothing in particular...", "I grew up in the", "contryside so I wrote", "something a bit folk-y")
        INO("like some silly", "lyrics about missing", "home and those familiar", "things...")
        MENU(
            CHOICE("I can't wait", [](){
                MC("I'm sure it'll turn", "out well! I can't", "wait to hear it!")
            }),
            CHOICE("that ain't silly!", [](){
                MC("oh that isn't silly", "at all!")
                MC("If you took the time", "to write it, there is", "no way it could", "be silly")
                MC("missing home is a", "normal feeling")
                MC("sometimes we need", "to leave. sometimes we", "need to go back!")
                INO("aww... well", "I hope you'll enjoy it!")
            })
        )
        MC("how much longer until", "you perform?")
        INO("well, we are here a", "bit early. so maybe", "fifteen to thirty", "minutes")
        MC("ahh ok. should we", "get something to drink?")
        INO("oh. haha. yea...", ":P")
        MC("oh you already have", "something! haha", "let me go over and", "pick something out")
        EMPTY("(you head to the bar)")
        MENU(
            CHOICE("beer", [](){
                MC("I'll go with some", "beer. probably whatever", "is on tap")
                EMPTY("(you head back over", "to Ino's table)")
                INO("oo what did you get?")
                MC("uhm, whatever they", "suggested. seems like", "a normal beer")
                INO("haha not that picky?")
                MC("ehh not today, at least!")
            }),
            CHOICE("cola", [](){
                MC("I'll go with a cola", "today, that's more my", "style")
                EMPTY("(you head back over", "to Ino's table)")
                INO("anything good?")
                MC("I did get something", "with sugar!")
                INO("haha I like your", "style!")
            }),
            CHOICE("water", [](){
                MC("actually just water", "for today, it was", "pretty hot outside")
                EMPTY("(you head back over", "to Ino's table)")
                INO("what did you get?")
                MC("oh just some", "water")
            })
        )
        MC("so when did you", "perform last?")
        INO("only a few weeks", "back. It was a pretty", "small group; only four", "of us!")
        MC("oh wow, how many", "do you think you'll", "get today?")
        INO("usually a few more", "people are free on", "the weekend")
        INO("so maybe six to eight!")
        MC("wow, nice!")
        INO("so if you weren't", "here listening to", "music, what would", "you normally do?")
        MENU(
            CHOICE("cleaning", [](){
                MC("I would be cleaning", "up my apartment.")
                MC("after that is over,", "probably take a nap", "and watch a movie")
                INO("so you...", "wouldn't leave the", "house at all?")
                MC("well...", "no, I guess not")
                INO("haha that's ok", "sometimes you just", "need a little push to", "do something interesting")
                MC("movies are interesting!")
                //! \ino_maybe is a bit sick of indoors
                INO("true, I like them", "too. but don't you get", "sick of being indoors?")
                INO("especially since our", "team sits at the computer", "most of the day")
                MC("well obviously it's", "nice to get out")
            }),
            CHOICE("working out", [](){
                MC("around this time,", "I would be going to", "work out.")
                MC("I went a bit earlier", "today in anticipation of", "something like this", "happening")
                INO("oh wow!", "busy, busy!")
                //! \ino_maybe would like to work out more seriously
                INO("yea I'd love to", "work out more seriously.")
                INO("though I think sports are", "the best way to have", "fun while you exercise")
                MC("yea, you have a point")
            })
        )
        INO("well then...")
        INO("looks like more people", "have arrived!", "we'll be starting soon")
        MC("!!")
        ORGANIZER("alright, gather round", "everyone!")
        ORGANIZER("looks like we have", "quite a crowd! Thanks", "everyone for joining")
        ORGANIZER("anyone want to go", "first?")
        MENU(
            CHOICE("nudge Ino", [](){
                MC("psstt Ino!", "go for it!")
                INO("... ", "not now!", "let a few others", "go at least!")
            }),
            CHOICE("*wait*", [](){
                EMPTY("(you wait patiently)")
            })
        )
        ORGANIZER("alright, Mario", "you can go first!")
        EMPTY("(Mario heads to", "the stage)")
        INO("oh he's pretty good!")
        EMPTY("(Mario plays a silly", "song about fixing his", "sink)")
        EMPTY("(the crowd loves it!)")
        INO("alright, let me see if", "I can go next")
        HANDLE_EMERGENCY
        INO("evrything good?")
        MC("yup, nothing important", "I've turned it off")
        INO("*phew* ok")
        ORGANIZER("alright any takers", "for the encore?")
        EMPTY("(Ino raises her hand)")
        ORGANIZER("oh Ino!", "thanks for showing up", "again!")
        ORGANIZER("looks like you've brought", "a friend with!", "welcome to out music", "circle")
        ORGANIZER("I hope you're enjoying", "yourself, newcomer")
        MC("yup, this place is", "pretty cool! I've", "never been to one", "before.")
        ORGANIZER("well, please relax and", "enjoy the music")
        ORGANIZER("Ino, would you like to", "go next?")
        INO("sure!")
        EMPTY("(Ino heads up to", "the stage)")
        INO("*ahem* alright this one", "is a little tune", "about my family and", "missing home")
        EMPTY("WOO!*", "*YEA!*")
        EMPTY("(the crowd is so", "excited!)")
        EMPTY("(Ino plays her song!)")
        EMPTY("(What a beautiful melody)")
        EMPTY("(And with that, Ino", "strums the final chord)")
        EMPTY("*WOO*", "*AMAZING!*")
        INO("thank you!")
        MENU(
            CHOICE("'amazing!'", [](){
                MC("WOOO! THAT WAS", "AMAZING!")
            }),
            CHOICE("'I love you!'", [](){
                MC("I LOVE YOU INO!!!", "WOOO!")
            }),
            CHOICE("'so cool!", [](){
                MC("YOU'RE SO COOL!", "WOOO!")
            })
        )
        INO("haha thank you", MCF("{}!"), "*phew* I'm glad", "its over")
        MC("what are you talking", "about!? that was superb!")
        INO("aww you're just saying", "that...")
        MC("look! look at all these", "people! They love it!", "I love it!")
        INO("aww...")
        MC("alright let's wait for", "everyone to finish", "and we can celebrate!")
        EMPTY("(you wait for the", "other four people to", "finish)")
        ORGANIZER("alright, that's it for", "today! We'll be back", "on Wednesday!", "take care, everyone!")
        EMPTY("(Ino lets out a", "final sigh)")
        MC("alright, what should we", "do to celebrate?")
        INO("I am going to celebrate", "with a nap at home")
        INO("I'm still feeling nervous", "and my song was thirty", "minutes ago!")
        MC("sounds good. maybe we", "can celebrate next time")
        MC("I enjoyed attending!", "Thanks for singing us", "your song!")
        INO("well I have a few", "other that I mix in")
        INO("maybe if you show", "up again, you'll hear", "'em all!")
        MC("maybe I will!")
        INO("alright, I'll catch you", "later! see you", MCF("{}!"))
        MC("bye Ino!")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief ino needs to visit her family in the countryside
    void ino_weekend_3_beer_purchase() {
        for(int chances = 0; chances < 5 && INO_FAMILY_BEER == main_character_state::none; chances++){
            if(chances == 4) {
                SHOW_INO_NORMAL
                INO("still can't decide?")
                MC("I'm taking a good", "look. Wouldn't want", "to get something", "your family hates")
                INO("haha well you", "barely know them.", "plus my dad will", "drink anything...")
                INO("Is there anything that", "matches what we're", "grilling?")
                MC("hmm let's see...")
            }
            MENU(
                CHOICE("Ridgeline Ale", [](){
                    MC("it says it goes", "well with red meat")
                    INO_FAMILY_BEER = main_character_state::ridgeline_ale;
                }),
                CHOICE("Blitz IPA", [](){
                    MC("it says it goes", "well with white meat")
                    INO_FAMILY_BEER = main_character_state::blitz_ipa;
                }),
                CHOICE("Summer Hefe", [](){
                    MC("it says it goes", "well with vegetables")
                    INO_FAMILY_BEER = main_character_state::summer_hefe;
                })
            )
            MC("should I get this?")
            MENU(
                CHOICE("no, keep looking", [](){
                    MC("I'll keep looking")
                    INO_FAMILY_BEER = main_character_state::none;
                }),
                CHOICE("yes", [](){
                    MC("let's go with this!")
                })
            )
        }
        if(INO_FAMILY_BEER == main_character_state::none) {
            INO("oh what is that", "down below?")
            INO("oh nice, that is", "dad's favorite!!")
            INO("let's go with that!")
            INO_FAMILY_BEER = main_character_state::dads_favorite;
        }
    }
    //! \brief internal
    bool ino_weekend_3_agreement;
    //! \brief internal
    bool ino_weekend_3_mom_happy;
    void ino_weekend_3() {
        MC("hmm what a nice", "day. maybe I should", "grill something...")
        MENU(
            CHOICE("hamburgers", [](){
                MC("well, can't go wrong", "with a burger. though I", "might be missing some", "toppings...")
                GRILL_ITEM = main_character_state::hamburgers;
            }),
            CHOICE("crispy chicken", [](){
                MC("oooh maybe some", "crispy chicken!", "gah!")
                GRILL_ITEM = main_character_state::crispy_chicken;
            }),
            CHOICE("mushrooms", [](){
                MC("maybe mushrooms would", "be nice. Especially with", "some sauce...")
                GRILL_ITEM = main_character_state::mushrooms;
            })
        )
        CELL_PHONE_BUZZ
        INO_TEXT("hey a strange request", "but I need to visit", "my parents in the", "countryside")
        INO_TEXT("would you like to tag", "along? we would head", "out in an hour or so.")
        MENU(
            CHOICE("yes!", [](){
                MC("sure, I'd love to!")
                INO_TEXT("sweet! lets meet", "at the train station", "at 2pm!")
                INO_TEXT("oh you might want", "to bring some clothes.", "They have a few extra", "rooms so you are...")
                INO_TEXT("welcome to stay overnight", "and enjoy the countryside", "a bit more")
                MC("ok. I'll do that!")
                ino_weekend_3_agreement = true;
            }),
            CHOICE("no!", [](){
                MC("sorry, this seems a", "bit hasty for me.")
                INO_TEXT("fair enough! see", "you at work, then!")
                ino_weekend_3_agreement = false;
            })
        )
        if(!ino_weekend_3_agreement) {
            return;
        }
        EMPTY("(you head to the", "train station)")
        SCENE_END
        BG_TRAIN_STATION
        FADE_IN
        INO(MCF("hey {}!"), "over here!")
        SHOW_INO_NORMAL
        INO("hey, nice to see", "you!")
        MC("hello Ino!", "so I think I'm all", "set with my luggage")
        INO("great! I've already got", "the tickets here.", "Are you hungry at", "all?")
        MENU(
            CHOICE("nope", [](){
                MC("I did have breakfast", "not too long ago, I", "think I'll be fine")
            }),
            CHOICE("just a bit", [](){
                MC("I only had some toast", "so I am feeling a", "bit hungry.")
                MC("though I can probably", "make it through the", "train ride so it", "won't be a problem")
            })
        )
        if(CAFE_ITEM_PREFERENCE != main_character_state::none) {
            if(CAFE_ITEM_PREFERENCE == main_character_state::chocolate_item) {
                INO("ok I brought along", "some chocolate cookies.")
            } else {
                INO("ok I brought along a", FMT_24("few {}s", main_character_state::to_string(CAFE_ITEM_PREFERENCE)))
            }
            INO("maybe we can share", "them after the train", "leaves")
            MC("oh nice!", "sure, let's do that.", "Thanks for being prepared!")
            INO("oh it's not problem...", "I head back every month", "so I usually pack", "something for the trip")
        } else {
            INO("oh ok. I have a", "snacks packed away.", "let me know if", "get hungry")
            MC("ok, neat")
        }
        INO("alright, I think we", "board in about ten", "minutes.")
        INO("I need to head to", "the bathroom. I'll be", "right back!")
        MC("ok!")
        EMPTY("(Ino leaves to find", "the bathroom)")
        HIDE
        if(handle_emergency([](){
            MC("*texts Ino*", "sorry, Ino.", "an important emergency", "has come up")
            MC("I'm sorry I can't", "head out with you")
            EMPTY("(you leave the station)")
            SHOW_INO_NORMAL
            INO(MCF("ready, {}?"),"","huh...")
            INO("where...", MCF("is {}?"))
            INO("*tearing*", "I...", "*sniff*", "well...")
            EMPTY("(Ino strongly", "disliked that)")
            state::st.rel_state.reset(character::INO);
            FREE
        })){ return; }
        SHOW_INO_NORMAL
        INO("alright, I'm back!")
        MC("ready to go?")
        INO("yup, looks like we", "can start boarding.")
        MC("alright, let's go!")
        EMPTY("(you board the train", "and depart to the", "countryside)")
        SCENE_END
        INO("alright, our stop is", "the next one. Let's", "get our things ready.")
        MC("ok")
        //! \ino family lives in Flower City
        EMPTY("*ding ding*", "Welcome to Flower City!", "again, this stop is for", "Flower City!")
        INO("here we are!")
        SCENE_END
        BG_FLOWER_CITY
        FADE_IN
        SHOW_INO_NORMAL
        MC("wow what a cute town!")
        INO("yup, its a cozy place.", "Let's sit at the bench", "over here for a bit")
        INO("then we can head toward", "my parents place")
        MC("sure.", "so did you grow up", "out here?")
        INO("yup! All of my childhood.", "I went to school in the", "city and have been at", "WidgetCorp ever since")
        MC("I guess there aren't", "many companies out here")
        INO("not really, some people", "stick around but most", "find their way to the", "city")
        INO("but I think we all", "really love it out", "here. The small town", "feel is hard to beat")
        MC("I am not really familiar", "with smaller towns but", "it does seem quiet here")
        INO("it's quiet most of", "the time, at least", "until the guitars come", "out!")
        MC("haha true")
        INO("I think my parents", "should be ready now.", "let's head over!")
        EMPTY("(you leave the town", "square and follow Ino", "to her parents' house)")
        SCENE_END
        BG_INO_PARENTS_HOUSE
        FADE_IN
        SHOW_INO_NORMAL
        INOS_MOTHER("welcome home!")
        INOS_FATHER("welcome back, Ino!")
        INO("hey, Mom and Dad!")
        INOS_FATHER("Who is this?")
        INO("Oh that is", MCF("{}!"))
        INOS_MOTHER("Nice to meet you", MCF("{}!"))
        INOS_FATHER("please make yourself", "comfortable!")
        INOS_FATHER("Hey Ino, I was going", "to start grilling", "for lunch. maybe", FMT_32("{}?", main_character_state::to_string(GRILL_ITEM)))
        INO("does that work for", MCF("you, {}?"))
        MENU(
            CHOICE("YES!", [](){
                MC("sure, that sounds", "delicous!")
            })
        )
        INOS_FATHER("oh Ino, we might", "be running low on", "beer...")
        INOS_MOTHER("and who's fault is", "that??")
        INOS_FATHER("mine!")
        INOS_MOTHER("*hmph* I can...", "see that")
        INOS_FATHER("Oh.. Ino...", "could you head to", "the store to get some?")
        INOS_MOTHER("I need a few things", "as well!")
        INOS_MOTHER("where is it...", "ah! here!")
        INOS_MOTHER("could you pick these", "things up?")
        INO("sure, that isn't much.", MCF("{}, want"), "to come with?")
        MC("sure, let's go")
        INO("ok, then.", "we'll be back", "in a bit!")
        EMPTY("(you head to the", "store)")
        SCENE_END
        BG_GROCERY_STORE
        FADE_IN
        SHOW_INO_NORMAL
        INO("alright, we just need", "a few ingredients", "and the beer")
        INO("I'll look for most", "of the ingredients, why", "don't you handle the", "alcohol.")
        MC("works for me!")
        HIDE
        MC("ok let's check out", "this beer section")
        ino_weekend_3_beer_purchase();
        SHOW_INO_NORMAL
        INO("alright, looks like", "we've got most of", "it")
        INO("hold on, let me", "double check...")
        INO("*mumbling*")
        INO("yup, we are good", "to go. Let's head back")
        SCENE_END
        BG_INO_PARENTS_HOUSE
        FADE_IN
        SHOW_INO_NORMAL
        INO("we're back!")
        INOS_MOTHER("wondeful! the", "food is almost ready!")
        INOS_FATHER("here it is!")
        EMPTY("(Ino's father brings", "in a large plate", "of food)")
        MC("wow, are we going", "to eat this all?")
        INO("haha nope.", "but we may end up", "having it for breakfast", "tomorrow")
        INOS_MOTHER("and the day after", "tomorrow")
        INOS_FATHER("and the day after", "that, too!")
        INOS_FATHER("oh Ino, we're", "you able to get", "any beer?")
        INO("what did you end", "up picking,", MCF("{}?"))
        if(INO_FAMILY_BEER == main_character_state::dads_favorite) {
            MC("well I had a hard", "time deciding, but", "Ino was able to find", "one that you like")
            INOS_FATHER("IS THAT!?")
            INO("yeah yeah", "its just beer, Dad")
            INOS_FATHER("but it's my favorite!", "ahh!!!!!!!!!!!!", "bless you, Ino!")
            INOS_MOTHER("you knucklehead!", MCF("Now {}"), "will think...", "*sigh*")
            INOS_FATHER("right, my manners...")
            INOS_FATHER("thank you,", MCF("{}!"), "I appreciate the", "consideration!")
            MC("well, Ino did most", "of the work...")
        } else if(
            (GRILL_ITEM == main_character_state::hamburgers && INO_FAMILY_BEER == main_character_state::ridgeline_ale) ||
            (GRILL_ITEM == main_character_state::crispy_chicken && INO_FAMILY_BEER == main_character_state::blitz_ipa) ||
            (GRILL_ITEM == main_character_state::mushrooms && INO_FAMILY_BEER == main_character_state::summer_hefe)
        ) {
            MC("I pickd the", main_character_state::to_string(INO_FAMILY_BEER))
            INOS_FATHER("A wise choice!", "no wonder WidgetCorp", "hired you both")
            INO("... Dad, beer has", "nothing to do with", "our job...")
            INOS_FATHER("I meant...", "well, nevermind.", "good pick,", MCF("{}!"))
        } else {
            MC(main_character_state::to_string(INO_FAMILY_BEER))
            INOS_FATHER("hmm...", "well, that's a bit", "questionable, honestly")
            INOS_MOTHER("oh cut it out!", "you'll drink anything!")
            INO("Dad, Mom is right", "you will drink anything.")
            INO(MCF("{},"), "its fine.")
        }
        INOS_FATHER("alright, let's get", "started!")
        EMPTY("(you enjoy a nice", "meal with Ino's", "family!)")
        INOS_FATHER("I'll get things", "cleaned up. You all", "can continue talking")
        INO("I'm going to help dad", "with the cleaning.", "you two can enjoy", "some rest")
        HIDE
        INOS_MOTHER(MCF("so, {}"), "Ino told us you", "helped her take", "care...")
        INOS_MOTHER("of her friends", "dog. Is that", "true?")
        ino_weekend_3_mom_happy = false;
        MC("yes, it was a few", "weeks ago")
        INOS_MOTHER("frankly, I'm surprised", "Ino agreed to take", "care of something")
        INOS_MOTHER("every time I call, she", "is always running around", "outside or busy with", "work")
        INOS_MOTHER("to think she has time", "for a dog, well...")
        INOS_MOTHER("I worry she is too", "busy, you know?", "")
        MC("I could see that.", "she really puts", "in a lot of effort", "at the office")
        MC("however, I think she", "is still able to find", "time for herself")
        INOS_MOTHER("Is there anything", "you like most", "about Ino?")
        MENU(
            CHOICE("her hobbies", [](){
                MC("I would say her", "hobbies. ")
                if(HOBBY_MUSIC_TALENT == main_character_state::part_of_band) {
                    MC("well, we are both part", "of a band so we", "have quite a bit", "in commmon there")
                    MC("I'd love to see her", "perform but I haven't", "had the chance yet...")
                    EMPTY("(Ino's mother smiles)")
                    INOS_MOTHER("I don't think it'll", "take long for her to", "show you!")
                    ino_weekend_3_mom_happy = true;
                } else {
                    MC("we both enjoy music", "and getting outside")
                    MC("so it is nice", "to spend time when", "we get a chance")
                    INOS_MOTHER("well...", "thats nice.")
                    INOS_MOTHER("I'm glad she could find", "someone who shares her", "interests")
                    ino_weekend_3_mom_happy = false;
                }
            }),
            CHOICE("her resolution", [](){
                MC("I really like how", "hard Ino works. I think", "she would do anything", "for her team")
                MC("and that sort of", "thing really inspires me.", "I think it inspires", "everyone, ")
                INOS_MOTHER("She's always been", "a bit outspoken.", "Maybe not so much", "anymore...")
                INOS_MOTHER("but she always worked", "hard and that sort", "of thing attracts", "people")
                INOS_MOTHER("I'm proud of how", "far she's come and", "its wonderful to", "hear that from you")
                ino_weekend_3_mom_happy = true;
            }),
            CHOICE("her leadership", [](){
                MC("I've worked with many", "people and Ino is an", "amazing leader")
                MC("She works hard to make", "sure everything gets done", "and doesn't just stop", "at 'good enough'")
                MC("I'm a better person", "because of it and I", "can't think of anything", "I would change")
                INOS_MOTHER("ahh ok...", "well, that's nice to hear")
                ino_weekend_3_mom_happy = false;
            })
        )
        SHOW_INO_NORMAL
        INO("how is everything going", "in here? We're", "amost done cleaning")
        if(ino_weekend_3_mom_happy) {
            INOS_MOTHER("things are going", "well, thank you!")
        } else {
            MC("we're doing alright!")
        }
        INO("ok, I'll be back!", "still have one more", "thing to put away...")
        HIDE
        INOS_MOTHER("well it was nice", MCF("chatting, {}!"))
        INOS_MOTHER("thanks for spending", "time with Ino.", "You're always welcome", "here!")
        MC("Thank you, I've enjoyed", "everything here.")
        SHOW_INO_NORMAL
        INO("alright, all set!")
        INO(MCF("{}, I'll"), "show you your room", "and we can take some", "rest")
        INO("I think that dinner", "is making me sleepy...")
        INOS_FATHER(MCF("goodnight, {}!"), "pleasure meeting you")
        INOS_MOTHER(MCF("goodnight, {}!"))
        SCENE_END
        EMPTY("(you head to the", "room and get ready", "for sleep)")
        EMPTY("(zzz)")
        EMPTY("(you awake and eat", "breakfast with Ino's", "family)")
        EMPTY("(you thank them again", "and make your way", "back to the city)")
        BG_TRAIN_STATION
        FADE_IN
        SHOW_INO_HAPPY
        INO("thanks again for coming", "to visit! I", "had a lot of fun!")
        MC("me too!")
        INO("I know my family", "can be a bit odd", "but they seemed to", "enjoy your company")
        INO("I'll let you know", "when I head back next", "maybe you can join us", "again")
        MC("I'd love that", "Thank you for the", "invitation!")
        INO("alright, see you", MCF("later, {}"))
        MC("see you, Ino!")
        SCENE_END
        if(ino_weekend_3_mom_happy && INO_FAMILY_BEER == main_character_state::dads_favorite) {
            // perfect ending
            vnlib::end(vnlib::PERFECT_END);
        } else {
            // good ending
            vnlib::end(vnlib::GOOD_END);
        }
    }

    //! \brief kanade is heading to buy some groceries
    void kanade_weekend_0() {
        MC("finally, some time away", "from work")
        MC("what should I do today?")
        MENU(
            CHOICE("cleaning", [](){
                MC("true, I should clean", "up this place. should", "only take thirty minutes", "or so...")
                MC("hmm what to clean", "first...")
                KANADE_WEEKEND_ACTIVITY = main_character_state::cleaning;
            }),
            CHOICE("fancy meal", [](){
                MC("maybe I could cook", "up a fancy meal?")
                MC("maybe a cake? or", "some cookies?", "I could also grill", "something...")
                KANADE_WEEKEND_ACTIVITY = main_character_state::fancy_meal;
            }),
            CHOICE("anime", [](){
                MC("I should catch up on", "my anime list...")
                MC("maybe four hours now,", "then lunch, then...")
                KANADE_WEEKEND_ACTIVITY = main_character_state::watching_anime;
            })
        )
        CELL_PHONE_BUZZ
        KANADE_TEXT("hey there! I was", "going to head to the", "store to buy some", "groceries")
        KANADE_TEXT("want to meet up?")
        MC("sure, I've got some", "time today")
        KANADE_TEXT("ok, the one by me", "is 111 main street.", "could you get there", "in an hour or so?")
        MC("yea, that works for me!")
        EMPTY("(you make your way", "to the grocery store)")
        FADE_OUT
        FREE
        BG_GROCERY_STORE
        FADE_IN
        MC("hmm no Kanade?", "maybe she is late?")
        KANADE("oi! hello!")
        SHOW_KANADE_NORMAL
        MC("oh there you are!", "nice to see you!")
        KANADE("glad you could make it.", "did you have anything", "else going on?")
        if(KANADE_WEEKEND_ACTIVITY == main_character_state::cleaning) {
            MC("well I was cleaning", "up my apartment. But", "I was able to finish", "just before leaving")
            //! \kanade_maybe can't stand when things are dirty
            KANADE("nice! I was cleaning this", "morning too! I can't", "stand when certain things", "are dirty")
        } else if(KANADE_WEEKEND_ACTIVITY == main_character_state::fancy_meal) {
            MC("I was thinking about", "cooking a fancy meal", "but couldn't figure", "out what to make")
            KANADE("oh! well if it's", "baking, then I've got", "tons of recipies and", "ideas!")
            MC("Do you ever make", "larger meals?", "like specialty pasta", "or soups?")
            KANADE("not really, my mom", "handles most of those", "things so I've never", "really bothered")
        } else if(KANADE_WEEKEND_ACTIVITY == main_character_state::watching_anime) {
            MC("oh nothing imporant", "just watching some anime")
            //! \kanade_maybe watches anime
            KANADE("wait you watch anime", "too! finally, someone else", "in the office!!")
            KANADE("do you like any", "romance anime? those", "are my favorite!")
            MC("from time to time", "I really watch a bunch", "of everything")
            KANADE("that is cool too!", "alwaysing giving stuff", "a chance")
        }
        KANADE("well let's look around.", "I still need to grab", "some things for these", "muffins")
        MC("we could always split", "up if you want me", "to grab a thing or", "two")
        KANADE("I suppose that would", "make things go faster...", "hmm...")
        KANADE("ok grab these two", "things: granulated sugar", "and vanilla bean extract")
        MC("ok I'm on it!")
        HIDE
        HANDLE_EMERGENCY
        MC("*ugh* I don't", "have time for that now!")
        MC("ok here is the baking", "aisle. lets see...", "wow! there is way more", "sugar than I thought...")
        MC("which one should I", "pick?")
        MENU(
            CHOICE("brown sugar", [](){
                MC("this brown sugar looks", "tasty!")
                KANADE_INGREDIENT_1 = main_character_state::brown_sugar;
            }),
            CHOICE("powdered sugar", [](){
                MC("powdered sugar goes", "well with everything!")
                KANADE_INGREDIENT_1 = main_character_state::powdered_sugar;
            }),
            CHOICE("granulated sugar", [](){
                MC("granulated sugar goes", "just like she asked!")
                KANADE_INGREDIENT_1 = main_character_state::granulated_sugar;
            })
        )
        MC("and that just leaves", "the extract...", "hmm which one did", "she say?")
        MENU(
            CHOICE("tamarind extract", [](){
                MC("tamarind extract, maybe", "this could work...")
                KANADE_INGREDIENT_2 = main_character_state::tamarind_extract;
            }),
            CHOICE("vanilla bean extract", [](){
                MC("vanilla bean extract!", "shopping is so easy!")
                KANADE_INGREDIENT_2 = main_character_state::vanilla_bean_extract;
            }),
            CHOICE("coffee bean extract", [](){
                MC("coffee bean extract?", "why not!")
                KANADE_INGREDIENT_2 = main_character_state::coffee_bean_extract;
            })
        )
        MC("yo Kanade! I found", "the items you asked for!")
        auto correct_1 = KANADE_INGREDIENT_1 == main_character_state::granulated_sugar;
        auto correct_2 = KANADE_INGREDIENT_2 == main_character_state::vanilla_bean_extract;
        if(correct_1 && correct_2) {
            KANADE("brilliant! I knew", "I could count of you!")
        } else if ((correct_1 && !correct_2) || (!correct_1 && correct_2)) {
            KANADE("well, you only got", "one correct...", "but the glass is half", "full, right?")
            KANADE("let's go swap it out!")
            EMPTY("(you head back to", "the baking isle to", "replace the wrong item)")
        } else if (KANADE_INGREDIENT_1 == main_character_state::brown_sugar && KANADE_INGREDIENT_2 == main_character_state::coffee_bean_extract) {
            KANADE("hmm...", "it isn't what I", "asked for...")
            KANADE("BUT! this could be", "the start of mean", "coffee cake! wonderful", MCF("idea, {}!"))
            if(KANADE_WEEKEND_ACTIVITY == main_character_state::fancy_meal) {
                MC("my culinary ability", "exceeds mere mortals!", "bask in my greatness!")
                KANADE("HAHAHA", MCF("{}?"), "have you been watching", "too much TV?")
                MC("oh, sorry!", "did I say that out", "loud?", "(oops!)")
            } else {
                MC("haha well let's", "call that a lucky guess...")
            }
        } else {
            KANADE(MCF("{}..."), "did you get enough", "sleep last night?")
            KANADE("these aren't what I", "asked for at all...", "*sigh*")
            KANADE("it's alright, Let's go", "replace them.")
            EMPTY("(you head back to", "the backing isle to replace", "both items)")
        }
        KANADE("alright, we're all done.", "let's head to the", "checkout area")
        EMPTY("(you help empty the", "cart at checkout and", "head outside with", "Kanade)")
        KANADE("want to walk back", "with me?", "I'll even let you", "hold a bag!")
        MC("haha sure!")
        MENU(
            CHOICE("the lighter one", [](){
                MC("could I take the", "lighter one?")
                KANADE("sure! take this one!")
            }),
            CHOICE("the heavier one", [](){
                MC("I can take the heavier", "one")
                KANADE("oh... well...", "I was hoping to get", "a bit of exercise...")
                KANADE("here!")
            }),
            CHOICE("both bags!", [](){
                MC("I can cary both", "of the bags!")
                KANADE("but what if I want", "to carry one? I", "invited you after", "all...")
                KANADE("here, take this one")
            })
        )
        EMPTY("(Kanade hands you", "the bag)")
        FADE_OUT
        FREE
        BG_STREET
        FADE_IN
        SHOW_KANADE_NORMAL
        MC("so do you have any", "other hobbies other", "than baking?")
        KANADE("hmm outside of baking", "mostly just reading")
        //! \kanade likes reading either at the park or the library
        KANADE("I'll usually head to", "the library or the park", "on the weekends to", "read")
        if(state::st.im_state.progress[character::KANADE] < 2) {
            KANADE("I also listen to", "the baseball games with", "my family")   
        } else {
            KANADE("I already mentioned", "listening to baseball", "the other day...")
        }
        KANADE("but I don't really", "get outside besides", "that.")
        MC("so you don't play", "any sports?")
        KANADE("not really, I never", "really found anything", "I like...")
        //! \kanade feels guilty about not playing sports
        KANADE("I do feel a bit", "guilty about not", "'working out' like", "other people do...")
        //! \kanade goes for walks early in the morning
        KANADE("so I try to go for", "a walk early in the", "morning. not every", "day, though")
        KANADE("that way, I can at", "least say I did", "something!")
        //! \kanade likes cats
        KANADE("and who knows, maybe", "I'll see a cat along", "the way!")
        MC("walks are a great", "way to start the day!", "I know plenty of", "people who do that")
        EMPTY("(you finish your walk", "back to Kanade's place)")
        KANADE("alright we're here!", "I'll take that")
        EMPTY("(you hand the bag", "back to Kanade)")
        KANADE("thank you, again!", "it was fun to get", "out")
        MC("I enjoyed it, too!", "have a nice rest", "of the day!")
        KANADE(MCF("see you, {}!"))
        HIDE
        FADE_OUT
        MC("(that went well!)")
    }
    //! \brief kanade is doing some volunteer work
    void kanade_weekend_1() {
        // volunteer work
        CELL_PHONE_BUZZ
        KANADE_TEXT("hey! are you", "interested in", "helping do some", "volunteer work?")
        MC("sure, I can help", "out!")
        KANADE_TEXT("sweet! the warehouse", "is at 1500 S Main", "street. wear some", "casual clothing!")
        KANADE_TEXT("the shift starts at", "11 so try to get", "there a bit before", "that")
        MC("alright, see you there", "10:50!")
        EMPTY("(you head out at", "10:30 on your way", "to the warehouse)")
        FADE_OUT
        FREE
        BG_WAREHOUSE
        FADE_IN
        KANADE("over here!", MCF("{}!"))
        SHOW_KANADE_NORMAL
        MC("hey! I made it!")
        KANADE("nice! thank you", "coming here!")
        switch(KANADE_WEEKEND_ACTIVITY) {
        case main_character_state::cleaning:
            KANADE("I know you'd rather", "be cleaning but this", "sort of thing", "is still important!")
            break;
        case main_character_state::fancy_meal:
            KANADE("maybe someone like", "you would rather cook", "something with the", "extra time...")
            KANADE("I know I'd rather", "be baking...", "but I still need", "to give back")
            break;
        case main_character_state::watching_anime:
            KANADE("I know you'd rather", "be watching anime but", "this can be", "just as fun!")
            break;
        default: break;
        }
        MC("haha its ok!", "it's good to take", "a break from the", "usual routine")
        KANADE("so I'll explain", "this a bit before", "the supervisor comes", "around")
        KANADE("basically, we just", "need to pack various", "items into each box")
        KANADE("one team will help", "out with the source", "boxes")
        KANADE("another team will", "do the packing")
        KANADE("and a final team", "will stack the packed", "boxes onto a pallet")
        MC("what exactly are", "we packing?")
        KANADE("oh this is a", "food warehouse!", "so we pack donated", "food for various")
        KANADE("families to pick", "up. usually they source", "food from grocery", "stores...")
        KANADE("and need to do the", "work to sort and", "distribute it")
        MC("ok, I understand now!")
        KANADE("oh look! they're here", "let's head over and", "listen")
        HANDLE_EMERGENCY
        HIDE
        WAREHOUSE_SUPERVISOR("welcome all!", "thanks for coming", "to the Food Warehouse", "to help pack!")
        WAREHOUSE_SUPERVISOR("we wouldn't be here", "without your support,", "so thank you")
        EMPTY("*cheers and applause*")
        WAREHOUSE_SUPERVISOR("alright, now the", "main event. We're going", "to split up by", "team")
        WAREHOUSE_SUPERVISOR("if you've never", "volunteerd with us", "before, don't worry", "you can switch")
        WAREHOUSE_SUPERVISOR("teams during the", "shift")
        WAREHOUSE_SUPERVISOR("ok...")
        WAREHOUSE_SUPERVISOR("let's start with the", "unloading team", "who wants to join", "the unloading team?")
        MENU(
            CHOICE("join", [](){
                WAREHOUSE_SUPERVISOR("ok those people", "who are on the", "unloading, please", "head over there")
            }),
            CHOICE("wait", [](){
                WAREHOUSE_SUPERVISOR("ok those people", "who are on the", "unloading, please", "head over there")
                WAREHOUSE_SUPERVISOR("now for the packing", "team. who wants to", "pack?")
                MENU(
                    CHOICE("join", [](){
                        WAREHOUSE_SUPERVISOR("ok packing team: please", "make your way over", "to the tables")
                    }),
                    CHOICE("wait", [](){
                        WAREHOUSE_SUPERVISOR("ok packing team: please", "make your way over", "to the tables")
                        WAREHOUSE_SUPERVISOR("that means the rest", "of you are on the", "stacking team")
                        WAREHOUSE_SUPERVISOR("you can head over", "to the pallet area", "for stacking instructions")
                    })
                )
            })
        )
        EMPTY("(you make your", "way over)")
        WAREHOUSE_TEAM_LEAD("welcome, everyone!", "I'm the team lead", "thanks for joining!")
        WAREHOUSE_TEAM_LEAD("your task is simple", "follow the instructions", "on this sheet")
        WAREHOUSE_TEAM_LEAD("let do some work!")
        MC("ok let's see what", "this instructions say")
        int success = 0;
        WAREHOUSE_INSTRUCTIONS("GO UP!")
        if(minigame_bugs::round(bn::keypad::key_type::UP)) {success++;}
        WAREHOUSE_INSTRUCTIONS("GO DOWN!")
        if(minigame_bugs::round(bn::keypad::key_type::DOWN)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO RIGHT!")
        if(minigame_bugs::round(bn::keypad::key_type::RIGHT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO DOWN!")
        if(minigame_bugs::round(bn::keypad::key_type::DOWN)) { success++;}
        WAREHOUSE_TEAM_LEAD("ok time for a quick", "water break")
        SHOW_KANADE_NORMAL
        KANADE(MCF("so, {}?"), "how do you like", "it so far?")
        MENU(
            CHOICE("not bad", [](){
                MC("I think it is", "pretty cool!", "I could do this", "all day!")
                KANADE("wonderful!", "I'm glad to", "hear that!")
                KANADE("let's head back, then")
            }),
            CHOICE("i'm tired", [](){
                MC("I am pretty tired")
                KANADE("so a 'good' tired", "or a 'bad' tired?")
                MC("a...", "well maybe not a", "'bad' tired...")
                KANADE("well, it's ok", "to not enjoy it.", "it is work, after", "all!")
                KANADE("but if you have", "the energy, why not", "try finishing", "the shift")
                MC("ok, I think I can", "do that!")
                KANADE("neat, let's head back")
            }),
            CHOICE("i hate it", [](){
                MC("I find it pretty", "boring, I think I'm", "going to head back", "home")
                KANADE("fair enough, thanks for", "trying it out!")
                MC_VOLUNTEERING_STATE = main_character_state::does_not_enjoy_volunteering;
            })
        )
        if(MC_VOLUNTEERING_STATE == main_character_state::does_not_enjoy_volunteering) {
            HIDE
            FADE_OUT
            MC("I don't know why", "but I have a bad", "feeling about that...")
            state::st.rel_state.reset(character::KANADE);
            return;
        }
        HIDE
        WAREHOUSE_TEAM_LEAD("welcome back!", "let's get back to it!")
        MC("what did those", "instructions say", "again?")
        WAREHOUSE_INSTRUCTIONS("GO RIGHT!")
        if(minigame_bugs::round(bn::keypad::key_type::RIGHT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO DOWN!")
        if(minigame_bugs::round(bn::keypad::key_type::DOWN)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO UP!")
        if(minigame_bugs::round(bn::keypad::key_type::UP)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO RIGHT!")
        if(minigame_bugs::round(bn::keypad::key_type::RIGHT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO DOWN!")
        if(minigame_bugs::round(bn::keypad::key_type::DOWN)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO RIGHT!")
        if(minigame_bugs::round(bn::keypad::key_type::RIGHT)) { success++;}
        WAREHOUSE_INSTRUCTIONS("GO LEFT!")
        if(minigame_bugs::round(bn::keypad::key_type::LEFT)) { success++;}
        WAREHOUSE_TEAM_LEAD("alright, you're all", "done for the day!", "thanks for your help!")
        WAREHOUSE_SUPERVISOR("everyone!", "come over here!")
        WAREHOUSE_SUPERVISOR("over here!")
        EMPTY("(everyone congregates", "near the front of", "the warehoues)")
        WAREHOUSE_SUPERVISOR("Thank you all for", "helping out here!")
        WAREHOUSE_SUPERVISOR("I know you'd rather", "be doing more", "interesting things", "on a Saturday")
        WAREHOUSE_SUPERVISOR("That's why we find", "any way we can to", "thank our volunteers")
        WAREHOUSE_SUPERVISOR("Fortunately, one grocery", "store had an overstock", "of strawberries and", "needed to make room")
        WAREHOUSE_SUPERVISOR("Please take as many", "as you can. We won't", "be able to distribute", "these")
        WAREHOUSE_SUPERVISOR("so don't let them", "go to waste!")
        WAREHOUSE_SUPERVISOR("take care and I", "hope to see you", "next week!")
        //! \kanade 's brother likes starberries
        SHOW_KANADE_HAPPY
        KANADE("woah! look how many!", "my brother will love", "these!")
        MC("hmm maybe I should", "grab a few packs")
        SHOW_KANADE_NORMAL
        KANADE("well I hope you", "enjoyed the last bit", "of the shift.")
        MC("yea, it wasn't so", "bad, I wouldn't mind", "coming back here!")
        KANADE("oh nice!", "well...")
        KANADE("I'm going to head", "back then!", "See you at work!")
        MC("see ya, Kanade!")
        HIDE
        FADE_OUT
        MC("(that went well!)")
    }
    //! \brief kanade is sick from doing too much work (family is also gone camping)
    void kanade_weekend_2() {
        MC("*phew* Saturday is", "finally here!")
        switch(KANADE_WEEKEND_ACTIVITY) {
        case main_character_state::cleaning:
            MC("probably a good time to", "catch up on some cleaning") break;
        case main_character_state::fancy_meal:
            MC("finally, I have time", "to cook a delicous meal!") break;
        case main_character_state::watching_anime:
            MC("at last!", "six consecutive hours", "ALL FOR ANIME!") break;
        default:
            MC("hack the planet!")
        }
        CELL_PHONE_BUZZ
        KANADE_TEXT(MCF("hey {}!"), "so some bad news...", "my family has left this", "weekend on to go camping")
        KANADE_TEXT("I didn't want to go", "with them as I was", "feeling sick on", "Friday night...")
        KANADE_TEXT("I've managed to get", "even more sick! so", "I can't get out", "of bed at the moment")
        KANADE_TEXT("could you bring some", "food over? I think", "anything warm will", "do the trick")
        MC("sure! I can head", "to the store now to", "pick something up")
        KANADE_TEXT(MCF("thank you, {}!"), "I owe you one!")
        MC("ok, time to head", "to the store")
        SCENE_END
        BG_GROCERY_STORE
        FADE_IN
        MC("alright, something warm...", "what should I get?")
        MENU(
            CHOICE("frozen pizza", [](){
                MC("she probably hasn't eaten", "in a while. at least", "she'll have leftovers")
                MC("you know what...")
                MC("I'll get two of", "them just in case", "I get the wrong one")
                KANADE_SICK_ITEM = main_character_state::frozen_pizza;
            }),
            CHOICE("soup can", [](){
                MC("well, I can't go", "wrong with soup. Can't", "say I know what she", "likes so maybe")
                MC("I'll just go with", "some vegetable one...", "actually I'll get", "two different ones")
                KANADE_SICK_ITEM = main_character_state::soup;
            }),
            CHOICE("macaroni and cheese", [](){
                MC("easy, I'll get macaroni", "and cheese. everyone", "like that, right?")
                MC("should be pretty", "simple to make, too")
                KANADE_SICK_ITEM = main_character_state::mac_and_cheese;
            })
        )
        MC("ok, I'm all set", "let's head to Kanade's", "place")
        EMPTY("(you get directions from", "Kanade and make your", "way over)")
        SCENE_END
        MC("looks like the front", "door is open...")
        EMPTY("(you step inside)")
        BG_KITCHEN
        FADE_IN
        MC("HELLO??", "YOOHOO!")
        KANADE("*quiet*", "yes, up here!")
        SCENE_END
        BG_KANADES_ROOM
        FADE_IN
        SHOW_KANADE_SICK
        KANADE(MCF("hey {}!"), "*cough*", "welcom-", "*cough*")
        MC("woah that's alright", "you can chill out")
        KANADE("ok")
        MC("do you want me", "to get the food started?")
        switch(KANADE_SICK_ITEM) {
        case main_character_state::frozen_pizza:
            MC("I bought a couple", "pizzas. Hopefully you", "like the flavors...") break;
        case main_character_state::soup:
            MC("I got two kinds of", "soup. I'm not really", "sure which flavor", "you like") break;
        case main_character_state::mac_and_cheese:
            MC("I got you some Mac", "and Cheese. I could", "find something to", "add to it, too.") break;
        default: break;
        }
        KANADE("sure, I haven't", "had much today.", "only some leftover", "bread")
        MC("alright, I'll head", "back downstairs and", "get this cooked")
        KANADE("I'll be-*cough*", "here")
        EMPTY("(you head to the", "kitchen downstairs)")
        SCENE_END
        BG_KITCHEN
        FADE_IN
        switch(KANADE_SICK_ITEM) {
        case main_character_state::frozen_pizza:
            MC("let's get this", "oven fired up") break;
        case main_character_state::soup:
        case main_character_state::mac_and_cheese:
            MC("ok let's get the", "stove fired up") break;
        default: break;
        }
        MC("oh!")
        MC("surely, they have some", "tea around here...")
        MC("maybe this drawer?")
        MC("hmm... this cabinent?")
        MC("aha! found it!")
        MC("oh and a kettle!")
        EMPTY("(you heat some water", "for the tea)")
        SCENE_END
        BG_KANADES_ROOM
        FADE_IN
        SHOW_KANADE_SICK
        MC("I made you some", "tea!")
        KANADE("ahh thank-*cough*", "you")
        MC("well the food will", "be ready in 10 to", "20 minutes")
        if(KANADE_WEEKEND_ACTIVITY == main_character_state::watching_anime) {
            MC("so were you catching", "up on watching any", "anime?")
            KANADE("yes, a bit")
            KANADE("mostly *cough*", "a new series")
            EMPTY("(Kanade shows you", "her phone)")
            MC("oh I've seen this", "mone mentioned online!", "I haven't seen it", "yet")
            KANADE("its good!", "*cough*", "very cute")
        } else {
            MC("so what were you", "up to today?", "maybe reading a bit?")
            KANADE("only-*cough*", "a bit")
            KANADE("audio-book is easier")
            MC("oh true, easier to", "stay warm")
        }
        MC("let me check on the", "food, one moment...")
        SCENE_END
        EMPTY("(you head downstairs", "...)")
        EMPTY("(...and bring the", "food back up)")
        FADE_IN
        SHOW_KANADE_SICK
        KANADE("thank you for", "*cough* the food!")
        HANDLE_EMERGENCY
        KANADE("if you need to", "go, thats ok")
        MC("it's alright", "it isn't something", "that is urgent")
        MC("how did you get", "sick anyway?", "were you around", "on Friday?")
        //! \kanade sick from working or from stress
        KANADE("I think I'm *cough*", "working too much")
        KANADE("maybe that or", "stress from the *cough*", "backlog")
        KANADE("there are always", "*cough* so many things", "to do...")
        MC("oh that sounds", "miserable...")
        MC("maybe you should", "take a vacation. I'm", "sure someone would", "cover for you")
        KANADE("would you?")
        MC("absolutely, I would!", "Though maybe only", "a quarter of", "your tasks")
        MC("I don't think I've", "been at WidgetCorp", "long enough to", "do much more")
        KANADE("haha *cough*", "well...")
        KANADE("I'll see how I am", "tomorrow. maybe a hot", "meal is *cough* all", "I need")
        EMPTY("(Kanade goes back", "to eating)")
        MC("oh is there a", "baseball game on", "tonight?")
        MC("maybe we could", "listen to that for", "a bit")
        KANADE("good idea.", "there is one but", "the radio *cough* is", "downstairs")
        MC("ok let me see if", "I can find it and", "bring it up")
        SCENE_END
        EMPTY("(you head downstairs", "again and search for", "the radio)")
        MC("oh right, the kitchen!")
        EMPTY("(you haul the radio", "up the stairs)")
        BG_KANADES_ROOM
        FADE_IN
        SHOW_KANADE_SICK
        KANADE("wonderful!")
        MC("plug it in...", "turn it on...", "and...")
        RADIO("... and that marks the", "end of the second.", "What do you think", "Rick? done yet?")
        KANADE("ahh! thank you!")
        RADIO("well, Alex it ain't", "over till its over.", "and I've seen it", "aaaalllll!")
        MC("so Rick and Alex?")
        KANADE("they are *cough*", "the commentators.", "they're pretty funny")
        MC("ahh ok")
        EMPTY("(Kanade explains the", "various element of", "the game)")
        EMPTY("(You listen for a", "few innings but", "you can tell Kanade", "is feeling tired)")
        MC("alright, I think I'll", "head out now! Thank", "you for the invitation")
        MC("please get well soon!", "and let me know if", "you need anything", "tomorrow")
        KANADE("ok!", "thank you-*cough*")
        SCENE_END
        MC("(that went well!", "well...", "for me)")
    }
    //! \brief kanade is baking food for her family
    void kanade_weekend_3() {
        MC("will today be the", "day?")
        switch(KANADE_WEEKEND_ACTIVITY) {
        case main_character_state::cleaning:
            MC("will I finally finish", "cleaning this place?") break;
        case main_character_state::fancy_meal:
            MC("will I finally cook", "the fancy meal?") break;
        case main_character_state::watching_anime:
            MC("will I finally get", "to watch anime?") break;
        default: break;
        }
        CELL_PHONE_BUZZ
        KANADE_TEXT("I have a dinner party", "with some friends", "can you help me shop", "for some things?")
        MC("sure, I'd love", "to help. Where should", "we meet?")
        KANADE_TEXT("Let's meet at the", "grocery store around", "11am. sound good?")
        MC("sounds good, I'll meet", "you there!")
        EMPTY("(the morning passes", "and you head over", "to the store)")
        SCENE_END
        BG_GROCERY_STORE
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE(MCF("hey {}!"), "how's it going?")
        MC("hey there Kanade!", "I'm doing quite well")
        switch(KANADE_WEEKEND_ACTIVITY) {
        case main_character_state::cleaning:
            MC("I was just cleaning", "my place up. I", "only have a few", "things left")
            KANADE("wow you might contest", "my mom at the cleanest", "house award!")
            KANADE("that's three weekends", "now! I know she'd be", "impressed")
            MC("just doing my best", "it isn't really that", "surprising")
            break;
        case main_character_state::fancy_meal:
            MC("just some prep work", "for a fancy meal later!")
            MC("though I might decide", "to make it tomorrow", "instead...")
            KANADE("oh, you must", "really enjoy cooking!")
            break;
        case main_character_state::watching_anime:
            MC("I was able to get", "a few anime episodes", "in, so its an easy", "start to the day")
            KANADE("haha I watched", "some last night!", "hard to put down", ", you think?")
            MC("difficult, but not", "impossible! I managed", "to get here!")
            KANADE("haha so did I!")
            break;
        default: break;
        }
        KANADE("alright, let's take", "a look around. oh...")
        KANADE("should we split", "up again?")
        MENU(
            CHOICE("no", [](){
                MC("let's stay together", "I think that will", "be more fun")
                KANADE("ok, works for me!")
                KANADE("first up we need to", "get some flour")
                EMPTY("(you make your", "way to the baking isle)")
                MC("there, near the bottom!")
                KANADE("oh nice, could you", "please grab one bag?")
                MC("sure")
                EMPTY("(one bag of sugar", "makes its way into", "the cart)")
                KANADE("I think there is flour", "somewhere here...")
                MC("hmmm...", "looks like it is near", "the back of this aisle")
                KANADE("ok you grab that", "I'll get these chocolate", "chips")
                EMPTY("(you fetch the flour)")
                KANADE("finally, we need to", "get some butter and eggs.", "let's head over")
                MC("so what exactly are", "you baking this weekend?")
                KANADE("I'll be making some blueberry", "muffins!")
                KANADE("oh! BLUEBERRIES!", "I'll go grab those", "and meet you back", "by the diary")
                MC("sounds good")
                EMPTY("(you momentarily split", "up to grab some ingredients", ", and soon reocnvene in", "the dairy section)")
                MC("here are some eggs", "and butter!")
                KANADE("wonderful!", "that should be everything!")
                KANADE_INGREDIENT_3 = main_character_state::blueberries;
                KANADE_INGREDIENT_4 = main_character_state::butter_and_eggs;
            }),
            CHOICE("yes", [](){
                MC("sure, it worked well", "last time, right?")
                KANADE("ok, great!", "we need some fruit...", "blueberries should", "work. get those!")
                KANADE("oh, butter and eggs!", "grab those too!")
                MC("got it!", "no mistakes this time!")
                KANADE("ok meet by the registers", "when you're done")
                HIDE
                MC("ok, gotta get the fruit", "and dairy")
                EMPTY("(you head to the", "produce section)")
                MC("which fruit was it", "again?")
                MENU(
                    CHOICE("banana", [](){
                        // wrong option
                        MC("bananas! I like those!")
                        KANADE_INGREDIENT_3 = main_character_state::banana;
                    }),
                    CHOICE("blueberry", [](){
                        // ok option
                        MC("How about these", "blueberries?")
                        KANADE_INGREDIENT_3 = main_character_state::blueberries;
                    }),
                    CHOICE("strawberry", [](){
                        // brother favorite
                        MC("Let's go with the", "strawberries!")
                        KANADE_INGREDIENT_3 = main_character_state::strawberries;
                    })
                )
                MC("ok that just leaves", "the diary items")
                EMPTY("(you head to the", "dairy aisle)")
                MC("which dairy items do", "I need?")
                MENU(
                    CHOICE("butter, eggs", [](){
                        // normal option: muffins
                        MC("butter and eggs!", "(I'm so good at this!)")
                        KANADE_INGREDIENT_4 = main_character_state::butter_and_eggs;
                    }),
                    CHOICE("heavy w. cream, eggs", [](){
                        // chef option: crepes
                        MC("heavy whipping creme?", "this could be delightful!")
                        KANADE_INGREDIENT_4 = main_character_state::heavy_whipping_cream_eggs;
                    }),
                    CHOICE("chocolate milk, eggs", [](){
                        // wrong option
                        MC("chocolate milk could", "make this dish excellent!")
                        KANADE_INGREDIENT_4 = main_character_state::chocolate_milk_eggs;
                    })
                )
                EMPTY("(you head to the front", "to meet Kanade)")
                KANADE("oh you got them!", "nic- wait!")
                KANADE("what did you get this", "time?")
                bool wrong_items = false;
                switch(KANADE_INGREDIENT_3) {
                case main_character_state::banana:
                case main_character_state::blueberries:
                    KANADE("oh nice, blueberries!")
                    break;
                case main_character_state::strawberries:
                    KANADE("starberries! not", "what I asked for but", "my brother will love", "these")
                    break;
                default:
                    KANADE("hmm I don't think these", "will work...")
                    wrong_items = true;
                }
                switch(KANADE_INGREDIENT_4) {
                case main_character_state::butter_and_eggs:
                    KANADE("butter and eggs!", "nice!")
                    break;
                case main_character_state::heavy_whipping_cream_eggs:
                    if(wrong_items) {
                        KANADE("whipping cream?", "no no this won't", "work either...")
                    } else {
                        KANADE("heavy whipping cream...", "maybe we could make", "crepes instead?")
                        KANADE("yea, let's do that!")
                    }
                    break;
                default:
                    KANADE("no no, these", "won't do...")
                    wrong_items = true;
                }
                if(wrong_items) {
                    KANADE("let's head back and", "grab the right things...")
                    EMPTY("(you make your way", "back to exchange the item)")
                }
                KANADE("alright, we're all", "set. let's checkout and", "head home.")
            })
        )
        EMPTY("(you buy the items", "and start to walk to", "Kanade's place)")
        SCENE_END
        BG_STREET
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE("if it's not a problem", "could you help me", "bring these things", "back home?")
        if(handle_emergency([](){
            KANADE("ok... I *sniff*", "see how it is...")
            EMPTY("(she runs away)", "", "(your relationship", "has reset)")
            state::st.rel_state.reset(character::KANADE);
        })) {
            return;
        }
        KANADE("all good?")
        MC("yea, nothing important...")
        // TODO walk, house + family conversation
        MC("so, I didn't ask yet", "but would you want to", "help me make these?")
        MC("I know my family is", "around so maybe you", "don't like being bothered", "while you cook")
        MC("oh that's alright", "with me. who knows,", "maybe they have some", "cool stories to share")
        KANADE("haha if you want", "stories, my brother has", "an encyclopedia of them")
        KANADE("that kid gets in", "trouble like its his", "job...")
        MC("how old is your", "brother? is he very", "young?")
        KANADE("oh no he is older", "than I am...", "I just call him a kid", "because he's annoying")
        MC("oh... well I'll", "be careful, I guess")
        KANADE("hahaha it'll make", "more sense when you meet", "him")
        EMPTY("(you finish the walk", "to Kanade's house", "in good spirts)")
        SCENE_END
        BG_LIVING_ROOM
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE("here we are!")
        KANADES_MOTHER("welcome back!", "oh!", "you brought a friend!")
        KANADES_FATHER("welcome, friend!")
        MC("hello, I'm", MCF("{}"), "pleased to meet you")
        KANADES_MOTHER("make yourself comfortable")
        KANADES_FATHER("do you want something", "to drink? the game", "is about to start")
        MC("hmm, just water would", "be nice")
        KANADE("oh I can get that!", "we can start cooking", "soon, I'll need your", MCF("help, {}"))
        MC("okee dokee!")
        KANADES_BROTHER("who the heck says", "'okee dokee'??", "what year is it?")
        MC("wel-")
        //! \kanade 's brother's name is Greg
        KANADE("oh buzz off Greg!", "go off and play some", "games since you're", "'SO good at them'")
        KANADES_BROTHER("*hmph* maybe I WILL", "play some games that", "I'm good at!")
        KANADES_BROTHER("*muttering* way", "better than OTHER", "people in this family...")
        KANADE("*hmph*")
        EMPTY("(Kanade's brother", "goes back upstairs)")
        MC("ok...", "I think I understand", "what your brother is", "like!")
        KANADE("yea...", "he's like that.")
        KANADE("well, let's get started", "shall we?")
        EMPTY("(you head to the", "kitchen)")
        SCENE_END
        BG_KITCHEN
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE("here: crack the eggs")
        COOKING_INSTRUCTIONS("lift the egg (UP)")
        minigame_bugs::round(bn::keypad::key_type::UP);
        COOKING_INSTRUCTIONS("and crack it (DOWN)")
        minigame_bugs::round(bn::keypad::key_type::DOWN);
        KANADE("ok now it's time", "to mix the ingredients")
        for(int times = 0; times < 10; times++) {
            COOKING_INSTRUCTIONS(FMT_24("swirl left ({}/10)", times))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
            COOKING_INSTRUCTIONS(FMT_24("swirl right ({}/10)", times))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
        }
        auto recipe_crepes = 
            (KANADE_INGREDIENT_3 == main_character_state::blueberries
                || KANADE_INGREDIENT_3 == main_character_state::strawberries)
            &&
            (KANADE_INGREDIENT_4 == main_character_state::heavy_whipping_cream_eggs);
        if(!recipe_crepes) {
            KANADE("ok, looks good!", "let's fill this pan")
            EMPTY("(you pour the batter", "into the pan)")
            KANADE("I've already preheated", "the oven so these", "can go in now.")
            EMPTY("(Kanade places the tray", "in the oven")
        }
        KANADE("sweet!", "last step is slicing", "the fruit!")
        for(int times = 0; times < 10; times++) {
            COOKING_INSTRUCTIONS(FMT_24("slice up ({}/10)", times))
            minigame_bugs::round(bn::keypad::key_type::UP);
            COOKING_INSTRUCTIONS(FMT_24("slice down ({}/10)", times))
            minigame_bugs::round(bn::keypad::key_type::DOWN);
        }
        KANADE("great work!")
        if(recipe_crepes) {
            KANADE("I'll head back in", "a bit and get them", "started.")
        } else {
            KANADE("now we wait!")
        }
        KANADE("let's head to the", "family room. sounds like", "the game has started")
        SCENE_END
        BG_LIVING_ROOM
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADES_MOTHER("did you get everything", "started?")
        if(recipe_crepes) {
            KANADE("I'll head back in", "a bit and start them." )
        } else {
            KANADE("yup! the food should", "be ready in 30 minutes", "or so")
        }
        KANADES_MOTHER("wonderful!")
        KANADES_MOTHER(MCF("so {}"), "I heard you went", "to volunteer with", "Kanade last weekend.")
        KANADES_MOTHER("how did that go?")
        auto enjoys_volunteering = MC_VOLUNTEERING_STATE != main_character_state::does_not_enjoy_volunteering;
        if(enjoys_volunteering) {
            MC("well, let's just", "say it wasn't for me")
            KANADES_MOTHER("why is that?")
            MC("I found it a bit", "boring for my taste")
            MC("I'm on the programming", "team so our work is", "a bit more exciting", "than moving some")
            MC("boxes and food around")
            KANADES_MOTHER("oh...", "well it's good to have", "tried it once, at least")
        } else {
            MC("it was alright!", "its difficult to say", "work is fun but ...")
            MC("the atmosphere is", "supportive which makes", "it much easier")
            KANADES_MOTHER("it's good to help", "out those around you")
        }
        KANADES_MOTHER("oh thank you for", "also taking care of", "Kanade the other weekend")
        KANADES_MOTHER("Kanade isn't one to", "get sick often so we", "figured it would be", "something small")
        KANADE("MOM I WAS FINE")
        KANADES_MOTHER("Kanade isn't one to", "burden the others around", "her")
        KANADES_MOTHER("its ok to ask for", "help from the people", "around you.")
        KANADES_MOTHER("you're lucky to", MCF("have {}"), "around!")
        KANADE("yes mom I know!")
        MC("it really wasn't", "a big thing, just", "me cooking a small", "meal...")
        KANADES_MOTHER("but Kanade doesn't", "ever bring anyone", "around-")
        KANADE("MOM!")
        KANADES_MOTHER("ok let's listen to", "the game until the", "food is ready")
        bool is_cook = KANADE_WEEKEND_ACTIVITY == main_character_state::fancy_meal;
        bool expert_cook_1 =
            (KANADE_INGREDIENT_1 == main_character_state::brown_sugar)
            && (KANADE_INGREDIENT_2 == main_character_state::coffee_bean_extract);
        bool expert_cook_2 =
            (KANADE_INGREDIENT_3 == main_character_state::strawberries)
            && (KANADE_INGREDIENT_4 == main_character_state::heavy_whipping_cream_eggs);
        if(enjoys_volunteering && is_cook && expert_cook_1 && expert_cook_2) {
            KANADES_FATHER("what did you end", "up making anyway?")
            KANADE("we made some crepes!")
            KANADES_FATHER("woah! fancy!")
            KANADE("well, I haven't", "started cooking them", "but all the ingredients", "are ready")
            KANADE("oh, we have starberries!", "Greg's favorite!")
            KANADES_FATHER("hey I like them", "too!")
            KANADE("haha I guess you", "can have some, too")
            KANADES_BROTHER("what's the commotion", "in here about?")
            KANADES_MOTHER("we're listening to the", "game! Kanade will", "make some crepes", "pretty soon too!")
            KANADES_FATHER("with strawberries!")
            KANADES_BROTHER("*hmph* I guess", "I'll have to try some...")
            EMPTY("(you enjoy listening", "to the game with Kanade's", "family, eagerly awaiting", "the crepes)")
            KANADE("ok let's head back", "and finish these")
            SCENE_END
            BG_KITCHEN
            KANADE(MCF("so {}"), "...")
            KANADE("well, I'm not really", "good with these things...")
            KANADE("but I wanted to", "say thanks for being", "around and spending", "time with me")
            KANADE("I've enjoyed every", "moment with you")
            KANADE("you're always pushing", "me to explore and", "try new things and I", "want to do")
            KANADE("the same with you!", "it's fun, right?", "having someone to", "try new things with?")
            MC("yes, I enjoy it, too!", "I... well I've", "had a wonderful time", "with you too")
            KANADE("well...", "let's finish these", "up...")
            EMPTY("(you finish cooking the", "crepes and bring them", "to the living room)")
            SCENE_END
            BG_LIVING_ROOM
            SHOW_KANADE_HAPPY
            KANADE("ALL DONE!")
            KANADES_MOTHER("these are so pretty!")
            KANADES_FATHER("ahh they're amazing!", "Thank you, Kanade")
            KANADE("here Greg, even", "one for you...")
            KANADES_BROTHER("...", "thanks")
            KANADE("let's not forget", MCF("{}!"), "thank you,", MCF("{}!"))
            KANADES_MOTHER("thank you,", MCF("{}!"))
            KANADES_FATHER("yes, thank you,", MCF("{}!"))
            KANADES_BROTHER("thanks...", MCF("{}"))
            KANADE(":)")
            SCENE_END
            vnlib::end(vnlib::PERFECT_END);
        } else {
            SCENE_END
            vnlib::end(vnlib::GOOD_END);
        }
    }

    //! \brief rika is shopping for garden supplies
    void rika_weekend_0() {
        RIKA_TEXT(MCF("hey, {}! are"), "you free today?", "I need to pick up", "some gardening supplies")
        MC("Hey Rika. No, I don't", "have any plans so I'm", "free to lend a hand")
        MC("Could you send", "over the address of", "the store?")
        RIKA_TEXT("it's at 565 main street.", "Can you meet me there", "in an hour?")
        MC("yea, that works for me!", "see you then")
        EMPTY("(you wait and then", "head to the store)")
        SCENE_END
        BG_GARDENING_STORE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA(MCF("hey there, {}"), "thanks for making it")
        MC("any time! I've never", "been to the gardening", "store so this should", "be a fun new experience")
        RIKA("haha well it isn't all", "that exciting, I guess", "some of the plants are", "cool to look at")
        RIKA("but make no mistake,", "keeping a garden alive", "is hard work!")
        RIKA("have you had one before?")
        MENU(
            CHOICE("no", [](){
                MC("nope, never had one.", "my family did have", "some pets so that", "almost counts, right?")
                //! \rika_maybe has never had any pets
                RIKA("oh yea, that counts!")
                RIKA("I've never had pets", "myself but I would guess", "that those are much", "more work")
            }),
            CHOICE("yes", [](){
                MC("yea, I had a few plants", "over the years. but I've", "never had enough space", "for a real garden")
                MC("I got the plants from", "a friend so I never", "really looked at getting", "more of them")
                RIKA("oh that is cool")
            })
        )
        MC("so which items", "did you need help with?")
        RIKA("so, I need a few", "things today.")
        RIKA("I am looking for a", "few extra pots and", "two or three new plants")
        MC("two or three plants...", "look how many you", "have to choose from!")
        RIKA("haha, exciting, right?", "that is part of the fun!")
        RIKA("now lets see... what do", "they have in this aisle...")
        MENU(
            CHOICE("hygrangea", [](){
                MC("these are... some", "hygdrangeas")
                RIKA("those could work!", "I have some already but", "not in this color")
            }),
            CHOICE("tulip", [](){
                MC("maybe some tulips?")
                RIKA("yea! those are", "big! though they're only", "around for a short time")
            }),
            CHOICE("lily of the valley", [](){
                MC("what is this? lily", "of the valley?")
                RIKA("oh that's a cute", "one!")
            })
        )
        RIKA("let's go with those.")
        RIKA("I'm not seeing anything", "else here so let's", "check the next room")
        EMPTY("(you head to the", "indoor area)")
        RIKA("hmm what do we have", "here?")
        MENU(
            CHOICE("succulent", [](){
                MC("oo succulents! these", "are supposed to be easy", "to keep, right?")
                RIKA("correct, they are", "pretty good for getting", "started")
                RIKA("though, you need to", "remember to re-pot them", "as they grow")
                RIKA("I won't pick some up", "this trip. I'm looking", "for something more", "colorful")
                MC("oh ok. got it.")
                RIKA("ok, let's grab some", "of those medium pots")
            }),
            CHOICE("lawn ornament", [](){
                MC("what about this lawn", "ornament?")
                RIKA("which one were you", "thinking of?")
                MENU(
                    CHOICE("frog", [](){
                        MC("what about this frog?", "its kinda cute")
                        RIKA("oh that frog is cute!", "I already have one", "like it but I like", "your style!")
                        MC("oh, got it!")
                    }),
                    CHOICE("bird bath", [](){
                        MC("what about this bird", "bath? do you already", "have one?")
                        RIKA("well I don't have", "one but I don't think", "it would look good", "at my place")
                        MC("aww...")
                    }),
                    CHOICE("dragon", [](){
                        MC("oh this dragon looks", "awesome! You should get", "this!")
                        RIKA(MCF("{}, look"), "at the price!")
                        MC("let's see...", "WAIT 500 COINS!")
                        RIKA("haha let's leave that", "one here")
                    })
                )
                RIKA("ok, let's grab some", "of those medium pots")
            }),
            CHOICE("pots", [](){
                MC("here are the pots!", "you needed some of these", "right?")
                RIKA("oh good find!", "yup, two of those medium", "ones")
            })
        )
        MC("these ones?")
        RIKA("yea those should work!")
        EMPTY("(you pick up the pots)")
        RIKA("nice, that's everything!")
        RIKA("oh..." , "actually, let me", "take a look again")
        RIKA("I'll pick out a few", "more and then we can", "head home")
        MC("sure, works for me!")
        EMPTY("(you scour the aisles", "for some more plants.", "after, you make your way", "back to Rika's place)")
        SCENE_END
        BG_STREET
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("alright, let's head back!")
        HANDLE_EMERGENCY
        RIKA("everything good?")
        MC("yup, I'm fine!", "Let's go!")
        RIKA(MCF("so {},"), "how did you end", "up at WidgetCorp?")
        MENU(
            CHOICE("research", [](){
                MC("we'll I tried to", "find a smaller company.")
                MC("I figured I would", "have more responsibility", "but still have", "knowledgable teammates")
                RIKA("ok, that makes sense!")
                //! \rika_maybe got job through networking
                RIKA("I definitely didn't", "think that much when I", "was looking")
                RIKA("I struck up a conversation", "with one of the sales", "members that went to", "the cafe by my place")
                RIKA("and they thought I", "would be pretty good at", "the job, so I checked", "it out")
                //! \rika_maybe has been at WidgetCorp for four years
                RIKA("and four years later,", "here I am!")
            }),
            CHOICE("luck", [](){
                MC("I would say a bit", "of luck")
                MC("I was walking around", "town one afternoon. Well,", "on my way to meet", "a friend.")
                MC("and I was feeling bored", "so I started looking", "around.")
                MC("I happened to walk", "by the office and I", "thought the logo looked", "cool")
                MC("so, yea, I looked", "them up online and saw", "they had a programming", "position open")
                MC("and now I'm here!")
                RIKA("haha, wow, I've", "never heard anything", "quite like that!")
                MC("yea it is a bit...","peculiar... but", "it worked!")
            })
        )
        EMPTY("(you continue down the", "road for a bit)")
        MC("so how far away", "is your place?")
        RIKA("oh it's just up ahead!")
        MC("oh wow, that's not", "far at all!")
        RIKA("yup, here we are!")
        SCENE_END
        BG_RIKAS_GARDEN
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("alright, just put those", "things over in the", "corner.")
        MC("sure. when will you", "end up using them?")
        RIKA("oh probably sometime", "tomorrow! or maybe", "next weekend. I haven't", "decided")
        RIKA("I think some friends", "might have plans tomorrow", "so I'll figure it out", "then!")
        MC("neat! well, I'm", "going to head back", "home!")
        RIKA("thanks again for the", "help! I'll see you", MCF("at work {}!"))
        MC("later Rika!")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief rika is planting her garden
    void rika_weekend_1() {
        RIKA_TEXT("hey I need some help", "outside. want to plant", "a few things in my", "garden?")
        MC("sure, I'm not up to", "anything today")
        RIKA_TEXT("alright, let me", "sent you my address", "again. can you come by", "in an hour?")
        MC("sure, I'll be there", "in an hour!")
        EMPTY("(you save Rika's address", "and head over)")
        SCENE_END
        BG_RIKAS_GARDEN
        FADE_IN
        SHOW_RIKA_NORMAL
        MC("hey Rika!")
        RIKA(MCF("oh hey {}!"), "want to skip the", "warm introduction?", "here's some gloves.")
        MC("haha, wonderful", "what do you want me", "to help with?")
        RIKA("I need a few holes", "over there.", "maybe one a bit to", "the left?")
        MC("around here?")
        RIKA("yea, that should work!", "here's a trowel")
        MC("alright, let's get", "started!")
        for(int i = 0; i < 5; i++) {
            GARDENING_INSTRUCTIONS(FMT_24("dig the hole: UP {}/5", i))
            minigame_bugs::round(bn::keypad::key_type::UP);
            GARDENING_INSTRUCTIONS(FMT_24("dig the hole: DOWN {}/5", i))
            minigame_bugs::round(bn::keypad::key_type::DOWN);
        }
        RIKA("alright, which one do you", "want to plant there?")
        MC("woah woah, this isn't", "my yard! don't you", "already have a plan?")
        RIKA("haha nope! flowers", "will look great anywhere!")
        RIKA("plus it's a little", "reminder!")
        MC("hmm?")
        //! \rika likes presents (and maybe unexpected things)
        RIKA("like a little present!", "something I wasn't", "expecting! I think that", "makes it special")
        MC("ooohh! I see.", "which one should I", "pick?")
        MENU(
            CHOICE("pansies", [](){
                MC("pansies would look", "good here.")
            }),
            CHOICE("marigold", [](){
                MC("are these marigolds?", "I choose these!")
            }),
            CHOICE("peonies", [](){
                MC("I'll do the peonies")
            })
        )
        MC("alright lets plant 'em")
        EMPTY("(you place the bulb in", "the hole)")
        RIKA("alright, now pack", "the dirt around the", "bulb")
        for(int i = 0; i < 4; i++) {
            GARDENING_INSTRUCTIONS("pack the dirt:", FMT_24("LEFT {}/4", i))
            minigame_bugs::round(bn::keypad::key_type::LEFT);
            GARDENING_INSTRUCTIONS("pack the dirt:", FMT_24("RIGHT {}/4", i))
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
        }
        RIKA("nice! I still have a", "few more. want to plant", "those, too?")
        HANDLE_EMERGENCY
        RIKA("everything good?")
        MC("yup, nothing important.", "where was I?")
        MC("oh yea...", "sure, I can plant a", "few more!")
        EMPTY("(you find some more", "space to the side and", "plant two new flowers)")
        MC("*phew*")
        RIKA("nice, I'd say that's", "some good progress for", "today!")
        MC("that was fun, I...", "wouldn't mind working", "some more!")
        RIKA("haha well come back", "next weekend! maybe we", "can put in another row")
        MC("that sounds nice!")
        RIKA("are you thirsty at all?", "Want to head to the", "cafe?")
        MC("yea, let's do that")
        EMPTY("(you tidy up the", "gardening tools and head", "over to the cafe)")
        SCENE_END
        BG_CAFE
        FADE_IN
        SHOW_RIKA_NORMAL
        //! \rika prefers tea to coffee
        RIKA("hmm now what to", "get...")
        RIKA("I know most people", "get coffee but I really", "enjoy the fruit teas")
        RIKA("if you can find a", "place with real fruit", "I promise you won't", "regret it")
        MC("so it is a mix of tea", "and fruit juice?")
        RIKA("yup! the perfect mix", "is a bit difficult to", "get right so I enjoy", "seeing each recipe")
        MC("alright, I'll give it", "a try. Which one", "should I get?")
        MENU(
            CHOICE("peach tea", [](){
                MC("how about the peach", "one? have you had that?")
                RIKA("oh nice! yea peach", "is really good!")
            }),
            CHOICE("passionfruit tea", [](){
                MC("maybe passionfruit?", "is that one good?")
                RIKA("mm yup! passionfruit is", "very good. Maybe a", "bit sweet for me")
            }),
            CHOICE("brown sugar tea", [](){
                MC("oh but the brown sugar", "one looks so good!")
                RIKA("have you been talking", "with Kanade? she would", "something like that")
                MC("haha true, she would", "like something this sweet")
            })
        )
        MC("alright, I'll go with", "that. What are you", "getting?")
        RIKA("this place has a", "pretty good strawberry", "black tea")
        MC("darn that sounds good!")
        EMPTY("(you order your drinks", "and sit by the window)")
        MENU(
            CHOICE("ask about hobbies", [](){
                MC("so do you have", "hobies other than gardening?")
                RIKA("well I do enjoy", "watching movies every so", "often")
                //! \rika_maybe likes comedy movies
                RIKA("these days, I mostly", "watch comedy. Though I'll", "enjoy pretty much", "anything")
                MC("anything else besides", "movies?")
                RIKA("well I do have a", "few groups of friends")
                RIKA("some like to sing,", "others like to play", "sports")
                RIKA("it's easy to stay", "busy with so many people", "around")
            }),
            CHOICE("ask about family", [](){
                MC("so do you have", "any family?", "like brothers or", "sisters?")
                //! \rika_maybe has an older borhter (several years)
                RIKA("yup, I do have", "a brother but he's", "several years older.")
                RIKA("we didn't really", "share any interests", "so we kinda grew", "in our own way")
                MC("what does he do", "now?")
                //! \rika_maybe s brother also works in software
                RIKA("oh he also works", "in software but he's", "on the programming side", "of things")
                MC("oh interesting", "do you see him often?")
                RIKA("ehh mostly for", "family events. He's", "already married", "so he's always busy")
                RIKA("but I drop by", "every month or so", "to see if he has", "any cool stories")
            })
        )
        MC("ahh, neat!")
        EMPTY("(you and Rika enjoy", "the rest of your", "drinks until it is", "time to leave)")
        RIKA("alright, shall we", "head out?")
        MC("sure, I had a great", "time! I never knew", "gardening could", "be so fun")
        MC("weird how work isn't", "always a pain in the", "butt")
        RIKA("haha I agree. I'll", "let you know if", "I ever plan to add", "some more plants")
        MC("sounds good. I'll", "see you later, Rika!")
        RIKA(MCF("take care, {}!"))
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief rika is heading to a street festival (learn about sister)
    void rika_weekend_2() {
        // street festival
        RIKA_TEXT(MCF("yo {}!"), "if you aren't", "busy today, lets go", "to the street festival")
        MC("sure, I don't have", "anything planned. what", "time do you want to", "meet at?")
        RIKA_TEXT("meet me at 3pm on", "pearl street. It is", "just around the corner", "from the flower shop!")
        MC("ok, I'll see you then!")
        EMPTY("(you wait until 2:45 and", "then head over)")
        SCENE_END
        BG_STREET
        FADE_IN
        MC("oh wow, there are a", "lot of people here!", "let me call Rika...")
        CELL_PHONE_BUZZ
        RIKA_TEXT("wow this is busy, huh!", "meet by the flower store", "and we can walk from", "there")
        MC("alright, that sounds", "much better")
        SHOW_RIKA_NORMAL
        RIKA(MCF("yo, {}!"), "you made it!")
        MC("look how many people", "there are! I never knew", "such a thing was going", "on this weekend")
        RIKA("yea they have a", "bunch of events planned.")
        RIKA("there are some street", "vendors and a few", "music acts!")
        MC("oh neat.", "do you know which", "genres?")
        RIKA("I am not sure, but", "last year there were", "a few rock bands")
        RIKA("there might be a few", "jazz bands mixed-in", "though those were earlier", "in the day")
        MC("hmmm interesting")
        RIKA("which area should we", "check out first?")
        MENU(
            CHOICE("arts vendor", [](){
                MC("let's head to the arts", "section. Maybe they", "have some cool keychains", "or pins")
                EMPTY("(you make your way", "the the art tents)")
                RIKA("is there anything", "you usually look for?")
                MENU(
                    CHOICE("keychain", [](){
                        MC("mostly keychains.")
                        RIKA("any particular reason?")
                        MC("well they seem so", "useful. but I have so", "many that they've", "lost some meaning")
                        RIKA("how many is that?")
                        MC("oh.. uhm...", "maybe fourty or fifty")
                        RIKA("FOURTY!", "gosh you must really", "like them")
                        RIKA("let's take a look", "around!")
                    }),
                    CHOICE("pins", [](){
                        MC("I try to find the", "smallest items, usually", "pins or things of that", "size")
                        RIKA("any reason for the", "size thing?")
                        MC("I think it is an", "interesting constraint", "plus its usually", "cheaper")
                        MC("and I can't get more", "variety")
                        RIKA("I see. that's cool!")
                    }),
                    CHOICE("pottery", [](){
                        MC("I like finding new", "pottery. like mugs or bowls.")
                        MC("some artists really", "put in extra effort", "and can make some", "pretty unique things")
                        RIKA("cool, not sure I've", "ever taken a closer look")
                    })
                )
                EMPTY("(you can Rika peruse", "the various art vendors)")
            }),
            CHOICE("concert", [](){
                MC("let's listen to some", "music for a bit")
                RIKA("alright, let's head", "closer to the stage")
                EMPTY("(you make your way to", "one end of the festival)")
                RIKA("hey this band is", "pretty good!")
                MC("is this the sort-of", "music you usually listen", "to?")
                //! \rika_maybe listens to electronic music
                RIKA("not particularly", "I mostly listen to", "electronic music")
                RIKA("I think that's what", "makese this better!", "It's like a small", "treat!")
                MC("oh I see!", "Yea it's nice, kinda", "jazz-y but still upbeat")
                RIKA("yea! I love when", "the music gives you life")
                EMPTY("(you and Rika listen", "to the music for", "several songs)")
            }),
            CHOICE("food tent", [](){
                MC("what about the food tent?", "I didn't have anything", "for lunch")
                RIKA("sure, let's do it")
                EMPTY("(you make your way to", "the tent)")
                MC("hmm, so many options...", "what should I get?")
                MENU(
                    CHOICE("burger", [](){
                        MC("oo! a burger sounds", "fantastic! Rika", "do you want one, too?")
                        RIKA("oh nice! Sure, I'll", "take one")
                        MC("alright, two burgers please!")
                    }),
                    CHOICE("baked potato", [](){
                        MC("Maybe a baked potato?")
                        RIKA("oh that is an interesting", "options. I don't think", "I've had one of those", "in forever!")
                        MC("oh do you want one", "too?")
                        RIKA("sure, I'll take one")
                        MC("alright, two baked potatoes", "please!")
                    }),
                    CHOICE("ice cream", [](){
                        MC("I think I'll get", "some ice cream. It's", "pretty hot out, anyway")
                        RIKA("oh nice, could you", "get an extra scoop?")
                        MC("oh do you want", "some too?", "sure, I can do that.")
                        RIKA("yes please!")
                        MC("two scoops of ice cream", "please!")
                    })
                )
                MC("let's sit over there", "by the curb")
                RIKA(MCF("nice pick {}!"), "this is tasty!")
            })
        )
        RIKA("alright, I'd say we're", "off to a good start!")
        MC("yea I'm having fun!")
        HANDLE_EMERGENCY
        RIKA("everything good?")
        MC("yup, nothing important!")
        RIKA("what should we", "do next?")
        MENU(
            CHOICE("ice cream", [](){
                MC("maybe grab some", "ice cream?")
                RIKA("hey that sounds", "pretty cool!", "hehe")
                EMPTY("(you walk to the ice", "cream tent)")
                RIKA("hey look at that!", "They have waffle sundaes!")
                MC("Is that different from", "a normal cone?")
                RIKA("yea its like a big", "ice cream boat!")
                RIKA("usually they'll add", "a bunch of toppings", "too")
                //! \rika_maybe loves crunchy foods
                RIKA("maybe I can ask them", "for more waffle parts.", "I love the crunchy", "bits")
                MC("what flavor ice cream", "do you get?")
                //! \rika_maybe likes vanilla ice cream with extra toppings
                RIKA("I usually get vanilla", "BUT I always get", "some extra toppings!")
                RIKA("usually fruit but", "I love it all!")
                MENU(
                    CHOICE("I like chocolate", [](){
                        MC("I love getting chocolate", "ice cream.")
                        RIKA("ooh maybe we can share?", "I think they're better", "together but I wouldn't", "want 100% chocolate")
                        MC("oh share a bit? sure!")
                    }),
                    CHOICE("I like vanilla", [](){
                        MC("I also like vanilla", "but I usually just", "get a cone instead", "of a sundae")
                        RIKA("that's fair, those'll", "always be available and", "never go out of style")
                    }),
                    CHOICE("I like weird flavors", [](){
                        MC("I usually pick out", "the weirdest flavor", "possible!")
                        RIKA("HAHA would you", "pick out a dirt flavor", "if they had it?")
                        MC("uhhhm....", "well maybe not that", "weird...")
                        MC("like pistachio or", "date flavored ones. but", "sometimes maple syrup", "or other ones")
                        RIKA("OH I understand now!", "that is pretty neat. I'd", "love to try something new")
                    })
                )
                EMPTY("(you head to the counter", "to grab the ice cream)")
                RIKA("let's sit over by", "that tent. looks like", "there is an open bench")
            }),
            CHOICE("carnival games", [](){
                MC("maybe we can play", "some carnival games?")
                RIKA("haha you like those?", "I thought they never", "allow you to win?")
                MC("yea we can ride some", "of the spinning ones")
                MC("and the only carnival game", "worth playing are the", "strength ones")
                MC("even if you don't win", "it's still fun to swing", "a mallet or punch a bag")
                RIKA("alright! count me in!")
                EMPTY("(you head to the", "spinning cup)")
                MC("ready? its starting", "soon!")
                RIKA("  WHOO")
                RIKA("", "     WHOO")
                RIKA("", "", "  WHOO")
                RIKA("", "WHOO")
                MC("  WHEE")
                MC("", "     WHEE")
                MC("", "", "  WHEE")
                MC("", "WHEE")
                EMPTY("(the ride comes to", "a stop)")
                RIKA("aww that was it?", "I was having fun...")
                MC("that's good! we", "can come back after.", "let's check out the", "strength games")
                EMPTY("(you walk with Rika", "to the mallet game)")
                RIKA("hmm so what do we", "do here?")
                MC("take the mallet and", "slam this area down here")
                RIKA("hmm... I've never", "done this, please", "don't laugh if it", "doesn't move")
                MC("don't worry, I have a", "feeling you'll do well")
                EMPTY("(Rika smashes the", "carnival machine)")
                RIKA("hey that went pretty", "hight! let me try", "this again")
                MC("go ahead! lets see", "that muscle, Rika!!")
                EMPTY("(Rika smashes the", "carnival machine, this time", "with intense power)")
                RIKA("look at that! so close", "to the bell! I'll try", "it again")
                MC("ok Rika, but maybe", "only one or two more times")
                EMPTY("(Rika insists she", "can hit the bell so you", "try 12 more times)")
                RIKA(MCF("{} maybe"), "you can grab some water", "we might be here a bit")
                MC("RIKA... uhm...", "weren't you the one", "who said they rig", "these?")
                //! \rika_maybe is definitely the type to gamble and think she will win
                RIKA("yea...", "but...", "I feel so close!!")
                EMPTY("(you take the mallet", "from Rika's hand)")
                MC("I'm sorry it has", "to be this way. but I", "absolutely must", "intervene")
                RIKA("*sigh*", "alright, let's find", "a place to site down", "I need to rest")
                MC("sure, there is a bench", "over there.")
                EMPTY("(you head to the", "bench)")
            }),
            CHOICE("alcohol", [](){
                MC("well it's getting a", "bit late. maybe we", "grab some alcohol", "and listen to the music")
                RIKA("ok, let's do that")
                EMPTY("(you head to the", "beer tent)")
                MC("hmm what do you", "normally get?")
                RIKA("oh I'm not too picky", "when it comes to alcohol")
                //! \rika_maybe is not picky with alcohol
                RIKA("these places can", "get expensive, too", "probably just something", "cheap for me")
                MC("alright, two of their", "cheapest beers, I guess!")
                EMPTY("(you grab your beer", "and head to a table)")
            })
        )
        RIKA("well, what a day!", "what do you think,", MCF("{}?"))
        MC("yea I'm having a", "great time. This was", "a great idea")
        MC("thanks for the invite!")
        RIKA("sure! Usuaully I", "try and invite a few", "more people but no one", "was around today")
        MC("aww... well I had a", "great time regardless")
        RIKA(MCF("so {}"), "do you have any", "family members?")
        MENU(
            CHOICE("a few", [](){
                MC("yea I have a few", "siblings")
                RIKA("oh nice!")
            }),
            CHOICE("none", [](){
                MC("I don't have any.", "why, what's up?")
                RIKA("oh ok...")
            })
        )
        RIKA("well, I have a bit", "of a... hmm", "problem?")
        //! \rika lives with her sister. her sister does not work a job.
        RIKA("so I let my younger", "sister live with me")
        RIKA("but she doesn't work", "at the moment")
        RIKA("She has tried", "a few jobs but nothing", "really works outs")
        RIKA("I haven't really", "figured out why", "that's the case but...", "yea...")
        RIKA("I wish I could find", "a way to fix her", "situation")
        RIKA("like, what if I", "get sick and can't", "help her anymore?")
        MENU(
            CHOICE("does she have hobbies?", [](){
                RIKA_SISTER_QUESTION = main_character_state::learned_sister_hobbies;
                MC("does she have any", "hobbies? maybe that's a", "good place to start")
                RIKA("well she spend most", "of her time on the", "computer")
                RIKA("I don't really know", "what she does all day")
                RIKA("I think she might play", "games but I don't really", "know much about them")
                RIKA("she doesn't really leave", "her room very often")
                MC("hmm that's tough...")
                if(state::st.wke_state.story_progress[character::RIN] >= 1) {
                    MC("you know...", "I wonder if Rin has", "any thoughts on this...")
                    RIKA("Rin? the person", "on the security team?")
                    MC("yea, I think", "she might have some", "input")
                    MC("she spends most of", "her time indoors", "and at the computer")
                    MC("who knows, maybe she", "would know a way", "to help")
                    MC("or at least a way", "to communicate in", "a way your sister", "can understand")
                    RIKA("hmm, I suppose you", "have a point...")
                    RIKA("sure, I'll try and", "talk to Rin and see", "what her ideas are")
                } else {
                    MC("can't say I know", "how to help here...")
                    MC("well, I'll think about", "it some more")
                    MC("I'm wonder if there", "is someone at the office", "that has some good ideas")
                    RIKA("oh true, I could", "ask around there.")
                    RIKA("some people usually have", "interesting ways of", "ending up at WidgetCorp")
                    RIKA("maybe they've also", "worked odd jobs before", "joining...")
                }
            }),
            CHOICE("previous jobs?", [](){
                RIKA_SISTER_QUESTION = main_character_state::learned_sister_jobs;
                if(state::st.wke_state.story_progress[character::KANADE] >= 2) {
                    RIKA("well, she worked a", "few low-skill jobs", "like convenience stores", "and park concessions")
                    RIKA("but I think she didn't", "really have a good team", "and was really bored")
                    RIKA("it can be tough when", "no one acknowledges your", "work, you know?")
                    MC("hmm true", "you know...")
                    MC("maybe she should talk", "to Kanade!", "She does some volunteering", "at this food bank")
                    MC("they have a really great", "bunch of staff and there", "maybe that sort of", "environment would help")
                    MC("and maybe they have", "the ability to hire", "her!")
                } else if (state::st.wke_state.story_progress[character::INO] >= 3) {
                    RIKA("well, she worked at", "a bartender at a music", "venue for a bit")
                    RIKA("but I think she got", "tired of the customers or", "the weird hours that", "were required")
                    MC("you know...", "there is a smaller bar", "that Ino goes to", "for open mic nights")
                    MC("that place is usually", "not very busy. I mean", "it still has people", "keeping it alive")
                    MC("but not as bustling as", "a concert venue")
                    MC("maybe they're looking", "for people?", "If she has already", "worked as a bartender")
                    MC("then it'll probably be", "pretty easy to work there")
                    RIKA("oh interesting!", "sure, I'll talk to", "Ino and see if she", "has more details")
                } else {
                    RIKA("she used to work at", "a bookstore and a few", "other small shops")
                    RIKA("I think she was a", "bit rude to the customers", "so that never really", "worked out")
                    MC("darn, that's tough.", "dealing with customers", "can be pretty frustrating")
                    MC("yea I'm not sure", "how to help...")
                    MC("I'm sure there is", "someone at the office", "that has some good ideas")
                    RIKA("that's alright, even", "just talking about it", "helps out")
                }
            })
        )
        RIKA(MCF("thanks {}"), "I'll see what I can", "do and go from there")
        MC("keep me posted!")
        EMPTY("(Rika and you enjoy", "the remaining part of", "the street festival)")
        SCENE_END
        MC("(that went well!)")
    }
    //! \brief shared conversation when mc doesn't talk to others before rika_weekend_3
    void rika_weekend_3_no_high_relation_conv() {
        MC("yea, but only for a", "brief moment")
        MC("unforutnately, I don't", "really have anything to", "help you out")
        RIKAS_SISTER("oh... ha...", "that's alright")
        RIKAS_SISTER("even just having someone", "else around...")
        RIKAS_SISTER("well...", "it really helps!")
        RIKAS_SISTER("I feel bad for Rika.", "I don't know... maybe that", "seems a bit selfish")
        MC("I don't think it's selfish", "I think you both understand", "each other well")
        RIKAS_SISTER("I really dont' want", "to be useless!")
        RIKAS_SISTER("it's just...", "nothing seems to work", "out")
        RIKAS_SISTER("it doesn't even feel", "real. like some big", "joke that...", "that...")
        MC("Selene, it's ok", "I think we've all been", "there")
        MC("I'm not saying I", "understand you or your", "situtation completely...")
        MC("just that...", "well, it's normal to", "need help from people")
        MC("so I think when", "you've received help", "when you really need", "it")
        MC("you learn to look out", "for it; for people that", "really need help")
        MC("so if you need anything", "ANYTHING at all", "just know that we", "are here for you")
        MC("even if it's as simple", "as a converstaion in", "the hallway of a", "karaoke parlor!")
        RIKAS_SISTER("haha *sniff*")
        RIKAS_SISTER(MCF("thank you, {}"))
    }
    //! \brief internal
    bool rika_weekend_3_deny_sister;
    //! \brief internal
    bool rika_weekend_3_perfect;
    //! \brief rika is going to karaoke with friends
    void rika_weekend_3() {
        RIKA_TEXT(MCF("hey, {}"), "are you free today?", "want to go to", "a karaoke place?")
        MC("uhm, sure, I can", "do that!")
        RIKA_TEXT("cool! There will", "be a few other friends", "there. I hope that", "is ok")
        MC("yea that's fine", "where should we meet?")
        RIKA_TEXT("meet us at", "888 main street", "in an hour or so")
        MC("ok, sounds good", "see you there!")
        EMPTY("(you wait a bit and", "head over)")
        SCENE_END
        BG_KARAOKE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA(MCF("hey {}"), "welcome!")
        MC("hey Rika!")
        RIKAS_FRIEND_1(MCF("hello {}"), "nice to meet you!")
        RIKAS_FRIEND_2(MCF("yo, {}"), "glad you could", "join us!")
        MC("hello hello!", "seems like you've", "already started singing")
        RIKA("oh yea, don't give the", "mic to those two", "they won't let go", "once they start")
        RIKAS_FRIEND_1("hey now!", "we gave you a few", "songs before this one")
        RIKAS_FRIEND_2("you're one to talk", "Rika! we needed to rip", "it from your hands", "to get our turn too")
        MC("haha sounds like you", "all love singing!")
        RIKA("we may not be the", "best, but we've got the", "spirit!")
        RIKAS_FRIEND_2(MCF("alright {}"), "let's see what you've", "got!")
        MENU(
            CHOICE("politely accept", [](){
                MC("heck yea, give", "me that!")
                RIKAS_FRIEND_1("whoo!", "what song do you want?")
                MENU(
                    CHOICE("happy song", [](){
                        MC("maybe a happy one?")
                        RIKAS_FRIEND_2("oh, maybe something", "from the radio?")
                        RIKA("yea! something love-y", "dove-y!")
                        RIKAS_FRIEND_2("how about this one?")
                        MC("sure, let's do that one!")
                        EMPTY("(you start the next", "song)")
                    }),
                    CHOICE("sad song", [](){
                        MC("I usually start the", "session with a sad one")
                        MC("this gets the negative", "energies out and gives", "birth to the positive", "ones")
                        RIKAS_FRIEND_1("woah...")
                        RIKAS_FRIEND_2("that's deep...")
                        RIKA("alright, then...")
                        EMPTY("(you find a sad song", "and sing it perfectly,", "moving your audience", "to tears!)")
                        //! \rika_maybe does not know Italian
                        RIKA("BONJOUR!")
                        RIKAS_FRIEND_1("I think you mean", "'bravo'?")
                        RIKA("oh...", "oops")
                        EMPTY("(the room bursts out", "in laughter)")
                        RIKA("oh man...", "alright...")
                        RIKAS_FRIEND_2("who wants to go", "next?")
                        RIKA("me! me! I want", "the encore")
                        RIKAS_FRIEND_1("alright, you're up!")
                        EMPTY("(Rika starts the next", "song)")
                    })
                )
            }),
            CHOICE("politely decline", [](){
                MENU(
                    CHOICE("succumb to peer pressure", [](){
                        MC("alright, alright", "if yelling is allowed,", "then I'll give it", "a try")
                        RIKA("HAHA don't worry, do", "your thing. All that", "matters is that", "you try it once")
                        RIKAS_FRIEND_1("you go this,", MCF("{}!"))
                        RIKAS_FRIEND_2("go for it!", MCF("{}!"))
                        MC("alright, here goes", "nothing...")
                        EMPTY("(you start the song)")
                    }),
                    CHOICE("politely insist", [](){
                        MC("uhm...", "I'm not feeling so", "comfortable...")
                        RIKA("aww... that's", MCF("alright {}"), "maybe another weekend")
                        RIKA("just enjoy yourself", "this time around")
                        RIKA("honestly it can be", "a lot of fun just", "listening to these two")
                        RIKA("alright, which one", "of you two wants it?")
                        RIKAS_FRIEND_1("me!")
                        RIKAS_FRIEND_2("aww, I'll go after", "then...")
                        EMPTY("(the next song starts)")
                    })
                )
            })
        )
        EMPTY("(the group continues", "alternating singers for", "the next thirty minutes)")
        RIKA("phew! that was awesome!", MCF("{}, how"), "are you liking it?")
        MC("I'm having a blast!")
        RIKA("oh... looks like", "I got a text from my", "sister...")
        MC("what's up?", "need help with something?")
        RIKA("oh she's just wondering", "if she can join us.", "any objections?")
        RIKAS_FRIEND_1("none here")
        RIKAS_FRIEND_2("nope!")
        RIKA(MCF("{}?"), "is it ok if she", "joins us?")
        MENU(
            CHOICE("ehh", [](){
                MC("I don't really know...", "I'm having a good time", "with just us...")
                RIKA("alright, that's fine", "with me. I'll tell", "her we've filled the", "room")
                rika_weekend_3_deny_sister = true;
            }),
            CHOICE("sure!", [](){
                MC("yea, that works for me!")
                RIKA("alright, I'll let her", "know... probably will", "take her ten to", "fifteen minutes")
                rika_weekend_3_deny_sister = false;
            })
        )
        if(rika_weekend_3_deny_sister) {
            RIKA("let's continue?")
            RIKAS_FRIEND_1("YEA!")
            EMPTY("(you finish the rest", "of the day in peace,", "but what about Rika's", "sister...)")
            vnlib::end(vnlib::BAD_END);
            return;
        }
        RIKA("which one of you", "wants to go next?")
        RIKAS_FRIEND_2("ME ME ME!")
        EMPTY("(you sing for a", "few more songs until", "Rika's sister arrives)")
        RIKA("oh looks like she", "is outside")
        EMPTY("(Rika brings her sister", "in from outside)")
        RIKA("This is my sister,", "Selene")
        RIKAS_FRIEND_1("hello there!")
        RIKAS_FRIEND_2("nice to meet you!")
        MC("hello Selene!")
        RIKAS_SISTER("he- hello")
        RIKAS_FRIEND_1("Do you want the", "next one, Selene?")
        RIKAS_SISTER("no, I'm-", "fine")
        RIKAS_FRIEND_1("oookay then", "Rika do you want to", "go next?")
        RIKA("sure! let's rock")
        EMPTY("(Rika begins the next", "song, rocking out)")
        EMPTY("(Rika's sister inches", "closer to you, though", "she's clearly pretty", "shy about it)")
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("hey, you're Rika's", "work friend, right?")
        MC("me? yea, I think so.", "Rika has a lot of", "friends so she probably", "has a few work ones")
        RIKAS_SISTER("did you talk to", "her recently about...", "me?")
        MC("oh uhm...", "yea we did talk", "about you")
        RIKAS_SISTER("oh, would we be", "able to talk in private", "for a bit?")
        MC("oh, sure")
        EMPTY("(you head to the hallway)")
        SCENE_END
        BG_KARAOKE_HALLWAY
        FADE_IN
        SHOW_RIKAS_SISTER
        RIKAS_SISTER("so I... wanted", "to thank y-")
        if(handle_emergency([](){
            MC("oops looks like something", "else has come up")
            MC("I'd love to stay", "and continue but", "another obligation requires", "my attention")
            EMPTY("(Rika's sister bursts", "out in tears)")
            SHOW_RIKA_NORMAL
            RIKA("WHA- what's", "going on out here!?")
            MC("I... uhm...", "I need to leave.", "something has come up!")
            RIKA("normally, I'm pretty", "relaxed with this sort", "of thing...")
            RIKA("but... really?", "you couldn't stay five", "more minutes and hear", "Selene out?")
            MC("I-")
            SHOW_RIKAS_SISTER
            RIKAS_SISTER("FINE... just leave...", "no one cares, anyway...")
            HIDE
            EMPTY("(Selene runs out of", "the karaoke parlor)")
            SHOW_RIKA_NORMAL
            RIKA("I really thought she", "would have fun today")
            RIKA("why don't you buzz", "off and have fun doing", "whatever else is more", "important")
            EMPTY("(Rika scoffs and goes", "back inside)")
            MC("...")
            state::st.rel_state.reset(character::RIKA);
        })) {
            return;
        }
        RIKAS_SISTER("oh sorry did", "something come up?")
        MC("oh no, nothing at", "all")
        if(RIKA_SISTER_QUESTION == main_character_state::learned_sister_hobbies) {
            RIKAS_SISTER("so Rika said you", "talked about some of", "my hobbies...")
            if(state::st.wke_state.story_progress[character::RIN] >= 1) {
                MC("yea I might have a", "lead for you!")
                RIKAS_SISTER("wait... really?", "you mean it?")
                MC("well, if you'll hear", "me out...")
                MC("I don't really know much", "about you so I apologise", "in advance if I")
                RIKAS_SISTER("oh... that's alright")
                MC("so I was talking with", "one of our coworkers, Rin", "the other week")
                EMPTY("(the flashback begins...)")
                SCENE_END
                BG_OFFICE_DESK
                FADE_IN
                SHOW_RIN_NORMAL
                MC("hey Rin, do you a few", "minutes?")
                RIN("yea but make it quick")
                MC("so Rika has a sister", "who needs some help")
                MC("she has tried a few", "jobs over the years", "but nothing seems to", "stick")
                MC("she... spends most of", "her time online...")
                MC("so I was wondering", "if you had some suggestions", "on what she should do", "next?")
                RIN("so you thought I", "would know how to fix", "someones's life...")
                RIN("...because I play", "video games?")
                MC("well... I mean your", "life is going pretty well,", "right?")
                RIN("hmm... I see where", "you're coming from...")
                RIN("listen, all I know", "is that it is really", "hard to stop playing", "games")
                RIN("they're built to be", "fun and they do a darn", "good job at it")
                RIN("maybe she should try", "to build a game of her", "own. even something", "small")
                MC("have you done that", "before?")
                RIN("yea, much earlier on", "in my careers. It didn't", "really amount to much")
                RIN("but I did find out", "which parts of the process", "I liked the most")
                RIN("who knows, maybe she", "is really good at telling", "stories")
                RIN("I'm sure there are people", "that could use help with", "that...")
                MC("hmm I see... alrigth", "I'll keep that in mind", "Thanks!")
                RIN("yea... no problem", "I guess")
                SCENE_END
                BG_KARAOKE_HALLWAY
                SHOW_RIKAS_SISTER
                RIKAS_SISTER(MCF("{}?"), "are you alright?")
                MC("oh sorry just remembering", "some things. I think I", "spaced out a bit")
                RIKAS_SISTER("oh, I hope you're ok!")
                MC("haha yea I'm fine.")
                MC("so Rika said you", "enjoy playing games.", "is that right?")
                RIKAS_SISTER("oh uh... yes", "I do play them often")
                MC("Rin suggested that maybe", "you could try building your", "own")
                RIKAS_SISTER("oh hmm... but I don't", "really know anything about", "coding...")
                MC("what about a different part", "of the game process?", "like maybe just the story?")
                RIKAS_SISTER("oh just the story...", "hmm well maybe I could", "try something like that")
                RIKAS_SISTER("I've never really written", "anything before. I can't", "imagine that I'll be", "any good at it...")
                MC("well... maybe try it once", "right? I mean I haven't", "created one before either")
                RIKAS_SISTER("would you want to", "write a story with me?")
                MENU(
                    CHOICE("sure!", [](){
                        MC("you know, I'd love to", "help out!")
                        RIKAS_SISTER("wait...", "reeeally?")
                        MC("sure, why not!?", "It it can help you,", "it can help me")
                        MC("though, I don't really", "know how to start", "something like this")
                        MC("are you still", "interested in trying", "it out?")
                    }),
                    CHOICE("uhm...", [](){
                        MC("well if want me to hold", "you accountable, I can", "at least do that")
                        MC("but I don't think I", "can work on a serious", "portion of it at all")
                        RIKAS_SISTER("oh...")
                        MC("have you seen how busy", "Rika is?")
                        RIKAS_SISTER("I suppose you're right")
                    })
                )
                RIKAS_SISTER("if you insist, I'll at", "least give it a try")
                MC("maybe you can talk to", "Rin, too. I'm sure", "she knows more about", "these thing than I do")
                RIKAS_SISTER("sure!")
                RIKAS_SISTER(MCF("thank, {}"), "this really helps!")
                MC("I'm eager to see", "how it turns out!")
                RIKAS_SISTER("Should we head back", "inside?")
                rika_weekend_3_perfect = true;
            } else {
                rika_weekend_3_no_high_relation_conv();
                rika_weekend_3_perfect = false;
            }
        } else {
            RIKAS_SISTER("so Rika said you", "talked about some of", "my previous jobs")
            if(state::st.wke_state.story_progress[character::INO] >= 3) {
                MC("yea I might have a", "lead for you!")
                RIKAS_SISTER("really?", "you mean it?")
                MC("yea I was talking with", "a coworker about it, too")
                EMPTY("(the flashback starts...)")
                SCENE_END
                BG_OFFICE_DESK
                FADE_IN
                SHOW_INO_NORMAL
                MC("Hey Ino, I have a", "bit of a weird", "question")
                INO(MCF("sure, {}"), "what's up?")
                MC("well, have you talked", "to Rika recently?")
                INO("Rika... from sales?", "no, I haven't")
                MC("so Rika has a sister", "who... needs some help")
                INO("how so?")
                MC("well, she is having", "some trouble finding", "a job")
                MC("she has tried working", "at a few places but", "nothing has really", "stuck")
                MC("anyway, one of the", "places she worked at", "was a music venue bar")
                MC("so I was thinking...")
                MC("maybe you knew if the", "small bar by work", "would have something", "available?")
                INO("ahh I see. like if", "her previous place was", "too busy or hectic...")
                INO("then something much", "smaller or home-y might", "work out?")
                MC("yea! I was thinking", "how well your open mic", "went and...")
                MC("it was the first place", "that came to mind!")
                INO("huh...", "well, I can't say", "I know if they're", "hiring...")
                INO("but I have met the", "owner a few times!")
                INO("I think they would", "be open to the idea", "of someone new")
                INO("so maybe she could", "stop by one of the", "open mic nights!")
                MC("sure, I'll pass along", "the information!")
                INO("any time! I hope", "she can make something", "of it")
                INO("and if she needs someone", "else to talk to, I'm", "usually at the open", "mics anyway")
                MC("awesome!", "I'll let her know!")
                SCENE_END
                BG_KARAOKE_HALLWAY
                FADE_IN
                SHOW_RIKAS_SISTER
                RIKAS_SISTER(MCF("{}, hello?"), "are you ok?")
                MC("oh yea, sorry", "was spacing out a bit")
                RIKAS_SISTER("oh... ok...")
                MC("I was just thinking", "about what Ino said...")
                MC("oh... right...", "Ino is my manager", "at WidgetCorp")
                MC("anyways, Rika mentioned", "that your worked at", "a bar before")
                MC("and Ino and I went", "to a cute bar a", "few weeks ago for", "an open mic night")
                MC("it was a really great", "time! partially because", "it was so small")
                MC("like everyone knew each", "other and they were", "all very supportive...")
                MC("maybe it's a stretch", "but if there was any", "place to work, maybe", "that would work...")
                RIKAS_SISTER("oh...", "I don't know...")
                MC("would you consider", "showing up to one", "of the open mic nights?")
                MC("Ino usually performs", "at those so maybe", "that would be a good", "way to see the place")
                RIKAS_SISTER("would you...", "want to come with?")
                MC("sure, I can introduce you", "to some of the people", "there, too")
                MC("even Rika could come", "along! well...", "if you're ok with that")
                RIKAS_SISTER("haha yea...", "that'd be fine")
                MC("ok neat, I'll let", "Rika know!")
                RIKAS_SISTER("should we head back", "inside?")
                rika_weekend_3_perfect = true;
            } else if (state::st.wke_state.story_progress[character::KANADE] >= 2) {
                MC("yea I might have a", "lead for you!")
                RIKAS_SISTER("oh... really?")
                MC("yea! I had a conversation", "with a coworker the other", "week")
                SCENE_END
                BG_OFFICE_DESK
                FADE_IN
                SHOW_KANADE_NORMAL
                MC("hey Kanade, I have a", "situation I need", "some help with")
                KANADE(MCF("sure, {}"), "what's up?")
                MC("have you...", "talked to Rika recently?")
                KANADE("Rika... from sales?", "hmm... no not recently")
                MC("ok... well, she has a", "sister who...", "needs some help finding", "a job")
                MC("her sister has had", "all sorts of side", "jobs. but...")
                MC("nothing seems to", "work out.")
                MC("and ever since we", "went to volunteer,", "I coulnd't help but", "think that it would")
                MC("be a good place for", "her to try and build", "up some work history")
                MC("plus, who knows, maybe", "that organization needs", "people to work with", "them full time")
                KANADE("ahh I see...")
                KANADE("it would be nice to", "meet her sister...", "*sigh*")
                KANADE("ahh right! work!", "hmm...")
                KANADE("the volunteer place...", "true, I think that would", "be a good place to", "start")
                KANADE("I've met all sorts of", "people when I show up.")
                KANADE("who knows, maybe one them", "would have something, too!")
                MC("oh true... I never", "thought of that")
                KANADE("all it takes a conversation!", "hopefully, she is good", "at having those")
                MC("hmm... I don't know exactly.", "she is at home often", "so...")
                KANADE("ahh I see...", "well if she ever wants", "to go to volunteer,", "I'll go with her!")
                MC("oh nice!", "I can pass that along")
                KANADE("ok, let me know if", "she decides to attend!")
                MC("will do!", "Thanks Kanade!")
                SCENE_END
                BG_KARAOKE_HALLWAY
                FADE_IN
                SHOW_RIKAS_SISTER
                RIKAS_SISTER(MCF("{}?"), MCF("{}!"), "are you ok!?")
                RIKAS_SISTER("you seem out of it")
                MC("oh sorry, was just", "thinking about the", "conversation...")
                MC("so Kanade said that", "she could help out!")
                RIKAS_SISTER("Kanade?")
                MC("ahh sorry!", "she is a coworker at", "WidgetCorp")
                MC("she works on the Marketing", "team. We went to", "volunteer one weekend a", "while back")
                MC("anyway, it got me thinking", "that maybe you could", "go there with us", "one time")
                MC("even if you don't", "enjoy the work... I mean", "it is REAL work...")
                MC("well, maybe you'll meet", "someone there! there", "are all sorts of people", "who show up")
                RIKAS_SISTER("so you'll...", "go there with me?")
                MC("sure! Kanade can come", "with. so you won't have", "to worry about going", "alone")
                MC("heck, I'm sure Rika", "would love to come, too!", "There are tons of people", "to talk to there")
                MC("oh... I mean, if you're", "ok with it...")
                RIKAS_SISTER("yea... that's ok")
                MC("neat, I'll let Rika", "know and we can find", "a time that works")
                RIKAS_SISTER("shall we...", "head back inside?")
                rika_weekend_3_perfect = true;
            } else {
                rika_weekend_3_no_high_relation_conv();
                rika_weekend_3_perfect = false;
            }
        }
        MC("sure, let's head back")
        SCENE_END
        BG_KARAOKE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("hey, everything good?")
        MC("yup!")
        RIKAS_SISTER("...yea!")
        SHOW_RIKA_HAPPY
        RIKA("wonderful!")
        if(rika_weekend_3_perfect) {
            vnlib::end(vnlib::PERFECT_END);
        } else {
            vnlib::end(vnlib::GOOD_END);
        }
    }

    //! \brief internal
    bool rin_weekend_0_accepted;
    //! \brief rin is shopping for some games
    void rin_weekend_0() {
        RIN_TEXT("hey loser! I know", "you aren't doing anything", "so come help me", "shop for some games")
        MC("huh? why do you need", "me for that?")
        RIN_TEXT("either you're in", "or you're out, pal")
        MENU(
            CHOICE("Im in", [](){
                MC("I'm in. where should", "I meet you?")
                RIN_TEXT("figure it out!")
                rin_weekend_0_accepted = true;
            }),
            CHOICE("I'm out", [](){
                MC("yea, I'm out")
                RIN_TEXT("fine")
                rin_weekend_0_accepted = false;
            })
        )
        if(!rin_weekend_0_accepted) {
            MC("guess I'll just do", "something more interesting")
            state::st.rel_state.reset(character::RIN);
            return;
        }
        MC("great, so now I have", "to find out where", "she could be...")
        MC("what a weird person...")
        MC("well, where should", "I start?")
        MENU(
            CHOICE("search online", [](){
                MC("hmm...", "looks like a few", "possible places...")
                MC("well, this one is", "downtown, I'll go check", "it out")
                MC("hmm 'Galapagos Games'", "I wonder why they", "named it that...")
            }),
            CHOICE("call someone", [](){
                MC("alright, who should", "I call?")
                MENU(
                    CHOICE("Ino", [](){
                        MC("sure, why not.", "maybe Ino knows")
                        CELL_PHONE_BUZZ
                        MC("Hey Ino. I hope your", "weekend is going well")
                        INO("yup, so far so good", "what's up?")
                        MC("yea, I was curious", "if you know of any", "video game stores")
                        INO("hmm...", "can't say that I", "know of any...")
                        INO("but if I had to guess,", "there might be one", "downtown")
                        MC("alright, I'll see if", "I can find one around", "there")
                        INO("sounds good!", "sorry I couldn't be", "more helpful, just not", "something I know...")
                        MC("all good, take care", "I'll see you at work")
                        INO(MCF("later, {}!"))
                        EMPTY("(you end the call)")
                        MC("ok let's check online", "maybe there will be", "something downtown...")
                        MC("hmm...")
                        MC("oh yea, 'Galapagos Games'", "this might work!")
                    }),
                    CHOICE("Kanade", [](){
                        MC("alright, I'll call", "Kanade")
                        CELL_PHONE_BUZZ
                        MC("Hey Kanade how are", "you doing?")
                        KANADE(MCF("oh hey {}"), "I'm doing alright.", "what's up?")
                        MC("you wouldn't happen", "to know where a", "video game store", "would be?") 
                        KANADE("a video game store?", "well I do know of", "one...")
                        KANADE("my brother plays a", "bunch so I sometimes", "drop by and ask for", "suggestions")
                        MC("oh great! do you have", "a name or address?")
                        KANADE("yea 'Galapagos Games'", "is the name")
                        KANADE("now the address...", "let me think...", "oh! it's at 345 south", "main street.")
                        MC("nice I'll go check", "it out!")
                        KANADE("alright, good luck!", "see you at work!")
                        MC("later!")
                        EMPTY("(you end the call)")
                        MC("alright, let's go", "check it out!")
                    })
                )
            })
        )
        EMPTY("(you make your way", "downtown)")
        SCENE_END
        BG_GAME_STORE
        FADE_IN
        MC("alright, let's ask and", "see if Rin has been here")
        EMPTY("(you make your way", "to the desk)")
        MC("excuse me, have you", "seen a woman here?", "She has dark hair and", "is about this tall.")
        RIN("hey idiot!")
        MC("nevermind, I've found her!")
        SHOW_RIN_NORMAL
        MC("yes, hello I made", "it! can you believe", "it?")
        RIN("no.")
        MC("ok then...")
        HANDLE_EMERGENCY
        RIN("oh you have a", "date with someone else?")
        MC("no it's alright", "it was nothing", "important")
        RIN("so...", "do you know anything", "about the games here?")
        MENU(
            CHOICE("yes", [](){
                MC("yup, I played a bunch", "growing up but haven't", "had much time in", "college to continue")
                RIN("suspicous...")
                MC("what?? how?")
                RIN("I'm pretty sure", "I'll still destroy", "you")
                MC("on which game?")
                RIN("all of them")
                MC("*sigh*")
            }),
            CHOICE("no", [](){
                MC("no, I don't really know", "much about them...")
                RIN("hmm...")
            })
        )
        RIN("so if...", "you had to pick", "a game to play", "now...")
        RIN("which one would", "you pick?")
        MENU(
            CHOICE("fighting game", [](){
                MC("probably a fighting", "those seem difficult")
                RIN_GAME_SELECTION = main_character_state::fighting_game;
            }),
            CHOICE("racing game", [](){
                MC("maybe a racing game?", "that shouldn't be so", "difficult to master")
                RIN_GAME_SELECTION = main_character_state::racing_game;
            }),
            CHOICE("casual game", [](){
                MC("I want the most casual", "game possible. like a", "family game. or something", "easy")
                RIN_GAME_SELECTION = main_character_state::casual_game;
            })
        )
        RIN("are you sure", "about that?")
        MC("...yes?", "I think so")
        RIN("hehehe alright.", "I think I know", "just the game")
        EMPTY("(Rin circles the store", "with manic energy,", "frequently muttering", "and whispering to herself)")
        RIN("alright, I've found", "it!")
        MC("which game is that?")
        RIN("don't worry, you'll see")
        MC("...why not just", "tell me the name?")
        RIN("because...", "I need to beat the", "game first then I'll", "let you play it")
        MC("so we're not going", "to play it today?")
        RIN("...no?", "did you want to", "play it today?")
        MENU(
            CHOICE("yea", [](){
                MC("yea, I think that", "would be fun")
                RIN("*hmph*")
            }),
            CHOICE("don't care", [](){
                MC("honestly it doesn't", "really matter, though", "I'm a bit confused", "why I was invited")
                RIN("there aren't that", "many people in our office", "that play video games")
                RIN("and this seemed more", "interesting than just asking")
            })
        )
        MC("...")
        EMPTY("(Rin heads to the", "front of the store", "to buy the game)")
        RIN("ok I'm heading back", "to play this. later.")
        HIDE
        MC("uhm... bye?")
        SCENE_END
        EMPTY("(that went...", "it was better than", "nothing, right?)")
    }
    //! \brief internal
    bool rin_weekend_1_td_skip;
    //! \brief play the td game. bonus conversation for asking Rin for help
    void rin_weekend_1_td() {
        RIN("next game, you get", "get to bulid these", "towers. They shoot", "at the oncoming enemy")
        MC("so I get money", "for every enemy killed?")
        RIN("yes, and you choose", "to upgrade the towers")
        MC("alright... I'll", "give it a try")
        EMPTY("(you win the first", "wave)")
        MC("so far, so good")
        rin_weekend_1_td_skip = false;
        for(int i = 0; i < 4 && !rin_weekend_1_td_skip; i++) {
            MC("which should I build?")
            auto third_choice = CHOICE("Wizard", [](){
                EMPTY("(you build the Wizard)")
            });
            if(i == 3) {
                third_choice = CHOICE("Ask Rin", [](){
                    MC("Rin I'm stuck on", "this level...")
                    RIN("let's see...", "the SECOND LEVEL?", MCF("{}..."))
                    RIN("alright, here is what", "you do...")
                    EMPTY("(Rin begans a", "PhD-level interpretation", "of the gameplay)")
                    RIN("and if we did", "everything correctly...")
                    EMPTY("(Rin restarts the level)")
                    MC("oh nice! It looks", "like its working!")
                    SHOW_RIN_HAPPY
                    RIN("hehe")
                    EMPTY("(you beat the second", "level!)")
                    SHOW_RIN_NORMAL
                    rin_weekend_1_td_skip = true;
                });
            }
            MENU(
                CHOICE("Cannon", [](){
                    EMPTY("(you build the cannon)")
                }),
                CHOICE("Spike Thrower", [](){
                    EMPTY("(you build the spike", "thrower)")
                }),
                third_choice
            )
            EMPTY("(and start the next", "wave...)")
            MC("aww darn that", "didn't work.", "should I try again?")
            MENU(
                CHOICE("try again!", [](){}),
                CHOICE("give up", [](){
                    MC("ugh, I give up...")
                    RIN("oh bummer, guess", "you'll just have to", "play something easier...")
                    MC("*sigh*")
                    rin_weekend_1_td_skip = true;
                })
            )
        }
        if(!rin_weekend_1_td_skip) {
            MC("well, I've tried it", "all and nothing is", "working...")
            RIN("gee if only you", "were sitting next to", "an expert gamer!")
            MC("*sigh*")
        }
    }
    //! \brief rin is going to the video game lounge
    void rin_weekend_1() {
        RIN_TEXT("I know you are busy", "rotting at home but", "I'll be heading to", "the pc cafe.")
        MC("ok, is that an", "invitation?")
        RIN_TEXT("...")
        MC("I guess I'll try", "to meet you there")
        MC("(looks like Rin doesn't", "want to talk...)")
        MC("(so I need to find", "where this cafe is...)")
        MENU(
            CHOICE("search online", [](){
                MC("let's look online", "first...")
                MC("hmm, I'm mostly getting", "coffee cafes")
                MC("it's gotta be here", "somewhere...")
                MC("wait!")
                MC("here it is!", "333 division street!")
                MC("let's check this place", "out. Hopefully Rin is", "already there")
            }),
            CHOICE("ask around", [](){
                MC("who should I ask?")
                MENU(
                    CHOICE("Kanade", [](){
                        MC("let's call Kanade")
                        CELL_PHONE_BUZZ
                        KANADE(MCF("hello {}!"), "anything new?")
                        MC("Hey Kanade! well, I", "do have have a new", "question. maybe that", "counts?")
                        KANADE("haha alright, what's", "your question!")
                        MC("so I am looking for a", "pc cafe, do you", "know where one is?")
                        KANADE("hold on, let me ask", "my brother...")
                        EMPTY("(You hear Kanade", "knocking on a door)")
                        KANADE("Greg! where is the", "pc cafe you go to?")
                        KANADES_BROTHER("can't you see I'm", "busy??")
                        KANADE("Greg there is a", "DOOR. of course I can't", "see...")
                        KANADES_BROTHER("well its in the", "corner of town.", "333 division street")
                        KANADE("Thank you!")
                        KANADE("did you hear that", MCF("{}?"))
                        MC("yup 333 division street")
                        KANADE("what's going on there?")
                        MC("oh I'm meeting Rin", "there. though, I don't", "know what time...")
                        KANADE("haha still, sounds", "like fun!")
                        MC("alright, I'm going to", "head there now! thank", "you again for the help")
                        KANADE("no problem, see you!")
                        EMPTY("(you end the call)")
                        MC("let's head out!")
                    }),
                    CHOICE("Ino", [](){
                        MC("let's call Ino")
                        CELL_PHONE_BUZZ
                        MC("Hey Ino", "do you have a", "minute?")
                        INO("sure, what's up?")
                        MC("I'm looking for a", "pc cafe in town, do", "you know of any?")
                        INO("hmm... pc cafe...")
                        INO("you know, there might be", "one somewhere on", "division street")
                        INO("I've driven by it", "on my way to my", "parents place")
                        MC("ahh nice, I'll double", "check online")
                        INO("is there some big", "event happening there?")
                        MC("no, not that I know", "of. I'm meeting Rin", "sometime today")
                        INO("sometime?")
                        MC("yea I don't quite", "know when she'll be", "there.")
                        MC("I'll probably just head", "out now and stick around", "until she shows up")
                        INO("alright, best of luck!")
                        MC("thanks Ino!")
                        EMPTY("(you end the call)")
                        MC("alright, let's see...")
                        MC("yea there is one at", "333 division street.", "Let's head out now!")
                    })
                )
            })
        )
        EMPTY("(you make your way", "to the cafe)")
        SCENE_END
        BG_INTERNET_CAFE
        FADE_IN
        MC("let's see if Rin", "is around here...")
        MC("is that her?")
        MC("hello, Rin")
        SHOW_RIN_NORMAL
        RIN("welcome")
        MC("are you in the middle", "of a game now?")
        RIN("you came at a good", "time, my last match", "just ended")
        RIN("I'm surprised you", "found this place")
        MC("I have my methods")
        RIN("Well try using those", "methods to win some", "games.")
        RIN("Here, this seat is", "open")
        MC("which game are we", "playing?")
        RIN("we!?", "...", "no no no...")
        RIN("you need to earn", "a game with me.")
        MENU(
            CHOICE("earn!?", [](){
                MC("what do you mean", "earn? don't you want", "to play with other", "people?")
                RIN("I am fine either way.", "besides, I'm alone", "most of the time", "anyway")
                RIN("so are you in", "or out?")
                MC("well I'm here, right?", "count me in.")
            }),
            CHOICE("where do I start?", [](){
                MC("alright, I'll do", "my best. Where do", "I start?")
                RIN("yea, let's see how", "long that spirit lasts")
            })
        )
        RIN("ok, the first game", "is an easy one:", "Paper Delivery Boy")
        RIN("you ride down the", "street and throw papers", "at the houses.", "easy enough.")
        HANDLE_EMERGENCY
        RIN("hmmmmmmmmm?")
        MC("it was nothing", "important...")
        MC("where were we?", "oh right, the paper", "delivery game...")
        MC("let's get started!")
        int successes = 0;
        for(int i = 0; i < 4; i++) {
            GAME(FMT_24("speed UP: {}/4", i))
            successes += minigame_bugs::round(bn::keypad::key_type::UP);
        }
        GAME("avoid mailbox LEFT: 0/2")
        successes += minigame_bugs::round(bn::keypad::key_type::LEFT);
        GAME("avoid mailbox RIGHT: 1/2")
        successes += minigame_bugs::round(bn::keypad::key_type::RIGHT);
        GAME("throw paper: A")
        successes += minigame_bugs::round(bn::keypad::key_type::A);
        MC("nice I got one!")
        RIN("yea yea", "beginners luck")
        rin_weekend_1_td();
        MC("alright, what now?")
        RIN("well I had a few", "more games in mind", "but I think I'm going", "to head home")
        RIN("I don't think I slpet", "enough last night")
        MC("I guess I'll head out", "too...", "Thanks for the...", "uhm...")
        MC("well, I'll see you", "at work!")
        SHOW_RIN_HAPPY
        RIN("ok, see ya", MCF("{}"))
        SCENE_END
        MC("(that went ok)")
    }
    //! \brief play the specific game, note that the emergency happens before this so the game could be none
    void rin_weekend_2_game(){
        switch(RIN_GAME_SELECTION) {
        case main_character_state::fighting_game:
            RIN("so you picked out", "the fighting game")
            RIN("are you sure you", "want to play this one?")
            MC("yes, I'm sure")
            RIN("then let's get started")
            EMPTY("(Rin boots up 1v1)")
            GAME("Punch! (A)")
            minigame_bugs::round(bn::keypad::key_type::A);
            GAME("Kick! (B)")
            minigame_bugs::round(bn::keypad::key_type::B);
            GAME("Block! (RIGHT)")
            minigame_bugs::round(bn::keypad::key_type::RIGHT);
            for(int i = 0; i < 2; i++) {
                GAME("Double Punch! (A)", FMT_24("{}/2", i))
                minigame_bugs::round(bn::keypad::key_type::A);
            }
            EMPTY("(Rin blocks your attack", "and unleashes a super move)")
            MC("hey what the heck!?")
            RIN("hehe didn't see that", "one coming, did ya?")
            MC("maybe you can teach", "me it?")
            RIN("sure...", "in an hour!")
            MC("*sigh*")
            EMPTY("(you continue fighting", "for another hour)")
            break;
        case main_character_state::racing_game:
            if(state::st.wke_state.emergency_progress[character::RIN] >= 4) {
                RIN("well, we've already", "played some Bosco cart")
                RIN("you still want to", "play it?")
                MC("sure, I'm down for", "a rematch")
                EMPTY("(You both grab", "controllers, eager to", "win the next race)")
            } else {
                RIN("so you picked a racing", "game. are you ready?")
                MC("yea, I think I can", "handle it")
                RIN("really? what makes", "you say that?")
                MC("uh...", "isn't it only turning", "left and right")
                RIN("ha...")
                RIN("here, take this")
                EMPTY("(Rin passes you a", "controller)")
            }
            EMPTY("(the game starts!)")
            for(int i = 0; i < 5; i++) {
               GAME("Accelerate! (A)", FMT_24("{}/5", i))
               minigame_bugs::round(bn::keypad::key_type::A);
            }
            GAME("turn left! (LEFT)")
            minigame_bugs::round(bn::keypad::key_type::LEFT);
            GAME("Accelerate! (A)")
            minigame_bugs::round(bn::keypad::key_type::A);
            for(int i = 0; i < 3; i++) {
                GAME("hard turn right! (RIGHT)", FMT_24("{}/3", i))
                minigame_bugs::round(bn::keypad::key_type::RIGHT);
            }
            MC("aww only third place...")
            RIN("not bad for a", "beginner...")
            MC("yea, how about we try", "that again!")
            EMPTY("(Rin resets the race,", "you play for an hour)")
            break;
        case main_character_state::casual_game:
        default:
            RIN("so I guess we're", "playing a casual game...")
            RIN("what do you think", "about a party game?")
            if(state::st.wke_state.emergency_progress[character::RIN] >= 1) {
                MC("oh, like Bosco Party?")
                RIN("yea we can play a", "few new mini-games")
                RIN("not like the ones", "we played before")
            } else {
                RIN("have you played Bosco Party", "before?")
                MC("no, I haven't.", "what do I do?")
                RIN("well, there are a", "bunch of simple games.", "most just require a", "few button inputs")
            }
            RIN("here, let's try this", "one. You need to flip", "the omelette in the", "pan")
            RIN("but make sure you", "flip it at the right", "time")
            MC("hmm... let's try", "it once")
            EMPTY("(Rin starts the game)")
            for(int i = 0; i < 5; i++) {
                GAME("The omelette is cooking", FMT_24("(DOWN) ({}/5)", i))
                minigame_bugs::round(bn::keypad::key_type::DOWN);
            }
            GAME("FLIP! (UP)")
            minigame_bugs::round(bn::keypad::key_type::UP);
            for(int i = 0; i < 6; i++) {
                GAME("The omelette is cooking", FMT_24("(DOWN) ({}/6)", i))
                minigame_bugs::round(bn::keypad::key_type::DOWN);
            }
            GAME("FLIP AGAIN! (UP)")
            minigame_bugs::round(bn::keypad::key_type::UP);
            EMPTY("(The minigame finishes", "and you tie with Rin)")
            MC("wow a tie! I must", "be pretty good at this", "game.")
            RIN("*grr*")
            EMPTY("(Rin is determined to", "win, you play for an hour", "to decide the victor)")
        }
    }
    //! \brief internal
    bool rin_weekend_2_ignored;
    //! \brief rin wants to play the game you bought earlier
    void rin_weekend_2() {
        RIN_TEXT("hey I finally beat", "the game we bought", "together.")
        MC("cool. good for you!")
        RIN_TEXT("are you interested", "in playing it?")
        MENU(
            CHOICE("no", [](){
                MC("no, not really.")
                RIN_TEXT("fine.")
                rin_weekend_2_ignored = true;
            }),
            CHOICE("yes", [](){
                MC("sure, I'd be down")
                RIN_TEXT("alright, come over in", "an hour and we can play", "it together")
                rin_weekend_2_ignored = false;
            })
        )
        if(rin_weekend_2_ignored) {
            state::st.rel_state.reset(character::RIN);
            return;
        }
        EMPTY("(you wait an hour", "and head over)")
        SCENE_END
        BG_RINS_APARTMENT_DOOR
        FADE_IN
        EMPTY("(you knock on the door)")
        MC("...")
        MC("Rin, I'm here!")
        MC("...")
        MC("maybe I got the time", "wrong?")
        MC("no, it was definitely", "an hour ago when I got", "the text...")
        MENU(
            CHOICE("bang on the door", [](){
                MC("guess I'll bang on", "door again")
                EMPTY("*BAM* *BAM*")
                RIN("WHAT THE HECK DO", "YOU WANT? I DON'T", "WANT TO BUY YOUR", "CRAP!")
                MC("Rin... it's me")
                SHOW_RIN_NORMAL
                RIN("oh... sorry", "about that. I have", "had some weird people", "come by recently")
                MC("weird people?")
                RIN("yea they are always", "trying to sell me", "stuff. And they wear", "suits. gross.")
                MC("hmm... well glad", "you're safe, I guess")
            }),
            CHOICE("wait it out", [](){
                MC("I'll text her and", "just wait it out")
                for(int i = 0; i < 10; i++) {
                    EMPTY("(you wait some more)", FMT_24("{}/10", i))
                }
                MC("alright, I'll try again")
                EMPTY("(the door opens)")
                SHOW_RIN_NORMAL
                RIN("oh... sorry", "about that. I was in", "middle of something")
            })
        )
        RIN("come inside...")
        SCENE_END
        BG_RINS_ROOM
        FADE_IN
        SHOW_RIN_NORMAL
        RIN("alright, let's get", "this party started!")
        MC("...sure?")
        rin_weekend_2_game();
        MC("sheesh...")
        MC("I am *yawn* tired")
        RIN("tired? we've only just", "started!")
        HANDLE_EMERGENCY
        RIN("nothing important?")
        MC("no, I'm good.", "where were we?")
        RIN("you wanted to take", "a 'break'")
        MC("don't you ever get", "tired of playing games?")
        RIN("well... yes but...", "aren't you having fun?")
        MENU(
            CHOICE("no", [](){
                MC("no, not really", "I mean it's OK but-")
                RIN("but?!")
                MC("well maybe I haven't", "found one I like")
                RIN("is there something else", "you'd rather be doing?", "I mean, what on Earth", "could be more interesting?")
                MC("well, I could be", "watching a movie...", "or playing some tennis...")
                RIN("I understand the movie", "part but you would", "rather be sweating in", "a gym?")
                MC("well-")
                RIN("here's a sport: take", "my trash to the bin", "outside")
                MC("Rin, that isn't-")
                RIN("so is that a yes", "or a no?")
                MENU(
                    CHOICE("NO!", [](){
                        MC("NO. take the darn", "thing out yourself")
                        RIN("fine. I'll do it", "tomorrow...")
                    }),
                    CHOICE("fine", [](){
                        MC("FINE. I'll do it.", "but just this one", "time!")
                        EMPTY("(Rin let's out a", "sigh of relief)")
                        EMPTY("(you bundle the trash", "bag and take it outside)")
                        MC("better, yea?")
                        RIN("...thank you...", MCF("{}..."))
                    })
                )
            }),
            CHOICE("yes", [](){
                MC("yea, this is a lot", "of fun. I think", "I'm feeling a", "bit tired.")
                RIN("hmm... alright.")
            })
        )
        RIN("so do you want to", "head home?")
        MC("I can stick around", "for a little while", "longer")
        RIN("ok...")
        auto family_choice = CHOICE("ask about family", [](){
            MC("do you have any", "family?")
            RIN("yea I have five", "other siblings")
            MC("FIVE? gosh")
            RIN("...")
            MC("do you like them", "at all?")
            RIN("I have four brothers", "so you can guess how", "that turned out")
            RIN("somehow they got more", "annoying as time went", "on")
            RIN("so, naturally, I ended", "up doing most things", "alone")
            RIN("except video games,", "at least I had that", "in common with them")
            MC("ok that makes sense")
            RIN("do you have any", "family?")
            MENU(
                CHOICE("yes", [](){
                   MC("yes I had one sibling", "growing up but they", "were much older")
                   MC("so we never really", "did anything together")
                   MC("I guess it is", "similar to your", "situation, minus the", "annoying brothers")
                   RIN("ehh barely similar")
                }),
                CHOICE("no", [](){
                    MC("no, I was an", "only child. I did", "do many things alone...")
                    MC("though I think it", "had the opposite", "effect...")
                    MC("where I tried to make", "more friends and did", "anything under the", "sun to avoid boredom")
                    RIN("I think I found", "a few interesting", "things and stuck", "with them")
                    RIN("they also happened", "to be things that I", "can do alone.")
                })
            )
        });
        if(state::st.wke_state.emergency_progress[character::RIN] >= 4) {
            // already learned about family
            family_choice = CHOICE("ask about future", [](){
                MC("so where do you", "see yourself in the", "future?")
                RIN("HAHA WHAT?")
                RIN("like am I going to", "become an astronaut or", "a doctor?")
                MC("well... sort-of.", "I mean do you have", "any plans or dreams", "like that?")
                //! \rin_maybe doesn't have any plans or dreams for the future
                RIN("can't say I've given", "it much thought. the answer", "is probably no, though")
                RIN("I have a reasonable", "job and I have time", "on the weekends to", "play games")
                RIN("I mean, maybe I would", "travel a bit? though I", "don't really know", "where I would go")
                RIN("don't most people just", "look at old bulidings", "or weird rocks?")
                RIN("sounds pretty silly", "though maybe there is", "at least one other", "cool place out there")
                MC("I haven't done much", "travel myself, but I'm", "sure there are places", "you would enjoy")
                MC("but it probably won't", "be obvious until you", "make a trip or explore", "a bit first")
            });
        }
        MENU(
            CHOICE("ask about hobbies", [](){
                MC("so do you really", "only play games in your", "free time?")
                RIN("I have other hobbies", "I just... do most", "of them alone")
                MC("you don't want", "more people to do", "them with?")
                RIN("well games make sense", "to play with others")
                RIN("but... yea", "I don't really have", "the patience to organize", "a party or a trip")
                RIN("I think growing up with", "a big faily just made", "those things annoying")
                RIN("so here I am,", "rotting alone")
                MC("Why not try something", "small? like even taking", "a walk to the park")
                RIN("you want to walk", "to the park now?")
                MC("sure, why not!?")
                RIN("... no, that was", "a joke. I don't want", "to walk at all")
                MC("at least give it", "a chance!")
                RIN("fine... maybe next time")
            }),
            family_choice
        )
        RIN("ok enough yapping.", "I want to get back", "to gaming")
        MC("I guess I'll head", "home...")
        MC("thank you for the", "invition. I'll see", "you later")
        RIN(MCF("see ya {}"))
        SCENE_END
        MC("(that went well)")
    }

    //! \brief internal
    bool rin_weekend_3_no;
    //! \brief rin wants to go cycling
    void rin_weekend_3() {
        // bicycle
        RIN_TEXT("hey do you own", "a bicycle?")
        MENU(
            CHOICE("yes", [](){
                MC("yea I have one.", "do you need to", "borrow it?")
                RIN_TEXT("no I don't need", "to borrow it")
                RIN_TEXT("maybe this is weird", "but maybe we could ride", "somewhere together?")
                MENU(
                    CHOICE("sure", [](){
                        MC("sure, that sounds", "interesting")
                        RIN_TEXT("ok, let's meet at", "the park by work", "maybe in an hour?")
                        MC("ok, works for me")
                        rin_weekend_3_no = false;
                    }),
                    CHOICE("rather not", [](){
                        MC("it's a bit, hot.", "maybe another day!")
                        RIN_TEXT(":(")
                        rin_weekend_3_no = true;
                    })
                )
            }),
            CHOICE("no", [](){
                MC("no, I don't. do you", "need one for something?")
                RIN_TEXT("oh, nevermind.", "its nothing important")
                rin_weekend_3_no = true;
            })
        )
        if(rin_weekend_3_no) {
            vnlib::end(vnlib::BAD_END);
            return;
        }
        MC("(Wow, Rin made", "real plans!)")
        EMPTY("(you wait an hour", "and then head out)")
        SCENE_END
        BG_PARK
        FADE_IN
        SHOW_RIN_HAPPY
        MC("hey Rin")
        RIN(MCF("oh hey {}"))
        MC("so...", "I'll be honest, I", "am really shocked to", "see you outside")
        SHOW_RIN_NORMAL
        RIN("oh shut it!")
        RIN("where do you want", "to ride to?")
        MC("do you not have", "a place picked out?")
        RIN("I bought the bike last", "weekend. I didn't really", "do much planning after", "that")
        MC("well, all we really", "need to do is remember", "how to get back and", "we can go anywhere")
        RIN("so we just pick", "a street and go?")
        MC("maybe? I don't really", "get out much either")
        RIN("then let's go down this", "one!")
        MC("sure")
        SCENE_END
        BG_STREET
        FADE_IN
        SHOW_RIN_HAPPY
        MC("so how did you", "decide on buying a bike,", "anyway?")
        RIN("I was thinking about", "it last weekend. you", "know?")
        RIN("maybe I should give", "going outside a chance.")
        RIN("but the only thing I", "ever did outside was", "ride a bike")
        RIN("so I found this used", "one and... yea")
        if(handle_emergency([](){
            MC("sorry Rin something", "has come up")
            RIN("well thanks, idiot!", "I was really looking", "forward to something", "new for once")
            RIN("but I can tell", "that it means nothing", "to you")
            RIN("just leave me", "alone. I don't", "care anymore")
            HIDE
            state::st.rel_state.reset(character::RIN);
        })) {
            return;
        }
        MC("where was I?")
        MENU(
            CHOICE("where did you ride?", [](){
                MC("where did you ride", "to when you were", "younger?")
                RIN("hmm... well nowhere far,", "just around the block", "and to the park, maybe", "to the store")
                RIN("there aren't many options", "when you're a kid")
                MC("maybe we should go", "somewhere far today!")
                SHOW_RIN_NORMAL
                RIN("didn't you just", "say something about", "knowing our way back?")
                MC("well yea-")
                SHOW_RIN_HAPPY
                RIN("maybe something easy", "this weekend, ok?")
                MC("ok, something easy")
            }),
            CHOICE("why stop riding?", [](){
                MC("Do you remember when", "you stopped riding your", "bike?")
                RIN("probably around middle", "or high school")
                RIN("why I stopped...", "that's hard to say", "I guess I got busy", "with other things")
                RIN("like computer stuff", "so it kinda dissapeared", "on its own")
                MC("fair enough, besides", "its easy enough to get", "back into")
            })
        )
        MC("well I don't know", "maybe places to ride", "around here")
        MC("I guess something", "generic might do")
        MENU(
            CHOICE("forest", [](){
                MC("is there a forest", "area? maybe they have", "a road trail we", "could use?")
                RIN("yea that might work", "but...")
                RIN("what if we get stuck", "on the trail, though?")
                RIN("I'm not sure this", "thing can handle that", "terrain")
                MC("hmm... good point")
                MC("let me check online")
                EMPTY("(you search for a", "forest area on your", "phone)")
                MC("oh here is a nature", "area. looks like it", "is in the south-west", "part of town")
                MC("it looks like big", "but it is only twenty", "minutes from here")
                MC("want to check it out?", "we don't even need", "to ride around the whole", "thing. just the start")
                RIN("hmm... ok", "just the beginning", "of the trail is fine")
                MC("alright, let's head out")
                EMPTY("(you ride to the forest)")
                SCENE_END
                BG_FOREST
                FADE_IN
                SHOW_RIN_NORMAL
                EMPTY("(you start down the", "forest path)")
            }),
            CHOICE("lake", [](){
                MC("maybe there is a small", "lake? we could ride", "around that a few", "times")
                RIN("ok see if you", "can find one that", "isn't too far")
                EMPTY("(you begin to search", "on your phone)")
                MC("oh wow that really", "is one in this town")
                MC("looks like it on the", "edge of town, somewhere", "south-east of here")
                MC("maybe a twenty minute", "ride?")
                RIN("alright, let's get started!")
                EMPTY("(you ride to the lake)")
                SCENE_END
                BG_LAKE
                FADE_IN
                SHOW_RIN_NORMAL
                EMPTY("(you circle the lake", "a few times)")
            }),
            CHOICE("park", [](){
                MC("maybe this park would do", "they might have a", "few paths and we could", "stay close")
                RIN("sure, we can cirle", "around a few times")
                MC("cool")
                EMPTY("(you ride around the", "park a bit more, taking", "a different path here", "and there)")
            })
        )
        RIN(MCF("so {}"), "what do you do when", "you're riding around?")
        MENU(
            CHOICE("listening", [](){
                MC("mostly I find myself", "listening to things", "around me")
                MC("like the wind rustling", "tree leafs or birds", "chirping")
                RIN("so you don't want", "to listen to music", "at all?")
                MC("I used to...", "but I realized things", "were must more peacful", "when the music is off")
                MC("I suppose you have", "to try it a couple time", "to convince yourself")
                RIN("hmm...")
            }),
            CHOICE("looking", [](){
                MC("mostly looking around", "maybe if there are", "plants or animals", "moving around")
                MC("you never know what", "you might find")
                MC("maybe I'll find a", "flower or a cool rock")
                RIN("a cool rock?!", "that is kinda weird")
                MC("yea... well...", "yea I guess so")
            }),
            CHOICE("thinking", [](){
                MC("most of the time", "I am thinking about", "random things")
                MC("it could be a movie", "I watched, it could be", "a new programming idea...")
                RIN("do you ever think", "about people?")
                MC("not really. I mean", "not people from real", "life")
                RIN("oh...")
            })
        )
        MC("Do you need ideas", "on what to do while", "you ride?")
        RIN("well, I just didn't", "know if I was doing", "it correctly...")
        MC("oh...", "yea, I don't think", "there is any one", "way to ride")
        MC("it's like art.", "you kinda just start", "and figure it out", "along the way")
        RIN("HAHA ART!?", "you're not an artist!", "you're a programmer!")
        MC("hey, maybe I'm a", "famous painter and", "you just don't know it!")
        RIN("HAHAA no way", "in heck that could be", "the case...")
        MC("*grr*")
        EMPTY("(Rin is looking a", "bit weary)")
        RIN("let's... uhm...", "stop here for a bit")
        EMPTY("(Rin points to a bench)")
        RIN("maybe I could have", "picked a better day", "to ride")
        MC("yea, it's a bit warm", "today... still...", "its a good day to get", "outside")
        RIN("...haha...", "yea...")
        EMPTY("(you sit for a bit", "catching your breath", "and cooling down)")
        RIN(MCF("so {}"), "I've been thinking")
        SHOW_RIN_HAPPY
        RIN("that maybe things", "are better with", "you around")
        MC("!", "(this is abrupt!)")
        SHOW_RIN_NORMAL
        RIN("wait, do you not", "think so too??")
        MC("no no no no", "I just... you're", "never so forward", "with things")
        MC("wait...", "you're always forward!", "but not like...", "in this way")
        RIN("DO YOU NOT THINK", "SO??")
        MC("Rin I enjoy being", "with you, too")
        MC("I think you're a bit", "harsh at times so it", "took a bit of adjusting")
        MC("but I think you're", "evolving")
        RIN("evolving?! wha-", "what on earth?")
        MC("I'M NOT GOOD WITH", "THESE THINGS", "EITHER, OK?")
        MC("you're easy to get", "along with when you're", "being polite")
        MC("I don't know why", "you don't try it", "more often.")
        MC("you'd have a million", "more friends if you", "really gave them", "a chance")
        MC("I know because...", "I gave you a chance", "and...")
        MC("I'm better for it")
        SHOW_RIN_HAPPY
        RIN("*sniff*")
        RIN("go on...")
        MC("uhm...")
        RIN("go on, keep saying", "nice things, please")
        MC("...", "well...")
        RIN("please!?")
        MC("I'm getting...", "thirsty. Let's head", "back and stop somewhere", "for some water")
        SHOW_RIN_NORMAL
        RIN("ugh, fine")
        SCENE_END
        EMPTY("(you head back with Rin,", "suspiciously delighted", "at how well the day", "went)")
        vnlib::end(vnlib::GOOD_END);
    }

    //! \brief ino's weekend events
    const vnlib::story_fx WEEKEND_INO[] = {ino_weekend_0, ino_weekend_1, ino_weekend_2, ino_weekend_3};
    //! \brief kanade's weekend events
    const vnlib::story_fx WEEKEND_KANADE[] = {kanade_weekend_0, kanade_weekend_1, kanade_weekend_2, kanade_weekend_3};
    //! \brief rika's weekend events
    const vnlib::story_fx WEEKEND_RIKA[] = {rika_weekend_0, rika_weekend_1, rika_weekend_2, rika_weekend_3};
    //! \brief rin's weekend events
    const vnlib::story_fx WEEKEND_RIN[] = {rin_weekend_0, rin_weekend_1, rin_weekend_2, rin_weekend_3};
    //! \brief get the next weekend event for a character. no bounds check!
    vnlib::story_fx get_next_story(character::CHAR_ENUM c) {
        int progress = STORY_PROGRESS[c];
        switch(c) {
        case character::INO:
            return WEEKEND_INO[progress];
        case character::KANADE:
            return WEEKEND_KANADE[progress];
        case character::RIKA:
            return WEEKEND_RIKA[progress];
        case character::RIN:
            return WEEKEND_RIN[progress];
        default:
            return [](){};
        }
    }

    /*! \brief if a character relationship is high enough, have an event
     *
     * sort characters by relationship decreasing, use the first character that has
     * a relationship above the story progress threshold.
     * currently: #WEEKEND_REL_PROGRESS_MULTIPLIER points per story
    */
    bool handled_event() {
        for(character::CHAR_ENUM c : state::st.rel_state.by_rel_desc()) {
            bool relationship_high_enough = state::st.rel_state.rels[c] >= STORY_PROGRESS[c] * WEEKEND_REL_PROGRESS_MULTIPLIER;
            bool have_progress_left = STORY_PROGRESS[c] < MAX_STORY_COUNT;
            if(relationship_high_enough && have_progress_left) {
                // start story
                original_story = c;
                current_story = c;
                get_next_story(c)();
                STORY_PROGRESS[c] += 1;
                return true;
            }
        }
        return false;
    }

    //! \brief a generic sunday event. created to support runtime_state::EMERGENCIES_ON_SUNDAY
    void handle_sunday_event(character::CHAR_ENUM saturday_char) {
        original_story = saturday_char;
        if(saturday_char == character::GENERIC) {
            MC("Sunday always comes", "so soon!")        
            if(!handle_emergency([](){})) {
                MC("(I should really", "help out more", "at work)")
            }
        } else {
            MC("Saturday was nice...", "maybe today will", "be better!")
            if(!handle_emergency([](){
                MC("wow! it really", "will get better!")
            })) {
                MC("well...")
                MC("there goes my", "only option at doing", "something interesting")
            }
        }
    }

    //! \brief ephemeral state to avoid sat+sun having same char. only possible as saves don't happen on weekends
    character::CHAR_ENUM saturday_character;
    void handle_event() {
        FREE
        BG_HOME_DESK
        FADE_IN
        if(state::st.is_saturday()) {
            // on saturdays, maybe handle an event
            if(handled_event()) {
                saturday_character = original_story;
            } else {
                saturday_character = character::GENERIC;
                // TODO maybe non-character event worldbuilding if not event handled
                MC("It's Saturday...", "maybe I should clean", "this place up?")
            }
        } else if(state::st.is_sunday() && EMERGENCIES_ARE_ON_SUNDAY) {
            // on sunday, only handle an event if emergencies are enabled
            handle_sunday_event(saturday_character);
        }
    }

#define PLAYTEST_CHOICE(type, character, story_num) CHOICE(#character#story_num, character##type##story_num)
#define PLAYTEST_CHOICES(type, character) PLAYTEST_CHOICE(type,character,0),PLAYTEST_CHOICE(type,character,1),PLAYTEST_CHOICE(type,character,2),PLAYTEST_CHOICE(type,character,3),
#define PLAYTEST_EVENTS(character) PLAYTEST_CHOICES(_weekend_, character)
    void playtest_event() {
        FREE
        BG_HOME_DESK
        FADE_IN
        auto options = vnlib::dense_MenuOptions();
        vnlib::menu({
            PLAYTEST_EVENTS(ino)
            PLAYTEST_EVENTS(kanade)
            PLAYTEST_EVENTS(rika)
            PLAYTEST_EVENTS(rin)
            CHOICE("back", [](){})
        }, &options);
    }

    //! \brief setup variables to test both emergency prompts and stories
    void playtest_emergency_setup(character::CHAR_ENUM c, int story) {
        // make it sunday
        state::st.day = 6;
        UNLOCKED_MARKETING = true;
        UNLOCKED_SALES = true;
        UNLOCKED_SECURITY = true;
        state::st.runtime_state.em_day = runtime_state::EMERGENCIES_ON_SUNDAY;
        // make desired character the highest relationship value
        for(auto ch : character::characters) {
            state::st.rel_state.reset(ch);
        }
        state::st.rel_state.rels[c] = relationship_state::REL_MAX;
        state::st.wke_state.emergency_progress[c] = story;
        handle_sunday_event(character::GENERIC);
    }

#define PLAYTEST_EMERGENCY_CHOICE(ch, ch_enum, story_num) CHOICE(#ch#story_num, [](){ playtest_emergency_setup(ch_enum, story_num); })
#define PLAYTEST_EMERGENCY_CHOICES(ch, ch_enum) PLAYTEST_EMERGENCY_CHOICE(ch, ch_enum, 0),PLAYTEST_EMERGENCY_CHOICE(ch, ch_enum, 1),PLAYTEST_EMERGENCY_CHOICE(ch, ch_enum, 2),PLAYTEST_EMERGENCY_CHOICE(ch, ch_enum, 3),
#define PLAYTEST_EMERGENCIES(ch, ch_enum) PLAYTEST_EMERGENCY_CHOICES(ch, ch_enum)
    void playtest_emergency() {
        FREE
        BG_HOME_DESK
        FADE_IN
        auto options = vnlib::dense_MenuOptions();
        vnlib::menu({
            PLAYTEST_EMERGENCIES(ino, character::INO)
            PLAYTEST_EMERGENCIES(kanade, character::KANADE)
            PLAYTEST_EMERGENCIES(rika, character::RIKA)
            PLAYTEST_EMERGENCIES(rin, character::RIN)
            CHOICE("back", [](){})
        }, &options);
    }
}