#pragma once
#include "../std/common.h"
#include "../cmsis_t113s3.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GpioConfigInput = 0b0000,
    GpioConfigOutput = 0b0001,
    GpioConfigFunction2 = 0b0010,
    GpioConfigFunction3 = 0b0011,
    GpioConfigFunction4 = 0b0100,
    GpioConfigFunction5 = 0b0101,
    GpioConfigFunction6 = 0b0110,
    GpioConfigFunction7 = 0b0111,
    GpioConfigFunction8 = 0b1000,
    GpioConfigFunction14 = 0b1110,
    GpioConfigExternalInterrupt = 0b1110,
    GpioConfigIODisable = 0b1111
} GpioConfig;

typedef enum {
    GpioPullDisable = 0b00,
    GpioPullUp = 0b01,
    GpioPullDown = 0b10,
} GpioPull;

void hal_gpio_set_config(GPIO_TypeDef* port, uint32_t pin, GpioConfig config);

void hal_gpio_write(GPIO_TypeDef* port, uint32_t pin, bool value);

void hal_gpio_pull(GPIO_TypeDef* port, uint32_t pin, GpioPull pull);

#ifdef __cplusplus
}
#endif