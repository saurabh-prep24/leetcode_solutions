class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for (auto i : text) {
            count[i - 'a']++;
        }

        string target = "balloon";
        vector<int> countTar(26, 0);
        for (auto i : target) {
            countTar[i - 'a']++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (countTar[i] > 0) {
                int occ = count[i] / countTar[i];
                ans = min(ans, occ);
            }
        }
        return ans;
    }
};