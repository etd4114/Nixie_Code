#include "MD_DS1307.h"


#define latchPinH 3
#define clockPinH 2
#define dataPinH 4
#define latchPinM 6
#define clockPinM 5
#define dataPinM 7
#define latchPinS 9
#define clockPinS 8
#define dataPinS 10
#define SDA 14
#define SCL 15

#define zero 0b1000 
#define one 0b0000
#define two 0b0010
#define three 0b0001
#define four 0b0100
#define five 0b0110
#define six 0b1010
#define seven 0b1001
#define eight 0b1100
#define nine 0b1110

int hour;
int minute;
int second;

int onesS;
int tensS;
int onesM;
int tensM;
int onesH;
int tensH;

byte hourB;
byte minuteB;
byte secondB;

byte byteDecode (int time) {
  switch (time) {
    case 0:
      return zero;
      break;
    case 1:
      return one;
      break;
    case 2:
      return two;
      break;
    case 3:
      return three;
      break;
    case 4:
      return four;
      break;
    case 5:
      return five;
      break;
    case 6:
      return six;
      break;
    case 7:
      return seven;
      break; 
    case 8:
      return eight;
      break;
    case 9:
      return nine;
      break;
  }
}

byte byteCombine (int timeOne, int timeTwo) {
  byte t1 = byteDecode(timeOne);
  byte t2 = byteDecode(timeTwo);
  t1 = (t1 << 4);
  return ((0b00000000 | t1) | t2);
}

void setup() {
  pinMode(latchPinS, OUTPUT);
  pinMode(clockPinS, OUTPUT);
  pinMode(dataPinS, OUTPUT);
  pinMode(latchPinM, OUTPUT);
  pinMode(clockPinM, OUTPUT);
  pinMode(dataPinM, OUTPUT);
  pinMode(latchPinH, OUTPUT);
  pinMode(clockPinH, OUTPUT);
  pinMode(dataPinH, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);
  Serial.begin(9600);
//yyyy, mm, dd, h, m, s, dow, pm
}

void loop() {
  RTC.readTime();
  hour = RTC.h;
  minute = RTC.m;
  second = RTC.s;
  tensH = (hour / 10) % 10;
  onesH = hour % 10;
  tensM = (minute / 10) % 10;
  onesM = minute % 10;
  tensS = (second / 10) % 10;
  onesS = second % 10;
  secondB = byteCombine(onesS, tensS);
  minuteB = byteCombine(onesM, tensM);
  hourB = byteCombine(onesH, tensH);
  digitalWrite(latchPinS, LOW);
  digitalWrite(latchPinM, LOW);
  digitalWrite(latchPinH, LOW);
  shiftOut(dataPinS, clockPinS, LSBFIRST, secondB);
  shiftOut(dataPinM, clockPinM, LSBFIRST, minuteB);
  shiftOut(dataPinH, clockPinH, LSBFIRST, hourB);
  digitalWrite(latchPinS, HIGH);
  digitalWrite(latchPinM, HIGH);
  digitalWrite(latchPinH, HIGH);  
}
