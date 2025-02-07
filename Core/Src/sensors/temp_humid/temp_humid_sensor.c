#include "temp_humid_sensor.h"
#include "main.h"

#define AHT20_ADDR 0x38

HAL_StatusTypeDef AHT20_Init(void) {
    uint8_t cmd = 0x71;
    
    if (HAL_I2C_Master_Transmit(&hi2c1, AHT20_ADDR << 1, &cmd, 1, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    HAL_Delay(40);
    
    return HAL_OK;
}

HAL_StatusTypeDef AHT20_Read(AHT20_Data* data) {
    uint8_t cmd[3] = {0xAC, 0x33, 0x00}; 
    uint8_t readData[7]; 
    
    if (HAL_I2C_Master_Transmit(&hi2c1, AHT20_ADDR << 1, cmd, 3, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }
    
    HAL_Delay(80);
    
    // Read data
    if (HAL_I2C_Master_Receive(&hi2c1, AHT20_ADDR << 1, readData, 7, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }
    
    // Check if measurement is ready (bit 7 of status byte should be 0)
    if (readData[0] & 0x80) {
        return HAL_BUSY;
    }
    // Calculate humidity
    uint32_t humidity_raw = ((uint32_t)readData[1] << 12) | ((uint32_t)readData[2] << 4) | (readData[3] >> 4);
    data->humidity = (float)humidity_raw * 100 / 0x100000;
    
    // Calculate temperature
    uint32_t temp_raw = ((uint32_t)(readData[3] & 0x0F) << 16) | ((uint32_t)readData[4] << 8) | readData[5];
    data->temperature = (float)temp_raw * 200 / 0x100000 - 50;
    
    return HAL_OK;
}