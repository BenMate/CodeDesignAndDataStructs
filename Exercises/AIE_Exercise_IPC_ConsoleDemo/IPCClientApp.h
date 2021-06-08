//IPCClientApp.h
//-----------------
#pragma once

#include "Application.h"
#include <Windows.h>

class IPCClientApp : public Application 
{

public:
	IPCClientApp();
	virtual ~IPCClientApp();
	virtual void Run();

	// gain access to a named shared memory block that already exists
	HANDLE m_fileHandle;

	// map the memory from the shared block to a pointer we can manipulate
	MyData* m_data; 
	


protected:
private:

};
