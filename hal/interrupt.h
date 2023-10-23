#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    InterruptSGI0 = 0,
    InterruptSGI1 = 1,
    InterruptSGI2 = 2,
    InterruptSGI3 = 3,
    InterruptSGI4 = 4,
    InterruptSGI5 = 5,
    InterruptSGI6 = 6,
    InterruptSGI7 = 7,
    InterruptSGI8 = 8,
    InterruptSGI9 = 9,
    InterruptSGI10 = 10,
    InterruptSGI11 = 11,
    InterruptSGI12 = 12,
    InterruptSGI13 = 13,
    InterruptSGI14 = 14,
    InterruptSGI15 = 15,
    InterruptPPI0 = 16,
    InterruptPPI1 = 17,
    InterruptPPI2 = 18,
    InterruptPPI3 = 19,
    InterruptPPI4 = 20,
    InterruptPPI5 = 21,
    InterruptPPI6 = 22,
    InterruptPPI7 = 23,
    InterruptPPI8 = 24,
    InterruptPPI9 = 25,
    InterruptPPI10 = 26,
    InterruptPPI11 = 27,
    InterruptPPI12 = 28,
    InterruptPPI13 = 29,
    InterruptPPI14 = 30,
    InterruptPPI15 = 31,
    InterruptCpuMessageBoxRead = 32, // CPUX MSGBOX READ IRQ
    /* interrupt 33 */
    InterruptUART0 = 34,
    InterruptUART1 = 35,
    InterruptUART2 = 36,
    InterruptUART3 = 37,
    InterruptUART4 = 38,
    InterruptUART5 = 39,
    /* interrupt 40 */
    InterruptTWI0 = 41,
    InterruptTWI1 = 42,
    InterruptTWI2 = 43,
    InterruptTWI3 = 44,
    /* interrupt 45 */
    /* interrupt 46 */
    InterruptSPI0 = 47,
    InterruptSPI1 = 48,
    /* interrupt 49 */
    InterruptPWM = 50,
    InterruptCirTx = 51,
    InterruptLedc = 52,
    /* interrupt 53 */
    /* interrupt 54 */
    InterruptOWA = 55,
    InterruptDMic = 56,
    InterruptAudioCodec = 57,
    /* interrupt 58 */
    InterruptI2S1 = 59,
    InterruptI2S2 = 60,
    InterruptUSB0Device = 61,
    InterruptUSB0EHCI = 62,
    InterruptUSB0OHCI = 63,
    /* interrupt 64 */
    InterruptUSB1EHCI = 65,
    InterruptUSB1OHCI = 66,
    /* interrupt 67 */
    /* interrupt 68 */
    /* interrupt 69 */
    /* interrupt 70 */
    /* interrupt 71 */
    InterruptSMHC0 = 72,
    InterruptSMHC1 = 73,
    InterruptSMHC2 = 74,
    InterruptMCI = 75,
    InterruptSMC = 76,
    /* interrupt 77 */
    InterruptEMAC = 78,
    InterruptTZMAError = 79, // SRAM_A1 TZMA IRQ
    InterruptCCUFError = 80,
    InterruptAHBHReadyTimeout = 81, // SYS_CTRL ahb_hready timeout
    InterruptDMACS_NS = 82,
    InterruptDMACS_S = 83,
    InterruptCE_NS = 84,
    InterruptCE_S = 85,
    InterruptSpinlock = 86,
    InterruptHSTimer0 = 87,
    InterruptHSTimer1 = 88,
    InterruptGPAdc = 89,
    InterruptTHS = 90, // Thermal Sensor IRQ
    InterruptTimer0 = 91,
    InterruptTimer1 = 92,
    /* interrupt 93 */
    InterruptTPADC = 94,
    InterruptWatchDog = 95,
    InterruptIOMMU = 96,
    /* interrupt 97 */
    InterruptVE = 98,
    /* interrupt 99 */
    /* interrupt 100 */
    InterruptGPIOB_NS = 101,
    InterruptGPIOB_S = 102,
    InterruptGPIOC_NS = 103,
    InterruptGPIOC_S = 104,
    InterruptGPIOD_NS = 105,
    InterruptGPIOD_S = 106,
    InterruptGPIOE_NS = 107,
    InterruptGPIOE_S = 108,
    InterruptGPIOF_NS = 109,
    InterruptGPIOF_S = 110,
    InterruptGPIOG_NS = 111,
    InterruptGPIOG_S = 112,
    /* interrupt 113 */
    /* interrupt 114 */
    /* interrupt 115 */
    /* interrupt 116 */
    InterruptCPUX_MSGBOX_DSP_W = 117, // CPUX MSGBOX WRITE IRQ for DSP
    /* interrupt 118 */
    InterruptDE = 119,
    InterruptDI = 120,
    InterruptG2D = 121,
    InterruptLCD = 122,
    InterruptTV = 123,
    InterruptDSI = 124,
    /* interrupt 125 */
    InterruptTVE = 126, // CVBS OUT interrupt
    InterruptCSI_DMA0 = 127,
    InterruptCSI_DMA1 = 128,
    /* interrupt 129 */
    /* interrupt 130 */
    /* interrupt 131 */
    InterruptCSI_PARSER0 = 132,
    // TODO: page 223
} Interrupt;

#ifdef __cplusplus
}
#endif