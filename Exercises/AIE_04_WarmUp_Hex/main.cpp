#include <iostream>
#include <string>
// TODO: Write your function here

bool isValidHexCode(std::string word) {
	if (word.size() != 7 || word[0] != '#') {
		return false;
	}

	for (int i = 1; i < 7; i++)
	{
		if (word[i] < '0' && word[i] >'9') {
			return false;
		}
		else if (isupper(word[i]) < 'A' && isupper(word[i]) > 'F') {
			return false;
		}
		else if (islower(word[i]) < 'a' && islower(word[i]) > 'f') {
			return false;
		}	
	}
	return true;
}
//bool isValidHexCode(std::string check)
//{
//
//	if (check[0] != '#' || check.length() != 7)
//		return false;
//	for (int i = 1; i < check.length(); i++)
//	{
//		if (check[i] >= 'a' && check[i] <= 'f')
//		{
//			continue;
//		}
//		if (check[i] >= 'A' && check[i] <= 'F')
//		{
//			continue;
//		}
//		if (check[i] >= '0' && check[i] <= '9')
//		{
//			continue;
//		}
//		return false;
//	}
//	return true;
//}

int main()
{
	std::cout << isValidHexCode("#CD5C5C") << ": expected true" << std::endl;
	std::cout << isValidHexCode("#EAECEE") << ": expected true" << std::endl;
	std::cout << isValidHexCode("#eaecee") << ": expected true" << std::endl;

	std::cout << isValidHexCode("#CD5C58C") << ": expected false" << std::endl;
	std::cout << isValidHexCode("#CD5C5Z") << ": expected false" << std::endl;
	std::cout << isValidHexCode("#CD5C&C") << ": expected false" << std::endl;
	std::cout << isValidHexCode("#Cd5C&C") << ": expected false" << std::endl;
	std::cout << isValidHexCode("CD5C5C") << ": expected false" << std::endl;
}
