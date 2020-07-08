#define A  2  //定义引脚Nano上D2—D5
#define B  3
#define C  4
#define D  5
int timeSpeed=5;     //每一步高电平停留时间(5ms)，间接控制速度
int angle=60;       //转动的角度
void setup()
{
  pinMode(A,OUTPUT);   //4个引脚引脚初始化
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
}

void loop(){
  Rotation();
  stopRotate;
  while(1);
}
//函数部分..............................................
void Phase_A()
{
  digitalWrite(A,HIGH);//单个相位高电平
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}

void Phase_B()
{
  digitalWrite(A,LOW); 
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}

void Phase_C()
{
  digitalWrite(A,LOW); 
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
}

void Phase_D()
{
  digitalWrite(A,LOW); 
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
}
void Rotate(){//电平正转
  Phase_A();      
  delay(timeSpeed);  
  Phase_B();      
  delay(timeSpeed);
  Phase_C();     
  delay(timeSpeed);
  Phase_D();      
  delay(timeSpeed);
}
void rev_Rotate(){//电平反转
  Phase_D();     
  delay(timeSpeed);
  Phase_C();     
  delay(timeSpeed);
  Phase_B();      
  delay(timeSpeed);
  Phase_A();   
  delay(timeSpeed);
}
void stopRotate(){//停转
  digitalWrite(A,LOW); 
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}
void Rotation(){//根据角度正转
   int i=0;
  while(i<angle){
    i++;
    Rotate();
    stopRotate();
    delayMicroseconds(10);
  }
  stopRotate();
}
void rev_Rotion(){//根据角度反转
  int i=0;
  while(i<angle){
    i++;
    rev_Rotate();
    stopRotate();
    delayMicroseconds(10);
  } 
}
