class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        // store count for each chars
        for (auto c : word) {
            count[c - 'a']++;
        }

        // sort in decreasing
        sort(count.begin(), count.end(), greater<int>());

        int ans = 0;
        // curr press count
        int press = 0;
        for (int i = 0; i < 26; i++) {
            // first non-zero then exit
            if (count[i] == 0) {
                break;
            }

            // if factor of 8 then press increment
            if (i % 8 == 0) {
                press++;
            }

            // add count of c * press
            ans += (count[i] * press);
        }
        return ans;
    }
};