//Some kind of codelock

#include <Keypad.h>

char a=' ', b=' ', c=' ';
int flag=0,lastflag=0,x=2;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte colPins[COLS] = {5, 4, 3, 2}; // col pinouts of the keypad
byte rowPins[ROWS]= {9, 8, 7, 6}; //row pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){

  Serial.begin(9600);
}

void loop(){
  //Hello!
  if (x==2) {
      Serial.println("Enter Teh Code");
      x=0;
  }
  char key = keypad.getKey();
  
// Enter Code!
  if (key != NO_KEY){ // only on press
    if(flag == 0){
      a = key;
      Serial.println(key);
      flag = 1;
      lastflag=0;
         }
    if(flag == 1 && lastflag==1){
     b = key; 
     Serial.println(key);
     flag =2;
    }
    if(flag == 2 && lastflag==2){
      c = key;
      Serial.println(key);
      flag = 0;
    
    }
    lastflag=lastflag+1;
  }
  
  // Compare
  //Matched
   if( a=='2' && b=='6' && c=='5'){
    Serial.println("Open");
    Serial.print(a);
    Serial.print(b);
    Serial.println(c);
    delay(2000);
    a=' ';
    b=' ';
    c=' ';
x=2;//goto Hello!
lastflag=0;//zero the hero
    }else{
      //If not matched
       if( a!='2'&& lastflag == 3 || b!='6'&& lastflag == 3 || c!='5'&& lastflag == 3){
    Serial.println("Wrond code");
    Serial.print(a);
    Serial.print(b);
    Serial.println(c);
    delay(2000);
    a=' ';
    b=' ';
    c=' ';
x=2; //goto Hello!
lastflag=0;//zero the hero
    }
    }
    }
  
  


