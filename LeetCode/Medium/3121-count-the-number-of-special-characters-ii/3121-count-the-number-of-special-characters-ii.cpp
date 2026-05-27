class Solution {
public:
    int solve1(string word) {
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
    int solve2(string word) {
        // store last index for each lowercase
        vector<int> lower(26, -1);
        // store first index for each uppercase
        vector<int> upper(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                // overwrite to keep last index
                lower[c - 'a'] = i;
            } else if (upper[c - 'A'] == -1) {
                upper[c - 'A'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                ans++;
            }
        }
        return ans;
    }
    int numberOfSpecialChars(string word) {
        // return solve1(word);
        return solve2(word);
    }
};