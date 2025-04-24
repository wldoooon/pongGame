#include "game_objects.h"
#include <stdio.h>

// Global game objects definitions
Ball ball;
Padle padle;
AI_Padle ai_padle;
AI_Padle ai_padle2;
Padle2 padle2;

// Global score variables
int Player_Win = 0;
int Ai_Win = 0;
bool _Ai = false;
bool _Player = false;
int Time = 80;

// Ball implementation
Ball::Ball() {
    radius = 10;
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    speed_x = 11;
    speed_y = 11;
}

void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update(bool& shakeActive, float& shakeDuration) {
    x += speed_x;
    y += speed_y;
    
    if (x + radius >= GetScreenWidth()) {
        Ai_Win++;
        GameReset();
        shakeActive = true;
        shakeDuration = 0.2f;
        _Ai = true;
    }
    
    if (x - radius <= 0) {
        Player_Win++;
        GameReset();
        shakeActive = true;
        shakeDuration = 0.5f;
        _Player = true;
    }
    else if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
        if (speed_x > 0)
            speed_x += GetRandomValue(1, 2);
        else
            speed_x -= GetRandomValue(1, 2);
    }
}

void Ball::GameReset() {
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    speed_x = 11;
    speed_y = 11;
}

// Paddle implementation
Padle::Padle() {
    x = GetScreenWidth() - 80;
    y = GetScreenHeight() / 2.0f - 60;
    Padle_width = 30;
    Padle_height = 200;
    speed = 15;
}

void Padle::Draw_Padle() {
    Rectangle rec = { x, y, Padle_width, Padle_height };
    DrawRectangleRounded(rec, 0.5f, 0, color);
}

void Padle::Update() {
    if (IsKeyDown(KEY_K))
        y += speed;
    else if (IsKeyDown(KEY_I))
        y -= speed;
    if (y <= 0)
        y = 0;
    if (y + Padle_height >= GetScreenHeight())
        y = GetScreenHeight() - Padle_height;
}

// Paddle2 implementation
void Padle2::Update2() {
    if (IsKeyDown(KEY_S))
        y += speed;
    else if (IsKeyDown(KEY_W))
        y -= speed;
    if (y <= 0)
        y = 0;
    if (y + Padle_height >= GetScreenHeight())
        y = GetScreenHeight() - Padle_height;
}

// AI Paddle implementation
void AI_Padle::Update_AI(int ball_y) {
    int target_y = ball_y - Padle_height / 2;

    // Move towards the ball, but ensure it stays within bounds
    if (y < target_y && y + Padle_height < GetScreenHeight())
        y += speed;
    else if (y > target_y && y > 0)
        y -= speed;
}

// Collision handling
void HandleCollision(Ball& ball, Padle& paddle) {
    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius,
        Rectangle{ paddle.x, paddle.y, paddle.Padle_width, paddle.Padle_height })) {
        ball.speed_x *= -1;
    }
} 