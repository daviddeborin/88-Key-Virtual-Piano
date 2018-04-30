#include "ofApp.h"
#include "keyboard.hpp"
#include <vector>
#include <string>

//--------------------------------------------------------------
void ofApp::setup() {
    location_layout = 3; // Default (center) layout
    
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

//    // Create a piano keyboard with 88 keys
//    for (ofSoundPlayer key_sound: key_sounds) {
//        PianoKey piano_key = (key_sound, shape, image);
//        piano_keyboard.piano_keys.push_back(piano_key);
//    }
    
    createKeyboardLocations();

    computer_keys = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
    establishComputerKeys(computer_keys);

    piano_image.load("/Users/daviddeborin/Desktop/C++ OpenFrameworks/of_v0.9.8_osx_release/apps/myApps/final-project-daviddeborin/Usable Pictures/1297658541.jpg");
    
}

//--------------------------------------------------------------
void ofApp::createKeyboard() {
    ofRectangle white_key_rectangle;
    ofColor white;
    white.set(255, 255, 255);
    ofSetColor(white);
    
    ofRectangle black_key_rectangle;
    ofColor black;
    black.set(0, 0, 0);
    ofSetColor(black);
    
    PianoKey piano_key_1 = {key_sounds[0], white_key_rectangle, white};
    PianoKey piano_key_2 = {key_sounds[1], black_key_rectangle, black};
    PianoKey piano_key_3 = {key_sounds[2], white_key_rectangle, white};

    piano_keyboard.piano_keys.push_back(piano_key_1);
    piano_keyboard.piano_keys.push_back(piano_key_2);
    piano_keyboard.piano_keys.push_back(piano_key_3);
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 12; j++) {
            PianoKey piano_key;
            if (j <= 4) {
                if (j % 2 == 0) {
                    // intialize black key
                    piano_key = {key_sounds[i * 12 + j + 3], black_key_rectangle, black};
                } else {
                    // initialize white key
                    piano_key = {key_sounds[i * 12 + j + 3], white_key_rectangle, white};
                }
            } else {
                if (j % 2 == 0) {
                    // initialize with white key
                    piano_key = {key_sounds[i * 12 + j + 3], white_key_rectangle, white};
                } else {
                    // initialize with black key
                    piano_key = {key_sounds[i * 12 + j + 3], black_key_rectangle, black};
                }
            }
        }
    }
    
    PianoKey piano_key_88 = {key_sounds[87], white_key_rectangle, white};
    piano_keyboard.piano_keys.push_back(piano_key_88);
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

// Called every frame (60 fps means it calls draw() 60 times a second)
void ofApp::draw() {
//    piano_image.draw(100, 100);
//    ofSetColor(100, 46, 200);

    ofColor ball_color;
    ball_color.r = 255;
    ball_color.g = 255;
    ball_color.b = 255;
    ofSetColor(ball_color);
    ofRectangle rectangle;
    rectangle.set(500, 500, 10, 80);
    ofDrawRectangle(rectangle);
}

//--------------------------------------------------------------
void ofApp::createKeyboardLocations() {
    for (int i = 0; i < 88; i++) {
        PianoKey a_key = piano_keyboard.piano_keys[i];
        
        if (i <= 47) {
            piano_keyboard.location1.push_back(a_key);
        }
        if (i >= 8 && i <= 55) {
            piano_keyboard.location2.push_back(a_key);
        }
        if (i >= 20 && i <= 67) {
            piano_keyboard.location3.push_back(a_key);
        }
        if (i >= 32 && i <= 79) {
            piano_keyboard.location4.push_back(a_key);
        }
        if (i >= 40 && i <= 87) {
            piano_keyboard.location5.push_back(a_key);
        }
    }
}

//--------------------------------------------------------------
void ofApp::establishComputerKeys(const std::string &computer_keys) {
    all_computer_keys = std::vector<int>(computer_keys.begin(), computer_keys.end());
}

//--------------------------------------------------------------
std::vector<PianoKey> ofApp::getCurrentPianoLayout() {
    switch (location_layout) {
        case 1:
            return piano_keyboard.location1;
        case 2:
            return piano_keyboard.location2;
        case 3:
            return piano_keyboard.location3;
        case 4:
            return piano_keyboard.location4;
        case 5:
            return piano_keyboard.location5;
        default:
            return piano_keyboard.location3;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RIGHT && location_layout < 5) {
        location_layout++;
        // highlight new location layout
        return;
    } else if (key == OF_KEY_LEFT && location_layout > 0) {
        location_layout--;
        // highlight new location layout
        return;
    } else {
        std::vector<PianoKey> current_layout_of_piano = getCurrentPianoLayout();
        for (int i = 0; i < all_computer_keys.size(); i++) {
            if (key == all_computer_keys[i]) {
                current_layout_of_piano[i].key_sound.play();
                // Draw()/light up the key as well
                return;
            }
        }
    }
    // Wrong key was pressed
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

std::vector<ofSoundPlayer> &ofApp::getKeySounds() {
    return key_sounds;
}

