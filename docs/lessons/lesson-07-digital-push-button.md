# レッスン 07: デジタルプッシュボタン

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト7：デジタルプッシュボタンのイラスト](../media/a8707354e54ea51bb92584f791ae79e5.png)

## 説明

これは基本的なボタンモジュールです。IOシールドに差し込むだけで、Arduinoを簡単に試すことができます。

## 特長

- 3.3Vから5Vまでの広い電圧範囲

- センサーのインターフェースが識別しやすい（「A」はアナログ、「D」はデジタル）

- 標準的な取り付け穴

- 分かりやすいアイコン表示

- 高品質コネクタ

- 差し込みや操作が簡単

- 大型ボタンと高品質キャップ

- 面白くインタラクティブな作品を実現できます

## 仕様

- 供給電圧: 3.3V〜5V

- インターフェース: デジタル

- 寸法: 30×20mm

- 重量: 4g

## 接続図

接続する前に、以下の部品を用意してください：

- V4.0ボード*1

- プッシュボタンモジュール*1

- USBケーブル*1

- ジャンパーワイヤー*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、負のピンをGND、正のピンを5Vに接続してください。

![接続図のイラスト](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## サンプルコード

以下のコードをコピーしてArduinoソフトウェアに貼り付けてください。

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## 動作例

下図のように配線を正しく行い、コードをボードにアップロードしてください。

デジタルボタンを押すと、V4.0ボード上の Led 13 が点灯します。ボタンを離すと、Led 13 は消灯します。以下に示します。

![動作例のイラスト](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
