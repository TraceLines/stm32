
#include "led1.h"
/**
 * 也体会到了C语言之中，全局亦变量的设置问题。
 */
// 静态变量记录当前点亮的位置（0~7）
static uint8_t current_led = 0;
void BSP_LED_Init(void)
{
    GPIO_InitTypeDef GPIO_LED_InitStruct = {0};

    GPIO_LED_InitStruct.Pin = LED_PINS;
    GPIO_LED_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_LED_InitStruct.Pull = GPIO_NOPULL;
    GPIO_LED_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_PORT, &GPIO_LED_InitStruct);
    HAL_GPIO_WritePin(LED_PORT, LED_PINS, GPIO_PIN_SET);
}

void BSP_LED_Loop(void)
{
    // 关闭所有LED
    HAL_GPIO_WritePin(LED_PORT, LED_PINS, GPIO_PIN_SET);

    // 点亮当前LED 使用
    HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_0 << current_led, GPIO_PIN_RESET);

    // 更新位置，循环0~7
    current_led = (current_led + 1) % 8;
}