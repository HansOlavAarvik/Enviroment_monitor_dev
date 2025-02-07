#ifndef TEMP_HUMID_SENSOR_H
#define TEMP_HUMID_SENSOR_H

#include "main.h"

extern I2C_HandleTypeDef hi2c1;

typedef struct {
    float temperature;
    float humidity;
} AHT20_Data;

HAL_StatusTypeDef AHT20_Init(void);
HAL_StatusTypeDef AHT20_Read(AHT20_Data* data);


void read_humid_temp();
    
#endif