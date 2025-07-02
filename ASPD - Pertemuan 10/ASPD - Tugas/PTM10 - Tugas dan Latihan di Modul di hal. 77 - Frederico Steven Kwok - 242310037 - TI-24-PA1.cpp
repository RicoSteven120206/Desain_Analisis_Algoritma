#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX
using namespace std;

int dist[MAX]; // deklarasi dsitance
vector<pair<int, int> > adj[MAX]; // deklarasi adjacency dengan vector
bool vis[MAX]; //deklarasi visited dengan boolean
int route[MAX]; // deklarasi route

class Graph{
  public:
	// membuat function dijkstra 
	void dijkstra(int start) { 
    	memset(vis, false, sizeof vis); //membuat set memori di suatu blok memori
    	for (int i = 0; i < MAX; i++) {
        	dist[i] = INF; // INF akan menyimpan data ke distance dengan array i
    	}
    
    	dist[start] = 0; // distance dengan array start dari 0
    	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // deklarasi pq dengan vector
    	pq.push({0, start}); // variabel pq akan push suatu value dengan parameter 0 dan start

		// akan melakukan looping jika variabel pq nya tidak kosong
    	while(!pq.empty()) {
        	pair<int, int> p = pq.top(); // deklarasi variabel p dengan vector dengan variabel pq
        	pq.pop(); // akan melakukan pop pada variabel pq
        	int x = p.second; // variabel p pada bagian kedua/second akan menyimpan data di variabel x
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

	// membuat function printRoute untuk mencetak suatu rute dengan parameter start dan end
	void printRoute(int start, int end) {
    	if (dist[end] == INF) { 
        	cout << "Tidak ada rute dari node " << start << " ke node " << end << endl;
        	return;
    	}

    	vector<int> path; // membuat path dengan vector
    	int currentNode = end; // deklarasi currentNode dengan isi variabel end;

    	while (currentNode != 0) {
        	path.push_back(currentNode);
        	currentNode = route[currentNode];
    	}
    
    	reverse(path.begin(), path.end());
    	cout << "Rute terpendek dari kota " << start << " ke kota " << end << " adalah:" << endl;
    	for (size_t i = 0; i < path.size(); ++i) {
        	cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
    	}
	}

	// membuat function printTable untuk mencetak matrix membentuk tabel dengan parameter from dan to
	void printTable(int from, int to) { 
    	for (int i = from; i <= to; i++) {
        	for (int j = 0; j < to; j++) {
            	cout << "\t" << adj[i][j].second;
        	}
        	cout << endl;
    	}
	}
};

int main() {
	Graph g;
    int N;
    cout << "Masukkan Jumlah Kota : ";
    cin >> N;
    cout << "Nilai Cost Matrix" << endl;

    for (int i = 1; i <= N; i++) {
        cout << "Cost Element Baris ke-: " << i << endl;
        for (int j = 1; j <= N; j++) {
            int weight; // deklarasi bobot
            cin >> weight;
            adj[i].push_back({j, weight});
        }
        cout << endl;
    }

    cout << "Cost List : " << endl;
    g.printTable(1, N);
    cout << endl;

    int asal, tujuan;

    cout << "Masukkan Kota Asal : ";
    cin >> asal;
    cout << "Masukkan Kota Tujuan : ";
    cin >> tujuan;

    g.dijkstra(asal);
    g.printRoute(asal, tujuan);
    
	cout << endl;
    cout << "Minimun Cost : " << dist[tujuan] << endl;

    system("pause");

    return 0;
}
