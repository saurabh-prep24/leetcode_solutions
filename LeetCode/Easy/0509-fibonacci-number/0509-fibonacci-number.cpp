class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int a = 1;
        int b = 1;
        for (int i = 2; i <= n; i++) {
            int t = a;
            a = a + b;
            b = t;
        }
        return b;
    }
};