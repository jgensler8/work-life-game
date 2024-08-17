#include "save_state.h"

namespace save_state {
    SaveState save;

    void read_all_saves() {
        save.read();
    }

    void save_slot_selected(int slot) {
        state::st = save.states[slot];
        state::st.initialize();
        vnlib::next(day::day_starting);
    }

    void write_to_slot(int slot) {
        state::st.initialize();
        save.states[slot] = state::st;
        save.write();
    }

    void render_save_slot(int slot, bn::fixed x, bn::fixed y, bn::sprite_text_generator gen, bn::vector<bn::sprite_ptr, 96>* sprites) {
        // read save slot to temp
        state::GameState t = save.states[slot];
        if(!t.is_initialized()) {
            auto empty = gen.generate<32>(x, y, "<empty>");
            for(auto s : empty) { sprites->push_back(s); }
            return;
        }
        // render slot
        auto ns = gen.generate<32>(x, y, bn::format<64>("{} {} w:{} d:{}", t.mc_name, t.short_day_name(), t.week(), t.day + 1));
        for(auto s : ns) { sprites->push_back(s); }
        ns = gen.generate<32>(x, y+10, FMT_24("in:{} ka:{}",
            t.rel_state.rels[character::INO],
            t.rel_state.rels[character::KANADE]
        ));
        for(auto s : ns) { sprites->push_back(s); }
        ns = gen.generate<32>(x, y+20, FMT_24("rk:{} rn:{}",
            t.rel_state.rels[character::RIKA],
            t.rel_state.rels[character::RIN]
        ));
        for(auto s : ns) { sprites->push_back(s); }
    }
}