/*
   This is the Hexaton ITPDP project code, the installation consists of 16 buttons, and 16 LEDs. When the program starts, the buttons will blink three times, after that a random LED will light up.
   When you push on the button to the corresponding light, a new LED will light up, and so forth until the game ends. When the game ends, the program will redirect the values: bestTime(),worstTime(),Player() to the server.

*/

int btn1 = 2;
int btn2 = 4;
int btn3 = 6;
int btn4 = 8;
int btn5 = 10;
int btn6 = 12;
int btn7 = 14;
int btn8 = 16;
int btn9 = 18;
int btn10 = 20;
int btn11 = 22;
int btn12 = 24;
int btn13 = 26;
int btn14 = 28;
int btn15 = 30;
int btn16 = 32;
int btn17 = 34;
int btn18 = 36;
int btn19 = 38;
int btn20 = 40;
int btn21 = 42;
int btn22 = 44;
int btn23 = 46;
int btn24 = 48;


int led1 = 3;
int led2 = 5;
int led3 = 7;
int led4 = 9;
int led5 = 11;
int led6 = 13;
int led7 = 15;
int led8 = 17;
int led9 = 19;
int led10 = 21;
int led11 = 23;
int led12 = 25;
int led13 = 27;
int led14 = 29;
int led15 = 31;
int led16 = 33;
int led17 = 35;
int led18 = 37;
int led19 = 39;
int led20 = 41;
int led21 = 43;
int led22 = 45;
int led23 = 47;
int led24 = 49;



int l2ed = 0;
int led = 0; // random værdi
int rdm = 0; //random værdi
int startBlink = 1;

long pushTimes[20];

// værdier der bruges til at tjekke array op mod hinanden
int first = 0;
int second;
long biggest;

int counter = 0;

void setup() {
  Serial.begin(9600);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  pinMode(btn6, INPUT_PULLUP);
  pinMode(btn7, INPUT_PULLUP);
  pinMode(btn8, INPUT_PULLUP);
  pinMode(btn9, INPUT_PULLUP);
  pinMode(btn10, INPUT_PULLUP);
  pinMode(btn11, INPUT_PULLUP);
  pinMode(btn12, INPUT_PULLUP);
  pinMode(btn13, INPUT_PULLUP);
  pinMode(btn14, INPUT_PULLUP);
  pinMode(btn15, INPUT_PULLUP);
  pinMode(btn16, INPUT_PULLUP);
  pinMode(btn17, INPUT_PULLUP);
  pinMode(btn18, INPUT_PULLUP);
  pinMode(btn19, INPUT_PULLUP);
  pinMode(btn20, INPUT_PULLUP);
  pinMode(btn21, INPUT_PULLUP);
  pinMode(btn22, INPUT_PULLUP);
  pinMode(btn23, INPUT_PULLUP);
  pinMode(btn24, INPUT_PULLUP);


  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(led19, OUTPUT);
  pinMode(led20, OUTPUT);
  pinMode(led21, OUTPUT);
  pinMode(led22, OUTPUT);
  pinMode(led23, OUTPUT);
  pinMode(led24, OUTPUT);





  randomSeed(analogRead(0));
}

void loop() {
  while (counter < 20) {
    if (startBlink == 1) {
      blinkStart();
    }
    gamemode2();
    Serial.print("Time: ");
    Serial.println(pushTimes[counter]);
  }
  Serial.print("best: ");
  Serial.println(makeRealSec(returnBest())); // returns the best time in seconds(double)
  Serial.print("Worst: ");
  Serial.println(makeRealSec(returnWorst())); // returns the best time in seconds(double)
  delay(20000);

}

double makeRealSec(double value) { // turns millis into seconds.
  return value / 1000;
}

long getTime() {
  return millis();
}

/////
void returnTimes() {} // funktion der returnerer alle værdier i pushTimes array

long returnBest() {
  int i;
  biggest = pushTimes[2];
  first = pushTimes[2];
  for (i = 3; i < 21; i++) {
    second = pushTimes[i];
    int dif = second - first;
    if (dif < biggest) {
      first = second;
      biggest = dif;
    }
    else {
      first = second;
    }
  }
  return biggest;

} // funktion der returnerer den bedste reaktionstid

long returnWorst() {
  int i;
  biggest = pushTimes[2];
  first = pushTimes[2];
  for (i = 3; i < 21; i++) {
    second = pushTimes[i];
    int dif = second - first;
    if (dif > biggest) {
      first = second;
      biggest = dif;
    }
    else {
      first = second;
    }
  }
  return biggest;
}

void serverSend() {} // HER SKAL VÆRE ET SCRIPT DER KOMMUNIKERER MED SERVEREN
// funktion der returnerer værste reaktionstid


////
void blinkStart() {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led4, HIGH);
  delay(200);
  digitalWrite(led5, HIGH);
  delay(200);
  digitalWrite(led6, HIGH);
  delay(200);
  digitalWrite(led7, HIGH);
  delay(200);
  digitalWrite(led8, HIGH);
  delay(200);
  digitalWrite(led9, HIGH);
  delay(200);
  digitalWrite(led10, HIGH);
  delay(200);
  digitalWrite(led11, HIGH);
  delay(200);
  digitalWrite(led12, HIGH);
  delay(200);
  digitalWrite(led13, HIGH);
  delay(200);
  digitalWrite(led14, HIGH);
  delay(200);
  digitalWrite(led15, HIGH);
  delay(200);
  digitalWrite(led16, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);
  digitalWrite(led14, LOW);
  digitalWrite(led15, LOW);
  digitalWrite(led16, LOW);

}

void gamemode1() {
  rdm = random(3, 14); // bestemmer hvor mange LED/knapper vi har på boardet.


  if (rdm == led) { // check om at den samme LED ikke lyser igen
    led = random(3, 14);
  }
  else {
    led = rdm;
  }

  if (led % 2 == 0) {
    led = led + 1;
  }
  delay(200);
  while (digitalRead(led - 1) == HIGH) {
    digitalWrite(led, HIGH);
  }
  Serial.print(" knap: ");
  Serial.println(digitalRead(led - 1));
  delay(200);
  digitalWrite(led, LOW);
  counter++;
  pushTimes[counter] = getTime();
  startBlink = 0;
}


void gamemode2() { // Player vs. Player game.
  rdm = random(2, 25); // bestemmer hvor mange LED/knapper vi har på boardet.


  if (rdm == led ) { // check om at den samme LED ikke lyser igen
    led = random(2, 25);
    l2ed = led + 24;
  }
  else {
    led = rdm;
    l2ed = led + 24;
  }

  if (led % 2 == 0) {
    led = led + 1;
    l2ed = led + 24;
  }
  delay(200);
  while (digitalRead(led - 1) == HIGH && digitalRead(l2ed - 1) == HIGH) { // As long as no players have pushed on their buttons, both LEDs will light up.
    digitalWrite(led, HIGH);
    digitalWrite(l2ed, HIGH);
    delay(200);
  }
  Serial.print(" knap: ");
  Serial.println(digitalRead(led - 1));
  delay(200);
  digitalWrite(led, LOW);
  digitalWrite(l2ed, LOW);
  counter++;
  Serial.print("count: ");
  Serial.println(counter);

  pushTimes[counter] = getTime();
  startBlink = 0;

}
