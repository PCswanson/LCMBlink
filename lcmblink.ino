/*
  LCMBlink (Lowest Common Multiple Blink)
  v 1.0 by Kris Swanson
  
  Arduino implementation of the following math problem:
  
  Two neon lights are turned on at the same time. 
    -One blinks every 4 seconds and the other blinks every 6 seconds.  
    -How long will it take for them to blink at the same time?
    -How many times will the 4 second light have blinked?
    -How many times will the 6 second light have blinked? 
 */
//Define the Ports that LEDs are plugged into

int LED1=12;
int LED2=11;

//Define the time in seconds between blinks

int blinkLED1=4;
int blinkLED2=6;

//Define the variable to keep track of time

int elapsedTime = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize LED pins for output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  // Initialize the serial communication 
  Serial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
  
  //Find the modulo of each blink timing, when divided by elapsed time
  //>>> If mod is 0, 
  int LED1mod = elapsedTime % blinkLED1;
  int LED2mod = elapsedTime % blinkLED2;
  
  //print the elapsed time to the serial monitor
  Serial.print(elapsedTime);
  Serial.print("\t");  
  
  // Check to see if LED1's timing is multiple of elapsed time
  if (LED1mod == 0){
    digitalWrite(LED1, HIGH);
    Serial.print("L1-on");
  
  }
  else
  {
    digitalWrite(LED1, LOW);
    Serial.print("L1-off");
  }
  
  Serial.print("\t");
  
  // Check to see if LED2's timing is multiple of elapsed time
  if (LED2mod == 0){
    digitalWrite(LED2, HIGH);
    Serial.print("L2-on");
  }
  else
  {
    digitalWrite(LED2, LOW);
    Serial.print("L2-off");
  }

  Serial.println("");  
  delay(1000);              // wait for a second
  elapsedTime ++;          //add one to elapsed time
}
