# Enviroment_monitor_dev

## Setup
   ```bash
   git clone <your-repository>
   cd <your-project>
   python setup.py
   ```

## short description of project
Enviromental monetring divice used for monitoring conditions in eletrical cabinets. Records sound, vibrations, if the door is opened (with tof), inside temperature, inside humidity, outside humidity, and outside temperature. The sensors are controlled with a STM32. Power and communication is done over ethernet. There are also some LED's and a buzzer that gives feedback to on-site opperators. Data processing is done on server, only recording, transmission, recieving and and signals to LED's/buzzer is controlled by microcontroller.

## Useful links:
https://community.st.com/t5/stm32-mcus/helpful-tips-on-using-vs-code-with-stm32/ta-p/751213

## Spesifics on recordings: 
### Aucustics: 
-48Khz sampeling rate, 16 bit recording
-Uses I2S bus
### Humidity / temperature:
-1hz sampeling rate, 8 bit recording
-Uses I2C bus
### Vibration:
-6Khz sampeling rate, 8 bit recording
-Uses I2C bus
### Time of light:
-1hz sampeling rate, 8 bit recording
-Uses I2C bus


# Pin layout:
-I2C1_SDA   --  PB9
-I2C1_SCL   --  PB8