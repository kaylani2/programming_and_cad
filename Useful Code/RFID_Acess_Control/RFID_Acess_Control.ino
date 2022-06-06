/*
   Update: 06/12/2017
   Author: Kaylani Bochie

   To add more authorized tags to the sketch, just change the macro NUMBER_OF_MEMBERS and the memberTags array.
*/

/*
   UID = Unique ID
   Tag = short for Proximity Integrated Circuit Card (RFID Tag itself)
   Based on the DumpInfo example of the MFRC522.h library
*/

/*    OUTPUTS AND CIRCUIT:

   Board used: Arduino Nano


   The output of the DumpByteArray (mfrc522.uid.uidByte, mfrc522.uid.size) gives something like the following on the output:
      95 32 0D AB


   The output of the PICC_DumpToSerial(Uid *uid) method gives something like the following on the output:

    Card UID: 95 32 0D AB
    Card SAK: 08
    Tag type: MIFARE 1KB
    Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits
      15     63   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             62   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             61   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             60   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
      14     59   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             58   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             57   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             56   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
      13     55   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             54   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             53   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             52   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
      12     51   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             50   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             49   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             48   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
      11     47   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             46   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             45   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             44   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
      10     43   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             42   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             41   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             40   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       9     39   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             38   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             37   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             36   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       8     35   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             34   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             33   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             32   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       7     31   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             30   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             29   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             28   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       6     27   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             26   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             25   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             24   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       5     23   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             22   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             21   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             20   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       4     19   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             18   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             17   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             16   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       3     15   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             14   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             13   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
             12   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       2     11   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
             10   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              9   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              8   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       1      7   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              4   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
       0      3   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
              2   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              1   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              0   95 32 0D AB  01 08 04 00  62 63 64 65  66 67 68 69  [ 0 0 0 ]



   The output of the PICC_DumpDetailsToSerial(Uid *uid) method gives something like the following on the output:

    Card UID: 95 32 0D AB
    Card SAK: 08
    Tag type: MIFARE 1KB



  Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/


#include <SPI.h>
#include <MFRC522.h>
/* The MFRC52 can be added with the Manage Libraries option on the Arduino IDE */

#define OK                                    0
#define NO_RFID_TAG_PRESENT_ERROR             1
#define RFID_TAG_READING_ERROR                2
#define DIFFERENT_BYTE_ARRAYS                 3


#define RESET_PIN                             9
#define SLAVE_SELECT_PIN                      10

#define TAG_UID_LENGTH                        4
#define INDICATOR_LED                         3
#define NUMBER_OF_MEMBERS                     3

MFRC522 mfrc522 (SLAVE_SELECT_PIN, RESET_PIN);
// This object will hold the ID that will be used to access or block the system
// Only one needed

byte memberTags [NUMBER_OF_MEMBERS][TAG_UID_LENGTH] =
{
  {0x95, 0x32, 0x0D, 0xAB},
  {0xEE, 0x86, 0x4E, 0xAE},
  {0x36, 0x04, 0x7D, 0x63}
};



int DumpByteArray (byte *byteArray, byte bufferSize)
{
  for (unsigned char index = 0; index < bufferSize; index++)
  {
    Serial.print (byteArray [index] < 0x10 ? " 0" : " ");
    Serial.print (byteArray [index], HEX);

    //    Serial.print (byteArray [index], HEX);
  }
  Serial.println ();

  return OK;
}

int CheckByteArrays (byte *firstByteArray, byte *secondByteArray, unsigned char byteArrayLength)
{
  for (unsigned char index = 0; index < byteArrayLength; index++)
  {
    if (firstByteArray [index] != secondByteArray [index])
      return DIFFERENT_BYTE_ARRAYS;
  }

  return OK;
}

int RfidScan ()
{
  if (!mfrc522.PICC_IsNewCardPresent ())
  {
    //    Serial.println ("Waiting");
    return NO_RFID_TAG_PRESENT_ERROR;
  }

  if (!mfrc522.PICC_ReadCardSerial ())
    return RFID_TAG_READING_ERROR;

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  //mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));
  DumpByteArray (mfrc522.uid.uidByte, mfrc522.uid.size);

  return OK;
}

void setup ()
{
  Serial.begin (9600);
  pinMode (INDICATOR_LED, OUTPUT);
  digitalWrite (INDICATOR_LED, HIGH); //active low
  SPI.begin ();
  mfrc522.PCD_Init ();
  Serial.println ("Ready to scan RFID tags and cards.");
}

void loop()
{
  boolean accessGranted = false;
  unsigned char index = 0;
  if (RfidScan () == OK)
  {
    while ( (index < NUMBER_OF_MEMBERS) && (accessGranted == false) )
      if (CheckByteArrays (mfrc522.uid.uidByte, memberTags [index],  TAG_UID_LENGTH) == OK)
        accessGranted = true;
      else
        index++;
    if (accessGranted == true)
    {
      Serial.println ("Access granted");
      digitalWrite (INDICATOR_LED, LOW);
      mfrc522.uid.uidByte [0] = 0xFF;
      // /\ Resets the object ID
    }
    else
    {
      Serial.println ("Access denied");
      digitalWrite (INDICATOR_LED, HIGH);
    }
  }
}
