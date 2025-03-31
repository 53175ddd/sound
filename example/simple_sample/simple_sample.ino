#include <sound.h>

#define CONCERT_PITCH 440.0f

#define SPK 14  // adapt to your circuit

// definition of score_t
// typedef struct {
//   uint8_t  note_number;  // note number. A4 is defined as 48.
//   uint16_t tone_period;  // length of it.
//   uint16_t mute_period;  // length of muted time after each note. normaly zero.
// } score_t;

score_t ode_to_joy[] = {{C5, QUARTER_NOTE - 10, 10}, {C5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {Ds5, QUARTER_NOTE - 10, 10}, {Ds5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {As4, QUARTER_NOTE, 0},
                        {Gs4, QUARTER_NOTE - 10, 10}, {Gs4, QUARTER_NOTE, 0}, {As4, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE - 10, 10}, {C5, DOTTED_QUARTER_NOTE, 0}, {As4, EIGHTH_NOTE - 10, 10}, {As4, HALF_NOTE, 0},
                        {C5, QUARTER_NOTE - 10, 10}, {C5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {Ds5, QUARTER_NOTE - 10, 10}, {Ds5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {As4, QUARTER_NOTE, 0},
                        {Gs4, QUARTER_NOTE - 10, 10}, {As4, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {As4, DOTTED_HALF_NOTE, 0}, {Fs4, EIGHTH_NOTE - 10, 10}, {Fs4, HALF_NOTE, 0},
                        {As4, QUARTER_NOTE - 10, 10}, {As4, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {Gs4, QUARTER_NOTE, 0}, {As4, HALF_NOTE, 0}, {C5, EIGHTH_NOTE, 0}, {Cs5, EIGHTH_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {Gs4, QUARTER_NOTE, 0},
                        {As4, HALF_NOTE, 0}, {C5, EIGHTH_NOTE, 0}, {Cs5, EIGHTH_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {Gs4, QUARTER_NOTE, 0},{Gs4, QUARTER_NOTE, 0}, {As4, QUARTER_NOTE, 0}, {Bs4, QUARTER_NOTE, 0},
                        {C5, HALF_NOTE - 10, 10}, {C5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {Ds5, QUARTER_NOTE - 10, 10}, {Ds5, QUARTER_NOTE, 0}, {Cs5, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {Cs5, EIGHTH_NOTE, 0}, {As4, EIGHTH_NOTE, 0},
                        {Gs4, QUARTER_NOTE - 10, 10}, {Gs4, QUARTER_NOTE, 0}, {As4, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}, {As4, DOTTED_QUARTER_NOTE, 0}, {Gs4, EIGHTH_NOTE - 10, 10}, {Gs4, DOTTED_HALF_NOTE, DOTTED_HALF_NOTE}};

void setup() {
  culc_freq_table(CONCERT_PITCH);
  set_speaker_out(SPK);

  play(ode_to_joy, sizeof(ode_to_joy) / sizeof(score_t), 124);
}

void loop() {
}
