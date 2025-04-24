#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <raylib.h>
#include "vector.h"

// Forward declarations
class Ball;
class Padle;

// Function to handle collision between ball and paddle
void HandleCollision(Ball& ball, Padle& paddle);

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    Ball();
    void Draw();
    void Update(bool& shakeActive, float& shakeDuration);
    void GameReset();
};

class Padle {
public:
    float x, y;
    float Padle_width, Padle_height;
    int speed;
    Color color = { 142, 140, 156, 255 };

    Padle();
    void Draw_Padle();
    virtual void Update();
};

class Padle2 : public Padle {
public:
    void Update2();
};

class AI_Padle : public Padle {
public:
    void Update_AI(int ball_y);
};

// Global game objects declarations
extern Ball ball;
extern Padle padle;
extern AI_Padle ai_padle;
extern AI_Padle ai_padle2;
extern Padle2 padle2;

// Global score variables
extern int Player_Win;
extern int Ai_Win;
extern bool _Ai;
extern bool _Player;
extern int Time;

#endif // GAME_OBJECTS_H 