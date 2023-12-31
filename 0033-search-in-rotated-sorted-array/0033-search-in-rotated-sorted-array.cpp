class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1, l = 0, r = nums.size() - 1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m] == target){
                ans = m;
                break;
            }
            if(nums[m] > nums[r]){
                if(target > nums[m]) l = m+1;
                else if (target <= nums[r]) l = m+1;
                else r = m-1;
            }
            else if(nums[m] < nums[l]){
                if(target >= nums[l]) r = m-1;
                else if(target > nums[m]) l = m+1;
                else r = m-1;
            }
            else{
                if(target>nums[m]) l = m+1;
                else r = m-1;
            }
        }
        return ans;
    }
};