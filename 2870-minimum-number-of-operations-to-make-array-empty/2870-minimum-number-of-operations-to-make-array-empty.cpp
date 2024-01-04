class Solution {
public:
    int cnt[1000001];
    int minOperations(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt));
        int c = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]==1) c++;
            else if(cnt[nums[i]] == 2) c--;
            if(cnt[nums[i]]%3 == 1) ans++;
        }
        if(c) return -1;
        return ans;
    }
};