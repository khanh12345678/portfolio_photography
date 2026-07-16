#include<LiquidCrystal_I2C.h>
#include "DHT.h"
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int up = 4,down = 2;
#define DHTTYPE DHT11
#define DHTPIN 5
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.init();
  pinMode(up,INPUT_PULLUP); 
  pinMode(down,INPUT_PULLUP); 
  lcd.backlight();
  greet();
  start();

}

void loop() {
  // put your main code here, to run repeatedly:
  // int state_1= digitalRead(up),state_2 = digitalRead(down);
  // Serial.println(state_2); 
}
void greet(){ 
    String org ="Haavk indus";
    lcd.setCursor(0,0);
    for(int a = 0;a<=10;a++){ 
        lcd.print(org[a]);
        delay(250);
    }
    delay(700);
    lcd.setCursor(0,1); 
    lcd.print("Welcome");
    lcd.setCursor(8,1);
    lcd.print("v1.0");
    delay(1000); 
    
}
void start(){ 
    int state_1= digitalRead(up),state_2 = digitalRead(down);
    lcd.setCursor(0,1); 
    lcd.print("press to start"); 
    while(state_1 == 1 && state_2 == 1){
       state_1= digitalRead(up);
       state_2 = digitalRead(down);
    }
    lcd.clear();
}
void temp_humid(){ 
  lcd.setCursor(0,0); 
  lcd.print("starting temp");
  lcd.setCusror(0,1);
  lcd.print("starting humid");
  delay(2000);
                                                                      
}