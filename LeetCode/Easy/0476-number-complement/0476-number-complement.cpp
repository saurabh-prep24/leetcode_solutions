class Solution {
public:
    int findComplement(int num) {
        int ans = 0, pos = 0;
        while (num > 0) {
            int currBit = !(num & 1);
            ans |= (currBit << pos);

            num = num >> 1;
            pos++;
        }
        return ans;
    }
};