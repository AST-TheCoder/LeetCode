class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> cnt;
        string ans;
        for(int i=0;i<paths.size();i++){
            cnt[paths[i][0]]++;
            cnt[paths[i][1]]--;
        }
        for(int i=0;i<paths.size();i++){
            if(cnt[paths[i][1]]==-1){
                ans=paths[i][1];
                break;
            }
        }
        return ans;
    }
};