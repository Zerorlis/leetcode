#include <exception>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        if (s.back() > 'A' && s.back() < 'z') return false;
        if (s.find(' ') != string::npos) return false;
        try {
            stod(s);
        } catch (exception e) {
            cout << e.what();
            return false;
        }
        return true;
    }
};
