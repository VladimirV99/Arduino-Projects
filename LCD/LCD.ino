#include <LiquidCrystal.h>

// Define the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
#define RS 4
#define EN 6

#define D4 10
#define D5 11
#define D6 12
#define D7 13

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message
  lcd.print("Hello, World!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

