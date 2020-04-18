#include <IRremote.h>

#define RECV_PIN 7

//Change these values to match data sent by your remote control
/*-----COMMANDS------*/
#define COMMAND_POWER         3225354495 // 0xC03F00FF
#define COMMAND_TV            3651225872 // 0xD9A14910
#define COMMAND_FM            3225414165 // 0xC03FEA15
#define COMMAND_DVD           3225361125 // 0xC03F1AE5

#define COMMAND_RED           3225408045 // 0xC03FD22D
#define COMMAND_GREEN         3225367245 // 0xC03F32CD
#define COMMAND_YELLOW        3225399885 // 0xC03FB24D
#define COMMAND_BLUE          3225383565 // 0xC03F728D

#define COMMAND_TELETEXT      3225417735 // 0xC03FF807
#define COMMAND_SLEEP         3225355005 // 0xC03F02FD
#define COMMAND_MUTE          3225364695 // 0xC03F28D7
#define COMMAND_BOSS          3225391725 // 0xC03F926D

#define COMMAND_CHANNEL_UP    3225366735 // 0xC03F30CF
#define COMMAND_CHANNEL_DOWN  3225356535 // 0xC03F08F7
#define COMMAND_VOLUME_UP     3225362655 // 0xC03F20DF
#define COMMAND_VOLUME_DOWN   3225358575 // 0xC03F10EF
#define COMMAND_ENTER         3225405495 // 0xC03FC837

#define COMMAND_FULLSCREEN    3225403455 // 0xC03FC03F
#define COMMAND_MENU          3225416205 // 0xC03FF20D
#define COMMAND_C             3225357045 // 0xC03F0AF5

#define COMMAND_PLAY          3225403965 // 0xC03FC23D
#define COMMAND_STOP          3225379485 // 0xC03F629D
#define COMMAND_SKIP_FORWARD  3225363165 // 0xC03F22DD
#define COMMAND_SKIP_BACKWARD 3225371325 // 0xC03F42BD
#define COMMAND_SEEK_FORWARD  3225397845 // 0xC03FAA55
#define COMMAND_SEEK_BACKWARD 3225365205 // 0xC03F2AD5

#define COMMAND_CH_1          3225395295 // 0xC03FA05F
#define COMMAND_CH_2          3225378975 // 0xC03F609F
#define COMMAND_CH_3          3225411615 // 0xC03FE01F
#define COMMAND_CH_4          3225391215 // 0xC03F906F
#define COMMAND_CH_5          3225374895 // 0xC03F50AF
#define COMMAND_CH_6          3225407535 // 0xC03FD02F
#define COMMAND_CH_7          3225399375 // 0xC03FB04F
#define COMMAND_CH_8          3225383055 // 0xC03F708F
#define COMMAND_CH_9          3225415695 // 0xC03FF00F
#define COMMAND_CH_0          3225372855 // 0xC03F48B7

#define COMMAND_PIP           3225375405 // 0xC03F52AD
#define COMMAND_REC           3225412125 // 0xC03FE21D

#define REPEAT_COMMAND        4294967295 // 0xFFFFFFFF
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
      case COMMAND_VOLUME_UP:
      case COMMAND_VOLUME_DOWN:
        if(repeat_counter%2==0)
          Serial.println(command);
        break;
      case COMMAND_POWER:
      case COMMAND_TV:
      case COMMAND_FM:
      case COMMAND_DVD:
      
      case COMMAND_RED:
      case COMMAND_GREEN:
      case COMMAND_YELLOW:
      case COMMAND_BLUE:

      case COMMAND_TELETEXT:
      case COMMAND_SLEEP:
      case COMMAND_MUTE:
      case COMMAND_BOSS:

      case COMMAND_CHANNEL_UP:
      case COMMAND_CHANNEL_DOWN:
      case COMMAND_ENTER:

      case COMMAND_FULLSCREEN:
      case COMMAND_MENU:
      case COMMAND_C:
      
      case COMMAND_PLAY:
      case COMMAND_SKIP_FORWARD:
      case COMMAND_SKIP_BACKWARD:
      case COMMAND_SEEK_FORWARD:
      case COMMAND_SEEK_BACKWARD:

      case COMMAND_CH_1:
      case COMMAND_CH_2:
      case COMMAND_CH_3:
      case COMMAND_CH_4:
      case COMMAND_CH_5:
      case COMMAND_CH_6:
      case COMMAND_CH_7:
      case COMMAND_CH_8:
      case COMMAND_CH_9:
      case COMMAND_CH_0:

      case COMMAND_PIP:
      case COMMAND_REC:
        if(repeat_counter == 0)
          Serial.println(command);
        break;
    }
    
    delay(100);
    irrecv.resume();
  }
}
