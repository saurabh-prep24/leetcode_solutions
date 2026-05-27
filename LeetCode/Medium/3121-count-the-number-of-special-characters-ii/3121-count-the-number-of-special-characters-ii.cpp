class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c >= 'A' && c <= 'Z') {
                cout << i << c << endl;
                if (lower[c - 'A'] != -1 && lower[c - 'A'] < i) {
                    ans++;
                }
                lower[c - 'A'] = -1;
            }
        }
        return ans;
    }
};