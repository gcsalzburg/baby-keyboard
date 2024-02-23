/* Baby Keyboard */
   
#include <Arduino.h>
#include <Keyboard.h>
#include <PS2Keyboard.h>

const int pin_data = 2;
const int pin_IRQ =  3;

PS2Keyboard ps2keyboard;

uint8_t baby_letter = 0;
uint8_t num_aaas = 1;

const uint8_t min_a = 1;
const uint8_t max_a = 7;
uint8_t letter_a = 0;

void speak_baby();

void setup() {
  delay(1000);
  ps2keyboard.begin(pin_data, pin_IRQ);

	Keyboard.begin();
}

void loop() {
	if (ps2keyboard.available()) {
		ps2keyboard.read();
		speak_baby();
  	}
}

void speak_baby(){
	switch(baby_letter){
		case 0:
			Keyboard.write('w');
			baby_letter++;
			num_aaas = random(min_a, max_a);
			letter_a = 0;
			break;
		case 1:
			Keyboard.write('a');
			letter_a++;
			if(letter_a >= num_aaas){
				baby_letter++;
			}
			break;
		case 2:
			Keyboard.write(' ');
			baby_letter = 0;
			break;
	}
}