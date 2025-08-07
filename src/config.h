#ifndef CONFIG_H
#define CONFIG_H

#define FOSC 11059200UL   // Crystal frequency
#define BAUD 9600

#define DS18B20_PIN P3_7  // 1-Wire data pin
#define LCD_RS P2_0
#define LCD_RW P2_1
#define LCD_EN P2_2
#define LCD_DATA P0       // Port for LCD data

#define BTN_UP   P3_2     // Increase set temp
#define BTN_DOWN P3_3     // Decrease set temp

#define FAN_PWM  P1_0     // Fan control pin

#define TEMP_DEFAULT 25   // Default temperature setpoint

#endif
