class Solution {
public:
    bool ans=true;
    int v[101]={0};
    int col[101]={-1};
    
    void dfs(vector<vector<int>>& g,int i, int color){
        if(v[i]){
            if(color!= col[i]){
             // cout<<i<<" ";
                ans=false;  
            }
            return;
        }
        v[i]=1;
        int acol=-1;
        col[i]=color;
        if (color==0) acol=1;
        else acol= 0;
        for(int j=0;j<g[i].size();j++){
            dfs(g,g[i][j],acol);
        }
        
    }
    
    
    bool isBipartite(vector<vector<int>>& g) {
        for(int i=0;i<g.size();i++){
            if(!v[i]){
               // cout<<i<<" ";
                dfs(g,i,0);   
            }
        }
        return ans;
    }
};