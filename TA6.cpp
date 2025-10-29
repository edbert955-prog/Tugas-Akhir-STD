#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;

struct DataBunga {
    string nama;
    int stok;
    double harga;
};

struct Node {
    int key; 
    DataBunga value;
    Node* next;
};

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

void insert(Node* table[], int key, string nama, int stok, double harga) {
    int index = hashFunction(key);
    Node* cur = table[index];

    while (cur != nullptr) {
        if (cur->key == key) {
            cur->value.nama = nama;
            cur->value.stok = stok;
            cur->value.harga = harga;
            cout << "\n(Info: Data ID " << key << " berhasil diperbarui)\n";
            return;
        }
        cur = cur->next;
    }

    Node* baru = new Node;
    baru->key = key;
    baru->value.nama = nama;
    baru->value.stok = stok;
    baru->value.harga = harga;

    baru->next = table[index];
    table[index] = baru;
    cout << "\n(Info: Bunga dengan ID " << key << " berhasil ditambahkan)\n";
}

Node* search(Node* table[], int key) {
    int index = hashFunction(key);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->key == key) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void removeKey(Node* table[], int key) {
    int index = hashFunction(key);
    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (cur->key == key) {
            if (prev == nullptr) {
                table[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            cout << "\n(Info: Bunga dengan ID " << key << " berhasil dihapus)\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "\n(Info: Bunga dengan ID " << key << " tidak ditemukan, gagal dihapus)\n";
}

void display(Node* table[]) {
    cout << "\n--- INVENTARIS TOKO BUNGA SAAT INI ---\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        Node* tmp = table[i];
        
        if (tmp == nullptr) {
            cout << "Kosong";
        }

        while (tmp != nullptr) {
            cout << "[ID:" << tmp->key 
                 << ", Nama: " << tmp->value.nama
                 << ", Stok: " << tmp->value.stok
                 << ", Harga: Rp" << tmp->value.harga << "] -> ";
            tmp = tmp->next;
        }
        
        if (table[i] != nullptr) {
            cout << "NULL";
        }
        cout << "\n";
    }
    cout << "----------------------------------------\n";
}

int main() {
    Node* table[SIZE];
    initTable(table);

    int pilihan;
    int idBunga, stokBunga;
    string namaBunga;
    double hargaBunga;
    Node* hasil;

    do {
        cout << "\n===== SISTEM INVENTARIS TOKO BUNGA =====\n";
        cout << "1. Tambah / Update Data Bunga\n";
        cout << "2. Cari Bunga (berdasarkan ID)\n";
        cout << "3. Hapus Bunga (berdasarkan ID)\n";
        cout << "4. Tampilkan Seluruh Inventaris\n";
        cout << "5. Keluar\n";
        cout << "----------------------------------------\n";
        cout << "Masukkan pilihan Anda (1-5): ";
        
        while (!(cin >> pilihan)) {
            cout << "Input tidak valid. Masukkan angka (1-5): ";
            cin.clear();
            cin.ignore(); 
        }
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "--- Tambah/Update Bunga ---\n";
                cout << "Masukkan ID Bunga (angka): ";
                while (!(cin >> idBunga)) {
                    cout << "ID harus angka. Coba lagi: ";
                    cin.clear();
                    cin.ignore(); 
                }
                cin.ignore(); 

                cout << "Masukkan Nama Bunga: ";
                getline(cin, namaBunga);

                cout << "Masukkan Stok Bunga (angka): ";
                while (!(cin >> stokBunga)) {
                    cout << "Stok harus angka. Coba lagi: ";
                    cin.clear();
                    cin.ignore(); 
                }

                cout << "Masukkan Harga Bunga (misal: 5000): ";
                while (!(cin >> hargaBunga)) {
                    cout << "Harga harus angka. Coba lagi: ";
                    cin.clear();
                    cin.ignore(); 
                }
                
                insert(table, idBunga, namaBunga, stokBunga, hargaBunga);
                break;
            
            case 2:
                cout << "--- Cari Bunga ---\n";
                cout << "Masukkan ID Bunga yang dicari: ";
                while (!(cin >> idBunga)) {
                    cout << "ID harus angka. Coba lagi: ";
                    cin.clear();
                    cin.ignore(); 
                }

                hasil = search(table, idBunga);
                if (hasil != nullptr) {
                    cout << "\n(Info: Bunga Ditemukan!)\n";
                    cout << "ID    : " << hasil->key << "\n";
                    cout << "Nama  : " << hasil->value.nama << "\n";
                    cout << "Stok  : " << hasil->value.stok << " tangkai\n";
                    cout << "Harga : Rp" << hasil->value.harga << "\n";
                } else {
                    cout << "\n(Info: Bunga dengan ID " << idBunga << " tidak ditemukan)\n";
                }
                break;

            case 3:
                cout << "--- Hapus Bunga ---\n";
                cout << "Masukkan ID Bunga yang akan dihapus: ";
                while (!(cin >> idBunga)) {
                    cout << "ID harus angka. Coba lagi: ";
                    cin.clear();
                    cin.ignore(); 
                }
                removeKey(table, idBunga);
                break;

            case 4:
                display(table);
                break;

            case 5:
                cout << "\nTerima kasih telah menggunakan sistem. Sampai jumpa!\n";
                break;

            default:
                cout << "\n(Error: Pilihan tidak valid. Silakan pilih 1-5)\n";
        }

    } while (pilihan != 5);

    return 0;
}