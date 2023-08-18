#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter;

unsigned long previousMillis = 0;
const unsigned long interval = 500;

void setup() {
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
  pinMode(8, OUTPUT);//Merah
  pinMode(9, OUTPUT);//Hijau
  
}

void loop() {
  float lux = lightMeter.readLightLevel();
  unsigned long currentMillis = millis();
  if(currentMillis-previousMillis > interval){
     if(lux != 0xFFFF){
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      Serial.print("Light Level : ");
      Serial.print(lux);
      Serial.println(" lux");
      Serial.println("");
    }
    else{
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      Serial.println("ERROR COK");
    } 
  }
}
