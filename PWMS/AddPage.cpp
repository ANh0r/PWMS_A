/*
Most codes of the page are Used from JohnWu(wuhan005)
And We need to Thank him for his unselfish!
To make run progress conveniently,and for JohnWu can easily maintain this Page
I do not change the varible name!
*/



#include <windows.h>
#include <stdio.h>
#include "sqlite3.h"
#define Conls 150
#define Lines 35
int ScriptCheck(char _input[50]);

//Add the Website information ------> SQL db needed;

char inputData[7][50];	//including ID and other Text
int nowInputIndex = 0;
char tips[50] = { "" };		//feedback

void printForm(int nowIndex);

//adding data to SQL db
void addData(char _data[7][50]) {
	sqlite3 *db = 0;	//connect to db
	int ret = 0;	//result
	char *errmsg = 0;

	char query[2000] = { "" };
	sprintf(query, "INSERT INTO `AccountsPass` ( 'ID', 'The Website', 'Login name', 'The third acconuts', 'Phone number', 'E-mail address', 'Password') VALUES ( '%s','%s', '%s', '%s', '%s', '%s', '%s')", _data[0], _data[1], _data[2], _data[3], _data[4], _data[5],_data[6]);

	ret = sqlite3_open("./Adding.db", &db);	//linked db
	ret = sqlite3_exec(db, query, NULL, NULL, &errmsg);	//run SQL
	sqlite3_free(errmsg);
	sqlite3_close(db);		//disconnect
}

int loadAddInfoPage(void) {
	system("title Add information");

	//clear the former data while inputing the next line data
	for (int i = 0; i < 7; i++) {
		strcpy(inputData[i], "");
	}
	nowInputIndex = 0;


	while (1) {
		system("cls");

		//line above
		for (int i = 0; i < Conls; i++) {
			printf("=");
		}

		printf("\n\n\t\t                                           >  Adding the statistics below\n\n");
		printf("\n\n\t\t       The 3rd accounts means that the number of QQ or Wechat or anythings else.（With QQ or Wechat like this) \n\n" );

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}

		printf("\n\n");

		printForm(nowInputIndex);

		printf("\n\n");

		//the 4 order  beneath 
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}
		printf("\n\n             /save           /up           /down           /exit \n\n");
		for (int i = 0; i < Conls; i++) {
			printf("-");
		}

		printf("\n\n   %s", tips);		//提示

		printf("\n\n");


		// =============== UI ================= //

		char userInput[50];		//the text user input
		//and we differentiate the text is order or data we introduce "/" to judge it.
		scanf("%s", userInput);

		int scriptFlag = ScriptCheck(userInput);

		if (scriptFlag == 0) {		//isData
			strcpy(inputData[nowInputIndex], userInput);		//modify the ID / Website / ......

			if (nowInputIndex == 7) {
				//nowInputIndex = 0;		// Idk why john wu give this line up....
				//actually i have no idea that what this part written like this.
			}
			else {
				nowInputIndex++;
			}

		}
		else if (scriptFlag == 1) {

		}
		else if (scriptFlag == -1) {		//quit
			return 0;
		}

	}
}

//the print form on the screen
void printForm(int nowIndex) {

	char inputField[][50] = { "ID","The Website", "Login name", "The third acconuts", "Phone number", "E-mail address", "Password" };	//字段提示

	for (int i = 0; i < 7; i++) {
		if (nowIndex == i) {
			printf("              > ");
		}
		else {
			printf("                ");
		}

		printf("%s： %s\n\n", inputField[i], inputData[i]);
	}
}

//if order or data
int ScriptCheck(char _input[50]) {
	strcpy(tips, "");	//clear tips former

	char instruction[5][10] = {
		"/exit",
		"/save",
		"/up",
		"/down",
	};

	int insCode = -1;

	if (_input[0] != '/') {		//is order
		return 0;
	}

	for (int i = 0; i < 5; i++) {		//read wholy
		if (!strcmp(_input, instruction[i])) {
			insCode = i;
			break;
		}
	}

	if (insCode == -1) {
		strcpy(tips, "Wrong Input!");
		return 1;
	}

	switch (insCode) {
	case 0:
		return -1;		//EXIT
		break;
	case 1:
		addData(inputData);		//SAVE

								//clear the data fomer inputted
		for (int i = 0; i < 7; i++) {
			strcpy(inputData[i], "");
		}
		nowInputIndex = 0;

		break;
	case 2:	//UP
		if (nowInputIndex != 0) {
			nowInputIndex--;
		}
		else {
			nowInputIndex = 5;
		}
		break;
	case 3:		//DOWN
		if (nowInputIndex != 5) {
			nowInputIndex++;
		}
		else {
			nowInputIndex = 0;
		}
		break;
	}
	return 1;
}