#define 1button 1
#define 2button 2
#define 3button 3
#define okButton 4
int boxes [4] = [4, 5, 5, 4];
bool is_player_turn = false;
randomSeed(2);

void AI (){
  bool léptem = false;
  // nim összeg
  int n = table[0] ^ table[1] ^ table[2];
  // valid lépés keresése
  if (n != 0){
    for(int i = 0; boxes.length <= i; i ++;)
    {
     // lépés megtalálása és meglépése
     if (boxes[i] ^ n < n && léptem == false){
      boxes[i] -= n; 
     }
    }
   
  }else{
    boxes[random(0,4)]--;
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
  int selected = 0;
  
  do {
    if (digitalRead(1button) ==  HIGH) {
      //placeholder beacuse why not
    }
  } while (digitalRead(okButton) == HIGH);
  
}
