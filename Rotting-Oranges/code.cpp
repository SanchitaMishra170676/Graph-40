#define ff first
#define ss second
class Solution {
public:
     vector<pair<int,int>> a={{0,1},{0,-1},{1,0},{-1,0}};
    bool safe(int x, int y, int r, int c){
        if(x>=0 && x<r && y>=0 && y<c)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c= grid[0].size();
        //cout<<r<<" "<<c<<" ";
        queue<pair<int,int>> q;
        vector<vector<int>> v(r, vector<int>(c,0)),dist(r, vector<int>(c,0)) ;
        int t=0;
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              if(grid[i][j]==2){
                  q.push({i,j});
                  v[i][j]=1;
                  dist[i][j]=0;
              }  
            }
        }
    
        while(! q.empty()){
            auto val = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=val.ff+a[i].ff;
                int y=val.ss+a[i].ss;
                if(! safe(x,y,r,c)){
                    continue;
                }
                
                if(grid[x][y] != 1){
                    continue;
                }
                
                if(! v[x][y]){
                    q.push({x,y});
                    v[x][y]=1;
                    grid[x][y]=4;
                    dist[x][y]=dist[val.ff][val.ss]+1;
                    t=max(t,dist[x][y]);
                }
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //cout<<grid[i][j]<<" ";
              if(grid[i][j]==1){
                 t=-1;
              }  
            }
        }
        
        return t;
        
        
    }
};