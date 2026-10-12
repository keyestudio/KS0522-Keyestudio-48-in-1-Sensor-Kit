# レッスン29：電圧検出

> **キット：** Keyestudio 48-in-1 センサーキット  
> **ボード：** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト29：電圧検出のイラスト](../media/41967398a781944fd64ebd49a9c746fa.jpeg)

## 説明

電子製品は種類が多いため、電源電圧も異なります。適切な電圧検出モジュールやコントローラで検出する必要があります。

コントローラのアナログインターフェースの最大入力電圧は5Vであり、5Vを超える電圧はそのままでは検出できません。

しかし、この電圧検出モジュールを使用すれば5Vを超える電圧を検出できます。

これは5:1の抵抗分圧に基づいています。アナログ基準が5Vの場合、入力電圧は最大25Vまで測定できます。アナログ基準が3.3Vの場合、入力電圧は最大16.5Vまでです。

AVRのアナログ-デジタルコンバータは10ビットなので、アナログ分解能は0.00489V（5 V / 1023）です。5:1の分圧を考慮すると、入力で検出可能な最小増分は約0.02445Vになります。

このセンサを3ピンケーブルで拡張ボードに接続すると、電源電圧の大きさを簡単に検出でき、インタラクティブメディア作品やロボットのためにバッテリの電力量を監視できます。また、IIC LCD1602 LCDモジュールと組み合わせて電圧を表示したり電圧モニタを作成したりすることもできます。

## 仕様

- 動作電圧: 0V-25V DC

- 信号タイプ: アナログ信号

## 接続図

まず、接続前に次の部品を用意してください:

- V4.0 ボード\*1

- 電圧センサー\*1

- USBケーブル\*1

- ジャンパーワイヤー\*3

モジュールのSピンをV4.0ボードのアナログ A0 に接続し、負極ピンをGNDポートに、NCピンを5Vポートに接続します。

![接続図のイラスト](../media/b8754c45901ff42ba9caadce5db01a3a.jpeg)

## サンプルコード

```c
////////////////////////////////////////////////////////////////////
int analogpin=0;     // Define analogpin as analog port 0
int val,val5;       //Define variables val,val5
int val2=0;      //Define variables val2
int val3=0;     //Define variables val3
int val4=0;    //Define variables val4

void setup()
{
    Serial.begin(9600);     //Set baud rate of 9600
}
void loop()
{
    int val,val5;
    float val1;
    val=analogRead(analogpin);     //Read the value of the analog port and assign it to the variable val
    val1=val/3.9;
    val5=(int)val1;
    val3=val5/100;
    val2=(val5%100)/10;
    val4=val5%10;
    Serial.print("$CLEAR\r\n");      //clear the screen
    Serial.print("$GO 1 1\r\n");
    Serial.print("$PRINT Voltage:\r\n");
    Serial.print("$GO 1 9\r\n");
    Serial.print("$PRINT ");
Serial.print(val3);        //The serial port prints the value of the variable val3
Serial.print(val2);      //The serial port prints the value of the variable val2
    Serial.print(".");               //The serial port prints out a point"."
    Serial.print(val4);         //The serial port prints the value of the variable val4
    Serial.println("V");          //The serial port prints out capital “ V”
    delay(100);      //delay 0.1 second
}
////////////////////////////////////////////////////////////////////
```

## 実例の結果

![実例の結果のイラスト](../media/ac8825bb333757bad26785e58651beb7.png)

上記の配線どおりに接続し、コードをコンパイルしてアップロード後、電源を入れてシリアルモニタを開くと、下図のように検出した電圧値が表示されます。

![実例の結果のイラスト](../media/af699a83a891ea99d193d5b53bd27fa1.jpeg)

---
