#include <iostream>     // Header standar untuk input-output
using namespace std;    // Agar tidak perlu menulis std:: di setiap penggunaan

// ======================
// Struktur Node (elemen Linked List)
// ======================
struct Node {
    char nama[50];  // Menyimpan nama siswa (maks. 50 karakter)
    int nilai;      // Menyimpan nilai siswa
    Node* next;     // Pointer yang menunjuk ke node berikutnya
};

// Pointer awal dari Linked List (list dimulai dari sini)
Node* head = NULL;

// ======================
// Fungsi untuk menambahkan data di akhir list
// ======================
void tambahData(char nama[], int nilai) {
    // Buat node baru
    Node* baru = new Node;

    // Salin data nama ke dalam node baru (manual karena menggunakan char[])
    int i = 0;
    while (nama[i] != '\0') {
        baru->nama[i] = nama[i];
        i++;
    }
    baru->nama[i] = '\0';   // Tambahkan karakter akhir string
    baru->nilai = nilai;    // Isi nilai
    baru->next = NULL;      // Node baru belum punya penerus (next = NULL)

    // Jika list masih kosong, jadikan node ini sebagai head
    if (head == NULL)
        head = baru;
    else {
        // Jika sudah ada data, telusuri hingga node terakhir
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        // Sambungkan node baru di akhir list
        temp->next = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
}

// ======================
// Fungsi untuk menampilkan semua data siswa
// ======================
void tampilkanData() {
    // Jika list kosong
    if (head == NULL) {
        cout << "\nData masih kosong.\n";
        return;
    }

    // Jika ada data, tampilkan semuanya
    Node* temp = head;
    cout << "\n=== Daftar Nilai Siswa ===\n";
    while (temp != NULL) {
        // Menampilkan nama dan nilai setiap node
        cout << "Nama : " << temp->nama << "\t| Nilai : " << temp->nilai << endl;
        temp = temp->next; // Pindah ke node berikutnya
    }
}

// ======================
// Fungsi utama (main program)
// ======================
int main() {
    int pilihan;   // Untuk memilih menu
    char nama[50]; // Input nama siswa
    int nilai;     // Input nilai siswa

    do {
        // Menu utama
        cout << "\n=== SISTEM NILAI SISWA DINAMIS ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan karakter newline (\n) agar input berikutnya tidak terganggu

        switch (pilihan) {
            case 1:
                // Input data siswa baru
                cout << "\nMasukkan Nama Siswa : ";
                cin.getline(nama, 50); // Membaca nama lengkap (bisa mengandung spasi)
                cout << "Masukkan Nilai      : ";
                cin >> nilai;
                cin.ignore(); // Bersihkan newline sebelum kembali ke menu
                tambahData(nama, nilai); // Panggil fungsi untuk menambah data
                break;

            case 2:
                // Menampilkan semua data siswa
                tampilkanData();
                break;

            case 3:
                // Keluar dari program
                cout << "\nTerima kasih!\n";
                break;

            default:
                // Jika input menu tidak sesuai
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 3); // Ulangi selama pilihan bukan "Keluar"

    return 0; // Program selesai
}
