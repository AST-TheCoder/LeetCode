class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int x[amount+1];
        x[0]=0;
        for(int i=1;i<=amount;i++) x[i]=amount+1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                x[j]=min(x[j],x[j-coins[i]]+1);
            }
        }
        if(x[amount]>amount) x[amount] = -1;
        return x[amount];
    }
};