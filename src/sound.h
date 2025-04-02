#ifndef SOUND_H
#define SOUND_H 

#include <Arduino.h>

#define A0   0
#define As0  1
#define Bf0  1
#define Hf0  1
#define B0   2
#define H0   2

#define C1   3
#define Cs1  4
#define Df1  4
#define D1   5
#define Ds1  6
#define Ef1  6
#define E1   7
#define F1   8
#define Fs1  9
#define Gf1  9
#define G1  10
#define Gs1 11
#define Af1 11
#define A1  12
#define As1 13
#define Bf1 13
#define Hf1 13
#define B1  14
#define H1  14

#define C2  15
#define Cs2 16
#define Df2 16
#define D2  17
#define Ds2 18
#define Ef2 18
#define E2  19
#define F2  20
#define Fs2 21
#define Gf2 21
#define G2  22
#define Gs2 23
#define Af2 23
#define A2  24
#define As2 25
#define Bf2 25
#define Hf2 25
#define B2  26
#define H2  26

#define C3  27
#define Cs3 28
#define Df3 28
#define D3  29
#define Ds3 30
#define Ef3 30
#define E3  31
#define F3  32
#define Fs3 33
#define Gf3 33
#define G3  34
#define Gs3 35
#define Af3 35
#define A3  36
#define As3 37
#define Bf3 37
#define Hf3 37
#define B3  38
#define H3  38

#define C4  39
#define Cs4 40
#define Df4 40
#define D4  41
#define Ds4 42
#define Ef4 42
#define E4  43
#define F4  44
#define Fs4 45
#define Gf4 45
#define G4  46
#define Gs4 47
#define Af4 47
#define A4  48
#define As4 49
#define Bf4 49
#define Hf4 49
#define B4  50
#define H4  50

#define C5  51
#define Cs5 52
#define Df5 52
#define D5  53
#define Ds5 54
#define Ef5 54
#define E5  55
#define F5  56
#define Fs5 57
#define Gf5 57
#define G5  58
#define Gs5 59
#define Af5 59
#define A5  60
#define As5 61
#define Bf5 61
#define Hf5 61
#define B5  62
#define H5  62

#define C6  63
#define Cs6 64
#define Df6 64
#define D6  65
#define Ds6 66
#define Ef6 66
#define E6  67
#define F6  68
#define Fs6 69
#define Gf6 69
#define G6  70
#define Gs6 71
#define Af6 71
#define A6  72
#define As6 73
#define Bf6 73
#define Hf6 73
#define B6  74
#define H6  74

#define C7  75
#define Cs7 76
#define Df7 76
#define D7  77
#define Ds7 78
#define Ef7 78
#define E7  79
#define F7  80
#define Fs7 81
#define Gf7 81
#define G7  82
#define Gs7 83
#define Af7 83
#define A7  84
#define As7 85
#define Bf7 85
#define Hf7 85
#define B7  86
#define H7  86

#define C8  87

#define WHOLE_NOTE            4000
#define DOTTED_HALF_NOTE      3000
#define HALF_NOTE             2000
#define DOTTED_QUARTER_NOTE   1500
#define QUARTER_NOTE          1000
#define DOTTED_EIGHTH_NOTE     750
#define EIGHTH_NOTE            500
#define DOTTED_SIXTEENTH_NOTE  375
#define SIXTEENTH_NOTE         250

typedef struct {
  uint8_t  note_number;
  uint16_t tone_period;
  uint16_t mute_period;
} score_t;

class sound {
  public:
    sound(const float pitch);
    void generate(void);
    void debug_table(void);
    void set_speaker_out(uint8_t spk);
    void play(score_t score[], uint16_t count, float tempo);

  private:
    float    _f;
    uint16_t freq_table[88];
    uint8_t  _spk;
};

#endif
