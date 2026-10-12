# レッスン44: 三軸デジタル加速度検出

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト44：三軸デジタル加速度検出の図](../media/2a26949601eb888348b798711fe1151e.jpeg)

## はじめに

MMA8452Qはスマートで低消費電力の三軸静電容量マイクロマシン加速度センサーで、12ビットの分解能を持ちます。

この加速度センサーは豊富な内蔵機能を備えており、柔軟なユーザープログラム可能なオプションと2つの割り込みピン構成を特徴としています。

内蔵の割り込み機能により、全体の消費電力を削減でき、メインプロセッサでデータを常時ポーリングする負担を軽減します。

さらに、MMA8452Qはユーザーが選択可能な±2g / ±4g / ±8gのレンジを持ち、ハイパスフィルタ処理されたデータと非フィルタデータをリアルタイムで出力できます。

本デバイスは慣性によるウェイクアップ割り込み信号を生成する内蔵機能を設定でき、静止状態でイベントを監視しながら低消費電力モードを維持できます。

## 性能パラメータ

- 電源電圧：1.95 V ～ 3.6 V

- インターフェース電圧：1.6 V ～ 3.6 V

- ±2g/±4g/±8g 選択可能な動作レンジ

- 出力データレート（ODR）範囲：1.56Hz ～ 800Hz

- ノイズ：99μg/√Hz

- 12ビットおよび8ビットのデジタル出力

- I2Cデジタル出力インターフェース（プルアップ抵抗が4.7kΩのとき最大2.25MHz）

- 6つの割り込みソースに適用できる2つのプログラム可能な割り込みピン

- 3つの組み込みモーション検出チャンネル：フリーフォール検出、パルス検出、シェイク検出

- 遅延補償設定付きの方向（横/縦）検出

- 自動ウェイクおよび自動スリープ時のODRを自動的に切替可能

- ハイパスフィルタ処理されたデータをリアルタイムで出力可能

- 消費電流：6μA ～ 165μA

## 接続図

まず以下のパーツを用意してください:

- V4.0 ボード*1

- MMA8452Q センサー*1

- USBケーブル*1

- ジャンパーワイヤ*4

SCLピンをAnalog A5ポートに、SDAピンをAnalog A4ポートに接続します; 正極ピンを3V3ポートに、負極ピンをGNDポートに接続します。

![接続図のイラスト](../media/fdd68f7da45d46e65f42918eac68a2f3.jpeg)

## サンプルコード

以下のコードをArduinoソフトにコピー＆ペーストしてください。

```c
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
// Begin using the library by creating an instance of the MMA8452Q
//  class. We'll call it "accel". That's what we'll reference from
//  here on out.
MMA8452Q accel;
// The setup function simply starts serial and initializes the
//  accelerometer.
void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");

  // Choose your adventure! There are a few options when it comes
  // to initializing the MMA8452Q:
  //  1. Default init. This will set the accelerometer up
  //     with a full-scale range of +/-2g, and an output data rate
  //     of 800 Hz (fastest).
  accel.init();
  //  2. Initialize with FULL-SCALE setting. You can set the scale
  //     using either SCALE_2G, SCALE_4G, or SCALE_8G as the value.
  //     That'll set the scale to +/-2g, 4g, or 8g respectively.
  //accel.init(SCALE_4G); // Uncomment this out if you'd like
  //  3. Initialize with FULL-SCALE and DATA RATE setting. If you
  //     want control over how fast your accelerometer produces
  //     data use one of the following options in the second param:
  //     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
  //     ODR_6, or ODR_1.
  //     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz.
  //accel.init(SCALE_8G, ODR_6);
}

// The loop function will simply check for new data from the
//  accelerometer and print it out if it's available.
void loop()
{
  // Use the accel.available() function to wait for new data
  //  from the accelerometer.
  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();

    // accel.read() will update two sets of variables.
    // * int's x, y, and z will store the signed 12-bit values
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated
    //   acceleration from those 12-bit values. These variables
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings

    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();

    Serial.println(); // Print new line every time.
  }
}

// The function demonstrates how to use the accel.x, accel.y and
//  accel.z variables.
// Before using these variables you must call the accel.read()
//  function!
void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
```

注: コードをコンパイルする前に、ライブラリをArduino IDEのlibrariesディレクトリに配置してください。さもなければ、コンパイルは失敗します。

## 実行結果

![実行例の画像](../media/9f81d233c0387bc32d25951abd3a407c.png)

コードのアップロードが完了してシリアルモニタを開くと、センサーの三軸加速度とその状態が以下のように表示されます。

![実行例の画像](../media/03421d279e2e961d7b40f645b7576d73.jpeg)

---
