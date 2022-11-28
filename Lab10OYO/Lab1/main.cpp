#include <iostream>
#include <time.h>

using namespace std;

long binaryFib(long num)
{
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return (binaryFib(num - 1) + binaryFib(num - 2));
}

long linearFib(long num, long a, long b)
{
    if(num == 0)
        return 0;
    if(num <= 2)
        return b;
    return linearFib(num - 1, b, a + b);
}

void iterativeFib(long num)
{
    long a = 0, b = 1, c = 0;
    for(int i = 0; i < num; i++)
    {
        //cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main()
{
    long num, result;
    struct timespec begin, end;
    cout << "Enter number to pass through: ";
    cin >> num;
    clock_gettime(CLOCK_REALTIME, &begin);
    cout << "The first " << num << " Fibonacci numbers using binary recursion are ";
    //for(int i = 0; i < num; i++)
        //cout << binaryFib(i) << " ";
    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    cout << " Time took to calculate: " << elapsed << " seconds" << endl;

    cout << endl;

    clock_gettime(CLOCK_REALTIME, &begin);
    cout << "The first " << num << " Fibonacci numbers using linear recursion are ";
    //for(int i = 0; i < num; i++)
    {
        //result = linearFib(i, 1, 1);
        //cout << result << " ";
    }
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    cout << " Time took to calculate: " << elapsed << " seconds" << endl;

    cout << endl;

    clock_gettime(CLOCK_REALTIME, &begin);
    cout << "The first " << num << " Fibonacci numbers using iterative are ";
    iterativeFib(num);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    cout << " Time took to calculate: " << elapsed << " seconds" << endl;
    return 0;
}