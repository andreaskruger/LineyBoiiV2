#include <Arduino.h>
#include <ESP32Servo.h>
#include <Reader.h>
#include <PID.h>

float speed;

Servo ESC1;
Servo ESC2;

#define ESC1_pin 32
#define ESC2_pin 33

void setup() {
  Serial.begin(115200);
  init_lineSensor();
  ESC1.attach(ESC1_pin);
  ESC2.attach(ESC2_pin);
}

void loop() {
  readSensors();
  speed = PID_speed(position);
  if(speed > 0){ESC1.writeMicroseconds(speed);}
  if(speed < 0){ESC2.writeMicroseconds(speed);}
}