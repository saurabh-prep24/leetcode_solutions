class Solution {
    bool isValidChar(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||
               c >= '0' && c <= '9';
    }

public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isValidChar(s[i])) {
                i++;
            } else if (!isValidChar(s[j])) {
                j--;
            } else if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            } else
                return 0;
        }
        return 1;
    }
};