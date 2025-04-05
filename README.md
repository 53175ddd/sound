# Arduino Sound Library

## 説明

このライブラリは，Arduino IDE に対応した各種マイコンボードで `tone()` 関数を使用して音楽を鳴らす際に，音階に応じた周波数を計算して呼び出したり，専用の構造体 `score_t` 型の配列を用いて楽譜を作ったりすることができる機能を提供するものです．
使い方は次のセクションで説明しています．

## 使い方｜初期設定

以下のようにインスタンスを作成します．

```cpp
#include <sound.h>

#define CONCERT_PITCH 440.0f // 基準音の周波数 (Hz)

sound music(CONCERT_PITCH); // インスタンスの作成
```

この際，マクロ定義またはグローバル変数を用いて基準となる音の周波数を指定してください．
基準音は，通常は A4 (440Hz) ですが，440Hz 以外の音を基準にしたい場合は，そのように値を変更してください．
基準音を変更すると，音階の計算がその基準音に対して行われます．

その後，`setup()` 関数内で以下の関数を呼び出し，音を鳴らす準備をします．

```cpp
void setup() {
  music.set_speaker_out(SPEAKER_PIN); // 音を鳴らす準備
  music.generate();                   // 基準音の周波数を元に各音階の周波数を計算
  // music.debug_table();             // 計算結果を見たい場合に実行
}
```

以上のようにして，初期設定を行います．

## 使い方｜音を鳴らす

音を鳴らすには，`music.play()` 関数を使います．  
この際，構造体 `score_t` を用いて楽譜を作成することで，曲を演奏することができます．

```cpp
#include <sound.h>

#define CONCERT_PITCH 440.0f // 基準音の周波数 (Hz)
#define SPEAKER_PIN     9    // スピーカーのピン番号
#define BPM           120    // テンポ (拍数/分)

score_t sample[] = {{C4, QUARTER_NOTE, 0}, {D4, QUARTER_NOTE, 0}, {E4, QUARTER_NOTE, 0}, {F4, QUARTER_NOTE, 0}, {G4, QUARTER_NOTE, 0}, {A4, QUARTER_NOTE, 0}, {B4, QUARTER_NOTE, 0}, {C5, QUARTER_NOTE, 0}}; // サンプル楽譜

void setup() {
  music.set_speaker_out(SPEAKER_PIN); // 音を鳴らす準備
  music.generate();                   // 基準音の周波数を元に各音階の周波数を計算

  music.play(sample, sizeof(sample) / sizeof(score_t), BPM); // 楽譜を演奏
}

void loop() {
}
```

この例では，`sample` という配列に音階と音符の長さを指定して楽譜を作成し，`music.play()` 関数を使って演奏しています．

音階及び音の長さは，`sound.h` 内で定義されているマクロを使って指定します．

音階は `A0` から `C8` までの音を指定することができます．これはピアノの音域に対応しています．  
基本的な音（ピアノの白鍵に相当）はそのまま `A4` などと，シャープやフラットが付く音は音階を表すアルファベットと数字の間に `s`（シャープ）や `f`（フラット）を挿入して指定します．
例えば，`C4` はドの音の 4 オクターブ目を表し，`Ds4` はド♯の音の 4 オクターブ目を表します．

音の長さは，以下のものを指定可能です．

- `WHOLE_NOTE` (全音符)
- `DOTTED_HALF_NOTE` (付点二分音符)
- `HALF_NOTE` (二分音符)
- `DOTTED_QUARTER_NOTE` (付点四分音符)
- `QUARTER_NOTE` (四分音符)
- `DOTTED_EIGHTH_NOTE` (八分音符)
- `EIGHTH_NOTE` (八分音符)
- `DOTTED_SIXTEENTH_NOTE` (十六分音符)
- `SIXTEENTH_NOTE` (十六分音符)

これと，音を鳴らした後にミュートする時間を組み合わせて，配列を作成します．
例えば，`score_t c4_quarter_single[1] = {{C4, QUARTER_NOTE, 0}};` は C4 の音を四分音符の長さで鳴らし，その後にミュートする時間は 0 秒という意味になります．

## Tips

同じ高さの音が続く場合は，音の長さを指定するだけでなく，ミュートの時間を指定することで，連続した音にならず，より自然な演奏が可能になります．
例えば，`score_t c4_quarter_twice[2] = {{C4, QUARTER_NOTE - 10, 10}, {C4, QUARTER_NOTE, 0}};` のようにすると，C4 の音を四分音符の長さで連続して鳴らしますが，その間に若干のミュートを入れることができます．注意点として，ただ三番目の要素に値を入れるだけではその分伸びてしまうので，それを打ち消すように音の長さを短くする必要があります．

休符は，直前の音のミュート時間の要素に書くだけで実現できます．  
例えば，`score_t c4_quarter_rest[2] = {{C4, QUARTER_NOTE, QUARTER_NOTE}, {C4, QUARTER_NOTE, 0}};` のようにすると，C4 の音を四分音符の長さで連続して鳴らしますが，その間に四分休符を入れることができます．

サンプルコード内の `simple_sample` というコードの中では，歓喜の歌（ode_to_joy）のスコア配列を用意しています．参考にしてください．
