#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
using namespace std;

// Comment #1: Function prototype for gen_hash_index
int gen_hash_index(string str);
void print_hash_table(map<int, list<string>> &hash_table);
void print_menu();

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

    bool isExit = false;
    int choice;
    string searchKey;

    // Comment #6: Menu loop
    while (!isExit) 
    {
        // Comment #7: Display menu options
        print_menu();

        cout << "Enter your choice: ";
        cin >> choice;

        // Comment #8: Handle user choice
        switch (choice) 
        {
            case 1:
                print_hash_table(hash_table);
                break;
            case 2:
                {
                    cout << "Please enter a search key: ";
                    cin >> searchKey;
                    int hashIndex = gen_hash_index(searchKey);
                    auto &list = hash_table[hashIndex];
                    bool found = false;

                    for (const auto &str : list) 
                    {
                        if (str == searchKey) 
                        {
                            found = true;
                            break;
                        }
                    }

                    if (found) 
                    {
                        cout << "Key '" << searchKey << "' found in the hash table." << endl;
                    } 
                    else 
                    {
                        cout << "Key '" << searchKey << "' not found in the hash table." << endl;
                    }

                    cout << endl;
                }
                break;

            default:
                isExit = true;
                break;
        }
    }

    return 0;
}

// Comment #9: Function definition for gen_hash_index
int gen_hash_index(string str)
{
    int sum = 0;
    for (char c : str) 
    {
        // Comment #10: Add the ASCII value of each character to sum
        sum += (int) c;
    }
    
    return sum % 1000;
}

void print_hash_table(map<int, list<string>> &hash_table)
{
    int count = 0;

    // Comment #11: Print the first 100 entries of the hash table
    for (auto &p : hash_table) 
    {
        // Comment #12: Limit output to first 100 entries
        if (count >= 100) 
        {
            break;
        }

        cout << "Index " << p.first << endl;

        // Comment #13: Print all strings stored at this hash index
        for (auto &s : p.second) 
        {
            cout << "\t" << s << endl;
        }

        count++;
    }
}

// Comment #14: Function definition for print_menu
void print_menu()
{
    cout << "Menu Options:" << endl;
    cout << "1. Print Hash Table" << endl;
    cout << "2. Search for a Key" << endl;
}

// Milestone 1