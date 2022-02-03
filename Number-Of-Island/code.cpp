class Solution {
public:
    vector<pair<int,int>> a={{1,0},{-1,0},{0,1},{0,-1}};
    bool safe(int x, int y, int r, int c){
        if(x>=0 && x<r && y>=0 && y<c){
            return true;
        }
        return false;
    }
    int v[301][301]={0};
    
    void dfs(vector<vector<char>> &g, int i, int j){
        if(v[i][j])
            return;
        int r=g.size();
        int c=g[0].size();
        v[i][j]=1;
        // cout<<g[i][j]<<" ";
        for(int k=0;k<4;k++){
            int x=i+a[k].first;
            int y=j+a[k].second;
            if(!safe(x, y, r, c)){
                continue;
            }
            int h=(int)g[x][y];
            if(h==48){
                continue;
            }
            //cout<<h<<" ";
            dfs(g,x,y);
        }
    }
    
    int numIslands(vector<vector<char>> &g) {
        int r=g.size();
        int c=g[0].size();
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int h=(int)g[i][j];
                //cout<<h<<" ";
                if(!v[i][j] && h== 49){
                    cnt++;
                dfs(g,i,j);
                }
                // cout<<"\n";
            }
        }
        return cnt;
    }
};