#include <IRremote.h>

#define RECV_PIN 7

/*-----COMMANDS------*/
#define COMMAND_CH_PREV   16753245 // 0xFFA25D
#define COMMAND_CH        16736925 // 0xFF629D
#define COMMAND_CH_NEXT   16769565 // 0xFFE21D

#define COMMAND_PREV      16720605 // 0xFF22DD
#define COMMAND_NEXT      16712445 // 0xFF02FD
#define COMMAND_PLAY      16761405 // 0xFFC23D

#define COMMAND_VOL_DOWN  16769055 // 0xFFE01F
#define COMMAND_VOL_UP    16754775 // 0xFFA857
#define COMMAND_EQ        16748655 // 0xFF906F

#define COMMAND_CH_0      16738455 // 0xFF6897
#define COMMAND_CH_100_UP 16750695 // 0xFF9867
#define COMMAND_CH_200_UP 16756815 // 0xFFB04F
#define COMMAND_CH_1      16724175 // 0xFF30CF
#define COMMAND_CH_2      16718055 // 0xFF18E7
#define COMMAND_CH_3      16743045 // 0xFF7A85
#define COMMAND_CH_4      16716015 // 0xFF10EF
#define COMMAND_CH_5      16726215 // 0xFF38C7
#define COMMAND_CH_6      16734885 // 0xFF5AA5
#define COMMAND_CH_7      16728765 // 0xFF42BD
#define COMMAND_CH_8      16730805 // 0xFF4AB5
#define COMMAND_CH_9      16732845 // 0xFF52AD

#define REPEAT_COMMAND 4294967295 // 0xFFFFFFFF
/*-----END COMMANDS------*/

unsigned long command = 0;
unsigned long last_command = 0;
int repeat_counter = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    // Serial.println(results.value);
    // Serial.println(results.value, HEX);
    
    command = results.value; //fetch received data
    
    if(command == REPEAT_COMMAND) {
      command = last_command;
      repeat_counter++;
    } else {
      last_command = command;
      repeat_counter = 0;
    }
    
    switch(command) {
      case COMMAND_VOL_DOWN:
      case COMMAND_VOL_UP:
        if(repeat_counter%2==0)
          Serial.println(command);
        break;
      case COMMAND_CH_PREV:
      case COMMAND_CH:
      case COMMAND_CH_NEXT:

      case COMMAND_PREV:
      case COMMAND_NEXT:
      case COMMAND_PLAY:

      case COMMAND_EQ:

      case COMMAND_CH_0:
      case COMMAND_CH_100_UP:
      case COMMAND_CH_200_UP:
      case COMMAND_CH_1:
      case COMMAND_CH_2:
      case COMMAND_CH_3:
      case COMMAND_CH_4:
      case COMMAND_CH_5:
      case COMMAND_CH_6:
      case COMMAND_CH_7:
      case COMMAND_CH_8:
      case COMMAND_CH_9:
        if(repeat_counter == 0)
          Serial.println(command);
        break;
    }

    delay(100);
    irrecv.resume();
  }
}
