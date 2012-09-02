#include <SPI.h>
#include <RF24.h>
#include "nRF24L01.h"


int red = 10;
int green = 6;
int blue = 5;
int left=4;
int right = 7;
unsigned int rate = 1000;

RF24 radio(9,10);

int R[3] = {255, 255, 0};
int G[3] = {255, 0, 255};
int B[3] = {0, 255, 255};
int C[3] = {0, 0, 255};
int M[3] = {0, 255, 0};
int Y[3] = {255, 0, 0};


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT);     
  pinMode(green, OUTPUT);     
  pinMode(blue, OUTPUT);     
  pinMode(right, OUTPUT);     
  digitalWrite(right, HIGH);
  pinMode(left, OUTPUT);     
  digitalWrite(left, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  int *colour = 0;
  byte n=0;
  for (n=0; n<6; n++) {
    switch (n) {
      case 0:
        colour = R;
        break;
      case 1:
        colour = G;
        break;
      case 2:
        colour = B;
        break;
      case 3:
        colour = C;
        break;
      case 4:
        colour = M;
        break;
      case 5:
        colour = Y;
        break;
    }
    analogWrite(red, colour[0]);
    analogWrite(green, colour[1]);
    analogWrite(blue, colour[2]);
    delay(rate);
  }

}
