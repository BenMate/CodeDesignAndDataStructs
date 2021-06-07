#include <iostream>
#include <vector>
std::string shiftLetters(std::string w, int n)
{
	int Space = 0;
	int length = w.length();
	std::vector<int> Spaces;

	//if n = 0 just straight up return the word
	if (n == 0) {
		return w;
	}

	//records the location of spaces
	for (int i = 0; i < w.size(); i++) {
		if (w[i] == ' ') {
			Spaces.push_back(i);
		}
	}

	//removes spaces (backwards for loop)
	for (int i = length -1; i >= 0; --i) {
		if (w[i] == ' ') {
			w.erase(i, 1);
		}
	}

	//shifts the characters
	for (int i = 0; i < n; i++)
	{
		char character = w.back();
		w.pop_back();
		w.insert(0, 1, character );
	}

	for (auto& i : Spaces)
	{
		w.insert(i, 1, ' ');
	}

	return w;
}
int main(int argc, char** argv)
{
	std::cout << shiftLetters("Boom", 1) << "; Expected : mBoo" << std::endl;
	std::cout << shiftLetters("Boom", 2) << "; Expected : omBo" << std::endl;
	std::cout << shiftLetters("This is a test", 4) << "; Expected: test Th i sisa" << std::endl;
	std::cout << shiftLetters("A B C D E F G H", 5) << "; Expected : D E F G H A B C" << std::endl;

	return 0;
}
