class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubArraySum = INT_MIN;
        for(int i=0, sum=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0) sum = 0;
            maxSubArraySum = max(maxSubArraySum, sum);
        }
        
        if(!maxSubArraySum){
            maxSubArraySum = INT_MIN;
            for(int i=0; i<nums.size();i++)
                maxSubArraySum = max(maxSubArraySum, nums[i]);
        }
        
        return maxSubArraySum;
    }
};