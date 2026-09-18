#include "app_adc.h"
#include "adc.h"

#define ADC_SAMPLE_COUNT 10

uint16_t APP_ADC_GetValue(void)
{
    uint16_t adc_value = 0;

    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK)
    {
        adc_value = (uint16_t)HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);

    return adc_value;
}

uint16_t APP_ADC_GetAverageValue(void)
{
    uint32_t sum =0;
    uint8_t i;
    for(i=0;i<ADC_SAMPLE_COUNT;i++)
    {
        sum+=APP_ADC_GetValue();
    }
    return (uint16_t)(sum/ADC_SAMPLE_COUNT);
}

float APP_ADC_GetVoltage(void)
{
    uint16_t adc_value;

    adc_value = APP_ADC_GetAverageValue();
    return ((float)adc_value * 3.3f) / 4095.0f;
}
