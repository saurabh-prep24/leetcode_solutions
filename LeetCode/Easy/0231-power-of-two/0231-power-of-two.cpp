class Solution {
public:
    bool binPowerTwo(int n){
        return (n&(n-1)) == 0;
    }
    bool isPowerOfTwo(int n) {
        if(n<1)     return 0;

        // while(n>0){
        //     if(n == 1)  return 1;
        //     if(n%2!=0)  return 0;
        //     n/=2;
        // }
        // return 0;

        return binPowerTwo(n);
    }
};