//BT
#include <SoftwareSerial.h>
int BtTx = 10;
int BtRx = 11;
int BtIncValue = 0;
SoftwareSerial bluetooth(BtTx, BtRx);

//Nema 17
#define stepPin 8
#define dirPin 9 

//PUMP
int in1 = 2;
int in2 = 4;
int enA = 3;
int in3 = 5;
int in4 = 7;
int enB = 6;

//buton
// int buton = 12;
// int sust = 100;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
   
  //Nema 17
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  //PUMP
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  //buton
  // pinMode(buton, INPUT_PULLUP);

}

void loop() {
  //BtIncValue = 1 => shake1
  //BtIncValue = 2 => shake2
  //BtIncValue = 3 => gotovo za mixvane
  //BtIncValue = 6 => mix
  //BtIncValue = 7 => 10 rotations
  //BtIncValue = 4 => stop mix
  
  
  
  if(bluetooth.available()>0){
    BtIncValue = bluetooth.read();
    Serial.print(BtIncValue);
    Serial.print("\n");
  }

  // sust = digitalRead(buton);
  // Serial.print(sust);
  // Serial.print("\n");  
  
  if(BtIncValue == 1 ){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(5000);    
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(200); 

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(5000);    
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(200);

    BtIncValue = 3;
    // Serial.print(sust);
    // Serial.print("\n");  
    // Serial.print(BtIncValue);
    // if(sust == 0 && BtIncValue == 3){
    //   digitalWrite(dirPin,HIGH); // lqvo -> dqsno
    //   // 200 pulsa = 1 zavurtane => i = 800 za 1 zavurtane
    //   for(int x = 0; x < 8000; x++) {
    //     Serial.print("LOL");
    //     digitalWrite(stepPin,HIGH); 
    //     delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    //     digitalWrite(stepPin,LOW); 
    //     delayMicroseconds(1000);
    //     BtIncValue = 4;      
    //   }       
    // }
  }

  if(BtIncValue == 2 ){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(7000);    
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(200); 

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(7000);    
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(enA, 100);
    digitalWrite(enB, 100);
    delay(200);

    BtIncValue = 3;
    
  }

  if(BtIncValue == 6){
  digitalWrite(dirPin,HIGH); // lqvo -> dqsno
  // 200 pulsa = 1 zavurtane => i = 800 za 1 zavurtane
    // for(int x = 0; x < 8000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1200);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1200); 
    // }     
    // BtIncValue = 4;  
    // digitalWrite(dirPin,LOW);     
  }

  if(BtIncValue == 7){
  digitalWrite(dirPin,HIGH); // lqvo -> dqsno
  // 200 pulsa = 1 zavurtane => i = 800 za 1 zavurtane
    for(int x = 0; x < 8000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1200);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1200); 
    }     
    BtIncValue = 4;  
    // digitalWrite(dirPin,LOW);     
  }
  // digitalWrite(in1, HIGH);
  // digitalWrite(in2, LOW);
  // digitalWrite(in3, HIGH);
  // digitalWrite(in4, LOW);
  // digitalWrite(enA, 100);
  // digitalWrite(enB, 100);
  
  // delay(3000);

  // digitalWrite(in1, LOW);
  // digitalWrite(in2, LOW);
  // digitalWrite(in3, LOW);
  // digitalWrite(in4, LOW);
  // digitalWrite(enA, 100);
  // digitalWrite(enB, 100);

  // digitalWrite(dirPin,HIGH); // lqvo -> dqsno
  // // 200 pulsa = 1 zavurtane => i = 800 za 1 zavurtane
  //  for(int x = 0; x < 8000; x++) {
  //   digitalWrite(stepPin,HIGH); 
  //   delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
  //   digitalWrite(stepPin,LOW); 
  //   delayMicroseconds(1000); 
  // }

}