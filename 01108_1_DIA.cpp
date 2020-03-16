#include <string>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        return replaceAll(address, ".", "[.]");
    }
    string& replaceAll(string& str, const string& old_value,
                       const string& new_value) {
        string::size_type pos = 0;
        while (true) {
            pos = str.find(old_value, pos);
            if (pos == string::npos) break;
            str.replace(pos, old_value.size(), new_value);
            pos += new_value.size();
        }
        return str;
    }
};
