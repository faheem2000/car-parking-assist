#include <LiquidCrystal.h>
#define trigger 10
#define echo 9
#define buzzer 8

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int safetyDistance;
float time = 0, distance = 0;

void setup(){
  lcd.begin(16, 2);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.print(" peace school");
  Serial.println(" peace school");
  lcd.setCursor(0, 1);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
  lcd.print(" Circuit Digest");
  delay(2000);
}
void loop(){
  lcd.clear();
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);
  distance = time * 340 / 20000;
  safetyDistance = distance;
  Serial.println(distance);
if (safetyDistance >= 5) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
  lcd.clear();
  lcd.print("Distance:");

  lcd.print(distance);
  lcd.print("cm");
   lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(distance / 100);
  lcd.print("m");
  delay(1000);
}