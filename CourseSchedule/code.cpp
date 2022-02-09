class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& v) {
      int n= v.size();
        
        vector<int> in(V,0);
       
        for(int i=0;i<n;i++){
            in[v[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        vector<vector<int>> adj(V);
        
        
        for(int i=0;i<n;i++){
            adj[v[i][1]].push_back(v[i][0]);
        }
        
        
        while(! q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for(int j=0;j<adj[val].size();j++){
                in[adj[val][j]]--;
                if(in[adj[val][j]]==0){
                    q.push(adj[val][j]);
                }
            }
            
        }
        
        if(ans.size()!= V){
            ans.clear();
        }
        
        return ans;
    }
};