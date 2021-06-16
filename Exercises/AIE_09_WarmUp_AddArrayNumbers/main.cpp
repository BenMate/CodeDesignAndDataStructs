#include <iostream>
#include <vector>
#include <utility>

std::pair<int,int> arrayNumbers(std::vector<int> numbers,int answer) {
	//loop through the list checking 1 number [i] against number [j]
	for (int  i = 0; i < numbers.size() ; i++)
	{	
		for (int j = 0; j < numbers.size(); j++)
		{
			//check if i or j is the sum of the answer
			if (numbers[i] + numbers[j] == answer)
			{
				//once found return the pair break out of loop
				return std::make_pair(numbers[i], numbers[j]);
			}
		}
	}	
	//if it couldnt find a pair return 0
	return std::make_pair(0, 0);
}

int main(int argc, char** argv) {
	auto pair = arrayNumbers({ 1, 4, 8, 9, 12 }, 13);// output [1, 12]
	std::cout << pair.first << " " << pair.second << std::endl;
	auto pair2 = arrayNumbers({ 1, 2, 3, 7, 8, 9 }, 10);  // output [8, 2] or [1, 9] or [7, 3] any of these are acceptable
	std::cout << pair2.first << " " << pair2.second << std::endl;
	auto pair3 = arrayNumbers({ 5, 7, 12, 13, 14, 15, 16, 17 }, 20);  // output: [5, 15] or [7, 13]
	std::cout << pair3.first << " " << pair3.second << std::endl;
}