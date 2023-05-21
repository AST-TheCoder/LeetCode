class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    
    void mark_island(vector<vector<int>>& grid, int u, int v){
        grid[u][v]=-1;
        for(int i=0;i<4;i++){
            int p=u+x[i],q=v+y[i];
            if(p>=0 && p<grid.size() && q>=0 && q<grid.size() && grid[p][q]==1){
                mark_island(grid,p,q);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            int ok=0;
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    mark_island(grid,i,j);
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]!=1) continue;
                for(int k=0;k<4;k++){
                    if(i+x[k]>=0 && i+x[k]<grid.size() && j+y[k]>=0 && j+y[k]<grid.size() && grid[i+x[k]][j+y[k]]==0){
                        q.push({i+x[k],j+y[k]});
                        grid[i+x[k]][j+y[k]]=2;
                    }
                }
            }
            //cout<<endl;
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int temp_x=p.first+x[i];
                int temp_y=p.second+y[i];
                if(temp_x>=0 && temp_x<grid.size() && temp_y>=0 && temp_y<grid.size()){
                    if(grid[temp_x][temp_y]==-1) ans=min(ans,grid[p.first][p.second]-1);
                    if(!grid[temp_x][temp_y]){
                        grid[temp_x][temp_y]=grid[p.first][p.second]+1;
                        q.push({temp_x,temp_y});
                    }
                }
            }
        }
        
        return ans;
    }
};