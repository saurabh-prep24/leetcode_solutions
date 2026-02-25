class Solution {
public:
    static int getSetBits(int n){
        int a=0;
        while(n){
            n = n&(n-1);
            a++;
        }
        return a;
    }

    static bool compare(int &a, int &b){
        if (getSetBits(a) == getSetBits(b)){
            return a<b;
        }
        return getSetBits(a) < getSetBits(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};