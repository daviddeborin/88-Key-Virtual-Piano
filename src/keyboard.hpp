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

public:
    Keyboard() {
        
        // 0th octave
        PianoKey a0(A0);
        piano_keys.push_back(A0);
        PianoKey b_flat_0(B_flat_0);
        piano_keys.push_back(b_flat_0);
        PianoKey b0(B_zero);
        piano_keys.push_back(b0);
        PianoKey c0(C0);
        piano_keys.push_back(c0);
        PianoKey d_flat_0(D_flat_0);
        piano_keys.push_back(d_flat_0);
        PianoKey d0(D0);
        piano_keys.push_back(d0);
        PianoKey e_flat_0(E_flat_0);
        piano_keys.push_back(e_flat_0);
        PianoKey e0(E0);
        piano_keys.push_back(e0);
        PianoKey f0(F0);
        piano_keys.push_back(f0);
        PianoKey g_flat_0(G_flat_0);
        piano_keys.push_back(g_flat_0);
        PianoKey g0(G0);
        piano_keys.push_back(g0);
        PianoKey a_flat_0(A_flat_0);
        piano_keys.push_back(a_flat_0);

        // 1st octave
        PianoKey a1(A1);
        piano_keys.push_back(a1);
        PianoKey b_flat_1(B_flat_1);
        piano_keys.push_back(b_flat_1);
        PianoKey b1(B1);
        piano_keys.push_back(b1);
        PianoKey c1(C1);
        piano_keys.push_back(c1);
        PianoKey d_flat_1(D_flat_1);
        piano_keys.push_back(d_flat_1);
        PianoKey d1(D1);
        piano_keys.push_back(d1);
        PianoKey e_flat_1(E_flat_1);
        piano_keys.push_back(e_flat_1);
        PianoKey e1(E1);
        piano_keys.push_back(e1);
        PianoKey f1(F1);
        piano_keys.push_back(f1);
        PianoKey g_flat_1(G_flat_1);
        piano_keys.push_back(g_flat_1);
        PianoKey g1(G1);
        piano_keys.push_back(g1);
        PianoKey a_flat_1(A_flat_1);
        piano_keys.push_back(a_flat_1);

        // 2nd octave
        PianoKey a2(A2);
        piano_keys.push_back(a2);
        PianoKey b_flat_2(B_flat_2);
        piano_keys.push_back(b_flat_2);

        PianoKey b2(B2);
        PianoKey c2(C2);
        PianoKey d_flat_2(D_flat_2);
        PianoKey d2(D2);
        PianoKey e_flat_2(E_flat_2);
        PianoKey e2(E2);
        PianoKey f2(F2);
        PianoKey g_flat_2(G_flat_2);
        PianoKey g2(G2);
        PianoKey a_flat_2(A_flat_2);
        
        // 3rd octave
        PianoKey a3(A1);
        PianoKey b_flat_3(B_flat_3);
        PianoKey b3(B3);
        PianoKey c3(C3);
        PianoKey d_flat_3(D_flat_3);
        PianoKey d3(D3);
        PianoKey e_flat_3(E_flat_3);
        PianoKey e3(E3);
        PianoKey f3(F3);
        PianoKey g_flat_3(G_flat_3);
        PianoKey g3(G3);
        PianoKey a_flat_3(A_flat_3);
        
        // 4th octave
        PianoKey a4(A4);
        PianoKey b_flat_4(B_flat_4);
        PianoKey b4(B4);
        PianoKey c4(C4);
        PianoKey d_flat_4(D_flat_4);
        PianoKey d4(D4);
        PianoKey e_flat_4(E_flat_4);
        PianoKey e4(E4);
        PianoKey f4(F4);
        PianoKey g_flat_4(G_flat_4);
        PianoKey g4(G4);
        PianoKey a_flat_4(A_flat_4);
        
        // 5th octave
        PianoKey a5(A5);
        PianoKey b_flat_5(B_flat_5);
        PianoKey b5(B5);
        PianoKey c5(C5);
        PianoKey d_flat_5(D_flat_5);
        PianoKey d5(D5);
        PianoKey e_flat_5(E_flat_5);
        PianoKey e5(E5);
        PianoKey f5(F5);
        PianoKey g_flat_5(G_flat_5);
        PianoKey g5(G5);
        PianoKey a_flat_5(A_flat_5);
        
        // 6th octave
        PianoKey a6(A6);
        PianoKey b_flat_6(B_flat_6);
        PianoKey b6(B6);
        PianoKey c6(C6);
        PianoKey d_flat_6(D_flat_6);
        PianoKey d6(D6);
        PianoKey e_flat_6(E_flat_6);
        PianoKey e6(E6);
        PianoKey f6(F6);
        PianoKey g_flat_6(G_flat_6);
        PianoKey g6(G6);
        PianoKey a_flat_6(A_flat_6);
        
        // 7th octave (final third)
        PianoKey a7(A7);
        PianoKey b_flat_7(B_flat_7);
        PianoKey b7(B7);
        PianoKey c7(C7);
        
//        // 0th octave
//        ofSoundPlayer A0;
//        ofSoundPlayer B_flat_0;
//        ofSoundPlayer B_zero;
//        ofSoundPlayer C0;
//        ofSoundPlayer D_flat_0;
//        ofSoundPlayer D0;
//        ofSoundPlayer E_flat_0;
//        ofSoundPlayer E0;
//        ofSoundPlayer F0;
//        ofSoundPlayer G_flat_0;
//        ofSoundPlayer G0;
//        ofSoundPlayer A_flat_0;
    }
};

#endif /* keyboard_hpp */
