#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
}

int largestPrimeBelow(int m)
{
    for (int p = m - 1; p >= 2; p--)
        if (isPrime(p))
            return p;
    return 1;
}

int main()
{
    int m;
    cout << "Enter table size (a prime such as 11 is recommended): ";
    cin >> m;
    if (m <= 0)
    {
        cout << "Error: table size must be positive" << endl;
        return 0;
    }
    if (!isPrime(m))
        cout << "Warning: " << m << " is not prime, some IDs may not find a free slot even if one exists." << endl;

    int R = largestPrimeBelow(m);
    vector<int> table(m, 0);
    vector<bool> used(m, false);

    int count;
    cout << "Enter number of student IDs: ";
    cin >> count;

    for (int s = 0; s < count; s++)
    {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = ((id % m) + m) % m;
        int h2 = R - (((id % R) + R) % R);

        int slot = h1;
        int probes = 0;
        while (probes < m && used[slot])
        {
            probes++;
            slot = (h1 + probes * h2) % m;
        }

        if (probes == m)
        {
            cout << "Error: could not place " << id << " (no free slot reachable, h1=" << h1
                 << ", h2=" << h2 << ")" << endl;
        }
        else
        {
            used[slot] = true;
            table[slot] = id;
            cout << id << " -> slot " << slot << " (h1=" << h1 << ", h2=" << h2
                 << ", collisions=" << probes << ")" << endl;
        }
    }

    cout << "Final table:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Slot " << i << ": ";
        if (used[i])
            cout << table[i];
        else
            cout << "Empty";
        cout << endl;
    }
    return 0;
}
