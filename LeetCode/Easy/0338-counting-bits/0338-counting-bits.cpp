class Solution {
public:
    int getSetBits(int n){
        int a=0;
        while(n){
            n = n&(n-1);
            a++;
        }
        return a;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i] = getSetBits(i);
        }
        return ans;
    }
};