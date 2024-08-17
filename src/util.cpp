#include "util.h"
namespace util {
    int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }
    int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
    int clamp(int a, int low, int high) {
        return max(min(a, high), low);
    }
}