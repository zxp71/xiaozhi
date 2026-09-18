#include "uart.h"
#include "usart.h"
#include<string.h>

void UART_SendByte(uint8_t data)
{
    HAL_UART_Transmit(&huart1,&data,1,100);
}

void UART_SendData(const uint8_t *data,uint16_t len)
{
    if(data==NULL||len==0)
    {
        return;
    }
    HAL_UART_Transmit(&huart1,(uint8_t*)data,len,100);
}

void UART_SendString(const char *str)
{
    if(str==NULL)
    {
        return;
    }
    UART_SendData((const uint8_t *)str,(uint16_t)strlen(str));
}

void UART_Log(const char *message)
{
    if(message==NULL)
    {
        return;
    }
    UART_SendString("[INFO]");
    UART_SendString(message);
    UART_SendString("\r\n");
}

void UART_Error(const char *message)
{
    if(message==NULL)
    {
        return;
    }
    UART_SendString("[ERROR]");
    UART_SendString(message);
    UART_SendString("\r\n");
}