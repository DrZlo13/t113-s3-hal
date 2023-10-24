#pragma once
#include <cstddef>
#include <cstdint>

// register
template <uint32_t address, uint32_t mask, uint32_t offset, class mutability_policy> struct reg {
    static void write(unsigned value) {
        mutability_policy::write(
            reinterpret_cast<volatile uint32_t*>(address), mask, offset, value);
    }
    static uint32_t read() {
        return mutability_policy::read(
            reinterpret_cast<volatile uint32_t*>(address), mask, offset);
    }
};

// array of registers
template <uint32_t address, size_t size, uint32_t mask, uint32_t offset, class mutability_policy>
struct reg_array {
    static void write(size_t index, unsigned value) {
        mutability_policy::write(
            reinterpret_cast<volatile uint32_t*>(address + index * size), mask, offset, value);
    }

    static uint32_t read(size_t index) {
        return mutability_policy::read(
            reinterpret_cast<volatile uint32_t*>(address + index * size), mask, offset);
    }
};

// array of bit in register
template <uint32_t address, size_t size, uint32_t mask, uint32_t offset, class mutability_policy>
struct reg_bit_array {
    static void write(size_t index, bool value) {
        mutability_policy::write(
            reinterpret_cast<volatile uint32_t*>(address), mask, offset + index * size, value);
    }

    static bool read(size_t index) {
        return mutability_policy::read(
            reinterpret_cast<volatile uint32_t*>(address), mask, offset + index * size);
    }
};

// write-only mutability policy
struct wo {
    static void write(volatile uint32_t* reg, uint32_t mask, uint32_t offset, uint32_t value) {
        *reg = (value & mask) << offset;
    }
};

// read-only mutability policy
struct ro {
    static uint32_t read(volatile uint32_t* reg, uint32_t mask, uint32_t offset) {
        return (*reg >> offset) & mask;
    }
};

// read-write mutability policy
struct rw : public ro {
    static void write(volatile uint32_t* reg, uint32_t mask, uint32_t offset, uint32_t value) {
        *reg = (*reg & ~(mask << offset)) | ((value & mask) << offset);
    }
};