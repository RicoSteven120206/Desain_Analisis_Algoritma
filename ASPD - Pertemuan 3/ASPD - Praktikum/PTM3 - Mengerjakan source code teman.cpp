#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Masukkan Bilangan yang anda inginkan : ";
	cin>>n;
	
	if (n >= 0) {
		cout<<n<<" Adalah Bilangan Positif";
	} else {
		cout<<n<<" Adalah Bilangan Negatif";
	}
}
