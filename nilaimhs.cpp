#include <iostream>
using namespace std;

float hitung(float uts, float uas, float tugas) {
    float hasil;
    hasil = 0.3 * uts + 0.4 * uas + 0.3 * tugas;
    return hasil;
}

int main() {
    string nama[10];
    string nim[10];
    float uts[10], uas[10], tugas[10], akhir[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> nama[i];
        cout << "NIM : ";
        cin >> nim[i];
        cout << "UTS : ";
        cin >> uts[i];
        cout << "UAS : ";
        cin >> uas[i];
        cout << "Tugas : ";
        cin >> tugas[i];

        akhir[i] = hitung(uts[i], uas[i], tugas[i]);
    }

    cout << endl;
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << nama[i] << endl;
        cout << "NIM : " << nim[i] << endl;
        cout << "UTS : " << uts[i] << endl;
        cout << "UAS : " << uas[i] << endl;
        cout << "Tugas : " << tugas[i] << endl;
        cout << "Nilai Akhir : " << akhir[i] << endl;
        cout << endl;
    }

    return 0;
}