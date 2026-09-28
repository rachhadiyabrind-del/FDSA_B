#include <iostream>
#include <string>
using namespace std;

struct SongNode
{
    string song;
    SongNode *prev;
    SongNode *next;
};

class Playlist
{
private:
    SongNode *head;
    SongNode *tail;

public:
    Playlist() : head(nullptr), tail(nullptr)
    {
    }

    void addToBeginning(const string &song)
    {
        SongNode *newNode = new SongNode{song, nullptr, nullptr};

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Added '" << song << "' at the beginning." << endl;
        display();
    }

    void addToEnd(const string &song)
    {
        SongNode *newNode = new SongNode{song, nullptr, nullptr};

        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Added '" << song << "' at the end." << endl;
        display();
    }

    bool insertAfterSong(const string &targetSong, const string &newSong)
    {
        SongNode *current = head;

        while (current != nullptr && current->song != targetSong)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Song '" << targetSong << "' not found in the playlist." << endl;
            display();
            return false;
        }

        SongNode *newNode = new SongNode{newSong, nullptr, nullptr};
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr)
            current->next->prev = newNode;
        else
            tail = newNode;

        current->next = newNode;

        cout << "Inserted '" << newSong << "' after '" << targetSong << "'." << endl;
        display();
        return true;
    }

    void deleteFirstSong()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty. Nothing to remove." << endl;
            return;
        }

        SongNode *temp = head;
        cout << "Removed first song: '" << head->song << "'" << endl;

        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
        display();
    }

    int countSongs() const
    {
        int count = 0;
        SongNode *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "Total songs in playlist: " << count << endl;
        return count;
    }

    void display() const
    {
        if (head == nullptr)
        {
            cout << "Playlist: empty" << endl;
            return;
        }

        cout << "Playlist: ";
        SongNode *temp = head;

        while (temp != nullptr)
        {
            cout << temp->song;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Playlist()
    {
        SongNode *temp = head;
        while (temp != nullptr)
        {
            SongNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main()
{
    Playlist playlist;
    int choice;
    string song, targetSong, newSong;

    cout << "=== Music Player Playlist ===" << endl;

    do
    {
        cout << "\n1. Add song at beginning" << endl;
        cout << "2. Add song at end" << endl;
        cout << "3. Insert song after a specific song" << endl;
        cout << "4. Remove first song" << endl;
        cout << "5. Count songs" << endl;
        cout << "6. Display playlist" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addToBeginning(song);
            break;

        case 2:
            cin.ignore();
            cout << "Enter song name: ";
            getline(cin, song);
            playlist.addToEnd(song);
            break;

        case 3:
            cin.ignore();
            cout << "Enter current song name: ";
            getline(cin, targetSong);
            cout << "Enter new song name: ";
            getline(cin, newSong);
            playlist.insertAfterSong(targetSong, newSong);
            break;

        case 4:
            playlist.deleteFirstSong();
            break;

        case 5:
            playlist.countSongs();
            break;

        case 6:
            playlist.display();
            break;

        case 7:
            cout << "Program ended..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}