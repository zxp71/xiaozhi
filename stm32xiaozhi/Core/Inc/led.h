#ifndef __LED_H__
#define __LED_H__

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

void LED1_On(void);
void LED2_On(void);
void LED3_On(void);

void LED1_Off(void);
void LED2_Off(void);
void LED3_Off(void);

void LED1_Toggle(void);
void LED2_Toggle(void);
void LED3_Toggle(void);

#ifdef __cplusplus
}
#endif

#endif
