
//Date: September 6, 2022
//Class: COSC 220
//Assignment: Lab 02 Part 1
//Program Objective: To make an array with parameters the user must decide, including size of array and range of numbers that the array can generate, the program shall then 
//count each occurring value and print how many values the array has at the end of the program.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* generateNumbers(int, int);
void displayArray(int[], int);
void arrayCount(int[], int);

int main()
{
    int range, size;
    char show;
    cout << "Input size of array: ";
    cin >> size;
    if(size <= 0)
    {
        do
        {
            cout << "Invalid size detected. Please enter another value: ";
            cin >> size;
        } while (size <= 0);
    }
    cout << "Input n > 0 for upper bound on range of random numbers, [1, n]: ";
    cin >> range;
    if(range <= 0)
    {
        do
        {
            cout << "Invalid range detected. Please enter another value: ";
            cin >> range;
        } while (range <= 0);
    }
    int *arrayGen = generateNumbers(range, size);
    cout << "Do you want a printout of the array> (Y/N) :";
    cin >> show;
    show = toupper(show);
    if(show != 'Y' && show != 'N')
    {
        do
        {
            cout << "Invalid choice. Please try again: (Y/N) :";
            cin >> show;
        } while (show != 'Y' && show != 'N');
    }
    if(show == 'Y')
    {
        displayArray(arrayGen, size);
    }
    for(int i = 0; i < range; i++)
    {        
        arrayCount(arrayGen, size);
    }
    return 0;
}

void arrayCount(int arr[], int size)
{
    int count = 0;
    static int interval = 1;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == interval)
        {
            count++;
        }
    }
    cout << interval << ": " << count << endl;
    interval++;
}

int* generateNumbers(int range, int size)
{
    int *arr = nullptr;
    arr = new int[size];
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % range + 1;
    }
    return arr;
}

void displayArray(int arr[], int size)
{
    cout << "Array" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
