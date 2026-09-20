#include "soft_pwm.h"

/*
 * TIM2 每 10us 进一次中断。
 * 100 次中断 = 1ms，软件 PWM 频率 = 1kHz。
 */
#define SOFT_PWM_PERIOD 100U

static uint8_t pwm_duty[3] = {0, 0, 0};
static uint8_t pwm_count = 0;

/* 三路呼吸灯：错开相位，各自在 0~100 之间来回变化 */
static uint8_t breath_duty[3] = {0, 50, 100};
static int8_t  breath_dir[3]  = {1, 1, -1};

void SoftPWM_Init(void)
{
    pwm_count = 0;

    pwm_duty[SOFT_PWM_LED1] = 0;
    pwm_duty[SOFT_PWM_LED2] = 0;
    pwm_duty[SOFT_PWM_LED3] = 0;

    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
}

void SoftPWM_SetDuty(SoftPWM_Channel_t channel, uint8_t duty)
{
    if (channel > SOFT_PWM_LED3)
    {
        return;
    }
    if (duty > 100U)
    {
        duty = 100U;
    }
    pwm_duty[channel] = duty;
}

uint8_t SoftPWM_GetDuty(SoftPWM_Channel_t channel)
{
    if (channel > SOFT_PWM_LED3)
    {
        return 0;
    }
    return pwm_duty[channel];
}

void SoftPWM_Update(void)
{
    uint32_t set_mask = 0;
    uint32_t rst_mask = 0;

    pwm_count++;
    if (pwm_count >= SOFT_PWM_PERIOD)
    {
        pwm_count = 0;
    }

    if (pwm_count < pwm_duty[SOFT_PWM_LED1])
    {
        set_mask |= LED1_Pin;
    }
    else
    {
        rst_mask |= LED1_Pin;
    }

    if (pwm_count < pwm_duty[SOFT_PWM_LED2])
    {
        set_mask |= LED2_Pin;
    }
    else
    {
        rst_mask |= LED2_Pin;
    }

    if (pwm_count < pwm_duty[SOFT_PWM_LED3])
    {
        set_mask |= LED3_Pin;
    }
    else
    {
        rst_mask |= LED3_Pin;
    }

    /* 三路灯都在 GPIOA，一次写完，缩短 10us 中断占用 */
    GPIOA->BSRR = rst_mask | (set_mask << 16);
}

void SoftPWM_BreathUpdate(void)
{
    uint8_t i;

    for (i = 0; i < 3U; i++)
    {
        if (breath_dir[i] > 0)
        {
            if (breath_duty[i] >= 100U)
            {
                breath_dir[i] = -1;
                breath_duty[i] = 100U;
            }
            else
            {
                breath_duty[i]++;
            }
        }
        else
        {
            if (breath_duty[i] == 0U)
            {
                breath_dir[i] = 1;
                breath_duty[i] = 0U;
            }
            else
            {
                breath_duty[i]--;
            }
        }

        SoftPWM_SetDuty((SoftPWM_Channel_t)i, breath_duty[i]);
    }
}
