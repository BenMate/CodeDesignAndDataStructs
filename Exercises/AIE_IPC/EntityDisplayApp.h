#pragma once
#include <vector>
#include "Application.h"
#include "Entity.h"
#include <conio.h>

#include "raylib.h"
#include "FixWindows.h"

class EntityDisplayApp : public Application
{
public:

	EntityDisplayApp(int screenWidth, int screenHeight);
	virtual ~EntityDisplayApp();

	virtual void Startup();
	virtual void Shutdown();

	virtual void Update(float deltaTime);
	virtual void Draw();

	// gain access to a named shared memory block that already exists
	HANDLE m_fileHandle;
	// map the memory from the shared block to a pointer we can manipulate
	Entity* m_data;

protected:

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
};

