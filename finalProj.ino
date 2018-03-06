int com1 = 7;    // J1 (right)
int com2 = 6;    // J2 (left)
int com3 = 5;    // J3 (backwards)
int com4 = 4;    // J4 (forward)

int pinky;    
int ring;
int middle;
int pointer;

// the setup routine runs once when you press reset:
void setup()  { 

  Serial.begin(9600);
  
  // declare pin 7 to be an output:
  pinMode(com1, OUTPUT);
  pinMode(com2, OUTPUT);
  pinMode(com3, OUTPUT);
  pinMode(com4, OUTPUT);

} 

// the loop routine runs over and over again forever:
void loop()  { 
  pinky = analogRead(A0);
  ring = analogRead(A1);
  middle = analogRead(A2);
  pointer = analogRead(A3);

  Serial.println(pointer);
  delay(1);        // delay in between reads for stability


  
  //backwards
  if ((pinky <= 260) && (ring <= 55) && (middle) <= 495 && (pointer <= 400))
  {
     digitalWrite(com4, LOW);
     digitalWrite(com3, HIGH);
     digitalWrite(com2, LOW);
     digitalWrite(com1, LOW);
  }

  //forewards
  if ((pinky >= 260) && (ring <= 55) && (middle <= 495) && (pointer >= 400))
  {
     digitalWrite(com4, HIGH);
     digitalWrite(com3, LOW);
     digitalWrite(com2, LOW);
     digitalWrite(com1, LOW);
  }


  //stop
  if ((pinky >= 260) && ring >= 55 && middle >= 495 && pointer >= 400)
  {
     digitalWrite(com4, LOW);
     digitalWrite(com3, LOW);
     digitalWrite(com2, LOW);
     digitalWrite(com1, LOW);
  }




  //left
  if ((pinky >= 260) && ring >= 55 && middle <= 495 && pointer <= 400)
  {
     digitalWrite(com4, LOW);
     digitalWrite(com3, LOW);
     digitalWrite(com2, HIGH);
     digitalWrite(com1, LOW);
  }

  //left and forward
  if ((pinky >= 260) && ring <= 55 && middle<= 495 && pointer <= 400)
  {
     digitalWrite(com4, HIGH);
     digitalWrite(com3, LOW);
     digitalWrite(com2, HIGH);
     digitalWrite(com1, LOW);
  }

  //right
  if ((pinky<= 260) && ring <= 55 && middle >= 495 && pointer >= 400)
  {
     digitalWrite(com4, LOW);
     digitalWrite(com3, LOW);
     digitalWrite(com2, LOW);
     digitalWrite(com1, HIGH);
  }

  //right and forward
  if ((pinky <= 260) && ring <= 55 && middle <= 495 && pointer >= 400)
  {
     digitalWrite(com4, HIGH);
     digitalWrite(com3, LOW);
     digitalWrite(com2, LOW);
     digitalWrite(com1, HIGH);
  }

  //delay(50);
/*
  
  digitalWrite(com1,HIGH);// NO3 and COM3 Connected;
  Serial.println("High");
  delay(5000);
  digitalWrite(com1,LOW);// NO3 and COM3 Disconnected;
  Serial.println("Low");
  delay(5000);


                         */
}
