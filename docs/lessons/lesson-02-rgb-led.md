# レッスン 02: RGB LED

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト2: RGB LED イラスト](../media/de14ae0679267cf87837b7c09934c52e.png)

## 説明

これはフルカラーLEDモジュールで、赤、緑、青という3つの基本色を含んでいます。それぞれは個別のLEDとして見ることができます。

プログラムにより、順番に点灯・消灯させたり、PWMのアナログ出力を使用して3色を混合し、さまざまな色を生成することができます。

## 仕様

- 色: 赤、緑、青

- 明るさ: 高

- 電圧: 5V

- 入力: デジタルレベル

- サイズ: 30 \*20mm

- 重量: 3g

## 接続図

まず、接続の前に以下の部品を用意してください:

- V4.0 ボード\*1

- RGB LEDモジュール \*1

- USBケーブル\*1

- ジャンパーワイヤー\*4

モジュールのVピンをV4.0ボードの5Vポートに接続し、BピンをDigital 11、RピンをDigital 10、GピンをDigital 9に接続します。

![接続図イラスト](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## サンプルコード

以下のコードをArduinoソフトにコピー＆ペーストしてください。

```c
const uint8_t redPin = 11;
const uint8_t bluePin = 10;
const uint8_t greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int value = 255; value >= 0; --value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
  for (int value = 0; value < 255; ++value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
}
```

## 例の結果

配線と電源を接続し、コードを問題なくアップロードすると、RGB LEDモジュールが鮮やかな色を発光します。

![実例イラスト](../media/0872e5256edf443efcb68218505096ba.png)

---
