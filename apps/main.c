
#include "midi.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  uart_init(uart0, MIDI_BAUD_RATE);
  gpio_set_function(PICO_DEFAULT_UART_TX_PIN, GPIO_FUNC_UART);

  uint8_t channel = 0;
  uint8_t note = 60;
  uint8_t velocity = 100;
  while (1) {
    midi_note_on(channel, note, velocity);
    sleep_ms(500);
    midi_note_off(channel, note, velocity);
    sleep_ms(500);
  }
  return 0;
}