#include <iostream>
using namespace std;
#include <fstream>

// Comment #1: Function prototype for sum_ascii
int sum_ascii(string str);

int main() 
{
    // Comment #2: Open the file lab-37-data-2.txt
    ifstream file("lab-37-data-2.txt");
    string line;
    int sum = 0;

    // Comment #3: Read each line from the file and calculate the ASCII sum
    while (getline(file, line)) 
    {
        sum += sum_ascii(line);
    }

    file.close();

    // Comment #4: Output the total ASCII sum
    cout << "Total ASCII sum: " << sum << endl;

    return 0;
}

// Comment #5: Function definition for sum_ascii
int sum_ascii(string str)
{
    int sum = 0;
    for (char c : str) 
    {
        // Comment #6: Add the ASCII value of each character to sum
        sum += (int) c;
    }
    
    return sum;
}

// Milestone 2