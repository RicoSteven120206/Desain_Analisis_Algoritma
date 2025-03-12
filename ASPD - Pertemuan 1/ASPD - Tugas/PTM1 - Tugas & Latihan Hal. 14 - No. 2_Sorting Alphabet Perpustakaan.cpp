#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;

int main() {
	int i, j, n;
	string index[100], temp;
	cout<<"Hallo!"<<endl;
	cout<<"Selamat Datang di Perpustakaan Ade Antonio Mufid\n";
	cout<<"Silahkan Masukkan Nama Buku Anda Untuk Kami Urutkan!\n\n";
	cout<<"Masukkan Jumlah Data Buku Yang Akan Di Masukkan: ";
	cin>>n;
	cin.ignore();
	for (i = 0; i < n; i++) {
		cout<<"Buku ke-"<<i+1<<" : ";
		getline(cin, index[i]);
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n-i-1; j++) {
			if (index[j] > index[j+1]) {
				temp = index[j];
				index[j] = index[j+1];
				index[j+1] = temp;
			}
//			cout<<"Iterasi ke-"<<i+1<<" ";
//			for(int k = 0; k < n; k++) {
//				cout<< index[k]<<" ";
//			}
//			cout<<endl;
		}
	}
	
	cout<<"\nList Urutan Buku Anda\n";
	for (int d = 0; d < n; d++) {
		cout<<d+1<<". "<<index[d]<<endl;
	}
}
