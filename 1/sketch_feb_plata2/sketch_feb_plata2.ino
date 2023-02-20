#include <Wire.h>
/*
#include <AmperkaServo.h>

#include <TroykaThermometer.h>

TroykaThermometer thermometer(A0);

AmperkaServo servo;
constexpr uint8_t SERVO_PIN = 9;
constexpr auto pinSensor = A0;
void setup()
{
  Serial.begin(9600);
  servo.attach(SERVO_PIN, 544, 2400, 0, 180);
}

void loop()
{
  int valueSensor = analogRead(pinSensor);
  Serial.print("Влажность почвы ");
  Serial.println(valueSensor);
  delay(100);
  thermometer.read();
  int thermometer_temp=thermometer.getTemperatureC();
  Serial.print("Температура воздуха ");
  Serial.print(thermometer_temp);
  Serial.println(" C");
  if (thermometer_temp < 25) { 
    Serial.println("Форточка закрыта");
    servo.write(0);
  } else if (thermometer_temp >= 25) { 
    Serial.println("Форточка открыта");
    servo.write(180);
  }

    delay(1000);
}
*/