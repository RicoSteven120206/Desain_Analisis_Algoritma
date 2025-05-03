#include <iostream>
using namespace std;

//mendefinisikan sebuah class bernama 'contoh'
class contoh {
    private: //private ini bagian yang hanya dapat diakses oleh isi dari dalam class itu sendiri
        int nilai; //data dari dalam class private, hanya dapat diakses dalam satu fungsi publik
    
    public: //publik ini bagian yang dapat diakses dari luar class
        contoh (int n) { //bagian ini merupakan constructor dengan parameter yang akan dipanggil oleh objek yang dibuat
            nilai = n; //menginisialisasikan variabel dari parameter ke variabel anggota 'nilai'
        }

        int getNum() { //fungsi ini untuk mengakses nilai private 'nilai'
            return nilai; //mengembalikan suatu nilai dari variabel anggota 'nilai'
        }
};

int main() {
    contoh obj(10); //membuat objek dalam class 'contoh' dan memberikan nilai 10 melalui constructor
    cout << "Nilai yanh diinput: " << obj.getNum() << endl; //memanggil fungsi getNum untuk mencetak nilai

    return 0;
}
