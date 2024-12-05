#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool validateOpen (ifstream &file); // (Filename)
bool validateDir (string, int, int, char*, int); // (Whole String, Length, Index, Next Letters, Direction)
int booltoint (bool); // (Bool)

int main()
{
    // File Validation
    ifstream dataFile("input"); 
    bool open = validateOpen(dataFile);
    if (!open) { cout << "File unable to be opened."; return 0; }

    // Global Variables
    string line;

    // Part 1 Solution
    // ---------------------------------------------------------------------------//
    string wholefile;
    int length, wholeWords = 0;
    char nextletters[] = {'M', 'A', 'S'};

    while (getline(dataFile, line))
    {
        if (length == 0) { length = line.length(); }
        wholefile += line;
    }

    for (int i = 0; i < wholefile.length(); i++)
    {
        char letter = wholefile[i];
        if (letter != 'X') { continue; }

        for (int direction = 0; direction <= 7; direction++)
        {
            bool check = validateDir(wholefile, length, i, nextletters, direction);
            wholeWords += booltoint(check);
        }
        
        
    }
    cout << "The answer to Part 1 is: " << wholeWords << endl;
    // ---------------------------------------------------------------------------//
    
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    // Part 2 Solution
    // ---------------------------------------------------------------------------//
    cout << "The answer to Part 2 is: " << endl;
    // ---------------------------------------------------------------------------//
    dataFile.close();
    return 0;
}

int booltoint (bool value) { return value && 1 || 0; }

bool validateOpen (ifstream &file)
{
    if (!file.is_open())
    {
        return false;
    }
    return true;
}

bool checkIndex (string wholefile, int index, char search)
{
    if (wholefile[index] == search)
    {
        return true;
    }    
    return false;
}

bool validateDir (string wholefile, int length, int index, char nextletters[], int direction)
{
    int localIndex = index;
    int currentRow = index / length;

    for (int x = 0; x < 3; x++)
    {
        // Up, Down, Left, Up Left, Down Left, Right, Up Right, Down Right
        if (direction == 0) { localIndex -= length; currentRow -= 1;}
        else if (direction == 1) { localIndex += length; currentRow += 1;}
        else if (direction == 2) { localIndex -= 1; }
        else if (direction == 3) { localIndex -= length; localIndex -= 1; currentRow -= 1; }
        else if (direction == 4) { localIndex += length; localIndex -= 1; currentRow += 1; }
        else if (direction == 5) { localIndex += 1; }
        else if (direction == 6) { localIndex -= length; localIndex += 1; currentRow -= 1; }
        else if (direction == 7) { localIndex += length; localIndex += 1; currentRow += 1; }
        else { return false; }

        if (localIndex < 0 || localIndex > wholefile.length() - 1) { return false; }
        if (localIndex / length != currentRow) { return false; }
        
        if (!checkIndex(wholefile, localIndex, nextletters[x])) { return false; }
    }

    return true;
}
