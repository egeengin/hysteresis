#include <printf.h>
#include "hysteresis.h"

#define HYSTERESIS_REGION_NO   4

typedef struct threshold {
    unsigned int low;
    unsigned int high;
    unsigned int level;
} threshold;

const threshold thresholds[HYSTERESIS_REGION_NO] = {
        {.low = 10, .high = 15, .level = 1},
        {.low = 35, .high = 40, .level = 2},
        {.low = 60, .high = 65, .level = 3},
        {.low = 85, .high = 90, .level = 4},
};

unsigned int hysteresis(unsigned int analogueInput) {
    static unsigned int discreteLevel = 0;
    static unsigned int lastAnalogueInput = 0;

    if (analogueInput > 100) {
        printf("Wrong Input: Last discrete level is returned.\n");
        return discreteLevel;
    }
    
    if (analogueInput >= lastAnalogueInput) {
        for (int i = HYSTERESIS_REGION_NO - 1; i >= 0; i--) {
            if (analogueInput >= thresholds[i].high) {
                discreteLevel = thresholds[i].level;
                break;
            }
        }
    } else {
        for (int i = HYSTERESIS_REGION_NO - 1; i >= 0; i--) {
            if (analogueInput <= thresholds[HYSTERESIS_REGION_NO - 1 - i].low) {
                discreteLevel = thresholds[HYSTERESIS_REGION_NO - 1 - i].level - 1;
                break;
            }
        }
    }

    lastAnalogueInput = analogueInput;
    return discreteLevel;
}
