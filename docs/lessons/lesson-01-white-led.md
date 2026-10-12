# レッスン01：白色LED

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換のATmega328Pボード

![プロジェクト1：白色LEDのイラスト](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## 説明

この白色LEDモジュールはArduinoの入門者に最適です。IO/Sensorシールドに簡単に接続でき、光に関連するさまざまな動作と連動できます。

注意：黄色、赤、緑、青など、異なる色を発光する他のLEDモジュールを選ぶこともできます。

## 仕様

- 白色LEDモジュール

- タイプ: デジタル

- PH2.54ソケット

- サイズ: 30\*20mm

- 重量: 3g

## 接続図

まず、接続する前に次の部品を用意してください：

- V4.0ボード\*1

- 白色LEDモジュール \*1

- USBケーブル\*1

- ジャンパー線\*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、負極ピンをGNDポートに、正極ピンを5Vポートに接続します。

![接続図のイラスト](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
const uint8_t ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

## 実行結果の例

配線と電源を接続してコードをアップロードすると、LEDモジュールが白色の光を点灯します。

![実行結果のイラスト](../media/40448f38601a6312bfb1e3764be22158.png)

---
