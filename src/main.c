#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyGPIO.h"
#include "MyPWM.h"

int main(int argc, char *argv[])
{
    // Ecriture
    printf("compilé\n");
    GPIOInit(18);
    printf("Port ok\n");
    GPIOSetDir(18, 0);
    printf("Direction mise\n");
    GPIOWrite(18, 1);
    printf("C'est ecrit !!!\n");
    // GPIODeInit(17);
}