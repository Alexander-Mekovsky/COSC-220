
//Date: September 6, 2022
//Class: COSC 220
//Assignment: Lab 02 Part 2
//Program Objective: To make an array bound by the limits of a number of dice. The user must decide how many rolls they want and with how many dice each roll shall have. At the end
//of the program each value rolled up to that point will be counted and added at the end similar to the previous program.


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
    cout << "Input number of rolls: ";
    cin >> size;
    if(size <= 0)
    {
        do
        {
            cout << "Invalid roll detected. Please enter another value: ";
            cin >> size;
        } while (size <= 0);
    }
    cout << "Input number of dice: ";
    cin >> range;
    if(range <= 0)
    {
        do
        {
            cout << "Invalid dice detected. Please enter another value: ";
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
    cout << "Counts" << endl;
    for(int i = 0; i < (range * 6); i++)
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
        for(int j = 0; j < range; j++)
        {
            arr[i] += (rand() % 6) + 1;
        }
    }
    return arr;
}

void displayArray(int arr[], int size)
{
    cout << "Rolls" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
