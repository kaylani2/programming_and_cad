/*
 * Author: Kaylani Bochie
 * email: kaylani2@hotmail.com
 * 
 * 
 * GARAGE HACKING
*/


#define OK                      0

#define PRESSED_TIME            200     /*ms*/
#define relay1                  3
#define relay2                  4
#define relay3                  5
#define relay4                  6
#define relay5                  7
#define relay6                  8
#define relay7                  9
#define relay8                  10
#define relayMain               11    /* this relay will act as the switch to test the code */


int control (int pin , int state) 
{
  if (state == 1)
    digitalWrite(pin , HIGH);
  else
    digitalWrite(pin , LOW);

  return OK;
}

void setup() 
{
  pinMode (relay1 , OUTPUT);
  pinMode (relay2 , OUTPUT);
  pinMode (relay3 , OUTPUT);
  pinMode (relay4 , OUTPUT);
  pinMode (relay5 , OUTPUT);
  pinMode (relay6 , OUTPUT);
  pinMode (relay7 , OUTPUT);
  pinMode (relay8 , OUTPUT);
  pinMode (relayMain , OUTPUT);
  digitalWrite (relay1, LOW); 
  digitalWrite (relay2, LOW); 
  digitalWrite (relay3, LOW); 
  digitalWrite (relay4, LOW); 
  digitalWrite (relay5, LOW); 
  digitalWrite (relay6, LOW); 
  digitalWrite (relay7, LOW); 
  digitalWrite (relay8, LOW); 
  digitalWrite (relayMain, LOW); 
}

void loop()
{
  for (int index1 = 0; index1 < 2; index1++)
    for (int index2 = 0; index2 < 2; index2++)
      for (int index3 = 0; index3 < 2; index3++)
        for (int index4 = 0; index4 < 2; index4++)
          for (int index5 = 0; index5 < 2; index5++)
            for (int index6 = 0; index6 < 2; index6++)
              for (int index7 = 0; index7 < 2; index7++)
                for (int index8 = 0; index8 < 2; index8++) 
                {  
                  control (relay1 , index1);
                  control (relay2 , index2);
                  control (relay3 , index3);
                  control (relay4 , index4);
                  control (relay5 , index5);
                  control (relay6 , index6);
                  control (relay7 , index7);
                  control (relay8 , index8);
                  digitalWrite (relayMain , HIGH);
                  delay (PRESSED_TIME);
                  digitalWrite (relayMain , LOW);
                }
}
