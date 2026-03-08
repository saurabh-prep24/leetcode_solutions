class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> unique;
        int n = nums.size();
        for (auto i : nums) {
            unique.insert(i);
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            string s(n, '0');
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    s[i] = '1';
                }
            }
            if (unique.find(s) == unique.end()) {
                return s;
            }
        }
        // for(auto i:unique){
        //     cout<<i<<endl;
        // }
        return "";
    }
};