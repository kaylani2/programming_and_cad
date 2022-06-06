/*


   CAN BE USED WITH PROCESSING, JUST LOOK AT THE PROCESSING SKETCH AT THE END
   MUST SEND ONLY A SINGLE SERIAL.PRINTLN(DISTANCE) AND WORK WITH THAT NUMBER (MUST BE A NUMBER)



   HC-SR04 Demo
   Demonstration of the HC-SR04 Ultrasonic Sensor
   Date: August 3, 2016

   Description:
    Connect the ultrasonic sensor to the Arduino as per the
    hardware connections below. Run the sketch and open a serial
    monitor. The distance read from the sensor will be displayed
    in centimeters and inches.

   Hardware Connections:
    Arduino | HC-SR04
    -------------------
      5V    |   VCC
      7     |   Trig
      8     |   Echo
      GND   |   GND

   License:
    Public Domain
*/

// Pins
#define TRIGGER_PIN 7
#define ECHO_PIN 8
#define MAXIMUM_DISTANCE 23200

// Anything over 400 cm (23200 us pulse) is "out of range"

void setup() {

  // The Trigger pin will tell the sensor to range find
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);

  // We'll use the serial monitor to view the sensor output
  Serial.begin(9600);
}

void loop() {

  unsigned long upTime;           //this will hold the time when the echo pin goes to high (positive edge detection)
  unsigned long downTime;         //this will hold the time when the echo pin goes to low  (negative edge detection)
  unsigned long pulseWidth;
  float cm;
  float inches;

  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 ) {
  }
  /*

    micros() gets reseted after 70 minutes = 4.200.000.000 microseconds
        the range of the HC - SR04 is up to 4 meters
        assuming sound travels at 340m / s on air
        the pulse width of the echo pin could get to 23.200 microseconds
        so we check to see if the values will not be measured during the reset time of the micros() function
  */
  unsigned long testTime = micros();
  if (testTime >= 4199976800) {
    delay(1000);
  }


  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  upTime = micros();
  while ( digitalRead(ECHO_PIN) == 1) {
  }
  downTime = micros();
  pulseWidth = downTime - upTime;

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed
  // off sound in air at sea level (~340 m/s).
  cm = pulseWidth / 58.0;
  inches = pulseWidth / 148.0;

  // Print out results
  if ( pulseWidth > MAXIMUM_DISTANCE ) {
    //Serial.println("Out of range");
  } else {
    Serial.println(cm);
    //Serial.print(" cm \t");
    //Serial.print(inches);
    //Serial.println(" in");
  }

  // Wait at least 60ms before next measurement
  delay(60);
}

/*
  import processing.serial.*;
  Serial myPort;
  float control = 0;
  float xmag, ymag = 0;
  float newXmag, newYmag = 0;



  void setup () {
  size(1280, 720, P3D);
  myPort = new Serial(this, "COM4", 9600);
  myPort.bufferUntil('\n');
  noStroke();
  colorMode(RGB, 1);
  }

  //void draw () {
  //  background(120, control/(control + control) , control);
  //}
  void draw()  {
  background(0.5);

  pushMatrix();
  translate(width / 2, height / 2, -30);

  newXmag = (control * 10) / float(width) * TWO_PI;
  newYmag = mouseY / float(height) * TWO_PI;

  float diff = xmag - newXmag;
  if (abs(diff) >  0.01) {
    xmag -= diff / 4.0;
  }

  diff = ymag - newYmag;
  if (abs(diff) >  0.01) {
    ymag -= diff / 4.0;
  }

  rotateX(-ymag);
  rotateY(-xmag);

  scale(90);
  beginShape(QUADS);

  fill(0, 1, 1); vertex(-1,  1,  1);
  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(1, 0, 1); vertex( 1, -1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);

  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);
  fill(1, 0, 1); vertex( 1, -1,  1);

  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(0, 0, 0); vertex(-1, -1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);

  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(0, 1, 1); vertex(-1,  1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);
  fill(0, 0, 0); vertex(-1, -1, -1);

  fill(0, 1, 0); vertex(-1,  1, -1);
  fill(1, 1, 0); vertex( 1,  1, -1);
  fill(1, 1, 1); vertex( 1,  1,  1);
  fill(0, 1, 1); vertex(-1,  1,  1);

  fill(0, 0, 0); vertex(-1, -1, -1);
  fill(1, 0, 0); vertex( 1, -1, -1);
  fill(1, 0, 1); vertex( 1, -1,  1);
  fill(0, 0, 1); vertex(-1, -1,  1);

  endShape();

  popMatrix();
  }
  void serialEvent (Serial myPort) {
  control = float(myPort.readStringUntil('\n'));
  }

  /
