const int ledPin = 2;      // lad albastru
const int touchPin = 4;    // g4

// limita este 1200, dacca scade sub aceasta limita se considera ca am atins pinul
const int limitaAtingere = 1200; 

void setup() {
  Serial.begin(115200);   
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valoareTouch = touchRead(touchPin); 

  Serial.print("Valoare senzor: ");
  Serial.println(valoareTouch);

  
  if (valoareTouch < limitaAtingere) {
    digitalWrite(ledPin, HIGH); // aprinde cand scade sub 600
  } else {
    digitalWrite(ledPin, LOW);  // ramane stins la aprox. 1840
  }

  delay(100); 
}
