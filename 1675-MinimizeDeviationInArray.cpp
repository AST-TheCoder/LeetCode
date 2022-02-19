class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int mn=INT_MAX,mx=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) nums[i]*=2;
            q.push(nums[i]);
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        
        int ans=mx-mn;
        
        while(!(q.top()%2)){
            int val=q.top()/2;
            q.pop();
            mn=min(mn,val);
            mx=max(q.top(),val);
            ans=min(ans,mx-mn);
            q.push(val);
        }
        
        return ans;
    }
};