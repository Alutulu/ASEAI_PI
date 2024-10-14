#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "MyGPIO.h"

int main(void) {
    printf("Hello from the motor.c\n");
    GPIOInit(12);
    GPIOSetDir(12, 0);
    GPIOWrite(12, 1);
    return 0;
}