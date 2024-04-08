
//
int trigPin=7;
int echoPin=6;
int thoigian,kc;
int SPEAKER=12;
int button=4;
int LED=2;
//setup các chân nối
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(9600);
}
int k=1;
 int tt;
//chạy
void loop()
{
  digitalWrite(SPEAKER, LOW);
  if(k==1) digitalWrite(LED,LOW);
  kc=0;
  dokc();
  checknut();
  if (k==0)
  {
    digitalWrite(LED,HIGH);
    if(kc<=200)
    {
      digitalWrite(SPEAKER, HIGH);
      tone(12,220,125);
      delay(125+kc*3);
      tone(12,2093,250);
      checknut();
      delay(125+kc*3);
    }
  }
}

void checknut() {
	tt=digitalRead(button);
    if (tt==0)
    {
        if (k==1) k=0;
        else k=1;
    }
}

// tính khoảng cách 
void dokc() {
  digitalWrite(trigPin, LOW); //tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // bật chân trig để tỏa xung
    delayMicroseconds(10); // độ rộng của xung là 10 microsecond
    digitalWrite(trigPin, LOW);
    
    thoigian= pulseIn(echoPin, HIGH);  //thời gian xung đi đến vật r quay lại
  
    kc=thoigian/2/29.1;
}