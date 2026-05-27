class Solution {
public:
    int numberOfSpecialChars(string word) {
        // store last index for each lowercase
        vector<int> lower(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                // overwrite to keep last index
                lower[c - 'a'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            // check only now for uppercase
            if (c >= 'A' && c <= 'Z') {
                // if lowercase last index != -1 and < i
                // then increment ans
                if (lower[c - 'A'] != -1 && lower[c - 'A'] < i) {
                    ans++;
                }
                // count this char as invalid now
                // as only first occurrence of upper needs consideration
                lower[c - 'A'] = -1;
            }
        }
        return ans;
    }
};