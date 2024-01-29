#define IN1 19
#define IN2 18
#define ENA 17

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int speed = 200;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  if (stringComplete) {
    inputString.trim();
    Serial.println(inputString);
    if(inputString.equals("forward")){
      goForward();
    }else if(inputString.equals("reverse")){
      goReverse();
    }else if(inputString.equals("left")){
      goLeft();
    }else if(inputString.equals("right")){
      goRight();
    }else if(inputString.equals("stop")){
      stop();
    }else{
      Serial.println("Invalid command");
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void goForward(){
  stop();
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(100);
}

void goReverse(){
  stop();
  analogWrite(ENA, speed);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delay(100);
}

void goLeft(){
  stop();
  analogWrite(ENA, speed);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  delay(100);
}

void goRight(){
  stop();
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(100);
}

void stop(){
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(100);
}