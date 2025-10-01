#include <iostream>
using namespace std;

void jumlahGanjil(int *x, int y) {
	*x = 0;
	for (int i = 1; i <= y; i++) {
		if (i % 2 != 0) {
			*x += i;
		}
	}
}

int main() {
	int y, hasil;
	cout << "Masukkan nilai y: ";
	cin >> y;

	jumlahGanjil(&hasil, y);
	cout << "Hasil penjumlahan bilangan ganjil 1 sampai " << y << " adalah: " << hasil << endl;

	return 0;
}
