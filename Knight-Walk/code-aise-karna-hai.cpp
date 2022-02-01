// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define ll int
#define ff first
#define ss second

class Solution {
public:

    vector<pair<ll,ll>> a = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    bool safe(ll x,ll y,ll n)
    {
        if(x>=1 && x<=n && y>=1 && y<=n)
            return true;
        else
            return false;
    }
	int minStepToReachTarget(vector<int>&k, vector<int>&t, int n)
	{
        queue<pair<pair<ll,ll>,ll>> q;
        q.push({{k[0],k[1]},0});
        vector<vector<ll>> v(n+1,vector<ll> (n+1,0));
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            if(it.ff.ff==t[0] && it.ff.ss==t[1])
            {
                return it.ss;
            }
            for(ll i=0;i<8;i++)
            {
                ll x,y,z;
                x = it.ff.ff+a[i].ff;
                y = it.ff.ss+a[i].ss;
                z = it.ss;
                if(safe(x,y,n))
                {
                    if(v[x][y]==0)
                    {
                        v[x][y] = 1;
                        q.push({{x,y},z+1});
                    }
                }
            }
        }
        return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends