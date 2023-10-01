#include "gpio.h"

void hal_gpio_set_config(GPIO_TypeDef* port, uint32_t pin, GpioConfig config) {
    uint32_t cfg_index = pin / (32 / 4);
    uint32_t cfg_offset = (pin % (32 / 4)) * 4;
    uint32_t cfg_reg = port->CFG[cfg_index];
    cfg_reg &= ~(0b1111 << cfg_offset);
    cfg_reg |= (((uint32_t)config & 0b1111) << cfg_offset);
    port->CFG[cfg_index] = cfg_reg;
}

void hal_gpio_write(GPIO_TypeDef* port, uint32_t pin, bool value) {
    if(value > 0) {
        SET_BIT(port->DATA, pin);
    } else {
        CLR_BIT(port->DATA, pin);
    }
}

void hal_gpio_pull(GPIO_TypeDef* port, uint32_t pin, GpioPull pull) {
    int pull_index = pin / (32 / 2);
    int pull_offset = (pin % (32 / 2)) * 2;

    uint32_t pull_reg = port->PULL[pull_index];
    pull_reg &= ~(0b11 << pull_offset);
    pull_reg |= (((uint32_t)pull & 0b11) << pull_offset);
    port->PULL[pull_index] = pull_reg;
}
