#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream dataFile("input.dat"); 
    bool open = validateOpen(dataFile);
    if (!open) {cout << "File unable to be opened."; return 0;}

    // Part 1 Solution
    cout << "The answer to Part 1 is: " << endl;
    
    // Part 2 Solution
    dataFile.clear();
    dataFile.seekg(0, ios::beg);
    
    cout << "The answer to Part 2 is: " << endl;

    dataFile.close();
    return 0;
}

bool validateOpen (ifstream file)
{
    if (!file.is_open())
    {
        return false;
    }
    return true;
}