/******************************\
|* Code with <3               |
|* Created by Buðra Bürüngüz  |
|* 2019-07-18                 |
|* BugraBurunguz@gmail.com    |
\*****************************/
//admin: kullanýcý adý 1453 password 1903
//user kullanýcý adý 3838 password 3438
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


struct userDTO{	
	char userID[5];
	char userName[15];
	int customerNumber;
	int userPassword;
	float money;
	int IBANNo;
	float debt;
	int isUserActive;
	int fileSize;
	int fileSize2;
}userR;
struct adminDTO{
	
	int adminID[5];
	char adminName[15];
	char atmName[15];
	int  adminPassword;
};
void adminAdd(struct adminDTO* adminR);
void userAdd(struct userDTO* userW);
void drawingCashScreen();
void drawingCash(struct userDTO* userR);
void otherAmountMoney(struct userDTO* userR);
void transferMoney(struct userDTO* userR);
void transferMoneyScreen();
void userDelete(struct userDTO *userR);
void userList(struct userDTO* userR);
void mainScreenMenu();
void mainMenuScreen();
void startApp(struct userDTO *userR, struct adminDTO *adminR);
void startAppScreen();
void login(struct userDTO* userR);
void adminLogin(struct adminDTO *adminR,struct userDTO *userR);
void adminScreen();
void adminScreenMenu(struct userDTO *userR);
void userDetail(struct userDTO *userR);
void loadMoney(struct userDTO *userR);
void adminAdd(struct adminDTO* adminR){
    
	int adminSize, i;

	setlocale(LC_ALL,"Turkish");
	
    printf("How many admin you will add?: ");
    scanf("%d", &adminSize);
    
    FILE *fptr = fopen("adminDTO.txt","a+");
    
	   for(i=0; i<adminSize; i++){
	 
        fflush(stdin);
        
        printf("Enter ID: ");
        scanf("%d",(adminR+i)->adminID);
        
    	printf("Enter Name: ");
        scanf("%s",(adminR+i)->adminName);
        
        printf("Enter Atm Name: ");
        scanf("%s",(adminR+i)->atmName);
        
        printf("Enter Password: ");
        scanf("%d",&(adminR+i)->adminPassword);
		
        fwrite((adminR+i), sizeof(struct adminDTO), 1, fptr);
    }
   		fclose(fptr);
}
void userAdd(struct userDTO *userR){
	
	int userSize,fileSize;
    
	setlocale(LC_ALL,"Turkish");

    printf("How many user you will add?: ");
    scanf("%d", &userSize);
    
    FILE *fptr = fopen("userDTO.txt","a+");
    int *ptr, i;
	   for(i=0; i<=userSize; i++){
	 
        printf("Enter ID: ");
        scanf("%s",(userR+i)->userID);
        
    	printf("Enter name: ");
        scanf("%s",(userR+i)->userName);
        
        printf("Enter Customer Number: ");
        scanf("%d",&(userR+i)->customerNumber);
        
        printf("Enter IBAN: ");
        scanf("%d",&(userR+i)->IBANNo);
        
        printf("Enter Money: ");
        scanf("%f",&(userR+i)->money);
        
        printf("Enter Password(4 digit): ");
        scanf("%d",&(userR+i)->userPassword);
        
        printf("Enter Debt: ");
        scanf("%f",&(userR+i)->debt);
        
        (userR+i)->isUserActive=1;
        fwrite((userR+i), sizeof(struct userDTO), 1, fptr);
    }
        
   		fclose(fptr);	
}
void drawingCashScreen(){
	printf(" _______             _______ \n");
	printf("|1) 10TL              |           |5)100TL              |\n");
	printf("|_______|           |_______|\n");
	printf("|2) 20TL              |           |6)250TL              |\n");
	printf("|_______|           |_______|\n");
	printf("|3) 30TL              |           |7)1000TL             |\n");
	printf("|_______|           |_______|\n");
	printf("|4) 50TL              |           |8)OTHER AMOUNT TL:   |\n");
	printf("|_______|           |_______|\n\n");
	printf("|		              |           |9)RETURN				|\n");
	printf("|_______|           |_______|\n\n");
	}	
void drawingCash(struct userDTO* userR){ 
	
	int moneyChoice,userID;
	drawingCashScreen();
	
	FILE *cmp=fopen("kayit.txt","r+");

	printf("%f",userR->money);
	printf("Enter your choice:");
	scanf("%d",&moneyChoice);
	
	switch(moneyChoice){
	case 1:{
		system("cls");
		userR->money-=10;
		printf("%.2f",userR->money);
		fseek (cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;
		}
	case 2:{
		system("cls");
		userR->money-=20;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;}
	case 3:{
		system("cls");
		userR->money-=30;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;
		}
	case 4:{
		system("cls");
		userR->money-=50;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;
		}
	case 5:{
		system("cls");
		userR->money-=100;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;
		}
	case 6:{
		system("cls");
		userR->money-=250;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		break;
		}
	case 7:{
		system("cls");
		userR->money-=100;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		}
	case 8:{
		system("cls");
		otherAmountMoney(userR);
		break;
		}
	case 9:{
		system("cls");
		mainScreenMenu(userR);
		break;
	}
	}
}
void otherAmountMoney(struct userDTO* userR){
	
	int amount;
	
	FILE *cmp=fopen("userDTO.txt","r+");
	
	printf("Please enter an amount: \n");
	scanf("%d",&amount);
	
    if(amount>(userR)->money){
		system("cls");
		printf("You cannot withdraw this amount of money! Please try again...");
		drawingCash(userR);
		}else if(amount%10!=0){
		system("cls");
		printf("10 ve 10'un katlarýný çekiniz");
		drawingCash(userR);	
		}
		else{
		(userR)->money-=amount;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
	}
	fclose(cmp);
}
void transferMoney(struct userDTO *userR){
	
	char account[4];
	int amount,i,transferType,otherCustomerIBAN,fileSize;
	
	transferMoneyScreen();
	
	printf("What is your choice?"); 
	scanf("%d",&transferType);
	FILE *cmp=fopen("kayit.txt","r+");
	switch(transferType){
		case 1:{
			system("cls");
		    printf("Please Enter other customer's IBAN: ");
		    scanf("%d",&otherCustomerIBAN);
		    printf("Please Enter amount:");
		    scanf("%d",&amount);
			
			userR->money-=amount;
		for(i = 0;i<2;i++){
		fread(userR,sizeof(struct userDTO),1,cmp);

		if(userR->IBANNo==otherCustomerIBAN){
			
			userR->IBANNo+=amount;
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
			printf("%d Paranýz Baþarýlý bir þekilde gönderilmiþtir",amount);
		}
	}
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
		}

			case 2:{
			system("cls");
			printf("Bu iþlemde hesabýnýzdan 10TL ekstra iþlem ücreti alýnacaktýr");
		    printf("Please Enter other customer's IBAN: ");
		    scanf("%d",&otherCustomerIBAN);
		    printf("Please Enter amount:");
		    scanf("%d",&amount);
			
			userR->money=10+amount;

			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);	
			break;
		}
			case 3:{
			system("cls");
			printf("Bu iþlemde hesabýnýzdan 50TL ekstra iþlem ücreti alýnacaktýr");
		    printf("Please Enter other customer's IBAN: ");
		    scanf("%d",&otherCustomerIBAN);
		    printf("Please Enter amount:");
		    scanf("%d",&amount);
			
			userR->money=50+amount;

			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);	
			break;
		}
	}

	for(i=0;i<2;i++){
		fread((userR),sizeof(struct userDTO),1,cmp);
		if(strcmp(account,(userR)->userID)==0){
			printf("Enter an amount:"); scanf("%d",&amount);
			(userR)->money+=amount;
			//kendi bakiyesinden düþsün
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
		}
		else 
		printf("There is no account!");
}
}
void transferMoneyScreen(){
	printf(" _____________________________________________\n");
	printf("|1)	    DBANK TO DBANK      |  9) IPTAL       |\n");
	printf("|___________________________|_________________|\n");
	printf("|2) DBANK TO OTHER BANK     |				  |\n");
	printf("|___________________________|				  |\n");
	printf("|3) DBANK TO FOREIGN BANK   | 				  |\n");
	printf("|___________________________|_________________|\n");
}
void userDelete(struct userDTO *userR){
	int i ;
	char userID1[5];
    userList(userR);
    
    printf("Silinecek kiþinin ID'si");
    scanf("%s",userID1);
    
 	FILE *cmp=fopen("userDTO.txt","r+");	  

	
		while(!feof(cmp)){
		fread(userR,sizeof(struct userDTO),1,cmp);
		if(strcmp((userR)->userID,userID1) == 0){
			userR->isUserActive=0;
			fseek(cmp,1*sizeof(struct userDTO), SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
			
		}
	}
    fflush(stdin);
}
void userList(struct userDTO *userR){
	
	int i;
	FILE *cmp=fopen("userDTO.txt","r");	  
	    	
    	while(!feof(cmp)){
    	fread(userR,sizeof(struct userDTO),1,cmp);
	    printf("* ID: %s Name: %s IBAN: %d Password: %.d TL Cutomer num: %d TL *\n", userR->userID, userR->userName,userR->IBANNo,userR->userPassword,userR->customerNumber);
    }
    fclose(cmp);
}
void mainScreenMenu(struct userDTO *userR){
	int secim;
	
 	mainMenuScreen();
	scanf("%d",&secim);
	switch(secim){
		case 1 :{
			drawingCash(userR);
			break;
		}
		case 2 :{
			transferMoney(userR);
			break;
		}
		case 3:{
			loadMoney(userR);
			break;
		}
		case 4:{
			userDetail(userR);
			break;
		}
		case 5:{
			main();
			break;
		}
		default :{
			printf("Lütfen Farklý Bir Seçim Yapýnýz");
			mainScreenMenu(userR);
			break;
		}
	}
}
void loadMoney(struct userDTO *userR){
	int amount,choice;
	
	FILE *cmp=fopen("kayit.txt","r+");
	printf("Devam Etmek için 1'e bir önceki ekran için 9 a basýn");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
				printf("Please enter an amount: \n");
	scanf("%d",&amount);
	
    if(amount>userR->money){
		system("cls");
		printf("You cannot withdraw this amount of money! Please try again...");
		loadMoney(userR);
		}else if(amount%10!=0){
		system("cls");
		printf("10 ve 10'un katlarýný giriniz.");
		loadMoney(userR);	
		}
		else{
		printf("\niþleminiz baþarýlý bir þekilde tamamlanmýþtýr");
		(userR)->money+=amount;
		printf("\n%.2f TL",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		printf("\nAna Ekrana Dönmek için bir tuþa basýn");
		getch();
		system("cls");
		mainScreenMenu(userR);
	}
	fclose(cmp);
			break;
		}
		case 9:{
			mainScreenMenu(userR);
			break;
		}
		
	}
	
}
void mainMenuScreen(){
	system("cls");
	printf(" _______             _______ \n");
	printf("|1)PARA CEKME      |             |4)HESAP DETAY        |\n");         
	printf("|_______|           |_______|	 |5)IPTAL			   |\n");
	printf("|2)PARA AKTARMA             |\n");
	printf("|_______|           |_______|\n");
	printf("|3)PARA YATIRMA            |\n");
	printf("|_______|           |_______|\n\n");
	printf("Seçiminizi yapýnýz (1,2,3..) ");
}
void startAppScreen(){
	system("cls");
	printf(" _______             _______ \n");
	printf("|1)    Kullanýcý Giriþi     |\n");         
	printf("|_______|           |_______|\n");
	printf("|2) 	 Admin Giriþi     	|\n");
	printf("|_______|           |_______|\n");
}
void startApp(struct userDTO *userR, struct adminDTO *adminR){
	
	int choice,a;
	
	startAppScreen();
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:{
			login(userR);
			break;
		}
		case 2:{
			adminLogin(adminR,userR);
			break;
		}
	}
}
void login(struct userDTO *userR){
	
	int customerNumber,password;

	FILE *cmp=fopen("userDTO.txt","r");
	
	printf("Kullanýcý Numaranýz Giriniz: ");
	scanf("%d",&customerNumber);
	printf("Kullanýcý Þifrenizi Giriniz: ");
	scanf("%d",&password);
	  
	while(!feof(cmp)){
	    	
		fread(userR,sizeof(struct userDTO),1,cmp);
			  
		if((customerNumber==userR->customerNumber)&&(password==userR->userPassword)){
			printf("Giriþ Baþarýlý");
			system("cls");
			mainScreenMenu(userR);
			break;
			}
		}
	fclose(cmp);
}
void adminLogin(struct adminDTO *adminR,struct userDTO *userR){
	int adminID,password;

	FILE *cmp=fopen("adminDTO.txt","r");
	
	printf("Admin Numaranýz Giriniz: ");
	scanf("%d",&adminID);
	printf("Kullanýcý Þifrenizi Giriniz: ");
	scanf("%d",&password);
	  
	while(!feof(cmp)){
	    	
		fread(adminR,sizeof(struct adminDTO),1,cmp);
			  
		if((adminID==adminR->adminID)&&(password==adminR->adminPassword)){
			printf("Giriþ Baþarýlý");
			adminScreenMenu(userR);
			break;
			}
		}
	fclose(cmp);
}
void adminScreen(){
	system("cls");
	printf(" _______             _______ \n");
	printf("|1)Kullanýcý Ekleme 		|       |4)Admin Ekle    |\n");         
	printf("|_______|           |_______|       |5)IPTAL         |\n");
	printf("|2)Kullanýcý Silme          |\n");
	printf("|_______|           |_______|\n");
	printf("|3)Kullanýcý Görüntüle      |\n");
	printf("|_______|           |_______|\n\n");
	printf("Seçiminizi yapýnýz (1,2,3..) ");
}
void adminScreenMenu(struct userDTO *userR){

	int secim;
	adminScreen();

	scanf("%d",&secim);
	switch(secim){
		case 1 :{
			system("cls");
			userAdd(userR);
			break;
		}
		case 2 :{
			system("cls");
			userDelete(userR);
			break;
		}
		case 3:{
			userList(userR);
			break;
		}
			case 5:{
			system("cls");
			main();
			break;
		}
		default :{
			printf("Lütfen Farklý Bir Seçim Yapýnýz");
			
			break;
		}
	}
}
void userDetail(struct userDTO *userR){
	int choice;
	system("cls");
	printf("Adý %s \n IBAN: TR %d \n Para %2.f TL ",userR->userName,userR->IBANNo,userR->money);
	printf("\n9) RETURN");
	scanf("%d",&choice);
	switch(choice){
		case 9:{
			mainScreenMenu(userR);
			break;
		}
	}
	
}
int main() {
	
	setlocale(LC_ALL, "Turkish"); 
	
	struct userDTO *user=(struct userDTO*) malloc(1 * sizeof(struct userDTO));
	struct adminDTO *adminR=(struct adminDTO*)malloc(1*sizeof(struct adminDTO));
//adminAdd(adminR);
	startApp(user,adminR);

	return 0;
}
