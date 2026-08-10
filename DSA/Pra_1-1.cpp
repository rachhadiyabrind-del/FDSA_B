#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number of items: ";
    int item;
    cin >> item;

    int array[item];

    cout << "Enter items: ";
    for (int i = 0; i < item; i++)
    {
        cin >> array[i];
    }

    cout << "Enter number of hours: ";
    int t;
    cin >> t;

    for (int j = 0; j <t; j++)
    {
        int first = array[0];

        for (int i = 0; i < item - 1; i++)
        {
            array[i] = array[i + 1];
        }

        array[item - 1] = first;
    }

    cout << "Items after " << t << " hours: ";

    for (int i = 0; i < item; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}