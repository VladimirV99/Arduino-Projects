// We have 8 segments: 7 for the digit and 1 for the decimal point
#define SEGMENTS 8
// Pin enumeration
#define PIN_A 0
#define PIN_B 1
#define PIN_C 2
#define PIN_D 3
#define PIN_E 4
#define PIN_F 5
#define PIN_G 6
#define PIN_DP 7
// Maximum number of digits we can have
#define MAX_DIGITS 4

// For a common cathode display we set power to HIGH to turn on a segment and LOW to select a digit
// For a common anode display switch these
#define SEGMENT_ON HIGH
#define SEGMENT_OFF LOW
#define DIGIT_ON LOW
#define DIGIT_OFF HIGH

// Number of digits
unsigned int num_digits = 0;
// Segment pins configuration
byte segment_pins[SEGMENTS];
// Digit pins configuration
byte digit_pins[MAX_DIGITS];

void setup() {
  // For the 5161AS sigle digit display
  unsigned int num_digits = 1;
  byte segment_pins[] = { 6, 5, 2, 3, 4, 7 ,8, 9 };
  byte digit_pins[] = {};
  init_pins(segment_pins, num_digits, digit_pins);

  // For the 5461AS four digit display
  /*
  unsigned int num_digits = 4;
  byte segment_pins[] = { 9, 2, 3, 5, 6, 8, 7, 4 };
  byte digit_pins[] = { 10, 11, 12, 13 };
  init_pins(segment_pins, num_digits, digit_pins);
  */
}

// Initialize the pins
void init_pins(byte segment_pins_in[], unsigned int num_digits_in, byte digit_pins_in[]) {
  for(int i = 0; i < SEGMENTS; i++) {
    segment_pins[i] = segment_pins_in[i];
  }
  num_digits = num_digits_in;
  for(int i = 0; i < num_digits; i++) {
    digit_pins[i] = digit_pins_in[i];
  }
  for(int i = 0; i < SEGMENTS; i++) {
    pinMode(segment_pins[i], OUTPUT);
  }
  for(int i = 0; i < num_digits; i++) {
    pinMode(digit_pins[i], OUTPUT);
  }
}

// Count to 9, clear the screen then reset
void loop() {
  for(int i = 0; i < 10; i++) {
    display_digit(i, 0);
    delay(1000);
  }
  clear_digit(0);
  delay(1000);
}

void select_digit(unsigned int position) {
  if(position >= num_digits)
    return;
  
  for(int i = 0; i < num_digits; i++) {
    if(i == position)
      digitalWrite(digit_pins[i], DIGIT_ON);
    else
      digitalWrite(digit_pins[i], DIGIT_OFF);
  }
}

void display_digit(unsigned int digit, unsigned int position) {
  if(digit > 9)
    return;
  
  select_digit(position);
  
  switch(digit) {
    case 0:
      display_configuration(0b11111100);
      break;
    case 1:
      display_configuration(0b01100000);
      break;
    case 2:
      display_configuration(0b11011010);
      break;
    case 3:
      display_configuration(0b11110010);
      break;
    case 4:
      display_configuration(0b01100110);
      break;
    case 5:
      display_configuration(0b10110110);
      break;
    case 6:
      display_configuration(0b10111110);
      break;
    case 7:
      display_configuration(0b11100000);
      break;
    case 8:
      display_configuration(0b11111110);
      break;
    case 9:
      display_configuration(0b11110110);
      break;
    default:
      clear_digit(position);
  }
}

void display_configuration(byte value) {
  for(int i = 0; i < SEGMENTS; i++) {
    if(value & (1 << (SEGMENTS-i-1))) {
      digitalWrite(segment_pins[i], SEGMENT_ON);
    } else {
      digitalWrite(segment_pins[i], SEGMENT_OFF);
    }
  }
}

void clear_digit(unsigned int position) {
  select_digit(position);
  display_configuration(0b00000000);
}

void show_decimal_point() {
  digitalWrite(segment_pins[PIN_DP], SEGMENT_ON);
}

void hide_decimal_point() {
  digitalWrite(segment_pins[PIN_DP], SEGMENT_OFF);
}