#include <NewPing.h>               // Include the NewPing library for ultrasonic sensor
#include <Wire.h>                  // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>     // Include the LiquidCrystal_I2C library for the LCD

#define TRIGGER_PIN  2            // Define the trigger pin of the ultrasonic sensor
#define ECHO_PIN     3            // Define the echo pin of the ultrasonic sensor
#define MAX_DISTANCE 200          // Define the maximum distance to measure (in centimeters)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // Create a NewPing object
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize the LCD with I2C address 0x27

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
}

void loop() {
  delay(50);  // Wait for 50 milliseconds

  unsigned int distance = sonar.ping_cm();  // Get the distance measured by the ultrasonic sensor (in centimeters)

  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);  // Set cursor to the first column of the first row
  lcd.print("Distance: ");  // Print "Distance: " on the LCD
  lcd.print(distance);  // Print the distance measured on the LCD
  lcd.print(" cm");  // Print " cm" on the LCD
}
