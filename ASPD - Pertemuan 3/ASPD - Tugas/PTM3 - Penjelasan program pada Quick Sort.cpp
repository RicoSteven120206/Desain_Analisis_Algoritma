#include <iostream>
using namespace std;

//embuat sebuah fungsi untuk menukarkan variabel
void swap (int arr[], int pos1, int pos2) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

//membuat sebuah fungsi pivot untuk membagi nilai yang lebih besar dan lebih kecil dari pivot
int partition (int arr[], int low, int high, int pivot) {
	int i = low; //deklarasi sebuah nilai untuk mencari nilai dari kiri ke kanan
	int j = low; //petunjuk untuk posisi penempatan nilai <= pivot
	
	while (i <= high) {
		if (arr[i] > pivot) { //jika suatu nilai lebih besar dari pivot, maka akan melanjutkan suatu program dan increment
			i++;
		} else {
			swap (arr, i, j); //jika suatu nilai lebih kecil atau sama dari pivot, maka akan menukarkan posisi j
			i++;
			j++;
		}
	}
	return j-1; //mengembalikan indeks akhir dari partisi kiri nilai <= pivot
}

//membuat sebuah fungsi untuk menjalankan sebuah program quick sort
void quickSort (int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high]; //deklarasi pivot diambil dari nilai paling kanan
		int pos = partition (arr, low, high, pivot); //deklarasi suatu partisi array
		
		//rekursif untuk bagian kiri dan kanan dari pivot
		quickSort(arr, low, pos-1); //sorting bagian kiri
		quickSort(arr, pos+1, high); //sorting bagian kanan
	}
}

int main() {
	int n; //deklarasi n untuk menentukan jumlah array
	cout<<"Tentukan Panjang Array : ";
	cin>>n; //input jumlah array
	int arr[n]; //deklarasi array dengan size n/dengan jumlah n
	for (int i = 0; i < n; i++) { // looping untuk input sebuah nilai array
		cout<<"Array ke-"<<i+1<<" : ";
		cin>>arr[i]; //input nilai array
	}
	
	//memanggil fungsi quicksort untuk mengurutkan array
	quickSort(arr, 0, n-1);
	
	//menampilkan hasil array yang telah dirutukan
	cout<<"Berikut Adalah Array Yang Telah di Sortir : ";
	
	for (int i = 0; i < n; i++) { 
		cout<<arr[i]<<" "; //menampilkan suatu nilai yang telah di sorting dengan program quicksort
	}
}
