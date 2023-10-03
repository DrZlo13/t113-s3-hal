#pragma once
#include "../std/common.h"
#include "../cmsis_t113s3.h"

typedef enum {
    PWMClockDiv1 = 0b0000,
    PWMClockDiv2 = 0b0001,
    PWMClockDiv4 = 0b0010,
    PWMClockDiv8 = 0b0011,
    PWMClockDiv16 = 0b0100,
    PWMClockDiv32 = 0b0101,
    PWMClockDiv64 = 0b0110,
    PWMClockDiv128 = 0b0111,
    PWMClockDiv256 = 0b1000,
} PWMClockDiv;

typedef enum {
    PWMClockSourceHOSC = 0b00,
    PWMClockSourceAPB0 = 0b01,
} PWMClockSource;

typedef enum {
    PWMModeCycle = 0b0,
    PWMModePulse = 0b1,
} PWMMode;

typedef enum {
    PWMActiveLow = 0b0,
    PWMActiveHigh = 0b1,
} PWMActive;

void hal_pwm_clock(size_t pwm, PWMClockDiv div, PWMClockSource src, uint8_t prescaler);

void hal_pwm_mode(size_t pwm, PWMMode mode, PWMActive active);

void hal_pwm_period(size_t pwm, uint16_t period);

void hal_pwm_duty(size_t pwm, uint16_t duty);

void hal_pwm_counter(size_t pwm, uint16_t counter);

uint16_t hal_pwm_counter_get(size_t pwm);

void hal_pwm_enable(size_t pwm);

void hal_pwm_disable(size_t pwm);