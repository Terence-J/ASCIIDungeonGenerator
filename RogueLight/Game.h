#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "RandomDungeonAlgorithm - Joiris, Terence - 1DAE-GD13" };

// Change the window dimensions here
float g_WindowWidth{  };
float g_WindowHeight{  };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
unsigned int seed = 146846;

const int g_DungeonWidth = 100;
const int g_DungeonHeight = 25;
const int g_MaxRooms = 3;  // Maximum number of rooms
char g_Dungeon[g_DungeonHeight][g_DungeonWidth];

// Declare your own functions here
void InitializeDungeon();
void GenerateRandomRooms();
void ConnectRoomsWithCorridors();
void DisplayDungeon();

struct Room {
    int x, y;
    int width, height;
};


// Array of rooms
Room rooms[g_MaxRooms];


#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling


#include <iostream>
#include "pch.h"