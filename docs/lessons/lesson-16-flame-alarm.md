# レッスン 16：火炎アラーム

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![プロジェクト16：火炎アラームのイラスト](../media/35c5a2593df5d4e76865158e790feada.png)

## 説明

この火炎センサーは、波長が760nm ～ 1100nmの火やその他の光を検出するために使用できます。

消火ロボットの競技では、火炎は探索において重要な役割を果たし、ロボットが火元を探すための“目”として使用できます。

## 仕様

1. 電源電圧: 3.3V～5V

2. 検出範囲: 20cm (4.8V) ～ 100cm (1V)

3. スペクトル帯域範囲: 760nm～1100nm

4. 動作温度: -25℃から85℃

5. インターフェース: デジタル

6. サイズ: 44*16.7mm

7. 重量: 4g

## 接続図

まず接続の前に次の部品を用意してください:

- V4.0 Board*1

- 火炎センサー*1

- USBケーブル*1

- ジャンパー線*3

モジュールのD0ピンをV4.0ボードのDigital 2に接続し、GNDピンをGNDポートに、VCCピンを5Vポートに接続します。

![接続図のイラスト](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## サンプルコード

以下のコードをArduinoソフトウェアにコピーして貼り付けてください。

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## 実行結果

配線と電源を接続し、コードをボードに正常にアップロードすると、

![実行結果のイラスト](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

ライターをセンサーに近づけると、センサーが火炎を検出した際にセンサー上の別のLEDが点灯します。

![実行結果のイラスト](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---
