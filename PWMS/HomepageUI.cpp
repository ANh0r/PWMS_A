#include<stdio.h>
#include<windows.h>
#include<string.h>
int PasscodeFunc(void);
void MainpageMenu(){
	system("title Welcome to PWMS");
	int i;
	//i,j are for circle menu below;
	char menu[8][50]={"About ME",
	"Browse Information",
	"Add information",
	"Seek Information",
	"Modify Information",
	"Delete Information",
	"Quit"};
	for ( i = 0; i < 7; i++) {

		//IN EVERY LINE we add a space ahead of the line 
		if (i % 2 == 0) {
			printf("                                              ");
			}
		printf("%d -> %-30s        ", i+1, menu[i]);// -20 means left duiqi
	//OUTPUT Enter every 2 line 
		if ((i + 1) % 2 == 0) {
			printf("\n\n");
		}

}
	//for(j=0;j<7;j++){
	
	printf("\n");	//Do not disturb the text next

}


void HomepageUI() 
{ 
printf("\n");
printf("------------------------------------------------------------------->Welcome to PWMS<------------------------------------------------------------------\n");
printf("----------------------------------------------------------->Password Information Manage System<-------------------------------------------------------\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\t\t					        `;-.          ___,\n");
printf("\t\t						  `.`\\_...._/`.-\\\"`\n");
printf("\t\t						    \\          /      ,\n");
printf("\t\t						     /()   () \\    .' `-._\n");
printf("\t\t						   |)  .    ()\\  /   _.'\n");
printf("\t\t						   \\  -'-     ,; '. <\n");
printf("\t\t						    ;.__     ,;|   > \n");
printf("\t\t						    / ,    / ,  |.-'.-'\n");
printf("\t\t						   (_/    (_/ ,;|.<`\n");
printf("\t\t						     \\    ,     ;-`\n");
printf("\t\t						     >   \\    /\n");
printf("\t\t						      (_,-'`> .'\n");
printf("\t\t							    (_,' \n");
printf("\n\n\n");
printf("\t\t					__________  __      __  _____    _________\n");
printf("\t\t					\\______   \\/  \\    /  \\/     \\  /   _____/\n");
printf("\t\t					|     ___/\\   \\/\\/   /  \\ /  \\ \\_____  \\\n ");
printf("\t\t					|    |     \\        /         \\/        \\\n");
 printf("\t\t					|____|      \\__/\\  /\\____|__  /_______  /\n");
  printf("\t\t							 \\/         \\/        \\/\n ");
  printf("\n\n\n");

	MainpageMenu();

	printf("\n\n");

	printf("======================================================= Copyright (c) 2018 Anh0r / C PWMS Project.====================================================\n");
	//printf("==========================================================================================================================\n");
	printf("--------------------------------------------------------->Please input the number you choose below<---------------------------------------------------\n");
}
int  PasscodeFunc(void){
	char Passcode[20];
	char PasscodeOri[20]="iloveyou";
	char ExitToHm[20]="exit";
	while(1){
	system("cls");

	printf("\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n");

	
	printf("\t\t\t----------------->This function needs Passcode,Please input the Passcode below\n\t\t\t\t\t\t\tAnd the Passcode comes from your Supporter<--------------------------\n ");
    scanf("%s",Passcode);


	if(strcmp(PasscodeOri,Passcode)==0){
		
			printf("\t\t\t-----------------> Passcode is right,Thank you for using the PWMS<-------------------------- ");
			return 1;		//Right!
			break;
			
			}//if end
	else if (_stricmp(ExitToHm,Passcode)==0){
			return 0;			//Exit
		;//HomepageUI();;
	}else {
		while (1){

			printf("\t\t\t\t\t-----------------> Passcode is wrong,Please try again<--------------------------\n ");
				scanf("%s",Passcode);


					if(strcmp(PasscodeOri,Passcode)==0){
		
						printf("\t\t\t-----------------> Passcode is right,Thank you for using the PWMS<-------------------------- ");
						return 1;	
						break;
					}else if (_stricmp(ExitToHm,Passcode)==0){
						return 0;	
					}
		}//while in else end
		break;
					

			

	getchar();

	}// else end
	}//while end



}//PasscodeFunc end


