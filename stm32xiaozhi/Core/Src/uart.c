#include "uart.h"
#include "usart.h"
#include<string.h>

static uint8_t uart_rx_data;
static uint8_t uart_rx_flag;

void UART_Init(void)
{
    HAL_UART_Receive_IT(&huart1,
                       &uart_rx_data,
                       1);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        uart_rx_flag = 1;
        HAL_UART_Receive_IT(&huart1,
                           &uart_rx_data,
                           1);
    }
}

uint8_t UART_GetRxData(uint8_t *data)
{
    if(uart_rx_flag)
    {
        *data = uart_rx_data;
        uart_rx_flag = 0;
        return 1;
    }
    return 0;
}