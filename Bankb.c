#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Customer{
	int account;
	char name[30];
	char birth[30];
	char address[50];
	char acc_type[50];
	int telnum;
	int amount;
};

int login();
int Get_data();
int check_value();
int List_customers();
int delete_acc();
int transfer();
int deposite();
int withdraw();
int update();
int copy_valueErr(int number);
int menu(){
	system("clear");
	int n;
	int choice;
	do{
		printf("\n\n\n");
		printf("\n\t\t\t\t\t\t\t     ++++++++++++++++++++++++++++++++++      ");
		printf("\n\t\t\t\t\t\t\t     +        SELECT THE OPTION       +      ");
		printf("\n\t\t\t\t\t\t\t     ++++++++++++++++++++++++++++++++++      \n\n");

		printf("\n\t\t\t\t\t\t\t ___________________________________________");
		printf("\n\t\t\t\t\t\t\t| [1] CREATE ACCOUNT                        |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [2] TRANSACTION                           |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [3] CKECK THE DETAILS EXITING ACCOUNT     |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [4] CUSTOMER LIST                         |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [5] OWN ACCOUNT TRANSFER                  |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [6] UPDATE ACCOUNT                        |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [7] DELETE ACCOUNT                        |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|");
		printf("\n\t\t\t\t\t\t\t| [0] EXIT                                  |");
		printf("\n\t\t\t\t\t\t\t| __________________________________________|\n");

		printf("\n\t\t\t\t\t\tCHOOSE THE NUMBER IN THE BOX ABOVE: ");
		scanf("%d",&n);
		printf("\n\n");

		if(n == 0){
			system("clear");
			printf("\n\t\t\t\t\t _______________________________________________________________________ ");
			printf("\n\t\t\t\t\t|  ___________________________________________________________________  |");
			printf("\n\t\t\t\t\t| |                                                                   | |");
			printf("\n\t\t\t\t\t| |                                                                   | |");
			printf("\n\t\t\t\t\t| | ++++++++++++  +++    +++       ++++       +++++   +-+  +-+   +--+ | |");
			printf("\n\t\t\t\t\t| | +++++--+++++  +-+    +-+      +-++-+      +-++-+  +-+  +-+  +-+   | |");
			printf("\n\t\t\t\t\t| |     +--+      +-+----+-+     +-+--+-+     +-+ +-+ +-+  +-+++-+    | |");
			printf("\n\t\t\t\t\t| |     +--+      +-+----+-+    +-+----+-+    +-+  +-++-+  +-+++-+    | |");
			printf("\n\t\t\t\t\t| |     +--+      +-+    +-+   +-+      +-+   +-+   +-+-+  +-+  +-+   | |");
			printf("\n\t\t\t\t\t| |     +--+      +-+    +-+  +-+        +-+  +-+    ++++  +-+   +--+ | |");
			printf("\n\t\t\t\t\t| |                                                                   | |");
			printf("\n\t\t\t\t\t| |                     +-+  +-+   +++++   +-+  +-+                   | |");
			printf("\n\t\t\t\t\t| |                      +-++-+   +-+ +-+  +-+  +-+                   | |");
			printf("\n\t\t\t\t\t| |                       +--+    +-+ +-+  +-+  +-+                   | |");
			printf("\n\t\t\t\t\t| |                       +--+    +-+ +-+  +-+  +-+                   | |");
			printf("\n\t\t\t\t\t| |                       +--+     +++++    ++++++                    | |");
			printf("\n\t\t\t\t\t| |                                                                   | |");
			printf("\n\t\t\t\t\t| |                           FOR USING BMS!                          | |");
			printf("\n\t\t\t\t\t| |                                                                   | |");
			printf("\n\t\t\t\t\t| |___________________________________________________________________| |");
			printf("\n\t\t\t\t\t|_______________________________________________________________________|\n");
			exit(0);
			break;
		}else{
			switch(n){
				case 1:
					Get_data();
					break;
				case 2:
					// transaction();
					system("clear");
					printf("\n\n\n\n\n\n\tTRANSACTION\n\t-----------------");
					printf("\n\t[1].DEPOSITE\n");
					printf("\t[2].WITHDRAW\n");
					printf("\t[0].BACK TO MENU\n");
					printf("\t-----------------\n");
					printf("\tChoose a number: ");
					scanf("%d",&choice);

					switch(choice){
						case 1:
							deposite();
							break;
						case 2:
							withdraw();
							break;
						case 0:
							system("clear");
					}
					break;

				case 3:
					check_value();
					break;
				case 4:
					List_customers();
					break;
				case 5:
					transfer();
					break;
				case 6:
					update();
					break;
				case 7:
					delete_acc();
					break;
			}
		}



	}while(n != 0);
}

int main(){
	system("clear");
	login();


	menu();
	return 0;
}

//Create A New Account for User
int Get_data(){

	system("clear");

	printf("\n\n\n\n\tNEW CUSTOMER ADDING");
	printf("\n\t________________________________________\n\n");
	struct Customer std1;
	FILE *file;
	int i,q,check,exit;

	file = fopen("document.txt","a");
		printf("\tEnter Account No.(Ex:- 1000): ");
		scanf("%d",&q);
		int x = copy_valueErr(q);

		if(x != 1){

			std1.account = q;

			printf("\n\tEnter Name : ");
			scanf(" %[^\n]%*c",std1.name);

			printf("\n\tEnter Birth Day : ");
			scanf(" %[^\n]%*c",std1.birth);

			printf("\n\tEnter Your Address : ");
			scanf(" %[^\n]%*c",std1.address);

			printf("\n\tEnter Type Of Account (Savings or Current): ");
			scanf(" %[^\n]%*c",std1.acc_type);

			printf("\n\tEnter Phone Number : ");
			scanf("%d",&std1.telnum);

			printf("\n\tEnter Amount : ");
			scanf("%d",&std1.amount);

			//Take user confirm to save this account
			printf("\n\t________________________________________\n\n");
			printf("\t[1].YES\n");
			printf("\t[0].NO\n\n");
			printf("\tDo you want to Save This Account : ");
			scanf("%d",&check);
			printf("\t________________________________________\n");

			if(check== 1){
				fwrite(&std1, sizeof(std1),1,file);
				fclose(file);
				printf("\n\tACCOUNT CREATED SUCCESSFULLY!!\n");

			}else{
				fclose(file);

			}


		}else{
			printf("\tError:: This Account Number Earlier Add.!\n");
		}

	printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");


}

//TRANSACTION
	//DEPOSITE MONEY
	int deposite(){

		printf("\n\n\t\tMONEY DEPOSITE\n\t\t--------------------\n");
		FILE *file,*copy;
		struct Customer stdD1;
		int AccNum,Amt,exit;

		file = fopen("document.txt","r");
		copy = fopen("copy.txt","w");
		printf("\t\tEnter Account Number To DEPOSITE: ");
		scanf("%d",&AccNum);

		//Conforming Account number is valid ?
		int x = copy_valueErr(AccNum);
		if(x==1){
			printf("\t\tEnter Amount: ");
			scanf("%d",&Amt);

			if(file == NULL){
				fprintf(stderr,"\t\tCan't open file\n");
			}

			while(fread(&stdD1,sizeof(struct Customer),1,file)){
				if(stdD1.account != AccNum){
					fwrite(&stdD1,sizeof(struct Customer),1,copy);
				}else{
					stdD1.amount += Amt;
					fwrite(&stdD1,sizeof(struct Customer),1,copy);
					//continue;

				}
			}
			fclose(file);
			fclose(copy);

			remove("document.txt");
			rename("copy.txt","document.txt");
			printf("\n\t\tTRANSACTION SUCCESSFUL!!\n");

		}else{
			printf("\t\tError:: This '%d' Account Number Not Valid!\n",AccNum);

		}

		printf("\n\t\t\t------------------------------\n\t\t\tENTER ANY NUMBER TO BACK : ");
		scanf("%d",&exit);
		system("clear");

	}

	// WITHDRAW MONEY
	int withdraw(){

		printf("\n\t\tWITHDRAW MONEY\n\t\t--------------------\n");
		FILE *file,*copy;
		struct Customer stdD1;
		int AccNum,Amt,exit;

		file = fopen("document.txt","r");
		copy = fopen("copy.txt","w");
		printf("\t\tEnter Account Number To WITHDRAW: ");
		scanf("%d",&AccNum);

		//Conforming Account number is valid ?
		int x = copy_valueErr(AccNum);
		if(x == 1){
			printf("\t\tEnter Amount: ");
			scanf("%d",&Amt);

			if(file == NULL){
				fprintf(stderr,"\t\tCan't open file\n");
			}

			while(fread(&stdD1,sizeof(struct Customer),1,file)){
				if(stdD1.account != AccNum){
					fwrite(&stdD1,sizeof(struct Customer),1,copy);
				}else{
					if(stdD1.amount >= Amt){
						stdD1.amount -= Amt;
						fwrite(&stdD1,sizeof(struct Customer),1,copy);
						printf("\n\t\tTRANSACTION SUCCESSFUL!! \n");
					}else{
						stdD1.amount -= 0;
						fwrite(&stdD1,sizeof(struct Customer),1,copy);
						printf("\t\tError:: You have not enough account balance. \n");
					}

				}
			}
			fclose(file);
			fclose(copy);

			remove("document.txt");
			rename("copy.txt","document.txt");
			//fun();
		}else{
			printf("\t\tError:: This '%d' Account Number Not Valid!\n",AccNum);
			//fun();
		}

		printf("\n\t\t\t------------------------------\n\t\t\tENTER ANY NUMBER TO BACK : ");
		scanf("%d",&exit);
		system("clear");
	}


//Display Details Of Account Holder
int check_value(){
	system("clear");

	printf("\n\n\n\n\tCUSTOMER CHECKING\n\t--------------------\n");
	struct Customer std2;
	FILE *file;
	int i, Acc_no,exit;

	file = fopen("document.txt","rb");

		printf("\n\tEnter Account No. :");
		scanf("%d",&Acc_no);
		int y = copy_valueErr(Acc_no);
		if(y==1){
			while(fread(&std2,sizeof(struct Customer),1,file)){
				if(std2.account == Acc_no){
					printf("\n\t| Account Holder\t| %s",std2.name);
					printf("\n\t|\t\t\t|");
					printf("\n\t| Birth Day\t\t| %s",std2.birth);
					printf("\n\t|\t\t\t|");
					printf("\n\t| Address\t\t| %s",std2.address);
					printf("\n\t|\t\t\t|");
					printf("\n\t| Account Type\t\t| %s",std2.acc_type);
					printf("\n\t|\t\t\t|");
					printf("\n\t| Phone Number\t\t| %d",std2.telnum);
					printf("\n\t|\t\t\t|");
					printf("\n\t| Amount\t\t| %d",std2.amount);


				}
			}
		}else{
			printf("\n\tError:: This Account Number Not Valid! ");
		}

	fclose(file);

	printf("\n\n\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");
}


//List all of customers
int List_customers(){

	system("clear");

	printf("\n\n\n\n\tCUSTOMER LIST\n");
	struct Customer std2;
	FILE *file;
	int i, Acc_no,exit;

	file = fopen("document.txt","r");

		printf("\t-----------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t|%-10s|%-20s|%-15s|%-30s|%-15s|%-15s|%-15s","Acc No","Account_Holder","Birth_Day","Address","Account_Type","Phone_Num","Amount\n");
		printf("-----------------------------------------------------------------------------------------------------------------------------\n");
		while(fread(&std2,sizeof(struct Customer),1,file)){
			printf("\t|%-10d|%-20s|%-15s|%-30s|%-15s|%-15d|%-15d\n",std2.account,std2.name,std2.birth,std2.address,std2.acc_type,std2.telnum,std2.amount);

		}


	fclose(file);

	printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");

}

//Delete Row Data
int delete_acc(){
	system("clear");

	printf("\n\n\n\n\tACCOUNT DELETE\n\t--------------------\n");

	FILE *file,*copy;
		struct Customer stdD1;
		int n,exit;

		file = fopen("document.txt","r");
		copy = fopen("copy.txt","w");
		printf("\tEnter Account Number To Delete: ");
		scanf("%d",&n);


		int x = copy_valueErr(n);
		if(x == 1){

			if(file == NULL){
				fprintf(stderr,"\t\tCan't open file\n");
			}

			while(fread(&stdD1,sizeof(struct Customer),1,file)){
				if(stdD1.account != n){
					fwrite(&stdD1,sizeof(struct Customer),1,copy);
				}else{
					continue;
				}
			}
			fclose(file);
			fclose(copy);

			remove("document.txt");
			rename("copy.txt","document.txt");
			printf("\n\t!!! RECORD DELETED. !!!\n");
		}else{
			printf("\n\tError:: This Account Number Not Found.!\n");
		}


	printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");

}
int transfer(){
	system("clear");

	printf("\n\n\n\n\tMONEY TRANSFER\n\t--------------------\n");
	printf("\n\t[0]EXIT\n");

		FILE *file,*copy;
		struct Customer stdD1;
		int n,S,nn,exit;


		printf("\n\tENTER FROM ACCOUNT NUMBER: ");
		scanf("%d",&n);

		if (n!=0) {
			int x = copy_valueErr(n);
			if (x!=1){
				printf("\n\tError:: This FROM Account Number Not Found.!\n");
				printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
				scanf("%d",&exit);
				menu();
				system("clear");
			}
			printf("\tEnter Amount: ");
			scanf("%d",&S);

			printf("\n\tENTER TO ACCOUNT NUMBER: ");
			scanf("%d",&nn);

			int y = copy_valueErr(nn);
			if (y!=1){
				printf("\n\tError:: This TO Account Number Not Found.!\n");
				printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
				scanf("%d",&exit);
				menu();
				system("clear");
			}

		}else if (n == 0){
			menu();

		}

		//deposite money to account num.
		file = fopen("document.txt","r");
		copy = fopen("copy.txt","w");

		if(file == NULL){
			fprintf(stderr,"\t\tCan't open file\n");
		}

		while(fread(&stdD1,sizeof(struct Customer),1,file)){
			if(stdD1.account != n){
				fwrite(&stdD1,sizeof(struct Customer),1,copy);
			}else{
				stdD1.amount -= S;
				fwrite(&stdD1,sizeof(struct Customer),1,copy);
			}
		}
		fclose(file);
		fclose(copy);

		remove("document.txt");
		rename("copy.txt","document.txt");

		//withdraw money to account num.
		file = fopen("document.txt","r");
		copy = fopen("copy.txt","w");


		if(file == NULL){
			fprintf(stderr,"\t\tCan't open file\n");
		}

		while(fread(&stdD1,sizeof(struct Customer),1,file)){
			if(stdD1.account != nn){
				fwrite(&stdD1,sizeof(struct Customer),1,copy);
			}else{
				stdD1.amount += S;
				fwrite(&stdD1,sizeof(struct Customer),1,copy);

			}
		}
		fclose(file);
		fclose(copy);

		remove("document.txt");
		rename("copy.txt","document.txt");
		printf("\n\tTRANSACTION SUCCESSFUL!! ");


	printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");
}

//update account
int update(){
	system("clear");
	printf("\n\n\n\n\tUPDATE ACCOUNT\n\t--------------------\n");

	FILE *file, *copy;
	struct Customer stdD1;
	struct Customer new_details;

	file = fopen("document.txt", "r");
	copy = fopen("copy.txt", "w");

	printf("\t[01]Enter The Account Number To UPDATE: ");
	scanf("%d", &new_details.account);
	getchar();

	int x = copy_valueErr(new_details.account);
	if(x==1){
		printf("\n\t[02]Enter Your Name To Update: ");
		scanf("%29[^\n]", new_details.name);
		getchar();

		printf("\n\t[03]Enter Your Birth Day To Update: ");
		scanf("%29[^\n]", new_details.birth);
		getchar();

		printf("\n\t[04]Enter Your New Address To Update: ");
		scanf("%49[^\n]", new_details.address);
		getchar();

		printf("\n\t[05]Enter Your New Telephone No: ");
		scanf("%d", &new_details.telnum);
		getchar();


		if (file == NULL) {
			fprintf(stderr, "\t\tCan't open file\n");
		}

		while (fread(&stdD1, sizeof(struct Customer), 1, file)) {
			if (stdD1.account != new_details.account) {

				fwrite(&stdD1, sizeof(struct Customer), 1, copy);
			} else {

				strcpy(stdD1.name, new_details.name);
				strcpy(stdD1.birth, new_details.birth);
				strcpy(stdD1.address, new_details.address);
				stdD1.telnum = new_details.telnum;

				fwrite(&stdD1, sizeof(struct Customer), 1, copy);

			}
		}
		fclose(file);
		fclose(copy);

		remove("document.txt");
		rename("copy.txt", "document.txt");
		printf("\n\tUPDATE SUCCESSFULL!!\n");
	}else{
		printf("\n\tError:: This Account Number could not find to Update\n");
	}


	int exit;
	printf("\n\t\t------------------------------\n\t\tENTER ANY NUMBER TO BACK : ");
	scanf("%d",&exit);
	system("clear");

}

//Validate Same Account Numbers and Return the Error key 1
int copy_valueErr(int number){
	struct Customer stdcopy;
	FILE *file;

	file = fopen("document.txt","rb");

	while(fread(&stdcopy,sizeof(struct Customer),1,file)){
		if(stdcopy.account == number){
			return 1;
		}
	}
	fclose(file);
}


//User Login
int login() {

	system("clear");
	char pass[10]="12345678";
	char get_pass[10];
	int again;
	int match;

	printf("\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n");
	printf("\n\t\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t\t\t\t        =                                               =");
	printf("\n\t\t\t\t\t\t        =                                               =");
	printf("\n\t\t\t\t\t\t        =                 ~~ WELCOME ~~                 =");
	printf("\n\t\t\t\t\t\t        =            BANK MANAGEMENT SYSTEM             =");
	printf("\n\t\t\t\t\t\t        =                                               =");
	printf("\n\t\t\t\t\t\t        =                                               =");
	printf("\n\t\t\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\n\t\t\t\t\t\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n\n");

	printf("\n\t\t\t\t\t\t    =======================        =======================");
	printf("\n\t\t\t\t\t\t     | | | | | | | | | | |  LOGIN   | | | | | | | | | | | ");
	printf("\n\t\t\t\t\t\t    =======================        =======================");

	printf("\n\n\n\t\t\t\t\t\t\t\tEnter PIN number: ");
	scanf("%s",get_pass);

	match=strcmp(pass, get_pass);

	if (match==0) {
		menu();
	}
	else {
		printf("\n\n\t\t\t\t\t\tIncorrect PIN !");
		printf("\n\t\t\t\t\t\tEnter 1 to login again: ");
		scanf("%d", &again);
			if (again==1) {
				login();
			}
			else {
				login();
			}
	}

}
