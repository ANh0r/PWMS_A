#include<stdio.h>
void MainpageMenu(){
	int i;
	//i,j are for circle menu below;
	char menu[8][50]={"About ME",
	"Brower Information",
	"Add information",
	"Seek Information",
	"Modify Information",
	"Delete Information",
	"Quit"};
	for ( i = 0; i < 7; i++) {

		//ÿһ�е�һ��Ҫ�ӿո��м�
		if (i % 2 == 0) {
			printf("                                              ");
			}
		printf("%d -> %-30s        ", i+1, menu[i]);// -20 means left duiqi
	//����һ�У��ж��Ƿ���
		if ((i + 1) % 2 == 0) {
			printf("\n\n");
		}

}
	//for(j=0;j<7;j++){
	
	printf("\n");	//�����Ž�����������

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


