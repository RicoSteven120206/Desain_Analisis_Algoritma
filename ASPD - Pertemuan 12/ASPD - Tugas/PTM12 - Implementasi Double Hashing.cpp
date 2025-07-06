#include <iostream>
#include <vector>
using namespace std;

const int emptySlot = -1;
const int deleteSlot = -2;

class DoubleHashing {
private:
    vector<int> hashTable; 
    int tableSize;              
    int prime;                  

public:
    DoubleHashing(int size) {
        this->tableSize = size;
        this->prime = 7; 
        hashTable.assign(tableSize, emptySlot); 
    }

    int hash1(int key) {
        return key % tableSize;
    }

    int hash2(int key) {
        return prime - (key % prime);
    }

    void insert(int key) {
        if (search(key) != -1) {
            cout << "-> Kunci " << key << " sudah ada di dalam tabel." << endl;
            return;
        }

        int h1 = hash1(key);

        if (hashTable[h1] == emptySlot || hashTable[h1] == deleteSlot) {
            hashTable[h1] = key;
            cout << "-> Kunci " << key << " berhasil disisipkan di indeks " << h1 << "." << endl;
            return;
        }

        int h2 = hash2(key);
        for (int i = 1; i < tableSize; ++i) {
            int probeIndex = (h1 + i * h2) % tableSize;

            if (hashTable[probeIndex] == emptySlot || hashTable[probeIndex] == deleteSlot) {
                hashTable[probeIndex] = key;
                cout << "-> Kunci " << key << " disisipkan di indeks " << probeIndex << " (setelah " << i << " kali probe)." << endl;
                return;
            }
        }

        cout << "-> Tabel hash penuh, tidak bisa menyisipkan kunci " << key << "." << endl;
    }

    int search(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < tableSize; ++i) {
            int probeIndex = (h1 + i * h2) % tableSize;

            if (hashTable[probeIndex] == key) {
                return probeIndex;
            }
            
            if (hashTable[probeIndex] == emptySlot) {
                return -1;
            }
        }

        return -1; 
    }

    void remove(int key) {
        int index = search(key);
        if (index != -1) {
            hashTable[index] = deleteSlot; 
            cout << "-> Kunci " << key << " di indeks " << index << " berhasil dihapus." << endl;
        } else {
            cout << "-> Kunci " << key << " tidak ditemukan di dalam tabel." << endl;
        }
    }

    void display() {
        cout << "\n===== ISI TABEL HASH =====\n";
        for (int i = 0; i < tableSize; i++) {
            cout << "Indeks " << i << ":\t";
            if (hashTable[i] == emptySlot) {
                cout << "[ Kosong ]" << endl;
            } else if (hashTable[i] == deleteSlot) {
                cout << "[ Dihapus ]" << endl;
            } else {
                cout << hashTable[i] << endl;
            }
        }
        cout << "==========================\n";
    }
};

int main() {
    int table_size; 

    int choice, key;
    
    cout<<"Masukkan Jumlah Table Size : ";
    cin>>table_size;
    
    DoubleHashing ht(table_size);

    do {
        cout<<"1. Sisipkan Kunci (Insert)"<<endl;
        cout<<"2. Cari Kunci (Search)"<<endl;
        cout<<"3. Hapus Kunci (Delete)"<<endl;
        cout<<"4. Tampilkan Tabel Hash"<<endl;
        cout<<"5. Selesai"<<endl;
        cout<<"Pilihan Anda: ";
        cin>>choice;

        if(choice == 1) {
            cout<<"Masukkan kunci yang akan disisipkan: ";
            cin>>key;
            ht.insert(key);
        } else if (choice == 2) {
            cout<<"Masukkan kunci yang akan dicari: ";
            cin>>key;
            int index = ht.search(key);
            if (index != -1) {
               cout << "-> Kunci " << key << " ditemukan di indeks " << index << "." << endl;
            } else {
                cout << "-> Kunci " << key << " tidak ditemukan." << endl;
            }
        } else if (choice == 3) {
            cout<<"Masukkan kunci yang akan dihapus: ";
            cin>>key;
            ht.remove(key);
        } else if (choice == 4) {
            ht.display();
        } else if (choice == 5) {
            cout<<"Program Selesai"<<endl;
        } else {
        	cout<<"Pilihan tidak valid. Silakan coba lagi"<<endl;
        }
    } while (choice != 5);

    return 0;
}
