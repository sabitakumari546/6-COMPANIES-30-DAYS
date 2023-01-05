class Solution {
public:
    void AliceDfs(int node,int par,int dis,vector<int> &parent,
                  vector<int> &distance, vector<int> adj[])
    {
        parent[node]=par;
        distance[node]=dis;
        for(auto it : adj[node])
        {
            if(it!=par) AliceDfs(it,node,dis+1,parent,distance,adj);
        }
    }
    void BobDfs(int node,int dis,vector<int> &amount,
                  vector<int> &distance,vector<int> &parent, vector<int> adj[])
    {
        if(dis<distance[node]) amount[node]=0;
        if(dis==distance[node]) amount[node] /=2;
        if(node==0) return ;
        BobDfs(parent[node],dis+1,amount,distance,parent,adj);
    }
    int CollectAmount(int node,vector<int> &amount,vector<int> &visited,
                      vector<int> adj[])
    {
        visited[node]=1;
        int res = amount[node];
        int maxi=INT_MIN;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            maxi=max(maxi,CollectAmount(it,amount,visited,adj)); 
            
        }
        if(maxi==INT_MIN) return res;
        return res + maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = edges.size()+1;
        vector<int> adj[n];
        vector<int> parent(n,0);
        vector<int> visited(n,0);
        vector<int> distance(n,0);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        AliceDfs(0,0,0,parent,distance,adj);
        BobDfs(bob,0,amount,distance,parent,adj);
        return CollectAmount(0,amount,visited,adj);
    }
};