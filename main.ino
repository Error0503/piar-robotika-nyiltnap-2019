#define button1 1
#define button2 2
#define button3 3
#define button4 4
#define okButton 5

int boxes[4] = [ 4, 5, 5, 4 ];
bool is_player_turn = false;

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
	// kivon egyet egy nemnulla értékű dobozból egyet
	for (i = 0; i < 4; i++){
		if (boxes[i] != 0 && lpetem == false){
			boxes[i]--;
			leptem = true;
		}
	}
}
void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(okButton, INPUT);
  pinMode(pin3, OUTPUT);     
  pinMode(pin4, OUTPUT);     
  pinMode(pin5, OUTPUT);     
  pinMode(pin6, OUTPUT);     
  pinMode(pin7, OUTPUT);     
  pinMode(pin8, OUTPUT);     
  pinMode(pin9, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);
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
void display(){
	int x 
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
	
	int numbers [9][7] = {{0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,0}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}}

		for(i=0; i==boxes[x]; i++){
			if(boxes[x][i]){
				digitalWrite(boxes[x][i], HIGH);
			}
			else{ 	
				digitalWrite(boxes[x][i], LOW);
			}		
		}

}
