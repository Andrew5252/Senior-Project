#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219_A(0x40);
Adafruit_INA219 ina219_B(0x41);
Adafruit_INA219 ina219_C(0x44);

void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  Serial.println("Hello!"); 
  
  Serial.println("Measuring voltage and current with INA219 ...");
  ina219_A.begin();
  ina219_B.begin();
  ina219_C.begin();
  
}

void loop(void) 
{
  int sensorValue3 = analogRead(A3);
  int sensorValue2 = analogRead(A1);
  int sensorValue1 = analogRead(A2);
  
  float voltage1 = sensorValue1 * (4.97 / 1023.0);
  float voltage2 = sensorValue2 * (4.97 / 1023.0);
  float voltage3 = sensorValue3 * (4.97 / 1023.0);
  
  float current1_mA = 0;
  float current2_mA = 0;
  float current3_mA = 0;
   
  current1_mA = ina219_A.getCurrent_mA();
  current2_mA = ina219_B.getCurrent_mA();
  current3_mA = ina219_C.getCurrent_mA();

  
  Serial.print("Voltage 1:    "); Serial.print(voltage1 * 2.00); Serial.println(" V");
  Serial.print("Current 1:    "); Serial.print(current1_mA); Serial.println(" mA");
  Serial.println("");
  
  Serial.print("Voltage 2:    "); Serial.print(voltage2 * 2.134); Serial.println(" V");
  Serial.print("Current 2:    "); Serial.print(current2_mA); Serial.println(" mA");
  Serial.println("");
   
  Serial.print("Voltage 3:    "); Serial.print(voltage3 * 1.50); Serial.println(" V");
  Serial.print("Current 3:    "); Serial.print(current3_mA); Serial.println(" mA");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  delay(2000);
}


