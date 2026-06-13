class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto s : words) {
            int w = 0;
            for (int j = 0; j < s.size(); j++) {
                w += weights[s[j] - 'a'];
            }
            ans += 'z' - w % 26;
        }
        return ans;
    }
};