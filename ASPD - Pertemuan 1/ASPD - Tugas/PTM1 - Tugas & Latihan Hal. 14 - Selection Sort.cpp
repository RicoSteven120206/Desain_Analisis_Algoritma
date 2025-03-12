#include <iostream>
using namespace std;

void selectionSort(int arr[], int n);
	
void reverseSelectionSort(int arr[],int n);

int main() {
	int n, i;
	cout<<"Masukkan Jumlah Elemen: ";
	cin>>n;
	int arr[n];
	cout<<"Masukkan Nilai Elemen: \n";
	for(i = 0; i < n; i++) {
		cout<<"Nilai Elemen ke-"<<i+1<<" : ";
		cin>>arr[i];
	}
	cout<<"\nData Sebelum Sorting; \n";
	for(i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	selectionSort(arr, n);
	
	cout<<"\nData Setelah Sorting: ";
	for (i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	
	
	//Selection Sort Dari Urutan Terbesar ke Terkecil
	cout<<"\n\n\n\nSelection Sort dari Terbesar ke Terkecil\n";
	
	int a, index[n];
	cout<<"Masukkan Nilai Elemen: \n";
	for(a = 0; a < n; a++) {
		cout<<"Nilai Elemen ke-"<<a+1<<" : ";
		cin>>index[a];
	}
	
	cout<<"\nData Sebelum Sorting; \n";
	for(a = 0; a < n; a++) {
		cout<<index[a]<<" ";
	}
	cout<<endl;
	
	reverseSelectionSort(index, n);
	
	cout<<"\nData Setelah Sorting: ";
	for (a = 0; a<n; a++) {
		cout<<index[a]<<" ";
	}
	
	return 0;
}

void selectionSort(int arr[], int n) {
	int i, j, minIndex, temp;
	for (i = 0; i < n-1; i++) {
		minIndex = i;
		for (j = i+1; j<n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
		cout<<"Iterasi ke-"<<i+1<<" ";
		for(int k = 0; k < n; k++) {
			cout<< arr[k]<<" ";
		}
		cout<<endl;
	}
}

void reverseSelectionSort(int arr[],int n) {
	int i, j, minIndex, temp;
	for (i = 0; i < n-1; i++) {
		minIndex = i;
		for (j = i+1; j < n; j++) {
			if (arr[j] > arr[minIndex]) {
				minIndex = j;
			}
		}
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
		cout<<"Iterasi ke-"<<i+1<<" ";
		for (int b = 0; b < n; b++) {
			cout<<arr[b]<<" ";
		}
		cout<<endl;
	}
}
