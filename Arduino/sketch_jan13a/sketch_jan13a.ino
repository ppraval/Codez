#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN = 8;
int RELAY_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode (RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode())
    {
     Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
     irrecv.resume();
     if (irrecv.decodedIRData.decodedRawData == 0x1FFC00 || irrecv.decodedIRData.decodedRawData == 0xED127F80)
     {
        digitalWrite (RELAY_PIN, LOW);
        delay(15000);
        digitalWrite(RELAY_PIN, HIGH);
     }
  }
}