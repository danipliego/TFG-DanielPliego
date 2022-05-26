#define heartratePin A1
#include "DFRobot_Heartrate.h"
DFRobot_Heartrate heartrate(DIGITAL_MODE);  //comentar si quieres ECG


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //Analog_ECG(); //Descomentar si quieres ECG y poner el sensor en modo analógico

  Digital_Pulsaciones();//tener el sensor en modo digital
}

void Analog_ECG() { //funcion para dibujar ECG
   int sensorValue = analogRead(A1);
   Serial.println(sensorValue);
   delay(10);
}

void Digital_Pulsaciones(){ //funcino para medir ppm
  uint8_t ppm;
  heartrate.getValue(heartratePin);
  ppm = heartrate.getRate();
  if(ppm){
    Serial.println(ppm);
    Serial.print("DATA,TIME,DATE,"); //funcion para guardarlo en qx
  }
  delay(100);
}
