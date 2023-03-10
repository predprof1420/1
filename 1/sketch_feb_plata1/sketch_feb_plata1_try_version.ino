#include <wire.h>
void setup() {
  Serial.begin(9600); /* begin serial comm. */
  Wire.begin(); /* join i2c bus as master */
  Serial.println("I am I2C Master");
}
void loop() {
  Wire.beginTransmission(8); /* begin with device address 8 */
  Wire.write("Hello Slave");  /* sends hello string */
  Wire.endTransmission();    /* stop transmitting */
  Wire.requestFrom(8, 9); /* request & read data of size 9 from slave */
  while(Wire.available()){
    char c = Wire.read();/* read data received from slave */
  Serial.print(c);
  }
  Serial.println();
  delay(1000);
}
