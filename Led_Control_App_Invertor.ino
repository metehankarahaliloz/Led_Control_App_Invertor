
#include "BluetoothSerial.h"


BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  pinMode(25,OUTPUT);pinMode(26,OUTPUT);
  SerialBT.begin("ESP32test"); 
  Serial.println("Bluetooth'u eslestir");
  
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
    
  }
  if (SerialBT.available()) {
    
    int s=SerialBT.read();
    delay(20);
    if(s==1){digitalWrite(25,HIGH);}
    if(s==2){digitalWrite(25,LOW);}
    if(s==3){digitalWrite(26,HIGH);}
    if(s==4){digitalWrite(26,LOW);}
    //if(s>50){analogWrite(25,s);}
   // Serial.write(SerialBT.read());
    Serial.write(s);
  }
  delay(20);
}