#include "sound.h"

sound::sound(const float pitch) {
  _f = pitch;
}

void sound::generate(void) {
  freq_table[48] = (uint16_t)_f;

  float f = _f;

  for(int8_t i = 47; 0 <= i; i--) {
    f = f / 1.05946309436;
    freq_table[i] = (uint16_t)f;
  }

  f = _f;

  for(int8_t i = 49; i < 88; i++) {
    f = f * 1.05946309436;
    freq_table[i] = (uint16_t)f;
  }
}

void sound::debug_table(void) {
  for(int8_t i = 0; i < (sizeof(freq_table) / sizeof(freq_table[0])); i++) {
    char buffer[32];
    sprintf(buffer, "freq_table[%2d] = %4d\n", i, freq_table[i]);
    Serial.print(buffer);
  }
}

void sound::set_speaker_out(uint8_t spk) {
  _spk = spk;
}

void sound::play(score_t score[], uint16_t count, float tempo) {
  for(uint16_t i = 0; i < count; i++) {
    uint16_t f = freq_table[score[i].note_number];  
    uint16_t p = score[i].tone_period * 60 / tempo;
    uint16_t m = score[i].mute_period * 60 / tempo;

    char buffer[32];
    sprintf(buffer, "freq = %d / delay = %d\n", f, p + m);
    Serial.print(buffer);
    
    tone(_spk, f, p);
    delay(p + m);
  }
}

void sound::play2(score_t score[], uint16_t count, int8_t shift, float tempo) {
  for(uint16_t i = 0; i < count; i++) {
    uint16_t f = freq_table[score[i].note_number + shift];  
    uint16_t p = score[i].tone_period * 60 / tempo;
    uint16_t m = score[i].mute_period * 60 / tempo;

    char buffer[32];
    sprintf(buffer, "freq = %d / delay = %d\n", f, p + m);
    Serial.print(buffer);
    
    tone(_spk, f, p);
    delay(p + m);
  }
}
