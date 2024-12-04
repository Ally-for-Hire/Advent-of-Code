#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool validateOpen (ifstream &file);

int main()
{
    // File Validation
    ifstream dataFile("test"); 
    bool open = validateOpen(dataFile);
    if (!open) { cout << "File unable to be opened."; return 0; }

    // Global Variables
    string line;

    // Part 1 Solution
    // ---------------------------------------------------------------------------//
    cout << "The answer to Part 1 is: " << endl;
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

bool validateOpen (ifstream &file)
{
    if (!file.is_open())
    {
        return false;
    }
    return true;
}