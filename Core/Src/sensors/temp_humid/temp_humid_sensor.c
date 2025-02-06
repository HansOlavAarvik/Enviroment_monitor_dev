#include "temp_humid_sensor.h"
#include  "../../Inc/main.h"

void read_humid_temp(){
    HAL_GPIO_TogglePin(LED2_GPIO_PORT,LED2_PIN);
    HAL_Delay(50);
    HAL_GPIO_TogglePin(LED1_GPIO_PORT,LED1_PIN);
    HAL_Delay(2000);
    HAL_GPIO_TogglePin(LED3_GPIO_PORT,LED3_PIN);
    HAL_Delay(100);
} 

