# レッスン 43：光学近接検出

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト43：光学近接検出のイラスト](../media/4085d5742012b8647b52c537b82974ff.jpeg)

## はじめに

**互換性についての注意:** 元の説明ではこのモジュールを TMD27713 として記載していますが、下記スケッチは APDS-9930 を対象にしています。IC のマーキングを確認し、アップロード前に対応するライブラリを使用してください。

このモジュールは環境光、近接センサ、および赤外LEDを統合したトリプルセンサです。

一つは環境光（ALS）を検出する用途です。現在の周囲の明るさに応じて、ソフトウェアでバックライトの明るさを自動調整できます。これによりバックライトの明るさを抑えて視力を保護し、省エネ効果を得られます。

もう一つの機能は近接センサ（PROX）です。送受信機が統合されて設計が簡素化されており、設計や取り付けにおけるスペース制約が少なく、構造も比較的単純です。

## パラメータ

- 動作電圧：DC 3.3V

- 検出距離：100mm

- 通信方式：IIC 通信

- 温度範囲：-30℃ 〜 85℃

## 接続図

まず次の部品を用意してください：

- V4.0 ボード*1

- TMD27713 センサ*1

- USBケーブル*1

- ジャンパーワイヤ*5

センサの INT ピンを V4.0 ボードの Digital 2 ポートに、SCL ピンを Analog A5 ポートに、SDA ピンを Analog A4 ポートに接続します；VCC ピンを 3V3 ポート、GND ピンを GND ポートに接続します。

![接続図のイラスト](../media/c9319e0f5116f416380d6b3c9ddc608c.jpeg)

## サンプルコード

APDS-9930 の近接割り込み機能をテストします。

APDS-9930 を I2C 経由で設定し、近接が高/低の条件に基づく外部割り込みを待ちます。手をセンサの近くに動かすと、ピン 13 の LED が点灯するのを確認してください。

## ハードウェア接続

**重要**: APDS-9930 は 3.3V のみ使用できます！

| Arduino ピン | APDS-9930 ボード | 機能       |
| :----------: | :--------------: | :---------: |
|    3.3V      |       VCC        | 電源       |
|     GND      |       GND        | 接地       |
|     A4       |       SDA        | I2C データ |
|     A5       |       SCL        | I2C クロック |
|      2       |       INT        | 割り込み   |
|     13       |        -         | LED        |

**リソース**: Wire.h と APDS9930.h を含めてください

**開発環境の特記事項**: Arduino 1.0.5 で作成

以下のコードを Arduino ソフトウェアにコピー＆ペーストしてください。

```c
#include <Wire.h>
#include <APDS9930.h>

// Pins
#define APDS9930_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define PROX_INT_HIGH   600 // Proximity level for interrupt
#define PROX_INT_LOW    0  // No far interrupt

// Global variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;
uint16_t proximity_data = 0;
volatile bool isr_flag = false;

void setup() {

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9930_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------------"));
  Serial.println(F("APDS-9930 - ProximityInterrupt"));
  Serial.println(F("------------------------------"));

  // Initialize interrupt service routine
  attachInterrupt(digitalPinToInterrupt(APDS9930_INT), interruptRoutine, FALLING);

  // Initialize APDS-9930 (configure I2C and initial values)
  if (apds.init()) {
    Serial.println(F("APDS-9930 initialization complete"));
  }
  else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }

  // Adjust the Proximity sensor gain
  if (!apds.setProximityGain(PGAIN_2X)) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Set proximity interrupt thresholds
  if (!apds.setProximityIntLowThreshold(PROX_INT_LOW)) {
    Serial.println(F("Error writing low threshold"));
  }
  if (!apds.setProximityIntHighThreshold(PROX_INT_HIGH)) {
    Serial.println(F("Error writing high threshold"));
  }

  // Start running the APDS-9930 proximity sensor (interrupts)
  if (apds.enableProximitySensor(true)) {
    Serial.println(F("Proximity sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if (apds.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for (reg = 0x00; reg <= 0x19; reg++) {
    if ((reg != 0x10) && \
      (reg != 0x11))
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

}

void loop() {

  // If interrupt occurs, print out the proximity level
  if (isr_flag) {

    // Read proximity level and print it out
    if (!apds.readProximity(proximity_data)) {
      Serial.println("Error reading proximity value");
    }
    else {
      Serial.print("Proximity detected! Level: ");
      Serial.print(proximity_data);
      Serial.print("   ");
    }
    apds.readAmbientLightLux(ambient_light);
    // Read the light levels (ambient, red, green, blue)
    if (!apds.readAmbientLightLux(ambient_light) ||
      !apds.readCh0Light(ch0) ||
      !apds.readCh1Light(ch1)) {
      Serial.println(F("Error reading light values"));
    }
    else {
      Serial.print(F("Ambient: "));
      Serial.print(ambient_light);
      Serial.print(F("  Ch0: "));
      Serial.print(ch0);
      Serial.print(F("  Ch1: "));
      Serial.println(ch1);
    }

    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9930 interrupt (IMPORTANT!)
    isr_flag = false;
    if (!apds.clearProximityInt()) {
      Serial.println("Error clearing interrupt");
    }

  }
}

void interruptRoutine() {
  isr_flag = true;
}
```

注意: コードをコンパイルする前に、ライブラリを Arduino IDE の libraries ディレクトリに配置することを忘れないでください。そうしないとコンパイルに失敗します。

## 実行例

![実行例のイラスト](../media/f2c369c253c3b5fd8cf2c9df39f1c01a.png)

Arduino-1.8.2 でテストした後、シリアルモニタを開くと下図のようにデータが表示されます。

![実行例のイラスト](../media/607fe1d8c324c14c06492d96d60eb0ca.png)

---
