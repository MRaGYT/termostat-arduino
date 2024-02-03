
int a = 0;
#include <Wire.h>
#include <microDS18B20.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
LiquidCrystal_I2C LCD(0x27,16,2);
MicroDS18B20<2> sensor;
void setup() {
LCD.init();
LCD.backlight();
Serial.begin(9600);
pinMode(8, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(4, OUTPUT);
}

void loop() {
  int b = sensor.getTemp();
    if(a<= 9 && a>= 0){
      LCD.setCursor(4,1);
      LCD.print("  ");
    }
    if(a<= 99 && a>= 0){
      LCD.setCursor(5,1);
      LCD.print("      ");
    }
    
  int but1 = digitalRead(8);
  int but2 = digitalRead(7);
  if(but1 == 1){
    a = a+1;
    delay(200);
  }
  if(but2 == 1){
    a = a-1;
    delay(200);
  }
sensor.requestTemp();
  LCD.setCursor(3,0);
  LCD.print(sensor.getTemp());
  if(a < 0){
      LCD.setCursor(2,1);
      LCD.print(a);
    } else if(a >= 0){
      LCD.setCursor(2,1);
      LCD.print(" ");
      LCD.setCursor(3,1);
      LCD.print(a);
    }
    if (b <= a){
      digitalWrite(4, 1);
    } else{
      digitalWrite(4, 0);
    }
Serial.println(a);

}
