// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzy = 8;

/* musical constants */
// note frequencies (in hz)
const int G4 = 392;
const int GFLAT4 = 370;
const int D4 = 294; // 293.66 hz
const int B3 = 247;
// note lengths (in ms at 150 bpm) and other misc.
const int QUARTER = 400;
const int EIGHTH = 200;
const bool STACCATO = true;

// defines variables
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}

void loop() {

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance
    distance = duration * 0.034 / 2;

    if (distance < 100) {
        digitalWrite(7, HIGH);
        //spoopyMusic();

        // for now... because we need an on/off switch or a WAY longer delay.
        delay(6400);

        digitalWrite(7, LOW);
    }
}

void playNote(int note, int noteLength, bool staccato = false) {

  tone(buzzy, note);
  if (staccato == false) {
    delay(noteLength);
    noTone(buzzy);
  } else {
    // Note lengths are halved when staccato is true
    delay(noteLength / 2);
    noTone(buzzy);
    delay(noteLength / 2);
  }
}

void spoopyMusic() {

  // Example:
  // tone(buzzy, 440);   // Send 1KHz sound signal...
  // delay(1000);        // ...for 1 sec
  // noTone(buzzy);      // Stop sound...

  // Spooky Scary Skeletons:
  // Measure 1
  playNote(G4, QUARTER, STACCATO);
  playNote(G4, QUARTER, STACCATO);
  playNote(GFLAT4, QUARTER, STACCATO);
  playNote(GFLAT4, QUARTER, STACCATO);
  // 2
  playNote(B3, QUARTER);
  playNote(D4, EIGHTH);
  playNote(B3, QUARTER);
  playNote(D4, EIGHTH);
  playNote(B3, QUARTER);
  // 3
  playNote(G4, QUARTER, STACCATO);
  playNote(G4, QUARTER, STACCATO);
  playNote(GFLAT4, QUARTER, STACCATO);
  playNote(GFLAT4, QUARTER, STACCATO);
  // 4
  playNote(B3, QUARTER);
  delay(1200); // delay for 1200 ms is 3/4 rest

}
