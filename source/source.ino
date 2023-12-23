// Circuit Connection
// Servo to pin D4
// LDR 1 to A0
// LDR 2 to A1

#include <Servo.h>
#define ldr1 A0
#define ldr2 A1
Servo myservo;
int pos = 90;
int tolerance = 20;

void setup() {
  myservo.attach(4);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myservo.write(pos);
  delay(1000);
}

void loop() {
  int val1 = analogRead(ldr1);
  int val2 = analogRead(ldr2);

  if ((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
  } else {
    if (val1 > val2) {
      pos = pos + 1;
    }
    if (val1 < val2) {
      pos = pos - 1;
    }
  }

  if (pos > 180) {
    pos = 180;
  }
  if (pos < 0) {
    pos = 0;
  }
  myservo.write(pos);
  delay(50);
}
