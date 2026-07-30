class Solution {
public:
    int minimumPushes(string word) {
        int push = 0, n = word.size();
        for (int i = 0; i < n; i++) {
            push += (i / 8) + 1;
        }
        return push;

        // 8 buttons - so keep all first letters on all 8
        // then another round will have 1 more tap for next 8 letters
        // since all unique letters so no hash map for keeping visited letter
        // all letters all first time only
        int count = 1;
        int len = word.size();
        int ans = 0;
        while (len > 0) {
            ans += (len <= 8 ? len * count : 8 * count);
            len -= 8;
            count++;
        }
        return ans;
    }
};