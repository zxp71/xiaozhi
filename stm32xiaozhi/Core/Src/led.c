#include "main.h"
#include "led.h"


void LED1_On(void)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
}

void LED2_On(void)
{
    HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
}

void LED3_On(void)
{
    HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_SET);
}

void LED1_Off(void)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
}

void LED2_Off(void)
{
    HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
}

void LED3_Off(void)
{
    HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_RESET);
}

void LED1_Toggle(void)
{
    HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
}

void LED2_Toggle(void)
{
    HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
}

void LED3_Toggle(void)
{
    HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
}
