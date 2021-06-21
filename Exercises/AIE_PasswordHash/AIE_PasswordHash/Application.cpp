#include "Appplication.h"
#include <iostream>
#include <string>
#include <fstream>

static const std::string passwordFile = "./.auth";

Application::Application()
{
	LoadPass();
}
Application::~Application()
{

}

void Application::Run()
{
	Authenticate();
	std::cout << "Welcome to the program" << std::endl;
}

bool Application::Authenticate()
{
	std::cout << "Login: " << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	int pwh = PromptPassword(false);
	std::cout << "----------------------------------------" << std::endl;

	if (pwh != m_authHash)
		throw NotAuthorisedException();

	return true;
}

void Application::LoadPass()
{
	std::ifstream f(passwordFile.c_str(), std::ios::binary);

	if (f.good())
	{
		// read the pw hash from file
		f.read((char*)&m_authHash, sizeof(m_authHash));
		f.close();
	}
	else
	{
		// run setup - prompt for a password
		// this will be the password needed to enter the program next time its run.
		std::cout << "Running program for first time (setup):" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		int pwh = PromptPassword(true);
		std::cout << pwh << std::endl;
		SavePass(pwh);
		std::cout << "Password Saved!" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}
}

void Application::SavePass(unsigned int hash)
{
	m_authHash = hash;
	std::ofstream f(passwordFile.c_str(), std::ios::binary);
	f.write((const char*)&m_authHash, sizeof(m_authHash));
	f.close();
}



int Application::PromptPassword(bool confirmPrompt)
{
	while (true)
	{
		std::cout << "Enter a password:" << std::endl;

		std::string pw;
		std::getline(std::cin, pw);
		int pwh = hashFn(pw.c_str(), pw.length());

		if (!confirmPrompt)
			return pwh;

		std::cout << "Confirm password:" << std::endl;

		std::string pwc;
		std::getline(std::cin, pwc);

		int pwch = hashFn(pwc.c_str(), pwc.length()); //hash function

		if (pwh == pwch)
		{
			return pwh;
		}
		else
		{
			std::cout << "Password confirmation doesn't match, try again!" << std::endl;
		}
	}
}

// This is the Basic Hash method from the lecture
unsigned int Application::BasicHash(const char* data, unsigned int size)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < size; ++i)//loops through the "data"
		hash += data[i]; //combines data

	return hash; 
	/*just returns the value meaning if numbers are jumbled it 
	will still return the same value - example . abc bca are both the same value */
}

//make another hash

unsigned int Application::MyHash(const char* data, unsigned int size)
{	
	
	unsigned int hash = 0;
	
	//loops through data
	for (unsigned int i = 0; i < size; ++i) {
		hash = hash * 131313 + 29873232 + 23232 + 
			2323 - 2323  * 2 - 232323 + 2323232 +
			2323 + data[i]; // :)
	}
	return hash;
}