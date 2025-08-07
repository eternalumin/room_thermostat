#include <reg51.h>
#include "lcd.h"

#define LCD P3
sbit RS = P2^1;
sbit EN = P2^2;

void delay_ms(unsigned int ms) {
    unsigned int i,j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void LCD_Command(unsigned char cmd) {
    LCD = cmd;
    RS = 0;
    EN = 1;
    delay_ms(2);
    EN = 0;
}

void LCD_Char(unsigned char dat) {
    LCD = dat;
    RS = 1;
    EN = 1;
    delay_ms(2);
    EN = 0;
}

void LCD_String(char *str) {
    while(*str) {
        LCD_Char(*str++);
    }
}

void LCD_Integer(unsigned int num) {
    char buffer[5];
    buffer[0] = (num/10) + '0';
    buffer[1] = (num%10) + '0';
    buffer[2] = '\0';
    LCD_String(buffer);
}

void LCD_Init() {
    LCD_Command(0x38); // 8-bit, 2 lines
    LCD_Command(0x0C); // Display ON, Cursor OFF
    LCD_Command(0x06); // Auto increment
    LCD_Command(0x01); // Clear display
}

void LCD_Clear() {
    LCD_Command(0x01);
}
