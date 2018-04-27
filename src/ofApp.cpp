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
    Keyboard piano_keyboard;
    for (ofSoundPlayer key_sound: key_sounds) {
        PianoKey piano_key(key_sound);
        piano_keyboard.getPianoKeys().push_back(piano_key);
    }
    
    // Create the 5 different piano keyboard locations/48-key layouts
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
    
    
    
    //    A0.play();
    //    B_flat_0.play();
    //    B_zero.play();
    //    D_flat_0.play();
    //    C0.play();
    //    D_flat_0.play();
    //    D0.play();
    //    E_flat_0.play();
    //    E0.play();
    //    F0.play();
    //    G_flat_0.play();
    //    G0.play();
    //    A_flat_0.play();
    
    

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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

