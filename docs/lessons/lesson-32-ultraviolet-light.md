# レッスン 32: 紫外線

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト32：紫外線のイラスト](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## 説明

Keyestudio GUVA-S12SD 紫外線センサーは紫外線を検出するために使用されます。GUVA-S12SD は時計、スマートフォンや紫外線インデックス検出機能を持つ屋外機器などのウェアラブルデバイスの紫外線インデックスを測定する用途に適しています。

また、紫外線の強度を監視したり、紫外線で消毒する際の UV 光検出器としても使用できます。

## 仕様

- サイズ: 15mm×30mm×0.7mm

- 供給電圧: 2.5V～5V

- 出力信号: アナログ信号

- 検出スペクトル範囲: 240-370nm

- 有効領域: 0.076mm2

- 感度: 0.14A/W

- 暗電流: 1nA

- 光電流: 101\~125nA（UVA 光、1mW/cm2）

## 接続図

まず接続する前に次の部品を用意してください。

- V4.0 ボード\*1

- GUVA-S12SD 3528 紫外線センサー \*1

- USB ケーブル\*1

- ジャンパーワイヤー\*3

モジュールの S ピンを V4.0 ボードのアナログ A0 に接続し、負極ピンを GND ポート、正極ピンを 3V3 ポートに接続します。

![接続図のイラスト](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## サンプルコード

以下のコードを Arduino ソフトウェアにコピーして貼り付けてください。

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## 実行例

![実行例のイラスト](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

配線を正しく行い、プログラムを書き込んだらシリアルモニタを開くとデータが表示されます。

センサーに紫外線を照射すると、シリアルモニタ上のデータが次の画像のように変化します。

![実行例のイラスト](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![実行例のイラスト](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---
