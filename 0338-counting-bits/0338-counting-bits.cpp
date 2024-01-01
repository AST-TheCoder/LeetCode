class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        while(ans.size()!=n+1){
            int sz=ans.size();
            for(int i=0;i<sz && ans.size()!=n+1;i++) ans.push_back(ans[i]+1);
        }
        return ans;
    }
};