class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        // count char in s
        vector<int> count(26, 0);
        for (auto i : s) {
            count[i - 'a']++;
        }

        // count char in target
        vector<int> countTar(26, 0);
        for (auto i : target) {
            countTar[i - 'a']++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            // ans will be min occurrence of count[i]/countTar[i]
            if (countTar[i] > 0) {
                int occ = count[i] / countTar[i];
                ans = min(ans, occ);
            }
        }
        return ans;
    }
};