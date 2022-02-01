// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pb push_back
 vector<pair<int,int>> adj[1000][1000];
class Solution {
public:
   
   
    int BFS(int N,  pair<int,int> k, pair<int,int> t){
    int  visited[N+1][N+1], dist[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            visited[i][j]=0;
        }
    }
    
    if(k.first==t.first && k.second == t.second){
        return 0;
    }
    
    queue<pair<int,int>> q;
    q.push(k);
	visited[k.first][k.second]=1;
	dist[k.first][k.second]=0;
	
	while(! q.empty()){
		pair<int,int> val=q.front();
		//cout<<val.first<<","<<val.second<<" ";
		
		
		q.pop();

		for(int i=0;i<adj[val.first][val.second].size();i++){
			if(!visited[adj[val.first][val.second][i].first][adj[val.first][val.second][i].second]){
				q.push(adj[val.first][val.second][i]);
				visited[adj[val.first][val.second][i].first][adj[val.first][val.second][i].second]=1;
			    dist[adj[val.first][val.second][i].first][adj[val.first][val.second][i].second] = 
			    dist[val.first][val.second]+1;
			    
			    if(adj[val.first][val.second][i].first == t.first && adj[val.first][val.second][i].second== t.second){
			        return dist[adj[val.first][val.second][i].first][adj[val.first][val.second][i].second];
			    }
			}
		}

	}
	
	return -1;
        
    }


	int minStepToReachTarget(vector<int>&KP, vector<int>&TP, int N){
	    // Code here
	    
	   for(int i=0;i<1000;i++){
	       for(int j=0;j<1000;j++){
	           adj[i][j].clear();
	       }
	   }
	   
	   
	   pair<int,int> k,t;
	   k={KP[0],KP[1]};
	   t={TP[0],TP[1]};
	   
	   for(int i=1;i<=N;i++){
	       for(int j=1;j<=N;j++){
	           if(i+2 <= N){
	               if(j+1 <= N){
	                   adj[i][j].pb({i+2,j+1});
	               }
	               if(j-1>0){
	                   adj[i][j].pb({i+2,j-1});
	               }
	           }
	           
	           if(i-2>0){
	               if(j+1<= N){
	                   adj[i][j].pb({i-2,j+1});
	               }
	               if(j-1>0){
	                   adj[i][j].pb({i-2,j-1});
	               }
	           }
	           
	           if(j+2<=N){
	               if(i+1 <= N){
	                   adj[i][j].pb({i+1,j+2});
	               }
	               if(i-1>0){
	                   adj[i][j].pb({i-1,j+2});
	               }
	           }
	           
	           if(j-2>0){
	               if(i+1 <=N){
	                   adj[i][j].pb({i+1,j-2});
	               }
	               if(i-1>0){
	                   adj[i][j].pb({i-1,j-2});
	               }
	           }
	           
	           
	       }
	   }
	   
	   
	   int ans= BFS(N,k,t);
	   
	   return ans;
	    
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