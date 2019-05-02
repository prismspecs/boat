// necessary to control servo motor(s)
#include <Servo.h>

// servo object, could create an array if you need multiple
Servo servo1;

void setup()
{
	// initiate serial comms w host computer
	// be sure both of the baud rates match
  Serial.begin(115200);

	// tell arduino which pin the servo is on
  servo1.attach(8);
}


void loop()
{
	// if there is any new data coming in on serial...
  while (Serial.available() > 0)
  {

    // currently i'm using a carriage return
    // after sending data, so check for that
    // before proceeding

    // read the first integer
    String incString = Serial.readStringUntil(10);
    int incoming = incString.toInt();

		// write the angle change to the servo and echo the value
		// so the host program can be sure all is well
    servo1.write(incoming);
    Serial.write(incoming);
  }
  
  delay(10);
}

