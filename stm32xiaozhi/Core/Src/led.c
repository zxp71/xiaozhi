#include "app_adc.h"
#include "led.h"
#include "soft_pwm.h"

void LED_ManualControl(void)
{
    uint16_t adc_value = APP_ADC_GetValue();
    uint8_t duty = (uint8_t)((adc_value * 100) / 4095);
    SoftPWM_SetDuty(SOFT_PWM_LED1,duty);
}

void LED_BreathMode(void)
{
    SoftPWM_BreathUpdate();
    HAL_Delay(10); // 延时 10ms，呼吸灯频率约为 1Hz
}

void LED_Off(void)
{
    SoftPWM_SetDuty(SOFT_PWM_LED1,0);
    SoftPWM_SetDuty(SOFT_PWM_LED2,0);
    SoftPWM_SetDuty(SOFT_PWM_LED3,0);
}