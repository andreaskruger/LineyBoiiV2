#include <Arduino.h>


double Kp = 0.01;  
double Kd = 0;
double ki = 0;
double currentTime=0;
double lastTime = 0;
double lastError = 0;
double eTime = 0;
double cum = 0;
float baseLineSpeedL = 1100;
float baseLineSpeedR = 1900;

float motor(float speed){
    if(speed <0){
        speed = baseLineSpeedL + speed;
    }
    if(speed >=0){
        speed = baseLineSpeedR - speed;
    }
    return speed;
}

float PID_speed(int position){
   int error = position - 1000;
   currentTime = millis();
   eTime = currentTime - lastTime;
   cum = cum + error*eTime;
   int motorSpeed = Kp * error + Kd * ((error - lastError)/(eTime))+ ki*(cum);
   lastError = error;
   lastTime = currentTime;
   motorSpeed = motor(motorSpeed);
   return motorSpeed;
}