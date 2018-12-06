#define Conls 150
#define Lines 35

#include <stdio.h>
#include <windows.h>
#include"ProjectHeader.h"

#include "sqlite3.h"

void showData(void);

int loadBrowseInfoPage(void) {
	system("title Browse information");
	while (1) {
		getchar();
		
		
	
		system("cls");
		

		//�Ϸ�����
	for (int i = 0; i < Conls; i++) {
		printf("=");
		}
	
		printf("\n\n \t\t\t                        -------->   Browsing the specific Information of the system\n\n");

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}
		printf("\n");

		printf("ID        The Website	                Login name	    The 3rd acconuts    Phone number	    E-mail address	          Password\n");
		//printf("");
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}

		printf("\n");

		showData();		//��ʾ����

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}
		BackUI();


		printf("-------------------------------------------------------------->Input Any keys to go back<------------------------------------------------------------- \n\n");
		getchar();

		return 0;
	}

	return 0;
}

//��ʾ����
void showData(void) {
	sqlite3 *db = 0;	//���ݿ�
	int ret = 0;	//����ֵ
	int ret2 =0;
	char *errmsg = 0;
	char **dbResult;	//���صĲ�ѯ����
	int rowNum, columnNum, index;

	sqlite3_open("./Adding.db", &db);	//�������ݿ�
	//ASC  ��  DESC��
	/*order by convert(int,sort) ASC����order by cast(sort as int) ASC
�����oracle���ݿ�Ļ�����order by to_number(sort) ASC; 
*/

	ret = sqlite3_get_table(db, "SELECT * FROM `AccountsPass` ORDER BY CAST (`ID` AS BINARY) ASC", &dbResult, &rowNum, &columnNum, &errmsg);
	ret2 =sqlite3_exec (db,"ALTER TABLE `AccountsPass`  MODIFY  `ID`  SMALLINT UNSIGNED AUTO_INCREMENT" , 0, &rowNum, (char **)errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("%-10s%-30s%-20s%-20s%-20s%-30s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5],dbResult[index + 6]);
			index += 7;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}