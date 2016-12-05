#include 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
const int inPin = 0;
const int potPin = 1;
 
byte degree[8] = {
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
lcd.createChar(1, degree);
lcd.begin(16, 2);
}

void loop() {
int value = analogRead(inPin);
int hasil = analogRead(potPin);
lcd.setCursor(0, 1);
float millivolts = (value / 1024.0) * 5000;
float millivolt = (hasil / 1024.0) * 5000;
float celsius = millivolts / 10;
float celcius = millivolt / 10;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Suhu 1   ");
lcd.print(celcius);
lcd.write(1);
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Suhu 2   ");
lcd.print(celsius);
lcd.write(1);
lcd.print("C");
delay(500);
}
