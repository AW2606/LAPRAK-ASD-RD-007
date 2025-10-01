#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan ukuran array: ";
    cin >> n;

    int arr[n];   
    int *ptr = arr; 

    
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);   
    }

   
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    
    for (int i = 0; i < n / 2; i++) {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + (n - 1 - i));
        *(ptr + (n - 1 - i)) = temp;
    }

   
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}
