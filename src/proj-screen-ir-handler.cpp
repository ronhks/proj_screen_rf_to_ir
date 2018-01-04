#include <Arduino.h>
#include <HardwareSerial.h>
#include <Print.h>

#include "lib/irremote/IRremote.h"
#include "lib/rc-switch-2.6.2/RCSwitch.h"

unsigned long IR_UP = 2148467714;
unsigned long IR_DOWN = 2148467713;

unsigned long RF_UP = 12007330;
unsigned long RF_DOWN = 12007332;

int IR_PIN = 2;
int RF_PIN = 10;

IRrecv irrecv(IR_PIN);

decode_results results;

RCSwitch mySwitch = RCSwitch();

void setup() {
	irrecv.enableIRIn(); // Start the receiver
	mySwitch.enableTransmit(RF_PIN);
}

void loop() {
	if (irrecv.decode(&results)) {

		if (results.value == IR_UP) {

			mySwitch.send(RF_UP, 24);
			delay(100);

		} else if (results.value == IR_DOWN) {

			mySwitch.send(RF_DOWN, 24);
			delay(100);
		}

		irrecv.resume(); // Receive the next value
	}

	delay(200);
}
