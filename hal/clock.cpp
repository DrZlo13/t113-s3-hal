#include "clock.h"
#include "regs/ccu.hpp"

static void hal_pwm_clock_enable() {
    // enable clock and deassert reset
    ccu::pwm_bgr_reg::gating::write(1);
    ccu::pwm_bgr_reg::reset::write(1);
}

static void hal_uart_clock_enable(uint32_t port) {
    hal_assert(port < 6);
    // enable clock and deassert reset
    ccu::uart_bgr_reg::gating::write(port, 1);
    ccu::uart_bgr_reg::reset::write(port, 1);
}

void hal_clock_enable(ClockSystem target) {
    switch(target) {
    case ClockSystemUart0:
        hal_uart_clock_enable(0);
        break;
    case ClockSystemUart1:
        hal_uart_clock_enable(1);
        break;
    case ClockSystemUart2:
        hal_uart_clock_enable(2);
        break;
    case ClockSystemUart3:
        hal_uart_clock_enable(3);
        break;
    case ClockSystemUart4:
        hal_uart_clock_enable(4);
        break;
    case ClockSystemUart5:
        hal_uart_clock_enable(5);
        break;
    case ClockSystemPWM:
        hal_pwm_clock_enable();
        break;
    default:
        break;
    }
}
