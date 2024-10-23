# ASEAI_PI
UV ASEAI à l'IMT NORD EUROPE

## Motor control
- **GPIO** : motor is turning or not
- **PWM** : pulse width modulation (`sys/class/pwm`)

## Compiler avec CMake
mkdir build && cd build
cmake ..
cmake --build .
sudo ./ASEAI_PI

## Signaux

List of the known signals : `kill -L`

## PWM

Dans `/boot/config.txt`, ajouter : `dtoverlay=pwm,pin=12,func=0`.
Puis faire `echo 0 > /sys/class/pwm/pwmchip0`.
Et un dossier `/sys/class/pwm/pwmchip0/pwm0` apparaît !
Puis echo dans `enable`, `period` et `duty_cycle`

Overlays data :
- PWM0 : GPIO 12, func 4
- PWM0 : GPIO 18, func 2
- PWM1 : GPIO 13 func 4
- PWM1 : GPIO 19, func 2

## Camera

### Installation
- In "Preferences", check that **SPI** is enable.
- `libcamera-hello`