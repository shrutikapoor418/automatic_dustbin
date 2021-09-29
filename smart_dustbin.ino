#include<Servo.h>
Servo s1;
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("welcome to");
    lcd.setCursor(0,1);
    lcd.print("smart dustbin");
pinMode(A0,INPUT);
pinMode(A1,OUTPUT);
s1.attach(5);
s1.write(0);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
long t=0,cm=0;
digitalWrite(A1,LOW);
delayMicroseconds(5);
digitalWrite(A1,HIGH);
delayMicroseconds(5);
digitalWrite(A1,LOW);
t=pulseIn(A0,HIGH);
long y=t/29;
cm=y/2;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(cm);
if(cm<=50)
{
  s1.write(90);
  delay(500);
}
else
{
   s1.write(0);
delay(500);
}
  
}
