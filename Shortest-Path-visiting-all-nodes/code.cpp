class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        queue<pair<int,int>> q;
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<g.size();i++){
          q.push({i,1<<i});
            mp[{i,1<<i}]=1; // current status of a node (bits denoting the path)
        }
        
        int ans=0;
        
        while(! q.empty()){
            int n=q.size();
            while(n--){
            int val=q.front().first;
            int status=q.front().second;
            q.pop();
            if(status == ((1<<g.size())-1)) return ans; //check if all are one
                
                for(int j=0;j<g[val].size();j++){
                    int  nstatus= status | 1<<g[val][j];
                    if(mp[{g[val][j],nstatus}]!=1){      //condition check for visited node with same status
                        q.push({g[val][j],nstatus});
                        mp[{g[val][j],nstatus}]=1;
                    }
                }
            
            }
            ans++;
        }
       return -1; 
    }
};