#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"sqlite3.h"



//HomePageUI declare
void HomepageUI();
//AboutPage declare
void AboutPageUI();
int AboutPage();
//AddPage
int loadAddInfoPage(void);
void addData(char _data[8][50]);
void printForm(int nowIndex);
int ScriptCheck(char _input[50]);
//BrowsePage
int loadBrowseInfoPage(void);
void showData(int temp);
//DeletePage
void  DelepageUI(void);
void BrowsePage2(void);
//SeekPage
int ShowSeekData(void);
void SeekUI(void);
void SeekInputUI(char _UserIn[100]);
void SeekInputUI2(char _UserIn2[100]);
void BackUI(void);
//Modify
void BrowsePageInModify2(void);
 void BrowsePageInModify(void);//show original Data  ShouData in this; and we have declared it in "ProjectHeader.h"
 void ModifyInputUI(char _Password[],char _data0[],char _data1[],char _data2[],char _data3[],char _data4[],char _data5[]);
 void ModifyPageIn(void);




//QuitPage
void QuitUI(void);

