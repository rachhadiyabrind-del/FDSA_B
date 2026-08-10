#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a array size: " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a array element: ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        bool print = false;
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                print = true;
                break;
            }
        }

        if (count > 1 && !print)
        {
            cout << arr[i] << " ";
        }
    }
}