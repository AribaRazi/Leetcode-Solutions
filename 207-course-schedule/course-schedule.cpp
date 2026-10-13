class Solution {
public:
bool dfs(int src, vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>& edge)
{
    vis[src]=true;
    recPath[src]=true;
    for(int i=0;i<edge.size();i++)
    {  
        //finding u and v vertex for each edge
        int v=edge[i][0];
        int u=edge[i][1];

        if(src==u)
        {
            if(vis[v]==false)
            {
               if(dfs(v,vis,recPath,edge)) return true;
            }
            else if(recPath[v]==true)
            {
              return true;
            }
        }
    }
    recPath[src]=false;
    return false;
}

    bool canFinish(int V, vector<vector<int>>& edges) {

        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);

        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                if(dfs(i,vis,recPath,edges))
                {
                    return false;
                }
            }
        }
        return true;
    }
};