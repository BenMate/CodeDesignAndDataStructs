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



	Application();
	virtual ~Application();
	virtual void Run() = 0;
	
protected:
	const wchar_t m_sharedPath[15] = L"MySharedMemory";
private:

};