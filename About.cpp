
#include "ProjectHeader.h"
#define Conls 117
#define Lines 110

//About

void AboutPageUI(void) {
	int i;
	
	system("cls");
	

	//lines above
	printf("\n");
	for ( i = 0; i < Conls; i++) {
		printf("=");
	}

                                                        
printf("\n\n");
printf("\t\t\t.----------------. .----------------. .----------------. .----------------. \n");
printf("\t\t\t| .--------------. | .--------------. | .--------------. | .--------------. |\n");
printf("\t\t\t| |   ______     | | | _____  _____ | | | ____    ____ | | |    _______   | |\n");
printf("\t\t\t| |  |_   __ \\   | | ||_   _||_   _|| | ||_   \\  /   _|| | |   /  ___  |  | |\n");
printf("\t\t\t| |    | |__) |  | | |  | | /\\ | |  | | |  |   \\/   |  | | |  |  (__ \\_|  | |\n");
printf("\t\t\t| |    |  ___/   | | |  | |/  \\| |  | | |  | |\\  /| |  | | |   '.___`-.   | |\n");
printf("\t\t\t| |   _| |_      | | |  |   /\\   |  | | | _| |_\\/_| |_ | | |  |`\\____) |  | |\n");
printf("\t\t\t| |  |_____|     | | |  |__/  \\__|  | | ||_____||_____|| | |  |_______.'  | |\n");
printf("\t\t\t| |              | | |              | | |              | | |              | |\n");
printf("\t\t\t| '--------------' | '--------------' | '--------------' | '--------------' |\n");
printf("\t\t\t '----------------' '----------------' '----------------' '----------------' \n");
	printf("\n\n");
    printf("			Here is a system about the Password Information Managing\n\n\n");
	printf("			And it can realize some basic functions just like saving your Passwords and Editting them. \n\n\n");
	printf("			Because the lack of some specific technique.\n\n\n");
	printf("			Some codes of the system are Asked form John Wu ( The author of SIMS personally)\n\n\n");
	printf("			And for any further Questions Please contact with Magicred Anhor\n\n\n");
	printf("			His number is 819702016（Tencent）\n\n\n ");
	printf("			Wechat is aviliable(vanhor)\n\n\n ");
	printf("			The passwords of this system may not be true\n\n\n");
	printf("			Please do not try these passcodes in reality.\n\n\n ");
	printf("			Thanks!\n\n\n ");
	//printf("				BUT STILL IT EXISTS SO MANY DIFFICULTIES\n\n\n");
		printf("\n");
	printf("\t\t \t\t      ___      .__   __.  __    __    ___   .______   \n");
    printf("  \t\t\t\t    /   \\     |  \\ |  | |  |  |  |  / _ \\  |   _  \\     \n");
   printf("  \t\t\t\t   /  ^  \\    |   \\|  | |  |__|  | | | | | |  |_)  |  \n"); 
  printf("\t\t \t\t  /  /_\\  \\   |  . `  | |   __   | | | | | |      /     \n");
 printf("\t\t\t\t /  _____  \\  |  |\\   | |  |  |  | | |_| | |  |\\  \\----.\n");
printf("\t\t\t\t/__/     \\__\\ |__| \\__| |__|  |__|  \\___/  | _| `._____|\n");
printf("\t\t     --------->If you want to Go Back to the HomePage ,Please Input E or e<---------\n");
	printf("\n\n");

	//lines below
	for ( i = 0 ; i< Conls; i++) {
		printf("=");
	}
	printf("\n");

	
}

int AboutPage() {
	char ch;
	while (1) {

		AboutPageUI();	//draw UI

		 ch = getchar();

		if (ch == 'E' || ch == 'e') {
			return 0;
			break;
		}

		//去除多余字符，直到换行符。等待下一次输入。
		while (ch != '\n') {
			ch = getchar();
		}//while end
	}//while 1 end
}//AboutPage end