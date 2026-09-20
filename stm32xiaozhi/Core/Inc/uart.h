#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include "main.h"
#ifdef __cplusplus

extern "C" {

#endif
void UART_Init(void);
uint8_t UART_GetRxData(uint8_t *data);
#ifdef __cplusplus

}

#endif
#endif
