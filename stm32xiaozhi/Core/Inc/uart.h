#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>

#ifdef __cplusplus

extern "C" {

#endif
typedef enum
{
 UART_LOG_DEBUG=0,
 UART_LOG_INFO,
 UART_LOG_WARN,
 UART_LOG_ERROR
}UART_LogLevel;

void UART_SendByte(uint8_t data);
void UART_SendData(const uint8_t *data,uint16_t len);
void UART_SendString(const char *str);
void UART_Log(const char *message);
void UART_Error(const char *message);

#ifdef __cplusplus

}

#endif
#endif
