#define Conls 150
#define Lines 35

#include <stdio.h>
#include <windows.h>
#include"ProjectHeader.h"

#include "sqlite3.h"

void showData(int temp);

int loadBrowseInfoPage(void) {
	system("title Browse information");
	while (1) {
		int temp;
		int Userinput;
		getchar();
		
		
	
		system("cls");
		

		//line above
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

		showData(0);		//ShowData without  Passcode

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}

		printf("\n");

		printf("The Data was Locked,Please input ZR's birthday to unlock(4 int)\n");

		scanf("%d",&Userinput);
		if (Userinput==1215)
			temp=1;



		system("cls");
		

		//line above
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
		showData(temp);



		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}
		BackUI();
		getchar();//clear temp enter


		printf("-------------------------------------------------------------->Input Any keys to go back<------------------------------------------------------------- \n\n");
		getchar();

		return 0;
	}

	return 0;
}

//ÏÔÊ¾Êý¾Ý
void showData( int temp) {
	sqlite3 *db = 0;	// DB
	int ret1= 0;	// Back Code
	int ret2 =0;
	char *errmsg = 0;
	char **dbResult;	//SQL result
	int rowNum, columnNum, index;

	sqlite3_open("./Adding.db", &db);	//Link DB
	//ASC  ¡ü  DESC¡ý
	/*order by convert(int,sort) ASC    or  order by cast(sort as int) ASC
if--->oracle  db ----> to use order by to_number(sort) ASC; 
*/

	ret1 = sqlite3_get_table(db, "SELECT * FROM `AccountsPass` ORDER BY CAST (`ID` AS BINARY) ASC", &dbResult, &rowNum, &columnNum, &errmsg);
	ret2 =sqlite3_exec (db,"ALTER TABLE `AccountsPass`  MODIFY  `ID`  SMALLINT UNSIGNED AUTO_INCREMENT" , 0, &rowNum, (char **)errmsg);
	if (ret1 == SQLITE_OK) {
		index = columnNum;
		
		if (temp==0){
		for (int i = 0; i < rowNum; i++) {
			printf("%-10s%-30s%-20s%-20s%-20s%-30s**********", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5]);
			index += 7;
			printf("\n");
		}
		}//temp == 0if end
		else if(temp==1){
			for (int i = 0; i < rowNum; i++) {
			printf("%-10s%-30s%-20s%-20s%-20s%-30s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5],dbResult[index + 6]);
			index += 7;
			printf("\n");
		}
		}//if temp==1 end

	}
	sqlite3_free_table(dbResult);
}
