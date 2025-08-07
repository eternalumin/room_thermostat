#ifndef EEPROM_H
#define EEPROM_H

void EEPROM_Init();
void EEPROM_Write(unsigned char addr, unsigned char data);
unsigned char EEPROM_Read(unsigned char addr);

#endif
