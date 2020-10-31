#include <iostream>
#include <stdio.h>
#include <windows.h>

char sec=0,min=0,hr=0;
char minb=0,minlb=0;
UINT_PTR timer;

void CALLBACK Timer(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	system("cls");
	printf("%dm:%ds\n\n",min,sec);
	sec--;
	if(sec<0){
		sec=59;
		min--;
	}
	if(min<0)
		Beep(590, 500);
	//tempo++;
	//printf("%d\n", tempo);
	//Beep(590, 500);
	//KillTimer(NULL, timer);
}	
int main(){
	char change;
	char ready=0;
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
	}
    //Change Break Session Time
    if(change==2){
    	printf("\nEnter the desired time:\n\n");
    	scanf("%d",&minb);
	}
    //Change Long Break Session Time
    if(change==3){
    	char lb;
    	printf("\nChoose the desired time:\n1:30 minutes\n2:10 minutes\n");
    	scanf("%d",&lb);
    	if(lb==1)
    		minlb=10;
    	else
    		minlb=30;
	}
    //Default
    if(change==0)
    	min=25,minb=5,minlb=30;
    printf("\nPress 4 if all settings are made or 1 to continue configuring\n\n");
    scanf("%d",&ready);
    system("cls");
	}while(ready!=4);
	
	timer = SetTimer(NULL, 0, 1000,(TIMERPROC) &Timer);
	while(GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
	return 0;
}

