#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

void generateArray(int arr[], int size, int minVal, int maxVal)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

int findMaxOddIndex(const int arr[], int size)
{
    int maxOdd = INT_MIN;
    int maxOddIndex = -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] % 2 != 0 && arr[i] > maxOdd)
        {
            maxOdd = arr[i];
            maxOddIndex = i;
        }
    }

    return maxOddIndex;
}

void swapLastWithMaxOdd(int arr[], int size)
{
    int maxOddIndex = findMaxOddIndex(arr, size);

    if (maxOddIndex != -1)
    {
        swap(arr[size - 1], arr[maxOddIndex]);
    }
}

int main()
{
    srand(time(0));

    const int SIZE = 13;
    const int MIN_VAL = -100;
    const int MAX_VAL = 100;

    int arr[SIZE];

    generateArray(arr, SIZE, MIN_VAL, MAX_VAL);
    cout << "Initial array: " << endl;
    printArray(arr, SIZE);

    swapLastWithMaxOdd(arr, SIZE);

    cout << "Modified array: " << endl;
    printArray(arr, SIZE);

    return 0;
}
