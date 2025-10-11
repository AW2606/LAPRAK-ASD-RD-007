#include <iostream>     // Library standar untuk input-output
using namespace std;    // Agar bisa menggunakan cout, cin tanpa menulis std::

// ===============================
// Struktur Node untuk menyimpan data siswa
// ===============================
struct Node {
    char nama[50];  // Menyimpan nama siswa (maksimum 50 karakter)
    int nilai;      // Menyimpan nilai siswa
    Node* next;     // Pointer yang menunjuk ke node berikutnya
};

// Pointer global sebagai penanda elemen pertama (head) dari linked list
Node* head = NULL;

// ===============================
// Fungsi: tambahDataTerurut
// Tujuan: Menambahkan data siswa secara terurut (ascending berdasarkan nilai)
// ===============================
void tambahDataTerurut(char nama[], int nilai) {
    // Buat node baru
    Node* baru = new Node;

    // Salin nama dari input ke field nama node baru (manual karena pakai array char)
    int i = 0;
    while (nama[i] != '\0') {  // Ulangi sampai akhir string
        baru->nama[i] = nama[i];
        i++;
    }
    baru->nama[i] = '\0';     // Tambahkan karakter akhir string
    baru->nilai = nilai;      // Simpan nilai ke node baru
    baru->next = NULL;        // Set pointer next menjadi NULL (belum terhubung)

    // Jika list kosong atau nilai lebih kecil dari nilai node pertama (head)
    if (head == NULL || nilai < head->nilai) {
        // Sisipkan di awal list
        baru->next = head;  // Node baru menunjuk ke node lama (head)
        head = baru;        // Jadikan node baru sebagai head
    } 
    else {
        // Jika list tidak kosong, cari posisi yang tepat untuk menyisipkan
        Node* temp = head;

        // Telusuri hingga menemukan node dengan nilai lebih besar
        // atau hingga mencapai akhir list
        while (temp->next != NULL && temp->next->nilai < nilai) {
            temp = temp->next;
        }

        // Setelah posisi ditemukan, hubungkan node baru ke dalam list
        baru->next = temp->next; // Node baru menunjuk ke node setelah temp
        temp->next = baru;       // Node sebelumnya menunjuk ke node baru
    }

    cout << "Data berhasil ditambahkan secara terurut!\n";
}

// ===============================
// Fungsi: tampilkanData
// Tujuan: Menampilkan seluruh data siswa dari awal hingga akhir list
// ===============================
void tampilkanData() {
    if (head == NULL) { // Jika list kosong
        cout << "\nData masih kosong.\n";
        return;
    }

    Node* temp = head;  // Mulai dari node pertama (head)
    cout << "\n=== Daftar Nilai Siswa (Terurut Ascending) ===\n";

    // Telusuri list dan tampilkan semua data
    while (temp != NULL) {
        cout << "Nama : " << temp->nama << "\t| Nilai : " << temp->nilai << endl;
        temp = temp->next;  // Pindah ke node berikutnya
    }
}

// ===============================
// Fungsi utama (main program)
// Menyediakan menu interaktif bagi pengguna
// ===============================
int main() {
    int pilihan;   // Variabel untuk menyimpan pilihan menu
    char nama[50]; // Variabel untuk input nama siswa
    int nilai;     // Variabel untuk input nilai siswa

    do {
        // Tampilkan menu utama
        cout << "\n=== SISTEM NILAI SISWA TERURUT ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Bersihkan karakter newline (\n) agar getline tidak terganggu

        switch (pilihan) {
            case 1:
                // Input data siswa
                cout << "\nMasukkan Nama Siswa : ";
                cin.getline(nama, 50); // Membaca nama lengkap (bisa ada spasi)
                cout << "Masukkan Nilai      : ";
                cin >> nilai;
                cin.ignore(); // Bersihkan buffer sebelum kembali ke menu
                tambahDataTerurut(nama, nilai); // Panggil fungsi insert terurut
                break;

            case 2:
                // Tampilkan seluruh data siswa
                tampilkanData();
                break;

            case 3:
                // Keluar dari program
                cout << "\nTerima kasih!\n";
                break;

            default:
                // Jika pengguna memasukkan angka selain 1–3
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3); // Ulangi selama pengguna belum memilih keluar

    return 0; // Program selesai
}
