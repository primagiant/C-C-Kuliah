#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    vector<int> tmp;
    stringstream ss(str);
    char ch;
    int a, b, c;

    while (ss >> a) {
        ss >> ch;
        tmp.push_back(a);
    }
    return tmp;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}