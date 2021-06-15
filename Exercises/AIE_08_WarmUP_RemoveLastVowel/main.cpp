#include <iostream>
#include <vector>

std::string removeLastVowel(std::string s) {
	std::vector<std::string> temp;
	std::string finalResult = "";
	std::string token = "";

	char space = ' ';
	int i = 0;

	//loop trough splitting words
	while (s[i] != '\0') {
		char c = s[i];
		if (c != space) {
			token += c;
		}
		else if (token.empty() == false) {
			temp.push_back(token);
			token.clear();
		}
		i++;
	}
	temp.push_back(token);

	//loop trough each word removing the last vowel
	for (auto& word : temp)
	{
		//bool isAVowelRemoved = false;
		for (int i = word.length() - 1; i >= 0; i--)
		{
			//if its a vowel remove it then 
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
				word.erase(i,1);
				break;
			}
		}
	}

	//ADD all words to a string;
	for (auto& word : temp) {
		finalResult += word;
		finalResult += " ";
	}
	return finalResult;
}

int main(int argc, char** argv)
{
	std::cout << removeLastVowel("Those who dare to fail miserably can achieve greetly.") << std::endl;
	//➞ "Thos wh dar t fal miserbly cn achiev gretly."
	std::cout << removeLastVowel("Love is a serious mental disease.") << std::endl;
	//➞ "Lov s  serios mentl diseas"
	std::cout << removeLastVowel("Get busy living or get busy dying.") << std::endl;
	//➞ "Gt bsy livng r gt bsy dyng"
}