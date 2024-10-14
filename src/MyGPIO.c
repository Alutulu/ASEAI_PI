#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

extern char *strerror(int);

/* constants */
#define ROOT_GPIO_DEVICES       "/sys/class/gpio"
#define EXPORT                  "export"
#define UNEXPORT                "unexport"
#define DIRECTION               "direction"
#define VALUE                   "value"
#define OUT                     0
#define IN                      1
#define STR_LEN                 256
#define STR_IN                  "in"
#define STR_OUT                  "out"

// Specific to my raspberry pi :
#define START_PIN               512

/*declarations*/
int GPIOInit(int); // init a GPIO pin using the corresponding export file
int GPIODeInit(int); // deinitialize a GPIO pin using the corresponding file
int GPIOSetDir(int, int); // set data direction (0 --> out, 1 --> in)
int GPIOWrite(int, int); // write a value (0 or 1) to a GPIO pin
int GPIORead(int); // read a value (0 or 1) from a GPIO pin

/*&&&&&&&&&&&&&&&&&&&&*/
/*init a GPIO pin without settings the data direction*/
/*&&&&&&&&&&&&&&&&&&&&*/
int GPIOInit(int iGPIONumber){
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_GPIO_DEVICES, EXPORT);
        /* try to open the file*/
        if((fout=fopen(szAccessPath, "w"))==NULL){
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return( -errno);
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
int GPIODeInit(int iGPIONumber){
        char szAccessPath[STR_LEN];
        FILE *fout;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/%s", ROOT_GPIO_DEVICES, UNEXPORT);
        /* try to open the file*/
        if((fout=fopen(szAccessPath, "w"))==NULL){
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return( -errno);
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
int GPIOSetDir(int iGPIONumber, int iDatDirection){
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%03d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, DIRECTION);
        // try to open the data ddirection file
        if((fOut=fopen(szAccessPath, "w"))==NULL){
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return( -errno);
        }
        switch (iDatDirection){
                case IN :
                        fprintf(fOut,"%s",(char *)(STR_IN));
                        break;
                case OUT :
                        fprintf(fOut,"%s",(char *)(STR_OUT));
                        break;
                default :
                        fclose(fOut);
                        return -1;
                        break;
        }
        fclose(fOut);
        /* ok*/
        return 0;
}

int GPIOWrite(int iGPIONumber, int value){
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%03d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, VALUE);
        // try to open the data direction file
        if((fOut=fopen(szAccessPath, "w"))==NULL){
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return( -errno);
        }
        printf("valeur ecrite : %d\n", value);
        fprintf(fOut,"%d",value);
        fclose(fOut);
        /* ok*/
        return 0;
}

int GPIORead(int iGPIONumber){
        int value;
        char szAccessPath[STR_LEN];
        FILE *fOut;
        /* builde the path to the file*/
        sprintf(szAccessPath, "%s/gpio%03d/%s", ROOT_GPIO_DEVICES, START_PIN + iGPIONumber, VALUE);
        // try to open the data direction file
        if((fOut=fopen(szAccessPath, "r"))==NULL){
                fprintf(stderr, "ERROR : GPIOInit() --> call to fopen(%s, ..)\n", szAccessPath);
                fprintf(stderr, "    error code %d (%s)\n", errno, (char *)(strerror(errno)));
                return( -errno);
        }
        fscanf(fOut, "%d", &value);
        printf("valeur lue : %d\n", value);
        fclose(fOut);
        /* ok*/
        return 0;
}

int main(void){
    // Ecriture
    printf("compilé\n");
    GPIOInit(17);
    printf("Port ok\n");
    GPIOSetDir(17, 0);
    printf("Direction mise\n");
    GPIOWrite(17, 0);
    printf("C'est ecrit !!!\n");
    // GPIOSetDir(17, 0);
    // printf("Direction mise\n");
    // GPIORead(17);
    GPIODeInit(17);
    

    return 0;
}