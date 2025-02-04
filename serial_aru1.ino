
#define PIN_IN11  4
#define PIN_IN12  5

#define PIN_IN21  8
#define PIN_IN22  9

int txt=0;

void setup(){
  Serial.begin(9600);

  pinMode(PIN_IN11,OUTPUT);
  pinMode(PIN_IN12,OUTPUT);

  pinMode(PIN_IN21,OUTPUT);
  pinMode(PIN_IN22,OUTPUT);

  analogWrite(PIN_IN11, 0);	//analogWrite PIN11を初期化
  analogWrite(PIN_IN12, 0);	//analogWrite PIN12を初期化

  analogWrite(PIN_IN21, 0);	//analogWrite PIN21を初期化
  analogWrite(PIN_IN22, 0);	//analogWrite PIN22を初期化
}
 
 void loop(){

   if(Serial.available()>0){
    txt = Serial.read();
    if(txt == 48){  //0を入力・・・待機
      digitalWrite(PIN_IN11, LOW);
      digitalWrite(PIN_IN12, LOW);

      digitalWrite(PIN_IN21, LOW);
      digitalWrite(PIN_IN22, LOW);
      Serial.println("待機モード");
    }else if(txt == 49){  //1を入力・・・キャリブレーション
      analogWrite(PIN_IN12, 100);
      analogWrite(PIN_IN22, 100);
      //digitalWrite(PIN_IN12, HIGH);
      //digitalWrite(PIN_IN11, LOW);

      //digitalWrite(PIN_IN22, HIGH);
      //digitalWrite(PIN_IN21, LOW);
      Serial.println("キャリブレーションモード");
    }else if(txt == 50){  //2を入力・・・体験
      Serial.println("IVRC雨40s_2.体験モード");
      analogWrite(PIN_IN12, 100);
      analogWrite(PIN_IN22, 100);
      delay(5000);
      analogWrite(PIN_IN12, 150);
      analogWrite(PIN_IN22, 150);
      delay(10000);
      analogWrite(PIN_IN12, 200);
      analogWrite(PIN_IN22, 200);
      delay(10000);
      analogWrite(PIN_IN12, 255);
      analogWrite(PIN_IN22, 255);
      delay(10000);
      analogWrite(PIN_IN12, 200);
      analogWrite(PIN_IN22, 200);
      delay(1000);
      analogWrite(PIN_IN12, 150);
      analogWrite(PIN_IN22, 150);
      delay(1000);
      analogWrite(PIN_IN12, 100);
      analogWrite(PIN_IN22, 100);
      delay(2000);
      analogWrite(PIN_IN12, 0);
      analogWrite(PIN_IN22, 0);
    }
  }
 }