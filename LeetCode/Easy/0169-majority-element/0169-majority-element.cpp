class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // sorting then return mid elem
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];

        // // hashmap
        // map<int,int> countMap;
        // for(auto i: nums) {
        //     countMap[i]++;
        //     if(countMap[i] > nums.size()/2)
        //     {
        //         return i;
        //     }   
        // }
        // return 0;


        // track life of elem - same then +1 else -1
        // as count > n/2 so even if half of non matching cancel majority will win
        int res = INT_MIN, life = 0;
        for(int i=0;i<nums.size();i++){
            if(life == 0){
                res = nums[i];
            }

            life = (res == nums[i]) ? life+1 : life-1;   
            // cout<<res<<" "<<nums[i]<<" "<<life<<" "<<(res == nums[i])<<endl;         
        }
        return res;
    }
};