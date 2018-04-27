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
#include "piano_key.hpp"
#include "ofMain.h"
#include "ofApp.h"

std::vector<PianoKey> piano_keys;

class Keyboard {
private:
    std::vector<PianoKey> piano_keys; // ALL 88 piano keys
    
    // A user will be able to play a certain location of the keyboard at a time (48 keys)
    std::vector<PianoKey> location1;
    std::vector<PianoKey> location2;
    std::vector<PianoKey> location3;
    std::vector<PianoKey> location4;
    std::vector<PianoKey> location5;
    
public:
    std::vector<PianoKey> getPianoKeys();
    std::vector<PianoKey> getLocation1();
    std::vector<PianoKey> getLocation2();
    std::vector<PianoKey> getLocation3();
    std::vector<PianoKey> getLocation4();
    std::vector<PianoKey> getLocation5();

};

#endif /* keyboard_hpp */
