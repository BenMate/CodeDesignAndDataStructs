#include <iostream>

// TODO: Write the FindOdd function

int FindOdd(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++)
    {
        int count = 0;
        for (int j = 0; j < arr_size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return arr[i];
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    // TODO: write test code to verify your function works as expected
    int arr[] = { 1,1,2,-2,5,2,4,4,-1,-2,5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int arr2[] = { 20,1,1,2,2,3,3,5,5,4,20,4,5 };
    int size2 = sizeof(arr2) / sizeof(arr[0]);

    int arr3[] = { 10 };
    int size3 = sizeof(arr3) / sizeof(arr[0]);

    std::cout << FindOdd(arr, size) << std::endl;
    std::cout << FindOdd(arr2, size2) << std::endl;
    std::cout << FindOdd(arr3, size3) << std::endl;

    return 0;
}
