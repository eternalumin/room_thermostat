#include <reg51.h>
#include "lcd.h"
#include "ds18b20.h"
#include "eeprom.h"

#define FAN_PWM_PIN P1_0
#define HIGH_TEMP_THRESHOLD 30
#define LOW_TEMP_THRESHOLD 25

unsigned char currentTemp = 0;
unsigned char highThreshold, lowThreshold;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void PWM_Fan_Control(unsigned char speed) {
    // Simple software PWM control
    unsigned char i;
    for (i = 0; i < 10; i++) {
        FAN_PWM_PIN = 1;
        delay_ms(speed);
        FAN_PWM_PIN = 0;
        delay_ms(10 - speed);
    }
}

void main() {
    LCD_Init();
    DS18B20_Init();
    EEPROM_Init();
    
    LCD_String("Room Thermostat");
    delay_ms(1000);
    LCD_Clear();
    
    // Load thresholds from EEPROM
    highThreshold = EEPROM_Read(0x00);
    lowThreshold = EEPROM_Read(0x01);
    
    // Default if EEPROM empty
    if (highThreshold == 0xFF) highThreshold = HIGH_TEMP_THRESHOLD;
    if (lowThreshold == 0xFF) lowThreshold = LOW_TEMP_THRESHOLD;
    
    while(1) {
        currentTemp = DS18B20_ReadTemp();
        
        LCD_Command(0x80);
        LCD_String("Temp: ");
        LCD_Integer(currentTemp);
        LCD_Char(223); // ° symbol
        LCD_Char('C');
        
        // Fan control logic
        if (currentTemp >= highThreshold) {
            LCD_Command(0xC0);
            LCD_String("Fan: HIGH   ");
            PWM_Fan_Control(8);
        } 
        else if (currentTemp >= lowThreshold) {
            LCD_Command(0xC0);
            LCD_String("Fan: MEDIUM ");
            PWM_Fan_Control(5);
        } 
        else {
            LCD_Command(0xC0);
            LCD_String("Fan: LOW    ");
            PWM_Fan_Control(2);
        }
        
        delay_ms(500);
    }
}
