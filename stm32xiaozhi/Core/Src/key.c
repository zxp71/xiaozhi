#include "key.h"

/* 板上按键接 GND，按下为低电平（GPIO_PIN_RESET），松开为高电平 */
uint8_t KEY1_IsPressed(void)
{
    if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
        {
            return KEY_PRESSED;
        }
    }
    return KEY_RELEASED;
}

uint8_t KEY2_IsPressed(void)
{
    if (HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        if (HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET)
        {
            return KEY_PRESSED;
        }
    }
    return KEY_RELEASED;
}

uint8_t KEY3_IsPressed(void)
{
    if (HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        if (HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin) == GPIO_PIN_RESET)
        {
            return KEY_PRESSED;
        }
    }
    return KEY_RELEASED;
}
