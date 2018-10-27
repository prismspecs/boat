#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup() {

        std::vector<ofx::IO::SerialDeviceInfo> devicesInfo = ofx::IO::SerialDeviceUtils::listDevices();

        ofLogNotice("ofApp::setup") << "Connected Devices: ";

        for (std::size_t i = 0; i < devicesInfo.size(); ++i)
        {
                ofLogNotice("ofApp::setup") << "\t" << devicesInfo[i];
        }

        if (!devicesInfo.empty())
        {
                // Connect to the first matching device.
                bool success = device.setup(devicesInfo[0], 115200);

                if(success)
                {
                        ofLogNotice("ofApp::setup") << "Successfully setup " << devicesInfo[0];
                }
                else
                {
                        ofLogNotice("ofApp::setup") << "Unable to setup " << devicesInfo[0];
                }
        }
        else
        {
                ofLogNotice("ofApp::setup") << "No devices connected.";
        }

        // OSC
        oscReceiver.setup(PORT);
        std::cout << "listening for osc messages on port " << PORT << "\n";

        // video
        vidPlayer.load("testvid.mp4");
    	vidPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update() {

	// OSC
	while (oscReceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscReceiver.getNextMessage(&m);

		std::cout << "OSC message received, address: " << m.getAddress() << "\n";

		if(m.getAddress() == "/boat1/mast") {

			std::string text = ofToString(m.getArgAsInt(0));
	        ofx::IO::ByteBuffer textBuffer(text);
	        device.writeBytes(textBuffer);
	        device.writeByte('\n');

	        std::cout << "OSC integer value: " << text << "\n";
		}
	}

        // The serial device can throw exeptions.
    try
    {
        // Read all bytes from the device;
        // uint8_t buffer[1024];
        //
        // while (device.available() > 0)
        // {
        //     std::size_t sz = device.readBytes(buffer, 1024);
        //
        //     for (std::size_t i = 0; i < sz; ++i)
        //     {
        //         std::cout << buffer[i];
        //     }
        // }

        // Send some new bytes to the device to have them echo'd back.
        // std::string text = ofToString(ofRandom(180));

        // ofx::IO::ByteBuffer textBuffer(text);

        // device.writeBytes(textBuffer);
        // device.writeByte('\n');

        // ofSleepMillis(5000);
    }
    catch (const std::exception& exc)
    {
        ofLogError("ofApp::update") << exc.what();
    }

    // video
    vidPlayer.update();

}

//--------------------------------------------------------------
void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	vidPlayer.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
