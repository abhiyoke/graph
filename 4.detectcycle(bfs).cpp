//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
  bool detcycle(int st,vector<int>adj[],int vis[]){
      queue<pair<int,int>>q;
      vis[st]=1;
      q.push({st,-1});
      while(!q.empty()){
          int par=q.front().second;
          int node=q.front().first;
          q.pop();
          for(auto it:adj[node]){
              if(!vis[it]){
                  vis[it]=1;
                  q.push({it,node});
              }
              else if(par!=it) return true;
          }
        
      }
        return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        int vis[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
              if(detcycle(i,adj,vis)){
                  return true;
              }
            }
        }
        return false;
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
