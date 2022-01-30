#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Graph {
    public:
    vector<int> *adj;
    vector<int> visited;
    vector<int> distance;
    int n;
        Graph(int n) {
            adj = new vector<int>[n+1];
            visited.resize(n+1,0);
            distance.resize(n+1,-1);
            this->n=n;
        }
    
        void add_edge(int u, int v) {
            //one-based index
            adj[u+1].pb(v+1);
            adj[v+1].pb(u+1);
            
        }
        
        vector<int> shortest_reach(int start) {
            start++; //one -based index
            visited[start]=1;
            queue<int> q;
            q.push(start);
            distance[start]=0;
            while(!q.empty()){
                int val =q.front();
                
                q.pop();
                for(int i=0;i<adj[val].size();i++){
                    if(! visited[adj[val][i]]){
                        q.push(adj[val][i]);
                        visited[adj[val][i]]=1;
                        distance[adj[val][i]]= distance[val]+6;
                    }
                }
            }
            return distance;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 1; i < distances.size(); i++) {
            if (distances[i]) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
