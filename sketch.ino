#include <Servo.h>

// Настройки пинов
const int emgPin = A0;   // Пин датчика ЭМГ
const int servoPin = 9;  // Пин сервопривода

// Параметры калибровки (подбираются индивидуально)
const int THRESHOLD = 340;       // Порог напряжения мышцы (0-1023)
const unsigned long DEBOUNCE_DELAY = 1000; // Пауза в мс между переключениями (1 секунда)

// Фильтрация (скользящее среднее)
const int WINDOW_SIZE = 10;      // Размер окна сглаживания
int readings[WINDOW_SIZE];       // Массив для хранения последних чтений
int readIndex = 0;               // Индекс текущего чтения
long total = 0;                  // Бегущая сумма
int smoothedEMG = 0;             // Сглаженное значение

// Состояния системы
Servo myServo;
bool servoState = false;         // false = 0 градусов, true = 180 градусов
unsigned long lastToggleTime = 0; // Время последнего переключения

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(0); // Стартовое положение сервы

  // Инициализируем массив фильтра нулями
  for (int i = 0; i < WINDOW_SIZE; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // --- 1. Алгоритм Скользящего Среднего ---
  total = total - readings[readIndex];       // Вычитаем старое значение
  readings[readIndex] = analogRead(emgPin);  // Читаем новое значение с датчика
  total = total + readings[readIndex];       // Добавляем новое значение к сумме
  readIndex = readIndex + 1;                 // Переходим к следующему элементу

  if (readIndex >= WINDOW_SIZE) {
    readIndex = 0;                           // Возвращаемся в начало массива
  }

  smoothedEMG = total / WINDOW_SIZE;         // Получаем сглаженный сигнал

  // Выводим данные в плоттер по калибровке (Вкладка Инструменты -> Плоттер по последовательному порту)
  Serial.print("Raw:");
  Serial.print(readings[readIndex == 0 ? WINDOW_SIZE - 1 : readIndex - 1]);
  Serial.print(",");
  Serial.print("Filtered:");
  Serial.print(smoothedEMG);
  Serial.print(",");
  Serial.print("Threshold:");
  Serial.println(THRESHOLD);

  // --- 2. Логика триггера с защитой от шумов ---
  // Проверяем: превышен ли порог И прошло ли достаточно времени с прошлого зажима?
  if (smoothedEMG > THRESHOLD && (millis() - lastToggleTime > DEBOUNCE_DELAY)) {
    
    servoState = !servoState; // Меняем состояние на противоположное

    if (servoState) {
      myServo.write(180);     // Поворот в рабочее положение
    } else {
      myServo.write(0);       // Поворот обратно
    }

    lastToggleTime = millis(); // Запоминаем время переключения
    delay(50);                 // Короткая пауза для стабилизации механизма
  }

  delay(5); // Частота дискретизации ~200 Гц
}
