//IPCServerApp.cpp
//----------------

#include "IPCServerApp.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

IPCServerApp::IPCServerApp() {
	m_fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/write access control
		0,
		sizeof(MyData), // size of the memory block, 
		m_sharedPath);

	m_data = (MyData*)MapViewOfFile(m_fileHandle,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(MyData));
}

IPCServerApp::~IPCServerApp() {
	// unmap the memory block since we're done with it
	UnmapViewOfFile(m_data);
	// close the shared file
	CloseHandle(m_fileHandle);
}

void IPCServerApp::Run() {
	srand(time(NULL));
	int i = 0;
	float f = 0;
	char c = 0;
	bool b = 0;
	double d = 0;

	int ch;
	bool able = true;

	while (able) {

		MyData myData = {
			//generates random values
			 i = rand() % 100 + 1,
			f = rand() % 100 + 1.5f,
			c = rand() % 90 + 65, //upper case characters 'Z' - 'A'
			b = rand() % 2, //true or false
			d = rand() % 100 + 1.41
		};

		if (m_fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " <<
				GetLastError() << std::endl;

			if (m_data == nullptr)
			{
				std::cout << "Could not map view of file: " <<
					GetLastError() << std::endl;

				CloseHandle(m_fileHandle);
			}

			// write to the memory block

			*m_data = myData;
			// wait for a keypress to close
			ch = _getch();
			if (ch == 27) {
				able = false;
			}
		}
	}
}
