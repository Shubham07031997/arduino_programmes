#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;


void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0x18A2: //Keypad button "1"
          digitalWrite(redPin, HIGH);
          delay(2000);
          digitalWrite(redPin, LOW);
          }

        switch(results.value){
          case 0x8A4: //Keypad button "2"
          digitalWrite(greenPin, HIGH);
          delay(2000);
          digitalWrite(greenPin, LOW);
          }

        irrecv.resume(); 
    }
}
