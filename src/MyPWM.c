//
// Created by arthur on 10/15/24.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "MyPWM.h"

#define START_PIN 0 // 512 pour les nouveaux PI OS

extern char *strerror(int);

/*&&&&&&&&&&&&&&&&&&&&*/
/*init a GPIO pin without settings the data direction*/
/*&&&&&&&&&&&&&&&&&&&&*/
int PWMInit(int iPWMNumber)
{
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_PWM_DEVICES, PWM_EXPORT);
        /* try to open the file*/
        if ((fout = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : PWMnit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        /* write the GPIO number in the export file */
        fprintf(fout, "%d", START_PIN + iPWMNumber);
        fclose(fout);
        /* ok*/
        return 0;
}

/*&&&&&&&&&&&&&&&&&&&&*/
/*Deinit a GPIO pin without settings the data direction*/
/*&&&&&&&&&&&&&&&&&&&&*/
int PWMDeInit(int iPWMNumber)
{
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_PWM_DEVICES, PWM_UNEXPORT);
        /* try to open the file*/
        if ((fout = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : PWMDeInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        /* write the GPIO number in the export file */
        fprintf(fout, "%d", START_PIN + iPWMNumber);
        fclose(fout);
        /* ok*/
        return 0;
}

/*&&&&&&&&&&&&&&&&&&*/
/* set the data direction for a given GPIO number*/
/*&&&&&&&&&&&&&&&&&&*/
int PWMSetEnable(int iPWMNumber)
{
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* build the path to the file*/
        sprintf(szAccessPath, "%s/pwm%d/%s", ROOT_PWM_DEVICES, START_PIN + iPWMNumber, PWM_ENABLE);
        if ((fOut = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : PWMSetEnable() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        fprintf(fOut, "1");
        fclose(fOut);
        /* ok*/
        return 0;
}

int PWMSetPeriod(int iPWMNumber, int iPeriod)
{
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* build the path to the file*/
        sprintf(szAccessPath, "%s/pwm%d/%s", ROOT_PWM_DEVICES, START_PIN + iPWMNumber, PWM_PERIOD);
        if ((fOut = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : PWMSetPeriod() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        fprintf(fOut, "%d", iPeriod);
        fclose(fOut);
        /* ok*/
        return 0;
}

int PWMSetDutyCycle(int iPWMNumber, int iCycle)
{
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* build the path to the file*/
        sprintf(szAccessPath, "%s/pwm%d/%s", ROOT_PWM_DEVICES, START_PIN + iPWMNumber, PWM_DUTY_CYCLE);
        if ((fOut = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : PWMSetDutyCycle() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        fprintf(fOut, "%d", iCycle);
        fclose(fOut);
        /* ok*/
        return 0;
}

int main(void)
{
        // Ecriture
        printf("compilé\n");
        PWMInit(0);
        printf("Port ok\n");
        PWMSetEnable(0);
        printf("Enable fait\n");
        PWMSetPeriod(0, 1000000);
        printf("Periode mise\n");
        PWMSetDutyCycle(0, 500000);
        printf("Duty cycle mis\n");
        // GPIODeInit(0);

        return 0;
}