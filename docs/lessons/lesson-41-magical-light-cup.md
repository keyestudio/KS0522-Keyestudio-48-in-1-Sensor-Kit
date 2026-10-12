# レッスン41: マジカルライトカップ

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328Pボード

![プロジェクト41: マジカルライトカップのイラスト](../media/dc3acff676b2611f440643f1657b42e7.png)

## はじめに

マジックライトカップモジュールはArduinoと連動できます。原理はPWMによる調光です。

モジュール上の水銀スイッチはデジタル信号を供給し、PWM制御をトリガーします。プログラム設計により2つのモジュールの明るさが一緒に変化し、最終的に2つのカップが光を注ぐような変化効果が見られます。

## 仕様

- 電源電圧: 3.3V～5V

- インターフェース: デジタル

## 接続図

![接続図のイラスト](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
///////////////////////////////////////////////////////////////
int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);
pinMode(LedPinA, OUTPUT);
pinMode(LedPinB, OUTPUT);

pinMode(ButtonPinA, INPUT);
pinMode(ButtonPinB, INPUT);
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);
if (buttonStateA == HIGH && brightnessA != 255)
{
brightnessA ++;
}
if (buttonStateA == LOW && brightnessA != 0)
{
brightnessA --;
}
analogWrite(LedPinB, brightnessA);
Serial.print(brightnessA);

Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);
if (buttonStateB == HIGH && brightnessB != 0)
{
brightnessB --;
}
if (buttonStateB == LOW && brightnessB != 255)
{
brightnessB++;
}
analogWrite(LedPinA, brightnessB);
Serial.println(brightnessB);
delay(5);
}
///////////////////////////////////////////////////////////////
```

## 実行結果

![実行例のイラスト](../media/f629888f2fedea9442ba74dc8761fcb3.png)

上の図のように配線し、コードをボードにアップロードすると、片方のカップが点灯してもう片方が消灯しているのが見えます。これら2つのカップを同じ側に傾けると、片方が徐々に明るくなり、もう片方の明るいカップが徐々に暗くなります。

![実行例のイラスト](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---
