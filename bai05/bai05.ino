#define IN1 6
#define IN2 7
#define ENB 10

#include <L298N.h>
L298N motor1(ENB, IN2, IN1);
L298N::Direction direction = L298N::FORWARD;

void setup()
{  
  Serial.begin (9600);
  motor1.setSpeed(70);
  
}


void loop()
{     
    direction = L298N::FORWARD;
    motor1.run(direction);    
    Serial.println ("Quay thuan");
    delay(5000);

    motor1.stop();    
    delay(2000);    
    
    direction = L298N::BACKWARD;    
    motor1.run(direction);    
    Serial.println ("Quay nguoc");
    delay(5000);
    
    motor1.stop();    
    Serial.println ("STOP");
    delay(2000);    
}
