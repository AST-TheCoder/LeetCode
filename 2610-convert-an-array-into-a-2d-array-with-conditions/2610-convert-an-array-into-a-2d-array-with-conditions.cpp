class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int cnt[nums.size()+1], mxCnt = 0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            mxCnt = max(mxCnt, cnt[nums[i]]);
        }
        vector<vector<int>> ans(mxCnt);
        for(int i=0;i<nums.size();i++){
            ans[cnt[nums[i]]-1].push_back(nums[i]);
            cnt[nums[i]]--;
        }
        return ans;
    }
};