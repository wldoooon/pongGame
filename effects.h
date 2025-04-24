#ifndef EFFECTS_H
#define EFFECTS_H

#include <raylib.h>
#include "vector.h"

constexpr auto max_flam = 200;

class Opacity {
public:
    float alpha;
    float alphaSpeed;
    bool FadeOut = true;

    Opacity();
    void FadeInOut();
};

class Score_OP : public Opacity {
public:
    void FadeOut_Fun();
    void Resest();
};

class flame {
public:
    Vector2 pos;
    Color color;
    float alpha;
    float size;
    float rotation;
    Vector2 speed;
    bool active;
};

// Global effects objects
extern Opacity Back_Opacity;
extern Score_OP Score_Opacity;

#endif // EFFECTS_H 