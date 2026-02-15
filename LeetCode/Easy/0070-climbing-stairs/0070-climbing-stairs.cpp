class Solution {
public:
    int rec(int n){
        if(n<0) return 0;
        if(n<2){
            return 1;
        }
        return rec(n-1)+rec(n-2);
    }
    int recDp(int n, vector<int> &dp){
        if(n<0) return 0;
        if(n<2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=recDp(n-1, dp)+recDp(n-2, dp);
    }

    int tab(int n){
        if(n<0) return 0;
        if(n<2){
            return 1;
        }
        vector<int> dp(n+1, -1);
        dp[0]=dp[1]=1;
        for(int m=2; m<=n ; m++ ){
            dp[m]=dp[m-1]+dp[m-2];
        }
        return dp[n];
    }
    int tabSpace(int n){
        // space opt DP bottom up approach
        int a=1, b=1;
        for(int i=2; i<=n; i++){
            int t = a;
            a=a+b;
            b=t;
        }
        return a;
    }
    int climbStairs(int n) {
        // f(n) = f(n-1)[ans with n-1 steps] + f(n-2)
        if(n<2){
            return n;
        }

        // return rec(n);
        // vector<int> dp(n+1, -1);
        // return recDp(n, dp);
        // return tab(n);
        return tabSpace(n);
    }
};