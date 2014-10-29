//Both included files were downloaded from the current sensor webiste

#include <Wire.h>
#include <Adafruit_INA219.h>

//Each board needs to be physically address and then it can be referenced in the code.  
Adafruit_INA219 ina219_A(0x40);
Adafruit_INA219 ina219_B(0x41);
Adafruit_INA219 ina219_C(0x44);

//Begin the setup which prints a freindly message to the serial monitor and starts each 
// sensor.  It also saids the baud rate.
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

//This next loop initializes the current sensor values and the analog pins being used to read the voltages.
void loop(void) 
{
  int sensorValue3 = analogRead(A3);
  int sensorValue2 = analogRead(A1);
  int sensorValue1 = analogRead(A2);
  
  // The values received by the analog inputs are assigned a value from 1 to 1023.  By dividing 5V by 1023 it
  // is converted to a 5V scale.  The 4.97 below is used to calibrate the results depending on the actual reference voltage.
  float voltage1 = sensorValue1 * (4.97 / 1023.0);
  float voltage2 = sensorValue2 * (4.97 / 1023.0);
  float voltage3 = sensorValue3 * (4.97 / 1023.0);
  
  float current1_mA = 0;
  float current2_mA = 0;
  float current3_mA = 0;
  
  // Rename the currents for convenience
  current1_mA = ina219_A.getCurrent_mA();
  current2_mA = ina219_B.getCurrent_mA();
  current3_mA = ina219_C.getCurrent_mA();

  // Print the current and voltage from the first voltage source.  A voltage devider is used to protect the inputs
  // thus the value needs to be multiplied by the factor the voltage devider decreases the voltage by.
  Serial.print("Voltage 1:    "); Serial.print(voltage1 * 2.134); Serial.println(" V");
  Serial.print("Current 1:    "); Serial.print(current1_mA); Serial.println(" mA");
  Serial.println("");
  
  // Print the current and voltage from the second voltage source.  A voltage devider is used to protect the inputs
  // thus the value needs to be multiplied by the factor the voltage devider decreases the voltage by.
  Serial.print("Voltage 2:    "); Serial.print(voltage2 * 2.134); Serial.println(" V");
  Serial.print("Current 2:    "); Serial.print(current2_mA); Serial.println(" mA");
  Serial.println("");
  
  // Print the current and voltage from the third voltage source.  A voltage devider is used to protect the inputs
  // thus the value needs to be multiplied by the factor the voltage devider decreases the voltage by.  
  Serial.print("Voltage 3:    "); Serial.print(voltage3 * 2.20); Serial.println(" V");
  Serial.print("Current 3:    "); Serial.print(current3_mA); Serial.println(" mA");
  Serial.println("");
  
  // Add a couple extra spaces in between sets and delay the reading of the sets.
  Serial.println("");
  Serial.println("");
  delay(2000);
}


