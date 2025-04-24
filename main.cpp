#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "vector.h"
#include "game_objects.h"
#include "effects.h"

int main()
{
	printf("Game is Started\n");
	const int screen_width = 1680;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "Pong");
	SetTargetFPS(60);

	//Background
	Texture2D background = LoadTexture("background/4.jpg");

	// Initialize game objects
	// Ball is already initialized in game_objects.cpp
	
	// Paddle initialization
	padle.x = screen_width - 80;
	padle.y = screen_height / 2.0f - 60;
	padle.Padle_width = 30;
	padle.Padle_height = 200;
	padle.speed = 15;

	// Paddle2 initialization
	padle2.x = 30;
	padle2.y = screen_height / 2.0f - 60; 
	padle2.Padle_width = 30; 
	padle2.Padle_height = 200;
	padle2.speed = 15; 

	// AI paddle initialization
	ai_padle.x = 30;
	ai_padle.y = screen_height / 2.0f - 60;
	ai_padle.Padle_width = 30;
	ai_padle.Padle_height = 200;
	ai_padle.speed = 10;

	ai_padle2.x = screen_width - 70;
	ai_padle2.y = screen_height / 2.0f - 60;
	ai_padle2.Padle_width = 40;
	ai_padle2.Padle_height = 200;
	ai_padle2.speed = 15;

	// Camera and shake effect setup
	bool _shake = false;
	float shakeDuration = 0.0f;
	float shakeIntensity = 4.0f;

	Camera2D camera = { 0 };
	camera.target = { screen_width / 2 , screen_height / 2 };
	camera.offset = { screen_width / 2 , screen_height / 2 };
	camera.zoom = 1.0f;

	// Music
	InitAudioDevice();
	Music music = LoadMusicStream("Music/pixel2.mp3");
	Music count = LoadMusicStream("Music/countdown.mp3");
	PlayMusicStream(music);
	PlayMusicStream(count);

	// Countdown
	float countdown = 3.0f;
	bool gameStarted = false;
	Font font = LoadFont("font/f2.ttf");

	// Effect initialization
	Score_Opacity.alpha = 1.0f;
	Score_Opacity.alphaSpeed = 0.015f;
	Back_Opacity.alpha = 1.0f;
	Back_Opacity.alphaSpeed = 0.25f;
	float action = 0;

	// Flame effect setup
	flame flamTail[max_flam] = { 0 };
	Color color = { 127,162,172,255 };

	// Timer
	float minute = 59.0f;
	float second = 10.0f;

	// Initialize flame effects
	for (int i = 0; i < max_flam; i++)
	{
		flamTail[i].pos = Vector2{ 0,0 };
		flamTail[i].color = color; 
		flamTail[i].alpha = 1.0f;
		flamTail[i].rotation = (float)GetRandomValue(1, 360);
		flamTail[i].size = (float)GetRandomValue(1, 90) / 90.0f;
		flamTail[i].active = false;
	}

	float gravity = 3.0f;

	Texture2D flame_Tx = LoadTexture("background/flame.png");
	int blending = BLEND_ADDITIVE; 

	// Eye tracking setup
	PVector leftEye(screen_width / 2 - 20, screen_height / 2);
	PVector rightEye(screen_width / 2 + 20, screen_height / 2);
    
    // Define pupil variables with broader scope
    PVector BallVector(0, 0);
    PVector leftPupil(leftEye.x, leftEye.y);
    PVector rightPupil(rightEye.x, rightEye.y);

	// Main game loop
	while (!WindowShouldClose())
	{
        // Game logic
        UpdateMusicStream(music);

        if (!gameStarted)
        {
            UpdateMusicStream(count);

            if (countdown > -1)
            {
                countdown -= GetFrameTime();
            }
            else
                gameStarted = true;
        }
        else
        {
            // Update flame effects
            for (int i = 0; i < max_flam; i++)
            {
                if (!flamTail[i].active)
                {
                    flamTail[i].active = true;
                    flamTail[i].alpha = 1.0f;
                    flamTail[i].pos = Vector2{ ball.x, ball.y };
                    i = max_flam;
                }
            }

            for (int i = 0; i < max_flam; i++)
            {
                if (flamTail[i].active)
                {
                    flamTail[i].pos.y += gravity / 2.0f;
                    flamTail[i].alpha -= 0.01f;

                    if (flamTail[i].alpha <= 0)
                    {
                        flamTail[i].active = false;
                    }
                    flamTail[i].rotation += 2.0f;
                }
            }

            // Handle collisions
            HandleCollision(ball, padle);
            HandleCollision(ball, ai_padle);

            // Camera shake effect
            if (_shake) {
                camera.offset.x = screen_width / 2.0f + (GetRandomValue(-shakeIntensity, shakeIntensity));
                camera.offset.y = screen_height / 2.0f + (GetRandomValue(-shakeIntensity, shakeIntensity));

                shakeDuration -= GetFrameTime();

                if (shakeDuration <= 0.0f) {
                    _shake = false; 
                    camera.offset = { screen_width / 2.0f, screen_height / 2.0f }; // Reset the offset
                }
            }
            else
            {
                camera.offset = { screen_width / 2.0f, screen_height / 2.0f };
            }

            // Update game objects
            ball.Update(_shake, shakeDuration);
            padle.Update();
            ai_padle.Update_AI(ball.y);
            
            // Update eye tracking
            BallVector = PVector(ball.x, ball.y);
            leftPupil = leftEye.copy().add(BallVector.copy().sub(leftEye).setMag(10));
            rightPupil = rightEye.copy().add(BallVector.copy().sub(rightEye).setMag(10));
        }

        // Update background opacity
        Back_Opacity.FadeInOut();

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);

        // Draw game elements
        // Draw background with opacity
        if (action >= 61)
        {
            DrawTexture(background, 0, 0, Fade(WHITE, Back_Opacity.alpha));
        }
        else
            DrawTexture(background, 0, 0, WHITE);
        action += 0.0184f;
        
        // Draw countdown or game elements
        if (countdown > -1)
        {
            DrawText(TextFormat("%i", (int)ceil(countdown)), screen_width / 2.0f, screen_height / 2.0f, 100, WHITE);
        }
        else
        {
            BeginMode2D(camera);
            
            // Draw eyes that follow the ball
            DrawCircleV(Vector2{ leftEye.x, leftEye.y }, 25, WHITE);
            DrawCircleV(Vector2{ rightEye.x, rightEye.y }, 25, WHITE);
            DrawCircleV(Vector2{ leftPupil.x, leftPupil.y }, 10, BLACK);
            DrawCircleV(Vector2{ rightPupil.x, rightPupil.y }, 10, BLACK);
            
            BeginBlendMode(blending);
            
            // Draw ball
            ball.Draw();
            
            // Draw countdown timer
            if (Time != 0)
            {
                DrawText(TextFormat("%i", (int)ceil(Time)), screen_width / 2.0f, screen_height + 10, 80, WHITE);
                Time--;
            }
            
            // Draw flame effects
            for (int i = 0; i < max_flam; i++)
            {
                if (flamTail[i].active)
                {
                    DrawTexturePro(flame_Tx,
                        Rectangle{ 0.0f, 0.0f, (float)flame_Tx.width, (float)flame_Tx.height },
                        Rectangle{ flamTail[i].pos.x, flamTail[i].pos.y, flame_Tx.width * flamTail[i].size, flame_Tx.height * flamTail[i].size },
                        Vector2{ (float)(flame_Tx.width * flamTail[i].size / 2.0f), (float)(flame_Tx.height * flamTail[i].size / 2.0f) },
                        flamTail[i].rotation,
                        Fade(flamTail[i].color, flamTail[i].alpha));
                }
            }

            // Draw paddles
            padle.Draw_Padle();
            ai_padle.Draw_Padle();

            // Draw score display
            if (_Ai || _Player)
            {
                DrawLine(screen_width / 2.0f, 105, screen_width / 2.0f, screen_height, Fade(WHITE, Score_Opacity.alpha));
                DrawLine(screen_width / 2.0f - 250, 0, screen_width / 2.0f, 105, Fade(WHITE, Score_Opacity.alpha));
                DrawLine(screen_width / 2.0f + 250, 0, screen_width / 2.0f, 105, Fade(WHITE, Score_Opacity.alpha));
                DrawLine(0, 105, screen_width, 105, Fade(WHITE, Score_Opacity.alpha));
                DrawText(TextFormat("%i", Ai_Win), screen_width / 4 - 20, 20, 80, Fade(WHITE, Score_Opacity.alpha));
                DrawText(TextFormat("%i", Player_Win), screen_width / 2 + 320, 20, 80, Fade(WHITE, Score_Opacity.alpha));

                Score_Opacity.FadeOut_Fun();
                if (Score_Opacity.alpha <= 0)
                {
                    _Ai = false; 
                    _Player = false; 
                    Score_Opacity.Resest();
                }
            }
            
            // Draw timer
            if (second >= 0)
            {
                if (second >= 9)
                    DrawText(TextFormat("%i : %i", 1, (int)ceil(second)), screen_width / 2 - 40, 20, 50, WHITE);
                else
                    DrawText(TextFormat("%i : 0%i", 1, (int)ceil(second)), screen_width / 2 - 40, 20, 50, WHITE);
                second -= GetFrameTime();
            }
            else
            {
                if (minute >= 9)
                {
                    DrawText(TextFormat("0%i : %i", 0, (int)ceil(minute)), screen_width / 2 - 85, 20, 50, WHITE);
                }
                else
                {
                    if (minute >= 0)
                        DrawText(TextFormat("0%i : 0%i", 0, (int)ceil(minute)), screen_width / 2 - 85, 20, 50, WHITE);
                    else 
                        DrawText(TextFormat("0%i : 0%i", 0, 0), screen_width / 2 - 85, 20, 50, WHITE);
                }

                minute -= GetFrameTime();
            }
            
            // End blend mode
            EndBlendMode();
            EndMode2D();
        }

		// Draw FPS counter
		DrawFPS(10, 10);
		EndDrawing();
	}

	// Cleanup
	UnloadTexture(background);
	UnloadTexture(flame_Tx);
	UnloadFont(font);
	UnloadMusicStream(music);
	UnloadMusicStream(count);
	CloseAudioDevice();
	CloseWindow();
	
	return 0;
} 