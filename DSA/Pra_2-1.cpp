#include <iostream>
using namespace std;

int n;

int find(int array[], int search, int i)
{
    if (i >= n)
    {
        return -1;
    }
    else if (array[i] == search)
    {
        return i;
    }
    else
    {
        return find(array, search, i + 1);
    }
}

int main()
{
    cout << "Enter number of car parking slots: ";
    cin >> n;

    int array[n];

    cout << "Enter the number of cars: ";

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Enter number of car to search: ";
    int search;
    cin >> search;

    int position = find(array, search, 0);

    if (position == -1)
    {
        cout << "Car not found";
    }
    else
    {
        cout << "Car found at position: " << position;
    }

    return 0;
}