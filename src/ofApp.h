#pragma once

#include "ofMain.h"
#include "keyboard.hpp"
#include <vector>
#include <string>

class ofApp : public ofBaseApp{
private:
    std::vector<ofSoundPlayer> key_sounds;
    Keyboard piano_keyboard;
    ofImage piano_image;
    
    // keeps track of which of the 5 piano keyboard layouts is in use.
    // 0 <= location_layout <= 5
    int location_layout;
    
    // A string consisting of all the computer keys used to play the virtual piano.
    string computer_keys;
    std::vector<int> all_computer_keys;
    
public:
    void setup();
    void update();
    void draw();
    
    // This method creates 5 different 48-key layouts (vectors) on the piano keyboard.
    void createKeyboardLocations();
    
    /**
     This method creates a vector that stores all the computer keys as ASCII numerics.

     @param computer_keys is a string made up of all the 48 computer keys used to play the virtual piano.
     */
    void establishComputerKeys(string computer_keys);
    
    // This method returns the current location layout of the virtual piano.
    std::vector<PianoKey> getCurrentPianoLayout();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int kmx, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    std::vector<ofSoundPlayer> getKeySounds();
    
};
