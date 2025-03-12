#include <iostream>

using namespace std;

int main() {
	int y;
	cout<<"Masukkan banyak array: ";
	cin>>y;
	
	int x[y];
	for (int i=0; i<y; i++) {
		cout<<"Masukkan angka ke-"<<i+1<<" : ";
		cin>>x[i];
		cout<<endl;
	}
	
	for (int i=1; i<y; i++) {
		int key = x[i];
		int j = i-1;
		while (j>=0 && x[j] > key) {
			x[j+1] = x[j];
			j--;
		}
		x[j+1] = key;
		cout<<"Proses sorting"<<endl;
		for ( int m=0; m<y; m++) {
			cout<<x[m]<<" ";
		}
		cout<<endl;
	}
	cout<<"Hasil akhir"<<endl;
	for (int m=0; m<y; m++) {
		cout<<x[m]<<" ";
	}
	
	cout<<"\n\n\n";
	
	//Insertion Sort dari Terbesar ke Terkecil
	int index[y];
	for (int a=0; a<y; a++) {
		cout<<"Masukkan angka ke-"<<a+1<<" : ";
		cin>>index[a];
		cout<<endl;
	}
		
	for (int a=1; a<y; a++) {
		int key = index[a];
		int b = a-1;
		while (b>=0 && index[b] < key) {
			index[b+1] = index[b];
			b--;
		}
		index[b+1] = key;
		cout<<"Proses sorting"<<endl;
		for ( int n=0; n<y; n++) {
			cout<<index[n]<<" ";
		}
		cout<<endl;
	}
	cout<<"Hasil akhir"<<endl;
	for (int n=0; n<y; n++) {
		cout<<index[n]<<" ";
	}
}
