#ifndef __APP_ADC_H__
#define __APP_ADC_H__
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif
uint16_t APP_ADC_GetValue(void);
uint16_t APP_ADC_GetAverageValue(void);
float APP_ADC_GetVoltage(void);

#ifdef __cplusplus
}
#endif
#endif
