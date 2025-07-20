// Servo açısını sayaca göre hesaplar (15°)
uint16_t degree_set(uint8_t count){
	return ((15 * count) * 1000) / 180;  // 15 dereceyi PWM değerine dönüştürür
}

uint8_t last_button_state = 0;   // Önceki buton durumu (debounce)
uint8_t count = 0;               // Buton sayacı

int main(void)
{
  HAL_Init();                  // Donanım soyutlama katmanı başlatılır
  SystemClock_Config();        // Sistem saat ayarları yapılır

  MX_GPIO_Init();              // GPIO pinleri başlatılır
  MX_TIM3_Init();              // Timer3 PWM için başlatılır

  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);  // PWM başlatılır

  while (1)
  {
    uint8_t button_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); // Buton durumu okunur

    // Butona basıldıysa ve önceki durum basılmamışsa
    if ((button_state == GPIO_PIN_SET) && (last_button_state == GPIO_PIN_RESET))
    {
      count++;                      // Sayaç arttırılır
      uint16_t angle_pulse = degree_set(count); // PWM değeri hesaplanır

      if (count <= 12)              // 0° - 180° arası açılar için
      {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (1000 + angle_pulse));  // PWM ayarlanır
        HAL_Delay(150);            // Servo için gecikme
      }
      else if (count > 12 && count <= 24) // 180° - 0° geri dönüş için
      {
        uint8_t reverse_count = 24 - count;
        uint16_t new_angle = (reverse_count * 15 * 1000) / 180;
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (1000 + new_angle));  // PWM geri ayarlanır
        HAL_Delay(150);
      }

      if (count > 24)               // Sayaç sıfırlanır ve servo başlangıç konumuna döner
      {
        count = 0;
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
      }
    }
    last_button_state = button_state; // Buton durumu güncellenir
  }
}
