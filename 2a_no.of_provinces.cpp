//https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int n) {
        // code here
         vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        }
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            c++;
            dfs(i,adj,vis);
        }
    }
    return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
