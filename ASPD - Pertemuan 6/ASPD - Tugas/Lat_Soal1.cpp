#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	private:
		string nama[];
		string npm[];
		double nilai[];
		
	public:
		void setNamaMahasiswa(string namaM[], int jmlhD) {
			for (int i = 0; i < jmlhD; i++) {
			nama[i] = namaM[i];
			}
		}
		
		void setNpmMahasiswa(string *npmM[], int jmlhD) {
			for (int i = 0; i < jmlhD; i++) {
			npm[i] = npmM[i];
			}
		}
		
		void setNilaiMahasiswa(double *nilaiM[], int jmlhD) {
			for (int i = 0; i < jmlhD; i++) {
			nilai[i] = nilaiM[i];
			}
		}
		
		string* getNamaMahasiswa() {
			return nama;
		}
		
		string* getNpmMahasiswa() {
			return npm;
		}
		
		double* getNilaiMahasiswa() {
			return nilai;
		}
		
		
};

int main() {
	Mahasiswa mahasiswa;
	string nama[n], npm[n];
	int n;
	double nilai[n];
	
	string *ptrNama = nama;
	string *ptrNpm = npm;
	double *ptrNilai = nilai;
	
	
	cout<<"Masukkan Jumlah Data Mahasiswa yang akan di input : ";
	cin>>n;
	
	cout<<"\nMasukkan Data Mahasiswa\n";
	for (int i = 0; i < n; i++) {
	cout<<"Nama Mahasiswa ke-"<<i+1<<"	: ";
	cin>>nama[i];
	cout<<"NPM Mahasiswa ke-"<<i+1<<"	: ";
	cin>>npm[i];
	cout<<"Nilai Mahasiswa ke-"<<i+!<<"	: ";
	cin>>nilai[i];
	cout<<endl;
	}
	
	mahasiswa.setNama(nama, n);
	mahasiswa.setNpm(npm, n);
	mahasiswa.setNilai(nilai, n);
	
//	int index[n];
//	for (int a=0; a<y; a++) {
//		cout<<"Masukkan angka ke-"<<a+1<<" : ";
//		cin>>index[a];
//		cout<<endl;
//	}
//		
//	for (int a=1; a<y; a++) {
//		int key = index[a];
//		int b = a-1;
//		while (b>=0 && index[b] < key) {
//			index[b+1] = index[b];
//			b--;
//		}
//		index[b+1] = key;
//	}

	string* ptrNama = 

	cout<<"Nama Mahasiswa	: "<<mahasiswa.getNama()<<endl;
	cout<<"NPM Mahasiswa	: "<<mahasiswa.getNpm()<<endl;
	cout<<"Nilai Mahasiswa	: "<<mahasiswa.getNilai()<<endl;
	
}
