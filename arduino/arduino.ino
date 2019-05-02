#include <Servo.h>

Servo servo1;

void setup()
{
  Serial.begin(115200);

  servo1.attach(8);
}


void loop()
{
  while (Serial.available() > 0)
  {
    // read the first integer
    String incString = Serial.readStringUntil(10);
    int incoming = incString.toInt();

    servo1.write(incoming);

    Serial.write(incoming);

    // currently i'm using a carriage return
    // after sending data, so check for that
    // before proceeding
  }
  
  delay(10);
}

