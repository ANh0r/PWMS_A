//Display original page first;
//To delete some lines---->control pannel
//Display after page;
//Using Browse Page;
#include <stdio.h>
#include <windows.h>
#include<string.h>
#include "ProjectHeader.h"
#include"sqlite3.h"
#define Conls 120
 void BrowsePage2(void);
 void deleteData(char _ID[50]) ;


void  DelepageUI(void){
	char _ID[50];
	char UserChoice;
	
	while(1){
	//getchar();
	
	system("cls");
	BrowsePage2();
	printf("Please input the Website below\n");
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
	sqlite3 *db = 0;	//���ݿ�
	char ret1 = 0;	//����ֵ
	char ret2;
	char *errmsg = 0;
	char **dbResult;	//���صĲ�ѯ����
	int rowNum, columnNum;// index;

	sqlite3_open("./Adding.db", &db);	//�������ݿ�

	ret1= sqlite3_get_table(db, "SELECT * FROM `AccountsPass`", &dbResult, &rowNum, &columnNum, &errmsg);
	/*if (ret == SQLITE_OK) 
		index = columnNum;*/
	



	char query[200] = "DELETE FROM `AccountsPass` WHERE `The Website` = '";
		strcat(query, _ID);
		strcat(query, "'");

		//DELETE FROM `AccountsPass` WHERE `Login name` = '001'
		/*typedef  int  ( * sqlite3_callback ) (void  * , int , char ** ,char **  );
		����void *��Ϊsqlite3_exec()���ĸ������ṩ�����ݣ�
		int�����ֶε���Ŀ��char** ���������ֶ����Ƶ��ַ��������飬
		char**��ʾ�ֶ�ing�ɵ��ַ������顣*/
	ret2 =sqlite3_exec (db,query , 0, &rowNum, (char **)errmsg);
}//static end


void BrowsePage2(void){// Show original Data
	
	//while (1) {
		//getchar();
		
		
	
		system("cls");
		

		//�Ϸ�����
	for (int i = 0; i < Conls; i++) {
		printf("=");
		}//for end
	
		printf("\n\n                         -------->   Editing the specific Information of the system\n\n");
		printf("\n\n                         -------->   To delete some lines,please input the Website on the end of the page\n\n");

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}//for end
		printf("\n");

		printf("The Website	    Login name	        The third acconuts  Phone number	E-mail address	    Password\n");
	//	printf("\n");
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end

		printf("\n");

		showData();		//��ʾ����

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end
	//}//while end
		



}//BrowsePage2 end