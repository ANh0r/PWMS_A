//Display original page first;
//To delete some lines---->control pannel
//Display after page;
//Using Browse Page;
#include <stdio.h>
#include <windows.h>
#include<string.h>
#include "ProjectHeader.h"
#include"sqlite3.h"
#define Conls 150
 void BrowsePage2(void);
 void deleteData(char _ID[50]) ;


int   DelepageUI(void){
	system("title Delete information");
	
	system("cls");

	if(PasscodeFunc() == 0){
		return 0;	
	}
	char _ID[50];
	char UserChoice;
	
	while(1){
	//getchar();
	
	system("cls");
	BrowsePage2();
	printf("Please input the ID below\n");
	scanf("%s",_ID);
	deleteData(_ID);
	printf("Please Choosing Keeping Deleting (ANY KEYS) or Exit(E)\n");
	getchar();
	scanf("%c",&UserChoice);
	
	if (UserChoice=='E'||UserChoice=='e'){
		     break;
	}//if end
	else
		getchar();
	}//while end
		
		
	
	
	//while(UserChoice!='e'||UserChoice!='E');
	


	/*//Line 
	for(int i=0;i<Conls;i++)
		printf("=");*/

}//DelepageUI end

 void deleteData(char _ID[100]) {
	sqlite3 *db = 0;	
	char ret1 = 0;	
	char ret2;
	char *errmsg = 0;
	char **dbResult;	
	int rowNum, columnNum;// index;

	sqlite3_open("./Adding.db", &db);	

	ret1 = sqlite3_get_table(db, "SELECT * FROM `AccountsPass` ORDER BY CAST (`ID` AS BINARY) ASC", &dbResult, &rowNum, &columnNum, &errmsg);
	/*if (ret == SQLITE_OK) 
		index = columnNum;*/
	



	char query[200] = "DELETE FROM `AccountsPass` WHERE `ID` = '";
		strcat(query, _ID);
		strcat(query, "'");

		//DELETE FROM `AccountsPass` WHERE `Login name` = '001'
		/*typedef  int  ( * sqlite3_callback ) (void  * , int , char ** ,char **  );
		其中void *是为sqlite3_exec()第四个参数提供的数据，
		int代表字段的数目，char** 便是行中字段名称的字符串的数组，
		char**表示字段ing成的字符串数组。*/
	ret2 =sqlite3_exec (db,query , 0, &rowNum, (char **)errmsg);
}//static end


void BrowsePage2(void){// Show original Data
	
	//while (1) {
		//getchar();
		
		
	
		system("cls");
		

		//line above
	for (int i = 0; i < Conls; i++) {
		printf("=");
		}//for end
	
		printf("\n\n\t\t                         -------->   Editing the specific Information of the system\n\n");
		printf("\n\n\t\t                         -------->   To delete some lines,please input the ID on the end of the page\n\n");

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}//for end
		printf("\n");

		printf("ID        The Website	                Login name	    The 3rd acconuts    Phone number	    E-mail address	          Password\n");
	//	printf("\n");
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end

		printf("\n");

		showData(0);		//Show Data 

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end
	//}//while end
		



}//BrowsePage2 end