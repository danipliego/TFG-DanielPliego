 int valLum;
 float valTemp;
 float valHum;
 #include "DHT.h"
 #define DHTPIN 2     // Pin donde está conectado el sensor
#define DHTTYPE DHT22   // Sensor DHT22
 DHT dht(DHTPIN, DHTTYPE); //Serial Port en 9600
 
void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  dht.begin();
}
void loop()
{
   
      valLum=analogRead(A0);   //connect grayscale sensor to Analog 0
      Serial.print("DATA,TIME,DATE,Luminosidad,");
      Serial.println(valLum);//print the value to serial
       valHum = dht.readHumidity(); //Leemos la Humedad
       valTemp = dht.readTemperature(); //Leemos la temperatura en grados Centigrados
       Serial.print("DATA,TIME,DATE,Temperatura,");
      Serial.println(valTemp);//print the value to serial
       Serial.print("DATA,TIME,DATE,Humedad,");
      Serial.println(valHum);//print the value to serial
      delay(5000);
}
