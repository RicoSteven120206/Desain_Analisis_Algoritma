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
	// Fungsi Mencari Bilangan Prima di Atas
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
	}

// Fungsi Cetak Output Hashtable
	void cetak(int n) {
	    cout << endl;
	    cout << "Output program : " << endl;
	    for (int a = 0; a < n; ++a) {
	        cout << "hash[" << a << "] = " << storage[a] << endl;
	    }
	}
};

// Main Program
int main() {
	Hash h;
    int n, nilai;
    char pilihan;
    string cara;

    cout << "Masukan jumlah data : ";
    cin >> n;

    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;

    hdt_boundary = h.prima_atas(n);

    for (int a = 0; a < n; ++a) {
        cin>>nilai;
        h.tambah_double_hashing(nilai);
        }
    h.cetak(n);
}
