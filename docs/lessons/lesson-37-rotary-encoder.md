# レッスン37: ロータリーエンコーダ

> **キット:** Keyestudio 48-in-1 Sensor Kit  
> **ボード:** Keyestudio V4.0 / Arduino Uno互換の ATmega328P ボード

![プロジェクト37：ロータリーエンコーダの図](../media/df622003846058dd3cf442518f655af2.png)

## はじめに

ロータリーエンコーダは、回転の正転・逆転の過程で出力されるパルスの回数を数えることができます。

この回転によるカウントは無制限で、ポテンショメータのような制限されたカウントとは異なります。初期状態に戻して0から再びカウントすることができます。

## 仕様

- 電源: 5V

- インターフェース: デジタル

- サイズ: 30\*20mm

- 重さ: 7g

## 接続図

![接続図のイラスト](../media/1de37f27caa224141230be6bdc95d29b.jpeg)

図のように、ロータリーエンコーダモジュールと2つのLEDモジュールをブレッドボードとV4.0ボードに接続します。

ロータリーエンコーダモジュールを使って2つのLEDモジュールの点灯/消灯を制御します。

## サンプルコード

```c
///////////////////////////////////////////////////////////////
const int interruptA = 0;
const int interruptB = 1;
int CLK = 2;     // PIN2
int DAT = 3;     // PIN3
int BUTTON = 4;  // PIN4
int LED1 = 5;    // PIN5
int LED2 = 6;    // PIN6
int COUNT = 0;

void setup()
 {
  attachInterrupt(interruptA, RoteStateChanged, FALLING);
 // attachInterrupt(interruptB, buttonState, FALLING);
  pinMode(CLK, INPUT);
  digitalWrite(2, HIGH);  // Pull High Resistance
  pinMode(DAT, INPUT);
  digitalWrite(3, HIGH);  // Pull High Resistance

pinMode(BUTTON, INPUT);
  digitalWrite(4, HIGH);  // Pull High Resistance
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
   Serial.begin(9600);
 }

void loop()
{
  if  (!(digitalRead(BUTTON)))
    {
     COUNT = 0;
     Serial.println("STOP COUNT = 0");
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     delay (2000);
    }
     Serial.println(COUNT);
}

//-------------------------------------------
void RoteStateChanged() //When CLK  FALLING READ DAT
{
 if  (digitalRead(DAT)) // When DAT = HIGH IS FORWARD
   {
    COUNT++;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(20);
   }
 else                   // When DAT = LOW IS BackRote
   {
    COUNT--;
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    delay(20);
   }
}
///////////////////////////////////////////////////////////////
```

## 実行結果

配線を正しく行い上記のコードをアップロードすると、エンコーダモジュールを回転させることで2つのLEDモジュールを交互に点灯/消灯させることができます。エンコーダを回すと、まず一方のLEDが点灯し、もう一方は消灯します。

さらに回し続けると、一方が消灯しもう一方が点灯する動作が繰り返されます。

![実行結果のイメージ](../media/4c1455602dc8ab6d61f5ab2e2d5dd67c.png)

---
