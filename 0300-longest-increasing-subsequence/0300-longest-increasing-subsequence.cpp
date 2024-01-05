class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        LIS.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            int id = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
            if(id==LIS.size()) LIS.push_back(nums[i]);
            else LIS[id] = nums[i];
        }
        return LIS.size();
    }
};