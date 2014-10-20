#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219_A(0x40);
Adafruit_INA219 ina219_B(0x41);
Adafruit_INA219 ina219_C(0x42);

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
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);
  float voltage3 = sensorValue3 * (5.0 / 1023.0);
  
  float current1_mA = 0;
  float current2_mA = 0;
  float current3_mA = 0;
   
  current1_mA = ina219_A.getCurrent_mA();
  current2_mA = ina219_B.getCurrent_mA();
  current3_mA = ina219_C.getCurrent_mA();

  
  Serial.print("Voltage 1:    "); Serial.print(voltage1 * 2.02); Serial.println(" V");
  Serial.print("Current 1:    "); Serial.print(current1_mA); Serial.println(" mA");
  Serial.println("");
  
  Serial.print("Voltage 2:    "); Serial.print(voltage2 * 2.02); Serial.println(" V");
  Serial.print("Current 1:    "); Serial.print(current2_mA); Serial.println(" mA");
  Serial.println("");
   
  Serial.print("Voltage 3:    "); Serial.print(voltage3 * 2.02); Serial.println(" V");
  Serial.print("Current 1:    "); Serial.print(current3_mA); Serial.println(" mA");
  Serial.println("");

  delay(2000);
}

/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:

// the loop routine runs over and over again forever:
//void loop() {
  // read the input on analog pin 0:
  
  // print out the value you read:
  //Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability
//}
