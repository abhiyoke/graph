//https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int start,int col,int vis[],vector<int>adj[]){
        vis[start]=col;
        vector<pair<int,int>>vec;
        for(auto it:adj[start]){
            if(vis[it]==-1){
                if(dfs(it,!col,vis,adj)==false) return false;
            }
            else if(vis[it]==vis[start]) return false;
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    int vis[n];
	    for(int i=0;i<n;i++) vis[i]=-1;
	    for(int i=0;i<n;i++){
	        if(vis[i]==-1) if(dfs(i,0,vis,adj)==false) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
