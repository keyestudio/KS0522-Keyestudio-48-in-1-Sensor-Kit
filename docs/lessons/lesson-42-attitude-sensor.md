# レッスン 42：姿勢センサー

> **キット：** Keyestudio 48-in-1 Sensor Kit  
> **ボード：** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト42：姿勢センサーのイラスト](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## 導入

**互換性に関する注意。** 部品表ではこのボードを APDS-9930 と表示していますが、以下のレガシーな例は APDS-9960 を対象としており `SparkFun_APDS9960` を使用します。スケッチをアップロードする前に実際のモジュールの IC マーキングを確認してください。APDS-9930 基板ではこの例を使用しないでください。単一の8ピンパッケージの APDS-9930 は、I2C インターフェイスに対応した環境光センサと赤外 LED 近接センサを提供できます。

完全に調整された近接センサは100mm の物体を検出でき、端末装置やサブコンポーネントの工場校正要件を不要にします。

明るい日光から暗い部屋まで、近接センサの近接検出機能は良好に動作します。

このモジュールはマイクロ光学レンズを追加しており、赤外線の効率的な送受信を提供し、全体の消費電力を低減できます。

さらに、内部のステートマシンによりデバイスを低消費電力モードにでき、非常に低い平均消費電力を実現します。

## 仕様

- 動作電圧：DC 3.3-3.8V

- 出力電流：0-20mA

- 温度範囲：-40℃—85℃

## 特徴

1. ALS、赤外 LED、および近接検出器を統合した光学モジュール
2. 最大16ビットの分解能
3. ダークガラス越しでも高感度に動作
4. 0.01 lux の低照度性能
5. 近接検出は工場で完全に較正され、100 mm の検出を実現
6. 赤外 LED および同期 LED ドライバを統合
7. 近接センサの工場較正を不要化
8. プログラム可能な待機タイマ、待機状態の消費電流 - 90 μA（代表値）
9. プログラム可能な範囲は2.7ミリ秒から8秒まで
10. I2C インターフェイス互換、最大400kHz（I2C ファストモード）
11. 専用の割り込みピン
12. スリープモード消費電流 - 2.2 μA（代表値）

## 接続図

まず、以下の部品を準備してください:

- V4.0 ボード\*1

- 姿勢センサー\*1

- USB ケーブル\*1

- ジャンパーワイヤー\*5

センサーの INT ピンを V4.0 ボードの Digital 2 ポートに接続、SCL ピンを Analog A5 ポートに、SDA ピンを Analog A4 ポートに接続；3V3 ピンを 3V3 ポートに、GND ピンを GND ポートに接続します。

![接続図のイラスト](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## サンプルコード

**重要**: APDS-9960 は 3.3V のみ受け付けます!

## ハードウェア接続

| Arduino Pin | APDS-9960 Board | 機能      |
| :---------: | :-------------: | :--------: |
|    3.3V     |       VCC       |   電源    |
|     GND     |       GND       |   グランド |
|     A4      |       SDA       | I2C データ |
|     A5      |       SCL       | I2C クロック |
|     D2      |       INT       | 割り込み   |
|     D13     |        -        |    LED    |

**リソース：** Wire.h と SparkFun_APDS-9960.h を含めます

**開発環境の詳細：** Arduino 1.0.5 で作成

以下のコードを Arduino ソフトウェアにコピー＆ペーストしてください。

```c
#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH  1000 // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9960_INT, INPUT);
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("-------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));
  Serial.println(F("-------------------------------------"));
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  // Set high and low interrupt thresholds
  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {
    Serial.println(F("Error writing low threshold"));
  }
  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {
    Serial.println(F("Error writing high threshold"));
  }
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  // Read high and low interrupt thresholds
  if ( !apds.getLightIntLowThreshold(threshold) ) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if ( !apds.getLightIntHighThreshold(threshold) ) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }
  // Enable interrupts
  if ( !apds.setAmbientLightIntEnable(1) ) {
    Serial.println(F("Error enabling interrupts"));
  }
  // Wait for initialization and calibration to finish
  delay(500);
}
void loop() {
  // If interrupt occurs, print out the light levels
  if ( isr_flag == 1 ) {

    // Read the light levels (ambient, red, green, blue) and print
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      Serial.print("Interrupt! Ambient: ");
      Serial.print(ambient_light);
      Serial.print(" R: ");
      Serial.print(red_light);
      Serial.print(" G: ");
      Serial.print(green_light);
      Serial.print(" B: ");
      Serial.println(blue_light);
    }
    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
    isr_flag = 0;
    if ( !apds.clearAmbientLightInt() ) {
      Serial.println("Error clearing interrupt");
    }
  }
}
void interruptRoutine() {
  isr_flag = 1;
}
```

注意: コードをコンパイルする前に、ライブラリを Arduino IDE の libraries ディレクトリに配置するのを忘れないでください。そうしないとコンパイルに失敗します。

## 実行結果の例

![実行結果のイラスト](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

コードをアップロードしたら、シリアルモニタを開き、ボーレートを9600に設定してください。

![実行結果のイラスト](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---
