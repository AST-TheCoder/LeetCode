class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        pair<int,int> nums_with_pos[n];
        for(int i=0;i<n;i++){
            nums_with_pos[i].first=nums[i];
            nums_with_pos[i].second=i;
        }
        
        sort(nums_with_pos,nums_with_pos+n);
        
        vector<int> ans;

        for(int i=0,j=n-1;i<j;){
            if(nums_with_pos[i].first+nums_with_pos[j].first<target) i++;
            else if(nums_with_pos[i].first+nums_with_pos[j].first>target) j--;
            else{
                ans.push_back(nums_with_pos[i].second);
                ans.push_back(nums_with_pos[j].second);
                break;
            }
        }
        
        return ans;
    }
};