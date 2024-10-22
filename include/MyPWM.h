#ifndef MY_GPIO_HEADER
#define MY_GPIO_HEADER

/* constants */
#define ROOT_PWM_DEVICES "/sys/class/pwm/pwmchip0"
#define PWM_EXPORT "export"
#define PWM_UNEXPORT "unexport"
#define PWM_ENABLE "enable"
#define PWM_PERIOD "period"
#define PWM_DUTY_CYCLE "duty_cycle"
#define STR_LEN 256

// Specific to my raspberry pi :
#define START_PIN 0

/*declarations*/
extern int PWMInit(int);              // init a GPIO pin using the corresponding export file
extern int PWMDeInit(int);            // deinitialize a GPIO pin using the corresponding file
extern int PWMSetEnable(int);         // set data direction (0 --> out, 1 --> in)
extern int PWMSetPeriod(int, int);    // set data direction (0 --> out, 1 --> in)
extern int PWMSetDutyCycle(int, int); // set data direction (0 --> out, 1 --> in)

#endif