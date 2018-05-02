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
        key_sounds[i].load("Piano Sounds/All 88 Key Sounds Edited \(mp3)/" + key_number + ".mp3");
    }
    
    setColors();
    createKeyboard();
    establishComputerKeys(computer_keys);
    getCurrentPianoLayout();
}

//--------------------------------------------------------------
void ofApp::setColors() {
    white.set(255, 255, 255);
    black.set(0, 0, 0);
    yellow.set(255, 255, 0);
    green.set(0, 255, 0);
    red.set(255, 0, 0);
    magenta.set(255, 0, 255);
    blue.set(0, 0, 255);
    layout_color.set(red);
}

//--------------------------------------------------------------
void ofApp::createKeyboard() {
    ofRectangle white_key_rectangle;
    ofSetColor(white);
    std::string white_key = "wide";
    
    ofRectangle black_key_rectangle;
    ofSetColor(black);
    std::string black_key = "thin";
    
    PianoKey piano_key_1 = {key_sounds[0], white_key_rectangle, white, white_key};
    PianoKey piano_key_2 = {key_sounds[1], black_key_rectangle, black, black_key};
    PianoKey piano_key_3 = {key_sounds[2], white_key_rectangle, white, white_key};

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
                    piano_key = {key_sounds[index_on_keyboard], white_key_rectangle, white, white_key};
                    piano_keyboard.piano_keys.push_back(piano_key);
                } else {
                    // initialize black key
                    piano_key = {key_sounds[index_on_keyboard], black_key_rectangle, black, black_key};
                    piano_keyboard.piano_keys.push_back(piano_key);
                }
            } else {
                if (j % 2 == 0) {
                    // initialize black key
                    piano_key = {key_sounds[index_on_keyboard], black_key_rectangle, black, black_key};
                    piano_keyboard.piano_keys.push_back(piano_key);
                } else {
                    // initialize white key
                    piano_key = {key_sounds[index_on_keyboard], white_key_rectangle, white, white_key};
                    piano_keyboard.piano_keys.push_back(piano_key);
                }
            }
        }
    }
    
    PianoKey piano_key_88 = {key_sounds[87], white_key_rectangle, white, white_key};
    piano_keyboard.piano_keys.push_back(piano_key_88);
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    // Centering the keyboard
    float initial_white_key_width = ((float) x_size_of_window / Keyboard::NUM_WHITE_KEYS);
    float buffer_space = (x_size_of_window / Keyboard::NUM_WHITE_KEYS) * 0.01;
    float initial_buffer = (x_size_of_window * 0.01) / 2.0;
    
    // Exact dimensions of white keys
    white_key_bottom_radius = 4;
    white_key_width = initial_white_key_width - buffer_space;
    white_key_height = (white_key_width * white_height_to_width_ratio) + white_key_bottom_radius;
    y_coordinate_of_piano = ((y_size_of_window / 2) - (white_key_height / 2));
    
    // Drawing the 52 white keys
    int white_keys_count = 0;
    for (int i = 0; i < Keyboard::NUM_OF_KEYS; i++) {
        PianoKey a_key = piano_keyboard.piano_keys[i];
        
        if (a_key.type == "wide") {
            ofRectangle key_shape = a_key.key_shape;
            key_shape.set(initial_buffer + (white_key_width * white_keys_count), y_coordinate_of_piano, white_key_width, white_key_height);
            ofSetColor(a_key.key_color);
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
    
    drawBlackKeys(initial_buffer);
    drawLayoutOutline(initial_buffer);
}

//--------------------------------------------------------------
void ofApp::drawBlackKeys(float starting_point) {
    // Exact dimensions of black keys
    black_to_white_width_ratio = black_key_unit_width / white_key_unit_width; // roughly 0.583
    black_key_width = white_key_width * black_to_white_width_ratio;
    black_key_height = black_key_width * black_height_to_width_ratio;
    

    top_of_c = (525 / white_key_unit_width) * white_key_width; // white space on the top of C and E
    top_of_f = (455 / white_key_unit_width) * white_key_width; // white space on the top of F and B
    
    // Drawing the first black key
    if (piano_keyboard.piano_keys[1].type == "thin") {
        float first_a = (735 / white_key_unit_width) * white_key_width;
        ofRectangle key_shape = piano_keyboard.piano_keys[1].key_shape;
        key_shape.set(first_a, y_coordinate_of_piano, black_key_width, black_key_height);
        ofSetColor(piano_keyboard.piano_keys[1].key_color);
        ofFill();
        ofDrawRectangle(key_shape);
    }
    
    // Drawing the other 35 black keys
    float x_coordinate = starting_point + (white_key_width * 2);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 12; j++) {
            int index_on_keyboard = (i * 12) + j + 3;
            PianoKey a_key = piano_keyboard.piano_keys[index_on_keyboard];
            
            if (j == 0 || j == 4) {
                if (a_key.type == "thin") {
                    ofRectangle key_shape = a_key.key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(a_key.key_color);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += top_of_c;
                } else {
                    x_coordinate += top_of_c;
                }
            } else if (j == 1 || j == 2 || j == 3) {
                if (a_key.type == "thin") {
                    ofRectangle key_shape = a_key.key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(a_key.key_color);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += black_key_width;
                } else {
                    x_coordinate += black_key_width;
                }
            } else if (j == 5 || j == 11) {
                if (a_key.type == "thin") {
                    ofRectangle key_shape = a_key.key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(a_key.key_color);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += top_of_f;
                } else {
                    x_coordinate += top_of_f;
                }
            } else {
                if (a_key.type == "thin") {
                    ofRectangle key_shape = a_key.key_shape;
                    key_shape.set(x_coordinate, y_coordinate_of_piano, black_key_width, black_key_height);
                    ofSetColor(a_key.key_color);
                    ofFill();
                    ofDrawRectangle(key_shape);
                    x_coordinate += black_key_width;
                } else {
                    x_coordinate += black_key_width;
                }
            }
        }
    }
}

void ofApp::drawLayoutOutline(float starting_point) {
    ofRectangle outlined_rectangle;
    float layout_width = 28 * white_key_width;
    float half_black_width = (black_key_width / 2);

    switch (location_layout) {
            
        case 1: // work on this one
            outlined_rectangle.set(starting_point, y_coordinate_of_piano, layout_width + half_black_width, white_key_height);
            layout_color.set(yellow);
            ofSetColor(layout_color);
            ofNoFill();
            ofSetLineWidth(2);
            ofDrawRectangle(outlined_rectangle);
            break;
        case 2:
            outlined_rectangle.set(starting_point + (5 * white_key_width), y_coordinate_of_piano, layout_width, white_key_height);
            layout_color.set(green);
            ofSetColor(layout_color);
            ofNoFill();
            ofSetLineWidth(2);
            ofDrawRectangle(outlined_rectangle);
            break;
        case 3:
            outlined_rectangle.set(starting_point + (12 * white_key_width), y_coordinate_of_piano, layout_width, white_key_height);
            layout_color.set(red);
            ofSetColor(layout_color);
            ofNoFill();
            ofSetLineWidth(2);
            ofDrawRectangle(outlined_rectangle);
            break;
        case 4:
            outlined_rectangle.set(starting_point + (19 * white_key_width), y_coordinate_of_piano, layout_width, white_key_height);
            layout_color.set(magenta);
            ofSetColor(layout_color);
            ofNoFill();
            ofSetLineWidth(2);
            ofDrawRectangle(outlined_rectangle);
            break;
        case 5: // work on this one
            outlined_rectangle.set(starting_point + (23 * white_key_width) + top_of_c, y_coordinate_of_piano, layout_width  + half_black_width, white_key_height);
            layout_color.set(blue);
            ofSetColor(layout_color);
            ofNoFill();
            ofSetLineWidth(2);
            ofDrawRectangle(outlined_rectangle);
            break;
        default:
            break;
    }

    ofSetLineWidth(1);
}

//--------------------------------------------------------------
void ofApp::establishComputerKeys(const std::string &computer_keys) {
    all_computer_keys = std::vector<int>(computer_keys.begin(), computer_keys.end());
}

//--------------------------------------------------------------
int ofApp::getCurrentPianoLayout() {
    switch (location_layout) {
        case 1:
            return loc_1_start;
        case 2:
            return loc_2_start;
        case 3:
            return loc_3_start;
        case 4:
            return loc_4_start;
        case 5:
            return loc_5_start;
        default:
            return loc_3_start;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RIGHT && location_layout < 5) {
        location_layout++;
        return;
    } else if (key == OF_KEY_LEFT && location_layout > 1) {
        location_layout--;
        return;
    } else {
       int starting_index = getCurrentPianoLayout();
        for (int i = 0; i < all_computer_keys.size(); i++) {
            if (key == all_computer_keys[i]) {
                piano_keyboard.piano_keys[i + starting_index].key_sound.play();
                piano_keyboard.piano_keys[i + starting_index].key_color.set(layout_color);
                return;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == OF_KEY_RIGHT || key == OF_KEY_LEFT) {
        return;
    }
    int starting_index = getCurrentPianoLayout();
    for (int i = 0; i < all_computer_keys.size(); i++) {
        if (key == all_computer_keys[i]) {
            if (piano_keyboard.piano_keys[i + starting_index].type == "wide") {
                piano_keyboard.piano_keys[i + starting_index].key_color.set(white);
            } else {
                piano_keyboard.piano_keys[i + starting_index].key_color.set(black);
            }
            return;
        }
    }
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

