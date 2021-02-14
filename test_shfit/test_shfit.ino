int latchPinH = 3;
int clockPinH = 2;
int dataPinH = 4;
int latchPinM = 6;
int clockPinM = 5;
int dataPinM = 7;
int latchPinS = 9;
int clockPinS = 8;
int dataPinS = 10;
byte zero = 0b1000;
byte one = 0b0000;
byte two = 0b0010;
byte three = 0b0001;
byte four = 0b0100;
byte five = 0b0110;
byte six = 0b1010;
byte seven = 0b1001;
byte eight = 0b1100;
byte nine = 0b1110;

byte nums[] = {0b10001000, 0b00000000, 0b00100010, 0b00010001, 0b01000100, 0b01100110, 0b10101010, 0b10011001, 0b11001100, 0b11101110};


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPinS, OUTPUT);
  pinMode(clockPinS, OUTPUT);
  pinMode(dataPinS, OUTPUT);
  pinMode(latchPinM, OUTPUT);
  pinMode(clockPinM, OUTPUT);
  pinMode(dataPinM, OUTPUT);
  pinMode(latchPinH, OUTPUT);
  pinMode(clockPinH, OUTPUT);
  pinMode(dataPinH, OUTPUT);
}

void loop() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    digitalWrite(latchPinS, LOW);
    digitalWrite(latchPinM, LOW);
    digitalWrite(latchPinH, LOW);
    shiftOut(dataPinS, clockPinS, LSBFIRST, 0b00000000);
    shiftOut(dataPinM, clockPinM, LSBFIRST, 0b00000000);
    shiftOut(dataPinH, clockPinH, LSBFIRST, 0b00000000);
    digitalWrite(latchPinS, HIGH);
    digitalWrite(latchPinM, HIGH);
    digitalWrite(latchPinH, HIGH);
    delay(1000);
    
}
  
}
