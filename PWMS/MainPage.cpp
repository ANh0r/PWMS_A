#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"ProjectHeader.h"

int main(){

	int ChoosingNumber = 0;
	system("mode con cols=150 lines=50");   //Settings of the cols and line
	system("color 07");     //03 mean UI all about blue
	
	while (1) {
		system("cls");

		HomepageUI();//HomepageUI.c 
		ChoosingNumber = getchar();

		if (isdigit(ChoosingNumber)) {

			

			//ChoosingNumber which means the ASCII
			//She Need Some Settings
			//Like -48(To become the number 1 2 3...)
			switch (ChoosingNumber - 48) {

			case 1:
				AboutPage();
				break;
			case 2:
				loadBrowseInfoPage();
				break;
			case 3:
				loadAddInfoPage();
				break;
			case 4:
				ShowSeekData();
				//getchar();
				break;
			case 5:
				ModifyPageIn();
				break;
			case 6:
				DelepageUI();
				break;
			case 7:
				QuitUI();
				break;

			default:
				printf("Your inputs WRONG!(ANY KEYS TO GO BACK) ");
				getchar();
				getchar();
				break;



			}//switch end

		}//if end

	}//while end


	//system("pause");
	return 0;






}