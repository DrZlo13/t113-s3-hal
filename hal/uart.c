#include "uart.h"

#define UART_DLH DLH_IER
#define UART_DLL DATA

void hal_uart_config(
    UART_TypeDef* uart,
    uint32_t baud_rate,
    UartParity parity,
    UartStopBit stop_bit,
    UartDataLen data_len) {
    uint32_t uart_clock_divisor = (24000000 + 8 * baud_rate) / (16 * baud_rate);

    // write fcr[FIFOE] to 1 to enable TX/RX fifos
    SET_BIT(uart->IIR_FCR, 0);
    // write halt[HALT_TX] to 1 to disable TX transfer
    SET_BIT(uart->UART_HALT, 0);
    // set lcr[DLAB] to 1 to access the dlh and dll registers
    SET_BIT(uart->UART_LCR, 7); // enable the divisor latch access bit to set baud: lcr[DLAB] = 1
    // set the baud rate
    uart->UART_DLH = ((uart_clock_divisor >> 8) & 0xFF);
    uart->UART_DLL = (uart_clock_divisor & 0xFF);
    // set lcr[DLAB] to 0 to disable latch access
    CLR_BIT(uart->UART_LCR, 7); // disable the latch access

    ////////////////////////////
    // set data width, stop bit, parity bit
    uart->UART_LCR = (((uint32_t)parity & 0x03) << 3) | (((uint32_t)stop_bit & 0x01) << 2) |
                     ((uint32_t)data_len & 0x03);
    // reset, enable FIFO and set FIFO trigger condition by writing to the fcr register
    uart->IIR_FCR = 0b111;
    // set flow control parameter by writing to the mcr register
    uart->UART_MCR = 0b11;
    // set halt[HALT_TX] to 0 to enable TX transfer
    CLR_BIT(uart->UART_HALT, 0);
}

void hal_uart_put_byte(UART_TypeDef* uart, uint8_t byte) {
    while((uart->UART_USR & (1 << 1)) == 0) {
    }
    uart->DATA = byte;
}

bool hal_uart_get_byte(UART_TypeDef* uart, uint8_t* byte) {
    bool result = false;

    if((uart->UART_USR & (1 << 3)) != 0) {
        *byte = uart->DATA;
        result = true;
    }

    return result;
}

void hal_uart_enable_interrupt(UART_TypeDef* uart) {
    // disable interrupt
    uart->DLH_IER = 0x01;
}

void hal_uart_disable_interrupt(UART_TypeDef* uart) {
    // disable interrupt
    uart->DLH_IER = 0x00;
}

uint8_t hal_uart_read_and_clear_int(UART_TypeDef* uart) {
    uint8_t int_status = 0;
    int_status = uart->IIR_FCR & 0b1111;
    return int_status;
}