#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int main()
{
    int table[TABLE_SIZE];
    bool used[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        used[i] = false;

    int count;
    cout << "Enter number of vehicles: ";
    cin >> count;

    for (int v = 0; v < count; v++)
    {
        int reg;
        cout << "Enter registration number: ";
        cin >> reg;

        int home = reg % TABLE_SIZE;
        if (home < 0)
            home += TABLE_SIZE;

        int tries = 0;
        int slot = home;
        while (tries < TABLE_SIZE && used[slot])
        {
            slot = (slot + 1) % TABLE_SIZE;
            tries++;
        }

        if (tries == TABLE_SIZE)
        {
            cout << "Error: parking lot is full, " << reg << " cannot be parked" << endl;
        }
        else
        {
            used[slot] = true;
            table[slot] = reg;
            cout << reg << " -> slot " << slot;
            if (slot != home)
                cout << " (collision, home slot " << home << ", probes " << tries << ")";
            cout << endl;
        }
    }

    cout << "Final parking lot:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++)
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
