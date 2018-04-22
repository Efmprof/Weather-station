// ======== Библиотеки ===========
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// ===============================

LiquidCrystal lcd(4, 5, 6, 7, 8, 9); // Подключаем LCD (RS, E, D4-7)

#define DHPIN 10 // Указываем пин и тип датчика температуры (иже)
#define DHTTYPE DHT11
DHT dht(DHPIN, DHTTYPE); // Инициализируем датчик

int hum, temp; // Переменные температуры и влажности

//=================================

void setup() {
  Serial.begin(9600); // Открываем Serial порт
  lcd.begin(16, 2); // Начинаем работу дисплея
  dht.begin(); // Начинаем работу датчика
}

void loop() {
  hum = dht.readHumidity(); // Получаем влажность и температуру
  temp = dht.readTemperature();

  //=-=-=-= Отображаем данные выше на дисплее -=-=-=-=
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("'C ");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("% ");

  //=-=-=-=-=- Выводим данные на компьютер =-=-=-=-=-

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(".C || ");
  Serial.print("Hum:");
  Serial.print(hum);
  Serial.println("%");

  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  delay(1500); // Спим полторы секунды

}

