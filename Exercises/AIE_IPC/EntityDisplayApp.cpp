#include "EntityDisplayApp.h"

#include "raylib.h"
#include "FixWindows.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, Shared_Path);

	m_data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * 10);
}

EntityDisplayApp::~EntityDisplayApp()
{
	// unmap the memory block since we're done with it
	UnmapViewOfFile(m_data);
	// close the shared file
	CloseHandle(m_fileHandle);
}

void EntityDisplayApp::Startup()
{
	
}

void EntityDisplayApp::Shutdown()
{

}

void EntityDisplayApp::Update(float deltaTime)
{

}

void EntityDisplayApp::Draw()
{
	bool able = true;
	while (able) {

		if (m_fileHandle == nullptr)
		{
			GetLastError(); 
			//print on screen waiting for file to open??
		}

		if (m_data == nullptr)
		{
			GetLastError();
			CloseHandle(m_fileHandle);

		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		// draw entities
		for (auto& entity : m_entities) {

			DrawRectanglePro(
				Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
				Vector2{ entity.size / 2, entity.size / 2 }, // origin
				entity.rotation,
				Color{ entity.r, entity.g, entity.b, 255 });
		}

		// output some text, uses the last used colour
		DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

		EndDrawing();
	}
}