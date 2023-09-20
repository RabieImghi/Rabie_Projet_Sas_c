#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//global variable
static int id=1111;
static int namberTask=0;

//struct
typedef struct {
	int day;
	int month;
	int year;
}Date;
typedef struct {
	int identifier=id;
	char title[20];
	char description[20];
	char Status[20]="realize";
	Date deadline;
}Task;
Task task[200];
void menu2(){
	printf("__________________________________________\n");
	printf("|                                         |\n");
	printf("|  Option 1 : back                        |\n");   
	printf("|_________________________________________|\n");
}
Task newTask(){
	task[namberTask].identifier=id;
	printf("Give me the task information : \n");
	printf("Give me task %d title : ");
	gets(task[namberTask].title);
	printf("Give me task %d description : ");
	gets(task[namberTask].description);
	printf("Give me Deadline of the task %d : \n");
	printf("Day of task %d: ");
	scanf("%d",&task[namberTask].deadline.day);
	printf("Month of task %d: ");
	scanf("%d",&task[namberTask].deadline.month);
	printf("Year of task %d: ");
	scanf("%d",&task[namberTask].deadline.year);
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
	printf("*  TASK %d DEADLINE    : %d/%d/%d\n",i+1,task[i].deadline.day,task[i].deadline.month,task[i].deadline.year);
	printf("******************************************\n");
	}
}
//function
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
		menu();
		printf("option : ");
		gets(option);
		system("CLS");
		optionInt = strtol(option, NULL, 10);
		switch (optionInt){
			case 1 : newTask(); break;
			case 2 : newmultipleTask(); break;
			case 3 : ShowTasks(); break;
			case 4 : newTask(); break;
			case 5 : newTask(); break;
			case 6 : newTask(); break;
			case 7 : newTask(); break;
			case 8 : printf("**************THANKS FOR YOUR TIME *************\n"); break;
		}
	}while(optionInt!=8);
	
	return 0;
}
