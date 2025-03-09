#include <LiquidCrystal_I2C.h>
#include <math.h>

#define sensorPin1 A0
#define sensorPin2 A1
#define sensorPin3 A2
#define piezoPin 2
char cmd;
double p =;
double q =;
char pos_y,pos_x;
LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  pinMode(piezoPin,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int val1 =analogRead(sensorPin1);
  int val2 =analogRead(sensorPin2);
  int val3 =analogRead(sensorPin3);
  Serial.println("Sensor1");
  Serial.println(val1);
  Serial.println("Sensor2");
  Serial.println(val2);
  Serial.println("Sensor3");
  Serial.println(val3);
  delay(100);

  if(Serial.available()){
    cmd =Serial.read();
    if(cmd =='x'){
      lcd.clear();
      pos_x =Serial.read();
    }
    if(cmd =='y'){
      lcd.clear();
      pos_y =Serial.read();
    }
  }

  if(pos_x =='a'){
    if(pos_y =='a'){
      lcd.setCursor(0,0);
      lcd.print("A pillar on floor 1");
      digitalWrite(piezoPin,HIGH);
      delay(5000);
    }
    else if(pos_y =='b'){
      lcd.setCursor(0,0);
      lcd.print("B pillar on floor 1");
      digitalWrite(piezoPin,HIGH);
      delay(5000);
    }
  }
  else if(pos_x =='b'){
    if(pos_y =='a'){
      lcd.setCursor(0,0);
      lcd.print("A pillar on floor 2");
      digitalWrite(piezoPin,HIGH);
      delay(5000);
    }
    else if(pos_y =='b'){
      lcd.setCursor(0,0);
      lcd.print("B pillar on floor 3");
      digitalWrite(piezoPin,HIGH);
      delay(5000);
    }
  }
  else if(pos_x =='c'){
    lcd.setCursor(0,0);
    lcd.print("on floor 3");
    digitalWrite(piezoPin,HIGH);
    delay(5000);
  }
  else{
    Serial.println("error 0");
  }
  digitalWrite(piezoPin,LOW);
}
