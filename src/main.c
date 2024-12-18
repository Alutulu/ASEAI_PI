#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyGPIO.h"
#include "MyPWM.h"

#define PERIOD_PWM 1000000

int main(int argc, char *argv[])
{
    int velocity = atoi(argv[1]);
    int sens = atoi(argv[2]);
    GPIOInit(24);
    PWMInit(0);

    if (velocity == 0)
    {
        printf("Velocite a zero\n");

        PWMSetDisable(0);
        GPIOSetDir(24, 0);
        GPIOWrite(24, 0);
    }
    else
    {
        int duty_cycle = (PERIOD_PWM / 100) * velocity;
        printf("duty cycle %d period %d\n", duty_cycle, PERIOD_PWM);

        GPIOSetDir(24, 0);
        GPIOWrite(24, sens);

        PWMSetPeriod(0, PERIOD_PWM);
        PWMSetDutyCycle(0, duty_cycle);
        PWMSetEnable(0);
    }

    return 0;
}