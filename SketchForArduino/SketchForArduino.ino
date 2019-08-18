#define POTENT A0 //порт в который подключен потенциометр

bool nums[10][8] = { // - массив цифр для дислея(от 0 до 9)
  // A, B, C, D, E, F, G, DP  - Форма записи для дисплея
  {1, 1, 1, 1, 1, 1, 0, 0}, //0                A
  {0, 1, 1, 0, 0, 0, 0, 0}, //1             F     B
  {1, 1, 0, 1, 1, 0, 1, 0}, //2                G
  {1, 1, 1, 1, 0, 0, 1, 0}, //3             E     C
  {0, 1, 1, 0, 0, 1, 1, 0}, //4                D
  {1, 0, 1, 1, 0, 1, 1, 0}, //5                   DP
  {1, 0, 1, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 1}  //9
};

 int potent_val;
 //замена задержки delay 
 unsigned long LAST_PRESS;
 
  void setup() {
    Serial.begin(9600); 
    pinMode(POTENT, INPUT);
    for (byte pin = 2; pin <= 9; pin++){
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }
  }

  void loop() {
    if (millis() - LAST_PRESS > 50){
      potent_val = analogRead(POTENT);
      for (byte pin = 2; pin <= 9; pin++)
        digitalWrite(pin, LOW);
      for (byte digit = 0; digit <= 9; digit++){
        if (nums[map(potent_val, 0, 1023, 0, 9)][digit] == 0)
          digitalWrite(digit + 2, LOW);
        else digitalWrite(digit + 2, HIGH);
      }
      
      LAST_PRESS = millis();
    }
  }
