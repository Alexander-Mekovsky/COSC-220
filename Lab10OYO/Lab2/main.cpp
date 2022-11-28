#include <iostream>
#include <ctime>

using namespace std;

int binRecursion(int arr[], int low, int high, int value)
{
    if(low < high)
    {
        int mid = (high + low) / 2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] < value)
            return binRecursion(arr, mid + 1, high, value);
        else
            return binRecursion(arr, low, mid - 1, value);
    }
    else
        return -1;
}

int binIterator(int arr[], int low, int high, int value)
{
    while(low < high)
    {
        int mid = (high + low) / 2;
        if(arr[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    if(arr[low] == value)
        return low;
    else if (arr[high] == value)
        return high;
    else
        return -1;
}

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(0));
    int value;
    const long SIZE = 10000;
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand()%SIZE + 1;
        cout << arr[i] << " ";
    }
    cout << "Please enter value to find from the randomly generated array. ";
    cin >> value;
    bubbleSort(arr, SIZE);
    int result = binRecursion(arr, 0, SIZE - 1, value);
    cout << "Following from binary search recursion: ";
    if(result == -1)
        cout << "The number is not found." << endl;
    else
        cout << "The number is found." << endl;
    int newResult = binIterator(arr, 0, SIZE - 1, value);
    cout << "Following from binary search iterator: ";
    if(newResult == -1)
        cout << "The number is not found." << endl;
    else
        cout << "The number is found." << endl;
    
    return 0;
}