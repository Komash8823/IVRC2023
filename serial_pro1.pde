import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

Minim minim = new Minim(this);
AudioPlayer player; //サウンドを入れる用変数

import processing.serial.*;
Serial myport;
int data = 0;

import controlP5.*;
ControlP5 Button, Button2, Button3;

void setup() 
{
  size(900, 600);
  background(255, 255, 255);
  //print(Serial.list());
  myport = new Serial(this, "COM5", 9600);

  Button = new ControlP5(this);
  Button.addButton("rain")
    .setLabel("rain")//テキスト
    .setPosition(50, 40)
    .setSize(100, 100)
    .setColorCaptionLabel(color(0,0,0)) //テキストの色
    .setFont(createFont("arial",20)) //size of text
    .setColorActive(color(0,0,255)) //押したときの色 引数はintとかcolorとか
    .setColorBackground(color(100,100,255)) //通常時の色
    .setColorForeground(color(0,0,255)); //hoverしたときの色
    
  Button2 = new ControlP5(this);
  Button2.addButton("stop")
    .setLabel("stop")//テキスト
    .setPosition(200, 40)
    .setSize(100, 100)
    .setColorCaptionLabel(color(255,255,255)) //テキストの色
    .setFont(createFont("arial",20)) //size of text
    .setColorActive(color(30,30,30)) //押したときの色 引数はintとかcolorとか
    .setColorBackground(color(150,150,150)) //通常時の色
    .setColorForeground(color(10,10,10)); //hoverしたときの色

  Button3 = new ControlP5(this);
  Button3.addButton("cari")
    .setLabel("cari")//テキスト
    .setPosition(350, 40)
    .setSize(100, 100)
    .setColorCaptionLabel(color(255,255,255)) //テキストの色
    .setFont(createFont("arial",20)) //size of text
    .setColorActive(color(30,30,30)) //押したときの色 引数はintとかcolorとか
    .setColorBackground(color(150,150,150)) //通常時の色
    .setColorForeground(color(10,10,10)); //hoverしたときの色
}

void draw() 
{ 
  
}

void rain() {
  player = minim.loadFile("IVRC雨40s_2.wav"); //ファイル読み込み
  player.play();
  myport.write(50); //keyboard number 2
  
}

void stop(){
  player.close();
  myport.write(48); //keyboard number 0
}

void cari(){
  myport.write(49); //keyboard number 1
}
