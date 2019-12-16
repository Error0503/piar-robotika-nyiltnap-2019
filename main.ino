#include <math.h>
#define button1 A5
#define button2 A4
#define button3 A3
#define button4 A2
#define okButton A1

int boxes[4] = {1, 0, 1, 1};
bool leptem = false;

void (*resetFunc)(void) = 0;

void randomFill(void)
{
  int i = 0;
  randomSeed(analogRead(A0));
  for (; i < 4; i++)
  {
    boxes[i] = random(1, 10);
  }
}

void writeWinner(int winner) //ez valamiért nem működik még
{
  int i, j;
  int letters1[3][7] = {
      {1, 0, 0, 1, 1, 1, 0},  // C betű
      {1, 1, 0, 0, 1, 1, 1},  // P betű
      {0, 1, 1, 1, 1, 1, 0}}; // U betű
  int letters2[3][7] = {
      {0, 1, 1, 1, 0, 1, 1},  // Y betű
      {1, 1, 1, 1, 1, 1, 0},  // O betű
      {0, 1, 1, 1, 1, 1, 0}}; // U betű

  for (i = 2; i < 9; i++)
  {
    digitalWrite(i, LOW);
  }
  for (i = 9; i < 13; i++)
  {
    digitalWrite(i, HIGH);
  }

  if (winner)
  {
    while (!digitalRead(okButton) && !digitalRead(button1) && !digitalRead(button2) && !digitalRead(button3) && !digitalRead(button4))
    {
      for (i = 0; i < 3; i++)
      {
        digitalWrite(i + 9, LOW);
        for (j = 0; j < 7; j++)
        {
          digitalWrite(j + 2, letters2[i][j]);
        }

        delayMicroseconds(1000);
        digitalWrite(i + 9, HIGH);
      }
    }
  }
  if (winner == 0)
  {
    while (!digitalRead(okButton) && !digitalRead(button1) && !digitalRead(button2) && !digitalRead(button3) && !digitalRead(button4))
    {
      digitalWrite(13, HIGH);
      for (i = 0; i < 3; i++)
      {
        digitalWrite(i + 9, LOW);
        for (j = 0; j < 7; j++)
        {
          digitalWrite(j + 2, letters1[i][j]);
        }

        delayMicroseconds(1000);
        digitalWrite(i + 9, HIGH);
      }
    }
  }
  resetFunc();
}

void setup()
{
  randomFill();
  Serial.begin(9600);
  int i;
  Serial.println("Setup begin.");

  for (i = 2; i < 9; i++)
  {
    pinMode(i, OUTPUT);
  }
  for (i = 9; i < 13; i++)
  {
    pinMode(i, OUTPUT);

    digitalWrite(i, HIGH);
  }
  for (i = 13; i < 21; i++)
  {
    pinMode(i, INPUT);
  }
  Serial.println("Setup success.");
}

void loop()
{
  int sum = 0;
  for (int i = 0; i < 4; i++)
  {
    sum += boxes[i];
  }
  if (sum != 0)
  {
    Serial.println("Called userinput.");
    UserInput();
  }
  else
  {
    writeWinner(0);
  }
  sum = 0;
   for (int i = 0; i < 4; i++)
  {
    sum += boxes[i];
  }
  if (sum != 0)
  {
    Serial.println("Called AI.");
    comp();
  }
  else
  {
    writeWinner(1);
  }
  display();
}

void comp()
{
  int nimsum = boxes[0] ^ boxes[1] ^ boxes[2] ^ boxes[3]; //n
  int i, maxpow, maxval = 0, maxs = 0;
  if (nimsum)
  {
    for (i = 0; i <= 4; i++)
    {
      if (nimsum / (int)pow(2, i))
        maxpow = i;
    }

    for (i = 0; i < 4; i++)
    {
      if ((boxes[i] & (int)(pow(2, maxpow + 1) - 1)) >= maxval)
      {
        maxs = i;
        maxval = (boxes[i] & (int)(pow(2, maxpow + 1) - 1));
      }
      else
      {
      }
    }

    boxes[maxs] = boxes[maxs] ^ nimsum;
  }

  else
  {
    for (i = 0; i < 4; i++)
    {
      if (boxes[i] >= boxes[maxs])
      {
        maxs = i;
      }
    }
    boxes[maxs]--;
  }
}

void AI()
{
  int i, n = 0;
  // nim összeg
  for (i = 0; i < 4; i++)
  {
    n = n ^ boxes[i];
  }
  Serial.println(n);
  // valid lépés keresése
  if (n != 0)
  {
    for (i = 0; i < 4; i++)
    {
      // lépés megtalálása és meglépése
      if ((boxes[i] ^ n) < n && (leptem == false))
      {
        boxes[i] = boxes[i] ^ n;
        Serial.println(boxes[i]);
        // lépés befejezése
        leptem = true;
      }
    }
  }
  else
  {
    // kivon egyet egy nemnulla értékű dobozból egyet
    for (i = 0; i < 4; i++)
    {
      if (boxes[i] != 0 && leptem == false)
      {
        boxes[i]--;
        leptem = true;
      }
    }
  }
}

void UserInput()
{
  int selected = 4;
  do
  {
    display();
    if (digitalRead(button1) == HIGH && boxes[0] > 0 && (selected == 0 || selected == 4))
    {
      boxes[0]--;
      selected = 0;
      delay(500);
    }
    else if (digitalRead(button2) == HIGH && boxes[1] > 0 && (selected == 1 || selected == 4))
    {
      boxes[1]--;
      selected = 1;
      delay(500);
    }
    else if (digitalRead(button3) == HIGH && boxes[2] > 0 && (selected == 2 || selected == 4))
    {
      boxes[2]--;
      selected = 2;
      delay(500);
    }
    else if (digitalRead(button4) == HIGH && boxes[3] > 0 && (selected == 3 || selected == 4))
    {
      boxes[3]--;
      selected = 3;
      delay(500);
    }
  } while ((!digitalRead(okButton) && selected != 4) || selected == 4);
  delay(500);
  leptem = false;
  return;
}

void display()
{
  int x, i, j;
  int pin2 = 2;
  int pin3 = 3;
  int pin4 = 4;
  int pin5 = 5;
  int pin6 = 6;
  int pin7 = 7;
  int pin8 = 8;
  int D1 = 9;
  int D2 = 10;
  int D3 = 11;
  int D4 = 12;

  int numbers[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 1},
                        {1, 1, 1, 1, 0, 0, 1},
                        {0, 1, 1, 0, 0, 1, 1},
                        {1, 0, 1, 1, 0, 1, 1},
                        {1, 0, 1, 1, 1, 1, 1},
                        {1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 0, 1, 1}};

  for (i = 0; i < 4; i++)
  {
    digitalWrite(i + 9, LOW);
    x = boxes[i];
    for (j = 0; j < 7; j++)
    {
      digitalWrite(j + 2, numbers[x][j]);
    }

    delayMicroseconds(1000);
    digitalWrite(i + 9, HIGH);
  }
}
