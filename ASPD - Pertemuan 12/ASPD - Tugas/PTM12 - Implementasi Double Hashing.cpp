#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MAX = 100;
int storage[MAX];
int hdt_boundary;

class Hash {
  public:
	// Fungsi Mencari Bilangan Prima di Atas
	int prima_atas(int n) {
	if (n % 2 == 0)
	    n = n + 1;
	else
	    n = n + 2;
	
	bool ketemu = false;
	
	while (!ketemu) {
	    bool prima = true;
	    if (n % 2 == 0)
	        prima = false;
	    else {
	        int i = 3;
	        while (prima && i <= sqrt(n)) {
	            if (n % i == 0)
	                prima = false;
	            i += 2;
	        }
	    }
	
	    if (prima)
	        ketemu = true;
	    else
	        n = n + 2;
	}
	
	return n;
	}
	
	// Fungsi Mencari Bilangan Prima di Bawah (untuk hashing ke-2)
	int prima_bawah() {
	int n = hdt_boundary - 1;
	while (n > 1) {
	    bool prima = true;
	    for (int i = 2; i <= sqrt(n); ++i) {
	        if (n % i == 0) {
	            prima = false;
	            break;
	        }
	    }
	    if (prima) return n;
	    n--;
	}
	return 2;
	}
	
	// Fungsi Double Hashing
	void tambah_double_hashing(int n) {
	int hash;
	int hash2 = prima_bawah();
	bool inserted = false;
	int i = 0;
	
	while (!inserted && i < hdt_boundary) {
	    hash = ((n % hdt_boundary) + i * ((n % hash2) + 1)) % hdt_boundary;
	
	    if (storage[hash] == 0) {
	        storage[hash] = n;
	        inserted = true;
	    } else {
	        ++i;
	        cout << "Terjadi tabrakan di " << hash << endl;
	    }
	}
	
	if (i == 0)
	    cout << "Langsung" << endl;
	
	cout << "Isi hash[" << hash << "] dengan " << n << endl;
	cout << "===========================================" << endl;
	}
	
	// Fungsi Cetak Output Hashtable
	void cetak(int n) {
	cout << endl;
	cout << "Output program : " << endl;
	for (int a = 0; a < n; ++a) {
	    cout << "hash[" << a << "] = " << storage[a] << endl;
	}
	}
	
	// Fungsi Generate Angka Random
	int getRandomNumberFromRange(int min, int max) {
	return min + (rand() % (max - min));
	}
};

// Main Program
int main() {
	Hash h;
    int n, random_number;
    char pilihan;
    string cara;

	srand((unsigned)time(0));

    cout << "Masukkan jumlah data yang ingin disisipkan: ";
    cin >> n;

    hdt_boundary = h.prima_atas(n);

    if (hdt_boundary > MAX) {
        cout << "Error: Jumlah data terlalu besar untuk kapasitas program (Maks: " << MAX << ")." << endl;
        return 1;
    }
    
    h.prima_bawah();
    
    for(int i = 0; i < hdt_boundary; i++) {
        storage[i] = 0;
    }

    cout << "\nProses Pemasukan Data ke Hashtable (Double Hashing)" << endl;
    cout << "Ukuran tabel diatur menjadi: " << hdt_boundary << endl;
    cout << "Bilangan prima untuk h2 diatur menjadi: " << h.prima_bawah() << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int a = 0; a < n; ++a) {
        int random_number = 1 + (rand() % 100);
        h.tambah_double_hashing(random_number);
    }

    h.cetak(n);

    cout << "\nFormula yang digunakan:\n";
    cout << "h1(k) = k % " << hdt_boundary << endl;
    cout << "h2(k) = " << h.prima_bawah() << " - (k % " << h.prima_bawah() << ")\n";
    cout << "Index = (h1(k) + i * h2(k)) % " << hdt_boundary << endl;
	
//    srand((unsigned)time(0));
//
//    cout << "Masukan jumlah data : ";
//    cin >> n;
//
//    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;
//
//    hdt_boundary = h.prima_atas(n);
//
//        random_number = h.getRandomNumberFromRange(0, n);
//            h.tambah_double_hashing(random_number);
//            cara = "Double hashing";
//
//    // Output hasil akhir
//    h.cetak(n);
//    cout << "Diatas adalah hasil output Hashtable dengan cara \"" << cara << "\"" << endl;
//
//    cout << "h1(k) = k mod " << hdt_boundary << endl;
//    cout << "h2(k) = (h1(k) + i * (k mod " << h.prima_bawah() << " + 1) ) mod " << hdt_boundary << endl;
//
//    return 0;
}
