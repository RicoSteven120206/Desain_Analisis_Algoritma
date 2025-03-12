#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	int i, j, tmp;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void reverseBubbleSort(int arr[],int n) {
	int i, j, temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n- 1; j++) {
			if (arr[j] < arr[j+1]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			} 
		}
	}
}

int main() {
	int array[100], n, i, j;
	cout<<"Masukkan Banyak Elemen: ";
	cin>>n;
	
	
	cout<<"Masukkan Nilai: ";
	for(i = 0; i < n; i++) {
		cin>>array[i];
	}
	
	bubbleSort(array, n);
	cout<<"Hasil Pengurutan Dengan Algoritma Bubble Sort: ";
	for (i = 0; i < n; i++) {
		cout<<array[i]<<" ";
	}
	cout<< endl;
	
	reverseBubbleSort(array, n);
	cout<<"Hasil Pengurutan Elemen Dari Terbesar Ke Terkecil Dengan Algoritma Bubble Sort: ";
	for (j = 0; j < n; j++) {
		cout<<array[j]<<" ";
	}
	cout<<endl;
}
