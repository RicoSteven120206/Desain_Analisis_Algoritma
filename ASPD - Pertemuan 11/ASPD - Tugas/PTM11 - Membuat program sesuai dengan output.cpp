#include <bits/stdc++.h>
#include <iostream>
#define MAX 100005
#define INF INT_MAX
using namespace std;

vector<pair<int, int> > adj[MAX];
bool vis[MAX];
int dist[MAX];

class graph {
  public:
	//membuat function dijkstra
	void djikstra(int start) {
	    memset(vis, false, sizeof vis);
	    for (int i = 0; i < MAX; i++) {
	        dist[i] = INF;
	    }
	    dist[start] = 0;
	
	    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	    pq.push({0, start});
	    while(!pq.empty()) {
	        pair<int, int> p = pq.top();
	        pq.pop();
	        int x = p.second;
	        if (vis[x]) {
	            continue;
	        }
	        vis[x] = true;
	
	        for (int i = 0; i < adj[x].size(); i++) {
	            int e = adj[x][i].first;
	            int w = adj[x][i].second;
	            if (dist[x] + w < dist[e]) {
	                dist[e] = dist[x] + w;
	                pq.push({dist[e], e});
	            }
	        }
	    }
	}
};

int main() {
	graph g;
    int n;
    cout<<"Masukkan jumlah vertex : ";
    cin>>n;
    
	for(int i = 0; i < n + 1; i++) {
		int value;
		cout<<"Distance : ";
		cin>>value;
		adj[0].push_back({i, value});
	}
    g.djikstra(0);
	
	cout<<"\n----------------------------------\n";
    cout<<"Vertex\tDistance from Source"<<endl;

    for (int i = 0; i < n + 1; i++) {
        cout<<"  "<<adj[0][i].first<<"\t\t"<<dist[i]<<endl;
    }
  
    return 0;
}
