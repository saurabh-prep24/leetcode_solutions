class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(auto i:s){
            mp[i]++;
        }
        int oddCount = 0;
        for(auto i: mp){
            if(i.second % 2 != 0){
                oddCount++;
            }
        }
        return oddCount > 0 ? s.size()-oddCount+1: s.size();

    }
};