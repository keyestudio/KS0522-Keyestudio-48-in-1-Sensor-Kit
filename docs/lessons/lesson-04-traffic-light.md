# レッスン04: 信号機

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト4: 信号機のイラスト](../media/a20653cffac8985dc4919614540ac367.jpeg)

## 説明

マイコンを学ぶ際、通常は赤・緑・黄の3つのLEDを外部接続で点滅させ、信号機の点滅を模擬します。

このモジュールは配線が非常に簡単になるよう特別に設計されており、モジュール上に赤、黄、緑のLEDが配置されています。

このモジュールはArduinoマイコンおよびRaspberry Piに完全対応しています。

## 仕様

- 動作電圧: 3.3-5V

- インターフェース: デジタル

- PH2.54 ソケット

## 接続図

まず接続する前に、以下の部品を準備してください：

- V4.0 ボード\*1

- 信号機モジュール \*1

- USB ケーブル\*1

- ジャンパーワイヤ\*4

モジュールの R ピンを V4.0 ボードの Digital 5 に接続し、Y ピンを Digital 4、G ピンを Digital 3、GND ピンをグラウンド端子に接続します。

![接続図イラスト](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
////////////////////////////////////////////////////////////////////
int redled =5; // initialize digital pin 5.
int yellowled =4; // initialize digital pin 4.
int greenled =3; // initialize digital pin 3.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{
digitalWrite(greenled, HIGH);//// turn on green LED
delay(5000);// wait 5 seconds
digitalWrite(greenled, LOW); // turn off green LED
for(int i=0;i<3;i++)// blinks for 3 times
{
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, HIGH);// turn on yellow LED
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, LOW);// turn off yellow LED
}
delay(500);// wait 0.5 seconds
digitalWrite(redled, HIGH);// turn on red LED
delay(5000);// wait 5 seconds
digitalWrite(redled, LOW);// turn off red LED
}
////////////////////////////////////////////////////////////////////
```

## 実行結果

コードをアップロードして電源を入れると、モジュール上の3つのLEDが自動で信号機の点灯・消灯を繰り返します。

![実行結果イラスト](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---
