
#include "midi.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"

void midi_note_on(uint8_t channel, uint8_t note, uint8_t velocity) {
  uart_putc_raw(uart0, 0x90 | (channel & 0x0F));
  uart_putc_raw(uart0, note & 0x7F);
  uart_putc_raw(uart0, velocity & 0x7F);
}

void midi_note_off(uint8_t channel, uint8_t note, uint8_t velocity) {
  uart_putc_raw(uart0, 0x80 | (channel & 0x0F));
  uart_putc_raw(uart0, note & 0x7F);
  uart_putc_raw(uart0, velocity & 0x7F);
}
