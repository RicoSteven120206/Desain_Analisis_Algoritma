#include <bits/stdc++.h>
#include <iostream>
#define MAX 100005
#define INF INT_MAX
using namespace std;

vector<pair<int, int> > adj[MAX];
bool vis[MAX];
int dist[MAX];
int route[MAX];

class graph {
  public:
  	// membuat function dijkstra dengan parameter start
	void dijkstra(int start) {
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
	                route[e] = x;
	                pq.push({dist[e], e});
	            }
	        }
	    }
	}
	
	void addEdge(vector<pair<int, int> > *adj, int from, int to, int weight) {
	    adj[from].push_back({to, weight});
	    adj[to].push_back({from, weight}); // undirected graph 
	}
	
	// membuat function print rute untuk membuat rute
	void printRoute(int start, int end) {
	    if (dist[end] == INF) {
	        cout << "Tidak ada rute dari node " << start << " ke node " << end << endl;
	        return;
	    }
	
	    vector<int> path; // deklarasi path dengan vector
	    int currentNode = end;
	    while (currentNode != 0) {
	        path.push_back(currentNode);
	        currentNode = route[currentNode];
	    }
	    
	    reverse(path.begin(), path.end());
	    for (size_t i = 0; i < path.size(); ++i) {
	        cout << path[i] << (i == path.size() - 1 ? "" : " -> "); // fungsi ternary
	    }
	}
};

int main() {
	graph g;
	int dari, ke, n;
	cout<<"Masukkan jumlah node: ";
	cin>>n;
	
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cout<<"Simpul asal : ";
		cin>>x;
		cout<<"Simpul Tujuan : ";
		cin>>y;
		cout<<"Bobot : ";
		cin>>z;
		cout<<endl;
    	g.addEdge(adj, x, y, z);
	}
    cout << "=> Masukkan simpul asal: ";
    cin >> dari;
    cout << "=> Masukkan simpul tujuan: ";
    cin >> ke;

    g.dijkstra(dari);

    cout << "Jarak terpendek dari node " << dari << " ke node " << ke << " adalah: " << dist[ke] << endl;
    cout << "Rute: " << endl;
    g.printRoute(dari, ke);
    cout << endl;

    system("pause");

    return 0;
}
