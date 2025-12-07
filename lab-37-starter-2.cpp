#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
using namespace std;

// Comment #1: Function prototype for gen_hash_index
int gen_hash_index(string str);

int main() 
{
    // Comment #2: Open the file lab-37-data-2.txt
    ifstream file("lab-37-data-2.txt");
    string line;
    map<int, list<string>> hash_table;

    // Comment #3: Read each line from the file and calculate the ASCII sum
    while (getline(file, line)) 
    {
        // Comment #4: Get the hash index and store the line in the hash table
        int hashIndex = gen_hash_index(line);

        // Comment #5: Store the line in the hash table at the computed hash index
        hash_table[hashIndex].push_back(line);
    }

    file.close();

    int count = 0;
    for (auto &p : hash_table) 
    {
        if (count >= 100) 
        {
            break;
        }

        cout << "Index " << p.first << endl;
        for (auto &s : p.second) 
        {
            cout << "\t" << s << endl;
        }

        count++;
    }

    return 0;
}

// Comment #6: Function definition for gen_hash_index
int gen_hash_index(string str)
{
    int sum = 0;
    for (char c : str) 
    {
        // Comment #7: Add the ASCII value of each character to sum
        sum += (int) c;
    }
    
    return sum % 1000;
}