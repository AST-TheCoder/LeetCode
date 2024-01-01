class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        sum = (sum*(sum+1))/2;
        for(int i=0;i<nums.size();i++) sum-=nums[i];
        return sum;
    }
};