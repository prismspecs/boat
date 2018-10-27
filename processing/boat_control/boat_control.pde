import controlP5.*;
ControlP5 cp5;
int servoSlider=0;


import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;

void setup() {

  size(400, 400);

  oscP5 = new OscP5(this, 12345);
  myRemoteLocation = new NetAddress("132.162.75.186", 12345);


  cp5 = new ControlP5(this);

  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("servoSlider")
    .setPosition(30, 30)
    .setRange(0, 180)
    ;
}

void draw() {
}

void servoSlider(float incoming) {
  OscMessage myMessage = new OscMessage("/boat1/mast");
  myMessage.add(incoming); /* add an int to the osc message */
  oscP5.send(myMessage, myRemoteLocation);
}
