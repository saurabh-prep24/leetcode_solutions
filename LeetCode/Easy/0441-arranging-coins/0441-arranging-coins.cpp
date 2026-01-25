class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int ans = 0;
        while(n-i >= 0){
            n = n-i;
            i++;
            ans++;
        }
        return ans;
    }
};