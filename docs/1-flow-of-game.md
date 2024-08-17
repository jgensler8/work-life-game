\page flow-of-the-game Design: Flow of the Game

# Flow of the Game

* Core gameplay loop takes place on a week-by-week basis. If no failure routes are taken, there are an infinite number of weeks.
* Usually, there will be some generic Story progression that takes place in the morning.
* After an optional Story you will have to complete a Work task. This is the only point where the player is allowed to save.
* Following the completion of a Work task, you have the option of a Work Life task. This can be skipped.
* Weekends are for Weekend Events and Weekend Emergency Events. More information below.
* There are bad endings which will result in your employment termination (or by quitting). The good endings will let you continue working.

| Day | Pre-Morning | Morning | Afternoon |
| --- | --- | --- | --- |
| Monday | Story | Work | Work Life |
| Tuesday | Story | Work | Work Life |
| Wednesday | Story | Work | Work Life |
| Thursday | Story | Work | Work Life |
| Friday | Story | Work | Work Life |
| Saturday | n/a | Weekend Event | **Weekend Emergency |
| Saturday | n/a | n/a | **Weekend Emergency |

\remark **: Weekend Emergencies can happen on either Saturday or Sunday. This behavior can be toggled at runtime. see runtime_state::emergency_day

# Work {#work}

| Team | Character | Theoretical Task | Skill | Code | **Hint Mode |
| --- | --- | --- | --- | --- | --- |
| Programming | Ino | writing code | math | \ref minigame_code | highlight the menu item |
| Paperwork | Kanade | filling in paperwork values | english | \ref minigame_paperwork | highlight the menu item |
| Sales | Rika | making calls with customers | memory | \ref minigame_calls | autocomplete all but last letter |
| Security | Rin | "squashing" bugs | directional input | \ref minigame_bugs | autocomplete all but last action |

* Work tasks consist of a mini-game to pass the time.
* Successful completion of a mini-game will incrase relationship value with the respective character
* Bonus relationship points earned on days when respective team member is instant_message::ONLINE or instant_message::BUSY.
* Not all tasks are unlocked at the beginning of the game. The player must agree to help the team during various story events. see \ref story_unlocks

\remark **: tired of the mini-games? try toggling the options while playing!
\remark Here are the options:
\remark DEFAULT: play the game with no help (see runtime_state::minigame_mode::PLAY)
\remark HINT: play game with most of the work completed (see runtime_state::minigame_mode::HINT)
\remark AUTOWIN: do not play at all, win (see runtime_state::minigame_mode::AUTOWIN)
\remark .
\remark also see runtime_state::minigame_mode


# Work Life {#work-life}

| Task | Code |
| --- | --- |
| Instant Message | see instant_message |
| Skip | n/a |

* Shorter side stories to learn more about characters.
* Might influence confession but mostly standalone.

# Story {#story}

see ::story

Main story that will not modify relationships:
* unlocking department work ( see \ref story_unlocks )
* progress checkpoints ( see \ref story_progress_checkpoints )
* adding work to backlog
* "random event" episodes (see \ref story_episodes )

# Weekend Event {#weekend-event}

| Character | Events |
| --- | --- |
| Ino | \ref weekend_event::WEEKEND_INO |
| Kanade | \ref weekend_event::WEEKEND_KANADE |
| Rika | \ref weekend_event::WEEKEND_RIKA |
| Rin | \ref weekend_event::WEEKEND_RIN |

* 1:1 event with team members.
* launched when relationship is high enough (see \ref 
weekend_event::WEEKEND_REL_PROGRESS_MULTIPLIER )
* will be the highest possible character past threshold
* if completed, will result in large relationship gain (however, a conflicting Weekend Emergency might result in a large relationship loss)

# Weekend Emergency (Emergency Event) {#weekend-emergency}

| Character | Prompts | Events |
| --- | --- | --- |
| Ino | \ref weekend_event::EMERGENCY_PROMPT_INO | \ref weekend_event::EMERGENCY_STORY_INO |
| Kanade | \ref weekend_event::EMERGENCY_PROMPT_KANADE | \ref weekend_event::EMERGENCY_STORY_KANADE |
| Rika | \ref weekend_event::EMERGENCY_PROMPT_RIKA | \ref weekend_event::EMERGENCY_STORY_RIKA |
| Rin | \ref weekend_event::EMERGENCY_PROMPT_RIN | \ref weekend_event::EMERGENCY_STORY_RIN |

\remark Weekend Emergencies can be toggled between Saturday and Sunday. see runtime_state::emergency_day

* triggered during a weekend event
* triggered highest non-current character
* if ignored, will result in large relationship loss
* if accepted, will result in large relationship loss of original weekend event character and large relationship gain of emergency character

also see: weekend_event::handled_event , weekend_event::handle_emergency