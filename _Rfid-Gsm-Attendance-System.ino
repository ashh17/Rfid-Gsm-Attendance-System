#include <SPI.h>
#include <MFRC522.h>
#include<SoftwareSerial.h>
int count = 0;
SoftwareSerial gsm(2,3);
 
#define SS_PIN 10
#define RST_PIN 9
#define sw3 2 //define green LED pin
#define sw4 3 //define red LED
#define BUZZER A4//buzzer pin
#define sw1 4
#define sw2 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

 
void setup() 
{
  
  
  
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("");
  content.toUpperCase();
  if (content.substring(1) == "B4 0E 80 C3") 
  {
    delay(10000);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //replace x by your number
  delay(1000);
  gsm.println("THIS IS AJAY");
  delay(100);
  gsm.println((char)26);
  delay(1000);
  }
   if (content.substring(1) == "24 93 51 43") 
  {
    delay(10000);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //replace x by your number
  delay(1000);
  gsm.println("THIS IS ASHISH");
  delay(100);
  gsm.println((char)26);
  delay(1000);

  }
} 
