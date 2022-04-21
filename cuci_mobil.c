#include "cuci_mobil.h"

//membuat Queue kosong
void createEmpty(queueMobil *Q){
	(*Q).front = NULL;
	(*Q).rear = NULL;
}//Kakak Tingkat


//cek Queue kosong
int isEmpty(queueMobil Q){
	int hasil = 0;
	
	if(Q.front == NULL){
		hasil = 1;
	} 
	
	return hasil;
}//Kakak Tingkat


//insert customer
void addMobil(int no_pel, int id_mobil, nd_mobil p_mobil, char nmor_polisi[], char jenis_mobil[], queueMobil *Q, int *jam,int *menit,int *detik){          	
	data_mobil *waktutemp;   // menambahkan pointer dengan nama waktu

	if(jam <9){     //kondisi ketika tempat belum buka
		elmt->jam_operasi.jam = 9;
		elmt->jam_operasi.menit = 0;
		elmt->jam_operasi.detik = 0;
	} 
	
	elmt = (data_mobil *) malloc (sizeof(data_mobil));
	elmt->no_pel = no_pel;fflush(stdin);
	elmt->id_mobil = id_mobil;fflush(stdin);
	elmt->jam_masuk.jam=jam;fflush(stdin);
	elmt->jam_masuk.menit=menit;fflush(stdin);
	elmt->jam_masuk.detik=detik;fflush(stdin);
	elmt->jenis_mobil=jenis_mobil;fflush(stdin);
	strcpy(elmt->nmor_polisi,nmor_polisi);fflush(stdin);
	
	if((*Q).front != NULL){ // kondisi pengambilan waktu ketika antrian sudah ada
		if((*Q).rear==NULL){
			waktutemp=(*Q).front;
		}
		else
		{
			waktutemp=(*Q).rear;
		}
		if ((elmt->jam_masuk.jam>waktutemp->jam_keluar.jam)||((elmt->jam_masuk.jam==waktutemp->jam_keluar.jam)&& (elmt->jam_masuk.menit > waktutemp->jam_keluar.menit)) || ((elmt->jam_masuk.jam==waktutemp->jam_keluar.jam)&&(elmt->jam_masuk.menit==waktutemp->jam_keluar.menit)&&(elmt->jam_masuk.detik>waktutemp->jam_keluar.detik)))
		{//kondisi ketika cucian sebelumnya selesai dikerjakan dan antrian sudah tidak ada
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
		  	if (waktutemp->jam_keluar.jam<17){ // prosedure untuk melakukan pengambilan waktu operasi ketika tempat belum tutup
				elmt->jam_operasi.jam=waktutemp->jam_keluar.jam;
				elmt->jam_operasi.menit=waktutemp->jam_keluar.menit+5;
				elmt->jam_operasi.detik=waktutemp->jam_keluar.detik;
				if(elmt->jam_operasi.menit>=60){
					elmt->jam_operasi.menit=elmt->jam_operasi.menit-60;
					elmt->jam_operasi.jam=elmt->jam_operasi.jam+1;
				}			
		   	}
	   		else{
	   			printf("MAAF Tempat Sudah Penuh\n"); // kondisi antrian waktu sudah melebihi batas pengerjaan
			}
		}
		
	}
	else 	
	if(jam>=12 && jam<13 && (*Q).front == NULL){  // kondisi ketika antrian kosong dan waktu pegawai untuk beristirahat
		elmt->jam_operasi.jam = 13;
		elmt->jam_operasi.menit = 00;
		elmt->jam_operasi.detik = 00;
		printf ("\nMaaf Kami Sedang Istirahat\nHarap Tunggu Sebentar\nMobil Anda akan kami cuci pada pukul %d:%d:%d\n", elmt->jam_operasi.jam,elmt->jam_operasi.menit,elmt->jam_operasi.detik);
	}else{
		elmt->jam_operasi.jam = jam;
		elmt->jam_operasi.menit = menit;
		elmt->jam_operasi.detik= detik;	
	}
		
	if(elmt->jenis_mobil==1){  // prosedure pengambilan waktu akhir ketika jenis mobil = A
		elmt->jam_keluar.jam=elmt->jam_operasi.jam;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+30;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if(elmt->jenis_mobil==2){ // prosedure pengambilan waktu akhir ketika jenis mobil = B
		elmt->jam_keluar.jam=elmt->jam_operasi.jam;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+45;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if(elmt->jenis_mobil==3){ // prosedure pengambilan waktu akhir ketika jenis mobil = C
		elmt->jam_keluar.jam=elmt->jam_operasi.jam+1;
		elmt->jam_keluar.menit=elmt->jam_operasi.menit+15;
		elmt->jam_keluar.detik=elmt->jam_operasi.detik;
		if(elmt->jam_keluar.menit>=60){
			elmt->jam_keluar.menit=elmt->jam_keluar.menit-60;
			elmt->jam_keluar.jam=elmt->jam_keluar.jam+1;
		}
	}
	if (elmt->jam_keluar.jam == 12){ // kondisi pengambilan waktu akhir ketika waktu akhir berada pada waktu istirahat pegawai
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
}//Nisrina dan Ummu

//delete customer
void delMobil(queueMobil *Q){
	if(isEmpty(*Q) == 1){
		printf("Queue Kosong\n");
	}else{
		elmt = (*Q).front;
		(*Q).front = (*Q).front->p_mobil;
		elmt->p_mobil = NULL;
		free(elmt);
	}
}//Kakak Tingkat

//menampilkan isi Queue
void printqueueMobil(queueMobil Q){
	if(isEmpty(Q) == 1){
		printf("Antrian Kosong");	
	}else{
		elmt = Q.front;
		
		printf("--");
		while(elmt != NULL){
			printf("%2d:%2d:%2d(%s) ",elmt->jam_operasi.jam,elmt->jam_operasi.menit,elmt->jam_operasi.detik,elmt->nmor_polisi);
			elmt = elmt->p_mobil;
		}
		printf("--");
		
	}
}//Kakak Tingkat

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
}//Ummu

//cek antrian
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
}//Ummu

//tambah antrian
void addAntrian(queueMobil Q[], data_tmptcuci tmptcuci[]){
	int index, i, antrian;
	nomor++;
	char a[10];
	int b;
	bool valid = false;
	int jam=0, menit=0, detik=0;
	
	index = cekAntrian(Q);
	antrian = countMobil(Q[index]);
	
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
				printf("|============================================================================================|\n");
				printf("|                                   Rincian Jenis Mobil                                      |\n");
				printf("|============================================================================================|\n");
				printf("| 1. mobil kecil : KIA Picanto, Daihatsu Ceria,                                  Rp. 25.000  |\n");
				printf("|                  Suzuki Karimun, Toyota Yaris dll (30 menit)                               |\n");
				printf("| 2. minibus     : Toyota Avanza, Honda Freed, Suzuki Ertiga, dll (45 menit)     Rp. 30.000  |\n");
				printf("| 3. mobil besar : Metromini, Truk, dll (75 menit)                               Rp. 40.000  |\n");
				printf("|============================================================================================|\n");
				printf("   Input Nomor Polisi : "); fflush(stdin); scanf("%[^\n]", &a);
				printf("   Input Jenis Mobil  : "); scanf("%d", &b);
				printf("   No ID Mobil Anda   : %d\n", nomor);
				printf("|============================================================================================|\n");
				addMobil(index + 1,nomor,NULL,a,b,&Q[index],jam,menit,detik);
				tmptcuci[index].p_tmptcuci = Q[index].front;
				printf("|========================================Berhasil============================================|\n");
				printf("|============================================================================================|\n\n");
				printf("------------Antrian cuci------------\n");
				printf("=====================================\n");
				i = 0;
				while(i < 2){
					printf("Tempat ke %d : ", i+1);
					printqueueMobil(Q[i]);
					printf("\n");
					i++;
				}	
			}else{
				printf("MAAF TEMPAT TUTUP\nTerimakasih \n\n");
			}
			valid = true;
		}
	}while (valid==false);
}//Nisrina dan Ummu

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
}//Nisrina dan Putri

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
}//Nisrina dan Putri

void checkout(queueMobil *Q){
	int id;
	bool found=false;
	elmt = (*Q).front;
	printf("Masukkan Nomor ID Mobil: ");
	scanf("%d",&id);
	
	while(elmt != NULL){
		if (id==elmt->id_mobil){
			found = true;
			elmt->biaya = biayapakai(&Q);
			printStruk(&Q);
			delMobil(&Q);
		}
		elmt = elmt->p_mobil;
	}
	if(found==false){
		printf("\nData Mobil tidak ditemukan\n");
	}
}//Nisrina,Putri,dan Ummu

//transaksi
void mainmenu(int *pilih){
	printf("|===================================================================================|\n");
	printf("|                      APLIKASI ANTRIAN CUCI MOBIL JTK                              |\n");
	printf("|                   | Nisrina-058 | Putri-060 | Ummu-065 |                          |\n");
	printf("|            Buka : 07.00-17.00 WIB, Istirahat : 12.00-13.00 WIB                    |\n");
	printf("|===================================================================================|\n");
	printf("|                     1. Masuk Antrian                                              |\n");
	printf("|                     2. Checkout                                                   |\n");
	printf("|                     3. Tampilkan Rekap                                            |\n");
	printf("|                     4. Help                                                       |\n");
	printf("|                     5. Exit                                                       |\n");
	printf("|===================================================================================|\n");
	printf("                      Masukan Pilihan : ");
	scanf("%d",&*pilih);	
}//Nisrina

void help(){//Menampilkan file berisi User Manual
		
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
}//Putri

void rekap (){
	FILE *f_rekap;
	time_t t = time(NULL);           // pengambilan current date
	struct tm *tm = localtime(&t);
	
	f_rekap = fopen ("rekap_mobil.dat", "ab");
	if ( f_rekap == NULL ){ 
        printf( "File failed to open." ) ; 
    } 
    else{
		fprintf(f_rekap,"|     %7s      |     %d       |    %2d:%2d:%2d      |  %2d:%2d:%2d     |  %2d:%2d:%2d    |     %d        |   %2d/%2d/%4d      |\n",elmt->nmor_polisi,elmt->jenis_mobil,elmt->jam_masuk.jam,elmt->jam_masuk.menit,elmt->jam_masuk.detik,
		elmt->jam_operasi.jam,elmt->jam_operasi.menit,elmt->jam_operasi.detik,elmt->jam_keluar.jam,elmt->jam_keluar.menit,elmt->jam_keluar.detik,elmt->no_pel,tm->tm_mday,tm->tm_mon+1,tm->tm_year+1900);
    }
	fclose(f_rekap);
}//Nisrina

void showrekap()
{	
    system("cls");		
	FILE *f_rekap;
	char cara[panjang];
	
	if ((f_rekap = fopen("rekap_mobil.dat", "rb")) == NULL){
		printf("File tidak dapat dibuka! \r\n");
		exit(1);
	}
	printf("|=====================================================================================================================|\n");
	printf("|   Nomor Polisi   | Jenis Mobil |  Jam kedatangan  |  Jam Operasi  |  Jam Keluar  | Tempat Cuci  | Tanggal Pencucian |\n");
	printf("|=====================================================================================================================|\n");
	while((fgets(cara, panjang, f_rekap)) != NULL){
		printf("%s\r", cara);
		printf("|=====================================================================================================================|\n");
	}
	fclose(f_rekap);
	system("pause");
}//Nisrina

