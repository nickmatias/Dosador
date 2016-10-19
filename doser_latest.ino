#include<Servo.h>

Servo trig;
int lmin = 58  , lmax = 87;
int tdelay = 1000;
bool going = true;

void setup() {
  trig.attach(2);
  trig.write(87);
  pinMode(6, INPUT_PULLUP);

  Serial.begin(9600);
        Serial.println(trig.read());

}

void loop() {
  if (digitalRead(6) == LOW) {
    if (going) {
      //Serial.println("going");
      trig.write(lmax);
      going = false;
      delay(tdelay);
    }
    else {
      //Serial.println("not going");
      trig.write(lmin);
      going = true;
      delay(tdelay);
    }
  }
  else {
    //Serial.println("Stop!");
    trig.write(trig.read());
  }
}
