//
//  piano_key.hpp
//  final-project-daviddeborin
//
//  Created by David Deborin on 4/23/18.
//

#ifndef piano_key_hpp
#define piano_key_hpp

#include <stdio.h>
#include "ofMain.h"

class PianoKey {
private:
    ofSoundPlayer key_sound;
    
public:
    PianoKey(ofSoundPlayer sound_of_key) {
        key_sound = sound_of_key;
    }
    
    ofSoundPlayer getKeysound();
};
#endif /* piano_key_hpp */
