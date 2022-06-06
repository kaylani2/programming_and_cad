#include <boarddefs.h>
#include <IRremote.h>

/*
 * Coded by Kaylani Bochie based on the IRRemote example
 * The button codes are from my led pannel controller
 * The codes were obtained from the 1838 IR Receiver
 * Pin1 - Signal Out
 * Pin2 - Ground
 * Pin3 - Vcc (5V)
 * Pins defined when the receiver is facing towards you and the pins are numbered from left to right

 *The buttons thirty trough hundred will be used to toggle the digital outputs from 3 trough 10, respectively
 *The +SPEED and -SPEED will be used to control the PWM signal of the 11 digital output in 10 equal steps
 *
 *This code should be used as a template for other IR based automation projects


 *ON  -> 16580863
 *10% -> 16589023
 *20% -> 16621663
 *30% -> 16605343
 *40% -> 16584943
 *50% -> 16617583
 *60% -> 16601263
 *70% -> 16593103
 *80% -> 16625743
 *90% -> 16609423
 *100% -> 16597183
 *FLASH -> 16582903
 *+SPEED -> 16615543
 *-SPEED ->  16599223
*/

const int receiverPin = 2;

IRrecv irrecv(receiverPin);
decode_results results;

void setup ()
{
  Serial.begin (9600);
  irrecv.enableIRIn (); // Starts the receiver
}

void loop () {
  if (irrecv.decode (&results))            //MAKES SURE THE RECEIVER IS RECEIVING A IR SIGNAL
  {
    Serial.println ("Readings: ");
    Serial.print ("Hex: ");
    Serial.println (results.value, HEX);
    Serial.print ("Decimal: ");
    Serial.println (results.value, DEC);
    Serial.print ("Binary: ");
    Serial.println (results.value, BIN);
    Serial.println ();
    Serial.println ();
    irrecv.resume (); // Receives the next value
  }
}
