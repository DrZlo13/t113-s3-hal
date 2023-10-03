#include "timer.h"

void hal_timer0_init(TIMER_TypeDef* timer, float frequency) {
    uint32_t reload = 24000000.0f / frequency;

    // 24Mhz clock
    timer->TMR0_CTRL_REG |= (0b01 << 2);

    // prescaler 0
    timer->TMR0_CTRL_REG |= (0b000 << 4);

    // period mode
    timer->TMR0_CTRL_REG |= (0b0 << 7);

    // set reload value
    timer->TMR0_INTV_VALUE_REG = reload;

    // load reload value
    timer->TMR0_CTRL_REG |= (0b1 << 1);

    // wait for timer to load
    while((timer->TMR0_CTRL_REG & (0b1 << 1)) != 0)
        ;

    // enable timer
    timer->TMR0_CTRL_REG |= (0b1 << 0);
}

void hal_timer0_interrupt_enable(TIMER_TypeDef* timer) {
    // enable interrupt
    timer->TMR_IRQ_EN_REG |= (0b1 << 0);
}

void hal_timer1_interrupt_enable(TIMER_TypeDef* timer) {
    // enable interrupt
    timer->TMR_IRQ_EN_REG |= (0b1 << 1);
}

void hal_timer0_interrupt_clear(TIMER_TypeDef* timer) {
    // clear interrupt
    timer->TMR_IRQ_STA_REG |= (0b1 << 0);
}

void hal_timer1_interrupt_clear(TIMER_TypeDef* timer) {
    // clear interrupt
    timer->TMR_IRQ_STA_REG |= (0b1 << 1);
}