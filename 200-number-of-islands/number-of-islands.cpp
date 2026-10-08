class Solution {
public:
void dfs(int i,int j, vector<vector<bool>>& vis,vector<vector<char>>& grid,int n,int m)
{
    // base case
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==true || grid[i][j]=='0')
    {return;}


    vis[i][j]=true;

    dfs(i,j-1,vis,grid,n,m);//left
    dfs(i,j+1,vis,grid,n,m);//right
    dfs(i-1,j,vis,grid,n,m);//top
    dfs(i+1,j,vis,grid,n,m);//bottom
}
    int numIslands(vector<vector<char>>& grid) {
         

        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==false)
                {
                    count++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        cout<<count;
        return count;
        
    }
};