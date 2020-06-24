#include <Servo.h>


//COMPONENTS
//=================================
//TEMPERATURE SENSOR
//  LM35

//CONSTANTS
//=================================
//Thermometer
const int sensorPin = A0;  //Temperature input pin
int val;                   //Value read from thermometer
//Servo
Servo myservo;
int maxPosition = 0;  //Lid is open
int minPosition = 145;  //Lid is closed
//Control Constants
//==================================
int minTemperature = 26;  //Below temp, lid closed
int maxTemperature = 28;  //Above temp, lid open


void setup() {
  // put your setup code here, to run once:
  //If laptop is there
  Serial.begin(9600);
  
  //Servo Setup
  myservo.attach(9);    //Attach to pin 9
  
}


void loop() {
  // put your main code here, to run repeatedly:
  //READ TEMPERATURE
  val = analogRead(sensorPin);
  float mv = (val/1023.0)*5000;
  float cel = mv/10;

  //PRINTING 
  Serial.print("Temperature = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();

  //ADJUSTING LID
  //If it is colder
  if(cel < minTemperature){
    servo.write(minPosition);
  }
  //If it is hotter
  if(cel > maxTemperature){
    servo.write(maxPosition);
  }
}
