# レッスン46: 超音波レンジャー

> **キット:** Keyestudio 48-in-1 センサーキット  
> **ボード:** Keyestudio V4.0 / Arduino Uno 互換 ATmega328P ボード

![プロジェクト46：超音波レンジャー（イラスト）](../media/c170155a5fb03abdc10866e25e3670b2.jpeg)

## 説明

超音波は指向性が強く、媒体中でのエネルギー損失が小さく長距離伝播できるため、距離測定（レンジファインダーや位置測定器）に広く用いられています。

超音波検出モジュールは、2cm〜450cm の非接触検出距離を提供でき、測距精度は最大で約3mmと、通常の要求を十分満たします。

このモジュールは超音波送信器と受信器および対応する制御回路を含んでいます。

## 動作概略

HC-SR04 の測定シーケンスは以下の通りです：

![動作概略図](../media/a7b0fc57b2e387962071da618153ad68.jpeg)

1\. まずTRIGをローにしておき、少なくとも10usのハイレベル信号でトリガーします；

2\. トリガー後、モジュールは自動的に8回の40kHzの方形波を送信し、戻り信号があるかを自動検出します。

3\. もし信号が返ってきた場合、ECHOピンからハイレベルが出力されます。ハイレベルの継続時間は、実際には超音波の送信から受信までの時間です。
$$
測定距離 = ハイレベル継続時間 * 340m/s * 0.5
$$

## パラメータ

- 動作電圧: 5 V DC

- 動作電流：15mA

- 検出範囲：2-450cm

- 検出角度：15度

- 入力トリガーパルス：10us TTL レベル

- 出力エコー信号：TTL レベル信号(HIGH)を出力、距離に比例

## ピン配置図

![ピン配置図](../media/c03e563bcd19796b483156724bae174a.png)

## 接続図

まず、以下の部品を準備してください：

- V4.0 ボード\*1

- 超音波センサ\*1

- USB ケーブル\*1

- ジャンパー線\*4

次に、以下の接続表を参照してください：

![接続図](../media/e708c019b57984a07feb241672793982.jpeg)

注：D4、D5 はデジタルピン4およびピン5です。

以下の接続図を参考にしてください：

![接続図](../media/b5b964743eac977e687c454b64e061fa.jpeg)

接続が正しくできたら、距離を測定してモニタに距離値を表示できます。

## テストコード

以下のテストコードをArduinoソフトウェアにコピー＆ペーストしてください

```c
///////////////////////////////////////////////////////////////////////////////
int inputPin=4; // define ultrasonic signal receiver pin ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5
 void setup()
{
Serial.begin(9600);
pinMode(inputPin, INPUT);
pinMode(outputPin, OUTPUT);

}
void loop()
{
digitalWrite(outputPin, LOW); delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
delayMicroseconds(10);
digitalWrite(outputPin, LOW);
int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
distance= distance/58; // Transform pulse time to distance
Serial.println(distance); //Output distance
delay(50);
}
///////////////////////////////////////////////////////////////////////////////
```

## 実行例

![実行例の図](../media/0dcff2ae88366ce40190b77f25d271d7.png)

コードをV4.0ボードに正常にアップロードしたら、シリアルモニタを開きます。超音波センサの前に物体を置くと（近くから遠くへ）、物体までの距離を検出します。値は下のモニタに表示されます。

![実行例の図](../media/1dbca5dc233994f6923601d942fadba6.png)

![実行例の図](../media/dcd49cc72e7a9f993083af7625d240db.png)

---
