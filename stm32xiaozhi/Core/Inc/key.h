#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

#define KEY_PRESSED  1
#define KEY_RELEASED 0

#ifdef __cplusplus
extern "C" {
#endif

uint8_t KEY1_IsPressed(void);
uint8_t KEY2_IsPressed(void);
uint8_t KEY3_IsPressed(void);

#ifdef __cplusplus
}
#endif

#endif
