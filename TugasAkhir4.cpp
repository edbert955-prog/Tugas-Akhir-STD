#include <iostream>
#include <string>

using namespace std;

const int MAX_HISTORY = 10;
string historyStack[MAX_HISTORY];
int topIdx = -1;

bool isHistoryEmpty();
bool isHistoryFull();
void visitNewPage(string url);
void pressBackButton();
void showCurrentPage();
void displayHistory();

int main() {
    int choice;
    string url;

    do {
        cout << "\n=== SIMULASI RIWAYAT BROWSER ===\n";
        cout << "1. Kunjungi Halaman Web Baru\n";
        cout << "2. Gunakan Tombol 'Kembali'\n";
        cout << "3. Lihat Halaman Saat Ini\n";
        cout << "4. Tampilkan Riwayat Kunjungan\n";
        cout << "5. Keluar dari Browser\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            cout << "Masukkan URL halaman baru: ";
            getline(cin, url);
            visitNewPage(url);
        } else if (choice == 2) {
            pressBackButton();
        } else if (choice == 3) {
            showCurrentPage();
        } else if (choice == 4) {
            displayHistory();
        }

    } while (choice != 5);

    cout << "\nBrowser ditutup. Terima kasih!\n";
    return 0;
}

bool isHistoryEmpty() {
    return topIdx == -1;
}

bool isHistoryFull() {
    return topIdx == MAX_HISTORY - 1;
}

void visitNewPage(string url) {
    if (isHistoryFull()) {
        cout << "[!] Riwayat sudah penuh. Tidak bisa membuka halaman baru.\n";
        return;
    }
    historyStack[++topIdx] = url;
    cout << "-> Berhasil membuka dan menyimpan halaman: " << url << endl;
}

void pressBackButton() {
    if (isHistoryEmpty()) {
        cout << "[!] Tidak ada halaman sebelumnya di dalam riwayat.\n";
        return;
    }
    cout << "<- Tombol 'Kembali' ditekan. Meninggalkan halaman: " << historyStack[topIdx] << endl;

    topIdx--;

    if (!isHistoryEmpty()) {
        cout << "   Anda sekarang kembali ke halaman: " << historyStack[topIdx] << endl;
    } else {
        cout << "   Riwayat kunjungan sekarang kosong.\n";
    }
}

void showCurrentPage() {
    if (isHistoryEmpty()) {
        cout << "[!] Anda tidak sedang membuka halaman apapun.\n";
        return;
    }
    cout << "Halaman saat ini adalah: " << historyStack[topIdx] << endl;
}

void displayHistory() {
    if (isHistoryEmpty()) {
        cout << "[!] Riwayat kunjungan masih kosong.\n";
        return;
    }
    cout << "\n--- Riwayat Kunjungan (Dari Terbaru ke Terlama) ---\n";
    for (int i = topIdx; i >= 0; --i) {
        if (i == topIdx) {
            cout << "--> " << historyStack[i] << " (Halaman Saat Ini)\n";
        } else {
            cout << "    " << historyStack[i] << "\n";
        }
    }
    cout << "--------------------------------------------------\n";
}