#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    cout << "Enter the sentence: ";
    string sentence;
    getline(cin, sentence);

    stringstream ss(sentence);
    
    string word, longest;

    ss >> longest;

    while (ss >> word)
    {
        if (word.length() > longest.length())
        {
            longest = word;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Number of letters: " << longest.length() << endl;

    return 0;
}