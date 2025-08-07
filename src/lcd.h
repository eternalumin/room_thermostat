#ifndef LCD_H
#define LCD_H

void LCD_Init();
void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char dat);
void LCD_String(char *str);
void LCD_Integer(unsigned int num);
void LCD_Clear();

#endif
