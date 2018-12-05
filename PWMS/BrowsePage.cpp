#define Conls 110
#define Lines 35

#include <stdio.h>
#include <windows.h>
#include"ProjectHeader.h"

#include "sqlite3.h"

void showData(void);

int loadBrowseInfoPage(void) {
	while (1) {
		getchar();
		
		
	
		system("cls");
		

		//上方的线
	for (int i = 0; i < Conls; i++) {
		printf("=");
		}
	
		printf("\n\n                         -------->   Browsing the specific Information of the system\n\n");

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");

		printf("The Website	    Login name	        The third acconuts  Phone number	E-mail address	    Password\n");
		//printf("");
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}

		printf("\n");

		showData();		//显示数据

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}
		BackUI();


		printf("----------------------------------------------->Input Any keys to go back<------------------------------------- \n\n");
		getchar();

		return 0;
	}

	return 0;
}

//显示数据
void showData(void) {
	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;
	char **dbResult;	//返回的查询数据
	int rowNum, columnNum, index;

	sqlite3_open("./Adding.db", &db);	//连接数据库

	ret = sqlite3_get_table(db, "SELECT * FROM `AccountsPass` ORDER BY `The Website`", &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("%-20s%-20s%-20s%-20s%-20s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5]);
			index += 6;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}