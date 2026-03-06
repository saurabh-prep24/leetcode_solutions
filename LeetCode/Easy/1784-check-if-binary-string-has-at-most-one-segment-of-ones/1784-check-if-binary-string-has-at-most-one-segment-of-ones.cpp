class Solution {
public:
    bool checkOnesSegment(string s) {
        int l = 0, maxi=0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if(maxi > 0){
                    return 0;
                }
                l++;
            } else {
                maxi = max(l, maxi);
                l = 0;
            }
        }
        maxi = max(maxi, l);
        return maxi > 0;
    }
};