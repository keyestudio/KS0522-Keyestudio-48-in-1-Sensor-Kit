# レッスン14：デジタル傾斜スイッチ

> **キット：** Keyestudio 48-in-1 センサーキット  
> **ボード：** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト14：デジタル傾斜スイッチの図](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## 説明

傾斜センサー（Tilt Sensor）はデジタル傾斜スイッチです。シンプルな傾斜スイッチとして使用できます。

IO/Sensorシールドに差し込むだけで配線が簡単です。専用のセンサーシールドとArduinoを使用すれば、さまざまな面白くインタラクティブな作品を作成できます。

## 仕様

- 供給電圧：3.3V〜5V
- インターフェース：デジタル
- サイズ：30*20mm
- 重量：3g

## 接続図

モジュールのSピンをV4.0ボードのDigital 3に接続し、負極ピンをGND端子に、正極ピンを5V端子に接続します。

![接続図（イラスト）](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
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
```

## 実行例

配線と電源を接続し、コードをV4.0ボードに正しくアップロードしたら、次のように動作します。

![実行例（イラスト）](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

センサーを傾けると、センサー上のLEDが点灯します。下図のようになります。

![実行例（イラスト）](../media/6c4a144c26675a100bffa806c532736c.png)

---
