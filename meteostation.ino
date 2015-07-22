//Old meteostation project
#include <LiquidCrystal.h>
#include <Wire.h>
#include <BMP085.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT22   
BMP085 dps = BMP085();
long Temperature = 0, Pressure = 0, Altitude = 0;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
const int but1 = 13;
boolean state = LOW;
boolean lastState = LOW;
int flag = 0;
int regim = 0;

void setup(void)
{
   Wire.begin();
   lcd.begin(16, 2);
   dht.begin(); 
   delay(1000);
   dps.init();
   pinMode(but1, INPUT);
}
void loop(void)

{
  state = digitalRead(but1);
  if (state == HIGH && flag == 0){
 regim ++;
 flag = 1;
 if (regim > 1){
  regim =0;}
 }
 
      if (state == HIGH && flag == 1)
{
  flag = 0;
}
   if(regim == 0)
    {
  dps.getPressure(&Pressure);
  dps.getAltitude(&Altitude); 
  dps.getTemperature(&Temperature);
  lcd.clear();
  lcd.print("Pressure: ");
  lcd.print(Pressure/133.3);
  lcd.setCursor(0, 1);
  lcd.print("Board temp: ");
  lcd.print(Temperature*0.1);
  delay(100);
    }
       if(regim == 1)
      {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
   lcd.clear();
   lcd.print("Ext Temp: ");
   lcd.print(t);
   lcd.setCursor(0, 1);
   lcd.print("Hum: ");
   lcd.print(h);
   lcd.print(" %\t"); 
   delay(100);
  }
}

