#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;

class StudentTable
{
    int size;
    int mode;
    vector<int> ids, scores;
    vector<bool> used;
    vector<list<pair<int, int>>> chains;

public:
    StudentTable(int tableSize, int chosenMode)
        : size(tableSize), mode(chosenMode), ids(tableSize, 0), scores(tableSize, 0),
          used(tableSize, false), chains(tableSize) {}

    bool insert(int id, int score)
    {
        int home = ((id % size) + size) % size;
        if (mode == 2)
        {
            chains[home].push_back(make_pair(id, score));
            return true;
        }
        for (int i = 0; i < size; i++)
        {
            int slot = (home + i) % size;
            if (!used[slot])
            {
                used[slot] = true;
                ids[slot] = id;
                scores[slot] = score;
                return true;
            }
        }
        return false;
    }

    bool search(int id, int &score) const
    {
        int home = ((id % size) + size) % size;
        if (mode == 2)
        {
            for (list<pair<int, int>>::const_iterator it = chains[home].begin();
                 it != chains[home].end(); ++it)
                if (it->first == id)
                {
                    score = it->second;
                    return true;
                }
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            int slot = (home + i) % size;
            if (!used[slot])
                return false;
            if (ids[slot] == id)
            {
                score = scores[slot];
                return true;
            }
        }
        return false;
    }

    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Slot " << i << ": ";
            if (mode == 1)
            {
                if (used[i])
                    cout << "(" << ids[i] << ", " << scores[i] << ")";
                else
                    cout << "Empty";
            }
            else
            {
                if (chains[i].empty())
                    cout << "Empty";
                for (list<pair<int, int>>::const_iterator it = chains[i].begin();
                     it != chains[i].end(); ++it)
                {
                    if (it != chains[i].begin())
                        cout << " -> ";
                    cout << "(" << it->first << ", " << it->second << ")";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int size, mode, count;
    cout << "Enter table size: ";
    cin >> size;
    cout << "Choose mode (1 = linear probing, 2 = chaining): ";
    cin >> mode;
    if (size <= 0 || (mode != 1 && mode != 2))
    {
        cout << "Error: invalid table size or mode" << endl;
        return 0;
    }

    StudentTable table(size, mode);
    cout << "Enter number of records: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int id, score;
        cout << "Enter student ID and score: ";
        cin >> id >> score;
        if (!table.insert(id, score))
            cout << "Error: table is full, record " << id << " not stored" << endl;
    }

    cout << "Final table:" << endl;
    table.display();

    int query, score;
    cout << "Enter an ID to look up: ";
    cin >> query;
    if (table.search(query, score))
        cout << "Found: ID " << query << " has score " << score << endl;
    else
        cout << "ID " << query << " not found" << endl;
    return 0;
}
