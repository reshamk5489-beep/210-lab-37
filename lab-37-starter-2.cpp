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
    string key;

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
                    cin >> key;

                    // Comment #9: Search for the key in the hash table
                    int hashIndex = gen_hash_index(key);

                    // Comment #10: Check if the key exists in the list at the computed hash index
                    auto &list = hash_table[hashIndex];
                    bool found = false;

                    // Comment #11: Iterate through the list to find the search key
                    for (const auto &str : list) 
                    {
                        if (str == key) 
                        {
                            found = true;
                            break;
                        }
                    }

                    if (found) 
                    {
                        cout << "Key '" << key << "' found in the hash table." << endl;
                    } 
                    else 
                    {
                        cout << "Key '" << key << "' not found in the hash table." << endl;
                    }

                    cout << endl;
                }
                break;
            case 3:
                {
                    cout << "Please enter a key to add: ";
                    cin >> key;

                    // Comment #12: Add the new key to the hash table
                    int hashIndex = gen_hash_index(key);
                    hash_table[hashIndex].push_back(key);

                    cout << "Key '" << key << "' added to the hash table." << endl << endl;
                }
                break;
            case 4:
                {
                    cout << "Please enter a key to remove: ";
                    cin >> key;

                    // Comment #13: Remove the key from the hash table
                    int hashIndex = gen_hash_index(key);
                    auto &list = hash_table[hashIndex];
                    auto it = find(list.begin(), list.end(), key);

                    // Comment #14: Check if the key was found and remove it
                    if (it != list.end())
                    {
                        list.erase(it);
                        cout << "Key '" << key << "' removed from the hash table." << endl << endl;
                    }
                    else
                    {
                        cout << "Key '" << key << "' not found in the hash table." << endl << endl;
                    }
                }
                break;
            case 5:
                {
                    cout << "Please enter the key to modify: ";
                    cin >> key;

                    cout << "Please enter the new key: ";
                    string newKey;
                    cin >> newKey;

                    // Comment #15: Modify the key in the hash table
                    int oldHashIndex = gen_hash_index(key);
                    auto &oldList = hash_table[oldHashIndex];
                    auto it = find(oldList.begin(), oldList.end(), key);

                    if (it != oldList.end())
                    {
                        // Comment #16: Remove the old key and add the new key
                        oldList.erase(it);
                        int newHashIndex = gen_hash_index(newKey);
                        hash_table[newHashIndex].push_back(newKey);
                        cout << "Key '" << key << "' modified to '" << newKey << "' in the hash table." << endl << endl;
                    }
                    else
                    {
                        cout << "Key '" << key << "' not found in the hash table." << endl << endl;
                    }
                }
                break;

            default:
                isExit = true;
                break;
        }
    }

    return 0;
}

// Comment #17: Function definition for gen_hash_index
int gen_hash_index(string str)
{
    int sum = 0;
    for (char c : str) 
    {
        // Comment #18: Add the ASCII value of each character to sum
        sum += (int) c;
    }
    
    return sum % 1000;
}

void print_hash_table(map<int, list<string>> &hash_table)
{
    int count = 0;

    // Comment #19: Print the first 100 entries of the hash table
    for (auto &p : hash_table) 
    {
        // Comment #20: Limit output to first 100 entries
        if (count >= 100) 
        {
            break;
        }

        cout << "Index " << p.first << endl;

        // Comment #21: Print all strings stored at this hash index
        for (auto &s : p.second) 
        {
            cout << "\t" << s << endl;
        }

        count++;
    }
}

// Comment #22: Function definition for print_menu
void print_menu()
{
    cout << "Menu Options:" << endl;
    cout << "1. Print Hash Table" << endl;
    cout << "2. Search for a Key" << endl;
    cout << "3. Add a Key" << endl;
    cout << "4. Remove a Key" << endl;
    cout << "5. Modify a Key" << endl;
}

// Milestone 5