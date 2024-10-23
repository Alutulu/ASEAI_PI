#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyGPIO.h"
#include "MyPWM.h"

int main(int argc, char *argv[])
{

    printf("compilé : %d arguments\n", argc);

    int c = atoi(argv[1]) + atoi(argv[2]);
    printf("addition: %d\n", c);

    GPIOInit(18);
    // printf("Port ok\n");
    // GPIOSetDir(18, 0);
    // printf("Direction mise\n");
    // GPIOWrite(18, 1);
    // printf("C'est ecrit !!!\n");
    // GPIODeInit(17);

    PWMInit(0);
    printf("Port ok\n");
    PWMSetPeriod(0, 1000000);
    printf("Periode mise\n");
    PWMSetDutyCycle(0, 500000);
    printf("Duty cycle mis\n");
    PWMSetEnable(0);
    printf("Enable fait\n");
    // GPIODeInit(0);

    return 0;
}