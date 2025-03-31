#include "sound.h"

void culc_freq_table(const float pitch) {
  float f;
  
  f = pitch;

  freq_table[48] = (uint16_t)round(f);

  for(int8_t i = 47; 0 <= i; i--) {
    f = f / pow(2, 1/12);
    freq_table[i] = (uint16_t)round(f);
  }

  f = pitch;

  for(int8_t i = 49; i < 88; i++) {
    f = f * pow(2, 1/12);
    freq_table[i] = (uint16_t)round(f);
  }
}

void set_speaker_out(uint8_t spk) {
  _spk = spk;
}

void play(score_t score[], uint16_t count, float tempo) {
  for(uint16_t i = 0; i < count; i++) {
    uint16_t f = freq_table[score[i].note_number];  
    uint16_t p = score[i].tone_period * (60 / tempo) * 1000;
    uint16_t m = score[i].mute_period * (60 / tempo) * 1000;

    tone(_spk, f, p);
    delay(p + m);
  }
}
