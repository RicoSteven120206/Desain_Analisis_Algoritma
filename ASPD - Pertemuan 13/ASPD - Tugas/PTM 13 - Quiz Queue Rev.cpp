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
				for (int a = 0; a < count-1; a++) {
					data[a] = data[a+1];
				}
				count--;
			}
		}
		
		int view() {
			int a;
			if (isEmpty()) {
				cout<<"Antrian Kosong..."<<endl;
			} else {
				for (int a = 0; a <= count-1; a++) {
					cout<<data[a];
				}
				cout<<data[count];
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
	cout << "Elemen Keluar: " << que.view() << endl;
	que.dequeue();
	cout << "Elemen Pertama: " << que.view() << endl;
	cout << "Ukuran Antrian: " << que.size() << endl;
	
	return 0;
}
