
//THIS IS JUST TO GET THE COMPILER TO STOP GIVING WARNINGS
const int WHEEL_L_FORWARD = 0;
const int WHEEL_L_BACK = 0;
const int WHEEL_R_FORWARD = 0;
const int WHEEL_R_BACK = 0;
const int HIGH = 1;
const int LOW = 0;
const int OUTPUT = 0;
const int PIN1 = 0;
const int PIN2 = 0;
const int OPEN_DEGREE = 0;
const int CLOSE_DEGREE = 0;

class Serial {
    public:
        void begin(int a) {};
        char read(){return 'a';};
};

class Servo {
    public:
        void write(int a) {};
};

class Encoder {
    public:
        Encoder(int a, int b) {};
        int read() {return 1;};
};

Serial serial;
Servo servo;

void delay(int a) {};

void digitalWrite(int a, int b) {

}

void pinMode(int a, int b) {
}

void moveLeft(){};
void moveRight(){};
void start(){};
void stop(){};

//END OF WARNING CODE

void setup() {
    pinMode(WHEEL_L_FORWARD, OUTPUT);
    pinMode(WHEEL_L_BACK, OUTPUT);
    pinMode(WHEEL_R_FORWARD, OUTPUT);
    pinMode(WHEEL_R_BACK, OUTPUT);
    serial.begin(9600);
}

void moveForward() {
    digitalWrite(WHEEL_L_FORWARD, HIGH);
    digitalWrite(WHEEL_L_BACK, LOW);
    digitalWrite(WHEEL_R_FORWARD, HIGH);
    digitalWrite(WHEEL_R_BACK, LOW);
}

void moveBackward() {
    digitalWrite(WHEEL_L_FORWARD, LOW);
    digitalWrite(WHEEL_L_BACK, HIGH);
    digitalWrite(WHEEL_R_FORWARD, LOW);
    digitalWrite(WHEEL_R_BACK, HIGH);
}

void readInput() {
    char input = serial.read();
    switch(input) {
        case('a'):
            moveForward();
            break;
        case('b'):
            moveBackward();
            break;
        case('c'):
            moveLeft();
            break;
        case('d'):
            moveRight();
            break;
        case('e'):
            start();
            break;
        case('f'):
            stop();
            break;
        case('g'):
            disposal(true);
            break;
        case('h'):
            disposal(false);
            break;
    }
}


Encoder rotarycs(PIN1, PIN2);
int rotaryPos = 0; // Initial encoder position

void loop() {
    int newPos;
    newPos = rotarycs.read();
    if (newPos != rotaryPos)
        rotaryPos = newPos;
}

void disposal(bool open) {
    if(open) {
        servo.write(OPEN_DEGREE); // Turn the servo to its proper angle
    }
    else {
        servo.write(CLOSE_DEGREE);
    }
    delay(100); //	Delay a period of time for servo to rotate to the corresponding position
}
