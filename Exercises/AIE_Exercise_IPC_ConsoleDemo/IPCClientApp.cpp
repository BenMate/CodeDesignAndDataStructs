//IPPClientApp.cpp
//------------------

#include "IPCClientApp.h"
#include<Windows.h>
#include <iostream>
#include <conio.h>

IPCClientApp::IPCClientApp() 
{
    std::cout << std::boolalpha;
}

IPCClientApp::~IPCClientApp() 
{
    // unmap the memory block since we're done with it
    UnmapViewOfFile(m_data);

    // close the shared file
    CloseHandle(m_fileHandle);
}

void IPCClientApp::Run() 
{
    int ch;
    bool able = true;
     
    m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, Shared_Path);

    m_data = (MyData*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));


    while (able) 
    {
        if (m_fileHandle == nullptr) 
        {
            std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
        }

        if (m_data == nullptr) 
        {
            std::cout << "Could not map view of file: " << GetLastError() << std::endl;
            CloseHandle(m_fileHandle);
        }

        // write out what is in the memory block
        std::cout << "MyData = { ";
        std::cout << m_data->i << ", ";
        std::cout << m_data->f << ", ";
        std::cout << m_data->c << ", ";
        std::cout << m_data->b << ", ";
        std::cout << m_data->d << ", ";
        std::cout << " };" << std::endl;

        // wait for a keypress to close

        Sleep(500);
        system("cls");
        
    }
}