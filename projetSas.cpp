#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//global variable
static int id=1111;
static int namberTask=0;
int showMenu=1;

typedef struct {
	int day;
	int hour;
	int minut;
}Date;
typedef struct {
	int identifier=id;
	char title[20];
	char description[20];
	char Status[20]="realize";
	Date deadline;
}Task;
Task task[200];
Task newTask(){
	task[namberTask].identifier=id;
	printf("Give me the task information : \n");
	printf("Give me task %d title : ",namberTask+1);
	gets(task[namberTask].title);
	printf("Give me task %d description : ",namberTask+1);
	gets(task[namberTask].description);
	printf("Give me Deadline of the task %d : \n");
	printf("Day of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.day);
	printf("Hour of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.hour);
	printf("Minut of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.minut);
	namberTask++;
	id++;
	
}
void newmultipleTask(){
	int nbTask;
	printf("Give me number of task you want : ");
	scanf("%d",&nbTask);
	char fakeOption[1];
	gets(fakeOption);
	for(int i=0;i<nbTask;i++){
		newTask();
		gets(fakeOption);
	}
}
void ShowTasks(){
	printf("************Task Information *************\n");
	for(int i=0;i<namberTask;i++){
	printf("*  TASK %d IDENTIFIER  : %d\n",i+1,task[i].identifier);
	printf("*  TASK %d Title       : %s\n",i+1,task[i].title);
	printf("*  TASK %d DESCRIPTION : %s\n",i+1,task[i].description);
	printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i+1,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
	printf("******************************************\n");
	}
}
void showTaskTrieAlphabity(){
	for(int i=0;i<namberTask-1;i++)
		for(int j=i+1;j<namberTask;j++){
			if(strcmp(task[i].title,task[j].title)>0){
				Task temp=task[i];
				task[i]=task[j];
				task[j]=temp;
			}
		}
	ShowTasks();
}
void showTaskTrieDeadLine(){
	for(int i=0;i<namberTask-1;i++)
		for(int j=i+1;j<namberTask;j++){
			if(task[i].deadline.day>task[j].deadline.day){
				Task temp=task[i];
				task[i]=task[j];
				task[j]=temp;
			}else if(task[i].deadline.day==task[j].deadline.day){
				if(task[i].deadline.hour>task[j].deadline.hour){
					Task temp=task[i];
					task[i]=task[j];
					task[j]=temp;
				}else if(task[i].deadline.hour==task[j].deadline.hour){
					if(task[i].deadline.minut>task[j].deadline.minut){
						Task temp=task[i];
						task[i]=task[j];
						task[j]=temp;
					}
				}
			}
		}
	ShowTasks();
}
void showTaskTrieDeadLine2(){
	int taskId[200];
	for(int i=0;i<namberTask-1;i++)
		if((task[i].deadline.day<3 )||(task[i].deadline.day==3 && task[i].deadline.hour<1)||(task[i].deadline.day==3 && task[i].deadline.day==0) && task[i].deadline.minut<1 ){
				printf("************Task Information *************\n");
				printf("*  TASK %d IDENTIFIER  : %d\n",i,task[i].identifier);
				printf("*  TASK %d Title       : %s\n",i,task[i].title);
				printf("*  TASK %d DESCRIPTION : %s\n",i,task[i].description);
				printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
				printf("******************************************\n");		
		}
		
}
void menu(){
	
	printf("__________________________________________\n");
	printf("|                                         |\n");
	printf("|  Option 1 : Add a new task              |\n");
	printf("|  Option 2 : Add multiple new tasks      |\n");
	printf("|  Option 3 : View list of all tasks      |\n");
	printf("|  Option 4 : Edit a task                 |\n");
	printf("|  Option 5 : Delete a task by identifier |\n");
	printf("|  Option 6 : Search Tasks                |\n");
	printf("|  Option 7 : Show list Statistics        |\n");
	printf("|  Option 8 : leave                       |\n");   
	printf("|_________________________________________|\n");
}
int main(){
	char option[1];
	int optionInt;
	do{
		if(showMenu==1)
		menu();
		printf("option : ");
		gets(option);
		system("CLS");
		optionInt = strtol(option, NULL, 10);
		switch (optionInt){
//Add a new task  **********************************************************************************
			case 1 : newTask(); break;
//Add multiple new tasks  **************************************************************************
			case 2 : newmultipleTask(); break;
//View list of all tasks****************************************************************************
			case 3 :  	showMenu=0; 
					  	char option[1];
						int optionInt;
						do{
							printf("_________________________________________________________\n");
							printf("|                                                       |\n");
							printf("|  Option 1 : Sort tasks alphabetically                 |\n"); 
							printf("|  Option 2 : Sort tasks by deadline                    |\n"); 
							printf("|  Option 3 : tasks whose deadline is in 3 days or less.|\n");
							printf("|  Option 4 : back                                      |\n");  
							printf("|_______________________________________________________|\n");
							printf("\noption : ");
							gets(option);
							optionInt = strtol(option, NULL, 10);
							system("CLS");
							//View list of all tasks by alphabity***********************************
							if(optionInt==1){
								 showTaskTrieAlphabity();
							}else
							//View list of all tasks by deadline************************************
							if(optionInt==2){
								showTaskTrieDeadLine();
							}else
							//View list of all tasks by deadline 3day left**************************
							if(optionInt==3){
								showTaskTrieDeadLine2();
							}
						}while(optionInt!=4);
						showMenu=1;
					 	break;
					 	
//Edit tasks****************************************************************************
			case 4 : showMenu=0; 
					  	char option[1];
						int optionInt;
						do{
							printf("_________________________________________________________\n");
							printf("|                                                       |\n");
							printf("|  Option 1 : Edit the description of a task            |\n"); 
							printf("|  Option 2 : Change the status of a task               |\n"); 
							printf("|  Option 3 : Change the deadline for a task  			|\n");
							printf("|  Option 4 : back                                      |\n");  
							printf("|_______________________________________________________|\n");
							printf("\noption : ");
							gets(option);
							optionInt = strtol(option, NULL, 10);
							system("CLS");
							//View list of all tasks by alphabity***********************************
							
						}while(optionInt!=4);
						showMenu=1;; break;
			//case 8 : printf("**************THANKS FOR YOUR TIME *************\n"); break;
			default: break;
				}
	}while(optionInt!=8);
	
	return 0;
}

