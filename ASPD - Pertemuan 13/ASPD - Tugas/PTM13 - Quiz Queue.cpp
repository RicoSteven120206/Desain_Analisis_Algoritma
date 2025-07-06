#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

class Queue {
	private:
		int count;
		int MAX;
		string* data;
	
	public:
		Queue() {
			count = 0;
			MAX = 0;
		}
		
		void setCount(int x) {
			MAX = x;
			data = new string[MAX];
		}
		
		int size() {
			return count;
		}
		
		bool isEmpty() {
			if (count == 0) {
				return true;
			} else {
				return false;
			}
		}
		
		bool isFull() {
			if (count >= MAX) {
				return true;
			} else {
				return false;
			}
		}
		
		void enqueue() {
			if (isFull()) {
				cout<<"Antrian Penuh...";
			} else {
				cin>>data[count];
				count++;
			}
		}
		
		int dequeue() {
			if (isEmpty()) {
				cout<<"Antrian Kosong."<<endl;
			} else {
				for (int a = 0; a < count-1; a++) {
					data[a] = data[a+1];
					cout<<data[a+1];
				}
				count--;
			}
		}
		
		int view() {
			if (isEmpty()) {
				cout<<"Antrian Kosong..."<<endl;
			} else {
				for (int a = count-1; a >= 0; a--) {
					cout<<data[a]<<endl;
				}
			}
			cout<<endl;
		}
};

int main() {
	int pilih;
	int n;
	string isi;
	string ans;
	Queue que;
	
	cout<<"Masukkan Jumlah Antrian : ";
	cin>>n;
	que.setCount(n);
	
	antri:
	cout<<"1. Masuk Antri "<<endl;

	cout<<"-> Pilih: ";
	cin>>pilih;
	
	if (pilih == 1) {
		for (int i = 0; i < n; i++) {
			que.enqueue();
		}
	} 
	
	cout << "Ukuran Antrian: " << que.size() << endl;
	cout << "Elemen Pertama: " << que.view() << endl;
	cout << "Elemen Keluar: " << que.dequeue() << endl;
	cout << "Elemen Pertama: " << que.view() << endl;
	cout << "Ukuran Antrian: " << que.size() << endl;
	
	return 0;
}
