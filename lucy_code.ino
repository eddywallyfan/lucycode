#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;
const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)


// sensor
// defines pins numbers for sensor
const int trigPin = 10; 
const int echoPin = 5;


// defines variables
long duration;
int distance;



void setup() {

  // sensor

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  MP3player.setVolume(1,1);


}

//do something else now
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
  distance = (duration / 2) / 54;
  Serial.println(distance);

  
  // Distance is lower then 5
if (MP3player.isPlaying() == 1) {
        delay(2000);
        MP3player.stopTrack();
      }

  if (distance < 20) {
    // play sound
    MP3player.playTrack(4);
    Serial.println("distance 1 (20cm)");
    delay (1000);

  } else {
  
  if (distance == 45) {

      // play sound
      MP3player.playTrack(7);
      Serial.println("distance 2 (36cm)");
    }
 
  if (distance == 80) {

      // play sound
      MP3player.playTrack(3);
      Serial.println("distance 3 (75cm)");
      
    }

 
  }

}
