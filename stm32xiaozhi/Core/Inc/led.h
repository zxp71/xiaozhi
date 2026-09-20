#ifndef __LED_H__
#define __LED_H__

#include "main.h"
#include "app_adc.h"

#ifdef __cplusplus
extern "C" {
#endif
void LED_ManualControl(void);
void LED_BreathMode(void);
void LED_Off(void);
#ifdef __cplusplus
}
#endif

#endif
