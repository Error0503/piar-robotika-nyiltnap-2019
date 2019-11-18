#define 1button 1
#define 2button 2
#define 3button 3
#define okButton 4
int boxes [3] = [4, 5, 5];
bool is_player_turn = false;
randomSeed(2);

void AI (){
  // nim összeg
  int n = table[0] ^ table[1] ^ table[2];
  // valid lépés keresése
  if (n != 0){
    for(int i = 0; 
   for    
  }else{
    boxes[random(0,3)]--;
  }
}
void setup() 
  pinMode(1button, INPUT);
  pinMode(2button, INPUT);
  pinMode(3button, INPUT);
  pinMode(okButton, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void UserInput() {
  int selected = 3;
  do {
    if (digitalRead(1button) ==  HIGH & boxes[0] > 0 & (selected == 0 || selected == 3)) {
      boxes[0]--;
      selected = 0;
    } else if (digitalRead(2button) == HIGH & boxes[1] > 0 & (selected == 1 || selected == 3)) {
      boxes[1]--;
      selected = 1;
    } else if (digitalRead(3button) == HIGH & boxes[2] > 0 & (selected == 2 || selected == 3)) {
      boxes[2]--;
      selected = 2;
    }
  } while (digitalRead(okButton) == HIGH);
  
}
