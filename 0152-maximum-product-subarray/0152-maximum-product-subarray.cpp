class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans=0,mxPP = 1, mxNP = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]){
                mxPP = 1;
                mxNP = INT_MIN;
                continue;
            }
            mxPP*=nums[i];
            if(mxPP > 0) ans=max(ans,mxPP);
            else{
                
                ans = max(ans, mxPP/mxNP);
                mxNP = max(mxNP, mxPP);
            }
        }
        return ans;
    }
};