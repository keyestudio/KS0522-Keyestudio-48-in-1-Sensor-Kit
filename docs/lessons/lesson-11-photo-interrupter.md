# レッスン11: フォトインタラプタ

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト11: フォトインタラプタの図](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## 説明

このセンサーの直立した部分は赤外線発光部で、反対側には遮蔽された赤外線検出部があります。一端から他端へ赤外線ビームを発射することで、物体がビームを通過したときに検出できます。

光学的リミットスイッチ、ペレット供給、一般的な物体検出など、多くの用途に使用されます。

## 仕様

- 電源電圧: 3.3V to 5V

- インターフェース: デジタル

- サイズ: 30*20mm

- 重量: 3g

## 接続図

接続の前に、まず以下の部品を用意してください:

- V4.0ボード\*1

- フォトインタラプタモジュール \*1

- USBケーブル\*1

- ジャンパーワイヤ\*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、負極ピンをGNDポートへ、正極ピンを5Vポートへ接続します。

![接続図のイラスト](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピーして貼り付けてください。

```c
////////////////////////////////////////////////////////////////////
// photo interrupter module
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## 実行結果

ボードへコードの書き込みが完了すると、V4.0ボード上とモジュール上の両方のLEDが点灯します。以下のように表示されます。

![実行結果のイラスト](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

モジュールの溝部分に紙を差し込むと信号が遮断され、モジュール上のLED1が消灯します。

![実行結果のイラスト](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---
