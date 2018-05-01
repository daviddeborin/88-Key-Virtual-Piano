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
#include "ofMain.h"
#include "ofxGui.h"

struct PianoKey {
    static ofColor white;
    static ofColor black;
    ofSoundPlayer key_sound;
    ofRectangle key_shape;
    ofColor key_color;
};

struct Keyboard {
    static const int NUM_OF_KEYS = 88;
    static const int NUM_WHITE_KEYS = 52;
    
    std::vector<PianoKey> piano_keys; // ALL 88 piano keys
    
    // A user will be able to play a certain location of the keyboard at a time (48 keys)
    std::vector<PianoKey> location1;
    std::vector<PianoKey> location2;
    std::vector<PianoKey> location3;
    std::vector<PianoKey> location4;
    std::vector<PianoKey> location5;
};

#endif /* keyboard_hpp */
