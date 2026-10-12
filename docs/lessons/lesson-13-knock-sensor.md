# レッスン13：ノックセンサー

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト13：ノックセンサーのイラスト](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## 説明

このモジュールはノックセンサーです。叩くと一時的な信号を送ります。

Arduinoと組み合わせて、電子ドラムなどの面白い実験を行うことができます。

## 仕様

- 動作電圧: 5V

- サイズ: 30\*20mm

- 重量: 3g

## 接続図

まず、接続する前に以下の部品を用意してください:

- V4.0 ボード\*1

- ノックセンサー \*1

- USBケーブル\*1

- ジャンパー線\*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、負極ピンをGNDポート、正極ピンを5Vポートに接続します。

![接続図のイラスト](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![サンプルコードのイラスト](../media/c3fc14de7267b517a739268ed5b88674.png)

## 実行結果

上記の配線と電源供給が完了し、コードを正しくアップロードしたら、センサーを叩くとV4.0ボード上のD13 LEDとセンサー上のD1 LEDの両方が点灯します。

---
