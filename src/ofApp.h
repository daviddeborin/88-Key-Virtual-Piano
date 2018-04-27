#pragma once

#include "ofMain.h"
#include <vector>
#include <string>

class ofApp : public ofBaseApp{
private:
    std::vector<ofSoundPlayer> key_sounds;
    Keyboard piano_keyboard;
    ofImage piano_image;
    int location_layout;
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
