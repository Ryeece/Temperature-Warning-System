#include <DHT.h>           // DHT sensor library
#include <LiquidCrystal.h> // 16x2 LCD library

#define DHTPIN 2        // DHT11 data pin
#define DHTTYPE DHT11   // sensor type
#define LEDPIN 13       // warning LED utput pin

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // RS, E, D4, D5, D6, D7, LCD pin allocation

DHT dht(DHTPIN, DHTTYPE); // create DHT11 sensor 

void setup() {
  dht.begin(); // initialise the DHT11 sensor

  Serial.begin(9600); // serial monitor for testing

  pinMode(LEDPIN, OUTPUT); // sets warning LED pin as an output

  lcd.begin(16, 2); // initialise the 16-column, 2-row LCD
}

void loop() {
 float temperature = dht.readTemperature(); // read temperature in degrees Celcius

 if (isnan(temperature)) {  // if the value given by the DHT11 is an invalid reading
  Serial.println("ERROR: Failed to read from DHT11");

  lcd.setCursor(0, 0);
  lcd.print("Sensor error       ");

  lcd.setCursor(0, 1);
  lcd.print("Check DHT11        ");

  digitalWrite(LEDPIN, HIGH);  // LED on for faulty DHT11 reading
  delay(2000);
  return;
 }

 Serial.println(temperature);

 lcd.setCursor(0, 0);
 lcd.print("Temp: ");
 lcd.print(temperature);
 lcd.print(" C");

  if (temperature >= 29.8){    // temporary threshold for testing
    lcd.setCursor(0, 1);
    lcd.print("TEMP TOO HIGH");
    Serial.println("WARNING TEMP TOO HIGH");
    digitalWrite(LEDPIN, HIGH);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Normal temp  ");
    digitalWrite(LEDPIN, LOW);
  }
  delay(1000); // wait 1 second before taking the next sensor reading
}