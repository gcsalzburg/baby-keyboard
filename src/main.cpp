/* Baby Keyboard */
   
#include <Arduino.h>
#include <PS2Keyboard.h>

const int pin_data = 2;
const int pin_IRQ =  3;

PS2Keyboard keyboard;

uint8_t baby_letter = 0;
uint8_t num_aaas = 1;

const uint8_t min_a = 2;
const uint8_t max_a = 10;
uint8_t letter_a = 0;

void speak_baby();

void setup() {
  delay(1000);
  keyboard.begin(pin_data, pin_IRQ);
  Serial.begin(115200);
}

void loop() {
	if (keyboard.available()) {
		char c = keyboard.read();
		speak_baby();
  	}
}

void speak_baby(){
	switch(baby_letter){
		case 0:
			Serial.print('w');
			baby_letter++;
			num_aaas = random(min_a, max_a);
			break;
		case 1:
			Serial.print('a');
			letter_a++;
			if(letter_a >= num_aaas){
				baby_letter++;
			}
			break;
		case 2:
			Serial.print(' ');
			baby_letter = 0;
			break;
	}
}