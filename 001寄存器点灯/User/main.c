/*!
************************************************
  * 文 件 名: main.c
  * 版 本 号: 初版
  * 修改作者: DongDong
  * 修改日期: 2022年12月19日
  * 功能介绍:          
  ***********************************************
  * 注意事项:
*************************************************/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"

/************************************************
函数名称 ： main
功    能 ： 主函数
参    数 ： 无
返 回 值 ： 无
作    者 ： DongDong
*************************************************/
int main(void)
{
    systick_config();   // 滴答定时器初始化
    led_gpio_config();  // led 初始化
    //BSP_GPIOD_OCTL |= (0x01 << 7);
	//BSP_GPIOD_OCTL &= ~(0x01 << 7);

	//BSP_GPIOD_BOP |= (0x01 << 7);
	BSP_GPIOD_BOP |= (0x01 << (7 + 16));

    BSP_GPIOD_TG |= (0x01 << 7);
    while(1) {
    }
}
