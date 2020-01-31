#include <CapacitiveSensor.h>


CapacitiveSensor capSensor1 = CapacitiveSensor(4, 2);
CapacitiveSensor capSensor2 = CapacitiveSensor(7, 5);


void setup() {
  Serial.begin(9600);
}

void loop() {
  
    long start = millis();
    long sensorValue1 = capSensor1.capacitiveSensor(30);
    long sensorValue2 = capSensor2.capacitiveSensor(30);


    Serial.print(millis() - start);        // check on performance in milliseconds

    Serial.print("Sensor1: ");
    Serial.print(sensorValue1);
    Serial.print("Sensor2: ");
    Serial.println(sensorValue2);


    int val1 = map(sensorValue1, 0, 500, 50, 4000 );
    int val2 = map(sensorValue2, 0, 10000, 10, 1000);



    tone(8, val1, 20);
    noTone;
    delay(val2);

  }
