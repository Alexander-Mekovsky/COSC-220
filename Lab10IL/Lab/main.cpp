#include <iostream>

using namespace std;

int pascal(const int row, const int col)
{
    if(row < 0 || col < 0 || col > row)
        return 0;
    else if(row == 0 || col == 0 || row == 1 || row == col)
        return 1;
    else
        return (pascal(row - 1, col) + pascal(row - 1, col - 1));
}
int main()
{
    int row, col;
    cout << "Enter n and k (integer) with a space in between them: ";
    cin >> row >> col;
    cout << row << " choose " << col << " = " << pascal(row, col) << endl;
    return 0;
}