#include <iostream>
#include <vector>

// TODO: Write your function here

bool isMiniSudoku(std::vector<std::vector<int>> arr) {
	bool isValid = false;
	int numbers[9] = { 0,0,0,0,0,0,0,0,0 };

	//counts through the rows
	for (int row = 0; row < 3; row++)
	{
		//counts through the col
		for (int col = 0; col < 3; col++)
		{
			int val = arr[row][col];
			//if any number is outside 0-9
			if (val <= 0 || val > 9) {
				return false;
			}
			//counts all items in the arr
			numbers[val - 1]++;
		}
	}
	//checks if the freq of all items in array is 1 if not return false
	bool valid = true;
	for (auto& n : numbers)
	{
		if (n != 1)
			valid = false;
	}
	return valid;
}

int main()
{
	std::cout << isMiniSudoku({ {1,3,2},{9,7,8},{4,5,6} }) << "Expected true" << std::endl;

	std::cout << isMiniSudoku({ {8,9,2},{5,6,1},{3,7,4} }) << "Expected true" << std::endl;

	std::cout << isMiniSudoku({ {1,1,3},{6,5,4},{8,7,9} }) << "Expected false" << std::endl;//The1isrepeatedtwice 

	std::cout << isMiniSudoku({ {0,1,2},{6,4,5},{9,8,7} }) << "Expected false" << std::endl; //The0isincluded(outsiderange)
}