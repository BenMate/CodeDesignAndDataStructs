#include <iostream>
#include <algorithm>
#include <chrono>

// TODO:
// Create a function that returns the number of characters shared between two words.

int SharedLetters(const std::string& string1, const std::string& string2) {
    //to get the length of each string
    int s1 = string1.length();
    int s2 = string2.length();
    //to store the number of pairs from the 2 words
    int word1[255] = { 0 };
    int word2[255] = { 0 };

    int i = 0;
    int count = 0;
    //loop through and update the commen occurrence of each character
    for (i = 0; i < s1; i++)
    {
        word1[string1[i]]++;
    }
    for (i = 0; i < s2; i++)
    {
        word2[string2[i]]++;
    }
    //find the count of each pair and compare them.
    for (i = 0; i < 255; i++)
    {
        count += (fmin(word1[i], word2[i]));
    }
    return count;
}

int main(int argc, char** argv)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::cout << SharedLetters("Apple", "meAty") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsook") << std::endl; // 1
    std::cout << SharedLetters("fanf", "forsook") << std::endl; // 1
    std::cout << SharedLetters("fanf", "forsookf") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsookf") << std::endl; // 1
    std::cout << SharedLetters("spout", "shout") << std::endl; // 4

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    //std::cout << SharedLetters("apple", "meaty") << std::endl; // 2
    //std::cout << SharedLetters("fanf", "forsook") << std::endl; // 1
    //std::cout << SharedLetters("fanf", "forsookf") << std::endl; // 2
    //std::cout << SharedLetters("fan", "forsookf") << std::endl; // 1
    //std::cout << SharedLetters("spout", "shout") << std::endl; // 4

    char c;
    std::cin >> c;
}

