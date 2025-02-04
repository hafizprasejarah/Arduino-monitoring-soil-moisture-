#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int sensorPin = A0;  
int powerPin = 8;    
const int dryThreshold = 300;  
const int wetThreshold = 700;  
const int maxThreshold = 1024; 
 
void setup() { 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight(); 

  pinMode(powerPin, OUTPUT);

  digitalWrite(powerPin, LOW);

  Serial.begin(9600);
}
 
void loop() {



  int sensorValue = bacaSensor(); 
  float rh; 
  String message;

  // Determine soil moisture status
      if (sensorValue <= dryThreshold) {
        rh = 0; // Very dry

    } else if (sensorValue <= wetThreshold) {
        // Interpolate moisture percentage

       message = Serial.println("Status: Lembap");
    } else if (sensorValue <= maxThreshold) {
        rh = 100; // Very wet

    } else {
        rh = 0; // Invalid reading
    
    }

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor:");
  lcd.print(readSensor());
  lcd.setCursor(0, 1);
  lcd.print("RH:");
  lcd.print(rh);
  lcd.print("%");
  lcd.setCursor(9,0);
  lcd.print(",Status:");
  lcd.setCursor(10,1); 
  delay(2000); // Wait for 2 seconds

}
 
int readSensor() {
  
  digitalWrite(powerPin, HIGH);
  delay(500);

  int nilaiSensor = analogRead(sensorPin);
  digitalWrite(powerPin, LOW);

 return 1023 - nilaiSensor;
}
