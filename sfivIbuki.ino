#define FORWARD  1
#define BACKWARD -1
#define S_LOW 0
#define S_MEDIUM 1
#define S_HIGH 2
#define S_ALL 3
#define keyDelay 15

void setup() {
  Keyboard.begin();
  for (int pin = 12; pin >1; pin--){
    pinMode(pin, INPUT_PULLUP);
  }
  //12 Kasumi Gake
  //11 Tsumuji
  //10 Hien
  //9 Kazegiri
  //8 Yoroitoshi
  //7 Hashinsho
  //6 Kasumi Suzaku
  //5 Neck Breaker
  //4 Raida
  //3 Kunai
  //2 Tsujigoe
}

void loop() {
  if(digitalRead(12) == LOW){
    //Kasumi Gake
    circleQuarter(FORWARD);
    kick(S_ALL);
    delay(keyDelay);
  }else if(digitalRead(11) == LOW){
    //Tsumuji
    circleQuarter(BACKWARD);
    kick(S_ALL);
    delay(keyDelay);
  }else if (digitalRead(10) == LOW){//
    //Hien
    circleShoryuken(BACKWARD);
    kick(S_ALL);
  }else if (digitalRead(9) == LOW){//
    //Kazegiri
    circleShoryuken(FORWARD);
    kick(S_ALL);
  }else if (digitalRead(8) == LOW){//
  //Yoroitoshi
    circleHalf(BACKWARD);
    circleHalf(BACKWARD);
    punch(S_ALL);
  }else if (digitalRead(7) == LOW){//
    //Hashinsho
    circleQuarter(FORWARD);
    circleQuarter(FORWARD);
    kick(S_ALL);
  }else if (digitalRead(6) == LOW){//
    //Kasumi Suzaku
    Keyboard.press(KEY_UP_ARROW);
    delay(keyDelay*8);
    Keyboard.release(KEY_UP_ARROW);
    delay(keyDelay);
    circleQuarter(FORWARD);
    circleQuarter(FORWARD);
    punch(S_ALL);
  }else if (digitalRead(5) == LOW){//
    //Neck Breaker
    circleHalf(FORWARD);
    punch(S_ALL);
  }else if (digitalRead(4) == LOW){//
    //Raida
    circleHalf(BACKWARD);
    punch(S_ALL);
  }else if (digitalRead(3) == LOW){//
    //Kunai
    Keyboard.press(KEY_UP_ARROW);
    delay(keyDelay*8);
    Keyboard.release(KEY_UP_ARROW);
    delay(keyDelay);
    circleQuarter(FORWARD);
    punch(S_ALL);
  }else if (digitalRead(2) == LOW){//
    //Tsujigoe
    circleShoryuken(FORWARD);
    punch(S_ALL);
  }
}
void punch(int STRENGTH){
  int keyChar = '=';
  switch (STRENGTH){
    case S_ALL:
      keyChar='=';
      break;
    case S_HIGH:
      keyChar='-';
      break;
    case S_MEDIUM:
      keyChar='0';
      break;
    case S_LOW:
      keyChar='9';
      break;
  }
  Keyboard.press(keyChar);
  delay(keyDelay);
  Keyboard.release(keyChar);
  delay(keyDelay);
}
void kick (int STRENGTH){
  int keyChar = ']';
  switch (STRENGTH){
    case S_ALL:
      keyChar=']';
      break;
    case S_HIGH:
      keyChar='[';
      break;
    case S_MEDIUM:
      keyChar='p';
      break;
    case S_LOW:
      keyChar='o';
      break;
  }
  Keyboard.press(keyChar);
  delay(keyDelay);
  Keyboard.release(keyChar);
  delay(keyDelay);
}
void circleQuarter(int dir){
  if (dir == FORWARD){
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
  }else if (dir == BACKWARD){
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
  }
}
void circleHalf(int dir){
    if (dir == FORWARD){
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
  }else if (dir == BACKWARD){
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
  }
}void circleFull(int dir){
    if (dir == FORWARD){
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_UP_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_UP_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
  }else if (dir == BACKWARD){
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_UP_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_UP_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
  }
}
void circleShoryuken(int dir){
  if (dir == FORWARD){
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(keyDelay); 
  }else if (dir == BACKWARD){
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(keyDelay);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(keyDelay);
    Keyboard.release(KEY_DOWN_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(keyDelay); 
  }
}
