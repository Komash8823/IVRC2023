// #define PIN_IN11  4
// #define PIN_IN12  5

#define PIN_IN21  10  //先に実装
#define PIN_IN22  11 //先に実装
#define PIN_VREF  12 //先に実装

// int txt=0;

void setup() {
  Serial.begin(9600);

  // pinMode(PIN_IN11,OUTPUT); //左
  // pinMode(PIN_IN12,OUTPUT); //左

  pinMode(PIN_IN21,OUTPUT); //右
  pinMode(PIN_IN22,OUTPUT); //右

  // analogWrite(PIN_IN11, 0);	//analogWrite PIN11を初期化
  // analogWrite(PIN_IN12, 0);	//analogWrite PIN12を初期化

  analogWrite(PIN_IN21, 0);	//analogWrite PIN21を初期化
  analogWrite(PIN_IN22, 0);	//analogWrite PIN22を初期化
}

void loop() {
  analogWrite(PIN_VREF, 255);
  digitalWrite(PIN_IN21, HIGH);
  digitalWrite(PIN_IN22, HIGH);

  // if(Serial.available()>0){
  //   txt = Serial.read();
  //   if(txt == 48){ //0を入力 -> 片目だけ動くモード（実験用）
  //     analogWrite(PIN_VREF, 255);
  //     digitalWrite(PIN_IN21, HIGH);
  //     digitalWrite(PIN_IN22, HIGH);
  //     Serial.println("片目温めるモード");
  //   }
  // }
}
