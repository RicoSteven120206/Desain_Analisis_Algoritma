#include <iostream>
using namespace std;

class buku {
	private:
		string judul_buku;
		
	public:
		buku(string buku1) {
			judul_buku = buku1;
			
			cout<<"Buku "<<judul_buku<<" ditambahkan" << endl;
		}
		
		~buku() {

			cout<<"Buku "<<judul_buku<<" dihapus" << endl;
		}
};

int main() {
	string judul;
	
	cout<<"Masukkan judul buku : ";
	cin>>judul;
	
	buku bukuN(judul);
	return 0;
}
