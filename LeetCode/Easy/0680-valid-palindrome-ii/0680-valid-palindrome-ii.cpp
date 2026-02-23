class Solution {
public:
    bool check(string s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return 0;
            }
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                if(check(s, l+1, r) || check(s, l, r-1)){
                    return 1;
                }else{
                    return 0;
                }
            }
        }
        return 1;
    }
};