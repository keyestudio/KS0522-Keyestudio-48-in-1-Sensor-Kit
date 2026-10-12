# レッスン 35: パルスレートモニター

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328Pボード

![プロジェクト35: パルスレートモニター イラスト](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## 説明

このモジュールは、超鮮明な赤外LEDとフォトトランジスタを使用して、指先の脈拍を検出します。赤色LEDは脈拍に合わせて点滅します。

動作原理

指の片側に明るいLEDを照射し、反対側のフォトトランジスタが透過光の量を検出します。血液が指を流れる際にフォトトランジスタの抵抗がわずかに変化します。

## 接続図

まずテストを行う前に以下の部品を用意してください。

- V4.0 ボード\*1

- パルスモジュール\*1

- USB ケーブル\*1

- ジャンパーワイヤー\*3

モジュールのSignalピンをV4.0ボードのAnalog A0に接続し、正極ピンを5Vポートに、負極ピンをGNDポートに接続します。

![接続図イラスト](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## サンプルコード

下記のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## 実行結果

上の図のように配線を正しく行い、コードをボードにアップロードしてから、Arduinoソフトウェアの右上にあるシリアルモニタのアイコンをクリックします。ボーレートを115200に設定すると、モニタにデータが表示されます。

データをExcelにコピー＆ペーストすると、最終的に下に示す対応するグラフが生成されます。

![実行結果イラスト](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![実行結果イラスト](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---
