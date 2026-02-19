class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int curr = 1, prev = 0;
        for (int i = 1; i < s.size(); i++) {
            // compare with prev elem 
            if (s[i] == s[i - 1]) {
                // if same then increase length
                curr++;
            } else {
                // process batch
                ans += min(prev, curr);
                // store curr and set new count 1
                prev = curr;
                curr = 1;
            }
        }
        // final batch
        ans += min(prev, curr);
        // return ans
        return ans;
    }
};