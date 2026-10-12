# レッスン40: 温度と湿度の表示

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト40: 温度と湿度の表示（イラスト）](../media/e164737761b08de30da9358b47511d62.png)

## 導入

この DHT11 センサーは、温度と湿度を測定する複合センサーで、校正済みのデジタル信号出力を備えています。その技術は高い信頼性と優れた長期安定性を保証します。

センサーには高性能な8ビットマイコンが載っています。このセンサーは抵抗素子と湿度感知用の NTC 温度測定素子を含みます。

優れた品質、応答速度の速さ、耐干渉性、および高いコストパフォーマンスが特徴です。

各 DHT11 センサーには湿度校正室で得られた非常に正確な校正データが含まれています。校正係数は OTP プログラムメモリに格納されており、内部センサーは信号検出時にこれらの校正係数を参照します。

単線シリアルインターフェースが統合されており、迅速かつ簡単に使用できます。小型、低消費電力、20メートルの信号伝送距離といった特性により、広範な用途や要求の厳しい用途にも適しています。

## 仕様

- 供給電圧: +5 V

- 温度範囲: 0-50 °C 誤差 ± 2 °C

- 湿度: 20-90% RH 誤差 ± 5% RH

- インターフェース: デジタル

## 接続図

まずテストの前に次の部品を準備してください。

- V4.0 ボード\*1

- DHT11 センサー\*1

- USB ケーブル\*1

- ジャンパー ワイヤー\*3

次に配線図に従って、センサーの Signal ピンを V4.0 ボードの Digital 4 ポートに接続し、負極ピンを GND ポートに、正極ピンを 5V ポートに接続します。

![接続図（イラスト）](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## サンプルコード

まず [DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) をダウンロードしてください。あるいは [ウェブサイトを訪問](http://playground.arduino.cc/Main/DHTLib)

以下のコードを Arduino ソフトウェアにコピー＆ペーストしてください。

```c
#include <dht.h>

dht DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  Serial.print(F("DHTlib version: "));
  Serial.println(DHT_LIB_VERSION);
  Serial.println(F("Status,Humidity (%),Temperature (C)"));
}

void loop() {
  const int status = DHT.read11(DHT11_PIN);

  switch (status) {
    case DHTLIB_OK:
      Serial.print(F("OK, "));
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print(F("Checksum error, "));
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print(F("Timeout error, "));
      break;
    default:
      Serial.print(F("Unknown error, "));
      break;
  }

  Serial.print(DHT.humidity, 1);
  Serial.print(F(", "));
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
```

## サンプル結果

配線を正しく行い、上記のコードを V4.0 ボードにアップロードします。

![サンプル結果のイラスト](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

次にシリアルモニタを開き、ボーレートを 9600 に設定すると、現在の温度と湿度の値が表示されます。

![サンプル結果のイラスト](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
