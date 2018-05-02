//
//  keyboard.hpp
//  final-project-daviddeborin
//
//  Created by David Deborin on 4/23/18.
//

#ifndef keyboard_hpp
#define keyboard_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "ofMain.h"
#include "ofxGui.h"

struct PianoKey {
    ofSoundPlayer key_sound;
    ofRectangle key_shape;
    ofColor key_color;
    std::string type;
};

struct Keyboard {
    static const int NUM_OF_KEYS = 88;
    static const int NUM_WHITE_KEYS = 52;
    
    std::vector<PianoKey> piano_keys; // ALL 88 piano keys
};

#endif /* keyboard_hpp */
