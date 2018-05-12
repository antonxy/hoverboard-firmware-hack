#pragma once
#include "stm32f1xx_hal.h"

// ################################################################################

#define PWM_FREQ         16000      // PWM frequency in Hz
#define DEAD_TIME        32         // PWM deadtime

#define DC_CUR_LIMIT     15         // Motor DC current limit in amps

#define BAT_LOW_LVL1     36.0       // gently beeps at this voltage level
#define BAT_LOW_LVL2     33.0       // your battery is almost empty. Charge now!
#define BAT_LOW_DEAD     31.0       // undervoltage lockout

// ################################################################################

//#define DEBUG_SERIAL_USART2
#define DEBUG_SERIAL_USART3
#define DEBUG_BAUD       115200     // UART baud rate
//#define DEBUG_SERIAL_SERVOTERM
#define DEBUG_SERIAL_ASCII
//#define DEBUG_I2C_LCD

#define TIMEOUT          5           //number of wrong / missing commands before emergency off

// ################################################################################

// ###### CONTROL VIA RC REMOTE ######
//#define CONTROL_PPM                // use PPM CONTROL_PPM
//#define PPM_NUM_CHANNELS 6         // number of PPM channels to receive

// ###### CONTROL VIA TWO POTENTIOMETERS ######
#define CONTROL_ADC

// ###### CONTROL VIA NINTENDO NUNCHUCK ######
// #define CONTROL_NUNCHUCK

// ################################################################################

// ###### DRIVING BEHAVIOR ######
#define SPEED_UP_VALUE 100 //Speed up per button press

//Turno boost at high speeds while button1 is pressed:
//#define ADDITIONAL_CODE \
if (button1 && speed > 700) { /* field weakening at high speeds */ \
  weakl = cmd1 - 700; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = cmd1 - 700; } \
else { \
  weakl = 0; \
  weakr = 0; }

// ###### BOBBYCAR ######
// #define FILTER              0.1
// #define SPEED_COEFFICIENT   -1
// #define STEER_COEFFICIENT   0

// #define ADDITIONAL_CODE \
if (button1 && speedR < 300) { \
  speedR = speedR * -0.2f;   \
  speedL = speedL * -0.2f; } \
else { \
  direction = 1; } \
if (button1 && speedR > 700) { /* field weakening at high speeds */ \
  weakl = speedR - 600; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = speedR - 600; } \
else { \
  weakl = 0; \
  weakr = 0; }

// ###### ARMCHAIR ######
// #define FILTER              0.05
// #define SPEED_COEFFICIENT   0.5
// #define STEER_COEFFICIENT   -0.2

// #define ADDITIONAL_CODE if (button1 && scale > 0.8) { /* field weakening at high speeds */ \
  weakl = speedL - 600; /* weak should never exceed 400 or 450 MAX!! */ \
  weakr = speedR - 600; } \
else {\
  weakl = 0;\
  weakr = 0;

// #define BEEPS_BACKWARD
