#include <iostream>
using namespace std;

int main() {
	int i, j, n;
	string x[100], y[100];
	cout<<"Jumlah Data Yang Akan di Input: ";
	cin>>n;
	cin.ignore();
	cout<<endl;
	cout<<"Masukkan Nama dan Npm Mahasiswa: \n";

	for (i = 0; i < n; i++) {
		cout<<"Nama	: ";
		getline(cin, x[i]);
		cout<<"NPM	: ";
		getline(cin, y[i]);
		cout<<endl;
	}
	
	cout<<"||======================================================||\n";
	cout<<"||	NPM		||	Nama			||\n";
	cout<<"||======================================================||\n";
	for(i = 0; i < n; i++) {
		cout<<"||	"<<y[i]<<"	||	"<<x[i]<<"	||\n";
	}
	
	cout<<"||======================================================||\n";
}
