  int p[6]; //array for storing password stored by the user
  int c[6]; //array for storing password entered through keypad module
  int n; //
  int lock = 3;
  int i; //looping variable
  int a = 0; //to check whether a key is pressed 

  //row pins
  int r1 = 6; 
  int r2 = 7;
  int r3 = 8;
  int r4 = 9;

  //column pins
  int c1 = 10;
  int c2 = 11;
  int c3 = 12;
  int c4 = 13;

  
  int coln1;
  int coln2;
  int coln3;
  int coln4;


void setup() {

  //pin mode setup
 pinMode(r1 , OUTPUT);
 pinMode(r2 , OUTPUT);
 pinMode(r3 , OUTPUT);
 pinMode(r4 , OUTPUT);
 pinMode(c1 , INPUT);
 pinMode(c2 , INPUT);
 pinMode(c3 , INPUT);
 pinMode(c4 , INPUT);
 
 Serial.begin(9600); //setting the baud rate

 digitalWrite(c1 , HIGH);
 digitalWrite(c2 , HIGH);
 digitalWrite(c3 , HIGH);
 digitalWrite(c4 , HIGH);
 digitalWrite(lock , LOW);

 //getting the password from the user
 for(int k=0;k<6;k++)
 {
  Serial.println("enter the password digit");
  p[k] = Serial.read(); 
 }
}

void loop() {
  digitalWrite(r1 , LOW);
  digitalWrite(r2 , HIGH);
  digitalWrite(r3 , HIGH);
  digitalWrite(r4 , HIGH);
  coln1 = digitalRead(c1);
  coln2 = digitalRead(c2);
  coln3 = digitalRead(c3);
  coln4 = digitalRead(c4);
  if(coln1 == LOW)
  {
    n = 1;
    a = 1;
    Serial.begin("1");
    delay(200);
  }
  if(coln2 == LOW)
  {
    n = 2;
    a = 1;
    Serial.begin("2");
    delay(200);
  }
  if(coln3 == LOW)
  {
    n = 3;
    a = 1;
    Serial.begin("3");
    delay(200);
  }  
  if(coln4==LOW)
  {
    Serial.println("LOCKED");
    digitalWrite(lock,LOW);
    i = 0;
    delay(200); 
  }
  digitalWrite(r1 , HIGH);
  digitalWrite(r2 , LOW);
  digitalWrite(r3 , HIGH);
  digitalWrite(r4 , HIGH);
  coln1 = digitalRead(c1);
  coln2 = digitalRead(c2);
  coln3 = digitalRead(c3);
  coln4 = digitalRead(c4);
  if(coln1==LOW)
  {
    n = 4;
    a = 1;
    Serial.println("4");
    delay(200);
    }
   if(coln2==LOW)
  {
    n = 5;
    a = 1;
    Serial.println("5");
    delay(200);
  }
  if(coln3==LOW)
  {
    n = 6;
    a = 1;
    Serial.println("6");
    delay(200);
  }
  if(coln4==LOW)
  {
    n = 0;
    a = 1;
    Serial.println("0");
    delay(200);
    }

  digitalWrite(r1 , HIGH);
  digitalWrite(r2 , HIGH);
  digitalWrite(r3 , LOW);
  digitalWrite(r4 , HIGH);
  coln1 = digitalRead(c1);
  coln2 = digitalRead(c2);
  coln3 = digitalRead(c3);
  coln4 = digitalRead(c4);
  if(coln1==LOW)
  {
    Serial.println("7");
    a = 1;
    n = 7;
    delay(200);
    }
   if(coln2==LOW)
  {
    Serial.println("8");
    a = 1;
    n = 8;
    delay(200);
    }
   if(coln3==LOW)
  {
    Serial.println("9");
    a = 1;
    n = 9;
    delay(200);
    }
   if(coln4==LOW)
   {
    if(c[0]==p[0]&&c[1]==p[1]&&c[2]==p[2]&&c[3]==p[3]&&c[4]==p[4]&&c[5]==p[5])
    {
      Serial.println("UNLOCKED");
      digitalWrite(lock,HIGH);
      c[5] = 9;
    }
    else
    {
      Serial.println("WRONG PASSWORD");
      delay(200);
      }
    }
   if(a==1)
   {
    c[i] = n;
    i = i+1;
    a= 0;
   }
}
    

   

  
  
   
