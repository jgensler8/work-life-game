\page initializer-list-notes Notes: Initializer List vs Vector

migrating back from `say(a1) say(a1,a2) ...` to `say(std::initializer_list<> a)`

command: `ls ./src | xargs -I {} basename {} '.cpp' | xargs -I {} ls -la "./build/{}.o"`

# before (overloaded w/ private _say(std::vector))

```
-rw-r--r-- 1 jgens jgens 72076 Jun 28 14:31 ./build/character.o
-rw-r--r-- 1 jgens jgens 429856 Jun 29 15:28 ./build/day.o
-rw-r--r-- 1 jgens jgens 404768 Jun 29 15:28 ./build/instant_message.o
-rw-r--r-- 1 jgens jgens 157164 Jun 29 15:28 ./build/main.o
-rw-r--r-- 1 jgens jgens 68760 Jun 29 15:29 ./build/main_character_state.o
-rw-r--r-- 1 jgens jgens 220304 Jun 29 15:29 ./build/minigame_bugs.o
-rw-r--r-- 1 jgens jgens 152816 Jun 29 15:29 ./build/minigame_calls.o
-rw-r--r-- 1 jgens jgens 339028 Jun 29 15:29 ./build/minigame_code.o
-rw-r--r-- 1 jgens jgens 310848 Jun 29 15:29 ./build/minigame_paperwork.o
-rw-r--r-- 1 jgens jgens 268444 Jun 29 15:29 ./build/save_state.o
-rw-r--r-- 1 jgens jgens 103984 Jun 29 15:29 ./build/state.o
-rw-r--r-- 1 jgens jgens 1209920 Jun 30 11:29 ./build/story.o
-rw-r--r-- 1 jgens jgens 4460 Jun 28 14:31 ./build/util.o
-rw-r--r-- 1 jgens jgens 505928 Jun 28 14:31 ./build/vnlib.o
-rw-r--r-- 1 jgens jgens 1160 Jun 28 14:31 ./build/vnlib_screen.o
-rw-r--r-- 1 jgens jgens 832332 Jun 30 11:46 ./build/weekend_event.o
```

# after (initializer_list for INO, KANADE, MC)

```
-rw-r--r-- 1 jgens jgens 72076 Jun 28 14:31 ./build/character.o
-rw-r--r-- 1 jgens jgens 429824 Jun 30 12:14 ./build/day.o
-rw-r--r-- 1 jgens jgens 323232 Jun 30 12:14 ./build/instant_message.o
-rw-r--r-- 1 jgens jgens 157164 Jun 30 12:14 ./build/main.o
-rw-r--r-- 1 jgens jgens 68760 Jun 29 15:29 ./build/main_character_state.o
-rw-r--r-- 1 jgens jgens 219548 Jun 30 12:14 ./build/minigame_bugs.o
-rw-r--r-- 1 jgens jgens 149352 Jun 30 12:14 ./build/minigame_calls.o
-rw-r--r-- 1 jgens jgens 306348 Jun 30 12:14 ./build/minigame_code.o
-rw-r--r-- 1 jgens jgens 261348 Jun 30 12:14 ./build/minigame_paperwork.o
-rw-r--r-- 1 jgens jgens 268444 Jun 30 12:14 ./build/save_state.o
-rw-r--r-- 1 jgens jgens 103984 Jun 30 12:14 ./build/state.o
-rw-r--r-- 1 jgens jgens 866384 Jun 30 12:14 ./build/story.o
-rw-r--r-- 1 jgens jgens 4460 Jun 28 14:31 ./build/util.o
-rw-r--r-- 1 jgens jgens 457416 Jun 30 12:20 ./build/vnlib.o
-rw-r--r-- 1 jgens jgens 1160 Jun 28 14:31 ./build/vnlib_screen.o
-rw-r--r-- 1 jgens jgens 626880 Jun 30 12:14 ./build/weekend_event.o
```

# after (initializer_list + menu vector)

```
-rw-r--r-- 1 jgens jgens 72076 Jun 28 14:31 ./build/character.o
-rw-r--r-- 1 jgens jgens 480852 Jun 30 12:30 ./build/day.o
-rw-r--r-- 1 jgens jgens 365584 Jun 30 12:30 ./build/instant_message.o
-rw-r--r-- 1 jgens jgens 157768 Jun 30 12:30 ./build/main.o
-rw-r--r-- 1 jgens jgens 68760 Jun 29 15:29 ./build/main_character_state.o
-rw-r--r-- 1 jgens jgens 219492 Jun 30 12:30 ./build/minigame_bugs.o
-rw-r--r-- 1 jgens jgens 143752 Jun 30 12:30 ./build/minigame_calls.o
-rw-r--r-- 1 jgens jgens 346316 Jun 30 12:30 ./build/minigame_code.o
-rw-r--r-- 1 jgens jgens 302764 Jun 30 12:30 ./build/minigame_paperwork.o
-rw-r--r-- 1 jgens jgens 268444 Jun 30 12:30 ./build/save_state.o
-rw-r--r-- 1 jgens jgens 103984 Jun 30 12:30 ./build/state.o
-rw-r--r-- 1 jgens jgens 985516 Jun 30 12:30 ./build/story.o
-rw-r--r-- 1 jgens jgens 4460 Jun 28 14:31 ./build/util.o
-rw-r--r-- 1 jgens jgens 413984 Jun 30 12:30 ./build/vnlib.o
-rw-r--r-- 1 jgens jgens 1160 Jun 28 14:31 ./build/vnlib_screen.o
-rw-r--r-- 1 jgens jgens 695376 Jun 30 12:30 ./build/weekend_event.o
```

# after (initializer_list + menu initializer_list)

```
-rw-r--r-- 1 jgens jgens 72076 Jun 28 14:31 ./build/character.o
-rw-r--r-- 1 jgens jgens 430524 Jun 30 12:33 ./build/day.o
-rw-r--r-- 1 jgens jgens 315180 Jun 30 12:33 ./build/instant_message.o
-rw-r--r-- 1 jgens jgens 157768 Jun 30 12:33 ./build/main.o
-rw-r--r-- 1 jgens jgens 68760 Jun 29 15:29 ./build/main_character_state.o
-rw-r--r-- 1 jgens jgens 219492 Jun 30 12:33 ./build/minigame_bugs.o
-rw-r--r-- 1 jgens jgens 143752 Jun 30 12:33 ./build/minigame_calls.o
-rw-r--r-- 1 jgens jgens 306228 Jun 30 12:33 ./build/minigame_code.o
-rw-r--r-- 1 jgens jgens 258636 Jun 30 12:33 ./build/minigame_paperwork.o
-rw-r--r-- 1 jgens jgens 268444 Jun 30 12:33 ./build/save_state.o
-rw-r--r-- 1 jgens jgens 103984 Jun 30 12:33 ./build/state.o
-rw-r--r-- 1 jgens jgens 811008 Jun 30 12:34 ./build/story.o
-rw-r--r-- 1 jgens jgens 4460 Jun 28 14:31 ./build/util.o
-rw-r--r-- 1 jgens jgens 393196 Jun 30 12:35 ./build/vnlib.o
-rw-r--r-- 1 jgens jgens 1160 Jun 28 14:31 ./build/vnlib_screen.o
-rw-r--r-- 1 jgens jgens 571768 Jun 30 12:34 ./build/weekend_event.o
```