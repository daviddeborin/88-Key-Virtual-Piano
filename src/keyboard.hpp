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

class Keyboard {
private:
    std::vector<PianoKey> piano_keys;
    
public:
    std::vector<PianoKey> getPianoKeys();
};

#endif /* keyboard_hpp */
