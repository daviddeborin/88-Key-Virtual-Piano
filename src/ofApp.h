#pragma once

#include "ofMain.h"
#include <vector>

//std::vector<ofSoundPlayer> key_sounds;

// 0th octave
ofSoundPlayer A0;
ofSoundPlayer B_flat_0;
ofSoundPlayer B_zero;
ofSoundPlayer C0;
ofSoundPlayer D_flat_0;
ofSoundPlayer D0;
ofSoundPlayer E_flat_0;
ofSoundPlayer E0;
ofSoundPlayer F0;
ofSoundPlayer G_flat_0;
ofSoundPlayer G0;
ofSoundPlayer A_flat_0;

// 1st octave
ofSoundPlayer A1;
ofSoundPlayer B_flat_1;
ofSoundPlayer B1;
ofSoundPlayer C1;
ofSoundPlayer D_flat_1;
ofSoundPlayer D1;
ofSoundPlayer E_flat_1;
ofSoundPlayer E1;
ofSoundPlayer F1;
ofSoundPlayer G_flat_1;
ofSoundPlayer G1;
ofSoundPlayer A_flat_1;

// 2nd octave
ofSoundPlayer A2;
ofSoundPlayer B_flat_2;
ofSoundPlayer B2;
ofSoundPlayer C2;
ofSoundPlayer D_flat_2;
ofSoundPlayer D2;
ofSoundPlayer E_flat_2;
ofSoundPlayer E2;
ofSoundPlayer F2;
ofSoundPlayer G_flat_2;
ofSoundPlayer G2;
ofSoundPlayer A_flat_2;

// 3rd octave
ofSoundPlayer A3;
ofSoundPlayer B_flat_3;
ofSoundPlayer B3;
ofSoundPlayer C3;
ofSoundPlayer D_flat_3;
ofSoundPlayer D3;
ofSoundPlayer E_flat_3;
ofSoundPlayer E3;
ofSoundPlayer F3;
ofSoundPlayer G_flat_3;
ofSoundPlayer G3;
ofSoundPlayer A_flat_3;

// 4th octave
ofSoundPlayer A4;
ofSoundPlayer B_flat_4;
ofSoundPlayer B4;
ofSoundPlayer C4;
ofSoundPlayer D_flat_4;
ofSoundPlayer D4;
ofSoundPlayer E_flat_4;
ofSoundPlayer E4;
ofSoundPlayer F4;
ofSoundPlayer G_flat_4;
ofSoundPlayer G4;
ofSoundPlayer A_flat_4;

// 5th octave
ofSoundPlayer A5;
ofSoundPlayer B_flat_5;
ofSoundPlayer B5;
ofSoundPlayer C5;
ofSoundPlayer D_flat_5;
ofSoundPlayer D5;
ofSoundPlayer E_flat_5;
ofSoundPlayer E5;
ofSoundPlayer F5;
ofSoundPlayer G_flat_5;
ofSoundPlayer G5;
ofSoundPlayer A_flat_5;

// 6th octave
ofSoundPlayer A6;
ofSoundPlayer B_flat_6;
ofSoundPlayer B6;
ofSoundPlayer C6;
ofSoundPlayer D_flat_6;
ofSoundPlayer D6;
ofSoundPlayer E_flat_6;
ofSoundPlayer E6;
ofSoundPlayer F6;
ofSoundPlayer G_flat_6;
ofSoundPlayer G6;
ofSoundPlayer A_flat_6;

// 7th octave (last third)
ofSoundPlayer A7;
ofSoundPlayer B_flat_7;
ofSoundPlayer B7;
ofSoundPlayer C7;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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

    
};
