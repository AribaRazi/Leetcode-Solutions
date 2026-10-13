class Solution {
public:

bool dfsCycle(int src, vector<bool>&vis,vector<vector<int>>& edges,vector<bool>&recPath)
{
    vis[src]=true;
    recPath[src]=true;
    //edges
    for(int i=0;i<edges.size();i++)
    {
        int v=edges[i][0];
        int u=edges[i][1];

        if(u==src)
        {
            if(vis[v]==false)
            {
                if(dfsCycle(v,vis,edges,recPath))
                {return true;}
            }
            else if(recPath[v])// back edge condition for directed graph
            {
             return true;
            }  
        }
        
    }
    recPath[src]=false;
    return false;
}

void topo(int src,vector<bool>&vis,vector<vector<int>>& edges,stack<int>&st)
{
    vis[src]=true;
    //edges
    for(int i=0;i<edges.size();i++)
    {
        int v=edges[i][0];
        int u=edges[i][1];

        if(u==src)
        {
            if(vis[v]==false)
            {
                topo(v,vis,edges,st);
            }
        }
        
    }
    st.push(src);
}
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                if(dfsCycle(i,vis,edges,recPath))
                {return ans;}
            }
        }

        stack<int>st;
        vis.assign(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                topo(i,vis,edges,st);
            }
        }
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};