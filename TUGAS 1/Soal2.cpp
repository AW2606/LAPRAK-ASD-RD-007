#include <iostream>
using namespace std;


void operasiMatematika(int *x, int y, long long *z) {
    *x = 0;     
    *z = 1;     

    for (int n = 1; n <= y; n++) {
        *x += n * n;      
        *z *= (2 * n - 1); 
    }
}

int main() {
    int y, hasilX;
    long long hasilZ;  

    cout << "Masukkan nilai y: ";
    cin >> y;

    operasiMatematika(&hasilX, y, &hasilZ);

    cout << "Hasil penjumlahan kuadrat (x): " << hasilX << endl;
    cout << "Hasil perkalian bilangan ganjil (z): " << hasilZ << endl;

    return 0;
}
