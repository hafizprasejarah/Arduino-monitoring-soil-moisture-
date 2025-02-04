This project is a simple soil moisture monitoring system using an Arduino, a soil moisture sensor, and an LCD display with I2C communication. The system reads the soil moisture level and displays the readings on an LCD screen. The data can also be sent to the serial monitor for further analysis.

Components Used :

1. Arduino Board (Uno, Mega, etc.)

2. Soil Moisture Sensor

3. LCD Display (16x2) with I2C module

4. Jumper Wires



Libraries Used:

This project uses the LiquidCrystal_I2C library to control the LCD display via I2C communication.



Installing LiquidCrystal_I2C Library:

1. Open Arduino IDE.

2. Go to Sketch → Include Library → Manage Libraries.

3. Search for LiquidCrystal_I2C.

4. Install the appropriate library.



How to Use :

1. Connect the components as per the wiring diagram.

2. Upload the code to the Arduino.

3. Open the Serial Monitor to view the readings.

4. Observe the LCD display for moisture levels.

Notes :

The I2C address may need adjustment depending on the LCD module.

The delay in readSensor() ensures accurate readings.

Modify the dryThreshold and wetThreshold based on your soil conditions.
