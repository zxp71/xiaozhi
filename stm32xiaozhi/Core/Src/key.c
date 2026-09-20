#include "key.h"
#include "main.h"

typedef enum
{
    KEY_STATE_RELEASED=0,
    KEY_STATE_DEBOUNDE,
    KEY_STATE_PRESSED
}KEY_State_t;


uint8_t KEY1_GetPressEvent(void)
{
    static KEY_State_t state = KEY_STATE_RELEASED;
    static uint32_t debounce_start_time = 0;

    GPIO_PinState pin_state= HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin);
    switch(state)
    {
        case KEY_STATE_RELEASED:
        if(pin_state==GPIO_PIN_RESET)
        {
            debounce_start_time = HAL_GetTick();
            state = KEY_STATE_DEBOUNDE;
        }
    
        break;
        case KEY_STATE_DEBOUNDE:
        if(pin_state==GPIO_PIN_SET)
        {
            state = KEY_STATE_RELEASED;
        }
        else if(HAL_GetTick()-debounce_start_time>=20)
        {
            state=KEY_STATE_PRESSED;
            return 1;
        }
        break;
        case KEY_STATE_PRESSED:
        if(pin_state==GPIO_PIN_SET)
        {
            state=KEY_STATE_RELEASED;
        }
        break;
        default:
        state=KEY_STATE_RELEASED;
        break;
    }
    return 0;
}
