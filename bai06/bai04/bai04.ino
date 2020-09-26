#include <L298N.h>
int TRIGGER_PIN = 2;
int ECHO_PIN = 3;
int BUZZER_PIN = 11;
int time;
int distance;

#define IN1 6
#define IN2 7
#define ENB 10

L298N motor1(ENB, IN2, IN1);
L298N::Direction direction = L298N::FORWARD;

void setup ( ) {
  
  Serial.begin (9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);
  pinMode (BUZZER_PIN, OUTPUT);
  motor1.setSpeed(70);
}

int measureDistance() {
  digitalWrite (TRIGGER_PIN, HIGH);
    delayMicroseconds (10);
    digitalWrite (TRIGGER_PIN, LOW);
    time = pulseIn (ECHO_PIN, HIGH);
    distance = (time * 0.034) / 2;  //The speed of sound in cm/us is 0.034cm/us
    return distance;
}
void loop ( ) {
    int distance = measureDistance();
    if (distance <= 10) {
      Serial.println (" Door Open ");
      Serial.print (" Distance= ");
      Serial.println (distance);
      digitalWrite (BUZZER_PIN, HIGH);
      Serial.println ("Quay thuan");
      direction = L298N::FORWARD;          
      delay (500);
    }
    else {
      Serial.println (" Door closed ");
      Serial.print (" Distance= ");
      Serial.println (distance);
      digitalWrite (BUZZER_PIN, LOW);
      Serial.println ("Quay nguoc");
      direction = L298N::BACKWARD;          
      delay (500);
    } 
    //digitalWrite (BUZZER_PIN, LOW);
    motor1.run(direction);         
}
