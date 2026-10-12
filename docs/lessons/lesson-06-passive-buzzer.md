# レッスン 06：パッシブブザー

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト6：パッシブブザーの図](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## 説明

Arduinoを使って多くのインタラクティブな作品を作ることができ、その中でも最もよく使われるのが音と光の表示です。この実験の回路は音を出すことができます。

通常、この実験はブザーまたはスピーカーで行えますが、ブザーの方が簡単で使いやすいです。

ここで紹介するブザーはパッシブブザーです。自ら駆動することはできず、外部からのパルス周波数で駆動します。周波数が異なれば異なる音が出ます。Arduinoを使って曲のメロディをコーディングすることができ、とても楽しく簡単です。

## 仕様

- 動作電圧: 3.3-5v

- インターフェースタイプ: デジタル

- サイズ: 30\*20mm

- 重量: 4g

## 接続図

まず、接続の前に以下の部品を用意してください:

- V4.0 ボード*1

- パッシブブザーモジュール*1

- USBケーブル*1

- ジャンパーワイヤ*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、マイナスピンをGNDポート、プラスピンを5Vポートに接続します。

![接続図のイラスト](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## 実行結果

コードをボードにアップロードすると、ブザーが鳴ります。

![実行結果のイラスト](../media/9b29eccd437694e479a836b7da66d500.png)

---
