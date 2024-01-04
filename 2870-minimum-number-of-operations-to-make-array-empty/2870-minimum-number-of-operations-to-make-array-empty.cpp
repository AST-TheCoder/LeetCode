class Solution {
public:
    int cnt[1000001];
    int minOperations(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }
        int ans=0;
        for(int i=1;i<=1000000;i++){
            if(cnt[i]==1) return -1;
            ans+=cnt[i]/3 + (cnt[i]%3!=0);
        }
        return ans;
    }
};