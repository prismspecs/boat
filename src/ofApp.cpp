#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup() {

  wiringPiSetup();

  // wiringPi thinks of GPIO2 as pin 8 for some reason
  // map: http://wiringpi.com/wp-content/uploads/2013/03/gpio1.png
  pinMode(8, OUTPUT); // led
  pinMode(9, INPUT);  // button

  // wiringPi thinks of GPIO18 as pin 1 for some reason
  pinMode(1, OUTPUT); // softwarepwm controlled servo
  digitalWrite(1, LOW);
  softPwmCreate(1, 15, 200);

  // servo-hat controlled servo
	servo.SetLeftUs(700);
	servo.SetRightUs(2400);
	servo.Dump();
  servo.SetAngle(CHANNEL(0), ANGLE(90));

}

//--------------------------------------------------------------
void ofApp::update() {

  // servo 1.5ms is middle (15 as int)
  // .5ms to 2.5ms
  // ofMap(inRot, 0, 180, 5, 25);

  // for (int i = 0; i < 180; i++) {
  //   softPwmWrite(1, (int)ofMap(i, 0, 180, 5, 25));
  //   ofLog() << i;
  //
  //   ofSleepMillis(100);
  // }

  for (int i = 0; i < 180; i++) {
    ofLog() << i;
    //wiringPiI2CWriteReg16 (fd, 0x00, i);
    //pwmWrite(316, (int)ofMap(i, 0, 180, 5, 25));

    servo.SetAngle(CHANNEL(0), ANGLE(i));

    ofSleepMillis(50);
  }

  // digitalWrite(8, HIGH);
  //
  // // gpio_led.setval_gpio("1");
  //
  // ofSleepMillis(1000);
  //
  // digitalWrite(8, LOW);
  //
  // // gpio_led.setval_gpio("0");
  //
  // ofSleepMillis(1000);
  //

  // check on button ... seems like all this should be farmed out to threads
  // button_state = digitalRead(9);
  // ofLog() << button_state;
  // if (button_state == 0) {
  //   softPwmWrite(1, 5);
  // } else {
  //   softPwmWrite(1, 25);
  // }

  // check potentiometer
  // ofLog() << analogRead(7);
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
