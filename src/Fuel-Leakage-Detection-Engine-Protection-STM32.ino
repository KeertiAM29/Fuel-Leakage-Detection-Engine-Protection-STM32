#include "main.h"

ADC_HandleTypeDef hadc1;

#define FUEL_THRESHOLD 2000

/* Pin assignment used in this implementation
 *
 * MQ-3 Analog Output : PA0  -> ADC1_IN0
 * Green LED          : PB0
 * Red LED            : PB1
 * Motor Control      : PB10
 */

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

int main(void)
{
    uint32_t adc_value;

    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_ADC1_Init();

    while (1)
    {
        /* Start ADC conversion */
        HAL_ADC_Start(&hadc1);

        /* Wait for ADC conversion */
        HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

        /* Read MQ-3 sensor value */
        adc_value = HAL_ADC_GetValue(&hadc1);

        if (adc_value < FUEL_THRESHOLD)
        {
            /* Normal condition */

            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_0,
                GPIO_PIN_SET
            );

            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_1,
                GPIO_PIN_RESET
            );

            /* Motor ON */
            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_10,
                GPIO_PIN_SET
            );
        }
        else
        {
            /* Fuel leakage detected */

            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_0,
                GPIO_PIN_RESET
            );

            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_1,
                GPIO_PIN_SET
            );

            /* Motor OFF */
            HAL_GPIO_WritePin(
                GPIOB,
                GPIO_PIN_10,
                GPIO_PIN_RESET
            );
        }

        HAL_Delay(100);
    }
}
