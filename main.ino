#define 1button 1
#define 2button 2
#define 3button 3
#define okButton 4

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
