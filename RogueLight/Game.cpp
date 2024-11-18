#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	srand(seed);

	InitializeDungeon();
	GenerateRandomRooms();
	ConnectRoomsWithCorridors();
	DisplayDungeon();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
	
	// SAMPLE CODE: check which mouse button was pressed
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//	//std::cout << "Left mouse button released\n";
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitializeDungeon() {
	for (int i = 0; i < g_DungeonHeight; i++) {
		for (int j = 0; j < g_DungeonWidth; j++) {
			g_Dungeon[i][j] = '#';  // Walls
		}
	}
}

void GenerateRoom(int amountRooms) {
	Room room = rooms[amountRooms];

	for (int i = room.x; i < room.x + room.width; i++) {
		for (int j = room.y; j < room.y + room.height; j++) {
			if (i >= 0 && i < g_DungeonHeight && j >= 0 && j < g_DungeonWidth) {
				g_Dungeon[i][j] = ' '; 
			}
		}
	}
}

void GenerateRandomRooms() {
	for (int i = 0; i < g_MaxRooms; i++) {
		int roomWidth = rand() % 4 + 3;
		int roomHeight = rand() % 4 + 3;
		int x = rand() % (g_DungeonHeight - roomWidth - 1);
		int y = rand() % (g_DungeonWidth - roomHeight - 1);

		// Assign Random Values
		rooms[i].x = x;
		rooms[i].y = y;
		rooms[i].width = roomWidth;
		rooms[i].height = roomHeight;

		GenerateRoom(i);
	}
}

void CreateCorridor(int x1, int y1, int x2, int y2) {
	// Horizontal Corridor
	if (x1 > x2) {
		for (int x = x2; x <= x1; x++) {
			g_Dungeon[x][y1] = ' ';
		}
	}
	else {
		for (int x = x1; x <= x2; x++) {
			g_Dungeon[x][y1] = ' ';
		}
	}

	// Vertical Corridor
	if (y1 > y2) {
		for (int y = y2; y <= y1; y++) {
			g_Dungeon[x2][y] = ' ';
		}
	}
	else {
		for (int y = y1; y <= y2; y++) {
			g_Dungeon[x2][y] = ' ';
		}
	}
}

void ConnectRoomsWithCorridors() {
	for (int i = 0; i < g_MaxRooms - 1; i++) {
		int x1 = rooms[i].x + rooms[i].width / 2;
		int y1 = rooms[i].y + rooms[i].height / 2;
		int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
		int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

		CreateCorridor(x1, y1, x2, y2);
	}
}

void DisplayDungeon() {
	for (int i = 0; i < g_DungeonHeight; i++) {
		for (int j = 0; j < g_DungeonWidth; j++) {
			std::cout << g_Dungeon[i][j];
		}
		std::cout << std::endl;
	}
}


#pragma endregion ownDefinitions