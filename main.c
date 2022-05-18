#include "cuci_mobil.h"
int main() {
	int choice,cek;

	queueMobil Q[2];
	data_tmptcuci tmptcuci[2];
	
	tmptcuci[0].no_tmptcuci = "Tempat 1";
	tmptcuci[0].p_tmptcuci = NULL;
	createEmpty(&Q[0]);
	tmptcuci[1].no_tmptcuci = "Tempat 2";
	tmptcuci[1].p_tmptcuci = NULL;
	createEmpty(&Q[1]);
		
	do{
		int i;
		system("cls");
		printf("\n\n\n\n");
		i = 0;
		gotoxy(40,3); printf("|=====================================|\n");
		gotoxy(40,4); printf("|             Antrian cuci            |\n");
		gotoxy(40,5); printf("|=====================================|\n");
		while(i < 2){
			printf("|Tempat ke %d| : ", i+1);
			printqueueMobil(Q[i]);
			printf("\n");
			i++;
		}
		printf("\n\n");
		mainmenu(&choice);
		switch(choice){
			case 1:{
				addAntrian(Q, tmptcuci);
				break;
			}
			case 2:{
				gotoxy(17,24); printf("Pilih Tempat Cuci : ");
				scanf("%d",&cek);
				if(cek == 1){
					checkout(&Q[0]);
				}else{
					checkout(&Q[1]);
				}
				break;
			}
			case 3:{
				showrekap();
				break;
			}
			case 4:{
				help();
				break;
			}
			case 5:{
				exit (0);
			}
			default:{
				printf("\nHanya ada 5 opsi\n");
				break;
			}
		}
		getch();
	}while(choice !=5);	
}
