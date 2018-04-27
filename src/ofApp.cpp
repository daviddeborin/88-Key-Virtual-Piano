#include "ofApp.h"
#include "keyboard.hpp"
#include "piano_key.hpp"
#include <vector>
#include <string>

//--------------------------------------------------------------
void ofApp::setup() {
    
    // create 88 sound objects
    for (int i = 0; i < 88; i++) {
        ofSoundPlayer key_sound_i;
        key_sounds.push_back(key_sound_i);
    }
    
    // Load the 88 sound objects
    for (int i = 0; i < 88; i++) {
        auto key_number = std::to_string(i + 1);
        key_sounds[i].load("/Users/daviddeborin/Desktop/C++ OpenFrameworks/of_v0.9.8_osx_release/apps/myApps/final-project-daviddeborin/Piano Sounds/All 88 Key Sounds \(mp3)/" + key_number + ".mp3");
    }
    
    // Create a piano keyboard with 88 keys
    for (ofSoundPlayer key_sound: key_sounds) {
        PianoKey piano_key(key_sound);
        piano_keyboard.getPianoKeys().push_back(piano_key);
    }
    
    createKeyboardLocations();

    computer_keys = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
    establishComputerKeys(computer_keys);

    piano_image.load("/Users/daviddeborin/Desktop/C++ OpenFrameworks/of_v0.9.8_osx_release/apps/myApps/final-project-daviddeborin/Usable Pictures/1297658541.jpg");
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

// Called every frame (60 fps means it calls draw() 60 times a second)
void ofApp::draw() {
    piano_image.draw(100, 100);
}

//--------------------------------------------------------------
void ofApp::createKeyboardLocations() {
    for (int i = 0; i < 88; i++) {
        PianoKey a_key = piano_keyboard.getPianoKeys()[i];
        
        if (i <= 47) {
            piano_keyboard.getLocation1().push_back(a_key);
        }
        if (i >= 8 && i <= 55) {
            piano_keyboard.getLocation2().push_back(a_key);
        }
        if (i >= 20 && i <= 67) {
            piano_keyboard.getLocation3().push_back(a_key);
        }
        if (i >= 32 && i <= 79) {
            piano_keyboard.getLocation4().push_back(a_key);
        }
        if (i >= 40 && i <= 87) {
            piano_keyboard.getLocation5().push_back(a_key);
        }
    }
}

void ofApp::establishComputerKeys(string computer_keys) {
    for (int i = 0; i < computer_keys.length(); ++i) {
        all_computer_keys.push_back(computer_keys[i]);
    };
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if(key == 'q') {
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

std::vector<ofSoundPlayer> ofApp::getKeySounds() {
    return key_sounds;
}

