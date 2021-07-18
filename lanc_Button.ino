
int buttonState = 0;
#define cmdPin 7 
#define lancPin 4
#define ledPin 13
#define recButton 9

int cmdRepeatCount;
int bitDuration = 104;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(recButton, INPUT);
  
pinMode(lancPin, INPUT); //listens to the LANC line
pinMode(cmdPin, OUTPUT); //writes to the LANC line
pinMode(recButton, INPUT); //start-stop recording button
digitalWrite(recButton, HIGH); //turn on an internal pull up resistor
digitalWrite(cmdPin, LOW); //set LANC line to +5V
delay(800); //Wait for camera to power up completly
bitDuration = bitDuration - 8; //Writing to the digital port takes about 8 microseconds so only 96 microseconds are left till the end of each bit
}


void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(recButton);


if (!digitalRead(recButton)) {

REC();{
  digitalWrite(ledPin, HIGH);
delay(250); //debounce button
}


  
void REC() {



//Write the 8 bits of byte 0 
//"18hex" or “00011000”  tells the camera that there will be a normal command to camera in the next byte
//Note that the command bits have to be put out in reverse order with the least significant, right-most bit (bit 0) first
digitalWrite(cmdPin, LOW);  //Write bit 0. 
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, LOW);  //Write bit 1 
delayMicroseconds(bitDuration);  
digitalWrite(cmdPin, LOW);  //Write bit 2
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, HIGH);  //Write bit 3
delayMicroseconds(bitDuration);  
digitalWrite(cmdPin, HIGH);  //Write bit 4
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, LOW);  //Write bit 5 
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, LOW);  //Write bit 6
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, LOW);  //Write bit 7
delayMicroseconds(bitDuration);
//Byte 0 is written now put LANC line back to +5V
digitalWrite(cmdPin, LOW);
delayMicroseconds(10); //make sure to be in the stop bit before byte 1


//0V after the previous stop bit means the START bit of Byte 1 is here
delayMicroseconds(bitDuration);  //wait START bit duration

//Write the 8 bits of Byte 1
//"33hex" or “00110011” sends the  Record Start/Stop command
//Note that the command bits have to be put out in reverse order with the least significant, right-most bit (bit 0) first
digitalWrite(cmdPin, HIGH);  //Write bit 0 
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, HIGH);  //Write bit 1 
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, LOW);  //Write bit 2
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, LOW);  //Write bit 3
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, HIGH);  //Write bit 4 
delayMicroseconds(bitDuration); 
digitalWrite(cmdPin, HIGH);  //Write bit 5
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, LOW);  //Write bit 6
delayMicroseconds(bitDuration);
digitalWrite(cmdPin, LOW);  //Write bit 7
delayMicroseconds(bitDuration);
//Byte 1 is written now put LANC line back to +5V
digitalWrite(cmdPin, LOW); 

/*Control bytes 0 and 1 are written, now don’t care what happens in Bytes 2 to 7
and just wait for the next start bit after a long pause to send the first two command bytes again.*/


}}

