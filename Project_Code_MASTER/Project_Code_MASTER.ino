/* 
 *  Filename: Project_Code_MASTER
 *  Authors: Fatema Janahi, Yael Lissack, Jillian Brislin, Matthew Colgrove
 *  Brief: Code for Master Arduino 
 *  Randomly lights up lights using a random number generator and sends corresponding
 *  integer to Slave Arduino. When time is up, buzzer sounds.
 */

//Including Libraries
#include<Wire.h> //including the wire Library

//int to hold random number
int randomNumber; 

//LED pin values
int LED1 = 5;
int LED2 = 2;
int LED3 = 3;
int LED4 = 4;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;

//piezo pin values
int piezoPin = 12;

//value of minutes before buzzer sounds
unsigned long minutes = 60000;

void setup() {
  
  //initiating wire library to join I2C bus 
  Wire.begin();

  //setting up leds as outputs
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
  pinMode (LED5, OUTPUT);
  pinMode (LED6, OUTPUT);
  pinMode (LED7, OUTPUT);
  pinMode (LED8, OUTPUT);
  pinMode (LED9, OUTPUT);
  
  //seeding the random number generator
  randomSeed(analogRead(0)); 
}

void loop() {
  
  //run this code for 1 min only
  if (millis() <= minutes) { 
    
    randomNumber = random(1,10); //generate a random number
    
    Wire.beginTransmission(5); //begin transmission with Slave Arduino
    Wire.write(randomNumber); //send the random number
    Wire.endTransmission(); 

    //Light up the lights according to the number generated
    
    if (randomNumber == 1)
    {
      //turn the first light on and all others off
      digitalWrite (LED1, 255);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 2)
    {
      //turn the second light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 255);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 3)
    {
      //turn the third light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 255); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 4)
    {
      //turn the fourth light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 255); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 5)
    {
      //turn the fifth light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 255);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 6)
    {
      //turn the sixth light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 255); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 7)
    {
      //turn the seventh light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 255); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 8)
    {
      //turn the eightth light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 255);  
      digitalWrite (LED9, 0); 
    }
    
    if (randomNumber == 9)
    {
      //turn the ninth light on and all others off
      digitalWrite (LED1, 0);
      digitalWrite (LED2, 0);  
      digitalWrite (LED3, 0); 
      digitalWrite (LED4, 0); 
      digitalWrite (LED5, 0);  
      digitalWrite (LED6, 0); 
      digitalWrite (LED7, 0); 
      digitalWrite (LED8, 0);  
      digitalWrite (LED9, 255); 
    }
    
    delay(900); // keep light on for this amount of time
    
    //now turn all lights off to give user time to reposition him/herself
    digitalWrite (LED1, 0);
    digitalWrite (LED2, 0);  
    digitalWrite (LED3, 0); 
    digitalWrite (LED4, 0); 
    digitalWrite (LED5, 0);  
    digitalWrite (LED6, 0); 
    digitalWrite (LED7, 0); 
    digitalWrite (LED8, 0);  
    digitalWrite (LED9, 0); 
    
    delay(250); // keep them off for a short time
    } 
    
  // if the time is over (1 min), sound the buzzer for 2000 ms
  if ((millis() > minutes) and ( millis() <= 62000)) { 
      tone(piezoPin, 100, 500); // if its at one minute then make the sound 
  }
  else 
  {
     // at any other time - no sound
  }
 }
 
