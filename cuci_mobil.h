#ifndef cuci_mobil_H
#define cuci_mobil_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#define panjang 600

typedef struct{
	int jam;
	int menit;
	int detik;
}waktu;

typedef struct mobil *nd_mobil;

typedef struct mobil{
	int id_mobil;				
	int no_pel;
	waktu jam_masuk;
	waktu jam_keluar;
	waktu jam_operasi;
	char nm_pel;						
	char nmor_polisi[12];				
	int jenis_mobil;
	int biaya;
	nd_mobil p_mobil;				
}data_mobil;
data_mobil *elmt;
int nomor;

typedef struct{							
	char *no_tmptcuci;					
	nd_mobil p_tmptcuci;							
}data_tmptcuci;

typedef struct{
	data_mobil *front;
	data_mobil *rear;
}queueMobil;

time_t now;
struct tm *now_tm;

/*membuat Queue kosong*/
void createEmpty(queueMobil *Q);

/*cek Queue kosong*/
int isEmpty(queueMobil Q);

/*Alokasi Dinamis*/
nd_mobil Alokasi(int no_pel, int id_mobil, nd_mobil p_mobil, char nmor_polisi[], int jenis_mobil, int jam,int menit,int detik);

/*hitungelemen*/
int countMobil(queueMobil Q);

/*insert pembeli*/
void addMobil(int no_pel, int id_mobil, nd_mobil p_mobil, char nmor_polisi[], int jenis_mobil, queueMobil *Q,int jam,int menit,int detik);

/*delete pembeli*/
void delMobil(queueMobil *Q);

/*menampilkan isi Queue*/
void printqueueMobil(queueMobil Q);

/*cek antrian*/
int cekAntrian(queueMobil Q[]);

/*tambah antrian*/
void addAntrian(queueMobil Q[], data_tmptcuci tmptcuci[]);

/*menu transaksi*/
void mainmenu(int *pilih);

int biayapakai (queueMobil *Q);

void printStruk (queueMobil *Q);

void checkout (queueMobil Q[]);

void rekap();

/*melihat keterangan setiap jenis mobil dalam waktu pelayanan*/
void help();

/* menampilkan record file antrian cuci mobil*/
void showrekap();

void gotoxy(int x, int y);

#endif

