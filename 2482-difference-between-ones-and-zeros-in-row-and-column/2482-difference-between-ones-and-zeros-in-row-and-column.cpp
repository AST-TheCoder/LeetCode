class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow,zerosRow,onesCol,zerosCol;
        for(int i=0;i<grid.size();i++){
            int ones=0;
            for(int j=0;j<grid[i].size();j++) ones+=grid[i][j];
            onesRow.push_back(ones);
            zerosRow.push_back(grid[i].size()-ones);
        }
        for(int j=0;j<grid[0].size();j++){
            int ones=0;
            for(int i=0;i<grid.size();i++) ones+=grid[i][j];
            onesCol.push_back(ones);
            zerosCol.push_back(grid.size()-ones);
        }
        vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++){
            vector<int> ret;
            for(int j=0;j<grid[i].size();j++){
                ret.push_back(onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j]);
            }
            ans.push_back(ret);
        }
        return ans;
    }
};