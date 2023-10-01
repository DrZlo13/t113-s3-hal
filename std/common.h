#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef __ASM
#define __ASM __asm
#endif

#define __NOP() __ASM volatile("nop")

#define SET_BIT(reg, bit) ((reg) |= (1 << (bit)))
#define CLR_BIT(reg, bit) ((reg) &= ~(1 << (bit)))

#define UNUSED(x) (void)(x)

void delay_nop(uint32_t n);