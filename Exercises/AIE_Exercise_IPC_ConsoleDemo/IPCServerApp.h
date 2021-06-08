//IPCServer.h
//-------------

#pragma once

#include "Application.h"
#include <Windows.h>


class IPCServerApp : public Application 
{
public:

	IPCServerApp();
	virtual ~IPCServerApp();
	virtual void Run();

	// gain access to a named shared memory block that already exists
    HANDLE m_fileHandle;

    // map the memory from the shared block to a pointer we can manipulate
	MyData* m_data;

	

protected:
private:
};