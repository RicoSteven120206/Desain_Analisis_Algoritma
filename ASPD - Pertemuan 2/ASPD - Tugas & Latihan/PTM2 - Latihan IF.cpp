#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Masukkan Sebuah Angka: ";
	cin>>n;
	
	if (n % 2 == 0) {
		cout<<n<<" Adalah Bilangan Genap\n";
	} else {
		cout<<n<<" Adalah Bilangan Ganjil\n";
	}
}
