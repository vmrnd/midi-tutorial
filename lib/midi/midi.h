
#ifndef MIDI_H
#define MIDI_H

#include <stdint.h>

#define MIDI_BAUD_RATE 31250

void midi_note_on(uint8_t channel, uint8_t note, uint8_t velocity);
void midi_note_off(uint8_t channel, uint8_t note, uint8_t velocity);

#endif // MIDI_H
