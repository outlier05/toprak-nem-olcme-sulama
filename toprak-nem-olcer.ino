int led1 = 3;
int led2 = 4;
int led3 = 5;
int motor = 7;

int toprakSensor = 0;
int sinyal = 6;

void setup() {
 //serial bağlantısını açtık
  Serial.begin(9600);
 //led çıkışlarının belirledik
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sinyal, OUTPUT);
  pinMode(motor, OUTPUT);

}

void loop() {
  nem_olc();

  Serial.println(toprakSensor);

  if (toprakSensor >= 250) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(motor, HIGH);
    }
  else if (toprakSensor < 250 && toprakSensor >= 150) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(motor, HIGH);
    }
   else if (toprakSensor < 150) {
   digitalWrite(led1, HIGH);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(sinyal, HIGH);
   delay(3000);
   digitalWrite(sinyal, LOW);
   digitalWrite(motor, LOW);
   delay(5000);
   digitalWrite(motor, HIGH);
   }
   delay(1000);

}

void nem_olc() {
  int toprakSensor = analogRead(toprakSensor);
  delay(1000);
  }
