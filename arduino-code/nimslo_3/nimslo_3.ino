const int ldr_read = A0;
const int flash_ready = A1;
const int shutter_ready = 2;
const int flash_actuator = 3;
const int shutter_actuator = 4;
const int green_led = 5;
const int red_led = 6;
const int film_led = 7;


void setup() {
  Serial.begin(9600);
  Serial.println("system started");
    pinMode(shutter_ready, INPUT);   
    pinMode(flash_actuator, OUTPUT);
    pinMode(green_led, OUTPUT);
    pinMode(red_led, OUTPUT);
    pinMode(film_led, OUTPUT);
    pinMode(shutter_actuator, OUTPUT);
    digitalWrite(shutter_actuator, HIGH);

    // LEDs OFF
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, HIGH);
}                   

void loop() {
while (digitalRead(shutter_ready) == LOW) {  //RUNS LOOP IF SHUTTER WOUND DURING HALF PRESS
  while (digitalRead(shutter_ready) == HIGH) { //ENDS LOOP IF SHUTTER IS NOT WOUND DURING HALF PRESS
      return;
  }

   //DETECTS VOLTAGE REF FROM AREF
  int sensorValue = analogRead(ldr_read);
  float voltage = sensorValue;

  // SET GREEN LED
  if (voltage >= 80) {
    digitalWrite(green_led, LOW);                            //GREEN LED ON IF VALUE MET
  } else if (voltage < 80) {     //VCC IS CONNECTED TO ORANGE WIRE
    digitalWrite(green_led, HIGH);                          //GND GREEN WIRE CONNECTED TO (PIN 5)
  }
  
  // SET RED LED
  if (voltage < 80) {
    digitalWrite(red_led, LOW);                          //RED LED ON IF VALUE NOT MET
  } else if (voltage > 80) {         //GND RED WIRE CONNECTED TO (PIN 6)
    digitalWrite(red_led, HIGH);          //PULLS HIGH TO TURN OFF LED
  }
  

  //SHUTTER PROFILE 1
  if (voltage <= 60 && voltage >= 0)  {
    Serial.println("s1");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(50);
        digitalWrite(shutter_actuator, LOW);
        digitalWrite(flash_actuator, HIGH);
        digitalWrite(flash_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }
  
  //SHUTTER PROFILE 2
  if (voltage <= 80 && voltage >= 60) { 
    Serial.println("s2");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(44);
        digitalWrite(shutter_actuator, LOW);
        digitalWrite(flash_actuator, HIGH);
        digitalWrite(flash_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }

  //SHUTTER PROFILE 3
  if (voltage <= 100 && voltage > 80)  {
    Serial.println("s3");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(40);
        digitalWrite(shutter_actuator, LOW);
        digitalWrite(flash_actuator, HIGH);
        digitalWrite(flash_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }

  //SHUTTER PROFILE 4
  if (voltage <= 120 && voltage > 100) {
    Serial.println("s4");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(38);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }

  //SHUTTER PROFILE 5
  if (voltage <= 135 && voltage > 120) {
    Serial.println("s5");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(36);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }
  
  //SHUTTER PROFILE 6
  if (voltage <= 150 && voltage > 135) {
    Serial.println("s6");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(34);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break ;
      }
      break;
  }

  //SHUTTER PROFILE 7
  if (voltage <= 165 && voltage > 150) {
    Serial.println("s7");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(32);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
       }
       break;
  }

  //SHUTTER PROFILE 8
  if (voltage <= 180 && voltage > 165) {
    Serial.println("s8");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(28);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        
        break; 
      }
      break;
  }

  //SHUTTER PROFILE 9
  if (voltage <= 200 && voltage > 180) {
       Serial.println("s9");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(24);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
    
        break;
      }
      break;
  }

  //SHUTTER PROFILE 10
  if (voltage <= 225 && voltage > 200) {
            Serial.println("s10");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(20);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        break;
      }
      break;
  }

  //SHUTTER PROFILE 11
  if (voltage <= 240 && voltage > 225) {
            Serial.println("s11");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(18);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        break;
      }
      break;
  }

  //SHUTTER PROFILE 12
  if (voltage <= 1024 && voltage > 240) {
    Serial.println("s12");
      digitalWrite(shutter_actuator, HIGH);
      delay(15);
      if (digitalRead(shutter_ready) == HIGH) {
        delay(16);
        digitalWrite(shutter_actuator, LOW);
        delay(50);
        digitalWrite(film_led, HIGH);            //INDICATOR LED FOR FILM
        delayMicroseconds(50);
        digitalWrite(film_led, LOW);
        break; 
      }
      break;
  }
  delay(50);
  break;
}

if (digitalRead(shutter_ready) == HIGH) {     //TURNS OFF LEDS IF SHUTTER ISN'T WOUND
  digitalWrite(green_led, HIGH);
  digitalWrite(red_led, HIGH);
}
  }
