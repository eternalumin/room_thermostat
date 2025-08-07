#include "eeprom.h"

void EEPROM_Init() {
    // Simulation only - nothing to init
}

void EEPROM_Write(unsigned char addr, unsigned char data) {
    // Simulation only - pretend write
}

unsigned char EEPROM_Read(unsigned char addr) {
    // Simulation - return default values
    return 0xFF;
}
