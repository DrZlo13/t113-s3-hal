#include "pwm.h"
#include "regs/pwm.hpp"

#define PWM_CHANNEL_COUNT 8

// Configuring Clock
// Step 1 PWM gating: When using PWM, write 1 to PCGR[PWMx_CLK_GATING].
// Step 2 PWM clock source select: Set PCCR01[PWM01_CLK_SRC] to select HOSC or APB0 clock.
// Step 3 PWM clock divider: Set PCCR01[PWM01_CLK_DIV_M] to select different frequency division
// coefficient (1/2/4/8/16/32/64/128/256).
// Step 4 PWM clock bypass: Set PCGR[PWM_CLK_SRC_BYPASS_TO_PWM] to 1, output the PWM clock after
// the secondary frequency division to the corresponding PWM output pin.
// Step 5 PWM internal clock configuration: Set PCR[PWM_PRESCAL_K] to select any frequency division
// coefficient from 1 to 256.

API void hal_pwm_clock(size_t pwm, PWMClockDiv div, PWMClockSource src, uint8_t prescaler) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    size_t pwm_pair = pwm / 2;

    // Enable PWM gating
    pwm::pcgr::clk_gating::write(pwm, true);

    // Set PWM clock source
    pwm::pccr::clk_src::write(pwm_pair, src);

    // Set PWM clock divider
    pwm::pccr::clk_div_m::write(pwm_pair, div);

    // Set PWM clock prescaler
    pwm::pcr::prescal_k::write(pwm, prescaler);
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

API void hal_pwm_mode(size_t pwm, PWMMode mode, PWMActive active) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    pwm::pcr::mode::write(pwm, mode);
    pwm::pcr::act_sta::write(pwm, active);
}

API void hal_pwm_period(size_t pwm, uint16_t period) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    while(pwm::pcr::period_rdy::read(pwm) != 0) {
        // Wait for PWM Period Register Ready
    }
    pwm::ppr::entire_cycle::write(pwm, period);
}

API void hal_pwm_duty(size_t pwm, uint16_t duty) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    while(pwm::pcr::period_rdy::read(pwm) != 0) {
        // Wait for PWM Period Register Ready
    }
    pwm::ppr::act_cycle::write(pwm, duty);
}

API void hal_pwm_counter(size_t pwm, uint16_t counter) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    pwm::pcntr::counter_start::write(pwm, counter);
}

API uint16_t hal_pwm_counter_get(size_t pwm) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    return pwm::pcntr::counter_status::read(pwm);
}

API void hal_pwm_enable(size_t pwm) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    pwm::per::en::write(pwm, 1);
}

API void hal_pwm_disable(size_t pwm) {
    hal_assert(pwm < PWM_CHANNEL_COUNT);
    pwm::per::en::write(pwm, 0);
}