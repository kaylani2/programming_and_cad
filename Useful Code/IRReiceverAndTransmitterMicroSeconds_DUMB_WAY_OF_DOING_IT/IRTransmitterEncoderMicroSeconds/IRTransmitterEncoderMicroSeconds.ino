/*
 * Instructions: (Kaylani)
 * 
 * The output doesn't work with PWM pins. I don't know why.
 * 
 * This code should work with any protocol because it doesn't rely on any libraries and uses the timing of the IR pulses.
 * 
 * Tested with the NecX protocol.
 * 
 * 
 * The circuit for the transmitter is the following:
 *
 * Arduino Digital Pin 13 -> one terminal of a 470 ohm resistor
 * The other terminal of the 470 ohm -> Base of a 2222 npn transistor
 * Arduino Ground -> Emitter of the 2222 npn transistor
 * Arduino Vcc -> Anode of the IR Led
 * Cathode of the IR Led -> Colector of the 2222 npn transistor
 *
 * 
 */

/*
 * See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
 */


#define OK                                              0
#define IRledPin                                        13

/*
 * This procedure sends a 38KHz pulse to the IRledPin
 * for a certain # of microseconds. We'll use this whenever we need to send codes
 */
int PulseIR (long microSeconds)
{
  // we'll count down from the number of microseconds we are told to wait
  cli();  // this turns off any background interrupts
  while (microSeconds> 0)
  {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite (IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds (10);         // hang out for 10 microseconds
    digitalWrite (IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds (10);         // hang out for 10 microseconds
    // so 26 microseconds altogether
    microSeconds -= 26;
  }

  sei();  // this turns them back on
  return OK;
}

int SendChannelCode () 
{
  /* Paste here the output of the IRReceiverDecoderMicroSeconds sketch */


  return OK;
}

void setup ()
{
  Serial.begin (9600);
  pinMode (IRledPin, OUTPUT);
}

void loop ()
{
  Serial.println ("Sending IR signal");
  SendChannelCode ();
  Serial.println ("Waiting 3 seconds");
  delay (3000);
}


