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
        int setA =  getSetBits(a);
        int setB =  getSetBits(b);
        if (setA == setB){
            return a<b;
        }
        return setA < setB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};