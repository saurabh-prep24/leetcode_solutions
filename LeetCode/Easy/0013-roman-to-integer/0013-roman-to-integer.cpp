class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> getVal;
        getVal['I'] = 1;
        getVal['V'] = 5;
        getVal['X'] = 10;
        getVal['L'] = 50;
        getVal['C'] = 100;
        getVal['D'] = 500;
        getVal['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            // cout<<s[i]<<getVal[s[i]]<<endl;
            if (i + 1 < s.size() && getVal[s[i]] < getVal[s[i + 1]]) {
                ans -= getVal[s[i]];
            } else {
                ans += getVal[s[i]];
            }
        }
        // ans += getVal[s[s.size()-1]];
        return ans;
    }
};