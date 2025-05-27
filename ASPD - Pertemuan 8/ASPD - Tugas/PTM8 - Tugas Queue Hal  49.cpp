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
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Masukkan Antrian: ";
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
			if (isEmpty()) {
				cout<<"Antrian Kosong..."<<endl;
			} else {
				cout<<"+-----------------------+"<<endl;
				cout<<"|	DATA ANTRIAN	|"<<endl;
				cout<<"+-----------------------+"<<endl;
				for (int a = count-1; a >= 0; a--) {
					cout<<"Antri "<<a+1<<" = "<<data[a]<<endl;
				}
			}
			
			if (isFull()) {
				cout<<"Antrian Penuh..."<<endl;
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
	
	cout<<"Masukkan Jumlah Antrian Tiket di Loket: ";
	cin>>n;
	que.setCount(n);
	
	antri:
		system("cls");
	cout<<"+---------------+"<<endl;
	cout<<"| ANTRIAN TIKET |"<<endl;
	cout<<"+---------------+"<<endl;
	cout<<"|1. Masuk Antri |"<<endl;
	cout<<"|2. Keluar Antri|"<<endl;
	cout<<"|3. Jumlah Antri|"<<endl;
	cout<<"|4. Lihat Antri |"<<endl;
	cout<<"|5. Exit Antri  |"<<endl;
	cout<<"+---------------+"<<endl;
	cout<<"-> Pilih: ";
	cin>>pilih;
	
	if (pilih == 1) {
		system("cls");
		que.enqueue();
		goto antri;
	} else if (pilih == 2) {
		que.dequeue();
		goto antri;
	} else if (pilih == 3) {
		system("cls");
		cout<<"Jumlah Antrian: "<<que.size()<<endl;
		cout<<"\nTekan 1 Untuk Lanjut Program"<<endl;
		cin>>ans;
		if (ans == "1") {
			goto antri;
		} else {
			return false;
		}
	} else if (pilih == 4) {
		system("cls");
		que.view();
		cout<<"\nTekan 1 Untuk Lanjut Program"<<endl;
		cin>>ans;
		if (ans == "1") {
			goto antri;
		} else {
			return false;
		}
	} else if (pilih == 5) {
		system("cls");
		cout<<"Terima Kasih...\n";
	}
	return 0;
}
