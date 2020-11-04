#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int sec=0,min=25,auxmin=25;
int minb=4,auxb=4,minlb=30,auxlb=30;
int pom=0,psr=0;
UINT_PTR timer,timRes;

void CALLBACK Reset(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime){
	if(kbhit()){
		psr=getch();
		if(psr=='5'){
			psr=0;
			printf("Press any key to continue:\n\n");
			getch();	
		}
		if(psr=='6'){
			KillTimer(NULL, timer);
		   	psr=0;
		}
		if(psr=='7'){
			sec=0,min=auxmin,minb=auxb,minlb=auxlb,pom=0,psr=0;	
		}	   
	}
}
void CALLBACK Timer(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	//Work Session
	if(min>=0 && pom!=4){
	system("cls");
	printf("Work Session:\n\n");
	printf("%dm:%ds\n\n",min,sec);
	printf("Pause/Play:5\nStop:6\nReset:7\n\n");
	sec--;
	if(sec<0){
		sec=59;
		min--;}	
	if(min==0 && sec==0){
	pom++;
	Beep(0, 1000);
	Beep(800, 100);
	Beep(600, 100);
	Beep(400, 100);
	}}	
	
	//Break Session
	if(min<0 && pom!=4){
	system("cls");
	printf("Break Session:\n\n");
	printf("%dm:%ds\n\n",minb,sec);
	printf("Pause/Play:5\nStop:6\nReset:7\n\n");
	sec--;
	if(sec<0){
		sec=59;
		minb--;}
	if(minb==0 && sec==0){	
	Beep(0, 1000);
	Beep(400, 100);
	Beep(600, 100);
	Beep(800, 100);
	min=auxmin;
	minb=auxb;
	}}
	
	//Long Break Session
	if(pom==4){
	system("cls");
	printf("Long Break Session:\n\n");
	printf("%dm:%ds\n\n",minlb,sec);
	printf("Pause/Play:5\nStop:6\nReset:7\n\n");
	sec--;
	if(sec<0){
		sec=59;
		minlb--;}
	if(minlb==0 && sec==0){
	Beep(0, 1000);
	Beep(400, 100);
	Beep(600, 100);
	Beep(800, 100);
	min=auxmin;
	minb=auxb;
	pom=0;
	}}
		
}	
int main(){
	int change;
	int ready=0;
	MSG msg;
    SetConsoleTitle("The Pomodoro Technique");

    do{
	printf("Change time:\n\n");
	printf("Work Session: Press 1\n");
	printf("Break Session: Press 2\n");
	printf("Long Break Session: Press 3\n");
    printf("Use default: Press 0\n\n");
    scanf("%d",&change);
		
    //Change Work Session Time
    if(change==1){
    	printf("\nEnter the desired time:\n\n");
		scanf("%d",&min);
		auxmin=min;
	}
    //Change Break Session Time
    if(change==2){
    	printf("\nEnter the desired time:\n\n");
    	scanf("%d",&minb);
    	minb--;
    	auxb=minb;
	}
    //Change Long Break Session Time
    if(change==3){
    	int lb;
    	printf("\nChoose the desired time:\n1:30 minutes\n2:10 minutes\n\n");
    	scanf("%d",&lb);
    	if(lb==1)
    		minlb=30,auxlb=30;
    	else if(lb==2)
    		minlb=10,auxlb=10;
	}
    //Default
    if(change==0)
    	min=25,auxmin=25,minb=4,auxb=4,minlb=30,auxlb=30;
    printf("\nPress 4 if all settings are made or 1 to continue configuring\n\n");
    scanf("%d",&ready);
    system("cls");
	}while(ready!=4);
	
	timer = SetTimer(NULL, 0, 1000,(TIMERPROC) &Timer);
	timRes = SetTimer(NULL, 0, 10,(TIMERPROC) &Reset);	
	while(GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);}
    
    
    
	return 0;
}

