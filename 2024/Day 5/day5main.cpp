#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool validateOpen (ifstream &file);

int main()
{
    // File Validation
    ifstream ruleFile("test1"); 
    bool open = validateOpen(ruleFile);
    if (!open) { cout << "File unable to be opened."; return 0; }
    ifstream dataFile("test2"); 
    open = validateOpen(dataFile);
    if (!open) { cout << "File unable to be opened."; return 0; }

    // Global Variables
    string line, rule;

    // Part 1 Solution
    // ---------------------------------------------------------------------------//
    // plan: test every case against every rule MANUALLY
    while (getline(dataFile, line))
    {
        while (getline(ruleFile, rule))
        {
            istringstream ruleStream (rule);
            string beforeStr, afterStr;

            getline(ruleStream, beforeStr, '|');
            getline(ruleStream, afterStr, '|');

            int before = stoi(beforeStr);
            int after = stoi(afterStr);

            cout << before << " | " << after << endl;
        }
    }

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