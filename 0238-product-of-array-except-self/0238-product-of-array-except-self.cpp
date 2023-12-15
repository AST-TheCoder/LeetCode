class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i=0,mul=1;i<nums.size();i++){
            ans.push_back(mul);
            mul*=nums[i];
        }
        for(int i=nums.size()-1,mul=1;i>=0;i--){
            ans[i]*=mul;
            mul*=nums[i];
        }
        return ans;
    }
};