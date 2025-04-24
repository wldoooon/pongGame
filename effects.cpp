#include "effects.h"

// Global effects objects definitions
Opacity Back_Opacity;
Score_OP Score_Opacity;

// Opacity implementation
Opacity::Opacity() {
    alpha = 1.0f;
    alphaSpeed = 0.25f;
    FadeOut = true;
}

void Opacity::FadeInOut() {
    if (FadeOut) {
        alpha -= alphaSpeed;
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            FadeOut = false;
        }
    }
    else {
        alpha += alphaSpeed;
        if (alpha >= 1.0f) {
            alpha = 1.0f;
            FadeOut = true;
        }
    }
}

// Score_OP implementation
void Score_OP::FadeOut_Fun() {
    if (FadeOut) {
        alpha -= alphaSpeed;
        if (alpha <= 0) {
            alpha = 0;
            FadeOut = false;
        }
    }
}

void Score_OP::Resest() {
    FadeOut = true;
    alpha = 1.0f;
} 