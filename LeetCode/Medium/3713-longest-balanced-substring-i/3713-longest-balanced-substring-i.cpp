class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        for (int start = 0; start < s.size() - 1; start++) {
            vector<int> count(26, 0);
            for (int end = start; end < s.size(); end++) {
                count[s[end] - 'a']++;

                int tempCount = 0;
                bool fixedCount = 1;
                for (int i = 0; i < 26; i++) {
                    if (count[i] > 0 && tempCount == 0) {
                        tempCount = count[i];
                    }
                    if (count[i] > 0 && tempCount > 0 &&
                        count[i] != tempCount) {
                        fixedCount = 0;
                        break;
                    }
                }

                if (tempCount > 0 && fixedCount) {
                    ans = max(ans, end - start + 1);
                }
            }
        }
        return ans;
    }
};