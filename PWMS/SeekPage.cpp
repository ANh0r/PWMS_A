/*
Draw UI first And the Input some static(Where sentences)
Need PIC;
and show data;
ShowData:that  some cols;
Plus: where can make some line+cols;


*/
#include <stdio.h>
#include <string.h>
#include "ProjectHeader.h"
#include "sqlite3.h"
#define Conls 150

int ShowSeekData(void);
void SeekUI(void);
void SeekInputUI(char _UserIn[100]);
void SeekInputUI2(char _UserIn2[100]);
void BackUI(void);


void SeekUI(void){
	//draw UI
	for(int i=0;i<Conls;i++){
		printf("=");
	}//for end


printf("\t\t\t------------------------->To search something in Database,you can choose Using Website or Username <--------------------\n");
printf("\n\n\n\n");
printf("\t\t\t\t\t.----------------. .----------------. .----------------. .----------------. \n");
printf("\t\t\t\t\t| .--------------. | .--------------. | .--------------. | .--------------. |\n");
printf("\t\t\t\t\t| |   ______     | | | _____  _____ | | | ____    ____ | | |    _______   | |\n");
printf("\t\t\t\t\t| |  |_   __ \\   | | ||_   _||_   _|| | ||_   \\  /   _|| | |   /  ___  |  | |\n");
printf("\t\t\t\t\t| |    | |__) |  | | |  | | /\\ | |  | | |  |   \\/   |  | | |  |  (__ \\_|  | |\n");
printf("\t\t\t\t\t| |    |  ___/   | | |  | |/  \\| |  | | |  | |\\  /| |  | | |   '.___`-.   | |\n");
printf("\t\t\t\t\t| |   _| |_      | | |  |   /\\   |  | | | _| |_\\/_| |_ | | |  |`\\____) |  | |\n");
printf("\t\t\t\t\t| |  |_____|     | | |  |__/  \\__|  | | ||_____||_____|| | |  |_______.'  | |\n");
printf("\t\t\t\t\t| |              | | |              | | |              | | |              | |\n");
printf("\t\t\t\t\t| '--------------' | '--------------' | '--------------' | '--------------' |\n");
printf("\t\t\t\t\t '----------------' '----------------' '----------------' '----------------' \n");
printf("\n\n\n\n");
printf("\t\t--------------------------->Choose  to seek in Login name(L) or Website(W)   E--->Quit<-------------------------------\n");


printf("\n\n\n");
}//SeekUI end

void BackUI(void){
	
//printf("----------------------------->To search something in Database,you can choose Using Website or Username <---------------------\n");
printf("\n\n\n\n");
printf("\t\t\t\t\t.----------------. .----------------. .----------------. .----------------. \n");
printf("\t\t\t\t\t| .--------------. | .--------------. | .--------------. | .--------------. |\n");
printf("\t\t\t\t\t| |   ______     | | | _____  _____ | | | ____    ____ | | |    _______   | |\n");
printf("\t\t\t\t\t| |  |_   __ \\   | | ||_   _||_   _|| | ||_   \\  /   _|| | |   /  ___  |  | |\n");
printf("\t\t\t\t\t| |    | |__) |  | | |  | | /\\ | |  | | |  |   \\/   |  | | |  |  (__ \\_|  | |\n");
printf("\t\t\t\t\t| |    |  ___/   | | |  | |/  \\| |  | | |  | |\\  /| |  | | |   '.___`-.   | |\n");
printf("\t\t\t\t\t| |   _| |_      | | |  |   /\\   |  | | | _| |_\\/_| |_ | | |  |`\\____) |  | |\n");
printf("\t\t\t\t\t| |  |_____|     | | |  |__/  \\__|  | | ||_____||_____|| | |  |_______.'  | |\n");
printf("\t\t\t\t\t| |              | | |              | | |              | | |              | |\n");
printf("\t\t\t\t\t| '--------------' | '--------------' | '--------------' | '--------------' |\n");
printf("\t\t\t\t\t '----------------' '----------------' '----------------' '----------------' \n");
printf("\n\n\n\n");

}//BackUI end
/*The codes below are used as the part if user chooses Website as the result!*/
void SeekInputUI(char _UserIn[100]){
	/*The codes below are used as the part if user chooses Website as the result!*/
	
	sqlite3 *db = 0;	
	int ret = 0;	
	char *errmsg = 0;
	char **dbResult;	
	int rowNum, columnNum, index;

	sqlite3_open("./Adding.db", &db);	

	char QueryUser[200]= "SELECT * FROM `AccountsPass` WHERE `The Website` = '";
	    strcat(QueryUser,  _UserIn);
		strcat(QueryUser, "'");
		strcat(QueryUser, " ORDER BY CAST (`ID` AS BINARY) ASC");

		//ORDER BY CAST (`ID` AS BINARY) ASC



	ret = sqlite3_get_table(db, QueryUser, &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("%-10s%-30s%-20s%-20s%-20s%-30s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5],dbResult[index + 6]);
			index += 7;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);

}//SeekInputUI end
/*The codes below are used as the part if user chooses Loginname as the result!*/
void SeekInputUI2(char _UserIn2[100]){
	/*The codes below are used as the part if user chooses Loginname as the result!*/
	
	sqlite3 *db = 0;	
	int ret = 0;	
	char *errmsg = 0;
	char **dbResult;	
	int rowNum, columnNum, index;

	sqlite3_open("./Adding.db", &db);	

	char QueryUser[200]= "SELECT * FROM `AccountsPass` WHERE `Login name` = '";
	    strcat(QueryUser,  _UserIn2);
		strcat(QueryUser, "'");
		strcat(QueryUser, "ORDER BY CAST (`ID` AS BINARY) ASC");
		//ret = sqlite3_get_table(db, "SELECT * FROM `AccountsPass` ORDER BY CAST (`ID` AS BINARY) ASC", &dbResult, &rowNum, &columnNum, &errmsg);


	ret = sqlite3_get_table(db, QueryUser, &dbResult, &rowNum, &columnNum, &errmsg);
		if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("%-10s%-30s%-20s%-20s%-20s%-30s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5],dbResult[index + 6]);
			index += 7;
			printf("\n");
		}
	}
	//sqlite3_free_table(dbResult);
	sqlite3_free_table(dbResult);

}//SeekInputUI2 end
int ShowSeekData(void){
	system("title Seeking in PWMS");
	system("cls");
	if(PasscodeFunc() == 0){
		return 0;	
	}




	char _UserIn[100];
	char The1Choice;
	char UserChoice;
	//int QuitGet;
	
	//
	while(1){
	
	getchar();	
  //  scanf("%c",&The1Choice);
	
	
	system("cls");
	SeekUI();
	
	scanf("%c",&The1Choice);
	if (The1Choice=='e'||The1Choice=='E')
		break;

	else if (The1Choice=='L'||The1Choice=='l'){
		/*The codes below are used as the part if user chooses Loginname as the result!*/
	
	printf("\t\t--------------------------------------->Please input the Login name you want to seek<---------------------------------\n");
	scanf("%s",_UserIn);
	system("cls");
	system("cls");
	for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");
		printf("\n");

		BackUI();
		printf("\t\t-------------------------------------------------------->Seeking Result<-----------------------------------------------\n\n");
	printf("ID        The Website	                Login name	    The 3rd acconuts    Phone number	    E-mail address	          Password\n");
	for (int i = 0; i < Conls; i++) {
			printf("-");

	}

	SeekInputUI2(_UserIn);
	for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");

	printf("Please Choosing Keeping Searching (ANY KEYS) Or Exit(E)\n");
	getchar();
	scanf("%c",&UserChoice);
	
	if (UserChoice=='E'||UserChoice=='e'){
		     break;
	}//if end
	
	//else
		//getchar();
	}//if big end


	else if(The1Choice=='W'||The1Choice=='w'){
		/*The codes below are used as the part if user chooses Website as the result!*/
	printf("\t\t------------------------------------------>Please input the Website you want to seek<---------------------------------\n");
	scanf("%s",_UserIn);
	system("cls");
	for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");
		printf("\n");
		
	
		BackUI();
		printf("\t\t-------------------------------------------------------->Seeking Result<-----------------------------------------------\t\n\n");
		printf("ID        The Website	                Login name	    The 3rd acconuts    Phone number	    E-mail address	          Password\n");
	for (int i = 0; i < Conls; i++) {
			printf("-");
		}
	SeekInputUI(_UserIn);
	for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");

	printf("Please Choosing Keeping Searching (ANY KEYS) or Exit(E)\n");
	getchar();
	scanf("%c",&UserChoice);
	if (UserChoice=='E'||UserChoice=='e'){
		     break;
	}//if end
	
	//else
		//getchar();
	}//the second big if end



	}//while end


	return 0;
}//ShowSeekData end



