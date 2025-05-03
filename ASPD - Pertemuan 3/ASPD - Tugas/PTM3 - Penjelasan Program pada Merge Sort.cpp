#include <iostream>
using namespace std;

//membuat suatu fungsi menggabungkan dua bagian array yang telah diurutkan
void merge (int arr[], int l, int m, int r) {
	int x, y, z;
	int n1 = m - l + 1; //deklarasi dari suatu nilai untuk menentukan jumlah nilai di bagian kiri
	int n2 = r - m; //deklarasi dari suatu nilai untuk menentukan jumlah nilai di bagian kanan
	
	int L[n1], R[n2]; //deklarasi suatu nilai untuk mengumpulkan atau menampung bagian kiri dan kanan
	
	for (x = 0; x < n1; x++) { //menyalin suatu nilai atau data ke dalam array bagian kiri
		L[x] = arr[l + x];
	}
	for (y = 0; y < n2; y++) { //menyalin suatu nilai atau data ke dalam array bagian kanan
		R[y] = arr[m + 1 + y];
	}
	
		x = 0; //membuat suatu nilai awal untuk array bagian kiri
		y = 0; //membuat suatu nilai awal untuk array bagian kanan
		z = l; //membuat suatu nilai awal untuk array gabungan 
	
	//bagian proses penggabungan dua array menjadi satu array secara terurut
	while (x < n1 && y < n2) {
		if (L[x] <= R[y]) {
			arr[z] = L[x]; //menyimpan data kiri untuk menggabungkan data di satu array
			x++;
		} else {
			arr[z] = R[y]; //menyimpan data kanan untuk menggabungkan data di satu array
			y++;
		}
		z++;
	}
	
	//menyimpan suatu data di L[], jika ada
	while (x < n1) {
		arr[z] = L[x];
		x++;
		z++;
	}
	
	//menyimpan suatu data di R[], jika ada
	while (y < n2) {
		arr[z] = R[y];
		y++;
		z++;
	}
}

//membuat suatu fungsi rekursi untuk melkaukan merge sort
void mergeSort (int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2; //menghindari kemungkinan overflow dibandingkan
		
		//memanggil suatu fungsi untuk mengurutkan bagian pertama dan kedua
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		
		//memanggil suatu fungsi untuk menggabungkan dua bagian terurut
		merge(arr, l, m, r);
	}
}

//membuat suatu fungsi untuk menampilkan isi array
void show (int A[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
}

int main() {
	int size; //deklarasi size untuk menentukan suatu ukuran banyak data
	cout<<"\n Masukkan Banyak Data : ";
	cin>>size;
	
	int arr[size]; //mendeklarasikan array sesuai dengan jumlah size yang di input
	
	//membuat suatu looping untuk memasukkan data ke dalam array
	for (int i = 0; i < size; ++i) {
		cout<<"\nMasukkan Data Array ke-"<<i+1<<" : ";
		cin>>arr[i]; //input suatu data dengan array
	}
	
	//memanggil suatu fungsi merge sort untuk mengurutkan array
	mergeSort(arr, 0, size);
	
	cout<<"Hasil\n";
	show(arr, size); //menampilkan array yang telah di sorting
	return 0;
}
