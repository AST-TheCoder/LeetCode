class Solution {
public:
    
    int solve(vector<int>& dp, vector<pair<pair<int,int>,pair<int,int>>>& chk, int pos, int n){
        if(pos==n) return 0;
        if(dp[pos]!=INT_MAX) return dp[pos];
        
        dp[pos]=solve(dp, chk, chk[pos].first.second+1, n)+chk[pos].first.first;
        if(chk[pos].second.first!=-1)
            dp[pos]=min(dp[pos],solve(dp, chk, chk[pos].second.second+1, n)+chk[pos].second.first);
        return dp[pos];        
    }
    
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int diff[boxes.size()];
        vector<pair<pair<int,int>,pair<int,int>>> chk;
        vector<int> dp;
        for(int i=0;i<boxes.size();i++){
            chk.push_back({{-1,-1},{-1,-1}});
            dp.push_back(INT_MAX);
            if(i==0) diff[i]=-1;
            else{
                if(boxes[i][0]==boxes[i-1][0]) diff[i]=diff[i-1];
                else diff[i]=i-1;
            }
        }
        
        for(int i=0,j=0,weight=0,trips=1;j<boxes.size();i++){
            weight+=boxes[i][1];
            if(i+1<boxes.size() && weight+boxes[i+1][1]<=maxWeight && i-j+2<=maxBoxes){
                if(boxes[i][0]!=boxes[i+1][0]) trips++;
                continue;
            }
            chk[j].first={trips+1,i};
            if(diff[i]>=j) chk[j].second={trips,diff[i]};
            weight-=boxes[j][1];
            
            if(i>j){
                if(boxes[j][0]!=boxes[j+1][0]) trips--;
                weight-=boxes[i][1];
                i--;
            }
            j++;
        }
        
        return solve(dp, chk, 0, (int)boxes.size());
    }
};
