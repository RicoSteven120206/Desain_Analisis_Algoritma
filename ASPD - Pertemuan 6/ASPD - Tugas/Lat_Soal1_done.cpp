#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	private:
		string nama;
		string npm;
		int nilai;
		
	public:
		void setNamaMahasiswa(string namaM, string npmM, int nilaiM) {
			nama = namaM;
			npm = npmM;
			nilai = nilaiM;
		}
		
		string getDataMahasiswa() {
			return nama;
			return npm;
			return nilai;
		}
};

int main() {
	int n;
	string nama, npm;
	int nilai;
	
	cout<<"Masukkan Jumlah Data Mahasiswa yang akan di input : ";
	cin>>n;
	Mahasiswa mahasiswa[n];
	
	cout<<"\nMasukkan Data Mahasiswa\n";
	for (int i = 0; i < n; i++) {
	cout<<"Nama Mahasiswa ke-"<<i+1<<"	: ";
	cin>>mahasiswa[i].nama;
	cout<<"NPM Mahasiswa ke-"<<i+1<<"	: ";
	cin>>mahasiswa[i].npm;
	cout<<"Nilai Mahasiswa ke-"<<i+1<<"	: ";
	cin>>mahasiswa[i].nilai;
	cout<<endl;
	mahasiswa.setNamaMahasiswa(nama, npm, nilai, n);
	cout<<endl;
	}
	
//	mahasiswa.setNama(nama, n);
//	mahasiswa.setNpm(npm, n);
//	mahasiswa.setNilai(nilai, n);
	
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

	cout<<"Urutan Data Mahasiswa"<<endl;
	for(int j = 0; j < n; j++) {
	cout<<"Nama Mahasiswa	: "<<mahasiswa.getDataMahasiswa<<endl;
//	cout<<"NPM Mahasiswa	: "<<mahasiswa.getNpmMahasiswa<<endl;
//	cout<<"Nilai Mahasiswa	: "<<mahasiswa.getNilaiMahasiswa<<endl;
	}
}
