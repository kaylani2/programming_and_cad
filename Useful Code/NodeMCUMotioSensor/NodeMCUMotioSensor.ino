/* Defines and includes for the NodeMCU board */
#define D0                                        16
#define D1                                        5
#define D2                                        4
#define D3                                        0
#define D4                                        2
#define D5                                        14
#define D6                                        12
#define D7                                        13
#define D8                                        15
#define D9                                        3
#define D10                                       1
#define BUILT_IN_LED                              D4
#define INDICATOR_LED                             D4
/* ------------------------------------------------------------------------------------*/



void setup() {
  Serial.begin (9600);
  pinMode (D0, INPUT);
  pinMode (BUILT_IN_LED, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  if (digitalRead (D0) == LOW)
    digitalWrite (BUILT_IN_LED, LOW);
  else
    digitalWrite (BUILT_IN_LED, HIGH);

  Serial.print ("Reading: ");
  Serial.println (digitalRead (D0));
  
}
