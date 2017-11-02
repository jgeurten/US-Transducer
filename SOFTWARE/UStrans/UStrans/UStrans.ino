#include <Wire.h>
#include <Adafruit_MotorShield.h>
import processing.serial.*; 
#create stepper objects:
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *xMotor = AFMS.getStepper(200, 1); //23Hs22 motor
Adafruit_StepperMotor *yMotor = AFMS.getStepper(?. 2);  //Vexta motor



int maxValue = 0; 
int xStopPin = 2; //2 or 3 for arduino uno
int yStopPin = 3; 

void setup() {
  Serial port; 
  Table dataTable; 
  String portName = Serial.list()[2];   //Arduino port number
  port = new Serial(this, portName, 115200); 

  table.addColumn("X"); 
  table.addColumn("Y"); 
  table.addColumn("Z"); 
  xMotor->setSpeed(100);
  yMotor->setSpeed(100); 

  attachInterrupt(digitalPinToInterrupt(xStopPin), xStopISR, RISING);   //limit for the xmotor
  attachInterrupt(digitalPinToInterrupt(yStopPin), yStopISR, RISING);   //limit for the ymotor
}

void stopISR()
{
  
}

int homeMode()
{
  
}
void loop() {
  
  if(Serial.available() > 0)  //received data from PySerial
  {
    int incomingByte = Serial.read(); 
    if(incomingByte == 1)
    {
      if(homeMode() == 1)
        scan(); 
    }
}

 
