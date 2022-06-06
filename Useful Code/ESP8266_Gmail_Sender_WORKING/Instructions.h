/*

  We are going to use SMTP to send messages.

  Using SMTP Authentication we provide only email and password,

  by default Google uses more complex verification methods so we need to change settings.

  Go to your Google account settings and enable "Allow less secure apps" at the bottom of the page.

  This mean apps only need your email and password when login to your gmail account.

  If you concerned about security, just use different account.


  I wrote a little sketch which send one test message to check if all works as should.

  When all software downloaded and installed:

  Unzip ESP8266_Gmail_Sender.zip
  Find and open ESP8266_Gmail_Sender.ino
  Set your wifi access point name (SSID) and password. Should be like this:
  const char* ssid = "MyWiFi";
  const char* password = "12345678";
  In setup() function find
  if(gsender->Subject(subject)->Send("boris.on@live.com", "Setup test"))
  first parameter of Send function is recipient email, second message text.

  Change recipient from <boris.on@live.com> to your email which will receive message.

  Subject function is optional! Subject sets once and stored until you change it.

  You can send mails without subject or if it already set

  gsender->Send(to, message);
  Now open Gsender.h tab
  We need Base64 encoded email address and password of gmail account which will be used to send emails.
  You can use base64encode.org for encoding, result must be something like:

  const char* EMAILBASE64_LOGIN = "Y29zbWkxMTExMUBnbWFpbC5jb20=";
  const char* EMAILBASE64_PASSWORD = "TGFzZGFzZDEyMzI=";
  Now set FROM field.
  const char* FROM = "your_email@gmail.com";
  That`s all for this part.

*/
