#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Graph {
  private:
    int V;
    vector<vector<int> > adj; // Adjacency list

  public:
    Graph (int V) {
        this->V = V;
        adj.resize(V); // Manipulasi ukuran pada simpul
    }
	
	
    void addEdgeUndir(int u, int v) {
        adj[u].push_back(v); // Add edge dari u ke v
        adj[v].push_back(u); // Add edge dari v ke u (untuk undirected)
    }
    
    void addEdgeDir(int u, int v) {
        adj[u].push_back(v); // Add edge dari u ke v
    }

    void printGraph() {
        for (int u = 0; u < V; u++) {
            cout << u << " -> ";
            for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

class graphWeight {
	private:
    	int V;
    	vector<vector<pair<int, int > > > adj; //Adjacency List
    public:
    	graphWeight (int V) {
        	this->V = V;
        	adj.resize(V); // Manipulasi ukuran pada simpul
    	}
    
    	void addEdgeWeiUndir(int u, int v, int weight) {
        	adj[u].push_back(make_pair(v, weight)); // Add edge dari u ke v
        	adj[v].push_back(make_pair(u, weight)); // Add edge dari u ke v (untuk undirected)
    	}
    	
    	void addEdgeWeiDir(int u, int v, int weight) {
        	adj[u].push_back(make_pair(v, weight)); // Add edge dari u ke v
    	}

    	void printGraphWeight() {
        	for (int u = 0; u < V; u++) {
            	cout << u << " -> ";
            for (vector<pair<int, int> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
                cout << "(" << it->first << ", " << it->second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
	int n, pilih, v1, v2, w;
	string data;
	
	ulang:
	cout<<endl;
	cout<<"Masukkan jumlah edge pada vertex: ";
	cin>>n;
	Graph graph(n);
	graphWeight gw(n);
	
	cout<<"IMPLEMENTAION GRAPH"<<endl;
	cout<<"1. Undirected Graph"<<endl;
	cout<<"2. Directed Graph"<<endl;
	cout<<"3. Undirected Weighted Graph"<<endl;
	cout<<"4. Directed Weighted Graph"<<endl;
	cout<<"Pilih salah satu: ";
	cin>>pilih;
	
	if(pilih == 1) {
		for(int i = 0; i < n; i++) {
			cout<<"Masukkan Simpul Asal : ";
			cin>>v1;
			cout<<"Masukkan Simpul Tujuan : ";
			cin>>v2; 
			graph.addEdgeUndir(v1, v2);
		}
	} else if(pilih == 2) {
		for(int i = 0; i < n; i++){
			cout<<"Masukkan Simpul Asal : ";
			cin>>v1;
			cout<<"Masukkan Simpul Tujuan : ";
			cin>>v2; 
			graph.addEdgeDir(v1, v2);
		}
	} else if(pilih == 3) {
		for(int i = 0; i < n; i++) {
			cout<<"Masukkan Simpul Asal : ";
			cin>>v1;
			cout<<"Masukkan Simpul Tujuan : ";
			cin>>v2;
			cout<<"Masukkan Beban : ";
			cin>>w;
			gw.addEdgeWeiUndir(v1, v2, w);
		}
	} else if(pilih == 4) {
		for(int i = 0; i < n; i++) {
			cout<<"Masukkan Simpul Asal : ";
			cin>>v1;
			cout<<"Masukkan Simpul Tujuan : ";
			cin>>v2;
			cout<<"Masukkan Beban : ";
			cin>>w;
			gw.addEdgeWeiDir(v1, v2, w);
		}
	} 
	
	if (pilih == 1 || pilih == 2) {
		graph.printGraph();
	} else if (pilih == 3 || pilih == 4) {
		gw.printGraphWeight();
	}
	
	char yes;
	cout<<"Apakah ingin melanjutkan program ini? (Y/N)? ";
	cin>>yes;
	
	if (yes == 'y' || yes == 'Y') {
		system("cls");
		goto ulang;
	} else {
		cout<<"Program Selesai..."<<endl;
	}

	return 0;
}
