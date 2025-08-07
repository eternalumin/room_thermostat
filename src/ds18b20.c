#include <reg51.h>
#include "ds18b20.h"

sbit DQ = P2^0; // DS18B20 Data Pin

void delay_us(unsigned int us) {
    while(us--);
}

void DS18B20_Init() {
    DQ = 1;
    delay_us(5);
}

unsigned char DS18B20_ReadTemp() {
    // Simulated fixed temperature value for Proteus
    return 28; 
}
