// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
int w=0;
int nL=0;
boolean iL=0;
int jumpButton = 6;
int sprintButton = 7;
int leftButton = 8;
int rightButton = 9;
int charPosx = 0;
int charPosy = 1;
int level = 1;
int blank = 10;
int blank2 = 11;
int lives = 5;
int moveP = 0;
int keyPx = 0;
int keyPy = 0;
int checkPoint = 0;
boolean keyI = 0;
boolean levelS = 0;
boolean jump = digitalRead(jumpButton);
int sprint = 1+digitalRead(sprintButton);
boolean left = digitalRead(leftButton);
boolean right = digitalRead(rightButton);
boolean r = 0;
boolean dead = false;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// make some custom characters:
byte player[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte key[8] = {
  0b00000,
  0b01110,
  0b01000,
  0b01110,
  0b01000,
  0b01100,
  0b10010,
  0b01100
};

byte Ldoor[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b01010,
  0b11111,
  0b11011,
  0b11011,
  0b11111
};

byte block[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte block2[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte blockLarge[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte place[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};
void setup() {
  // initialize LCD and set up the number of columns and rows:
  level=1;
  if(jump==1 && sprint==1 && left==1 && right==1){
    levelS=1;
  }
  
  if(jump==1 && sprint==2 && right==1 && left==1){
    iL=1;  
  }
  
  moveP=7;
  r=1;
  lcd.begin(16, 2);
  lcd.createChar(1, player);
  lcd.createChar(2, block);
  lcd.createChar(3, block2);
  lcd.createChar(4, blockLarge);
  lcd.createChar(5, place);
  lcd.createChar(6, Ldoor);
  lcd.createChar(7, key);
  // displays level number then sets the cursor to the top left
  lcd.setCursor(3, 0);
  lcd.write("Level"); 
  lcd.setCursor(9, 0);
  lcd.println(level); 
  lcd.setCursor(blank, 0);
  lcd.write(" ");
  lcd.setCursor(blank2, 0);
  lcd.write(" ");
  delay(500);
  lcd.setCursor(0,0);
  
  Serial.begin(9600);
  pinMode(jumpButton, INPUT);
  pinMode(sprintButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  lcd.clear();
}

void loop() {  
if(iL==1){
  lives=-1;
}
if(w==4 && right==1 && left==1 && jump==1){
levelS=1;
keyI=0;
nL=0;
}
 if(w==1){ 
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.write("You Won!");
  delay(2000);
  w=2;
  }
  if(w==2){
   lcd.setCursor(2, 0);
   lcd.write("Level Select");
   lcd.setCursor(4, 1);
   lcd.write("Unlocked");
   delay(1000);
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.write("L+R+Jump");
   delay(2000);
   lcd.clear();
   w=3;
  }
  if(w==3){
   lcd.setCursor(1, 0);
   lcd.write("Press Sprint to");
   lcd.setCursor(4, 1);
   lcd.write("Restart");
    if(sprint==2){
    level=1;
    w=4;
   }
  }
 //end "Restart?"
  //level select
  if(levelS==1){
  lcd.setCursor(0,1);
  lcd.write("1");
  lcd.setCursor(1,1);
  lcd.write("2");
  lcd.setCursor(2,1);
  lcd.write("3");
  lcd.setCursor(3,1);
  lcd.write("4");
  lcd.setCursor(4,1);
  lcd.write("5");
  lcd.setCursor(5,1);
  lcd.write("6");
  lcd.setCursor(6,1);
  lcd.write("7");
  lcd.setCursor(7,1);
  lcd.write("8");
  if(charPosx == 0 && sprint == 2){
    level=1;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
  if(charPosx == 1 && sprint == 2){
    level = 2;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
  if(charPosx == 2 && sprint == 2){
    level = 3;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
  if(charPosx == 3 && sprint == 2){
    level = 4;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
 if(charPosx == 4 && sprint == 2){
    level = 5;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
 if(charPosx == 5 && sprint == 2){
    level = 6;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
 if(charPosx == 6 && sprint == 2){
    level = 7;
    levelS=0;
    lcd.clear();
    charPosx=0;
    charPosy=1;
  }
 if(charPosx == 7 && sprint == 2){
   level = 8;
   levelS=0;
   lcd.clear();
   charPosx=0;
   charPosy=1;
 }
}//end level select
 
 if(charPosx > 15 && keyI==1||lives == 0)
 {
 nL=0;
 keyI=0;
  lcd.clear();
  charPosx = 0;
 if(lives >= 1){ 
  level++;
 }
 if(lives == 0){
  if(checkPoint==0){
   level=1;
  }
  if(checkPoint==1){
   level=4;
  }
   lives=5;
 }
  lcd.setCursor(3, 0);
  lcd.write("Level");
  lcd.setCursor(9, 0);
  lcd.println(level);
  lcd.setCursor(blank, 0);
  lcd.write(" ");
  lcd.setCursor(blank2, 0);
  lcd.write(" ");
  delay(500);
  lcd.clear();
 }
  if(level == 9)
  {
    blank = 11;
    blank2 = 12;
  }
  if(level == 99)
  {
    blank = 12;
    blank2 = 13;
  }
  
  int sensorReading = analogRead(A0);
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  //moves the cursor so the player gets drawn in the right spot
  lcd.setCursor(charPosx, charPosy);
  
  // draw the little man, arms down:
  lcd.write(1);
  delay(delayTime);
//sets variables = to the state of the buttons
jump = digitalRead(jumpButton);
sprint = 1+digitalRead(sprintButton);
left = digitalRead(leftButton);
right = digitalRead(rightButton);
  
  //makes sure player is always on screen:
  if(charPosx < 0)
  {
    charPosx = 0;
  }
  if(charPosx > 15)
  {
    charPosx = 15;
  }
  
  //button inputs:
  if(right == HIGH)
  {
    lcd.clear();
    charPosx+=sprint;
  }
  if(left == HIGH)
  {
    lcd.clear();
    charPosx-=sprint;
  }
  if(jump == HIGH)
  {
    lcd.clear();
    charPosy = 0;
  }
  if(jump == LOW)
  {
    lcd.clear();
    charPosy = 1;
  }
 
 //levels:
 if(levelS==0){
   //resets player to the start of the level
   if(dead==true){
    charPosx = 0;
    charPosy = 1;
    lives--;
    lcd.clear();
    keyI=0;
    if(lives>0){
    lcd.setCursor(3, 0);
    lcd.write("Lives: ");
    lcd.setCursor(10, 0);
    lcd.println(lives-1);
    lcd.setCursor(11, 0);
    lcd.write(" ");
    lcd.setCursor(12, 0);
    lcd.write(" ");
    }
    delay(1000);
    lcd.clear();
    dead=false;
  }//end dead
  
  if(level == 1){
    keyI=1;
    lcd.setCursor(5,1);
    lcd.write(2);
    lcd.setCursor(6,1);
    lcd.write(2);
    lcd.setCursor(8,0);
    lcd.write(3);
    lcd.setCursor(9,0);
    lcd.write(3);
    if(charPosx == 5 && charPosy == 1 || charPosx == 6 && charPosy == 1 || charPosx == 8 && charPosy == 0 || charPosx == 9 && charPosy == 0)
    {
    dead=true;
    }//end collision
  }//end level 1
  if(level == 2){
    keyI=1;
    lcd.setCursor(3,0);
    lcd.write(4);
    lcd.setCursor(3,1);
    lcd.write(4);
    if(charPosx == 3)
    {
      dead=true;
    }//end collision
  }//end level 2
   if(level == 3){
    keyI=1;
    lcd.setCursor(3,1);
    lcd.write(2);
    lcd.setCursor(4,1);
    lcd.write(4);
    lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(6,0);
    lcd.write(3);
    lcd.setCursor(7,0);
    lcd.write(3);
    if(charPosx == 4 || charPosx == 3 && charPosy == 1 || charPosx == 6 && charPosy == 0 || charPosx == 7 && charPosy == 0)
    {
      dead=true;
    }//end collision
  }//end level 3
  
  if(level==4){
  keyI=1;
   if(checkPoint==0){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.write("Check Point");
    checkPoint=1;
    delay(1000);
    lcd.clear();
  }
  lcd.setCursor(1,1);
  lcd.write(4);
  lcd.setCursor(2,1);
  lcd.write(4);
  lcd.setCursor(0,0);
  lcd.write(4);
  lcd.setCursor(9,1);
  lcd.write(4);
  lcd.setCursor(8,1);
  lcd.write(4);
  lcd.setCursor(10,0);
  lcd.write(4);
  lcd.setCursor(11,0);
  lcd.write(4);
  if(charPosx==0 && charPosy==0 || charPosx==1 && charPosy==1 || charPosx==2 && charPosy==1 || charPosx==8 && charPosy==1 || charPosx==9 && charPosy==1 || charPosx==10 && charPosy==0 || charPosx==11 && charPosy==0){ 
   dead=true;
  }
}//end level 4
  
   if(level == 5){
    keyI=1;
    lcd.setCursor(1,1);
    lcd.write(4);
    lcd.setCursor(1,0);
    lcd.write(4);
    lcd.setCursor(2,0);
    lcd.write(4);
    lcd.setCursor(3,1);
    lcd.write(4);
    lcd.setCursor(4,1);
    lcd.write(4);
    lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(6,1);
    lcd.write(4);
    lcd.setCursor(6,0);
    lcd.write(4);
    lcd.setCursor(7,0);
    lcd.write(4);
    if(charPosx == 1 || charPosx == 2 && charPosy == 0 || charPosx == 3 && charPosy == 1 || charPosx == 4 || charPosx ==6 || charPosx == 7 && charPosy == 0)
    {
      dead=true;
    }//end collision
   }//end level 5
   if(level == 6){
    keyI=1;
    lcd.setCursor(1,0);
    lcd.write(4);
    lcd.setCursor(1,1);
    lcd.write(4);
    lcd.setCursor(2,1);
    lcd.write(4);
    lcd.setCursor(3,0);
    lcd.write(4);
    lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(moveP-1,0);
    lcd.write(4);
    lcd.setCursor(moveP-1,1);
    lcd.write(4);
    if(moveP==10){
      r=0;
    }//end set left
    if(moveP==7){
      r=1;
    }//end set right
    if(r==1){
      moveP++;
    }//end right
    if(r==0){
      moveP--;
    }//end left
    if(charPosx==moveP && r==0 || charPosx==moveP && r==1 || charPosx==1 || charPosx==2 && charPosy==1 || charPosx==3 && charPosy==0 || charPosx==4 && charPosy==0){
      dead=true;
    }//end collision
   }//end level 6
 if(level == 7){
  keyI=1;
  lcd.setCursor(1, 0);
  lcd.write(4);
  lcd.setCursor(2, 1);
  lcd.write(4);
  lcd.setCursor(2, 0);
  lcd.write(4);
  lcd.setCursor(3, 1);
  lcd.write(4);
  lcd.setCursor(4, 1);
  lcd.write(4);
  lcd.setCursor(4, 0);
  lcd.write(4);
  lcd.setCursor(5, 0);
  lcd.write(4);
  lcd.setCursor(6, 1);
  lcd.write(4);
  lcd.setCursor(6, 0);
  lcd.write(4);
  lcd.setCursor(7, 0);
  lcd.write(4);
  lcd.setCursor(8, 0);
  lcd.write(4);
  lcd.setCursor(8, 1);
  lcd.write(4);
  lcd.setCursor(9, 1);
  lcd.write(4);
   if(charPosx==1 && charPosy==0 || charPosx==2 || charPosx==3 && charPosy==1 || charPosx==4 || charPosx==5 && charPosy==0 || charPosx==6 || charPosx==8 || charPosx==7 && charPosy==0 || charPosx==9 && charPosy==1){
     dead=true;
   }//end collision
 }//end level 7
 if(level==8){
  if(nL==0){
    keyI=0;
    nL=1;
  }
  keyPx=10;
  keyPy=1;
  lcd.setCursor(6, 1);
  lcd.write(4);
  lcd.setCursor(6, 0);
  lcd.write(4);
  lcd.setCursor(3, 1);
  lcd.write(2);
  lcd.setCursor(4, 1);
  lcd.write(2);
  lcd.setCursor(9, 1);
  lcd.write(4);
  lcd.setCursor(8, 1);
  lcd.write(4);
  lcd.setCursor(11, 1);
  lcd.write(4);
  if(keyI==0){
  lcd.setCursor(15,0);
  lcd.write(6);
  lcd.setCursor(15,1);
  lcd.write(6);
  lcd.setCursor(keyPx, keyPy);
  lcd.write(7);
  }
 if(charPosx == keyPx && charPosy == keyPy){
  keyI=1;
 }
 if(keyI==0 && charPosx==15 || keyI==0 && charPosx==16){
  charPosx=14;
 }
 if(charPosx==8 && charPosy==1 || charPosx==11 && charPosy==1 || charPosx==9 && charPosy==1 || charPosx==6 || charPosx==3 && charPosy==1 || charPosx==4 && charPosy==1){
  dead=1;
 }
 }//end level 8
 if(level==9 && w==0){
   lcd.clear();
   w=1;
 }//end level 9
 if(level==10){
 level=1;
 }
 }//end levels
}//end loop
