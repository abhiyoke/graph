//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&list){
        vis[node]=1;
        list.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,list);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        int start=0;
        vector<int>list;
        dfs(start,adj,vis,list);
        return list;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
