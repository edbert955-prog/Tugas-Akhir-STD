#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<pair<int, string>> books = {
        {101, "Pemrograman C++ untuk Pemula"},
        {102, "Algoritma dan Struktur Data"},
        {103, "Dasar-dasar Jaringan Komputer"},
        {104, "Sistem Operasi: Teori dan Praktik"},
        {105, "Basis Data Relasional"},
        {106, "Rekayasa Perangkat Lunak"},
        {107, "Matematika Diskrit"},
        {108, "Interaksi Manusia dan Komputer"},
        {109, "Kecerdasan Buatan"},
        {110, "Keamanan Siber"}
    };

    int n = static_cast<int>(books.size()); 
    int targetId;

    cout << "=== Sistem Pencarian Buku (Sequential Search Sentinel) ===\n";
    cout << "Masukkan ID buku yang ingin dicari: ";
    if (!(cin >> targetId)) {
        cout << "Input tidak valid.\n";
        return 1;
    }

    books.push_back({targetId, "[SENTINEL]"});

    int i = 0;
    while (books[i].first != targetId) {
        i++;
    }

    if (i < n) {
        cout << "\nBuku ditemukan!\n";
        cout << "ID   : " << books[i].first << "\n";
        cout << "Judul: " << books[i].second << "\n";
    } else {
        cout << "\nBuku dengan ID " << targetId << " tidak ditemukan di katalog.\n";
    }

    return 0;
}
