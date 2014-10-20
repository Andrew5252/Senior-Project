#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  Serial.println("Hello!");
  
  Serial.println("Measuring voltage and current with INA219 ...");
  ina219.begin();
}

void loop(void) 
{
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
   
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Voltage:    "); Serial.print(voltage * 2); Serial.println(" V");
  Serial.print("Current:    "); Serial.print(current_mA); Serial.println(" mA");
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
