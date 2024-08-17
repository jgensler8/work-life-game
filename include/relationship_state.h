#pragma once
#include "character.h"

//! \brief state encapslated relationship state and its operations
namespace relationship_state {
    //! \brief the maximum points a relationship can have
    constexpr int REL_MAX = 36;
    //! \brief the starting point of a relationship
    constexpr int REL_INIT = 0;
    //! \brief possible amounts to increase/decrease by
    enum RELATION_INC_AMT {
        //! \brief used during weekend_event
        REALLY_BAD = -5,
        //! \brief TODO unused
        BAD = -1,
        //! \brief TODO unused
        NONE = 0,
        //! \brief using at various points (various minigames, instant_message)
        GOOD = 1,
        //! \brief TODO unused
        GREAT = 2,
        //! \brief used during weekend_event
        REALLY_GOOD = 5
    };
    //! \brief the relationship state struct
    struct relationship_state {
        //! \brief relationship values of various characters. value between [0, REL_MAX]
        int rels[character::COUNT];
        //! \brief update the relation by a fixed amount
        void modify_relation(character::CHAR_ENUM c, RELATION_INC_AMT amt) {
            this->rels[c] = util::clamp(this->rels[c] + amt, 0, REL_MAX);
        }
        //! \brief initialize the struct
        void init() {
            for(auto c : character::characters) {
                reset(c);
            }
        }
        //! \brief used in SaveScreen rendering and viewing in the Morning
        bn::string<8> fmt(character::CHAR_ENUM c) {
            return FMT_8("{}/{}", this->rels[c], REL_MAX);
        }
        //! \brief used in extreme story events
        void reset(character::CHAR_ENUM c) {
            rels[c] = REL_INIT;
        }
        //! \brief used in weekend_event and during weekend emergencies
        bn::array<character::CHAR_ENUM, character::COUNT> by_rel_desc(){
            int rels_cpy[character::COUNT];
            bn::array<character::CHAR_ENUM, character::COUNT> chars;
            for(auto c: character::characters) {
                rels_cpy[c] = rels[c];
                chars[c] = c;
            }
            // selection sort n^2
            for(int start = 0; start < character::COUNT-1; start += 1) {
                // find char index with max rel
                int max_idx = start;
                for(int s = start+1; s < character::COUNT; s += 1) {
                    if(rels_cpy[s] > rels_cpy[max_idx]) {
                        max_idx = s;
                    }
                }
                // swap max
                if (max_idx != start) {
                    int temp_r = rels_cpy[start];
                    character::CHAR_ENUM temp_c = chars[start];
                    rels_cpy[start] = rels_cpy[max_idx];
                    chars[start] = chars[max_idx];
                    rels_cpy[max_idx] = temp_r;
                    chars[max_idx] = temp_c;
                }
            }
            return chars;
        }
    };
}