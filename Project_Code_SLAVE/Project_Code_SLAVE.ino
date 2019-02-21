/* 
 *  Filename: Project_Code_SLAVE
 *  Authors: Fatema Janahi, Yael Lissack, Jillian Brislin, Matthew Colgrove
 *  Brief: Code for Slave Arduino 
 *  Uploaded to board connected to  force sensors and LCD screen. Receives random
 *  number from master and checks to see if corresponding force sensor is being
 *  pressed. Adds points accordingly.
 */

//Including libraries
#include<Wire.h>
#include<LiquidCrystal.h>

//setting up LCD screen
const int rs = 12, en = 11, d4 =5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//declaring variables to hold data
int numberfrommaster;
int points = 0;

//time to run for
unsigned long minutes = 60000;

//button pin values
const int buttonPin1 = 6;
const int buttonPin2 = 7;
const int buttonPin3 = 8;
const int buttonPin4 = 9;
const int buttonPin5 = 10;
const int buttonPin6 = A0;
const int buttonPin7 = A1;
const int buttonPin8 = A2;
const int buttonPin9 = A3;

//button states set to OFF
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;

//function receives data from Master Arduino
void receiveEvent(int howManybytes)
{
    while(Wire.available())
    {
        numberfrommaster = Wire.read();
    }
}

void setup() {
    //begin serial data transmission
    Serial.begin(9600);
    //begin I2C Communication
    Wire.begin(5);
    Wire.onReceive(receiveEvent);
    //initialize screen
    lcd.begin(16,2);

}

void loop() {

    //if time is not up
    if (millis() <= minutes) {

      //depending on the number received from master, read whether that
      //button is being pressed, and increment score accordingly
      
      if (numberfrommaster==1)
      {
          delay(750); //time delay for user to press button
          
          buttonState1 = digitalRead(buttonPin1); //read button
          
          if (buttonState1 == HIGH) //increment points if pressed
          {
              points = points + 10;
          }
            delay(250);
      }
      
      
      if (numberfrommaster==2)
      {
          delay(750);
          
          buttonState2 = digitalRead(buttonPin2);
          if (buttonState2 == HIGH)
          {
              points = points + 10;
          }
              
            delay(250);
      }

    
      if (numberfrommaster==3)
      {
          delay(750);
          
          buttonState3 = digitalRead(buttonPin3);
          if (buttonState3 == HIGH)
          {
              points = points + 10;
          }
 
          delay(250);
      }


    
      if (numberfrommaster==4)
      {
          delay(750);
          
          buttonState4 = digitalRead(buttonPin4);
          if (buttonState4 == HIGH)
          {
              points = points + 10;
            
          }
          delay(250);
      }
    
      if (numberfrommaster==5)
      {
          delay(750);
          
          buttonState5 = digitalRead(buttonPin5);
          if (buttonState5 == HIGH)
          {
              points = points + 10;
          }
          delay(250);
      }
    
      if (numberfrommaster==6)
      {
          delay(750);
          
          buttonState6 = digitalRead(buttonPin6);
          if (buttonState6 == HIGH)
          {
             points = points + 10;
          }
              
          delay(250);
      }
              
              
      if (numberfrommaster==7)
      {
          delay(750);
         
          buttonState7 = digitalRead(buttonPin7);
          if (buttonState7 == HIGH)
          {
            points = points + 10;
            
          }
          delay(250);
      }
    
    
      if (numberfrommaster==8)
      {
          delay(750);
          
          buttonState8 = digitalRead(buttonPin8);
          if (buttonState8 == HIGH)
          {
            points = points + 10;
          }
          delay(250);
      }
    
      if (numberfrommaster==9)
      {
        delay(750);
       
        buttonState9 = digitalRead(buttonPin9);
        if (buttonState9 == HIGH)
        {
          points = points + 10;
        }
        delay(250);
      }
    
    //output points to LCD screen as game is played
    lcd.setCursor(0, 0); 
    lcd.print("Points:  ");
    lcd.setCursor(0, 1);
    lcd.print(points);
    }
else //time is up
    {
    //display total points
    lcd.setCursor(0, 0); 
    lcd.print("Total points:  ");
    lcd.setCursor(0, 1);
    lcd.print(points);
      }
}



