#pragma once
#include "../cmsis_t113s3.h"

#ifdef __cplusplus
extern "C" {
#endif

void hal_timer0_init(TIMER_TypeDef* timer, float frequency);

void hal_timer0_interrupt_enable(TIMER_TypeDef* timer);

void hal_timer1_interrupt_enable(TIMER_TypeDef* timer);

void hal_timer0_interrupt_clear(TIMER_TypeDef* timer);

void hal_timer1_interrupt_clear(TIMER_TypeDef* timer);

#ifdef __cplusplus
}
#endif