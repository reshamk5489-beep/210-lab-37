#include <iostream>
using namespace std;

int sum_ascii(string str);

int main() 
{
    int sum = sum_ascii("Hello");
    cout << sum << endl;

    return 0;
}

int sum_ascii(string str)
{
    int sum = 0;
    for (char c : str) 
    {
        sum += (int) c;
    }
    
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

// Milestone 1
