//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,int parent,int vis[],vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                if(dfs(it,node,vis,adj)==true) return true;
            }
            else if(it!=parent) return true;
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        int vis[n]={0};
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,-1,vis,adj)==true) return true;;
            }
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
