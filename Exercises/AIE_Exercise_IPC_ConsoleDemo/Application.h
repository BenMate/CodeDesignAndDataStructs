// Application.h
// -----------------

#pragma once

class Application {
public:

	struct MyData
	{
		int i;
		float f;
		char c;
		bool b;
		double d;
	};

	const wchar_t Shared_Path[15] = L"MySharedMemory";

	Application();
	virtual ~Application();
	virtual void Run() = 0;
	
protected:
private:

};