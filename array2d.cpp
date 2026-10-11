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