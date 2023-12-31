#pragma once
#include "../std/common.h"
#include "../cmsis_t113s3.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ClockSystemUart0,
    ClockSystemUart1,
    ClockSystemUart2,
    ClockSystemUart3,
    ClockSystemUart4,
    ClockSystemUart5,
    ClockSystemPWM,
} ClockSystem;

void hal_clock_enable(ClockSystem target);

#ifdef __cplusplus
}
#endif
