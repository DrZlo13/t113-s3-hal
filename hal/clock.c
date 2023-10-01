#include "clock.h"

#define CCM_UART_RST_OFFSET (16)
#define CCM_UART_GATING_OFFSET (0)

static void hal_uart_clock_enable(uint32_t port) {
    // enable clock
    SET_BIT(CCU->UART_BGR_REG, CCM_UART_GATING_OFFSET + port);

    // deassert reset
    SET_BIT(CCU->UART_BGR_REG, CCM_UART_RST_OFFSET + port);
}

void hal_clock_enable(ClockTarget target) {
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
    default:
        break;
    }
}
