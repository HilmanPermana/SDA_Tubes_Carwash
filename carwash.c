#include "cuci_mobil.h"

/*membuat Queue kosong*/
void createEmpty(queueMobil *Q){
	(*Q).front = NULL;
	(*Q).rear = NULL;
}


/*cek Queue kosong*/
int isEmpty(queueMobil Q){
	int hasil = 0;
	
	if(Q.front == NULL){
		hasil = 1;
	} 
	
	return hasil;
}

nd_mobil Alokasi(int no_pel, int id_mobil, nd_mobil p_mobil, char nmor_polisi[], int jenis_mobil, int jam,int menit,int detik){
	
	
	elmt = (data_mobil *) malloc (sizeof(data_mobil));
	if(elmt != NULL){
	
		elmt->no_pel = no_pel;fflush(stdin);
		elmt->id_mobil = id_mobil;fflush(stdin);
		elmt->jam_masuk.jam=jam;fflush(stdin);
		elmt->jam_masuk.menit=menit;fflush(stdin);
		elmt->jam_masuk.detik=detik;fflush(stdin);
		elmt->jenis_mobil=jenis_mobil;fflush(stdin);
		strcpy(elmt->nmor_polisi,nmor_polisi);fflush(stdin);
		
	}
	
	return elmt;
	
}

/*insert customer*/
void addMobil(int no_pel, int id_mobil, nd_mobil p_mobil, char nmor_polisi[], int jenis_mobil, queueMobil *Q, int jam,int menit,int detik){          	
	data_mobil *waktutemp;   /* menambahkan pointer dengan nama waktu*/
	
	/*Alokasi Dinamis*/
	elmt = Alokasi(no_pel, id_mobil, p_mobil, nmor_polisi, jenis_mobil, jam, menit, detik);
	
	if((*Q).front != NULL){ /* kondisi pengambilan waktu ketika antrian sudah ada*/
		if((*Q).rear==NULL){
			waktutemp=(*Q).front;
		}
		else
		{
			waktutemp=(*Q).rear;
		}
		if ((elmt->jam_masuk.jam>waktutemp->jam_keluar.jam)||((elmt->jam_masuk.jam==waktutemp->jam_keluar.jam)&& (elmt->jam_masuk.menit > waktutemp->jam_keluar.menit)) || ((elmt->jam_masuk.jam==waktutemp->jam_keluar.jam)&&(elmt->jam_masuk.menit==waktutemp->jam_keluar.menit)&&(elmt->jam_masuk.detik>waktutemp->jam_keluar.detik)))
		{/*kondisi ketika cucian sebelumnya selesai dikerjakan dan antrian sudah tidak ada*/
			elmt->jam_operasi.jam=jam;
			elmt->jam_operasi.menit=+5;
			elmt->jam_operasi.detik=detik;
			if(elmt->jam_operasi.menit>=60){
				elmt->jam_operasi.menit=elmt->jam_operasi.menit-60;
				elmt->jam_operasi.jam=elmt->jam_operasi.jam+1;
			}		
		}
		else
		{	
		  	if (waktutemp->jam_keluar.jam<16){ /* prosedure untuk melakukan pengambilan waktu operasi ketika tempat belum tutup*/
				elmt->jam_operasi.jam=waktutemp->jam_keluar.jam;
				elmt->jam_operasi.menit=waktutemp->jam_keluar.menit+5;
				elmt->jam_operasi.detik=waktutemp->jam_keluar.detik;
				if(elmt->jam_operasi.menit>=60){
					elmt->jam_operasi.menit=elmt->jam_operasi.menit-60;
					elmt->jam_operasi.jam=elmt->jam_operasi.jam+1;
				}			
		   	}
	   		else{
	   			printf("MAAF Tempat Sudah Tutup\n"); /* kondisi antrian waktu sudah melebihi batas pengerjaan*/
			}
		}
		
	}
	else 	
	if(jam>=12 && jam<13 && (*Q).front == NULL){  /* kondisi ketika antrian kosong dan waktu pegawai untuk beristirahat*/
		elmt->jam_operasi.jam = 13;
		elmt->jam_operasi.menit = 00;
		elmt->jam_operasi.detik = 00;
		printf ("\nMaaf Kami Sedang Istirahat\nHarap Tunggu Sebentar\nMobil Anda akan kami cuci pada pukul %d:%d:%d\n", elmt->jam_operasi.jam,elmt->jam_operasi.menit,elmt->jam_operasi.detik);
	}else{
		elmt->jam_operasi.jam = jam;
		elmt->jam_operasi.menit = menit;
		elmt->jam_operasi.detik= detik;	
	}
		
	if(elmt->jenis_mobil==1){  /* prosedure pengambilan waktu akhir ketika jenis mobil = A*/
		elmt->jam_keluar.jam=elmt->jam_operasi.jam;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+30;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if(elmt->jenis_mobil==2){ /* prosedure pengambilan waktu akhir ketika jenis mobil = B*/
		elmt->jam_keluar.jam=elmt->jam_operasi.jam;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+45;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if(elmt->jenis_mobil==3){ /* prosedure pengambilan waktu akhir ketika jenis mobil = C*/
		elmt->jam_keluar.jam=elmt->jam_operasi.jam+1;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+15;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if (elmt->jam_keluar.jam == 12){ /* kondisi pengambilan waktu akhir ketika waktu akhir berada pada waktu istirahat pegawai*/
		elmt->jam_keluar.jam=13;
		elmt->jam_keluar.menit=elmt->jam_keluar.menit;
		elmt->jam_keluar.detik=elmt->jam_keluar.detik;
	}
	rekap();
	elmt->p_mobil = p_mobil;
	
	if((*Q).front == NULL){
		(*Q).front = elmt;	
	}else{
		(*Q).rear->p_mobil = elmt;
	}
	(*Q).rear = elmt;
	elmt = NULL;
} 

/*delete customer*/
void delMobil(queueMobil *Q){
	if(isEmpty(*Q) == 1){
		printf("Queue Kosong\n");
	}else{
		elmt = (*Q).front;
		(*Q).front = (*Q).front->p_mobil;
		elmt->p_mobil = NULL;
		free(elmt);
	}
}

/*menampilkan isi Queue*/
void printqueueMobil(queueMobil Q){
	if(isEmpty(Q) == 1){
		printf("Antrian Kosong");	
	}else{
		elmt = Q.front;
		
		printf(" ");
		while(elmt != NULL){
			printf("%2d:%2d:%2d[%s]",elmt->jam_keluar.jam,elmt->jam_keluar.menit,elmt->jam_keluar.detik,elmt->nmor_polisi);
			elmt = elmt->p_mobil;
			printf(" << ");
		}
		
	}
}

int countMobil(queueMobil Q){
	int hasil = 0;
	
	if(isEmpty(Q) == 1){
		hasil = 0;
	}else{
		elmt = Q.front;
		
  		while(elmt != NULL){
			hasil = hasil + 1;
			elmt = elmt->p_mobil;
		}
	}
	
return hasil;
}

/*cek antrian*/
int cekAntrian(queueMobil Q[]){
	int jml_antrian, min, index, i;

	
	min = countMobil(Q[0]);
	index = 0;
	i = 1;
	while(i < 2){
		jml_antrian = countMobil(Q[i]);
		if(jml_antrian < min){
			min = jml_antrian;
			index = i;
		}
		i++;
	}
	
	return index;
}



/*tambah antrian*/
void addAntrian(queueMobil Q[], data_tmptcuci tmptcuci[]){
	int index, i, antrian;
	char a[10];
	int b;
	bool valid = false;
	int jam=0, menit=0, detik=0;
	nomor++;	/*id mobil atau field key*/
	
	
	do{
		printf("\nMasukkan Jam Masuk (hh:mm:ss): ");
		scanf("%2d:%2d:%2d", &jam,&menit,&detik);
		if(jam>23|| menit>59 || detik>59 || jam<0 || menit<0 || detik<0){
			valid  = false;
			printf("\nWaktu tidak valid, silahkan ulangi lagi\n");	
		}
		else{
			if(jam >= 9 && jam<16){
				
				system("cls");
				index = cekAntrian(Q);
					gotoxy(12,3);printf("|============================================================================================|\n");
					gotoxy(12,4);printf("|                                   Rincian Jenis Mobil                                      |\n");
					gotoxy(12,5);printf("|============================================================================================|\n");
					gotoxy(12,6);printf("| 1. mobil kecil : KIA Picanto, Daihatsu Ceria,                                  Rp. 25.000  |\n");
					gotoxy(12,7);printf("|                  Suzuki Karimun, Toyota Yaris dll (30 menit)                               |\n");
					gotoxy(12,8);printf("| 2. minibus     : Toyota Avanza, Honda Freed, Suzuki Ertiga, dll (45 menit)     Rp. 30.000  |\n");
					gotoxy(12,9);printf("| 3. mobil besar : Metromini, Truk, dll (75 menit)                               Rp. 40.000  |\n");
					gotoxy(12,10);printf("|============================================================================================|\n");
					gotoxy(12,11);printf("   Input Nomor Polisi : "); fflush(stdin); scanf("%[^\n]", &a);
					gotoxy(12,12);printf("   Input Jenis Mobil  : "); scanf("%d", &b);
					gotoxy(12,13);printf("   No ID Mobil Anda   : %d\n", nomor);
					gotoxy(12,14);printf("|============================================================================================|\n");
					addMobil(index + 1,nomor,NULL,a,b,&Q[index],jam,menit,detik);
					tmptcuci[index].p_tmptcuci = Q[index].front;
					gotoxy(12,15);printf("|========================================Berhasil============================================|\n");
					gotoxy(12,16);printf("|============================================================================================|\n\n");
					gotoxy(40,20);printf("------------Antrian cuci------------\n");
					gotoxy(40,21);printf("=====================================\n");
				i = 0;
				while(i < 2){
					printf("|Tempat ke %d| : ", i+1);
					printqueueMobil(Q[i]);
					printf("\n");
					i++;
				}	
			}else{
				printf("MAAF TEMPAT TUTUP\nTerimakasih \n\n");
				exit(0);
			}
			valid = true;
		}
	}while (valid==false);
}

int biayapakai(queueMobil *Q){
	int harga;
	if (elmt->jenis_mobil==1){
		harga=25000;
	}else if (elmt->jenis_mobil==2){
		harga=30000;
	}else if (elmt->jenis_mobil==3){
		harga=40000; 
	}
	return harga;
}

void printStruk (queueMobil *Q){
	int uang;
	bool valid=false;
	
	printf("\nNomor Polisi\t: %s\n", elmt->nmor_polisi);
	printf("Jenis Mobil\t: %d\n",elmt->jenis_mobil);
	printf("Tempat Cuci\t: %d\n",elmt->no_pel);
	printf("Jam Masuk\t: %d:%d:%d\n",elmt->jam_masuk.jam,elmt->jam_masuk.menit,elmt->jam_masuk.detik);
	printf("Jam Keluar\t: %d:%d:%d\n",elmt->jam_keluar.jam,elmt->jam_keluar.menit,elmt->jam_keluar.detik);
	printf("Biaya Akhir\t: %d",elmt->biaya);
	do{
		printf("\nMasukkan Uang yang Dibayarkan: ");
		scanf("%d", &uang);
		printf("\n");
		if(uang > elmt->biaya || uang==elmt->biaya){
			valid=true;
		}else{
			printf("Uang Kurang, tagih kembali\n");
		}
	}while(!valid);
	if(uang - elmt->biaya >0){
		printf("Kembalian : Rp. %d\n\n", uang-elmt->biaya);
	}else{
		printf("Tidak ada kembalian\n\n");
	}
}

void checkout(queueMobil Q[]){
	int id,index;
	bool found=false;
	
	printf("Masukkan Nomor ID Mobil: ");
	scanf("%d",&id);
	
	if(id % 2 == 0){
		elmt = Q[1].front;
	} 
	else{
		elmt = Q[0].front;
	}
	
		while(elmt != NULL){
			if (id==elmt->id_mobil){
				found = true;
				elmt->biaya = biayapakai(Q);
				printStruk(Q);
				delMobil(Q);
			}
			elmt = elmt->p_mobil;
		}
		if(found==false){
		printf("\nData Mobil tidak ditemukan\n");
		}
}

/*transaksi*/
void mainmenu(int *pilih){
	gotoxy(17,11);printf("|===================================================================================|\n");
	gotoxy(17,12);printf("|                      APLIKASI ANTRIAN CUCI MOBIL JTK                              |\n");
	gotoxy(17,13);printf("|                        | Hilman-015 | Salman-028 |                                |\n");
	gotoxy(17,14);printf("|            Buka : 09.00-16.00 WIB, Istirahat : 12.00-13.00 WIB                    |\n");
	gotoxy(17,15);printf("|===================================================================================|\n");
	gotoxy(17,16);printf("|                     1. Masuk Antrian                                              |\n");
	gotoxy(17,17);printf("|                     2. Checkout                                                   |\n");
	gotoxy(17,18);printf("|                     3. Tampilkan Rekap                                            |\n");
	gotoxy(17,19);printf("|                     4. Help                                                       |\n");
	gotoxy(17,20);printf("|                     5. Exit                                                       |\n");
	gotoxy(17,21);printf("|===================================================================================|\n");
	gotoxy(1,22);printf("                      Masukan Pilihan : ");
	scanf("%d",&*pilih);	
}

void help(){/*Menampilkan file berisi User Manual*/
		
	FILE *fp;
	char ch;
	
	if((fp=fopen("Help.txt","rt"))== NULL){
		printf("File tidak dapat dibuka! \r\n");
	}
	else{
		ch = fgetc(fp);	
		while (ch != EOF){
        	printf ("%c", ch);
        	ch = fgetc(fp);
    	}
	}
    fclose(fp);
}

void rekap (){
	FILE *f_rekap;
	time_t t = time(NULL);           /* pengambilan current date*/
	struct tm *tm = localtime(&t);
	
	f_rekap = fopen ("rekap_mobil.dat", "ab");
	if ( f_rekap == NULL ){ 
        printf( "File failed to open." ) ; 
    } 
    else{
		fprintf(f_rekap,"|     %7s      |     %d       |     %d       |    %2d:%2d:%2d      |  %2d:%2d:%2d     |  %2d:%2d:%2d    |     %d        |   %2d/%2d/%4d      |\n",elmt->nmor_polisi,elmt->id_mobil,elmt->jenis_mobil,elmt->jam_masuk.jam,elmt->jam_masuk.menit,elmt->jam_masuk.detik,
		elmt->jam_operasi.jam,elmt->jam_operasi.menit,elmt->jam_operasi.detik,elmt->jam_keluar.jam,elmt->jam_keluar.menit,elmt->jam_keluar.detik,elmt->no_pel,tm->tm_mday,tm->tm_mon+1,tm->tm_year+1900);
    }
	fclose(f_rekap);
}

void showrekap()
{	
	FILE *f_rekap;
	char cara[panjang];
    system("cls");		

	
	if ((f_rekap = fopen("rekap_mobil.dat", "rb")) == NULL){
		printf("File tidak dapat dibuka! \r\n");
		exit(1);
	}
	printf("|====================================================================================================================================|\n");
	printf("|   Nomor Polisi     |   ID Mobil   | Jenis Mobil |  Jam kedatangan  |  Jam Operasi  |  Jam Keluar  | Tempat Cuci  | Tanggal Pencucian |\n");
	printf("|====================================================================================================================================|\n");
	while((fgets(cara, panjang, f_rekap)) != NULL){
		printf("%s\r", cara);
		printf("|================================================================================================================================|\n");
	}
	fclose(f_rekap);
	system("pause");
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
