#include "pwm.h"

// Configuring Clock
// Step 1 PWM gating: When using PWM, write 1 to PCGR[PWMx_CLK_GATING].
// Step 2 PWM clock source select: Set PCCR01[PWM01_CLK_SRC] to select HOSC or APB0 clock.
// Step 3 PWM clock divider: Set PCCR01[PWM01_CLK_DIV_M] to select different frequency division
// coefficient (1/2/4/8/16/32/64/128/256).
// Step 4 PWM clock bypass: Set PCGR[PWM_CLK_SRC_BYPASS_TO_PWM] to 1, output the PWM clock after
// the secondary frequency division to the corresponding PWM output pin.
// Step 5 PWM internal clock configuration: Set PCR[PWM_PRESCAL_K] to select any frequency division
// coefficient from 1 to 256.

#define PWM_CLK_GATING_OFFSET (0)

void hal_pwm_clock(size_t pwm, PWMClockDiv div, PWMClockSource src, uint8_t prescaler) {
    //assert(pwm < 8);
    size_t pwm_pair = pwm / 2;

    // Enable PWM gating
    SET_BIT(PWM->PCGR, PWM_CLK_GATING_OFFSET + pwm);

    // Set PWM clock source
    PWM->PCCR[pwm_pair] |= ((src & 0b11) << 7);

    // Set PWM clock divider
    PWM->PCCR[pwm_pair] |= ((div & 0b1111) << 0);

    // Set PWM clock prescaler
    PWM->CH[pwm].PCR |= prescaler << 0;
}

// Configuring PWM
// Step 1 PWM mode: Set PCR[PWM_MODE] to select cycle mode or pulse mode, if pulse mode,
// PCR[PWM_PUL_NUM] needs to be configured.
// Step 2 PWM active level: Set PCR[PWM_ACT_STA] to select a low level or high level.
// Step 3 PWM duty-cycle: Configure PPR[PWM_ENTIRE_CYCLE] and PPR[PWM_ACT_CYCLE] after clock gating
// is opened.
// Step 4 PWM starting/stoping phase: Configure PCNTR[PWM_COUNTER_START] after the clock gating is
// enabled and before the PWM is enabled. You can verify whether the configuration was successful by
// reading back PCNTR[PWM_COUNTER_STATUS].
// Step 5 Enable PWM: Configure PER to select the corresponding PWM enable bit; when selecting pulse mode,
// PCR[PWM_PUL_START] needs to be enabled.

void hal_pwm_mode(size_t pwm, PWMMode mode, PWMActive active) {
    //assert(pwm < 8);
    PWM->CH[pwm].PCR |= ((mode & 0b1) << 9);
    PWM->CH[pwm].PCR |= ((active & 0b1) << 8);
}

void hal_pwm_period(size_t pwm, uint16_t period) {
    //assert(pwm < 8);
    while((PWM->CH[pwm].PCR & (1 << 11)) != 0) {
        // Wait for PWM Period Register Ready
    }
    PWM->CH[pwm].PPR = (PWM->CH[pwm].PPR & 0x0000FFFF) | ((period & 0xFFFF) << 16);
}

void hal_pwm_duty(size_t pwm, uint16_t duty) {
    //assert(pwm < 8);
    while((PWM->CH[pwm].PCR & (1 << 11)) != 0) {
        // Wait for PWM Period Register Ready
    }
    PWM->CH[pwm].PPR = (PWM->CH[pwm].PPR & 0xFFFF0000) | (duty & 0xFFFF);
}

void hal_pwm_counter(size_t pwm, uint16_t counter) {
    //assert(pwm < 8);
    PWM->CH[pwm].PCNTR = (counter & 0xFFFF) << 16;
}

uint16_t hal_pwm_counter_get(size_t pwm) {
    return (PWM->CH[pwm].PCNTR) & 0xFFFF;
}

void hal_pwm_enable(size_t pwm) {
    //assert(pwm < 8);
    PWM->PER |= 1 << pwm;
}

void hal_pwm_disable(size_t pwm) {
    //assert(pwm < 8);
    PWM->PER &= ~(1 << pwm);
}