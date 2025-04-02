#include <sound.h>

#define CONCERT_PITCH 440.0f

#define SPK   14  // adapt to your circuit
#define SHIFT  3

sound music(CONCERT_PITCH);

// definition of score_t
//
// typedef struct {
//   uint8_t  note_number;  // note number. A4 + SHIFT is defined as 4 + SHIFT8.
//   uint16_t tone_period;  // length of it.
//   uint16_t mute_period;  // length of muted time after each note. normaly zero.
// } score_t;

score_t ode_to_joy[] = {{C5 + SHIFT, QUARTER_NOTE - 10, 10}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {Ds5 + SHIFT, QUARTER_NOTE - 10, 10}, {Ds5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0},
                        {Gs4 + SHIFT, QUARTER_NOTE - 10, 10}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE - 10, 10}, {C5 + SHIFT, DOTTED_QUARTER_NOTE, 0}, {As4 + SHIFT, EIGHTH_NOTE - 10, 10}, {As4 + SHIFT, HALF_NOTE, 0},
                        {C5 + SHIFT, QUARTER_NOTE - 10, 10}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {Ds5 + SHIFT, QUARTER_NOTE - 10, 10}, {Ds5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0},
                        {Gs4 + SHIFT, QUARTER_NOTE - 10, 10}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, DOTTED_QUARTER_NOTE, 0}, {Gs4 + SHIFT, EIGHTH_NOTE - 10, 10}, {Gs4 + SHIFT, HALF_NOTE, 0},
                        {As4 + SHIFT, QUARTER_NOTE - 10, 10}, {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, EIGHTH_NOTE, 0}, {Cs5 + SHIFT, EIGHTH_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Gs4 + SHIFT, QUARTER_NOTE, 0},
                        {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, EIGHTH_NOTE, 0}, {Cs5 + SHIFT, EIGHTH_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0}, {Ds4 + SHIFT, QUARTER_NOTE, 0},
                        {C5 + SHIFT, HALF_NOTE - 10, 10}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {Ds5 + SHIFT, QUARTER_NOTE - 10, 10}, {Ds5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {Cs5 + SHIFT, EIGHTH_NOTE, 0}, {As4 + SHIFT, EIGHTH_NOTE, 0},
                        {Gs4 + SHIFT, QUARTER_NOTE - 10, 10}, {Gs4 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, QUARTER_NOTE, 0}, {C5 + SHIFT, QUARTER_NOTE, 0}, {As4 + SHIFT, DOTTED_QUARTER_NOTE, 0}, {Gs4 + SHIFT, EIGHTH_NOTE - 10, 10}, {Gs4 + SHIFT, DOTTED_HALF_NOTE, DOTTED_HALF_NOTE}};

void setup() {
  Serial.begin(115200);

  music.set_speaker_out(SPK);
  music.generate();
  music.debug_table();

  music.play(ode_to_joy, sizeof(ode_to_joy) / sizeof(score_t), 124);
}

void loop() {
}
