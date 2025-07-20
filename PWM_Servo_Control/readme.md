# 🚀 STM32F4 Servo Kontrol - PWM Butonla 15° Artırma

Bu proje, STM32F4 serisi bir mikrodenetleyici ile **SG90 servo motorunun PWM sinyali ile kontrolünü** hedefler. Butona her basıldığında servo motorun konumu **15° artırılarak** hareket ettirilir. Belirli bir sınıra ulaşıldığında sistem geriye döner ve servo motor ters yönde hareket etmeye başlar. Projede **Timer3 kullanılarak PWM sinyali** oluşturulmuştur.

## 🧠 Proje Özeti

- **Dil**: C
- **Platform**: STM32F4
- **IDE**: STM32CubeIDE
- **Donanım**: SG90 Servo, Push Button, STM32F4 Discovery veya Nucleo kart
- **PWM Timer**: TIM3_CH1

---

## ⚙️ Sistem Saat Konfigürasyonu (System Clock Configuration)

Projede kullanılan **sistem saat ayarı 42 MHz** olarak belirlenmiştir. Bu değer, **geliştirme sürecinde sade bir yapı**, **düşük güç tüketimi** ve **temel işlemler için yeterli performans** sağlamak amacıyla seçilmiştir.

### 🔍 Clock Ayarları (Kullanılan Konfigürasyon)
| Parametre         | Değer     |
|-------------------|-----------|
| HSE               | 25 MHz    |
| PLLM              | 16        |
| PLLN              | 168       |
| PLLP              | 4         |
| SYSCLK            | 42 MHz    |
| AHB Prescaler     | 1         |
| APB1 Prescaler    | 1         |
| APB2 Prescaler    | 1         |

---

### ⚖️ Alternatif Konfigürasyon ve Karşılaştırma

| Özellik                         | 42 MHz Konfigürasyon            | 84 MHz Konfigürasyon (Önerilen)  |
|----------------------------------|----------------------------------|-----------------------------------|
| İşlemci Hızı (SYSCLK)            | 42 MHz                          | 84 MHz                            |
| Timer Clock (APB1/APB2)          | 42 MHz                          | 84 MHz                            |
| Timer PWM çözünürlüğü           | Orta                            | Yüksek                            |
| Güç Tüketimi                     | Düşük                           | Daha yüksek                       |
| Gerçek zamanlı uygulama desteği | Sınırlı                         | Daha güçlü                        |
| Geliştirme süreci                | Daha sade                       | Biraz daha karmaşık               |

---

## 🔧 Kodun Temel Yapısı

```
uint16_t degree_set(int count) {
    uint16_t pulse = 0;
    pulse = 1000 + (15 * count * 1000) / 180;
    return pulse;
}
```
# 🚀 STM32F4 Servo Control - PWM Button-Controlled 15° Increment

This project demonstrates **PWM-based control of an SG90 servo motor** using an STM32F4 microcontroller. Every time a button is pressed, the servo motor rotates **15° forward**. When a limit is reached, the system reverses direction and moves the servo backward. **Timer3** is used to generate the PWM signal.

## 🧠 Project Overview

- **Language**: C  
- **Platform**: STM32F4  
- **IDE**: STM32CubeIDE  
- **Hardware**: SG90 Servo, Push Button, STM32F4 Discovery or Nucleo board  
- **PWM Timer**: TIM3_CH1  

---

## ⚙️ System Clock Configuration

The system clock is configured to **42 MHz** to maintain simplicity, low power consumption, and sufficient performance for basic tasks.

### 🔍 Clock Configuration Used

| Parameter         | Value     |
|-------------------|-----------|
| HSE               | 25 MHz    |
| PLLM              | 16        |
| PLLN              | 168       |
| PLLP              | 4         |
| SYSCLK            | 42 MHz    |
| AHB Prescaler     | 1         |
| APB1 Prescaler    | 1         |
| APB2 Prescaler    | 1         |

---

### ⚖️ Alternative Configuration Comparison

| Feature                        | 42 MHz Configuration        | 84 MHz Configuration (Recommended) |
|-------------------------------|-----------------------------|------------------------------------|
| Processor Speed (SYSCLK)      | 42 MHz                      | 84 MHz                             |
| Timer Clock (APB1/APB2)       | 42 MHz                      | 84 MHz                             |
| PWM Resolution                | Medium                      | High                               |
| Power Consumption             | Low                         | Higher                             |
| Real-Time Performance         | Limited                     | Better                             |
| Development Simplicity        | Easier                      | Slightly more complex              |

---

## 🔧 Core Function Example

```
uint16_t degree_set(int count) {
    uint16_t pulse = 0;
    pulse = 1000 + (15 * count * 1000) / 180;
    return pulse;
}


