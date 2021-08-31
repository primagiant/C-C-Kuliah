#include <iostream>
#include <string>
using namespace std;

/*** 
Input Format

You are given two strings,  and , separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of  and  respectively.
In the second line print the string produced by concatenating  and  ().
In the third line print two strings separated by a space,  and .  and  are the same as  and , respectively, except that their first characters are swapped. 
***/

int main() {
    // get input from user
    string a, b;
    cin >> a;
    cin >> b;

    // print size of a and b
    cout << a.size() << " " << b.size() << endl;

    // print union of a and b
    cout << a + b << endl;

    // swap first char on string
    string swap;
    swap[0] = a[0];
    a[0] = b[0];
    b[0] = swap[0];

    cout << a << " " << b << endl;

    return 0;
}