class Solution {
public:
    int v[500][500];
    vector<pair<int,int>> a={{1,0},{-1,0},{0,1},{0,-1}};
    bool safe(int i, int j, int r, int c){
        if(i>=0 && i<r && j>=0 && j<c)
            return true;
        return false;
    }
    void dfs(vector<vector<char>>& b,vector<vector<char>>& ans,int i, int j){
        int r=b.size();
        int c=b[0].size();
        if(v[i][j]){
            return;
        }
        v[i][j]=1;
        ans[i][j]='O';
        cout<<"\n"<<i<<" "<<j;
        cout<<"\n";
        for(int k=0;k<4;k++){
            int x=i+a[k].first;
            int y=j+a[k].second;
            if(!safe(x,y,r,c)){
                continue;
            }
            if(b[x][y]=='O'){
                // cout<<i<<" "<<j<<"= "<<x<<" "<<y;
           
                dfs(b,ans,x,y);
            }
            
        }
    }
    void solve(vector<vector<char>>& b) {
        int r=b.size();
        int c=b[0].size();
        vector<vector<char>> ans(r,vector<char>(c));
        for(int i=0;i<r;i++)
        fill(ans[i].begin(),ans[i].end(),'X');
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0|| i==r-1 || j==c-1){
                    if(b[i][j]=='O')
                    {
                        // cout<<"----"<<i<<" "<<j;
                        dfs(b,ans,i,j);
                    }
                }
            }
        }
        b=ans;
    }
};