class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int> count(26, 0);
        for (auto i : word) {
            // for lowercase
            if (i >= 'a' && i <= 'z') {
                count[i - 'a']++;
            }
        }
        for (auto i : word) {
            if (i >= 'A' && i <= 'Z' && count[i - 'A'] > 0) {
                // for uppercase check if lower count > 0
                // then increment ans and update count = 0 
                // this is to avoid duplicates count
                ans++;
                count[i - 'A'] = 0;
            }
        }
        return ans;
    }
};