#include "../../cmsis_t113s3.h"
#include "../../std/register.hpp"

#define ADDR(base, type, member) ((base) + offsetof(type, member))

/* PWM peripheral */
namespace pwm {

// peripheral base addresses
#define PCGR_ADDR ADDR(PWM_BASE, PWM_TypeDef, PCGR)
#define PCCR_ADDR ADDR(PWM_BASE, PWM_TypeDef, PCCR)
#define PCR_ADDR ADDR(PWM_BASE, PWM_TypeDef, CH[0].PCR)
#define PPR_ADDR ADDR(PWM_BASE, PWM_TypeDef, CH[0].PPR)
#define PCNTR_ADDR ADDR(PWM_BASE, PWM_TypeDef, CH[0].PCNTR)
#define PER_ADDR ADDR(PWM_BASE, PWM_TypeDef, PER)

/*
    0x0040
    PWM Clock Gating Register
*/
namespace pcgr {
    /* 
        Gating clock for PWM[0-7]
        0: mask, 1: pass 
    */
    typedef reg_bit_array<PCGR_ADDR, 0x01, 0b1, 0, rw> clk_gating;
    /* 15:8 Reserved */
    /* 
        Bypass clock source (after pre-scale) to PWM[0-7] output. 
        0: not bypass, 1: bypass 
    */
    typedef reg_bit_array<PCGR_ADDR, 0x01, 0b1, 16, rw> clk_bypass;
    /* 31:24 Reserved */
};

/*
    0x080
    PWM Enable Register
*/
namespace per {
    /* 
        PWM[0-7] Enable
        When PWM is enabled, the 16-bit up-counter starts working and PWM channel is permitted to output PWM waveform.
        0: PWM disable, 1: PWM enable
    */
    typedef reg_bit_array<PER_ADDR, 0x01, 0b1, 0, rw> en;
    /* 31:8 Reserved */
}

/*
    0x0020 + N*0x04 (N=0~4)
    PWM Clock Configuration Register
*/
namespace pccr {
    /* 
        PWM_Group[0-4] Clock Divide M
        0000: 1, 0001: 2, 0010: 4, 0011: 8, 0100: 16, 0101: 32, 0110: 64, 0111: 128, 1000: 256
    */
    typedef reg_array<PCCR_ADDR, 0x04, 0b1111, 0, rw> clk_div_m;
    // 6:4 Reserved
    /* 
        PWM_Group[0-4] Clock Source
        00: HOSC, 01: APB0
    */
    typedef reg_array<PCCR_ADDR, 0x04, 0b11, 7, rw> clk_src;
    // 31:9 Reserved
};

/*
    0x0100 + 0x00 + N*0x20 (N=0~7)
    PWM Control Register
*/
namespace pcr {
    /*
        PWM[0-7] pre-scale K
        actual pre-scale is (K+1)
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b11111111, 0, rw> prescal_k;
    /* 
        PWM[0-7] Active State
        0: low level, 1: high level
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b1, 8, rw> act_sta;
    /* 
        PWM[0-7] Mode
        0: cycle mode, 1: pulse mode
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b1, 9, rw> mode;
    /*
        PWM[0-7] Pulse Output Start
        0: No effect
        1: Output pulse for PWM_CYCLE_NUM + 1
        After finishing configuration for the output pulse, set this bit once, then PWM would output waveform. After the waveform is finished, the bit will be cleared automatically.
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b1, 10, rw> pul_start;
    /* 
        PWM[0-7] Period Register Ready
        0: PWM period register is ready, 1: PWM period register is busy
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b1, 11, ro> period_rdy;
    // 15:12 Reserved
    /* 
        PWM[0-7] Pulse Number
        In pulse mode, the PWM outputs pulse for PWM_CYCLE_NUM+1 times and then stops.
    */
    typedef reg_array<PCR_ADDR, 0x20, 0b1111111111111111, 16, rw> pul_num;
};

/*
    0x0100 + 0x04 + N*0x20 (N=0~7)
    PWM Period Register
*/
namespace ppr {
    /*
        PWM[0-7] Number of the active cycles in the PWM clock.
        0: 0 cycle
        1: 1 cycle
        ...
        N: N cycles
    */
    typedef reg_array<PPR_ADDR, 0x20, 0b1111111111111111, 0, rw> act_cycle;
    /*
        PWM[0-7] Number of the entire cycles in the PWM clock.
        0: 1 cycle
        1: 2 cycles
        ...
        N: N+1 cycles
    */
    typedef reg_array<PPR_ADDR, 0x20, 0b1111111111111111, 16, rw> entire_cycle;
};

/*
    0x0100 + 0x08 + N*0x20 (N=0~7)
    PWM Period Register
*/
namespace pcntr {
    /*
        PWM[0-7] counter status.
        On PWM output or capture input, reading this register could get the current value of the PWM 16-bit up-counter.
    */
    typedef reg_array<PCNTR_ADDR, 0x20, 0b1111111111111111, 0, ro> counter_status;
    /*
        PWM[0-7] counter start.
        PWM counter value is set for phase control.
    */
    typedef reg_array<PCNTR_ADDR, 0x20, 0b1111111111111111, 16, rw> counter_start;
};

};