#pragma once

#include "ofMain.h"
#include "keyboard.hpp"
#include <vector>
#include <string>

class ofApp : public ofBaseApp{
private:
    ofColor white;
    ofColor black;
    ofColor yellow;
    ofColor green;
    ofColor red;
    ofColor magenta;
    ofColor blue;
    ofColor layout_color;
    
    int x_size_of_window = 1024;
    int y_size_of_window = 768;
    
    // White key dimensions
    int white_key_bottom_radius;
    const float white_height_to_width_ratio = 5.39;
    float white_key_width;
    float white_key_height;
    float y_coordinate_of_piano;
    float white_key_unit_width = 840.0;
    
    // Black key dimensions
    float black_key_unit_width = 490.0;
    float black_to_white_width_ratio;
    const float black_height_to_width_ratio = 5.84;
    float black_key_height;
    
    /* If you look closely at a piano, you'll notice that the black keys are not perfectly
     located between 2 white keys. In fact, only 7 of the 36 black keys are symmetrically
     located in between 2 white keys. Furthermore, there are 3 different distances between
     a black key and a white key.
     */
    float black_key_width;
    float top_of_c;
    float top_of_f;
    
    std::vector<ofSoundPlayer> key_sounds;
    Keyboard piano_keyboard;
    ofImage piano_image;
    
    // keeps track of which of the 5 piano keyboard layouts is in use.
    // 0 <= location_layout <= 5
    int location_layout;
    
    // A string consisting of all the computer keys used to play the virtual piano.
    const std::string computer_keys = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
    std::vector<int> all_computer_keys;
    
public:
    void setup();
    void update();
    
    void draw();
    void drawBlackKeys(float starting_point);
    
    void setColors();
    
    // This method creates 5 different 48-key layouts (vectors) on the piano keyboard.
    void createKeyboardLocations();
    
    /**
     This method creates a vector that stores all the computer keys as ASCII numerics.
     @param computer_keys is a string made up of all the 48 computer keys used to play the virtual piano.
     */
    void establishComputerKeys(const std::string &computer_keys);
    
    // This method creates all 88 keys, where each key has a sound, shape, and color.
    void createKeyboard();
    
    void drawLayoutOutline(float starting_point);
    
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
    
    std::vector<ofSoundPlayer> &getKeySounds();
    
};
