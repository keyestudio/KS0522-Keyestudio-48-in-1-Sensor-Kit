# レッスン 03: 3W LED

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト 3: 3W LED のイラスト](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## 説明

このLEDモジュールは、搭載されているLED素子が3Wであるため高輝度です。  
Arduinoプロジェクトに応用でき、ロボットや捜索・救助プラットフォームでの使用に最適です。

例えば、自律ロボットが照明用にこのモジュールを使用できます。安全上の理由から、LEDの光を直接人間の目に当てないでください。

## 仕様

- 色温度: 6000\~7000K

- 光束: 180\~210lm

- 電流: 700\~750mA

- 電力: 3W

- ビーム角: 140度

- 動作温度: -50\~80℃

- 保管温度: -50\~100℃

- 高出力LEDモジュール、IOポートでマイコンにより制御

- IOタイプ: デジタル

- 供給電圧: 3.3V〜5V

- サイズ: 40x28mm

- 重量: 6g

## 接続図

まず、接続の前に以下のパーツを準備してください:

- V4.0 ボード\*1

- 3W LEDモジュール\*1

- USBケーブル\*1

- ジャンパー線\*3

モジュールのSピンをV4.0ボードのDigital 13に接続し、負極ピンをGNDに、正極ピンを5Vに接続します。

![接続図のイラスト](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## 実行結果

配線と電源を接続し、コードを正常にアップロードすると、D13のLEDとモジュール上のLEDがそれぞれ1秒点灯して1秒消灯を繰り返します。

![実行例のイラスト](../media/edeb5b089be0300c719652badfd269e7.png)

---
