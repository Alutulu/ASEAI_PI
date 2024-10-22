#ifndef MY_GPIO_HEADER
#define MY_GPIO_HEADER

/* constants */
#define ROOT_PWM_DEVICES "/sys/class/pwm"
#define PWM_EXPORT "export"
#define PWMUNEXPORT "unexport"
#define PWM_DIRECTION "direction"
#define VALUE "value"
#define OUT 0
#define IN 1
#define STR_LEN 256
#define STR_IN "in"
#define STR_OUT "out"

// Specific to my raspberry pi :
#define START_PIN 512

/*declarations*/
extern int GPIOInit(int);        // init a GPIO pin using the corresponding export file
extern int GPIODeInit(int);      // deinitialize a GPIO pin using the corresponding file
extern int GPIOSetDir(int, int); // set data direction (0 --> out, 1 --> in)
extern int GPIOWrite(int, int);  // write a value (0 or 1) to a GPIO pin
extern int GPIORead(int);        // read a value (0 or 1) from a GPIO pin

#endif