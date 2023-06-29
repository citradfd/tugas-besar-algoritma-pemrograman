#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

struct Pegawai {
    char NIP[10];
    char Nama[30];
    char Alamat[30];
    string gol;
    float gaji;
};

struct Node{
    Pegawai info;
    Node* next;
    Node* prev;
};

typedef Node *pointer;
typedef pointer List;

void createElement (pointer& pBaru);
string golPegawai (int gaji);
void insertFirst (List& first, pointer pBaru);
void insertLast (List& first, pointer pBaru);
void traversal (List first);
void deleteFirst (List& first, pointer& pHapus);
void deleteLast (List& first, pointer& pHapus);
void linearSearch (List first, pointer& pCari, char NIP[], int& found);
void insertAfter (List& first, pointer pBaru, pointer pCari);
void deleteAfter (List& first, pointer& pHapus, pointer pCari);
void deleteByKey (List& first, pointer& pHapus, pointer pCari);
void gajiMaks (List first);
void gajiRata (List first);
char menu();

int main(){
    List first = NULL;
    pointer pBaru, pHapus, pCari;
    char keyNIP[10];
    int opt2;
    int found = 0;
    cout << "----------Program List Data Pegawai----------\n";
    bool prgrmPeg = true;
    while (prgrmPeg){
        int opt = menu();
        switch(opt){
            case 1:
                createElement(pBaru);
                insertFirst(first, pBaru);
                traversal(first);
                break;
            case 2:
                createElement(pBaru);
                insertLast(first, pBaru);
                traversal(first);
                break;
            case 3:
                cout << "\nMasukkan NIP yang dicari : "; cin.get(keyNIP,10);
                cin.ignore();
                linearSearch(first, pCari, keyNIP, found);
                if (found){
                    cout << "\nData yang dicari telah ditemukan!" << endl;
                    createElement(pBaru);
                    insertAfter(first, pBaru, pCari);
                    traversal(first);
                }
                else{
                    cout << "\nData yang dicari tidak ditemukan!" << endl;
                }
                break;
            case 4:
                traversal(first);
                break;
            case 5:
                gajiMaks(first);
                break;
            case 6:
                gajiRata(first);
                break;
            case 7:
                deleteFirst(first, pHapus);
                cout << endl;
                traversal(first);
                break;
            case 8:
                deleteLast(first, pHapus);
                cout << endl;
                traversal(first);
                break;
            case 9:
                cout << "\nMasukkan NIP yang dicari\t: "; cin.get(keyNIP,10);
                cin.ignore();
                linearSearch(first, pCari, keyNIP, found);
                if (found) {
                    deleteByKey(first, pHapus, pCari);
                    cout << endl;
                    traversal(first);
                }
                else {
                    cout << "\nData yang dicari tidak ditemukan!" << endl;
                }
                break;
            case 10:    
                cout << "\nMasukkan NIP yang dicari\t: "; cin.get(keyNIP,10);
                cin.ignore();
                linearSearch(first, pCari, keyNIP, found);
                if (found) {
                    deleteAfter(first, pHapus, pCari);
                    cout << endl;
                    traversal(first);
                }
                else {
                    cout << "\nData Tidak Ditemukan!" << endl;
                }
                break;
            default:
                cout << "\nPilihan Tidak Valid!" << endl;
                break;
        }

        cout << "\nIngin melanjutkan program?(Pilih 1 atau 2)\n1. Ya\n2. Tidak " << endl;
        cout << "Pilihan\t: "; cin >> opt2; cin.ignore();
        
        if (opt2 == 1) {
            prgrmPeg = true;
        }
        else if (opt2 == 2) {
            prgrmPeg = false;
            cout << "\nTerima kasih telah menggunakan program ini" << endl;
        }
        else {
            prgrmPeg = false;
            cout << "\nNomor yang anda input salah" << endl;
        }
    }
}

void createElement (pointer& pBaru) {
    pBaru = new Node;
    cout << "\nData pegawai yang ingin ditambahkan:" << endl;
    cout << "NIP\t: "; cin.get(pBaru->info.NIP,10); cin.ignore();
    cout << "Nama\t: "; cin.get(pBaru->info.Nama,30); cin.ignore();
    cout << "Alamat\t: "; cin.get(pBaru->info.Alamat,30); cin.ignore();
    cout << "Gaji\t: "; cin >> pBaru->info.gaji; cin.ignore();
    pBaru->info.gol = golPegawai(pBaru->info.gaji);
    pBaru->next = NULL;
}
string golPegawai (int gaji) {
    string gol;
    if (gaji <= 1000000) {
    gol = "1A";
    }
    else if (gaji > 1000000 && gaji <= 2000000) {
    gol = "1B";
    }
    else if (gaji > 2000000 && gaji <= 3000000) {
    gol = "2A";
    }
    else if (gaji > 3000000 && gaji <= 4000000) {
    gol = "2B";
    }
    else if (gaji > 4000000 && gaji <= 5000000) {
    gol = "3A";
    }
    else if (gaji > 5000000 && gaji <= 6000000) {
    gol = "3B";
    }
    else if (gaji > 6000000 && gaji <= 7000000) {
    gol = "4A";
    }
    else if (gaji > 7000000) {
    gol = "4B";
    }
    return gol;
    }

void insertFirst (List& first, pointer pBaru) {
    if (first == NULL) {
        first = pBaru;
    }
    else {
        pBaru -> next = first;
        first = pBaru;
    }
}

void insertLast (List& first, pointer pBaru) {
    if (first == NULL) {
        first = pBaru;
    }
    else {
        pointer last = first;
        while (last -> next != NULL){
            last = last -> next;
        }
        last -> next = pBaru;
    }
}

void traversal (List first) {
    if (first == NULL) {
        cout << "\nList tidak kosong!" << endl;
    }
    else {
        pointer pBantu = first;
        cout << endl;
        cout << setw(10) << "NIP" << setw(30) << "Nama" << setw(30) <<
"Alamat" << setw(10) << "Gol" << setw(15) << "Gaji" << endl;
    do {
        cout << setw(10) << pBantu->info.NIP << setw(30) << pBantu->info.Nama << setw(30) << pBantu->info.Alamat;
        cout << setw(10) << pBantu->info.gol << setw(15) << fixed <<
setprecision(0) << pBantu->info.gaji << endl;
        pBantu = pBantu -> next;
    }
    while (pBantu != NULL);
    }
}

void deleteFirst (List& first, pointer& pHapus) {
    if (first == NULL) {
        pHapus = NULL;
    }
    else if (first -> next == NULL) {
        pHapus = first;
        first = NULL;
    }
    else {
        pHapus = first;
        first = first -> next;
        pHapus -> next = NULL;
    }
}
void deleteLast (List& first, pointer& pHapus) {
    if (first == NULL) {
        pHapus = NULL;
    }
    else if (first -> next == NULL) {
        pHapus = first;
        first = NULL;
    }
    else {
        pointer last = first;
        pointer precLast = NULL;
        while (last -> next != NULL) {
            precLast = last;
            last = last -> next;
        }
        pHapus = last;
        precLast -> next = NULL;
    }
}
void linearSearch (List first, pointer& pCari, char NIP[], int& found) {
    found = 0;
    pCari = first;
    while (found == 0 && pCari != NULL) {
        if (strcmp(pCari->info.NIP, NIP) == 0) {
            found = 1;
        }
        else {
            pCari = pCari -> next;
        }
    }
}

void insertAfter (List& first, pointer pBaru, pointer pCari) {
    if (pCari -> next == NULL) {
        pCari -> next = pBaru;
    }
    else {
        pBaru -> next = pCari -> next;
        pCari -> next = pBaru;
    }
}

void deleteAfter (List& first, pointer& pHapus, pointer pCari) {
    if (pCari -> next == NULL){
        pHapus = NULL;
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else {
        pHapus = pCari -> next;
        pCari -> next = pHapus -> next;
        pHapus -> next = NULL;
    }
}

void deleteByKey (List& first, pointer& pHapus, pointer pCari) {
    if (pCari == first) {
        deleteFirst(first, pHapus);
    }
    else if (pCari -> next == NULL) {
        deleteLast(first, pHapus);
    }
    else {
        deleteAfter(first, pHapus, pCari);
    }
}
void gajiMaks (List first) {
    pointer pBantu;
    float maksimal = 0;
    if (first == NULL) {
        cout << "\nList tidak kosong" << endl;
    }
    else {
        pBantu = first;
        do {
            if (pBantu->info.gaji > maksimal) {
                maksimal = pBantu->info.gaji;
            }
            pBantu = pBantu -> next;
        }
    while (pBantu != NULL);
        cout << "\nGaji Maksimum\t: Rp" << maksimal << endl;
    }
}

void gajiRata (List first) {
    pointer pBantu;
    float hasil, rata = 0;
    int i = 0;
    if (first == NULL) {
        cout << "\nList kosong!" << endl;
    }
    else {
        pBantu = first;
        do {
            rata += pBantu->info.gaji;
            i++;
            pBantu = pBantu -> next;
            hasil = rata/i;
        }
    while (pBantu != NULL);
        cout << "\nRata-Rata Gaji\t: Rp" << hasil << endl;
    }
}

char menu() {
    int opt;
    cout << "\nMenu Program Pegawai" << endl;
    cout << "1. Insert Data Pertama Pegawai" << endl;
    cout << "2. Insert Data Terakhir Pegawai" << endl;
    cout << "3. Insert Data Pegawai (After Key)" << endl;
    cout << "4. Tampilkan Seluruh List Data Pegawai" << endl;
    cout << "5. Tampilkan Gaji Maksimum Pegawai" << endl;
    cout << "6. Tampilkan Rata-Rata Gaji Pegawai" << endl;
    cout << "7. Hapus Data Pertama Pegawai" << endl;
    cout << "8. Hapus Data Terakhir Pegawai" << endl;
    cout << "9. Hapus Data Pegawai (By Key)" << endl;
    cout << "10. Hapus Data Pegawai (After Key)" << endl;
    cout << "Pilihan\t: "; cin >> opt; cin.ignore();
    return opt;
}