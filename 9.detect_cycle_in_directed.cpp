//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,int vis[],int vispath[],vector<int>adj[]){
        vis[node]=1;
        vispath[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,vispath,adj)==true) return true;
            }
            else if(vispath[it]) return true;
        }
        vispath[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        int vis[n]={0};
        int vispath[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,vispath,adj)==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
