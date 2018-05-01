#include "ofApp.h"
#include "keyboard.hpp"
#include <vector>
#include <string>

//--------------------------------------------------------------
void ofApp::setup() {
    location_layout = 3; // Default (center) layout
    
    // create 88 sound objects
    for (int i = 0; i < Keyboard::NUM_OF_KEYS; i++) {
        ofSoundPlayer key_sound_i;
        key_sounds.push_back(key_sound_i);
    }
    
    // Load the 88 sound objects
    for (int i = 0; i < Keyboard::NUM_OF_KEYS; i++) {
        auto key_number = std::to_string(i + 1);
        key_sounds[i].load("/Users/daviddeborin/Desktop/C++ OpenFrameworks/of_v0.9.8_osx_release/apps/myApps/final-project-daviddeborin/Piano Sounds/All 88 Key Sounds \(mp3)/" + key_number + ".mp3");
    }
    
    createKeyboard();
    createKeyboardLocations();
    establishComputerKeys(computer_keys);
    getCurrentPianoLayout();
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
            int index_on_keyboard = (i * 12) + j + 3;
            PianoKey piano_key;
            
            if (j <= 4) {
                if (j % 2 == 0) {
                    // intialize white key
                    piano_key = {key_sounds[index_on_keyboard], white_key_rectangle, white};
                    piano_keyboard.piano_keys.push_back(piano_key);
                } else {
                    // initialize black key
                    piano_key = {key_sounds[index_on_keyboard], black_key_rectangle, black};
                    piano_keyboard.piano_keys.push_back(piano_key);
                }
            } else {
                if (j % 2 == 0) {
                    // initialize with black key
                    piano_key = {key_sounds[index_on_keyboard], black_key_rectangle, black};
                    piano_keyboard.piano_keys.push_back(piano_key);
                } else {
                    // initialize with white key
                    piano_key = {key_sounds[index_on_keyboard], white_key_rectangle, white};
                    piano_keyboard.piano_keys.push_back(piano_key);
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
    ofColor white;
    ofColor black;
    white.set(255, 255, 255);
    black.set(0, 0, 0);
    
    // Exact dimensions of white keys
    int white_key_bottom_radius = 4;
    float white_height_to_width_ratio = 5.39;
    
    float initial_white_key_width = ((float) x_size_of_window / Keyboard::NUM_WHITE_KEYS);
    float buffer_space = (x_size_of_window / Keyboard::NUM_WHITE_KEYS) * 0.01;
    float initial_buffer = (x_size_of_window * 0.01) / 2.0;
    
    float white_key_width = initial_white_key_width - buffer_space;
    float white_key_height = (white_key_width * white_height_to_width_ratio) + white_key_bottom_radius;
    float y_coordinate_of_piano = ((y_size_of_window / 2) - (white_key_height / 2));
    
    // Try casting as ints and see how it looks like without the noFill()
    int white_keys_count = 0;
    for (int i = 0; i < Keyboard::NUM_OF_KEYS; i++) {
        if (piano_keyboard.piano_keys[i].key_color == white) {
            
            ofRectangle key_shape = piano_keyboard.piano_keys[i].key_shape;
            key_shape.set(initial_buffer + (white_key_width * white_keys_count), y_coordinate_of_piano, white_key_width, white_key_height);
            ofSetColor(white);
            ofFill();
            ofDrawRectRounded(key_shape, 0, 0, white_key_bottom_radius, white_key_bottom_radius);
            
            ofRectangle outlined_rectangle;
            ofSetColor(black);
            outlined_rectangle.set(initial_buffer + (white_key_width * white_keys_count), y_coordinate_of_piano, white_key_width, white_key_height);
            ofNoFill();
            ofDrawRectRounded(outlined_rectangle, 0, 0, white_key_bottom_radius, white_key_bottom_radius);
            
            white_keys_count++;
        }
    }
    
    // Exact dimensions of black keys
    float white_key_unit_width = 840.0;
    float black_key_unit_width = 490.0;
    float black_to_white_width_ratio = black_key_unit_width / white_key_unit_width; // roughly 0.583
    float black_height_to_width_ratio = 5.84;
    float black_key_width = white_key_width * black_to_white_width_ratio;
    float black_key_height = black_key_width * black_height_to_width_ratio;

    float key_1 = (525 / white_key_unit_width) * white_key_width; // C
    float key_2 = (black_key_unit_width / white_key_unit_width) * white_key_width; // D_FLAT
    float key_3 = (455 / white_key_unit_width) * white_key_width; // F
    
    float first_a = (735 / white_key_unit_width) * white_key_width;
    ofRectangle key_shape = piano_keyboard.piano_keys[1].key_shape;
    key_shape.set(first_a, y_coordinate_of_piano, black_key_width, black_key_height);
    ofSetColor(black);
    ofFill();
    ofDrawRectangle(key_shape);
    
    float x_coordinate = initial_buffer + (white_key_width * 2);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 12; j++) {
            int index_on_keyboard = (i * 12) + j + 3;

            if (j == 0 || j == 4) {
                if (piano_keyboard.piano_keys[index_on_keyboard].key_color == black) {
                    ofRectangle key_shape = piano_keyboard.piano_keys[index_on_keyboard].key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(black);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += key_1;
                } else {
                    x_coordinate += key_1;
                }
            } else if (j == 1 || j == 2 || j == 3) {
                if (piano_keyboard.piano_keys[index_on_keyboard].key_color == black) {
                    ofRectangle key_shape = piano_keyboard.piano_keys[index_on_keyboard].key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(black);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += key_2;
                } else {
                    x_coordinate += key_2;
                }
            } else if (j == 5 || j == 11) {
                if (piano_keyboard.piano_keys[index_on_keyboard].key_color == black) {
                    ofRectangle key_shape = piano_keyboard.piano_keys[index_on_keyboard].key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(black);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += key_3;
                } else {
                    x_coordinate += key_3;
                }
            } else {
                if (piano_keyboard.piano_keys[index_on_keyboard].key_color == black) {
                    ofRectangle key_shape = piano_keyboard.piano_keys[index_on_keyboard].key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(black);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += key_2;
                } else {
                    x_coordinate += key_2;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::createKeyboardLocations() {
    for (int i = 0; i < Keyboard::NUM_OF_KEYS; i++) {
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

