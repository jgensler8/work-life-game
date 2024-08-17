#include "instant_message.h"
#define PROGRESS state::st.im_state.progress

namespace instant_message {
    //! \brief relationship state increment needed to get a new instant message
    constexpr bn::fixed IM_STATE_REL_MULTILIER = 7;
    //! \brief relationship state increment needed to get a new thank you
    constexpr bn::fixed THANK_YOU_REL_MULTILIER = 4;
    //! \brief there are four im conversations
    constexpr unsigned int MAX_IM_COUNT = 4;
    //! \brief there are five thank you conversations
    constexpr unsigned int MAX_THANKS_COUNT = 5;

    //! \brief ino busy thank you
    void ino_busy_thank_you() {
        INO(MCF("sorry {}"), "I'm a bit busy but", "I saw a task complete!", "nice work!")
        MC(":)")
    }
    //! \brief when no more thanks are left, send this
    void ino_generic_thank_you() {
        INO("Keep up the good", MCF("work, {}!"))
        MC("Thank you, Ino!")
    }
    //! \brief ino thank you 0
    void ino_thank_you_0() {
        INO("Hey, there! Just saw", "you moved a task to", "done. Great work!", "Keep it up!")
        MC("Thank you!", "I'll do my best!")
        MC("(I can't let", "her down!)")
    }
    //! \brief ino thank you 1
    void ino_thank_you_1() {
        INO("You seem to be getting", "the hang of it!", "Keep it up!")
        MC(":)")
    }
    //! \brief ino thank you 2
    void ino_thank_you_2() {
        INO("Hey, I noticed you've", "been putting in", "some serious hours")
        INO("Just wanted to say", "that I see your", "hard work.")
        MC("Thank you!", "I'll keep it up!")
    }
    //! \brief ino thank you 3
    void ino_thank_you_3() {
        INO(MCF("{}!"), "Do you see how", "many tasks you've", "completed!?")
        INO("Maybe you need", "need something a", "bit more challenging?")
        MC("sure! bring it on!")
    }
    //! \brief ino thank you 4
    void ino_thank_you_4() {
        INO(MCF("Hey, {}"), "Since joining, you've", "really been a huge", "help to this team")
        INO("I understand programming", "isn't always the", "most exciting task")
        INO("That's why I wanted", "to thank you again!")
        INO("It really means a", "lot. I am proud to work", "with you and I hope", "you are proud too")
        MENU(
            CHOICE("I love this team!", [](){
                MC("I couldn't have", "picked a better team")
                MC("We are lucky to be", "surrounded by hardworking", "people")
                MC("Team members that", "really push everyone", "to do their best")
                MC("I know that if I", "do my part, my team", "has my back.")
                INO("Brilliant!")
            }),
            CHOICE("You are the best!", [](){
                MC("Well, I wouldn't", "be here without your help")
                MC("You are the best leader", "and I wouldn't have", "it any other way!")
                INO("Aww, thank you", MCF("{}!"))
            })
        )
    }
    //! \brief Ino talks about the other teams (required first day)
    void ino_0() {
        MC("hey Ino!", "I was wondering if", "you could share more", "info about the team")
        // programming
        INO("ahh the programming", "team. sure!")
        INO("we'll we mostly exist", "to build out the", "features that cusomters", "request")
        MC("check!")
        // marketing
        INO("the closest team to", "us on this floor", "is the marketing team")
        INO("the marketing team", "mostly handles", "advertisements and", "social media")
        INO("I've always thought", "of marketing as a", "sort of celebration")
        INO("after all, we've put", "so much work into", "these features, let's", "share them!")
        MC("ok, got it")
        // sales
        INO("then there is the sales", "team...")
        INO("most of the time", "the sales team is the", "one that gets this", "feedback")
        INO("though we sometimes", "decide to build", "things on our own")
        MC("ahh ok")
        // security
        INO("finally, there is the", "security team.")
        INO("they find and patch", "bugs that would cause", "defects in the expected", "functionality.")
        INO("we're bound to make", "mistakes so they're the", "last line of defense,", "so to speak")
        MC("phew, that's quite a", "bit to remember!")
        // wrap up
        INO("just focus on the", "programming tasks for", "now")
        INO("it won't take long", "for you to cross paths", "with members of the", "other teams")
        INO("WidgetCorp isn't that", "big, after all!")
        MC("ok, I'll do my best!")
        INO("good luck!", "I'll talk to you later")
        MC("sounds good.", "see you!")
    }
    //! \brief Ino talks about her past work experience
    void ino_1() {
        MC("hey Ino", "I was curious...")
        MC("how long have you", "been leading the", "programming team?")
        INO("how long?", "let's see...")
        INO("about 5 years.")
        INO("Though it feels", "like just yesterday", "I joined...")
        //! \ino was previously a software engineer
        INO("Maybe its hard to", "tell, but I was once", "a software engineer")
        //! \ino believes in her leadership
        INO("but I thought I", "could be a better leader", "than a programmer")
        MENU(
            CHOICE("would you go back?", [](){
                MC("would you consider", "going back to", "writing code?")
                INO("well, I do think about", "it...")
                INO("I enjoy what I do", "now because I get to", "work with more people")
                INO("It is an interesting", "balance...")
                INO("working on what", "you're good at versus", "working on what you want")
                MC("I can't say I'm good", "at much now, but I'll", "do my best this coming", "year")
                INO("keep it up!")
            }),
            CHOICE("other career?", [](){
                MC("did you always", "want to work in", "software?")
                MC("any other plans?")
                //! \ino_maybe would become a musician
                INO("I do play the guitar.", "Both electric and", "acoustic")
                INO("My parents taught me", "when I was growing up.", "I guess I don't", "think much of it")
                INO("Maybe it would be cool", "to make music for a", "living? It's hard to say")
                MC("true, can't say I know", "many musicians other", "than the famous ones")
                INO("it is a cool dream", "but there are still other", "jobs out there")
                //! \ino_maybe wants to work with nice people
                INO("as long as the people", "are nice, then the job", "will be fine with me")
            })
        )
        INO("oh shoot!", "I lost track of time")
        INO("I have another meeting!", "Thanks for the chat", MCF("{}!"))
        MC("later, Ino");
    }
    //! \brief Ino talks about her movie preferences
    void ino_2() {
        MC("Hey Ino, are you", "around?")
        INO(MCF("oh hey {}"), "yup I have a bit of", "time now. what's up?")
        MC("well I've been running", "out of things to do", "on the weekend..")
        MC("do you have any", "tv or movie", "recommendations?")
        INO("well I can't say I", "know you're specific", "taste...")
        INO("but I'm a sucker for", "action movies. especially", "if they have cars")
        //! \ino like action movies (and Fast and Glroious)
        INO("have you seen Fast and", "Glorious: Tokyo Swift?")
        MC("oh the Fast and", "Glorious franchise! hmm", "I've only seen clips", "online...")
        INO("well they have so", "many movies! maybe ten?", "that would be an easy", "way to pass time!")
        MENU(
            CHOICE("more rec.", [](){
                MC("any others movies you", "can recommend?")
                INO("well, anything with", "tension and fighting", "let's see...")
                //! \ino_maybe likes old dramas (Markface movie)
                INO("maybe Markface, its an", "old crime drama but it", "pretty long, nearly", "three hours!")
                INO("that should keep you", "busy!")
                MC("oh nice, Markface, I'll", "write that one down")
            }),
            CHOICE("seen them all?", [](){
                MC("have you seen them", "all?")
                //! \ino_maybe loves the Fast and Glorious franchise
                INO("oh yea! NO WAY I", "would miss a Fast and", "Glorious release!")
                INO("well they aren't", "all that great, to", "be honest...")
                INO("but they all have", "some charm!")
                INO("so give one a chance", "and maybe you'll find", "other ones you like!")
                MC("ok I'll give it", "a try!")
            })
        )
        MC("do you ever try", "watching other genres?", "like comedy or romance?")
        INO("ehh not really.", "comedy is ok but", "when things aren't", "moving I fall asleep")
        INO("the same with romance", "I guess it doesn't", "really have the 'WOW'", "moments")
        INO("its fun seeing explosions", "and fights. anything to", "keep me on the edge", "of my seat")
        MC("I like them too!")
        MC("well thanks for the", "info, I'll check out", "some of those movies", "this weekend!")
        INO("I hope you enjoy", "them!", "talk to you later!")
        MC("later!")
    }
    //! \brief internal
    bool ino_3_global_skip;
    //! \brief Ino wants to head to the bar
    void ino_3() {
        MC("Hey Ino!", "how is it going?")
        INO(MCF("hello, {}"), "oh things are going", "well")
        INO("say, do you have", "some free time now?", "I was thinking of", "heading to the")
        INO("bar to celebrate this", "week's progress")
        MENU(
            CHOICE("sorry", [](){
                MC("sorry, I am not", "feeling well, maybe", "another time?")
                INO("all good, I'll", "talk to you later!")
                ino_3_global_skip = true;
            }),
            CHOICE("sure!", [](){
                MC("sure, that sounds", "wonderful!")
                INO("ok let's head out", "at 4pm. I'll meet", "you at the front desk")
                MC("got it!")
                ino_3_global_skip = false;
            })
        )
        if(ino_3_global_skip) {
            return;
        }
        SCENE_END
        EMPTY("(you and Ino", "walk to the bar)")
        BG_BAR
        FADE_IN
        SHOW_INO_NORMAL
        INO("ahh it's good to", "get out!")
        INO("it can sure get dull", "in thre. though I'm too", "busy to notice")
        MC("to be fair, it isn't", "any more cheery in", "here...")
        INO("aww once they get", "some music going it'll", "feel just like home!")
        MENU(
            CHOICE("how did you find this?", [](){
                MC("so how did you", "find this place?")
                INO("well it would be", "cute if I said I was", "walking around and", "happened to find it")
                INO("but the truth is", "that I saw an Ad", "online...")
                MC("oh haha")
            }),
            CHOICE("seems empty?", [](){
                MC("it seems a bit", "empty... does", "this place get", "any business?")
                INO("it sure does! but ", "it still is a hidden gem.")
                INO("there is hardly ever", "a crowd here. which", "means there is always", "a place to sit!")
                //! \ino_maybe doesn't like busy places
                INO("I can't stand the busy", "ones. Let me enjoy", "my stay without bumping", "into anyone!")
                MC("I hear you on", "that one!")
            })
        )
        //! \ino is a regular at the bar
        INO("I am a bit of a regular", "here. Usually I'll", "pop in after work", "for a drink or two")
        INO("they also have an", "open mic night where", "the locals will", "perform their songs")
        MC("oh nice, what day", "is that usually on?")
        INO("once or twice during", "the week. But usually", "there is one on Monday")
        MENU(
            CHOICE("how many people?", [](){
                MC("how many people", "end up performing?", "there isn't too", "much space in here")
                INO("oh maybe six or", "seven people")
                INO("it does fill up the", "place but people are", "friendly so it ends", "up feeling cozy")
                MC("that sounds nice!")
            }),
            CHOICE("have you performed?", [](){
                MC("have you every performed", "at one of those?")
                INO("I did a long while", "ago. but I haven't", "really created anything", "new recently")
                INO("creativity isn't", "always something you", "can control")
                MC("true")
            })
        )
        EMPTY("(you and Ino sit", "and enjoy the cozy", "bar. an hour passes)")
        MC("ahh! I think that's", "it for me!", "This was a good idea!")
        SHOW_INO_HAPPY
        INO("I'm glad we could", "find the time. Thanks", "for joining me", "today!")
        INO("I'll stick around a", "bit longer and see", "if the regulars show", "up")
        MC("cool! I'll see", "you at work!")
        INO("later!")
        SCENE_END
        MC("(ahh that was nice!)")
    }

    //! \brief kanade busy thank you
    void kanade_busy_thank_you() {
        KANADE("I'm a bit busy today", "but thanks for the", "help! talk to", "you later!")
        MC(":)")
    }
    //! \brief when no more thanks are left, send this
    void kanade_generic_thank_you() {
        KANADE("Keep up the good", MCF("work, {}!"))
        MC("Thank you, Kanade!");
    }
    //! \brief kanade thank you 0
    void kanade_thank_you_0() {
        KANADE("hey! I just saw you", "completed a marketing", "task!")
        KANADE("I can't thank", "you enough!")
        MC("haha well I did have", "some free time...")
        KANADE("well we always", "appreciate it!")
        KANADE("but don't let your", "programming team down!")
        MC("will do!")
    }
    //! \brief kanade thank you 1
    void kanade_thank_you_1() {
        KANADE("Woo! You go!", "You're on a", "roll, keep it up!")
        MC("whoo!", "You can count", "on me! :)")
    }
    //! \brief kanade thank you 2 (she is worried)
    void kanade_thank_you_2() {
        KANADE("Are you sure", "you are spending time", "on your programming", "tasks?")
        MENU(
            CHOICE("yes!", [](){
                MC("yes yes yes","its all going", "according to plan")
                MC("I'm sure Ino", "will let me know", "when something isn't", "right")
                MC("I trust her ability", "to lead. She won't", "let things fall", "out of line")
                KANADE("OK I trust her, too.", "Thanks again for", "your help!")
            }),
            CHOICE("well...", [](){
                MC("well, sort-of.", "I mean Ino hasn't", "really said anything")
                MC("and I still do", "a task now and then")
                KANADE("NOW AND THEN!?")
                KANADE(MCF("{}!"), "What if you get fired?", "Then you can't", "help either team...")
                MC("true, but I really", "dont' think that will", "happen")
                MC("I'm all for preparing", "for the worst, but some", "things just need to", "work themselves out")
                KANADE(":/")
                KANADE("ok I trust you!", "but please don't get", "fired!")
                MC("sure, I'll", "do my best!")
            })
        )
    }
    //! \brief kanade thank you 3 (silly joke)
    void kanade_thank_you_3() {
        KANADE(MCF("uhm, {}"), "I have some bad", "news...")
        KANADE("You're killing it!")
        MC("...")
        KANADE("ok that one", "was a bit dark...", "but you are seriously", "amazing!")
        KANADE("have you thought", "about switching teams?")
        MENU(
            CHOICE("yes", [](){
                MC("I've given it a", "bit of thought. I", "enjoy the mix of", "tasks now")
                MC("but maybe the", "marketing department", "is a better fit.", "right?")
                KANADE("well, we'd be lucky", "to have you!")
            }),
            CHOICE("not really", [](){
                MC("no, not really", "honestly, I love both", "teams.")
                MC("at this point, I", "don't think I could", "choose either one!")
                KANADE("well, if you were", "ever in doubt,", "we would love to", "have you here!")
                MC("understood!")
            })
        )
    }
    //! \brief kanade thank you 4 (sincere thanks)
    void kanade_thank_you_4() {
        KANADE(MCF("Hey, {}!"), "well there isn't", "really an easy" ,"way to say it")
        KANADE("I like to make", "people feel welcomed", "especially when they've", "gone above and beyond")
        KANADE("and I think you've", "really gone above and", "beyond with our", "marketing work!")
        KANADE("I wish there was", "a more sincere way", "to thank you other", "than just saying it...")
        KANADE("BUT I DONT KNOW ONE", "so THANK YOU!")
        MC("I do it 'cause", "I love it!")
        KANADE("well, we owe you", "one! or twenty...")
    }
    //! \brief Kanade asks if we are feeling better
    void kanade_0(){
        MC("hey Kanade")
        KANADE(MCF("hello, {}!"))
        KANADE("I heard you weren't", "feeling well the", "other day")
        KANADE("Are you eating enough?", "Are you skipping", "breakfast?")
        MENU(
            CHOICE("I never skip breakfast!", [](){
                MC("haha I was just", "feeling a bit sleepy")
                MC("no, I am not", "skipping breakfast.", "Actually, I quite", "enjoy it!")
                KANADE("I enjoy breakfast", "too!")
            }),
            CHOICE("skipping breakfast",[](){
                MC("well, I do skip", "breakfast from time", "to time")
                MC("but I probably didn't", "get enough sleep the", "other day...")
                KANADE("maybe you need to", "find something you", "enjoy eating!") 
            })
        )
        /*! \kanade likes eggs */
        KANADE("When I have time", "I usually make eggs")
        KANADE("but the rest", "of my family", "eats cereal")
        KANADE("what do you", "usually have?")
        MENU(
            CHOICE("eggs", [](){
                MC("I usually make", "eggs, too")
                KANADE("oh, wonderful!")
            }),
            CHOICE("cereal", [](){
                MC("I am a cereal", "person")
                MC("can't say I am", "too proud of it", "though...")
                KANADE("oh cereal is fine!", "its better", "than nothing!")
            }),
            CHOICE("buttered toast", [](){
                MC("well, I usually", "have trouble waking", "up on time")
                MC("so I usually just", "throw some toast", "in the oven")
                KANADE("well I like bread too", "but maybe pick something", "better!")
            })
        )
        KANADE("oh shoot! look at", "the time!")
        KANADE("I have a meeting!", "I gotta go!")
        MC("see ya, Kanade")
    }
    //! \brief we talk to Kanade about her hobbies (baseball)
    void kanade_1(){
        MC("hey Kanade")
        KANADE(MCF("oh hey {}!"), "how are things?")
        MENU(
            CHOICE("good", [](){
                MC("well I'm doing alright", "making some steady", "progress on work")
                KANADE("good same here!")
            }),
            CHOICE("i've been better", [](){
                MC("I've definitely been", "better!")
            })
        )
        if(state::st.wke_state.story_progress[character::KANADE] == 0) {
            MC("Do you have any hobbies?")
            //! \kanade likes baseball and reads books
            KANADE("Well, I do like", "watching baseball. and I", "read books every so", "often")
        }
        MC("oh!")
        MC("I was watching the", "news recently and", "...")
        MC("there was a grand", "slam during the game", "yesterday.")
        MC("Did you see?")
        KANADE(MCF("oh, {}!"), "I was at the game!", "It was amazing!")
        KANADE("The most unbelievable", "part is the player", "that hit the ball", "...")
        KANADE("has some of the", "worst season stats", "in the league!")
        KANADE("now if they can", "hit a home run,", "than I can finish", "this paperwork!")
        MC("haha, I like the", "spirit!")
        KANADE("well, I gotta split.", "see ya!")
        MC("later!")
    }
    //! \brief more small talk (baseball news or would-you-rather)
    void kanade_2(){
        MC("hello Kanade", "are you around?")
        KANADE(MCF("hello, {}!"), "yup I've got some", "free time!")
        MENU(
            CHOICE("baseball news", [](){
                MC("any cool baseball news?")
                KANADE("let's see...")
                KANADE("well there was a raffle", "to win an autographed", "ball the other day")
                KANADE("it was being run through", "a radio station so", "I tried calling in", "to win...")
                KANADE("I even got my brother", "and mom in on it!", "Dad put up a fuss", "so that didn't help")
                KANADE("but we just got put on", "hold...", "maybe next time? :(")
                MC(":( sorry to", "hear that.", "Can you buy one", "at the store?")
                KANADE("an autographed one?", "not really.")
                KANADE("I mean I'm SURE", "unlimited money can find", "a way...")
                //! \kanade_maybe wishes she had more money
                KANADE("but with my salary,", "this is the only option", "I have :(")
                MC("that is...", "heartbreaking!")
                KANADE("well keep your eyes", "peeled! if you ever see", "one, send me a message!")
                MC("will do!")
            }),
            CHOICE("would you rather", [](){
                MC("would you rather win", "a week long vacation", "or free lunch for", "a year?")
                KANADE("ooo this is a", "good one!", "let's see...")
                //! \ino_maybe likes the beach
                KANADE("well I am a beach", "go-er so the trip is", "temping...")
                KANADE("but a year's supply", "of cookies sounds", "way too good!")
                KANADE("I mean really really", "think about it! That", "has to be millions", "of cookies!")
                KANADE("how could that NOT", "be worth it??")
                KANADE("ugh now I'm getting", "hungry...", ">:(")
                MC("so a years supply", "of cookies is your", "final choice?")
                KANADE("absolutely!", "which one would you", "pick?")
                MENU(
                    CHOICE("vacation", [](){
                        MC("I'd have to pick", "the vacation!", "I've had a few", "places on my list")
                        MC("for too long!")
                        KANADE("didn't you just", "graduate? how do you", "have a travel list?")
                        MC("oh I see a bunch", "of pictures online", "plus I have a few", "older friends that")
                        MC("do a bunch of travel", "for their work!")
                        KANADE("ahh ok!", "that makes sense.")
                        KANADE("yea can't say", "I have many places", "on my list...")
                        //! \kanade_maybe like spending time with her family
                        KANADE("I like spending time", "with my family and", "it is always hard", "to get them to")
                        KANADE("do the same thing.")
                        KANADE("I guess I've never", "bothered planning", "something like", "a vacation...")
                        MC("well there is still", "time to change your", "answer!")
                        KANADE("haha well...", "I'm still picking", "the million cookies!")
                    }),
                    CHOICE("free lunch", [](){
                        MC("I'd have to pick", "the free lunch, too!")
                        MENU(
                            CHOICE("pizza", [](){
                                MC("I would have to pick", "pizza for my lunch", "item! I'd never", "get tired of that!")
                                KANADE("ahh ok", "that's a good choice.", "but I think one month", "of pizza...")
                                KANADE("will...","'change' you...")
                                MC("oh, right...", "that is true")
                                MC("I mean it can't", "be THAT much worse", "compared to cookies!?")
                                KANADE("no no no no", "cookies are the", "best option! period!")
                            }),
                            CHOICE("burrito", [](){
                                MC("I think I could", "eat burritos for a", "year!")
                                MC("plus I probably", "don't have to eat", "the whole thing...")
                                MC("maybe I can have", "it for lunch AND", "dinner!")
                                KANADE("hmm I suppose", "that could work. They", "are pretty filling!")
                                KANADE("buuuuut", "I'm not sure unlimited", "burritos beats unlimited", "cookies")
                                MC("???")
                            }),
                            CHOICE("cake", [](){
                                MC("it's a tough choice", "but I'd have to go", "with cake!")
                                MC("even just a small slice", "would be so nice!", "how easy would it", "be to wake up")
                                MC("every day knowing", "you get cake for lunch!")
                                KANADE("oh I hadn't thought", "of that! who knew", "waking up early", "could sound nice")
                            })
                        )
                    })
                )
            })
        )
        KANADE("ok, I gotta split!", "talk to you later!")
        MC("see ya!")
    }
    //! \brief internal
    bool kanade_3_global_skip;
    //! \brief Kanade is hungry, head to the diner to get some food
    void kanade_3(){
        MC("hey are you around?")
        KANADE(MCF("oh hello, {}!"), "how are you doing?")
        MC("things are going well", "do you have some free", "time now?")
        KANADE("actually I forgot my", "lunch at home and I", "only had a granola bar", "for lunch")
        KANADE("do you want to grab", "some food? I think", "there is a diner", "around here")
        MENU(
            CHOICE("no thanks", [](){
                MC("actually I've got", "a lot going on", "right now. I'll", "have to skip")
                KANADE("oh bummer.", "well I'll talk to", "you later, then!")
                MC("ok. see ya!")
                kanade_3_global_skip = true;
            }),
            CHOICE("sure!", [](){
                MC("sure, that sounds", "delightful!")
                KANADE("ok. lets meet in the", "lobby at 4!")
                kanade_3_global_skip = false;
            })
        )
        if(kanade_3_global_skip) {
            return;
        }
        EMPTY("(you wait until", "4pm...)")
        EMPTY("(you and Kanade meet", "up and head to the", "diner)")
        SCENE_END
        BG_DINER
        FADE_IN
        SHOW_KANADE_NORMAL
        KANADE("yes! finally!")
        KANADE("I'm going to order", "something tasty...", "let's see...")
        KANADE("do you want some", "pancakes? looks like", "there is a lunch", "special")
        MC("sure!")
        KANADE(MCF("oh {}"))
        KANADE("you've been putting", "a lot of work on", "the marketing tasks...")
        KANADE("thanks again!")
        KANADE("we all really", "appreciate it! It can't", "be easy balancing", "both team's work...")
        MC("oh, it's nothing...")
        KANADE("well it has really", "made a difference!")
        KANADE("we had one other", "person join around the", "time I was hired...")
        KANADE("and they left only", "a few months after we", "started because the", "work was demanding")
        KANADE("I talked with them", "them about it...", "here, actually, of", "all places")
        MC("did you try to get", "them to stick around?")
        KANADE("well, that was my", "initial thought but after", "our conversation...")
        KANADE("I realized that it", "probably wasn't going to", "work well in the long", "term.")
        MC("ahh I see")
        MC("have you thought about", "leaving WidgetCorp?")
        KANADE("I mean, the thought", "has crossed my mind a", "few times...")
        KANADE("it isn't even about", "the work...")
        //! \kanade wants to change careers
        KANADE("I guess I don't", "get a lot out of my", "work.")
        KANADE("at least if you go", "to a gym you see", "results")
        KANADE("I don't even have", "those! It's like a", "big work treadmill!")
        MC("so you don't know", "what else you would", "try?")
        KANADE("I don't know...", "maybe programming?")
        KANADE("I hear the security", "team also does some", "coding though I hear", "its a bit different")
        KANADE("which team do you", "think would be a good", "fit for me?")
        MENU(
            CHOICE("programming", [](){
                MC("probably the programming", "team. I think the work", "is a bit more", "difficult than marketing")
                MC("but not too difficult", "for you to pick up")
                MC("plus, you could always", "make the switch later.", "programming to security")
            }),
            CHOICE("security", [](){
                MC("if you really want", "a challenge, then try", "talking to the", "security team")
                MC("maybe they'll have", "some tasks you could", "do now to see if", "its a good fit!")
            })
        )
        KANADE("true, thank you", "for the advice,", MCF("{}!"))
        KANADE("alright, I'm feeling", "pretty full!", "let's head back!")
        MC("works for me!")
        SCENE_END
        MC("(that went well)")
    }


    //! \brief rika busy thank you
    void rika_busy_thank_you() {
        RIKA("sorry, I'm a bit", "tied up right now!", "Thanks for the", "help!")
        MC(":)")
    }
    //! \brief when no more thanks are left, send this
    void rika_generic_thank_you() {
        RIKA("Awesome work!", "Keep it up!")
        MC(":)")
    }
    //! \brief rika thank you 0
    void rika_thank_you_0() {
        RIKA("Hey, great job!", "only a few more and", "you'll be a pro!")
        MC("Thank you!", "I'll keep at it!")
    }
    //! \brief rika thank you 1
    void rika_thank_you_1() {
        RIKA("Hey, great job!", "only a few more and", "you'll be a pro!")
        MC("Thank you!", "I'll keep at it!")
    }
    //! \brief rika thank you 2
    void rika_thank_you_2() {
        RIKA("Hey, great job!", "only a few more and", "you'll be a pro!")
        MC("Thank you!", "I'll keep at it!")
    }
    //! \brief rika thank you 3
    void rika_thank_you_3() {
        RIKA("Hey, great job!", "only a few more and", "you'll be a pro!")
        MC("Thank you!", "I'll keep at it!")
    }
    //! \brief rika thank you 4
    void rika_thank_you_4() {
        RIKA("Hey, great job!", "only a few more and", "you'll be a pro!")
        MC("Thank you!", "I'll keep at it!")
    }
    //! \brief admits she is a slow typist, meet to get some coffee
    void rika_0(){
        MC("hey Rika")
        RIKA(MCF("yo {}"), "let me swing by", "and we can grab some", "coffee")
        MC("oh! uhm...", "sure!")
        SCENE_END
        BG_OFFICE_DESK
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA(MCF("hey, {}"))
        RIKA("I hope getting some", "coffee is fine")
        RIKA("I know everyone love", "messaging these days", "so I'm sorry if this", "is a bit weird")
        MC("it isn't weird!", "I was thinking of", "getting some coffee")
        //! \rika is a slow typist
        RIKA("the truth is that I'm", "a slow typist so", "talking in-person is", "easier")
        MC("is that why you ended", "up in sales? so you", "could spend time on", "the phone?")
        //! \rika likes talking to people
        RIKA("well, sort-of. The", "whole sales thing", "happened because", "I like talking")
        RIKA("but it does work pretty", "well given that there", "isn't much computer work")
        RIKA("how long have you", "been at WidgetCorp?")
        MC("it's my first month")
        RIKA("oh wow!", "My first month was...", "gee..", "three years ago?")
        RIKA("yea, just about.", "It's a fun place", "definitely lots to", "get done")
        RIKA("but the people make", "it worth it. It is", "awesome to see so", "much camraderie")
        MENU(
            CHOICE("agreed", [](){
                MC("agree! I love it", "here! It reminds me", "of a few of my group", "projects in college")
                MC("well, the ones that", "went well...")
                RIKA("haha WidgetCorp is", "way better than a group", "project!")
                RIKA("Keep up and you'll have", "a great time here!")
            }),
            CHOICE("ehh", [](){
                MC("ehh I don't see it", "much. But maybe that's", "because I haven't", "been around long")
                RIKA("haha just you wait!")
                RIKA("You may not always", "love the work, but", "you'll definitely love", "the people!")
                MC("you think so?")
                RIKA("oh I know so!", "I talk to people all", "day. all sorts of", "people")
                RIKA("happy ones, angry ones")
                RIKA("without a doubt, we", "have the best people", "on planet earth", "in this very office!")
                MC("that... sounds", "amazing!")
                RIKA("don't let it distract", "you too much though! haha")
            })
        )
        RIKA("well I'm going", "to head back. It was", "nice meeting you!")
        MC("nice to meet you, too")
    }
    //! \brief go for a short walk with Rika
    void rika_1(){
        MC("hey Rika", "are you free now?", "maybe we can take", "a walk?")
        RIKA("yo!", "sure, maybe somewhere", "close?")
        MC("ok. let's meet", "near the main desk")
        SCENE_END
        EMPTY("(you head to the desk", "and head to a nearby", "park)")
        SCENE_END
        BG_PARK
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("ahh, man is it", "good to be out", "of a chair!")
        MENU(
            CHOICE("i don't mind it", [](){
                MC("I don't mind sitting", "at my desk. I guess", "my area isn't", "really busy so")
                MC("its easy to concentrate", "I wouldn't want", "to sit near your", "team")
                RIKA("WOAH WOAH", "I am right here!", "hahaha")
                MC("oh I didn't mean", "it like that...", "oops")
                RIKA("haha that's ok", "I understand what", "you mean")
                RIKA("I guess we have pretty", "different jobs, eh?")
                RIKA("can't say I've ever", "though about learning", "to code, though...")
                MC("technically it", "is a language so", "its almost like", "talking, I guess")
                MC("who knows, maybe it", "is something you", "would enjoy!")
                //! \rika_maybe doesn't try many new things
                RIKA("ehh, I can't say", "I'm one to try new", "things often")
                RIKA("plus I am content", "where I am at.", "but ya, who knows!")
            }),
            CHOICE("i hate it", [](){
                MC("honestly I hate", "working at my", "desk")
                RIKA("woah woah", "aren't you on the", "programming team?")
                RIKA("I mean, I guess", "you don't have to LOVE", "it...")
                MC("haha okay okay", "maybe hate is the", "wrong word here!")
                MC("but I do enjoy taking", "breaks every now and", "then. plus, I", "see programming")
                MC("as a means to an end.", "but the end is", "definitely worth the", "effort")
                //! \rika_maybe always trys her best at work to make things right
                RIKA("I hear you!", "customers aren't", "always patient but I", "always try my")
                RIKA("best to make things", "right. I mean you'd", "want that too, right?")
                MC("true")
            })
        )
        RIKA("alright, lets head back.", "that was fun, let", "me know when you", "want to go again!")
        MC("likewise, this was", "nice. talk to you later!")
    }
    //! \brief Rika is hungry, head to the pizza place
    void rika_2(){
        MC("hey Rika", "anything new")
        RIKA("hey there!", "yea, not much for me")
        RIKA("say, I haven't eaten", "lunch yet, want to", "get some food?")
        MC("oh, sure!")
        SCENE_END
        BG_PIZZA_PLACE
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("pizza!")
        RIKA("this place can be", "hit or miss so I'm", "sorry if you don't", "end up liking it")
        MC("oh, that's fine")
        RIKA("now, what should I get?")
        MENU(
            CHOICE("meat lovers", [](){
                MC("what about the meat", "lovers?")
                RIKA("oh good choice!", "let's do that")
            }),
            CHOICE("veggie", [](){
                MC("how does the veggie", "pizza sound?")
                RIKA("that sounds pretty", "good. but...", "I want something more", "filling...")
                RIKA("I'll go with the", "meat lovers!")
            }),
            CHOICE("cheese", [](){
                MC("cheese would be good!")
                RIKA("hmm...", "maybe something with a", "more flavor")
                RIKA("I'll go with the", "meat lovers!")
            })
        )
        RIKA("which one will you", MCF("get, {}?"))
        MENU(
            CHOICE("same one", [](){
                MC("I'll get the same one", "you picked")
                RIKA("mm")
            }),
            CHOICE("daily special", [](){
                MC("looks like there is a", "daily special...", "I'll go with that one")
                RIKA("ooo! which flavor?")
                MC("it looks like...", "anchovy")
                RIKA("anchovy?", "well...", "you enjoy that!")
            })
        )
        EMPTY("(Rika grabs the slices)")
        RIKA(MCF("so {}..."), "have you thought about", "switching teams?")
        MC("like... leaving the", "programming team?")
        RIKA("well... you've been", "working on a lot of", "sales tasks")
        RIKA("so I've been wondering", "if maybe you wanted to", "join our team!")
        MENU(
            CHOICE("yes", [](){
                MC("yes, I would love", "to join the sales", "team!")
                RIKA("have you talked with", "Ino about it?")
                MC("well...")
                RIKA("haha maybe run it", "by her first")
                RIKA("I'm glad to hear you're", "considering it")
                RIKA("I'm sure you'll fit", "in anywhere, sales team", "or otherwise!")
                MC("sure!")
            }),
            CHOICE("I help everyone", [](){
                MC("well these days I", "help anyone who needs", "it.")
                MC("this week seemed like", "a work for some of the", "sales tasks")
                MC("but I have plenty of", "programming tasks left", "so I can't be too", "generous")
                RIKA("the sales team", "appreciates your help!")
                RIKA("be careful not to", "let the programming", "tasks get out of hand")
                RIKA("unfortunately, I couldn't", "help if something like", "that were to happen...")
            })
        )
        EMPTY("(you wrap up your meal)")
        RIKA("well, that was nice!", "thanks for coming with", MCF("{}!"))
        MC("any time!", "let's head back")
        SCENE_END
    }
    //! \brief Rika wants to head to the bar to play darts
    void rika_3(){
        MC("hey rika")
        RIKA("listen, I've had a", "stressful week. Why", "don't we had to", "the bar later?")
        MC("sure, works for me.", "meet at the front", "desk at 5pm?")
        RIKA("let's do it!")
        EMPTY("(you wait until 5.", "You meet with Rika", "then head to the", "bar)")
        SCENE_END
        BG_BAR
        FADE_IN
        SHOW_RIKA_NORMAL
        RIKA("ahhhhhhhhhh", "finally")
        MC("wow some week?")
        RIKA("yea, just swamped with", "calls...")
        RIKA("Its like, as soon as", "I complete a task", "there are two more", "new ones!!")
        RIKA("I mean how is that", "possible? It this a", "game??")
        MC("no, without a doubt", "this is real life.", "but I totally know", "what you mean.")
        MC("no matter how hard", "I work, there is always", "something more to do")
        MC("as if there is no", "end in sight! like", "a work treadmill!")
        RIKA("or a hampster wheel!")
        MC("yea!!")
        RIKA("*gah*")
        RIKA("oh they have a dart", "board! want to check", "it out?")
        MC("sure, I've never", "tried that before")
        EMPTY("(you head over to the", "dart board)")
        RIKA("alright, let's see", "who can get the most", "points")
        MC("I'm just going to try", "and get it on the", "board")
        EMPTY("(you take your first", "throw)")
        MC("aww. only seven!")
        RIKA("here, throw the rest", "of these, too")
        MC("here is goes...")
        MC("and...")
        MC("ok, that's like 23 in", "total")
        RIKA("my turn!")
        EMPTY("(Rika takes aim...)")
        RIKA("oh no!")
        MC("did that hit the wall?")
        RIKA("so that's what all", "those holes are...")
        RIKA("here, I'll aim for the", "top")
        EMPTY("(the dart hits the wall,", "this time above the", "board)")
        RIKA("I guess you could call", "that aiming, hehe")
        EMPTY("(Rika takes aim for", "her last dart)")
        RIKA("oh nice! one of these", "twenty ones!", "what does this little", "area mean?")
        MC("I think it means", "double points, right?", "because it's smaller?")
        RIKA("ooooh!", "fourty points for me!")
        EMPTY("(you finish up a few", "rounds of darts)")
        RIKA("*phew* well, I'll", "head home from here")
        SHOW_RIKA_HAPPY
        RIKA("thanks for joining me", MCF("{}!"))
        MC("that was fun! let's", "do this again, Rika!")
        SCENE_END
    }

    //! \brief Rin question gate (mainly for format option dialog)
    bool rin_answer_result_correct;
    //! \brief Python GIL
    void rin_0() {
        MC("hey rin how's it going?")
        RIN("what global mutex prevents", "Python threads from", "executing bytecode", "concurrently?")
        MENU(
            CHOICE("global command sequencer", [](){
                MC("its the global command", "sequencer")
                RIN("ha, back to the books")
                rin_answer_result_correct = false;
            }),
            CHOICE("global interpreter lock", [](){
                MC("its the global interpreter", "lock")
                rin_answer_result_correct = true;
            }),
            CHOICE("global wait group", [](){
                MC("its the global wait group")
                RIN("close, but not correct", "see ya")
                rin_answer_result_correct = false;
            })
        )
        if(!rin_answer_result_correct) {
            return;
        }
        RIN("wow I'm surprised you", "didn't need to Woogle", "that")
        MC("I've had a few projects", "back in university", "explaing how it worked...")
        RIN("well, well", "I'll be the judge of", "that...")
        RIN("what do you need", "anyway?")
        MC("oh I just wanted", "to chat")
        RIN("chat?", MCF("{}, take one"), "look at the backlog")
        RIN("how do you have", "time to chat?")
        MC("well...", "I mean weight lifters", "need to take breaks", "between sets...")
        RIN("oh you lift weights?")
        MENU(
            CHOICE("yes", [](){
                MC("yes, I've exercising", "seriously for many", "years")
                RIN("well don't think that", "it makes you better", "than others")
                RIN("I'd lift weights", "too if I wasn't so", "busying doing things", "with-")
                RIN("nevermind... I", "need to get back", "to work")
            }),
            CHOICE("no", [](){
                MC("I mean, I lift", "up heavy things", "every so often...")
                RIN("LOL I bet the", "only thing you lift", "are grocery bags")
                MC("I do, in fact,", "lift grocery bags!", "all of them!")
                RIN("LOL go lift so", "more work out of the", "backlog.")
                RIN("I've got more important", "things to do")
            })
        )
        MC("ok then...")
    }
    //! \brief Rin max unsigned int value
    void rin_1() {
        MC("hey rin want to", "take a break?")
        RIN("what is the max value", "of an unsigned", "16 bit integer?")
        MENU(
            CHOICE("65534", [](){
                MC("65534, right?")
                rin_answer_result_correct = false;
            }),
            CHOICE("65535", [](){
                MC("65535. easy.")
                rin_answer_result_correct = true;
            }),
            CHOICE("65536", [](){
                MC("so easy. 65536.")
                rin_answer_result_correct = false;
            })
        )
        if(!rin_answer_result_correct) {
            RIN("HA WRONG!", "maybe next time")
            return;
        }
        RIN("wow look at that!")
        RIN("maybe one day", "you'll be smart", "enough to ask", "me questions")
        MC("alright, here's a", "question: how", "many years have you", "been at WidgetCorp")
        //! \rin_maybe has been at WidgetCorp for six years
        RIN("easy. six years.", "see how smart I am?", "how fast I type?")
        MC("no one is measuring", "how fast you type")
        //! \rin_maybe is a very fast typist
        RIN("well I measure.", "and last time I", "checked, I am pretty", "darn fast")
        MC("do your fingers", "hurt from all that", "typing?")
        RIN("the only thing that", "hurts is reading", "your sorry messages")
        RIN("maybe come up with", "a real joke next time")
        RIN("later, nerd.")
        MC("(how does she have", "a job here...)")
    }
    //! \brief internal
    bool rin_2_mediocre_joke;
    //! \brief Rin RSB
    void rin_2() {
        MC("(which joke should", "I pick?)")
        MENU(
            CHOICE("mediocre joke", [](){
                MC("why should you never", "trust stairs")
                rin_2_mediocre_joke = true;
            }),
            CHOICE("bad joke", [](){
                MC("what do dentists", "call their x-rays?")
                rin_2_mediocre_joke = false;
            })
        )
        RIN(MCF("no {}"), "I get to ask", "questions first")
        RIN("What is the instruction", "for the ARM7 mneumonic", "RSB?")
        MENU(
            CHOICE("Reverse Subtract", [](){
                MC("Reverse Subtract!")
                rin_answer_result_correct = true;
            }),
            CHOICE("Rolling Subtract", [](){
                MC("is it Rolling Subtract?")
                rin_answer_result_correct = false;
            }),
            CHOICE("Reverse Super Blue", [](){
                MC("Reverse...", "Super...", "Blue...?")
                rin_answer_result_correct = false;
            })
        )
        if(!rin_answer_result_correct) {
            RIN("ERR maybe next", "time!")
        }
        RIN("wow bingo!", "oh... the joke")
        RIN("I have no idea")
        MC("did you try and", "think about it?")
        RIN("yea but I am busy", "so I decided I don't", "have time to think")
        RIN("plus it would ruin", "the joke if I knew", "the answer")
        MC("well... I guess")
        if(rin_2_mediocre_joke) {
            MC("you should never trust", "stairs because their", "always UP TO", "SOMETHING!!!")
            RIN("wow")
            MC("pretty good, though,", "right?")
            RIN("good enough to", "belong in the trash", "bin. keep working", "on it.")
        } else {
            MC("dentists call their", "x-rays TOOTH-PICS!")
            RIN("ok but shouldn't", "toothpicks also make", "sense in this context?")
            MC("Rin...")
            RIN("alright alright fine.", "ha ha.")
            RIN("now get back to", "work!")
        }
    }
    //! \brief Rin doesn't have a question
    void rin_3() {
        MC("hey Rin are you free?")
        RIN("yes I'm free", "what's up?")
        MC("no question today?")
        RIN("no it's been a long", "week and I don't", "have the energy")
        MC("I was curious how", "you ended up on the", "security team")
        RIN("well, I wanted to", "avoid as many people", "as I possibly could")
        RIN("and my school counselor", "suggested some type of", "computer work")
        RIN("so I started programming", "but was very confused", "by how many existing", "problems there were")
        RIN("so why not try to", "make a career out of", "finding and fixing", "problems?")
        MC("ahh you make it", "sound so generous")
        RIN("it is actually", "quite painful")
        MC("oh...")
    }

    /*! \brief a character is online only when their IM progress is past a threshold.
     *
     * this threshold is based on IM_STATE_REL_MULTILIER
    */
    online_state online_or_busy(character::CHAR_ENUM c) {
        bool relationship_high_enough = state::st.rel_state.rels[c] >= PROGRESS[c] * IM_STATE_REL_MULTILIER;
        bool progress_available = PROGRESS[c] < MAX_IM_COUNT;
        if(relationship_high_enough && progress_available) {
            return ONLINE;
        }
        return BUSY;
    }

    online_state status(character::CHAR_ENUM c) {
        int weekday = state::st.day % 7;
        switch(c) {
        case character::INO:
            if(weekday == 0 || weekday == 3) {
                return online_or_busy(character::INO);
            }
            return OFFLINE;
        case character::KANADE:
            if(weekday == 1 || weekday == 4){
                return online_or_busy(character::KANADE);
            }
            return OFFLINE;
        case character::RIKA:
            if(weekday == 0 || weekday == 1 || weekday == 3 || weekday == 4) {
                return online_or_busy(character::RIKA);
            }
            return OFFLINE;
        case character::RIN:
            if(weekday == 2) {
                return online_or_busy(character::RIN);
            }
            return OFFLINE;
        default:
            return OFFLINE;
        }
    }

    //! \brief ino's im conversations
    const vnlib::story_fx IMS_INO[MAX_IM_COUNT] = {ino_0, ino_1, ino_2, ino_3};
    //! \brief kanade's im conversations
    const vnlib::story_fx IMS_KANADE[MAX_IM_COUNT] = {kanade_0, kanade_1, kanade_2, kanade_3};
    //! \brief rika's im conversations
    const vnlib::story_fx IMS_RIKA[MAX_IM_COUNT] = {rika_0, rika_1, rika_2, rika_3};
    //! \brief rin's im conversations
    const vnlib::story_fx IMS_RIN[MAX_IM_COUNT] = {rin_0, rin_1, rin_2, rin_3};

    void send_message(character::CHAR_ENUM c) {
        FREE
        BG_IM
        switch(c) {
        case character::INO:
            IMS_INO[PROGRESS[c]]();
            break;
        case character::KANADE:
            IMS_KANADE[PROGRESS[c]]();
            break;
        case character::RIKA:
            IMS_RIKA[PROGRESS[c]]();
            break;
        case character::RIN:
            IMS_RIN[PROGRESS[c]]();
            break;
        default:
            return;
        }
        PROGRESS[c] += 1;
        state::st.rel_state.modify_relation(c, relationship_state::GOOD);
    }

    //! \brief ino's thank you conversations
    const vnlib::story_fx THANKS_INO[MAX_THANKS_COUNT] = {ino_thank_you_0, ino_thank_you_1, ino_thank_you_2, ino_thank_you_3, ino_thank_you_4};
    //! \brief kanades's thank you conversations
    const vnlib::story_fx THANKS_KANADE[MAX_THANKS_COUNT] = {kanade_thank_you_0, kanade_thank_you_1, kanade_thank_you_2, kanade_thank_you_3, kanade_thank_you_4};
    //! \brief rika's thank you conversations
    const vnlib::story_fx THANKS_RIKA[MAX_THANKS_COUNT] = {rika_thank_you_0, rika_thank_you_1, rika_thank_you_2, rika_thank_you_3, rika_thank_you_4};
    //! \brief rin's thank you conversations (she doesn't do this)
    const vnlib::story_fx THANKS_RIN[MAX_THANKS_COUNT] = {};
    
    //! \brief thank you sent when a character is BUSY
    void busy_thank_you(character::CHAR_ENUM c) {
        switch(c) {
        case character::INO:
            ino_busy_thank_you();
            break;
        case character::KANADE:
            kanade_busy_thank_you();
            break;
        case character::RIKA:
            rika_busy_thank_you();
            break;
        default: break;
        }
    }
    //! \brief thank you sent when rel state is high enough
    void relationship_thank_you(character::CHAR_ENUM c) {
        switch(c) {
        case character::INO:
            THANKS_INO[state::st.im_state.thank_you[c]]();
            break;
        case character::KANADE:
            THANKS_KANADE[state::st.im_state.thank_you[c]]();
            break;
        case character::RIKA:
            THANKS_RIKA[state::st.im_state.thank_you[c]]();
            break;
        default: return;
        }
        state::st.im_state.thank_you[c] += 1;
    }
    //! \brief thank you sent when online but rel isn't high enough
    void generic_thank_you(character::CHAR_ENUM c) {
        switch(c) {
        case character::INO:
            ino_generic_thank_you();
            break;
        case character::KANADE:
            kanade_generic_thank_you();
            break;
        case character::RIKA:
            rika_generic_thank_you();
            break;
        default: break;
        }
    }

    void thank_you(character::CHAR_ENUM c) {
        auto st = status(c);
        if(st == OFFLINE) {
            return;
        } else if (c == character::RIN) {
            // Rin never thanks us
            return;
        }
        COMPUTER("*ding*")
        BG_IM
        MC("hmm, what's that?")
        // send a relationship thank you even if they are busy
        if(state::st.im_state.thank_you[c] * THANK_YOU_REL_MULTILIER > state::st.rel_state.rels[c]
            && state::st.im_state.thank_you[c] < MAX_THANKS_COUNT) {
            relationship_thank_you(c);
        } else if (st == BUSY) {
            busy_thank_you(c);
        } else {
            generic_thank_you(c);
        }
        state::st.rel_state.modify_relation(c, relationship_state::GOOD);
    }

    //! \brief playtest post-task thanks
    void playtest_thank_you(character::CHAR_ENUM ch, int num) {
        state::st.rel_state.rels[ch] = relationship_state::REL_MAX;
        state::st.im_state.thank_you[ch] = num;
        relationship_thank_you(ch);
    }

    //! \brief playtest afternoon im
    void playtest_im(character::CHAR_ENUM ch, int num) {
        PROGRESS[ch] = num;
        send_message(ch);
    }

#define PLAYTEST_IM_THANKS_GENERIC(ch) CHOICE("gen", [](){ generic_thank_you(ch); })
#define PLAYTEST_IM_THANKS_BUSY(ch) CHOICE("busy", [](){ busy_thank_you(ch); })
#define PLAYTEST_IM_THANKS_NUM(ch_short, ch, num) CHOICE(#ch_short#num, [](){ playtest_thank_you(ch, num); })
#define PLAYTEST_IM_THANKS(ch_short, ch) PLAYTEST_IM_THANKS_NUM(ch_short, ch, 0),PLAYTEST_IM_THANKS_NUM(ch_short, ch, 1),PLAYTEST_IM_THANKS_NUM(ch_short, ch, 2),PLAYTEST_IM_THANKS_NUM(ch_short, ch, 3),PLAYTEST_IM_THANKS_NUM(ch_short, ch, 4),PLAYTEST_IM_THANKS_GENERIC(ch),PLAYTEST_IM_THANKS_BUSY(ch)
#define PLAYTEST_IM_MESSAGE(ch_short, ch, num) CHOICE(#ch_short#num, [](){ playtest_im(ch, num); })
#define PLAYTEST_IM_ALL(ch_short, ch) PLAYTEST_IM_MESSAGE(ch_short,ch,0),PLAYTEST_IM_MESSAGE(ch_short,ch,1),PLAYTEST_IM_MESSAGE(ch_short,ch,2),PLAYTEST_IM_MESSAGE(ch_short,ch,3)
    void playtest() {
        BG_PLAIN
        auto options = vnlib::dense_MenuOptions();
        options.cols = 1;
        vnlib::menu({
            CHOICE("thanks", [](){
                BG_CODE
                auto o1 = vnlib::dense_MenuOptions();
                o1.cols = 7;
                o1.ani_x_inc = 30;
                vnlib::menu({
                    PLAYTEST_IM_THANKS(in, character::INO),
                    PLAYTEST_IM_THANKS(ka, character::KANADE),
                    PLAYTEST_IM_THANKS(rk, character::RIKA),
                    // PLAYTEST_IM_THANKS(rn, character::RIN),
                    CHOICE("back", [](){})
                }, &o1);
            }),
            CHOICE("im", [](){
                BG_DESKTOP_WITH_WIDGETS(false)
                auto o2 = vnlib::dense_MenuOptions();
                vnlib::menu({
                    PLAYTEST_IM_ALL(in, character::INO),
                    PLAYTEST_IM_ALL(ka, character::KANADE),
                    PLAYTEST_IM_ALL(rk, character::RIKA),
                    PLAYTEST_IM_ALL(rn, character::RIN),
                    CHOICE("back", [](){})
                }, &o2);
            }),
            CHOICE("back", [](){})
        }, &options);
    }
}