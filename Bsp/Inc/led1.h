
/**
 * @brief 要考虑重复包含的问题
 */
#ifndef BSP_LED_H
#define BSP_LED_H
#include "stm32f1xx_hal.h"

//============================================================================
// 引脚的定义
#define LED_PORT GPIOA

#define LED_PINS (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | \
                  GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)

void BSP_LED_Init(void);
void BSP_LED_Loop(void);

#endif /* 结束 #ifndef BSP_LED_H */