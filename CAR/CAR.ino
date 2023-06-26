
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLBisLOZeu"
#define BLYNK_DEVICE_NAME "RELAY"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

int motor1pin1 = 25;
int motor1pin2 = 26;

int motor2pin3 = 27;
int motor2pin4 = 33;

#define VPIN_F V4
#define VPIN_B V5
#define VPIN_L V6
#define VPIN_R V7

#define echoPin1 22// attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 23 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 35
#define trigPin2 32
#define echoPin3 13
#define trigPin3 14
#define echoPin4 18
#define trigPin4 19

#define SOUND_SPEED 0.034



// defines variables
long duration1; // variable for the duration of sound wave travel
int distance1; // variable for the distance measurement
long duration2;
int distance2;
long duration3;
int distance3;
long duration4;
int distance4;

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT

int F_State = 0;
int B_State = 0;
int L_State = 0;
int R_State = 0;


#include "BlynkEdgent.h"

WidgetLED led1(V8);
WidgetLED led2(V9);
WidgetLED led3(V10);
WidgetLED led4(V11);

BLYNK_CONNECTED()
{
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_F);
  Blynk.syncVirtual(VPIN_L);
  Blynk.syncVirtual(VPIN_B);
  Blynk.syncVirtual(VPIN_R);
  
}
//Forward

  BLYNK_WRITE(VPIN_F)
  {
    F_State = param.asInt();
    if (distance1 < 25 && F_State == 1)
    {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin3, LOW);
      digitalWrite(motor2pin4, LOW);
      Serial.println("Obstacle Detected by 1");
      }
      else if(F_State == 1)
       {
            digitalWrite(motor1pin1, HIGH);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor2pin3, LOW);
            digitalWrite(motor2pin4, HIGH);
          }
          else
          {
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, LOW);
            digitalWrite(motor2pin3, LOW);
            digitalWrite(motor2pin4, LOW);
          }
          
          
}


//Backward

  BLYNK_WRITE(VPIN_B)
  {
    if (distance2 < 25)
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  Serial.println("Obstacle Detected by 2");
}
else
{
  //Backward
  B_State = param.asInt(); //requests for latest state of the button
  if (B_State == 1) {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  }
  else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, LOW);
  }
}
}




//Right Turn

  BLYNK_WRITE(VPIN_R)
{
  if (distance3 < 25)
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  Serial.println("Obstacle Detected by 3");
}
else
{
  //RIGHT Turn
  R_State = param.asInt(); //requests for latest state of the button
  if (R_State == 1) {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  }
  else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, LOW);
  }
}
}

//LEFT Turn

  BLYNK_WRITE(VPIN_L)
{
  if (distance4 < 25)
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  
  Serial.println("Obstacle Detected by 4");
}
else
{
  //LEFT Turn
  L_State = param.asInt(); //requests for latest state of the button
  if (L_State == 1) {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, HIGH);
  }
  else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, LOW);
  }
}
}



void ultrasonic()
{
  //ultrasonic 1
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Blynk.virtualWrite(V0, distance1);
  delay(1000);
  if  (distance1 < 25)
  {
  led1.on();
  }
  else
  {
  led1.off();
}



  //ultrasonic_2
  // Clears the trigPin condition
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  Blynk.virtualWrite(V1, distance2);
  delay(1000);
  if  (distance2 < 25)
  {
  led2.on();
  }
  else
  {
  led2.off();
}


  //ultrasonic_3
  // Clears the trigPin condition
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance3 = duration3 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  Blynk.virtualWrite(V2, distance3);
  delay(1000);
  if  (distance3 < 25)
  {
  led3.on();
  }
  else
  {
  led3.off();
}

  //ultrasonic_4
  // Clears the trigPin condition
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration4 = pulseIn(echoPin4, HIGH);
  // Calculating the distance
  distance4 = duration4 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance4: ");
  Serial.print(distance4);
  Serial.println(" cm");

  Blynk.virtualWrite(V3, distance4);
  delay(1000);
  if  (distance4 < 25)
  {
  led4.on();
  }
  else
  {
  led4.off();
}

}



void setup()
{
  Serial.begin(115200);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  pinMode(motor2pin4, OUTPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  delay(1000);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay(1000);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  delay(1000);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  delay(1000);

  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  ultrasonic();
 

  }
