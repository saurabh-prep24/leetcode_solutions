class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int totalSum = (n*(n+1))/2;
        // int sum = 0;
        // for(auto i:nums){
        //     sum+= i;
        // }
        // return totalSum - sum;

        /*
            x^0 = x
            x^x = 0
            x^y = y^x
            so do xor with all elem once from 0 to n
            then xor with arr[i] so cancel occurring elem
            last remaining will be missing
        */
        int ans = 0;
        for(int i=0;i<=nums.size();i++){
            ans = ans^i;
        }
        for(auto i:nums){
            ans = ans^i;
        }
        return ans;
    }
};