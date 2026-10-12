# レッスン33: デジタルIR受信機

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト33: デジタルIR受信機のイラスト](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## 説明

IR（赤外線）はリモコンで広く使われています。このIR受信機を使えば、正しいデコーダがあればArduinoプロジェクトで任意の赤外線リモコンからのコマンドを受信できます。もちろん、IR送信機を使って独自のIRコントローラを作るのも簡単です。

## 仕様

- 電源: 5V

- インターフェース: デジタル

- 変調周波数: 38Khz

- モジュールインターフェースソケット: JST PH2.0

- サイズ: 30*20mm

- 重量: 4g

## 接続図

まず接続する前に以下の部品を準備してください。

- V4.0 ボード\*1

- IR レシーバーモジュール\*1

- USB ケーブル\*1

- ジャンパー線\*3

モジュールのSピンをV4.0ボードのデジタルピン11に接続し、負極ピンをGND、正極ピンを5Vに接続します。

![接続図](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

下のサンプルコードではデジタルピン11が使用されています。配線を変更するか、サンプルコードを変更して一致させてください。

## サンプルコード

以下のコードをArduinoソフトウェアにコピー＆ペーストしてください。

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**注意:** コードをコンパイルする前に、ライブラリをArduino IDEのlibrariesディレクトリに配置するのを忘れないでください。そうしないとコンパイルは失敗します。

IR Remote Libraryには送信と受信のサンプルコードが含まれています。

<https://github.com/shirriff/Arduino-IRremote>

## 実行結果の例

![実行結果の例](../media/2692333113be48ffa11c27649d18dcb8.png)

配線とコードのアップロードが完了したら、赤外線リモコンでIR受信モジュールを操作するとD1のLEDが点滅します。

![実行結果の例](../media/4bb52e2957e3aaeace252021e7084c95.png)

---
