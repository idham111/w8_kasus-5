#ifndef HEADER_H
#define HEADER_H

typedef struct Orang {
    char nama[50];
    struct Orang *nextOrang;
    struct Kota *nextKota;
} Orang;

typedef struct Kota {
    char nama[50];
    int jumlahOrang;
    struct Orang *firstOrang;
    struct Kota *nextKota;
} Kota;

void entryKota(Kota **head, char *namaKota);
void deleteKota(Kota **head, char *namaKota);
void tampilKota(Kota *head);
void tambahOrang(Kota *head, char *namaKota, char *namaOrang);
void deallocateMemory(Kota *head);

#endif
