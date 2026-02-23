class Solution {
public:
    bool validPalindrome(string s) {
        int count[26] = {0};
        for (auto i : s) {
            count[i - 'a']++;
        }
        char mismatch = '0';
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                mismatch = i + 'a';
                break;
            }
        }

        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }

            if (mismatch != '0' && s[i] == mismatch) {
                i++;
            } else if (mismatch != '0' && s[j] == mismatch) {
                j--;
            } else
                return 0;
        }
        return 1;
    }
};