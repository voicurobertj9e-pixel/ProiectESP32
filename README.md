# ProiectESP32
Buna ziua! Voicu Robert sunt de la AIA 2.3B si am terminat proiectul pentru nota 5. Am creat un program
folosindu-ma de un ESP32, iar in momentul in care ating unul din pinii acestuia, ledul albastru se aprinde.
Explicatia detaliata este in filmulet. Initial voiam sa fac ceva putin mai complex de atat, am cumparat si un senzor de temperatura
dar pe langa acesta mi-au fost livrate firele gresite si nu am reusit sa termin in timp acest proiect asa ca m-am folosit doar de microcontroller.

https://www.youtube.com/watch?v=Up993SDPNYQ



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
