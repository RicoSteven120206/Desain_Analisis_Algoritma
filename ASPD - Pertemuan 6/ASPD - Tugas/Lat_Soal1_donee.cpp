#include <iostream>
using namespace std;

class Mahasiswa
{
    private:
        string nama;
        string nim;
        float nilai;
    
    public:
        void setData(string nama_, string nim_, float nilai_)
        {
            nama = nama_;
            nim = nim_;
            nilai = nilai_;
        }

        int getNilai()
        {
            return nilai;
        }
};

void swap(Mahasiswa &val1, Mahasiswa &val2)
{
    Mahasiswa temp = val1;
    val1 = val2;
    val2 = temp;
}

int partition(Mahasiswa *siswa, int low, int high) {

    float pivot = siswa[high].getNilai();

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (siswa[j].getNilai() < pivot) {
            i++;
            swap(siswa[i], siswa[j]);
        }
    }
    
    swap(siswa[i + 1], siswa[high]);  
    return i + 1;
}

void quickSort(Mahasiswa *siswa, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(siswa, low, high);

        quickSort(siswa, low, pi - 1);
        quickSort(siswa, pi + 1, high);
    }
}

int main()
{
    Mahasiswa mahasiswa[5];

    for (int i = 0; i < 5; i++)
    {
        string nama, npm;
        float nilai;

        cout << "Nama : ";
        getline(cin, nama);
        cout << "NPM : ";
        cin >> npm;

        cout << "nilai : ";
        cin >> nilai;
        cin.ignore();

        mahasiswa[i].setData(nama, npm, nilai);
    }

    quickSort(mahasiswa, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << mahasiswa[i].getNilai() << ' ';
    }
}
