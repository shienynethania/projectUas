#include <iostream>
#include <string>
#include <ctime>    

using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

void tampilkanWaktu() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Waktu Restock: " << dt;
}

void tampilkanBarang(Barang barangList[], int jumlahBarang) {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang di daftar.\n";
        return;
    }
    cout << "\nDaftar Barang yang Tersedia:\n";
    for (int i = 0; i < jumlahBarang; ++i) {
        cout << "Nama Barang: " << barangList[i].nama << endl;
        cout << "Jumlah Stok: " << barangList[i].jumlah << " unit" << endl;
        cout << "Harga: Rp " << barangList[i].harga << endl;
        cout << "--------------------------------\n";
    }
}

void restockBarang(Barang barangList[], int& jumlahBarang, const string& namaBarang, int jumlahRestock, double hargaBarang) {
    if (jumlahRestock <= 0) {
        cout << "Jumlah yang di-restock tidak valid!" << endl;
        return;
    }

    for (int i = 0; i < jumlahBarang; ++i) {
        if (barangList[i].nama == namaBarang) {
            barangList[i].jumlah += jumlahRestock;
            cout << "Barang " << barangList[i].nama << " berhasil di-restock sebanyak " << jumlahRestock << " unit.\n";
            return;
        }
    }

    if (jumlahBarang < 10) {
        barangList[jumlahBarang++] = {namaBarang, jumlahRestock, hargaBarang};
        cout << "Barang baru " << namaBarang << " berhasil ditambahkan dengan jumlah " << jumlahRestock << " unit.\n";
    } else {
        cout << "Daftar barang sudah penuh! Tidak bisa menambah barang baru.\n";
    }
}

int main() {
    Barang barangList[10] = {
        {"Teh Botol", 50, 4000.0},
        {"Indomie", 100, 3000.0},
        {"Qtela", 75, 5000.0}
    };
    int jumlahBarang = 3;  

    int pilihan, jumlahRestock;
    double hargaBarang;
    string namaBarang;

    do {
        // tampilan
        cout << "\n=== Restocking Barang Supermarket ===\n";
        cout << "1. Tampilkan Daftar Barang\n";
        cout << "2. Restock Barang\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanBarang(barangList, jumlahBarang);
                break;

            case 2:
                cin.ignore();  
                cout << "Masukkan nama barang yang ingin di-restock: ";
                getline(cin, namaBarang);

                cout << "Masukkan jumlah barang yang ingin di-restock: ";
                cin >> jumlahRestock;

                if (jumlahRestock > 0) {
                    bool barangDitemukan = false;
                    for (int i = 0; i < jumlahBarang; ++i) {
                        if (barangList[i].nama == namaBarang) {
                            barangDitemukan = true;
                            break;
                        }
                    }

                    
                    if (!barangDitemukan) {
                        cout << "Masukkan harga barang (jika barang baru): ";
                        cin >> hargaBarang;
                    } else {
                        hargaBarang = 0;  
                    }

                    restockBarang(barangList, jumlahBarang, namaBarang, jumlahRestock, hargaBarang);
                    tampilkanWaktu();
                    tampilkanBarang(barangList, jumlahBarang);
                } else {
                    cout << "Jumlah restock tidak valid!\n";
                }
                break;

            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 3);  

    return 0;
}
