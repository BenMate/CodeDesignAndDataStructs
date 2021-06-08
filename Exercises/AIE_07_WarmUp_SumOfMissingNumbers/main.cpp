#include <vector>
#include <iostream>
#include <algorithm>
int sumMissingNumbers(std::vector<int> arr)
{
    //ge the min max and total
    int TotalNumber = 0;
    auto VecterMinAndMax = minmax_element(arr.begin(), arr.end());
    int min = *VecterMinAndMax.first;
    int max = *VecterMinAndMax.second;

    //loop through
    for (int i = min; i < max; i++)
    {
        //find missing number
        bool MissingNumb = false;
        //loop through arr to find the values
        for (int num : arr)
        {
            if (i == num)
                MissingNumb = true;
        }
        //if you find missing number add the count to totalnumber
        if (!MissingNumb)
            TotalNumber += i;
    }
    return TotalNumber;
}

int main(int argc, char** argv)
{
    // TODO: write tests to verify your output
    std::cout << sumMissingNumbers({ 1, 3, 5 }) << std::endl; // 2+ 4 = 6
    std::cout << sumMissingNumbers({ 1, 3, 5, 7, 10 }) << std::endl; // 2 + 4 + 6 + 8 + 9 = 29
    std::cout << sumMissingNumbers({ 10, 7, 5, 3, 1 }) << std::endl;// 29
    std::cout << sumMissingNumbers({ 10, 20, 30, 40, 50, 60 }) << std::endl;// 1575

    

}