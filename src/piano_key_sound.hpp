//
//  piano_key_sound.hpp
//  final-project-daviddeborin
//
//  Created by David Deborin on 4/23/18.
//

#ifndef piano_key_sound_hpp
#define piano_key_sound_hpp

#include <stdio.h>
#include "ofMain.h"

class PianoKeySound {
private:
    ofSoundPlayer key_sound;
    
public:
    PianoKeySound(ofSoundPlayer sound_of_key) {
        key_sound = sound_of_key;
    }
}

#endif /* piano_key_sound_hpp */
