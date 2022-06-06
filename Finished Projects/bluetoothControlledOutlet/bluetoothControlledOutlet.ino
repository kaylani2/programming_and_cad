/*
 * Update: 12/11/2017
 * 
 * Holy shit! This code is really badly written. Since it works just fine for my purposes I'll leave exactly like it is.
 * Suggested modifications:
 *  -> Use char arrays instead of String objects
 *  -> Remove all the "ifdef nano" bullshit. Just change the pin numbers if needed instead
 *  -> Define all the (now, after removing the "ifdef" statements) constant values as macros
 *  -> DO NOT USE THE AUTO INDENT COMMAND. The code is hard to read as it is, the auto indent command makes it even worse.
 *  
 *  
 */

/*
 * Coded by Kaylani Bochie
 * Questions: kaylani2@hotmail.com
 * 
 * Created:  5/2/2017
 * Last modification: 12/2/2017
 */

/*
 * This code works on the computer keyboard 
 * But only works when the bluetooth module is not connected to the pins 0 and 1 of the arduino
 * This code also works with the HC-05 Bluetooth Module, it should work with any other bluetooth modules  
 * 
 * Code function: Control an outlet using bluetooth comunication with password protection and voice commands available
*/


char inputChar = "";
String inputString = "";          //OOP, HEAP INEFFICIENCY, TRIED USING CHAR ARRAYS, DIDN'T WORK, GO FIGURE
int lock = 1;
int relayPin = 6;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
const int testPin = 13;

/*
 * The PWM pins are being used because the first version of the code controlled the brightness of the leds, you can change to any digital pins now and it should work just fine
 */


//UNCOMMENT THE NEXT LINE IF USING AN ARDUINO NANO INSTEAD OF UNO
#define ARDUINO_NANO

void setup()
{
  #ifdef ARDUINO_NANO
    relayPin = 5;
    redPin = 2;
    greenPin = 3;
    bluePin = 4;
  #endif
  
  Serial.begin (9600);
  pinMode (relayPin, OUTPUT);
  pinMode (redPin, OUTPUT);  
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  pinMode (testPin , OUTPUT);
  digitalWrite (relayPin , HIGH);       //LOW LEVEL TRIGGER
  digitalWrite (redPin , LOW);
  digitalWrite (greenPin , LOW);
  digitalWrite (bluePin , HIGH);
  digitalWrite (testPin , HIGH);
}

void loop()
{
  if (Serial.available ()) {

   

    inputChar = (char) Serial.read ();
    
    if ((inputChar == '\n') || (inputChar == '#')) 
    {          
    //CAN BE USED WITH \N OR \R, NOT BOTH, DON'T KNWOW WHY

      
    /*
     * I'm also using an Android app called AMR_Voice to control the relay states
     * The app doesn't send a new line feed or a return carriage (I think) with the input string
     * And it sends, by default, an asterisk(*) before and a hashtag/pound/sharp(#) symbol after the command
     * So, when reading from the buffer, the code looks for the new line feed or the hashtag
     * And it was easier to change my keywords to portuguese since my phone is set to it, just change the keywords to whatever you like and add as many as you want using the or (||) operator
     * 
     */

      inputString.toLowerCase ();

      if (  ((inputString == "*ligar painel") || 
            (inputString == "*acender painel") || 
            (inputString == "*ligar televisao") || 
            (inputString == "*ligar ar condicionado") || 
            (inputString == "*ligar ar-condicionado") || 
            (inputString == "*ligar ventilador") || 
            (inputString == "*ligar") || 
            (inputString == "*ligar tomada") || 
            (inputString == "*acender") || 
            (inputString == "*acender luz")) && (lock == 0)) 
      {
        digitalWrite (redPin , LOW);
        digitalWrite (greenPin , HIGH);
        digitalWrite (relayPin , LOW);     //low level trigger
        Serial.println ("The outlet is now on");
      }

      else if (   ((inputString == "*desligar painel") || 
                  (inputString == "*apagar painel") || 
                  (inputString == "*desligar televisao") || 
                  (inputString == "*desligar ar condicionado") || 
                  (inputString == "*desligar ar-condicionado") || 
                  (inputString == "*desligar ventilador") || 
                  (inputString == "*desligar") || 
                  (inputString == "*desligar tomada") || 
                  (inputString == "*apagar") || 
                  (inputString == "*apagar luz")) && (lock == 0)) 
      {   
        digitalWrite (greenPin , LOW);
        digitalWrite (redPin , HIGH);
        digitalWrite (relayPin , HIGH);   //low level trigger
        Serial.println ("The outlet is now off");
      }

      else if (   ((inputString == "*ligar") || 
                  (inputString == "*ligar tomada") || 
                  (inputString == "*acender") || 
                  (inputString == "*acender luz") || 
                  (inputString == "*apagar") || 
                  (inputString == "*apagar luz") || 
                  (inputString == "*desligar") || 
                  (inputString == "*desligar tomada") ) && (lock == 1)) 
      {
        Serial.println ("System locked");
        Serial.println ("Enter the password");
      }

      else if (inputString == "*teste") 
      {    //testPin led (13)
        digitalWrite (testPin , !digitalRead (13));
      }

      else if (inputString == "*bloquear sistema")
      {
        if (lock == 0) {
          lock = 1;
          digitalWrite (redPin , LOW);
          digitalWrite (greenPin , LOW);
          digitalWrite (bluePin , HIGH);
          digitalWrite (relayPin , HIGH);     //low level trigger
          Serial.println ("System locked");
        } 
      }

      else if (inputString == "*desbloquear sistema") //you may change this password
      {      
        if (lock == 1) 
        {
          lock = 0;
          digitalWrite (bluePin , LOW);
          digitalWrite (redPin , HIGH);
          Serial.println ("System unlocked");
        }
      }
  
      Serial.println ();
      inputString = "";
    
    }
    else 
    {
      inputString += inputChar;           //make a string of the characters coming on serial
    }
  }
}
