# レッスン34: デジタル赤外線送信機

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト34: デジタル赤外線送信機 イラスト](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## 説明

IR送信モジュールはIR通信向けに設計されており、短距離の視線（ライン・オブ・サイト）でテレビなどの機器を操作する用途で広く使われています。

赤外線（IR）リモコンは光を使用するため、操作対象機器への視線が必要です。ただし、赤外線信号は他の光源と同様に鏡で反射することもあります。

赤外線受信機は、受光素子（フォトトランジスタ）の光学特性により、動作角がある程度制限される傾向があります。

しかし、受信機の前に半透明のマットな物体を置くことで、動作角を簡単に広げることができます。

## 仕様

- 電源: 3-5V

- 赤外線中心波長: 850nm-940nm

- 赤外線放射角: 約20度

- 赤外線送信距離: 約1.3m（5V 38Khz）

- インターフェースソケット: JST PH2.0

- 取付穴: 内径は3.2mm、間隔は15mm

## 接続図

まず接続する前に以下の部品を用意してください。

- V4.0 ボード\*1

- IR送信モジュール\*1

- USBケーブル\*1

- ジャンパー線\*3

モジュールのSピンをV4.0ボードのDigital 3に接続し、負極ピンをGNDポート、正極ピンを5Vポートに接続します。

![接続図 イラスト](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## サンプルコード1

```c
int led = 3;
void setup() {
   pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
```

暗い環境では、赤外線LEDをスマートフォンのカメラで撮影すると、画面に青い点滅光が見えます。

上記のコードをボードにアップロードすると、センサー上のLEDが赤く点滅します。

以下では、IR受信モジュールとIR送信モジュール間のインタラクティブな例に進みます。

## 赤外線リモコン/通信

## 必要なハードウェア

- Arduino R3 ×2

- デジタルIR受信機 ×1

- IR送信モジュール ×1

注意: この実験には2枚のマイコンボードが必要です。ブレッドボードは受信側のスケッチを実行できないため、2枚目のボードの代わりにはなりません。

## 二枚のボードによる通信設定

## IR送信機用

注意: Arduino-IR リモコンは送信にD3のみをサポートします。

![IR送信機用 イラスト](../media/08ebf9b37949caf1782e499f49934f1d.png)

## IR受信機用

信号ピンをD11ポートに接続してください。

![IR受信機用 イラスト](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## IR送信機に接続したV4.0へコード2をアップロード

```c
 #include <IRremote.h>
  IRsend irsend;
 void setup()
 {}
 void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8);
     delay(200); }
```

## IR受信機に接続したV4.0へコード3をアップロード

```c
#include <IRremote.h>
 const int RECV_PIN = 11;
 const int LED_PIN = 13;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
 {Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
 }
  void loop()
 {if (irrecv.decode(&results))
   { if ( results.bits > 0 )
     {

       int state;
       if ( 0x1 == results.value )
       {
         state = HIGH;
       }
       else
       {
         state = LOW;
       }
       digitalWrite(LED_PIN, state);
     }
  irrecv.resume();        // prepare to receive the next value
   }}
```

## 結果

IR受信モジュールがIR送信機から赤外線信号を受信すると、IR受信モジュール上のD1 LEDが点滅します。

IR受信モジュールがIR送信機から赤外線信号を受信すると、IR受信モジュール上のD1 LEDが点滅します。

![結果 イラスト](../media/4d73a7178e89de72df7e82a147778ae9.png)

---
