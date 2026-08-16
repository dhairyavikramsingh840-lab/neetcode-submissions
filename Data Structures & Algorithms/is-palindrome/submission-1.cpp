#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(static_cast<unsigned char>(s[i]));
            }
        }

        string t = "";
        string n = "";

        for (int i = 0; i < s.length(); ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                t += s[i];
            }
        }

     
        for (int i = s.length()-1; i >= 0; --i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                n += s[i];
            }
        }

      
        for (int i = 0; i < t.length(); ++i) {
            if (t[i] != n[i]) {
                return false;
            }
        }

        return true;
    }
};