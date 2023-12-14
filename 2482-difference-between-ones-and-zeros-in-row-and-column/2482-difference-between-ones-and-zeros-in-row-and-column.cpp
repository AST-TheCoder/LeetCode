class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> onesRow(n),onesCol(m);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                onesRow[i]+=grid[i][j];
                onesCol[j]+=grid[i][j];
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++){
            vector<int> ret;
            for(int j=0;j<grid[i].size();j++){
                ret.push_back(2*(onesRow[i]+onesCol[j])-grid[i].size()-grid.size());
            }
            ans.push_back(ret);
            ret.clear();
        }
        return ans;
    }
};