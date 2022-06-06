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

#include <ESP8266WiFi.h>

#define NETWORK_SSID                             "GVT-9209"
#define NETWORK_PASSWORD                         "5067014388"

int ledPin = BUILT_IN_LED;
int firstOutput = D1;
int secondOutput = D2;

WiFiServer server(80);

int FazerConexaoWifiInicializarServidor (const char *networkSSID, const char *networkPassword)
{  
  Serial.println ();
  Serial.print ("Connecting to ");
  Serial.println (networkSSID);
  Serial.println ();
  delay (500);

  WiFi.begin (networkSSID, networkPassword);

  while (WiFi.status() != WL_CONNECTED) {
    delay (500);
    Serial.print (".");
  }
  Serial.println ("");
  Serial.println ("WiFi connected");

  // Start the server
  server.begin ();
  Serial.println ("Server started");

  // Print the IP address
  Serial.print ("MAC Adress: ");
  Serial.println (WiFi.macAddress ());
  Serial.print ("Use this URL to connect: ");
  Serial.print ("http://");
  Serial.print (WiFi.localIP ());
  Serial.println ("/");

  delay (500);
  return OK;
}

void setup() {
  Serial.begin (9600);  

  pinMode (ledPin, OUTPUT);
  digitalWrite (ledPin, LOW);

/*
  pinMode (firstOutput, OUTPUT);
  pinMode (secondOutput, OUTPUT);
  digitalWrite (firstOutput, LOW);
  digitalWrite (secondOutput, LOW);
*/

  // Connect to WiFi network
  FazerConexaoWifiInicializarServidor (NETWORK_SSID, NETWORK_PASSWORD);
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available ();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil ('\r');
  Serial.println (request);
  client.flush ();

  // Match the request

  int value = LOW;
  if (request.indexOf ("/LED=ON") != -1)  {
    digitalWrite (ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf ("/LED=OFF") != -1)  {
    digitalWrite (ledPin, LOW);
    value = LOW;
  }

/*
  if (request.indexOf ("/firstOutput=ON") != -1)  {
    digitalWrite (firstOutput, HIGH);
  }

  if (request.indexOf ("/firstOutput=OFF") != -1)  {
    digitalWrite (firstOutput, LOW);
  }


  if (request.indexOf ("/secondOutput=ON") != -1)  {
    digitalWrite (secondOutput, HIGH);
  }

  if (request.indexOf ("/secondOutput=OFF") != -1)  {
    digitalWrite (secondOutput, LOW);
  }
*/
  
  // Return the response
  client.println ("HTTP/1.1 200 OK");
  client.println ("Content-Type: text/html");
  client.println (""); //  do not forget this one
  client.println ("<!DOCTYPE HTML>");
  client.println ("<html>");






  client.print ("Led pin is now: ");
  if (value == HIGH)
    client.print ("On");
  else
    client.print ("Off");
  



  client.println ("<br><br>");
  client.println ("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println ("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");


/*
  client.println ("<br><br>");
  client.println ("First Output: ");
  client.println ("<a href=\"/firstOutput=ON\"\"><button>Turn On </button></a>");
  client.println ("<a href=\"/firstOutput=OFF\"\"><button>Turn Off </button></a><br />");

  client.println ("<br><br>");
  client.println ("Second Output: ");
  client.println ("<a href=\"/secondOutput=ON\"\"><button>Turn On </button></a>");
  client.println ("<a href=\"/secondOutput=OFF\"\"><button>Turn Off </button></a><br />");
*/







  client.println ("</html>");
  delay (1);
  Serial.println ("Client disonnected");
  Serial.println ("");
}

