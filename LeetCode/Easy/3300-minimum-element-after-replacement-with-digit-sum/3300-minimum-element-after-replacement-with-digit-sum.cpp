class Solution {
public:
    int sumDig(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int miniSum = INT_MAX;
        for (auto i : nums) {
            miniSum = min(miniSum, sumDig(i));
        }
        return miniSum;
    }
};