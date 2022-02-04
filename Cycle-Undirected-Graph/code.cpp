// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<int> v;
    bool ans=false;
    void dfs(vector<int> adj[], int i, int prev){
        if(v[i]){
            // cout<<i<<" ";
            ans=true;
            return;
        }
        
        v[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]==prev){
                continue;
            }
            dfs(adj,adj[i][j],i);
        }        

        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        v.resize(V+1);
        fill(v.begin(),v.end(),0);
        for(int i=0;i<V;i++){
            if(!v[i])
            dfs(adj,i,i);
        }
        return ans;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends