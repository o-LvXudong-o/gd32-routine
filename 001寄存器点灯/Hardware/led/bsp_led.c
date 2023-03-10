#include "bsp_led.h"

/************************************************
函数名称 ： led_gpio_config
功    能 ： led灯gpio引脚配置
参    数 ： 无
返 回 值 ： 无
作    者 ： DongDong
*************************************************/

void led_gpio_config(void)
{
     /* 开启GPIO 端口时钟 */
     BSP_RCU_AHB1EN |= (0x01<<3);            // RCU_AHB1EN寄存器的第3位置1 
     /* 配置PD7为输出模式 */
     BSP_GPIOD_CTL &= ~(0x03 << (2*7));      // 清零第15位和第14位
     BSP_GPIOD_CTL |= (0x01 << (2*7));       // 第15位和第14位配置为01
     /* 配置PD7为浮空模式 */
     BSP_GPIOD_PUD &= ~(0x03 << (2*7));      // 清零第15位和第14位
     BSP_GPIOD_PUD |= (0x00 << (2*7));       // 第15位和第14位配置为00
     /* 配置PD7位推挽输出 */
     BSP_GPIOD_OMODE &= ~(0x01 << 7);        // 把第7位清零
     BSP_GPIOD_OMODE |= (0x00 << 7);         // 第7位配置为0
     /* 配置PD7的速度为等级2 50MHZ */
     BSP_GPIOD_OSPD &= ~(0x03 << (2*7));     // 清零第15位和第14位
     BSP_GPIOD_OSPD |= (0x02 << (2*7));      // 第15位和第14位配置为10
}
