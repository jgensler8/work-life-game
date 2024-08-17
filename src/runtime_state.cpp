#include "runtime_state.h"

namespace runtime_state {
    void toggle(bool* option) {
        (*option) = !(*option);
    }
    void toggle(minigame_mode* option) {
        switch(*option){
        case PLAY: *option = HINT; break;
        case HINT: *option = AUTOWIN; break;
        case AUTOWIN: *option = PLAY; break;
        default: break;
        }
    }
    void toggle(emergency_day* option) {
        switch(*option){
        case EMERGENCIES_ON_SATURDAY: *option = EMERGENCIES_ON_SUNDAY; break;
        case EMERGENCIES_ON_SUNDAY: *option = EMERGENCIES_ON_SATURDAY; break;
        default: break;
        }
    }
    bn::string<8> to_str(minigame_mode option) {
        switch(option) {
        case PLAY: return "DEFAULT";
        case HINT: return "HINT";
        case AUTOWIN: return "AUTOWIN";
        default: return "?";
        }
    }
    bn::string<8> to_str(emergency_day option) {
        switch(option) {
        case EMERGENCIES_ON_SATURDAY: return "Saturday";
        case EMERGENCIES_ON_SUNDAY: return "Sunday";
        default: return "?";
        }
    }
}