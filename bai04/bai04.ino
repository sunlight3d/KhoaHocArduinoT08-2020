int TRIGGER_PIN = 2;
int ECHO_PIN = 3;
int BUZZER_PIN = 10;
int time;
int distance;
void setup ( ) {
  
  Serial.begin (9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);
  pinMode (BUZZER_PIN, OUTPUT);
}
int measureDistance() {
  digitalWrite (TRIGGER_PIN, HIGH);
    delayMicroseconds (10);
    digitalWrite (TRIGGER_PIN, LOW);
    time = pulseIn (ECHO_PIN, HIGH);
    distance = (time * 0.034) / 2;  //The speed of sound in cm/us is 0.034cm/us
}
void loop ( ) {
    
    if (distance <= 10) {
      Serial.println (" Door Open ");
      Serial.print (" Distance= ");
      Serial.println (distance);
      digitalWrite (BUZZER_PIN, HIGH);
      delay (500);
    }
    else {

      Serial.println (" Door closed ");
      Serial.print (" Distance= ");
      Serial.println (distance);
      digitalWrite (BUZZER_PIN, LOW);
      delay (500);
    } 
    
}
