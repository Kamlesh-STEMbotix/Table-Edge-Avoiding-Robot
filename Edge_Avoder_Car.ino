
//for Table Edge Avoiding Robot using IR sensors  
  
  
int lm1=8; //left motor output 1
int lm2=9; //left motor output 2
int rm1=10;  //right motor output 1
int rm2=11;  //right motor output 2
int sl=6;    //sensor 1 input (left)
int sr=12;    //sensor 2 input (right)
int EN1 = 3; 
int EN2 = 5;

int SlV=0;
int SrV=0;
int led=A0;
void setup()
{
 Serial.begin(9600);
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sl,INPUT);
  pinMode(sr,INPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  analogWrite(EN1, 110);
  analogWrite(EN2, 160);


sTOP();
}
void loop()
{
 SlV=digitalRead(sl);
 SrV=digitalRead(sr);
 Serial.print(SlV);
 Serial.println(SrV);
 if(SrV==LOW && SlV== LOW)
 {
   digitalWrite(led,LOW);
  ForWard();
   }
   if(SrV==HIGH && SlV== HIGH)
 {
   digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Right();
  delay(550);  
  ForWard();
  delay(200);
   }
    if(SrV==LOW && SlV== HIGH)
 {
  digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Right();
  delay(550);
  ForWard();
  delay(200);
   }
    if(SrV==HIGH && SlV== LOW)
 {
  digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Left();
  delay(550);
  ForWard();
  delay(200);
   }
}
void ForWard()
 {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
 } 
 void BackWard()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
 }
 void Left()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
 } 
 void Right()
 {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
 }  
   void sTOP()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
 } 
