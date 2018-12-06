/*
Draw UI first and display the main Statistics
Then show user tips which are to ask: The line and the specific statistics that he want to modify
User input 
---->query strcat
---->Run SQL
---->Display again and go back to the 1St or Exit;


///_Password ------> ID!!!





*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjectHeader.h"
#include "sqlite3.h"
#define Conls 150
 void BrowsePageInModify(void);//show original Data  ShouData in this; and we have declared it in "ProjectHeader.h"
 void ModifyInputUI(char _Password[],char _data0[],char _data1[],char _data2[],char _data3[],char _data4[],char _data5[]);
 void ModifyPageIn(void);
 void BrowsePageInModify2(void);

 void BrowsePageInModify(void){
	 for (int i = 0; i < Conls; i++) {
		printf("=");
		}//for end
		system("cls");	
		BackUI();

		//上方的线
	for (int i = 0; i < Conls; i++) {
		printf("=");
		}//for end
	
		printf("\n\n\t\t                         -------->   Here is the Original Information of the system\n\n");
		printf("\n\n\t\t                         -------->   To Update some lines,please input the ID on the end of the page\n\n"); 
		

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

		showData(1);		//

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end
	//}//while end
		

 }//BrowsePageInModify end

  void BrowsePageInModify2(void){
	  system("cls");		
		for (int i = 0; i < Conls; i++) {
			printf("=");
			}//for end

				//上方的线
				BackUI();
		for (int i = 0; i < Conls; i++) {
				printf("=");
				}//for end
				printf("\n\n\t\t                                         -------->   After Modifying Data  <--------\n\n");
						//Here, we make the easilest version that we pretend the password of every user is different and It can also as the end of the SQL query;
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

		showData(1);		//

		printf("\n");

		for (int i = 0; i < Conls; i++) {
			printf("-");
		}//for end
	//}//while end
		

 }//BrowsePageInModify end

 void ModifyInputUI(char _Password[],char _data0[],char _data1[],char _data2[],char _data3[],char _data4[],char _data5[]){
	 /*The codes below are used as the part Password as the result!*/
	
	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;
	//char **dbResult;	//返回的查询数据
	int rowNum;//, columnNum, index;

	sqlite3_open("./Adding.db", &db);	//连接数据库
	
	

	char QueryUser[1000]="UPDATE `AccountsPass` SET `The Website`='";
		strcat(QueryUser, _data0);
	    strcat(QueryUser, "'");
		strcat(QueryUser, ",`Login name`='"); 
		strcat(QueryUser, _data1);
		strcat(QueryUser, "'");
		strcat(QueryUser, " ,`The third acconuts`='");
		strcat(QueryUser, _data2);
		strcat(QueryUser, "'");
		strcat(QueryUser, " ,`Phone number`='");
		strcat(QueryUser, _data3);
		strcat(QueryUser, "'");
		strcat(QueryUser, " ,`E-mail address`='");
		strcat(QueryUser, _data4);
		strcat(QueryUser, "'");
		strcat(QueryUser, " ,`Password`='");
		strcat(QueryUser, _data5);
		strcat(QueryUser, "'");
		strcat(QueryUser, " WHERE `ID`='");
		strcat(QueryUser,  _Password);
		strcat(QueryUser, "'");
		//printf("%s",QueryUser);



	ret = sqlite3_exec(db, QueryUser, 0, &rowNum, (char**)&errmsg);
	/*if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("%-20s%-20s%-20s%-20s%-20s%-20s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5]);
			index += 6;
			printf("\n");
		}
	}*/
	//sqlite3_free_table(dbResult);
 }//ModifyINputUI end

 void ModifyPageIn(void){
	 system("title Modify information");
	 while (1){

				char _Password[100];
				char _data0[150] ;char _data1[150];char _data2[150];char _data3[150];char _data4[150];char _data5[150];
				//char TheChoiceOfE;
				char UserChoice;
				
				BrowsePageInModify();
				printf("\t\t    -------------------------------------->Please input the the ID of the Updated line<-------------------------------\n");
				scanf("%s",_Password);
				printf("\t -------------------------------------->Please input the the information of for the line<--------------------------------\n\n");
				printf("\t ----------------------------------->The first Text is The Website, ID will not be Changed<------------------------------\n\n");
				printf("\t ---------------------------------->Using Space to make every Text apart and Enter to Finish<----------------------------\n\n");
				scanf("%s",_data0);
				scanf("%s",_data1);
				scanf("%s",_data2);
				scanf("%s",_data3);
				scanf("%s",_data4);
				scanf("%s",_data5);
				
				system("cls");
				BackUI();
				ModifyInputUI( _Password , _data0 , _data1, _data2,_data3, _data4, _data5);
				//system("cls");
				
				
		   		BrowsePageInModify2();

				for(int i=0;i<Conls;i++){
					printf("=");
				}
				printf("Please Choosing Keeping Modifying (ANY KEYS) or Exit(E)\n");
				getchar();
				scanf("%c",&UserChoice);
				if (UserChoice=='E'||UserChoice=='e'){
						 break;
				}//if end
	 }//while end



 }//ModifyPageUI end
