#include <Arduino.h>


#define s1 1
#define s2 2
#define s3 3
#define s4 4


#define sensorRead_pin 5
int sensPins[4] = {1,2,3,4};
int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
};

float lineValue[16];
float position;

void init_lineSensor(){
    pinMode(s1,OUTPUT);
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);
    pinMode(s4,OUTPUT);
}

void readSensors(){
    for(int j = 0; j < 15; j++){
        for(int i = 0; i < 4; i ++){
            digitalWrite(sensPins[i], muxChannel[j][i]);
        }
    lineValue[j];
    }
}

float getValue(int index){
    return lineValue[index];
}
float getPosition(){
    lineValue[0] = lineValue[0]*8;
    lineValue[1] = lineValue[1]*7;
    lineValue[2] = lineValue[2]*6;
    lineValue[3] = lineValue[3]*5;
    lineValue[4] = lineValue[4]*4;
    lineValue[5] = lineValue[5]*3;
    lineValue[6] = lineValue[6]*2;
    lineValue[7] = lineValue[7]*1;
    lineValue[8] = lineValue[8]*-1;
    lineValue[9] = lineValue[9]*-2;
    lineValue[10] = lineValue[10]*-3;
    lineValue[11] = lineValue[11]*-4;
    lineValue[12] = lineValue[12]*-5;
    lineValue[13] = lineValue[13]*-6;
    lineValue[14] = lineValue[14]*-7;
    lineValue[15] = lineValue[15]*-8;
    position = 0;
    for(int i; i < 15; i++){
        position += lineValue[i];
    }
    return position;
}