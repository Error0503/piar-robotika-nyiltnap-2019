#define button1 1
#define button2 2
#define button3 3
#define button4 4
#define okButton 5

int boxes[4] = [ 4, 5, 5, 4 ];
bool is_player_turn = false;
randomSeed(analogRead(A0));

void AI()
{
  int i, n = 0;
  bool leptem = false;
  // nim összeg
  for (i = 0; i < 4; i++)
  {
    n = n ^ boxes[i];
  }
  // valid lépés keresése
  if (n != 0)
  {
    for (i = 0; i < sizeof(boxes)/sizeof(int); i++)
    {
      // lépés megtalálása és meglépése
      if ((boxes[i] ^ n) < n && (leptem == false))
      {
        boxes[i] -= n;
        // lépés befejezése
        leptem = true;
      }
    }
  }
  else
  {
    //olyanból is ki tud vonni, amiben nincs
    boxes[random(0, 4)]--;
  }
}
void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(okButton, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

void UserInput()
{
  int selected = 4;
  do
  {
    if (digitalRead(button1) == HIGH & boxes[0] > 0 & (selected == 0 || selected == 4))
    {
      boxes[0]--;
      selected = 0;
    }
    else if (digitalRead(button2) == HIGH & boxes[1] > 0 & (selected == 1 || selected == 4))
    {
      boxes[1]--;
      selected = 1;
    }
    else if (digitalRead(button3) == HIGH & boxes[2] > 0 & (selected == 2 || selected == 4))
    {
      boxes[2]--;
      selected = 2;
    }
    else if (digitalRead(button4) == HIGH & boxes[3] > 0 & (selected == 3 || selected == 4))
    {
      boxes[3]--;
      selected = 3;
    }
  } while (digitalRead(okButton) == LOW);
}