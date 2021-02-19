//N.B you have to define the pins as per the your circuit...

#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>
#include <Wire.h>


LiquidCrystal lcd(2,3,4,5,6,7);
int IRSensor = 9; 
int IRSensor2 = 10; 
float Btemp=97;
bool pump=11;
int statusSensor2;
int buz=12;
int red=14;
int green=13;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();


void setup() {
  mlx.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (IRSensor2, INPUT); // sensor pin INPUT


}

void loop() {
digitalWrite(pump,LOW);
  Serial.print(mlx.readAmbientTempC());
  Serial.print(mlx.readObjectTempC());
  
  lcd.clear();
  int statusSensor = digitalRead (IRSensor);
  Serial.println(statusSensor);
  lcd.setCursor(3,0);
  lcd.print("Hi there !");
  delay (800);
  lcd.setCursor(1,1);
  lcd.print("Use Sanitizer");
  delay (800);
  lcd.clear();
  
  dcpump:
  
  if(statusSensor ==0)
  {
    //TODO:Configure DC pump.
   digitalWrite(pump,HIGH);
    delay(1000);
   digitalWrite(pump,LOW);
    delay(1000);
    
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("DONE :)");
    lcd.setCursor(3,1);
    lcd.print("Thank You");
    delay (800);
    lcd.clear();
     int statusSensor = digitalRead (IRSensor);
     if(statusSensor ==0)
     {
     goto dcpump;
     }else if(statusSensor ==1){
      int statusSensor2 =1;//only declaration.
      while(statusSensor2 ==1){
          int statusSensor2 = digitalRead (IRSensor2);
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Check Your");
           lcd.setCursor(0,1);
          lcd.print("Body Temperature");
          delay(200);
          if(statusSensor2 ==0)
          {
            goto temperature;
          }
        }

       }
        temperature:
        if(statusSensor2 ==0)
           {
          //TODO:Read temperature and store it in a variable temp(in faren heat) ;display it in the LCD display 
          lcd.clear();
          Btemp=mlx.readObjectTempC();
          lcd.setCursor(0,0);
          lcd.print("Body Temperature :");
          lcd.setCursor(6,1);
          Btemp=(1.8*Btemp)+32;
          lcd.print(Btemp);
          lcd.print("°F");
          delay(7000);
           }
   }
 if (Btemp<99)
 {
  //open the dore and print welcome
  digitalWrite(green,HIGH);
  delay(1000);
  wel();
  digitalWrite(green,LOW);
 }else
  {
    //TODO:enable continueous buzzer and show high temperature in display (in the second line)
      digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  alert();
  }
  // put your main code here, to run repeatedly:

}


void wel()
{
	//TODO: Write code for opening the dore and printing welcome
  digitalWrite(buz,HIGH);
  delay(1000);
  digitalWrite(buz,LOW);
}

void alert()
{
	//TODO:Write code for alerting the customer by using buzzer , display etc.
    digitalWrite(buz,HIGH);
  delay(100);
  digitalWrite(buz,LOW);
  delay(100);
   digitalWrite(buz,HIGH);
  delay(100);
  digitalWrite(buz,LOW);
  delay(100);
   digitalWrite(buz,HIGH);
  delay(100);
  digitalWrite(buz,LOW);
  delay(100);
   digitalWrite(buz,HIGH);
  delay(100);
  digitalWrite(buz,LOW);
  delay(100);
  
  }
