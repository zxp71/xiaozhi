#ifndef __SOFT_PWM_H__
#define __SOFT_PWM_H__

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SOFT_PWM_LED1 = 0,
    SOFT_PWM_LED2,
    SOFT_PWM_LED3
} SoftPWM_Channel_t;

void SoftPWM_Init(void);
void SoftPWM_SetDuty(SoftPWM_Channel_t channel, uint8_t duty);
uint8_t SoftPWM_GetDuty(SoftPWM_Channel_t channel);
void SoftPWM_Update(void);
void SoftPWM_BreathUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* __SOFT_PWM_H__ */
