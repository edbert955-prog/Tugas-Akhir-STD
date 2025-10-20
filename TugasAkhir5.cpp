#include <iostream>

using namespace std;

struct Node {
    int key; 
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } 
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

bool searchNode(Node* root, int key) {
    if (!root) {
        return false;
    }
    if (root->key == key) {
        return true;
    }

    if (key < root->key) {
        return searchNode(root->left, key);
    }

    return searchNode(root->right, key);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int findMin(Node* root) {
    if (!root) return -1; 
    while (root->left) {
        root = root->left;
    }
    return root->key;
}

int findMax(Node* root) {
    if (!root) return -1; 
    while (root->right) {
        root = root->right;
    }
    return root->key;
}

int countNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

long long sumNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return root->key + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = nullptr; 
    int pilih, id;

    do {
        cout << "\n=== SISTEM MANAJEMEN ID ANGGOTA KLUB ALGORHYTHM ===\n";
        cout << "1. Daftarkan Anggota Baru (Insert ID)\n";
        cout << "2. Verifikasi Keanggotaan (Search ID)\n";
        cout << "3. Tampilkan Semua ID Terurut (Inorder)\n";
        cout << "4. Tampilkan Urutan Preorder (Backup View)\n";
        cout << "5. Tampilkan Urutan Postorder\n";
        cout << "6. Cari ID Anggota Terkecil (Pertama)\n";
        cout << "7. Cari ID Anggota Terbesar (Terbaru)\n";
        cout << "8. Hitung Total Anggota\n";
        cout << "9. Jumlahkan Semua Nilai ID\n";
        cout << "10. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan ID Anggota Baru: ";
                cin >> id;
                root = insertNode(root, id);
                cout << "ID " << id << " berhasil didaftarkan.\n";
                break;
            case 2:
                cout << "Masukkan ID yang ingin diverifikasi: ";
                cin >> id;
                cout << (searchNode(root, id) ? "Status: Anggota DITEMUKAN" : "Status: Anggota TIDAK DITEMUKAN") << "\n";
                break;
            case 3:
                cout << "Daftar ID Anggota (Terurut): ";
                inorder(root);
                cout << "\n";
                break;
            case 4:
                cout << "Daftar ID Anggota (Preorder): ";
                preorder(root);
                cout << "\n";
                break;
            case 5:
                cout << "Daftar ID Anggota (Postorder): ";
                postorder(root);
                cout << "\n";
                break;
            case 6:
                cout << "ID Anggota Terkecil: " << findMin(root) << "\n";
                break;
            case 7:
                cout << "ID Anggota Terbesar: " << findMax(root) << "\n";
                break;
            case 8:
                cout << "Jumlah Total Anggota: " << countNodes(root) << "\n";
                break;
            case 9:
                cout << "Jumlah dari Semua Nilai ID: " << sumNodes(root) << "\n";
                break;
            case 10:
                cout << "Terima kasih telah menggunakan sistem!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilih != 10);

    return 0;
}