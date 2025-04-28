#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Menambahkan kota baru
void entryKota(Kota **head, char *namaKota) {
    Kota *newKota = (Kota*)malloc(sizeof(Kota));
    strcpy(newKota->nama, namaKota);
    newKota->jumlahOrang = 0;
    newKota->firstOrang = NULL;
    newKota->nextKota = *head;
    *head = newKota;
}

// Menghapus kota dan semua orang di dalamnya
void deleteKota(Kota **head, char *namaKota) {
    Kota *curr = *head, *prev = NULL;

    while (curr != NULL && strcmp(curr->nama, namaKota) != 0) {
        prev = curr;
        curr = curr->nextKota;
    }

    if (curr == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    Orang *orang = curr->firstOrang;
    while (orang != NULL) {
        Orang *hapus = orang;
        orang = orang->nextOrang;
        free(hapus);
    }

    if (prev == NULL) {
        *head = curr->nextKota;
    } else {
        prev->nextKota = curr->nextKota;
    }

    free(curr);
}

// Menampilkan semua kota dan semua orangnya
void tampilKota(Kota *head) {
    if (head == NULL) {
        printf("Tidak ada kota yang terdaftar.\n");
        return;
    }

    Kota *currKota = head;
    while (currKota != NULL) {
        printf("\nKota: %s (Jumlah Orang: %d)\n", currKota->nama, currKota->jumlahOrang);
        Orang *currOrang = currKota->firstOrang;
        if (currOrang == NULL) {
            printf("  (Belum ada orang)\n");
        }
        while (currOrang != NULL) {
            printf("  - %s\n", currOrang->nama);
            currOrang = currOrang->nextOrang;
        }
        currKota = currKota->nextKota;
    }
}

// Menambahkan orang ke kota tertentu
void tambahOrang(Kota *head, char *namaKota, char *namaOrang) {
    Kota *curr = head;
    while (curr != NULL && strcmp(curr->nama, namaKota) != 0) {
        curr = curr->nextKota;
    }

    if (curr == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    Orang *newOrang = (Orang*)malloc(sizeof(Orang));
    strcpy(newOrang->nama, namaOrang);
    newOrang->nextOrang = curr->firstOrang;
    newOrang->nextKota = curr->nextKota;
    curr->firstOrang = newOrang;
    curr->jumlahOrang++;
}

// Menghapus semua memory
void deallocateMemory(Kota *head) {
    Kota *currKota;
    while (head != NULL) {
        Orang *orang = head->firstOrang;
        while (orang != NULL) {
            Orang *hapus = orang;
            orang = orang->nextOrang;
            free(hapus);
        }
        currKota = head;
        head = head->nextKota;
        free(currKota);
    }
}
