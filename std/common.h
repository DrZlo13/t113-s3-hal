#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASM
#define __ASM __asm
#endif

#define __NOP() __ASM volatile("nop")

#define SET_BIT(reg, bit) ((reg) |= (1 << (bit)))
#define CLR_BIT(reg, bit) ((reg) &= ~(1 << (bit)))

#define UNUSED(x) (void)(x)

#define API extern "C"

void hal_assert_handler(const char* expr, const char* func, size_t line);

#if defined(DEBUG) || defined(_DEBUG) || defined(HAL_ENABLE_ASSERT)
#define hal_assert(x)                                   \
    if(!(x)) {                                          \
        hal_assert_handler(#x, __FUNCTION__, __LINE__); \
    }
#else
#define hal_assert(x) UNUSED(x)
#endif

void delay_nop(uint32_t n);

#ifdef __cplusplus
}
#endif