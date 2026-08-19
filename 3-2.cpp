#include <iostream>
using namespace std;

void sort012(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];

    cout << "Enter 0, 1 and 2: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort012(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}