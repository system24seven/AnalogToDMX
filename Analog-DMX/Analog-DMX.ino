/*
  Writes level 100 to DMX channel 1 (address 0) when button connected to pin 2 is pushed
*/

// Include the SPI library:
#include <SPI.h>

// pushbutton pin
const int analogPin1 = 0;
// pushbutton status
int input1State = 0;
// Delay of 10 microseconds. At least 6 microseconds required between each SPI command
const int delayTime = 20;

// Set up SPI speed, data order and data mode
SPISettings settings(125000, MSBFIRST, SPI_MODE1);

void setup() {
  // Initialise the pushbutton pin as an input:
  pinMode(analogPin1, INPUT);
  pinMode(13,OUTPUT);
  // Initalise SPI Slave Select (also known as chip select) and set high
  pinMode (SS, OUTPUT);
  digitalWrite(SS, HIGH);
  // Initialise SPI
  SPI.begin();
}

void loop() {
  // Read the state of the pushbutton value:
  input1State = map(analogRead(analogPin1), 0, 1024, 0, 102);
  //analogWrite(13, input1State);

    SPI.beginTransaction(settings);
    // Set the Slave Select pin low to select the chip:
    digitalWrite(SS, LOW);

    // Control byte. Write to specific DMX channel being transmitted
    SPI.transfer(0xE0);
    delayMicroseconds(delayTime);
    // Lower 8 bits of channel address
    SPI.transfer(0x00);
    delayMicroseconds(delayTime);
    // Level 100 is written to channel address 0 (DMX channel 1)
    SPI.transfer(input1State);

    // Set the Slave Select pin high to deselect the chip
    digitalWrite(SS, HIGH);
    SPI.endTransaction();
    delay(100);

    
    SPI.beginTransaction(settings);
    // Set the Slave Select pin low to select the chip:
    digitalWrite(SS, LOW);

    // Control byte. Write to specific DMX channel being transmitted
    SPI.transfer(0xE0);
    delayMicroseconds(delayTime);
    // Lower 8 bits of channel address
    SPI.transfer(0x01);
    delayMicroseconds(delayTime);
    // Level 100 is written to channel address 0 (DMX channel 1)
    SPI.transfer(input1State);

    // Set the Slave Select pin high to deselect the chip
    digitalWrite(SS, HIGH);
    SPI.endTransaction();

    delay(100);
     SPI.beginTransaction(settings);
    // Set the Slave Select pin low to select the chip:
    digitalWrite(SS, LOW);

    // Control byte. Write to specific DMX channel being transmitted
    SPI.transfer(0xE0);
    delayMicroseconds(delayTime);
    // Lower 8 bits of channel address
    SPI.transfer(0x02);
    delayMicroseconds(delayTime);
    // Level 100 is written to channel address 0 (DMX channel 1)
    SPI.transfer(input1State);

    // Set the Slave Select pin high to deselect the chip
    digitalWrite(SS, HIGH);
    SPI.endTransaction();
    delay(100);

    
    SPI.beginTransaction(settings);
    // Set the Slave Select pin low to select the chip:
    digitalWrite(SS, LOW);

    // Control byte. Write to specific DMX channel being transmitted
    SPI.transfer(0xE0);
    delayMicroseconds(delayTime);
    // Lower 8 bits of channel address
    SPI.transfer(0x03);
    delayMicroseconds(delayTime);
    // Level 100 is written to channel address 0 (DMX channel 1)
    SPI.transfer(input1State);

    // Set the Slave Select pin high to deselect the chip
    digitalWrite(SS, HIGH);
    SPI.endTransaction();
    delay(100);
  
}
