#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back 
#define int long long
#define pi 3.14159265358979323846
#define watch(xxx) cerr<<(#xxx)<<" is "<<xxx<<"\n";
using namespace std;

void print_adj(vector<int> adj[], int v){
	for(int i=0;i<=v;i++){
		cout<<i<<"\t";
		int n=adj[i].size();
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void adjacency(vector<int> adj[], int e){
	for (int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}
}




 vector<int> ans,v;
void dfs(vector<int> adj[], int i){
        if(v[i])
            return;
        v[i]=1;
        ans.push_back(i);
        for(int j=0;j<adj[i].size();j++){
            dfs(adj,adj[i][j]);
        }
    }

signed main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,e; 
	cin>>n>>e;
	vector<int> adj[n+1];
	adjacency(adj,e);
	int count =0;
	v.resize(n+1);
	fill(v.begin(),v.end(),0);
	for(int i=1;i<=n;i++){
		if(!v[i]){
			count++;
			watch(count);
		}
		dfs(adj,i);
	}
	cout<<count;
} 