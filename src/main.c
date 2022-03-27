#include <stdio.h>
#include "hysteresis.h"

#define say_bye() do {printf("\nThank you.\n"); } while(0)
static volatile int keepRunning = 1;

int main(void) {
    unsigned int discreteLevel, analogueInput;

    printf("Welcome\n");
    while (keepRunning) {
        printf("Please enter an analogue input or Ctrl + D to exit: ");
        if (scanf("%d", &analogueInput) < 1) {
            say_bye();
            return 0;
        }

        discreteLevel = hysteresis(analogueInput);
        printf("Discrete Level : %d\n", discreteLevel);
    }
    return 0;
}