#include <Servo.h> 

 
Servo myservo1; 
Servo myservo2;
int pos1 = 90; 
int pos2 = 160;   // initial position
int sens1 = A0; // LRD 1 pin ЛН
int sens2 = A1; //LDR 2 pin ЛВ
int sens3 = A3; // LRD 1 pin ПВ
int sens4 = A5; //LDR 2 pin ПН
int tolerance = 10;
 
void setup() 
{ 
  myservo1.attach(11);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(8);
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  pinMode(sens3, INPUT);
  pinMode(sens4, INPUT);
  myservo1.write(pos1);
  myservo2.write(pos2);
  Serial.begin(9600);
  delay(2000); // a 2 seconds delay while we position the solar panel
}  
 
void loop() 
{ 
  int val1 = analogRead(sens1); // read the value of sensor 1
  int val2 = analogRead(sens2); // read the value of sensor 2
  int val3 = analogRead(sens3); // read the value of sensor 3
  int val4 = analogRead(sens4); // read the value of sensor 4
  Serial.print("1 - ");
   Serial.print(analogRead(sens1));
   Serial.print("  2 - ");
   Serial.print(analogRead(sens2));
   Serial.print("  3 - ");
   Serial.print(analogRead(sens3));
   Serial.print("  4 - ");
   Serial.println(analogRead(sens4));
  if((abs(val2 + val1  - val3 - val4) <= tolerance)) {
    //do nothing if the difference between values is within the tolerance limit
  } else {    
    if(val2 + val1 > val3 + val4)
    {
      pos1 = --pos1;
    }
    if (val2 + val1 < val3 + val4) 
    {
      pos1 = ++pos1;
    }
  }
  if(pos1 > 180) { pos1 = 180; } // reset to 180 if it goes higher
  if(pos1 < 1) { pos1 = 1; } // reset to 0 if it goes lower
  
  myservo1.write(pos1); // write the position to servo
  delay(50);

 if((abs(val3 + val2  - val1 - val4) <= tolerance)) {
    //do nothing if the difference between values is within the tolerance limit
  } else {    
    if(val3 + val2 > val1 + val4)
    {
      pos2 = ++pos2;
    }
    if(val3 + val2 < val1 + val4) 
    {
      pos2 = --pos2;
    }
  }
  
  if(pos2 >160) { pos2 = 160; } // reset to 180 if it goes higher
  if(pos2 < 95) { pos2 = 95; } // reset to 0 if it goes lower
  
  myservo2.write(pos2); // write the position to servo
  
  // Ждём одну секунду для просмотра результата
 
  delay(50);
}
