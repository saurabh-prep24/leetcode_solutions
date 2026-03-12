class Solution {
public:
    int findComplement(int num) {
        int ans = 0, pos = 0;
        while (num > 0) {
            if(!(num & 1)){
                ans |=  (1<<pos);
            }
            num = num >> 1;
            pos++;
        }
        return ans;
    }
};