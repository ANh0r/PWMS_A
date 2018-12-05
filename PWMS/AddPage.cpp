/*
Most codes of the page are Used from JohnWu(wuhan005)
And We need to Thank him for his unselfish!
To make run progress conveniently,and for JohnWu can easily maintain this Page
I do not change the varible name!
*/



#include <windows.h>
#include <stdio.h>
#include "sqlite3.h"
#define Conls 110
#define Lines 35
int ScriptCheck(char _input[50]);

//添加学生信息

char inputData[6][50];	//输入的 字段
int nowInputIndex = 0;
char tips[50] = { "" };		//反馈提示

void printForm(int nowIndex);

//添加数据到数据库
void addData(char _data[6][50]) {
	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;

	char query[2000] = { "" };
	sprintf(query, "INSERT INTO `AccountsPass` ( 'The Website', 'Login name', 'The third acconuts', 'Phone number', 'E-mail address', 'Password') VALUES ( '%s', '%s', '%s', '%s', '%s', '%s')", _data[0], _data[1], _data[2], _data[3], _data[4], _data[5]);

	ret = sqlite3_open("./Adding.db", &db);	//连接数据库
	ret = sqlite3_exec(db, query, NULL, NULL, &errmsg);	//执行SQL
	sqlite3_free(errmsg);
	sqlite3_close(db);		//断开连接
}

int loadAddInfoPage(void) {

	//每次进入时都清空上次的数据
	for (int i = 0; i < 6; i++) {
		strcpy(inputData[i], "");
	}
	nowInputIndex = 0;


	while (1) {
		system("cls");

		//上方的线
		for (int i = 0; i < Conls; i++) {
			printf("=");
		}

		printf("\n\n                                           >  Adding the statistics below\n\n");
		printf("\n\n       The 3rd accounts means that the number of QQ or Wechat or anythings else.（With QQ or Wechat like this) \n\n" );

		for (int i = 0; i < Conls; i++) {
			printf("=");
		}

		printf("\n\n");

		printForm(nowInputIndex);

		printf("\n\n");

		//操作指令
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

		char userInput[50];		//用户输入的值
		scanf("%s", userInput);

		int scriptFlag = ScriptCheck(userInput);

		if (scriptFlag == 0) {		//用户输入是数据
			strcpy(inputData[nowInputIndex], userInput);		//修改字段

			if (nowInputIndex == 7) {
				//nowInputIndex = 0;		//实际使用感觉不需要这个
			}
			else {
				nowInputIndex++;
			}

		}
		else if (scriptFlag == 1) {

		}
		else if (scriptFlag == -1) {		//退出的指令
			return 0;
		}

	}
}

//打印输入的表单
void printForm(int nowIndex) {

	char inputField[6][50] = { "The Website", "Login name", "The third acconuts", "Phone number", "E-mail address", "Password" };	//字段提示

	for (int i = 0; i < 6; i++) {
		if (nowIndex == i) {
			printf("              > ");
		}
		else {
			printf("                ");
		}

		printf("%s： %s\n\n", inputField[i], inputData[i]);
	}
}

//检测用户输入的是否是指令
int ScriptCheck(char _input[50]) {
	strcpy(tips, "");	//清除上一次的提示

	char instruction[5][10] = {
		"/exit",
		"/save",
		"/up",
		"/down",
	};

	int insCode = -1;

	if (_input[0] != '/') {		//判断用户输入的是否是指令
		return 0;
	}

	for (int i = 0; i < 5; i++) {		//遍历检测用户输入的指令
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

								//清空上次的数据
		for (int i = 0; i < 6; i++) {
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