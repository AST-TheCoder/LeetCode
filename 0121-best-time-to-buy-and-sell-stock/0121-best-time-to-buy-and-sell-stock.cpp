class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=prices.size()-2,sell=prices[prices.size()-1];i>=0;i--){
            ans=max(ans,sell-prices[i]);
            sell=max(prices[i],sell);
        }
        return ans;
    }
};