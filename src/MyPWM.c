//
// Created by arthur on 10/15/24.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "MyGPIO.h"

#define START_PIN 0 // 512 pour les nouveaux PI OS

extern char *strerror(int);

/*&&&&&&&&&&&&&&&&&&&&*/
/*init a GPIO pin without settings the data direction*/
/*&&&&&&&&&&&&&&&&&&&&*/
int GPIOInit(int iGPIONumber)
{
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_GPIO_DEVICES, EXPORT);
        /* try to open the file*/
        if ((fout = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        /* write the GPIO number in the export file */
        fprintf(fout, "%d", START_PIN + iGPIONumber);
        fclose(fout);
        /* ok*/
        return 0;
}

/*&&&&&&&&&&&&&&&&&&&&*/
/*Deinit a GPIO pin without settings the data direction*/
/*&&&&&&&&&&&&&&&&&&&&*/
int GPIODeInit(int iGPIONumber)
{
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_GPIO_DEVICES, UNEXPORT);
        /* try to open the file*/
        if ((fout = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        /* write the GPIO number in the export file */
        fprintf(fout, "%d", START_PIN + iGPIONumber);
        fclose(fout);
        /* ok*/
        return 0;
}

/*&&&&&&&&&&&&&&&&&&*/
/* set the data direction for a given GPIO number*/
/*&&&&&&&&&&&&&&&&&&*/
int GPIOSetDir(int iGPIONumber, int iDatDirection)
{
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%02d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, DIRECTION);
        // try to open the data ddirection file
        if ((fOut = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        switch (iDatDirection)
        {
        case IN:
                fprintf(fOut, "%s", (char *)(STR_IN));
                break;
        case OUT:
                fprintf(fOut, "%s", (char *)(STR_OUT));
                break;
        default:
                fclose(fOut);
                return -1;
                break;
        }
        fclose(fOut);
        /* ok*/
        return 0;
}

int GPIOWrite(int iGPIONumber, int value)
{
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%02d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, VALUE);
        // try to open the data direction file
        if ((fOut = fopen(szAccessPath, "w")) == NULL)
        {
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        printf("valeur ecrite : %d\n", value);
        fprintf(fOut, "%d", value);
        fclose(fOut);
        /* ok*/
        return 0;
}

int GPIORead(int iGPIONumber)
{
        int value;
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%02d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, VALUE);
        // try to open the data direction file
        if ((fOut = fopen(szAccessPath, "r")) == NULL)
        {
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return (-errno);
        }
        fscanf(fOut, "%d", &value);
        printf("valeur lue : %d\n", value);
        fclose(fOut);
        /* ok*/
        return 0;
}
