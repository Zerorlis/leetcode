#include <climits>
#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << string::npos << endl;
    cout << string::npos + 1 << endl;
    cout << (string::npos == string::npos + 1);
}
