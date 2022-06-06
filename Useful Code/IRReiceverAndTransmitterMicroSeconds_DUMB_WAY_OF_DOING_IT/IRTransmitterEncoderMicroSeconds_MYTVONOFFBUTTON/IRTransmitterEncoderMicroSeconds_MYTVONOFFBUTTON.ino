// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!

int IRledPin = 13;    // LED connected to digital pin 13

// The setup() method runs once, when the sketch starts

void setup()   {
  // initialize the IR digital pin as an output:
  pinMode (IRledPin, OUTPUT);
  pinMode (LED_BUILTIN, output);
  digitalWrite (LED_BUILTIN, LOW);


  Serial.begin (9600);
}

void loop()
{
  Serial.println ("Sending IR signal");
  digitalWrite (LED_BUILTIN, !digitalWrite (LED_BUILTIN));


  SendChannelCode ();

  delay (3000);  // wait twenty seconds (20 seconds * 1000 milliseconds)
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR (long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
  }

  sei();  // this turns them back on
}

void SendChannelCode() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST


  /*
    delayMicroseconds(); //Time off (Left Column on serial monitor)
    pulseIR();           //Time on  (Right Column on serial monitor)
  */
  delayMicroseconds (35084);
  pulseIR (4860);
  delayMicroseconds (4420);
  pulseIR (760);
  delayMicroseconds (1540);
  pulseIR (740);
  delayMicroseconds (1580);
  pulseIR (680);
  delayMicroseconds (1620);
  pulseIR (660);
  delayMicroseconds (500);
  pulseIR (640);
  delayMicroseconds (520);
  pulseIR (620);
  delayMicroseconds (520);
  pulseIR (620);
  delayMicroseconds (540);
  pulseIR (600);
  delayMicroseconds (560);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (560);
  delayMicroseconds (600);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (1740);
  pulseIR (560);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1740);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (48140);
  pulseIR (4660);
  delayMicroseconds (4640);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (560);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (580);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (560);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1740);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (560);
  delayMicroseconds (1740);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (580);
  delayMicroseconds (1720);
  pulseIR (560);
}

