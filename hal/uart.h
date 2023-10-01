#pragma once
#include "../std/common.h"
#include "../cmsis_t113s3.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    UartParityNone = 0,
    UartParityOdd = 1,
    UartParityEven = 3,
} UartParity;

typedef enum {
    UartStopBit1 = 0,
    UartStopBit1p5 = 1,
    UartStopBit2 = 1,
} UartStopBit;

typedef enum {
    UartDataLen5 = 0,
    UartDataLen6 = 1,
    UartDataLen7 = 2,
    UartDataLen8 = 3,
} UartDataLen;

void hal_uart_config(
    UART_TypeDef* uart,
    uint32_t baud_rate,
    UartParity parity,
    UartStopBit stop_bit,
    UartDataLen data_len);

void hal_uart_put_byte(UART_TypeDef* uart, uint8_t byte);

bool hal_uart_get_byte(UART_TypeDef* uart, uint8_t* byte);

void hal_uart_enable_interrupt(UART_TypeDef* uart);

void hal_uart_disable_interrupt(UART_TypeDef* uart);

// 0000: modem status
// 0001: no interrupt pending
// 0010: THR empty
// 0011: RS485 Interrupt
// 0100: received data available
// 0110: receiver line status
// 0111: busy detect
// 1100: character timeout

typedef enum {
    UartInterruptModemStatus = 0b0000,
    UartInterruptNoInterrupt = 0b0001,
    UartInterruptThrEmpty = 0b0010,
    UartInterruptRs485 = 0b0011,
    UartInterruptReceiverDataAvailable = 0b0100,
    UartInterruptReceiverDataStatus = 0b0110,
    UartInterruptBusyDetect = 0b0111,
    UartInterruptCharacterTimeout = 0b1100,
} UartInterrupt;

uint8_t hal_uart_read_and_clear_int(UART_TypeDef* uart);

#ifdef __cplusplus
}
#endif