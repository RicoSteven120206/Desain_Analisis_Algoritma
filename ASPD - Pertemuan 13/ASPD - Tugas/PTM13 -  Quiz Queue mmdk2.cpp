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
		
		void enqueue(int value) {
			if (isFull()) {
				cout<<"Antrian Penuh...";
			} else {
				getline(cin, data[count]);
				count++;
			}
		}
		
		int dequeue() {
			if (isEmpty()) {
				cout<<"Antrian Kosong."<<endl;
			} else {
				for (int b = 0; b < count; b++) {
					data[b] = data[b+1];
				}
				count--;
			}
		}
		
		int view() {
			int a;
			if (isEmpty()) {
				cout<<"Antrian Kosong..."<<endl;
			} else {
				for (count; a < count; a++) {
					cout<<data[a];
				}
			}
		}
};

int main() {
	int n;
	int m;
	Queue que;
	
	cout<<"Masukkan Jumlah Antrian: ";
	cin>>m;
	que.setCount(m);
	
	cout<<"Masukkan "<<m<<" bilangan untuk antrian: "<<endl;
	for (int i = 0; i < m; i++) {
		cin>>n;
		que.enqueue(n);
	}
	
	cout << "Ukuran Antrian: " << que.size() << endl;
	cout << "Elemen Pertama: " << que.view() << endl;
	cout << "Elemen Keluar: " << que.view() << que.dequeue() << endl;
	cout << "Elemen Pertama: " << que.view() << endl;
	cout << "Ukuran Antrian: " << que.size() << endl;
	
	return 0;
}
