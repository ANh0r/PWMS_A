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

		//每一行第一个要加空格到中间
		if (i % 2 == 0) {
			printf("                                              ");
			}
		printf("%d -> %-30s        ", i+1, menu[i]);// -20 means left duiqi
	//两个一行，判断是否换行
		if ((i + 1) % 2 == 0) {
			printf("\n\n");
		}

}
	//for(j=0;j<7;j++){
	
	printf("\n");	//不打扰接下来的内容

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


