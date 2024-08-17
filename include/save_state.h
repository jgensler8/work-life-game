#pragma once
#include "bn_sram.h"
#include "day.h"

/*! \brief save state cover how SRAM is mapped
 *
 * it handles saving/loading the (singular) global game state and a particular save slot
 */
namespace save_state {
    //! \brief SaveState holds 3 game states
    struct SaveState {
    public:
        //! \brief array of contiguous game states
        state::GameState states[3];
        //! \brief read SaveState from SRAM
        void read() {
            bn::sram::read(*this);
        }
        //! \brief write this SaveState to SRAM
        void write() {
            bn::sram::write(*this);
        }
    };
    //! \brief singular global SaveSate
    extern SaveState save;

    //! \brief read SRAM and load into save_state::save
    void read_all_saves();
    //! \brief load a particular game state (state::GameState) from save_state::save (SaveState::states) into the global game state (state::st)
    void save_slot_selected(int slot);
    //! \brief write the global game state (state::st) into a particular save slot (save_state::save 's SaveState::states)
    void write_to_slot(int slot);
    //! \brief paint a save slot on the save screen
    void render_save_slot(int slot, bn::fixed x, bn::fixed y, bn::sprite_text_generator gen, bn::vector<bn::sprite_ptr, 96>* sprites);
}