# レッスン23: 水位

> **キット：** Keyestudio 48-in-1 センサーキット  
> **ボード：** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト23: 水位のイラスト](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## 説明

Keyestudioの水センサーは使いやすく、携帯性に優れ、コスト効果の高い設計で、水位や水滴の検知に使用されます。

この小型センサーは、露出した並列配線のトレース配列を通じて、水滴の量や水の量を測定できます。

## 特徴

- 水量とアナログ量の間の滑らかな変換;
- 高い柔軟性で、基本的なアナログ値を出力;
- 低消費電力かつ高感度;
- マイクロプロセッサやその他の論理回路に直接接続可能で、Arduinoコントローラ、STC単一チップマイコン、AVR単一チップマイコンなど、さまざまな開発ボードやコントローラに適合。

## 仕様

- 動作電圧: DC5V
- 動作電流: <20mA
- センサータイプ: アナログ
- 検出面積: 40mm x16mm
- 製造工程: FR4 両面スズメッキ
- 形状設計: 滑り止め半月状凹み
- 動作温度: 10℃-30℃
- 動作湿度: 結露なき状態で10%-90%
- 重量: 3g
- 寸法: 65mm x 20mm x 8mm

## 接続図

モジュールのSピンをV4.0ボードのアナログA0に接続し、負極をGNDポート、正極を5Vポートに接続します。

![接続図のイラスト](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## サンプルコード

下のコードをArduinoソフトウェアにコピーして貼り付けます。

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## 実行結果

![実行結果のイラスト](../media/ca727c75f4d4e454c95258d77afdf10e.png)

上記の手順が完了したら、低い水位でテストしてどうなるか確認してみましょう。

コードをV4.0ボードにアップロードし、シリアルモニタを開いてボーレートを9600に設定します。

センサーを異なる水位に入れると、値がそれに応じて変化するのが確認できます。

![実行結果のイラスト](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

さらに、警報値を設定してブザーを接続し、アラームを鳴らすことができます。

水位が警報値に達していない場合、LEDは点灯しません。水位が警報値に達すると、LEDが点灯し、ブザーが鳴ってアラームを発します。

---
