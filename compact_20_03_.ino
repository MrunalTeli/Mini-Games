#include <Ultrasonic.h>
#include <SoftwareSerial.h>

#define buzzer 4
#define led 12 

int info = 0;
int sound=0;
SoftwareSerial BTSerial(2, 3); // RX | TX

Ultrasonic ultrasonic1(6,7);
Ultrasonic ultrasonic2(9,10);
long int distance1,distance2;

void setup() { 
  
  Serial.begin(9600); 
  BTSerial.begin(9600);
  
  pinMode(led, OUTPUT); //defining LED pin
  pinMode(buzzer, OUTPUT);
}

void loop(){ //here we combine both codes to work in the loop
  sensor();
}

void sensor() { 
  
  distance1=ultrasonic1.distanceRead(CM);
  distance2=ultrasonic2.distanceRead(CM);
  
  if (distance1 <= 10 && distance1 > 0) {
    digitalWrite(led, HIGH);
  
    Serial.print("  Sensor1: ");
    Serial.print(distance1);
    Serial.println(" cm");
    BTSerial.print(distance1,DEC);
    BTSerial.print(" cm");
    sound=300;  
  }
  
  else {
    
    if (distance2 <= 10 && distance2 > 0) {
      digitalWrite(led, HIGH);
      
      Serial.print("  Sensor2: ");
      Serial.print(distance2);
      Serial.println(" cm");
      BTSerial.print(distance2,DEC);
      BTSerial.print(" cm");
      sound=300;  
    }
    
    else {
      digitalWrite(led,LOW);
      Serial.println(" OUT OF RANGE ");
      BTSerial.println(" OUT OF RANGE ");
    }
  }
  delay(1000);
  
}
