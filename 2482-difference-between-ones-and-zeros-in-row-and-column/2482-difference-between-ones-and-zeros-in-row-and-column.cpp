class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow,onesCol;
        for(int i=0;i<grid.size();i++){
            int ones=0;
            for(int j=0;j<grid[i].size();j++) ones+=grid[i][j];
            onesRow.push_back(ones);
        }
        for(int j=0;j<grid[0].size();j++){
            int ones=0;
            for(int i=0;i<grid.size();i++) ones+=grid[i][j];
            onesCol.push_back(ones);
        }
        vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++){
            vector<int> ret;
            for(int j=0;j<grid[i].size();j++){
                ret.push_back(2*(onesRow[i]+onesCol[j])-grid[i].size()-grid.size());
            }
            ans.push_back(ret);
        }
        return ans;
    }
};