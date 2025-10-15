#include "midi.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  stdio_init_all();
  uart_init(uart0, MIDI_BAUD_RATE);
  gpio_set_function(PICO_DEFAULT_UART_TX_PIN, GPIO_FUNC_UART);

  uint8_t channel = 0;
  uint8_t velocity = 100;
  uint8_t c_minor_pentatonic[] = {0x3C, 0x3F, 0x41, 0x43, 0x46, 0x48, 0x4B,
                                  0x4D, 0x4F, 0x52, 0x54, 0x57, 0x59, 0x5C};
  size_t scale_len = sizeof(c_minor_pentatonic) / sizeof(c_minor_pentatonic[0]);
  srand((unsigned)time(NULL));

  while (1) {
    uint8_t note = c_minor_pentatonic[rand() % scale_len];
    midi_note_on(channel, note, velocity);
    sleep_ms(100);
    midi_note_off(channel, note, velocity);
    sleep_ms(100);
  }
  return 0;
}