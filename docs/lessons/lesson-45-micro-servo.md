# レッスン45: マイクロサーボ

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換 ATmega328P ボード

![プロジェクト45: マイクロサーボのイラスト](../media/12c59bd3ab0733beb6ff7802305d4384.jpeg)

## はじめに

サーボモーターは位置制御用の回転アクチュエータです。主にハウジング、回路基板、コアレスモーター、ギア、および位置センサーで構成されます。

サーボモーターには、シャフトに接続するさまざまな白いモーターマウントが付属しています。回路に合わせて任意のマウントを取り付けて構いません。視覚的な補助になり、サーボの回転が見やすくなります。

サーボには茶色、赤、オレンジの線で区別される3つのインターフェースがあります（ブランドにより色が異なる場合があります）。茶色の線がGND、赤が電源5V、オレンジが信号端子（PWM信号）です。

![導入のイラスト](../media/e7eb9914318b92eff98a4a84a8d1a557.png)

サーボの回転角はPWM（パルス幅変調）信号のデューティ比を調整して制御されます。PWM信号の標準周期は20ms（50 Hz）に固定されており、パルス幅は1ms〜2msの間で変化します。パルス幅はサーボの回転角（0°～90°）に対応します。

![導入のイラスト](../media/723671941df8a57cf9246c9916e7b279.png)

次に、サーボモーターの制御方法を学びましょう。

この実験では、サーボモーターといくつかのジャンパー線だけが必要です。

## 接続図

V4.0 用接続 :

![接続図のイラスト](../media/da1e3590f86a5a8ed27b333742ae49c9.jpeg)

2560 R3 用接続:

![接続図のイラスト](../media/1c8bd09408be60254883b910ef4fc9bf.png)

モーターをデジタルピン9に接続してください。

モーターが指定した角度に回転するようプログラムをコンパイルし、その角度を画面に表示します。

## サンプルプログラム

Arduinoでサーボモーターを制御する方法は2通りあります。

1つは、Arduinoの一般的なデジタルセンサーポートを使ってデューティ比の異なる方形波を発生させ、PWM信号をシミュレートしてモーターの位置決めを制御する方法です。

もう1つは、ArduinoのServo機能を直接使用してモーターを制御する方法です。

この方法ではプログラムは簡単になりますが、サーボ機能は二接点モーターのみ制御でき、使用できるのはデジタルピン9と10だけです。Arduinoの駆動能力には限界があります。したがって複数のモーターを制御する場合は外部電源が必要です。

## 方法1

## サンプルプログラムA

```c
//////////////////////////////////////////////////////////
int servopin=9;// select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val;
void servopulse(int servopin,int myangle)// define a servo pulse function
{
pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width
digitalWrite(servopin,HIGH);// set the level of servo pin as “high”
delayMicroseconds(pulsewidth);// delay microsecond of pulse width
digitalWrite(servopin,LOW);// set the level of servo pin as “low”
delay(20-pulsewidth/1000);
}
void setup()
{
pinMode(servopin, OUTPUT);
Serial.begin(9600);
Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()// convert number 0 to 9 to corresponding 0-180 degree angle, LED blinks corresponding number of time
{
val=Serial.read();// read serial port value
if(val>='0'&&val<='9')
{
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}
}
}
//////////////////////////////////////////////////////////
```

## 方法2

まず Arduino の組み込みサーボ機能といくつかの一般的な文を見てみましょう。

1\. **attach(interface)**——サーボ用のピンを選択します。使用できるのはピン9または10のみです。

2\. **write(angle)**——サーボの回転角を制御するために使用します。角度は0度から180度の範囲で設定できます。

3\. **read()**——サーボの角度を読み取るために使用します。write() 関数で設定した値を読み取るための関数と考えてください。

4\. **attached()**——サーボのパラメータがサーボピンに送られているかどうかを判定します。

5\. **detach()**——サーボとピンの接続を切断します。ピン（デジタルピン9または10）はPWMポートとして使用できるようになります。

注意：上記の文の書き方は「サーボ変数名. 特定の文()」です。例: myservo. Attach (9).

ここでもサーボをピン9に接続してください。

## サンプルプログラムB

```c
#include <Servo.h>// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu

Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop()
{
myservo.write(90);// set rotating angle of the motor
}
```

## 実行結果

![実行結果のイラスト](../media/f02556e0631fb206c114ced29e643016.png)

配線を正しく行い、プログラムA をボードにアップロードしたら、Arduinoソフトのシリアルモニタを開き、ボーレートを9600に設定します。上部の入力欄に数値を入力して「送信」をクリックすると、サーボが対応する角度に回転し、移動角がモニタに表示されます。以下に示します。

電源を入れ、プログラムB をボードに正常にアップロードすると、サーボはまず90度の位置に移動します。

![実行結果のイラスト](../media/de50d502cb8ed1feb5935d16584cfd63.png)

---
