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
    int incoming = Serial.parseInt();

    // currently i'm using a carriage return
    // after sending data, so check for that
    // before proceeding
    if (Serial.read() == '\n') {

      servo1.write(incoming);

      Serial.write(incoming);

    }
  }

  delay(10);
}
