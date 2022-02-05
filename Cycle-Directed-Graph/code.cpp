    // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool ans= false;
    vector<int> v;
    void dfs(vector<int> adj[],int i){
        if(v[i]){
            if(v[i]==1)
            ans=true;
            return;
        }
        
        v[i]=1;
        for(int j=0;j<adj[i].size();j++){
            dfs(adj,adj[i][j]);
            v[adj[i][j]]=2;
        }
        v[i]=2;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        v.resize(V+1);
        fill(v.begin(),v.end(),0);
        
        for(int i=0;i<V;i++){
            if(v[i]==0){
                dfs(adj,i);
            }
        }
        return ans;
        
        
    }
};


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