#include <iostream>
using namespace std;

int find(int array[], int search, int x, int y)
{
    if (x > y)
    {
        return -1;
    }

    int mid = (x + y) / 2;

    if (array[mid] == search)
    {
        return mid;
    }
    else if (array[mid] < search)
    {
        return find(array, search, mid + 1, y);
    }
    else
    {
        return find(array, search, x, mid - 1);
    }
}

int main()
{
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    int array[n];

    cout << "Enter the book codes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Enter code of book to search: ";
    int search;
    cin >> search;

    int position = find(array, search, 0, n - 1);

    cout << "Book found at index: " << position << endl;

    return 0;
}