#include <iostream>
using namespace std;

int main() {
	int i[] = {10, 20, 30, 40, 50};
	cout<<"Isi Array:\n";
	for (int j = 0; j < 5; j++) {
		cout<<"Angka["<<j+1<<"] = "<<i[j]<<endl;
	}
}
