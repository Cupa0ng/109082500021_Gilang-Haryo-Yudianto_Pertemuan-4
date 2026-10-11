# <h1 align="center">Modul 3  ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Gilang Haryo Yudianto- 109082500021</p>

## Dasar Teori

### A. Abstract Data Type (ADT)

Abstract Data Type (ADT) merupakan model data statik secara matematis dan logis yang terdiri dari suatu tipe data beserta operasi dasar (primitif) penyertanya. Definisi ADT yang utuh mencakup aturan invarian dan aksioma untuk mengatur perilaku objek, serta memungkinkan penyusunan tipe dari ADT lain—misalnya ADT waktu yang dibangun dari gabungan ADT JAM dan DATE, atau bentuk geometris seperti segiempat yang berasal dari dua buah titik (Point).

### B. Primitif ADT (Operasi Dasar)

Dalam pemrograman prosedural, primitif adalah fungsi atau prosedur fundamental yang berfungsi mengelola dan memanipulasi Abstract Data Type (ADT). Dilihat dari kegunaannya, primitif diklasifikasikan ke dalam sembilan kelompok utama:
#### 1. Konstruktor (Kreator)
Berperan menetapkan nilai awal suatu tipe data (umumnya menggunakan awalan Make). Tahap ini wajib dilewati oleh setiap variabel atau objek baru dari tipe tersebut.
#### 2. Selektor
Berfungsi mengambil atau mengakses data dari komponen yang menyusun tipe tersebut (biasanya diawali kata Get).
#### 3. Prosedur Pengubah
 Digunakan untuk mengubah atau memperbarui isi data di dalam komponen tipe tersebut.
#### 4. Validator Komponen
Berupa fungsi penguji untuk memvalidasi apakah kombinasi nilai yang dimasukkan sudah memenuhi syarat sah pembentukan tipe data tersebut.
#### 5. Destruktor (Dealokator)
Bertugas menghapus objek sekaligus membebaskan kembali ruang memori yang sebelumnya digunakan.
#### 6. Operasi Baca/Tulis
Berfungsi sebagai penghubung untuk menangani proses masukan (input) dan keluaran (output) pada perangkat.
#### 7. Operator Relasional
Digunakan untuk membandingkan dua objek dari tipe yang sama (seperti menentukan kesamaan, atau mana yang lebih besar/kecil).
#### 8. Operator Aritmatika
Merupakan operasi matematika khusus yang dirancang untuk tipe bentukan, sebab operator bawaan (seperti dalam C/C++) biasanya hanya mendukung tipe angka standar.
#### 9. Konversi
Berfungsi mengubah format nilai dari tipe bentukan tersebut ke tipe data dasar, ataupun sebaliknya.


### C. Modularisasi dan Implementasi AD

Secara praktis, struktur ADT dibangun menggunakan tiga komponen dasar: file spesifikasi header (.h), file realisasi body (.c/.cpp), dan driver sebagai antarmuka utama. File header berfokus pada deklarasi aturan tipe data dan cetak biru fungsi atau prosedur—termasuk parameter, batas nilai (range/domain), serta status awal dan akhir (I.S. dan F.S.). Sementara itu, file body merealisasikan cetak biru tersebut ke dalam kode program aktual. Agar sistem lebih modular dan mudah dirawat, proses realisasi ini idealnya memanfaatkan fungsi pembangun (constructor) dan pengambil nilai (selector) yang ada.

## Guided 

### 1. File mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDE
#define MAHASISWA_H_INCLUDE

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif //MAHASISWA_H_INCLUDE

```
Kode C++ ini menerapkan file header untuk membuat struktur data (ADT) mahasiswa yang rapi dan modular. Di dalamnya, sebuah struct dirancang untuk menampung tiga data penting: array karakter berukuran 10 komponen untuk NIM, serta dua variabel integer untuk menyimpan nilai. Proses pembaruan data dilakukan lewat prosedur inputMhs menggunakan metode call by reference agar langsung mengubah variabel asli. Sementara untuk perhitungan, fungsi rata2 menggunakan metode call by value yang mengembalikan nilai rata-rata bertipe float. Tak lupa, mekanisme include guard (#ifndef, #define, #endif) juga disematkan agar file tidak dibaca berulang kali saat kompilasi, sehingga arsitektur program menjadi lebih terstruktur dan efisien.

### 2. File mahasiswa.cpp

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
    {80, 85, 90},
    {75, 80, 85},
    {90, 95, 100}
};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
File C++ ini memisahkan implementasi ADT mahasiswa dari deklarasinya lewat file mahasiswa.h dan <iostream>. Prosedur inputMhs menggunakan call by reference agar input nilai langsung tersimpan ke variabel aslinya, sementara fungsi rata2 menghitung nilai rata-rata berbasis float agar hasilnya berupa angka desimal yang presisi. Secara keseluruhan, pemisahan ini membuat struktur kode modular dan lebih mudah dikelola.


### 3. File main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std ;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
}
```
Program C++ ini memperlihatkan pemakaian ADT mahasiswa dari file lain. File ini memanggil #include "mahasiswa.h" agar dapat mengenali struct mahasiswa beserta prosedur inputMhs dan fungsi rata2, serta #include <iostream> untuk output ke layar. Di dalam main, dibuat sebuah variabel mhs bertipe mahasiswa, lalu variabel tersebut dikirim ke prosedur inputMhs yang menerimanya secara call by reference, sehingga nim, nilai1, dan nilai2 yang diketik pengguna langsung tersimpan di mhs. Setelah itu, mhs dikirim ke fungsi rata2 yang menerimanya secara call by value, menghitung rata-rata dari kedua nilai, dan hasilnya langsung dicetak ke layar dengan label “rata-rata = “. Secara keseluruhan, file ini dibuat untuk menunjukkan cara memanggil operasi ADT dari file yang berbeda, sehingga program utama tetap singkat dan terstruktur.


## Unguided 

### 1. program yang dapat menyimpan data mahasiswa

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Output 1](https://github.com/Cupa0ng/109082500021_Gilang-Haryo-Yudianto_Pertemuan-4/blob/main/Output_nilaihms/Output_nilaihms.png)

Kode C++ ini menerapkan konsep array of struct untuk mengelola data mahasiswa dengan kapasitas maksimal 10 orang. Tipe data bentukan struct Mahasiswa dirancang untuk menampung data nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Program memanfaatkan konstanta MAX senilai 10 untuk membatasi ukuran array mhs. Melalui mekanisme perulangan do-while, program memastikan jumlah data yang diinput pengguna valid dan tidak melebihi kapasitas memori yang tersedia. Proses input dilakukan secara sekuensial memakai perulangan for, di mana perintah getline digunakan agar nama yang mengandung spasi dapat terbaca, dan cin.ignore() dipakai untuk membersihkan sisa karakter newline pada buffer. Nilai akhir dihitung secara otomatis oleh fungsi hitungNilaiAkhir menggunakan bobot nilai 30% UTS, 40% UAS, dan 30% tugas. Pada tahap akhir, visualisasi data disajikan dalam bentuk tabel rapi di layar menggunakan perulangan for dengan tabulasi (\t) sebagai pemisah antarkolom. Secara garis besar, kode ini menjadi contoh nyata implementasi penggabungan fungsi, struct, dan array dalam memproses data majemuk pada C++.



### 2. 3 FIle Terpisah 

### pelajaran.h 
```C++
#ifndef MAHASISWA_H_INCLUDE
#define MAHASISWA_H_INCLUDE

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif //MAHASISWA_H_INCLUDE
```
### pelajaran.cpp 
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### main.cpp 
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std ;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
### Output Unguided 2 :

##### Output 2
![Output 2](https://github.com/Cupa0ng/109082500021_Gilang-Haryo-Yudianto_Pertemuan-4/blob/main/Output_adtpelajaran/Output_adtpelajaran.png)

### 1 file pelajaran.h
File header C++ ini berfungsi sebagai kerangka yang mendefinisikan ADT pelajaran tanpa menyertakan detail implementasinya. Di dalamnya terdapat struct pelajaran yang terdiri dari dua field string (namaMapel dan kodeMapel), serta deklarasi untuk fungsi create_pelajaran dan prosedur tampil_pelajaran. Selain itu, file ini dilengkapi dengan header guard (#ifndef, #define, #endif) untuk mencegah terjadinya redundansi pembacaan saat proses kompilasi.

### 2. file pelajaran.cpp
File ini memuat implementasi fungsi dan prosedur dari deklarasi pada pelajaran.h. Fungsi create_pelajaran bertugas membuat variabel bertipe pelajaran dengan mengisi namaMapel serta kodeMapel berdasarkan parameter input, lalu mengembalikannya. Sementara itu, prosedur tampil_pelajaran berfungsi mencetak isi kedua field tersebut ke layar menggunakan label “nama pelajaran” dan “nilai”. Secara menyeluruh, file ini mencontohkan penerapan dan pemisahan antara deklarasi data ADT di file header dengan implementasi kodenya di file .cpp.

## 3. file main.cpp
File ini berisi program utama untuk menguji ADT pelajaran. Di dalam fungsi main, variabel namapel (diisi 'Struktur Data') dan kodepel (diisi 'STD') dikirim ke fungsi create_pelajaran lalu disimpan ke variabel pel. Hasilnya dicetak via tampil_pelajaran menjadi dua baris: nama pelajaran dan nilainya. Secara garis besar, kode ini memperlihatkan cara memanggil ADT modular menggunakan #include "pelajaran.h" agar fungsi utama tetap ringkas.


### 3. Program 2 buah array 2d berukuran 3x3
```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp;
    temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20;
    int *ptr1, *ptr2;
    int baris, kolom;

    ptr1 = &x;
    ptr2 = &y;

    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << endl << "Tukar isi array A dan B pada posisi tertentu" << endl;
    cout << "Masukkan baris (0-2) : ";
    cin >> baris;
    cout << "Masukkan kolom (0-2) : ";
    cin >> kolom;

    tukarArray(A, B, baris, kolom);

    cout << endl << "Setelah ditukar" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << endl << "Sebelum tukar pointer" << endl;
    cout << "x = " << *ptr1 << endl;
    cout << "y = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Setelah tukar pointer" << endl;
    cout << "x = " << *ptr1 << endl;
    cout << "y = " << *ptr2 << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 3
![Output 3](https://github.com/Cupa0ng/109082500021_Gilang-Haryo-Yudianto_Pertemuan-4/blob/main/Output_array2d/Output_array2d.png)


Program C++ ini mendemonstrasikan penggunaan array dua dimensi 3x3 bertipe integer dan konsep pointer. Sejak awal, array A dan B telah diinisialisasi dengan nilai tertentu, sementara variabel x (bernilai 10) dan y (bernilai 20) alamat memorinya disimpan ke dalam ptr1 dan ptr2. Data dari kedua array tersebut ditampilkan dalam bentuk matriks menggunakan fungsi tampilArray lewat perulangan for bersarang. Program ini juga memfasilitasi interaksi pengguna untuk menentukan baris dan kolom guna menukar elemen array A dan B di posisi tersebut melalui fungsi tukarArray. Selain itu, terdapat fungsi tukarPointer yang memanfaatkan operator dereferensi untuk menukar nilai variabel x dan y secara tidak langsung. Melalui seluruh proses ini, program berhasil memperlihatkan cara mendeklarasikan array 2D, melakukan looping, memodifikasi elemen matriks, serta mengimplementasikan pointer.

## Kesimpulan
Modul 3 membahas struktur data dasar dalam C++ melalui tiga latihan program untuk menciptakan kode yang rapi, odular, dan efisien. Latihan pertama membandingkan penyimpanan data mahasiswa (array of struct vs array terpisah) dan penghitungan nilai akhir dengan fungsi. Latihan kedua menerapkan modulasi kode menggunakan Abstract Data Type (ADT) yang dipecah ke dalam tiga file terpisah (header, implementasi, dan main). Latihan ketiga memadukan array 2D 3x3 dengan pointer untuk memanipulasi dan menukar nilai variabel langsung di memori menggunakan operator dereferensi dan alamat. Secara keseluruhan, modul ini mengajarkan cara efektif mengelola serta mengolah data di memori.


## Referensi
[1] Malik, D. S. (2010). Data Structures Using C++ (2nd ed.). Boston: Cengage Learning.<br>
[2] Drozdek, A. (2013). Data Structures and Algorithms in C++ (4th ed.). Boston: Cengage Learning.<br>
[3] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Boston: Pearson.<br>
[4] Deitel, P., & Deitel, H. (2017). C++ How to Program (10th ed.). Boston: Pearson.<br>
[5] Liem, I. (2003). Diktat Pemrograman Prosedural. Bandung: Departemen Teknik Informatika Institut Teknologi Bandung.<br>

