#include "../../cmsis_t113s3.h"
#include "../../std/register.hpp"

/* CCU peripheral */
namespace ccu {
/*
    0x7AC
    PWM Bus Gating Reset Register
*/
namespace pwm_bgr_reg {
    constexpr size_t address = ADDR(CCU_BASE, CCU_TypeDef, PWM_BGR_REG);
    typedef reg<address, 0b1, 0, rw> gating;
    /* 15:1 Reserved */
    typedef reg<address, 0b1, 16, rw> reset;
    /* 31:17 Reserved */
};
/*
    0x90C
    UART Bus Gating Reset Register
*/
namespace uart_bgr_reg {
    constexpr size_t address = ADDR(CCU_BASE, CCU_TypeDef, UART_BGR_REG);
    typedef reg_bit_array<address, 1, 0b1, 0, rw> gating;
    /* 15:1 Reserved */
    typedef reg_bit_array<address, 1, 0b1, 16, rw> reset;
    /* 31:17 Reserved */
};
}