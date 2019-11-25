#define 1button 1
#define 2button 2
#define 3button 3
#define okButton 4
int boxes [4] = [4, 5, 5, 4];
bool is_player_turn = false;
randomSeed(2);

void AI () {
  bool leptem = false;
  // nim összeg
  int n = table[0] ^ table[1] ^ table[2]; // Nem boxes?
  // valid lépés keresése
  if (n != 0) {
    for(int i = 0; boxes.length <= i; i ++;) {
     // lépés megtalálása és meglépése
      if (boxes[i] ^ n < n && leptem == false) {
        boxes[i] -= n; 
        // lépés befejezése
        leptem = true;
      }
    }
  } else {
    boxes[random(0,4)]--;
  }
}
void setup() {
  pinMode(1button, INPUT);
  pinMode(2button, INPUT);
  pinMode(3button, INPUT);
  pinMode(okButton, INPUT);
  // Lépések ismétlésben
}

void loop() {}

void UserInput() {
  int selected = 3;
  do {
    // Melyik gombot nyomjuk & Van még kő a dobozban & ???
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
  } while (digitalRead(okButton) == HIGH); // Ok megnyomásáig
}
