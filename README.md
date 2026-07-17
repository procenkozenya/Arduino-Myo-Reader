# EMG Muscle Signal Reader & Servo Controller (Arduino)

> **3‑Language Documentation:**  
> [🇬🇧 English](#-english) · [🇩🇪 Deutsch](#-deutsch) · [🇷🇺 Русский](#-русский)

---

## 🎥 Video Demonstration

[![Demo Video](https://img.shields.io/badge/YouTube-Watch%20Demo-red?logo=youtube)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)

Click the badge above or use this link:  
🔗 **https://www.youtube.com/watch?v=1bi1sjHFQHw**  
*(Replace `YOUR_VIDEO_ID` with your actual YouTube video ID)*

---

## 🇬🇧 ENGLISH

### Overview
This project reads raw EMG (electromyography) signals from a muscle sensor connected to an Arduino and uses them to toggle a servo motor. The signal is filtered with a **moving average** to reduce noise, and a **debounce mechanism** prevents rapid toggling. The servo rotates between 0° and 180° every time a muscle contraction exceeds the set threshold.

### Hardware Requirements
- Arduino board (Uno/Nano/Mega)
- EMG muscle sensor (e.g., MyoWare or generic analog output)
- Servo motor (SG90 / MG995 / similar)
- Power supply (5V for servo, battery recommended)

### Wiring Diagram
| Component | Arduino Pin |
|-----------|-------------|
| EMG Signal | A0 |
| Servo PWM | D9 |
| Servo VCC | 5V (external supply recommended for high‑current servos) |
| GND | GND |

### How It Works
1. **Signal Acquisition** – reads analog voltage from the EMG sensor (0–1023).  
2. **Noise Filtering** – applies a sliding window average (size = 10 samples) to smooth the raw signal.  
3. **Threshold Detection** – compares the filtered value against a user‑defined threshold (default: `340`).  
4. **Debounce** – enforces a 1‑second cooldown between toggles to avoid accidental triggers.  
5. **Servo Action** – switches the servo between 0° and 180° on each valid trigger.

### Calibration & Tuning
- **Threshold**:  
  Connect the sensor, relax your muscle, and watch the `Filtered` value in the Serial Plotter. Set `THRESHOLD` slightly above the resting level.  
- **Window Size**: Increase `WINDOW_SIZE` for smoother readings (reduces response time).  
- **Debounce Delay**: Adjust `DEBOUNCE_DELAY` (ms) to change the minimum time between actions.

### Installation
1. Install the [Servo](https://www.arduino.cc/en/reference/servo) library (usually pre‑installed).  
2. Upload the sketch to your Arduino.  
3. Open **Serial Plotter** (Tools → Serial Plotter) to visualise the raw, filtered, and threshold values.

### Usage
- Place the EMG electrodes on a muscle (e.g., biceps).  
- Contract the muscle firmly – the servo will rotate to 180°.  
- Relax and contract again to return to 0°.  
- Use the Serial Plotter to fine‑tune the threshold in real time.

---

## 🇩🇪 DEUTSCH

### Überblick
Dieses Projekt liest rohe EMG‑Signale (Elektromyographie) von einem Muskel‑Sensor über Arduino und steuert damit einen Servomotor. Ein **gleitender Mittelwertfilter** reduziert Rauschen, und eine **Entprellung** verhindert ungewolltes Umschalten. Der Servo bewegt sich bei jeder Muskelkontraktion, die den Schwellwert überschreitet, zwischen 0° und 180°.

### Benötigte Hardware
- Arduino (Uno/Nano/Mega)
- EMG‑Muskelsensor (z. B. MyoWare oder analoger Ausgang)
- Servomotor (SG90 / MG995 / ähnlich)
- Netzteil (5V für Servo, Batterie empfohlen)

### Anschlussbelegung
| Komponente | Arduino‑Pin |
|------------|-------------|
| EMG‑Signal | A0 |
| Servo PWM | D9 |
| Servo VCC | 5V (bei starken Servos externe Versorgung) |
| GND | GND |

### Funktionsweise
1. **Signalerfassung** – liest die analoge Spannung des EMG‑Sensors (0–1023).  
2. **Rauschfilterung** – gleitender Mittelwert über 10 Messwerte glättet das Signal.  
3. **Schwellwert‑Erkennung** – vergleicht den gefilterten Wert mit einem festgelegten Schwellwert (Standard: `340`).  
4. **Entprellung** – 1‑Sekunde‑Sperre zwischen Umschaltvorgängen.  
5. **Servo‑Aktion** – schaltet den Servo bei jedem gültigen Trigger zwischen 0° und 180° um.

### Kalibrierung & Einstellungen
- **Schwellwert**:  
  Sensor anschließen, Muskel entspannen und den `Filtered`‑Wert im seriellen Plotter beobachten. Setzen Sie `THRESHOLD` knapp über dem Ruhewert.  
- **Fenstergröße**: Erhöhen Sie `WINDOW_SIZE` für glattere Werte (verringert die Reaktionszeit).  
- **Entprellzeit**: Passen Sie `DEBOUNCE_DELAY` (ms) an, um die Mindestpause zwischen Aktionen zu ändern.

### Installation
1. Die [Servo](https://www.arduino.cc/en/reference/servo)‑Bibliothek ist meist schon installiert.  
2. Laden Sie den Sketch auf Ihren Arduino hoch.  
3. Öffnen Sie den **seriellen Plotter** (Werkzeuge → Serieller Plotter), um Roh‑, Filter‑ und Schwellwert‑Signale zu visualisieren.

### Verwendung
- Elektroden auf einen Muskel (z. B. Bizeps) kleben.  
- Muskel kräftig anspannen – der Servo dreht auf 180°.  
- Entspannen und erneut anspannen, um auf 0° zurückzukehren.  
- Passen Sie den Schwellwert live im Plotter an.

---

## 🇷🇺 РУССКИЙ

### Обзор
Проект считывает сырые сигналы ЭМГ (электромиографии) с датчика мышц, подключённого к Arduino, и управляет сервоприводом. Сигнал фильтруется **скользящим средним** для подавления шумов, а **антидребезг** предотвращает ложные срабатывания. При каждом сокращении мышцы, превышающем порог, сервопривод переключается между 0° и 180°.

### Необходимые компоненты
- Плата Arduino (Uno/Nano/Mega)
- Датчик ЭМГ (например, MyoWare или аналоговый выход)
- Сервопривод (SG90 / MG995 / аналогичный)
- Источник питания (5В для серво, рекомендуется батарея)

### Схема подключения
| Компонент | Пин Arduino |
|-----------|-------------|
| Сигнал ЭМГ | A0 |
| ШИМ серво | D9 |
| Питание серво | 5В (для мощных серво – внешний источник) |
| GND | GND |

### Принцип работы
1. **Сбор сигнала** – чтение аналогового напряжения с датчика ЭМГ (0–1023).  
2. **Фильтрация шума** – скользящее среднее по окну из 10 измерений сглаживает сигнал.  
3. **Пороговая обработка** – сравнение отфильтрованного значения с заданным порогом (по умолчанию `340`).  
4. **Антидребезг** – принудительная пауза в 1 секунду между переключениями.  
5. **Действие серво** – при каждом валидном срабатывании серво меняет положение (0° ↔ 180°).

### Калибровка и настройка
- **Порог**:  
  Подключите датчик, расслабьте мышцу и смотрите значение `Filtered` в плоттере последовательного порта. Установите `THRESHOLD` чуть выше уровня покоя.  
- **Размер окна**: Увеличьте `WINDOW_SIZE` для более гладкого сигнала (уменьшит скорость реакции).  
- **Задержка антидребезга**: Изменяйте `DEBOUNCE_DELAY` (мс) для регулировки минимальной паузы между действиями.

### Установка
1. Библиотека [Servo](https://www.arduino.cc/en/reference/servo) обычно уже установлена в Arduino IDE.  
2. Загрузите скетч на вашу плату Arduino.  
3. Откройте **Плоттер по последовательному порту** (Инструменты → Плоттер по последовательному порту), чтобы визуализировать сырой, отфильтрованный сигнал и порог.

### Использование
- Закрепите электроды на мышце (например, бицепс).  
- Сильно сократите мышцу – сервопривод повернётся на 180°.  
- Расслабьтесь и снова сократите – вернётся в 0°.  
- Настраивайте порог в реальном времени, наблюдая за плоттером.

---

## 📊 Serial Plotter Output Example
Raw: 256, Filtered: 245, Threshold: 340
Raw: 412, Filtered: 389, Threshold: 340 ← trigger
...


## 🔧 Customisation Tips (for all languages)
- **Change servo angle range** – modify `myServo.write(180)` / `write(0)` to any value 0–180.  
- **Invert trigger logic** – swap the servo states or use `<` instead of `>` for threshold.  
- **Add LED feedback** – connect an LED to indicate when the threshold is exceeded.

---

**Happy hacking!** 🤖💪
