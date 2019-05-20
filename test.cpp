#include <iostream>
using namespace std;
int main() {
    int c = 1;
    int a[10] = {c};
    for (int c : a) {
        cout << c << endl;
    }
}
