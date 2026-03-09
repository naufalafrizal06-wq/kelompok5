#include <iostream>
using namespace std;

int jumlahAnggota = 0;

string nama[100];
string buku[100];
int lamaPinjam[14];

void tambahAnggota();
void pinjamBuku();
void kembalikanBuku();
void tampilData();

int main() {
    int pilih;

    do {
        cout << "\n=== SISTEM PERPUSTAKAAN ===\n";
        cout << "1. Tambah Anggota\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch(pilih) {
            case 1: tambahAnggota(); break;
            case 2: pinjamBuku(); break;
            case 3: kembalikanBuku(); break;
            case 4: tampilData(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan salah!\n";
        }

    } while (pilih != 5);

    return 0;
}

void tambahAnggota() {
    cout << "Nama anggota: ";
    getline(cin, nama[jumlahAnggota]);
    jumlahAnggota++;
    cout << "id anggota: " << jumlahAnggota - 1 << endl;
    cout << "Anggota berhasil ditambahkan!\n";
}

void pinjamBuku() {
    int id;
    cout << "Masukkan ID anggota: ";
    cin >> id;
    cin.ignore();
    cout << "Judul buku: ";
    getline(cin, buku[id]);
    cout << "Lama pinjam (hari): ";
    cin >> lamaPinjam[id];
    cout << "Buku berhasil dipinjam!\n";
}

void kembalikanBuku() {
    int id;
    cout << "Masukkan ID anggota: ";
    cin >> id;
    cin.ignore();

    if (buku[id].empty()) {
        cout << "Tidak sedang meminjam buku!\n";
    } else {
        buku[id] = "";
        lamaPinjam[id] = 0;
        cout << "Buku berhasil dikembalikan!\n";
    }
}

void tampilData() {
    cout << "\n=== DATA ANGGOTA ===\n";

    for (int i = 0; i < jumlahAnggota; i++) {
        cout << "\nID: " << i;
        cout << "\nNama: " << nama[i];

        if (buku[i].empty()) {
            cout << "\nStatus: Tidak sedang meminjam";
        } else {
            cout << "\nStatus: Sedang meminjam";
            cout << "\nJudul Buku: " << buku[i];
            cout << "\nLama Pinjam: " << lamaPinjam[i] << " hari";
        }
        cout << "\n-------------------";
    }
}