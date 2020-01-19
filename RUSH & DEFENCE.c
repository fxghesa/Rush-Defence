#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#define MAKSTURN 15
float perubahan1[MAKSTURN]={-12,70,-14,21,25,60,-3,14,50,-4,6,70,3,-15,70}; //attack damage counter
float perubahan2[MAKSTURN]={-12,3,30,1,-2,70,3,-14,50,14,26,70,-16,-26,12};
float perubahan3[MAKSTURN]={-12,5,-4,1,5,7,-13,4,50,-14,16,70,13,-28,10};
float perubahan4[MAKSTURN]={-22,60,-14,30,25,50,70,24,50,-14,6,70,50,-25,70}; //data keluar oleh pop()
int top1=-1,top2=-1,top3=-1,top4=-1;
struct x{
	char character[6];
	int indeks;
	float hp,atk;
	struct x *rush,*defence;
};
struct x *head,*tail;
struct x *karakter;
struct x *temansupport,*temantanker;
struct x *musuhtanker,*musuhsupport;
pop(float dmg){
	float atkcounter;
	if((dmg==200)||(dmg==300)){
		atkcounter=perubahan1[top1];
		atkcounter=(atkcounter/100)*dmg;
		dmg=dmg+atkcounter;
		top1--;
		return (dmg);
	}
	if((dmg==180)||(dmg==280)){
		atkcounter=perubahan2[top2];
		atkcounter=(atkcounter/100)*dmg;
		dmg=dmg+atkcounter;
		top2--;
		return (dmg);
	}
	if((dmg==230)||(dmg==330)){
		atkcounter=perubahan3[top3];
		atkcounter=(atkcounter/100)*dmg;
		dmg=dmg+atkcounter;
		top3--;
		return (dmg);
	}
	if((dmg==150)||(dmg==250)){
		atkcounter=perubahan4[top4];
		atkcounter=(atkcounter/100)*dmg;
		dmg=dmg+atkcounter;
		top4--;
		return (dmg);
	}
}
mainmenu(){
	char opsi;
	system("cls");
	printf("\t  RUSH & DEFENCE\n\n");
	printf(" 1. Play\n");
	printf(" 2. Help\n");
	printf(" 3. Credit\n");
	printf(" 4. Exit\n");
	opsi=getch();
	switch(opsi){
		case '1' :
			loadingscreen();
			formasi();
		case '2' :
			bantuan();
		case '3' : 
			kredit();
		case '4' :
			system("cls");
			exit(0);
	}
}
kredit(){
	char opsi;
	system("cls");
	printf("Prepare to die edition by :\n\n");
	printf("- Ahmad Maruf Firman \t [2210141054]\n");
	printf("- Florensius Ghesa \t [2210141055]\n");
	printf("  ComputerEngineering B 2k14 PENS"); puts("\n");
	printf("1. Main menu"); opsi=getch();
	if(opsi=='1'){
		mainmenu();
	} else kredit();
}
bantuan(){
	char opsi;
	system("cls");
	printf("Rush & Defence guide : \n");
	printf(" 1. Use numerical key to navigate\n");
	printf(" 2. Use alphabetic and enter key to enter name\n");
	printf(" 3. Please enter 7 char or less for player name\n");
	printf(" 4. Attack critical damage depend on class and weapon type\n");
	printf(" 5. No class or weapon equiped result in a very small ATK status\n");
	printf(" 6. Support can attack tanker and support\n");
	printf(" 7. Tanker can only attack tanker\n");
	printf(" 8. Semi realtime, enemy can counter your attack\n");
	printf(" 9. If one of character HP below 0, the opposite player will win the battle\n");
	printf("\n1. Main Menu"); opsi=getch();
	if(opsi=='1'){
		mainmenu();
	} else bantuan();
}
senjata(){
	char opsi;
	float longsword=200,katana=180,headsmanaxe=230,dagger=150;
	printf("Select class : \n");
	printf(" 1. Battle Maiden\n");
	printf("	EQP -> Elven Longsword\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", longsword);
	printf("	CRI -> 30/100\n");
	printf(" 2. Ronin\n");
	printf("	EQP -> Atoshi Katana\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", katana);
	printf("	CRI -> 35/100\n");
	printf(" 3. Berserker\n");
	printf("	EQP -> Headsman Axe\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", headsmanaxe);
	printf("	CRI -> 20/100\n");
	printf(" 4. Assasin\n");
	printf("	EQP -> Dual Dagger\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", dagger);
	printf("	CRI -> 40/100\n");
	opsi=getch();
	switch(opsi){
		case '1' :
			return(longsword);
		case '2' :
			return(katana);
		case '3' :
			return(headsmanaxe);
		case '4' :
			return(dagger);
	}
}
kelas(){
	char opsi;
	float dutchman=300,sniper=280,antimage=330,ninja=250;
	printf("Select class : \n");
	printf(" 1. Dutchman\n");
	printf("	EQP -> Aghanim Schepter\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", dutchman);
	printf("	CRI -> 30/100\n");
	printf(" 2. Sniper\n");
	printf("	EQP -> 50 Cal Barreta\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", sniper);
	printf("	CRI -> 35/100\n");
	printf(" 3. Antimage\n");
	printf("	EQP -> God Slayer\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", antimage);
	printf("	CRI -> 20/100\n");
	printf(" 4. Ninja\n");
	printf("	EQP -> Kunai\n");
	printf("	HP  -> 2000\n");
	printf("	ATK -> %.0f\n", ninja);
	printf("	CRI -> 40/100\n");
	opsi=getch();
	switch(opsi){
		case '1' :
			return(dutchman);
		case '2' :
			return(sniper);
		case '3' :
			return(antimage);
		case '4' :
			return(ninja);
	}
}
loadingscreen(){
	int i,j,k;
	for(i=0;i<=4;i++){
		system("cls");
		printf(" - x - \n");
		printf(" Now Loading\n");
		Sleep(200);
		system("cls");
		printf("        - x - \n");
		printf(" Now Loading");
		Sleep(200);
	}
}
formasi(){
	int j=0;
	system("cls");
	printf("Please, fill the blank!");
	getch();
	system("cls");
	while(1){
		karakter=(struct x*)malloc(sizeof(struct x));
		if(j==0){ 							//indeks 0 & 1 untuk pemain
			printf(" -Player Support- \n");
			printf("%d. Name : ",j+1);
			scanf("%s",&karakter->character);
			karakter->hp = 2000;
			karakter->atk = kelas();
			karakter->indeks=0;
			system("cls");
		}
		if(j==1){
			printf(" -Player Tanker- \n");
			printf("%d. Name : ",j+1);
			scanf("%s",&karakter->character);
			karakter->hp = 5000;
			karakter->atk = senjata();
			karakter->indeks=1;
			system("cls");
		}
		if(j==2){							//indeks 2 & 3 untuk musuh
			printf(" -Enemy Tanker- \n");
			printf("%d. Name : ",j+1);
			scanf("%s",&karakter->character);
			karakter->hp = 5000;
			karakter->atk = senjata();
			karakter->indeks=2;
			system("cls");
		}
		if(j==3){
			printf(" -Enemy Support- \n");
			printf("%d. Name : ",j+1);
			scanf("%s",&karakter->character);
			karakter->hp = 2000;
			karakter->atk = kelas();
			karakter->indeks=3;
			system("cls");
		}
	    if(j==0){
	    	karakter->rush=NULL;
	    	karakter->defence=NULL;
	    	head=karakter;
	    	tail=karakter;
	    }else{
 	    	tail->rush=karakter;
 	    	karakter->rush=NULL;
 	    	karakter->defence=tail;
 	    	tail=karakter;
  	  	}
	    if(j>=3) break; //karakter max=4
	    j++;
	}
	system("cls"); sellector();
}
alliesstatus(){
	struct x *tampil;
	system("cls");
	printf("Player stats :");
	tampil=head;
	while(tampil->indeks!=2){
		printf("\nName\t: %s",tampil->character);
		printf("\nHP\t: %.0f",tampil->hp);
		printf("\nATK\t: %.0f",tampil->atk);
		puts("");
		tampil=tampil->rush;
	}
	puts("");
}
axisstatus(){
	char opsi;
	struct x *tampil;
	printf("Enemy stats :");
	tampil=tail;
	while(tampil->indeks!=1){
		printf("\nName\t: %s",tampil->character);
		printf("\nHP\t: %.0f",tampil->hp);
		printf("\nATK\t: %.0f",tampil->atk);
		puts("");
		tampil=tampil->defence;
	}
	printf("\n1. Back\n"); opsi=getch();
	if(opsi='1') 
		battle(); 
	else
		alliesstatus();
}
serang(){
	float damage1,damage2;
	char opsi,opsi2='1',opsi3;
	system("cls");
	battlefield(); puts("");
	printf("\nSelect your character !\n");
	printf(" 1. %s\n",temantanker->character);
	printf(" 2. %s\n",temansupport->character);
	opsi=getch();
	system("cls");
	battlefield(); puts("");
	if(opsi!='2'){
		printf("\nEnemy to slay!\n");
		printf(" 1. %s\n",musuhtanker->character);
		opsi2=getch();
	}
	if(opsi!='1'){
		printf("\nEnemy to slay!\n");
		printf(" 1. %s\n",musuhtanker->character);
		printf(" 2. %s\n",musuhsupport->character);
		opsi2=getch();
	}
	switch(opsi){
		case '1' :
			switch(opsi2){
				case '1' :
					musuhtanker->hp=musuhtanker->hp-(damage1=pop(temantanker->atk));
					temantanker->hp=temantanker->hp-(damage2=pop(musuhtanker->atk));
					axistanker_attacked();
					printf("\n%s give %.0f damage \n",temantanker->character,damage1);
					printf("%s counter %.0f damage \n",musuhtanker->character,damage2);
					pascaserang();
				case '2' :
					musuhsupport->hp=musuhsupport->hp-(damage1=pop(temantanker->atk));
					temantanker->hp=temantanker->hp-(damage2=pop(musuhsupport->atk));
					axissupport_attacked();
					printf("\n%s give %.0f damage \n",temantanker->character,damage1);
					printf("%s counter %.0f damage \n",musuhsupport->character,damage2);
					pascaserang();
			}
		case '2' :
			switch(opsi2){
				case '1' :
					musuhtanker->hp=musuhtanker->hp-(damage1=pop(temansupport->atk));
					temansupport->hp=temansupport->hp-(damage2=pop(musuhtanker->atk));
					axistanker_attacked();
					printf("\n%s give %.0f damage \n",temansupport->character,damage1);
					printf("%s counter %.0f damage \n",musuhtanker->character,damage2);
					pascaserang();
				case '2' :
					musuhsupport->hp=musuhsupport->hp-(damage1=pop(temansupport->atk));
					temansupport->hp=temansupport->hp-(damage2=pop(musuhsupport->atk));
					axissupport_attacked();
					printf("\n%s give %.0f damage \n",temansupport->character,damage1);
					printf("%s counter %.0f damage \n",musuhsupport->character,damage2);
					pascaserang();
			}
	}
}
pascaserang(){
		char opsi;
		printf("\n 1. Countinue\n");
		opsi=getch();
		if(opsi='1') battle();
		else pascaserang();
}
sellector(){
	temansupport=head; temantanker=head;
	musuhsupport=tail; musuhtanker=tail;
	while(temansupport->indeks!=0){
		temansupport=temansupport->rush;
	} 
	while(temantanker->indeks!=1){
		temantanker=temantanker->rush;
	} 
	while(musuhtanker->indeks!=2){
		musuhtanker=musuhtanker->defence;
	} 
	while(musuhsupport->indeks!=3){
		musuhsupport=musuhsupport->defence;
	}
//	loadingscreen();
	battle();
}
battlefield(){
	system("cls");
	printf("ENEMY FORCES	...					<-	<-\n");
	printf("==================="); puts("");
	printf("| Name	: %7s | =======================",musuhsupport->character); puts("");
	printf("| HP	: %7.0f | | Name	: %7s |",musuhsupport->hp,musuhtanker->character); puts("");
	printf("| ATK	: %7.0f | | HP	: %7.0f |",musuhsupport->atk,musuhtanker->hp); puts("");
	printf("------------------- | ATK	: %7.0f |",musuhtanker->atk); puts("");
	printf("		    -----------------------"); puts("\n");
	printf("			      - VS -"); puts("\n");
	printf("			-------------------"); puts("");
	printf("			| Name	: %7s | -----------------------",temantanker->character); puts("");
	printf("			| HP	: %7.0f | | Name	: %7s |",temantanker->hp,temansupport->character); puts("");
	printf("			| ATK	: %7.0f | | HP	: %7.0f |",temantanker->atk,temansupport->hp); puts("");
	printf("			=================== | ATK	: %7.0f |",temansupport->atk); puts("");
	printf("					    ======================="); puts("");
	printf("->	->					...	YOUR FORCES\n");
}
axistanker_attacked(){
	int i,j;
	char opsi;
	system("cls");
	for(i=0;i<=2;i++){
		system("cls");
		battlefield();
		Sleep(200);
		system("cls");
		printf("ENEMY FORCES	...					<-	<-\n");
		printf("==================="); puts("");
		printf("| Name	: %7s |   X       X",musuhsupport->character); puts("");
		printf("| HP	: %7.0f |     X   X",musuhsupport->hp); puts("");
		printf("| ATK	: %7.0f |       X",musuhsupport->atk); puts("");
		printf("-------------------     X   X"); puts("");
		printf("                      X       X"); puts("\n");
		printf("			      - VS -"); puts("\n");
		printf("			-------------------"); puts("");
		printf("			| Name	: %7s | -----------------------",temantanker->character); puts("");
		printf("			| HP	: %7.0f | | Name	: %7s |",temantanker->hp,temansupport->character); puts("");
		printf("			| ATK	: %7.0f | | HP	: %7.0f |",temantanker->atk,temansupport->hp); puts("");
		printf("			=================== | ATK	: %7.0f |",temansupport->atk); puts("");
		printf("					    ======================="); puts("");
		printf("->	->					...	YOUR FORCES\n");
		Sleep(200);
	}
}
axissupport_attacked(){
	int i,j;
	char opsi;
	system("cls");
	for(i=0;i<=3;i++){
		system("cls");
		battlefield();
		Sleep(200);
		system("cls");
		printf("ENEMY FORCES	...					<-	<-\n");
		printf("  X	  X	"); puts("");
		printf("    X   X       ==================="); puts("");
		printf("      X	        | Name	: %7s |",musuhtanker->character); puts("");
		printf("    X	X       | HP	: %7.0f |",musuhtanker->hp); puts("");
		printf("  X       X	| ATK	: %7.0f |",musuhtanker->atk); puts("");
		printf("                -------------------"); puts("\n");
		printf("			      - VS -"); puts("\n");
		printf("			-------------------"); puts("");
		printf("			| Name	: %7s | -----------------------",temantanker->character); puts("");
		printf("			| HP	: %7.0f | | Name	: %7s |",temantanker->hp,temansupport->character); puts("");
		printf("			| ATK	: %7.0f | | HP	: %7.0f |",temantanker->atk,temansupport->hp); puts("");
		printf("			=================== | ATK	: %7.0f |",temansupport->atk); puts("");
		printf("					    ======================="); puts("");
		printf("->	->					...	YOUR FORCES\n");
		Sleep(200);
	}
}
nyawatester(){
	char opsi;
	if((temantanker->hp<=0)||(temansupport->hp<=0)){
		printf("You have lose your battle\n");
		printf("\n1. Main menu\n");
		opsi=getch();
		if(opsi='1') mainmenu();
		else nyawatester();
	}
	if((musuhtanker->hp<=0)||(musuhsupport->hp<=0)){
		printf("You have won your battle\n");
		printf("\n1. Main menu\n");
		opsi=getch();
		if(opsi='1') mainmenu();
		else nyawatester();
	}
}
diam(){
	system("cls");
	printf("Okay, you've done nothing, but ... ");
	getch();
	battle();
}
battle(){
	char opsi;
	system("cls");
	nyawatester();
	printf("Please, your order!\n");
	printf(" 1. Attack\n");
	printf(" 2. Do Nothing\n");
	printf(" 3. Stats\n");
	printf(" 4. Main Menu\n");
	opsi=getch();
	switch(opsi){
		case '1':
			serang();
		case '2' :
			diam();
		case '3':
			alliesstatus();
			axisstatus();
		case '4':
			mainmenu();
	}
}
main(){
	mainmenu();
}
