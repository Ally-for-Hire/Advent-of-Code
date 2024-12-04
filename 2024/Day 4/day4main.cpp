#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream dataFile("input.dat"); 

    if (!dataFile.is_open())
    {
        cout << "File not opened.";
        return 0;
    }

    // Part 1 Solution
    cout << "The answer to Part 1 is: " << endl;
    
    // Part 2 Solution
    dataFile.clear();
    dataFile.seekg(0, ios::beg);
    
    cout << "The answer to Part 2 is: " << endl;

    dataFile.close();
    return 0;
}