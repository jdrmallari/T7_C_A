void function setup() {
    pinMode(wheel_L_FORWARD, OUTPUT);
    pinMode(wheel_L_BACK, OUTPUT);
    pinMode(wheel_R_FORWARD, OUTPUT);
    pinMode(wheel_R_BACK, OUTPUT);
    Serial.begin(9600);
}

void function readInput() {
	input = Serial.Read();
	
	switch(input) {
		case(F):
			moveForward();
		case(B):
			moveBackward();
		case(L):
			moveLeft();
		case(R):
			moveRight();
		case(START):
			start();
		case(EXIT):
			exit();		
	}
}


void function moveForward() {
	digitalWrite( wheel_L_FORWARD, HIGH);
   	digitalWrite( wheel_L_BACK, LOW);
   	digitalWrite( wheel_R_FORWARD, HIGH);
   	digitalWrite( wheel_R_BACK, LOW);
}

void function moveBackward() {
	digitalWrite( wheel_L_FORWARD, LOW);
   	digitalWrite( wheel_L_BACK, HIGH);
   	digitalWrite( wheel_R_FORWARD, LOW);
   	digitalWrite( wheel_R_BACK, HIGH);
}

