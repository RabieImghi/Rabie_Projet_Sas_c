#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
static int id=100;//global variable for identifiant task
static int namberTask=0; //global variable for count task


//struct for Deadline
typedef struct {
	int day;
	int hour;
	int minut;
}Date;

//struct for tasks
typedef struct {
	int identifier;
	char title[20];
	char description[20];
	char Status[20]="realize";
	Date deadline;
}Task;
Task task[200];//global variable for table tasks

//Function Add New Task
Task newTask(){
	task[namberTask].identifier=id;
	printf("Give me the task information : \n");
	printf("Give me task %d title : ",namberTask+1);
	gets(task[namberTask].title);
	printf("Give me task %d description : ",namberTask+1);
	gets(task[namberTask].description);
	printf("Give me Deadline of the task %d : \n",namberTask+1);
	printf("Day of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.day);
	printf("Hour of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.hour);
	printf("Minut of task %d: ",namberTask+1);
	scanf("%d",&task[namberTask].deadline.minut);
	namberTask++;
	id++;	
}

//Function Add Multipl New Task
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

//Function display all task
void ShowTasks(){
	if(namberTask!=0){
		printf("************Task Information *************\n");
		for(int i=0;i<namberTask;i++){
			printf("*  TASK %d IDENTIFIER  : %d\n",i+1,task[i].identifier);
			printf("*  TASK %d TITEL       : %s\n",i+1,task[i].title);
			printf("*  TASK %d DESCRIPTION : %s\n",i+1,task[i].description);
			printf("*  TASK %d STATUS : %s\n",i+1,task[i].Status);
			printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i+1,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
			printf("******************************************\n");
		}
	}else if(namberTask==0) printf("****************NOTHING TO DISPLAY IT KNOW **********\n");
}

//Function display all task Trie By Alphabity
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

//Function display all task Trie By DeadLine
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

//Function display all task He Have DeadLine less than 3 Day
void showTaskTrieDeadLine2(){
	int taskId[200];
	for(int i=0;i<namberTask-1;i++)
		if((task[i].deadline.day<3 )||(task[i].deadline.day==3 && task[i].deadline.hour<1)||(task[i].deadline.day==3 && task[i].deadline.day==0) && task[i].deadline.minut<1 ){
			printf("************Task Information *************\n");
			printf("*  TASK %d IDENTIFIER  : %d\n",i,task[i].identifier);
			printf("*  TASK %d Title       : %s\n",i,task[i].title);
			printf("*  TASK %d DESCRIPTION : %s\n",i,task[i].description);
			printf("*  TASK %d STATUS : %s\n",i+1,task[i].Status);
			printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
			printf("******************************************\n");		
		}
}

//Function Edit Task Desciption 
void editTaskDescription(){
	char desciption[20],fake[1];
	int tasknumEdit;
	ShowTasks();							
	printf("select a task by identifier : ");							
	scanf("%d",&tasknumEdit);							
	gets(fake);							
	for(int i=0;i<namberTask;i++){							
		if(task[i].identifier==tasknumEdit){								
			printf("Give me new description");								
			gets(desciption);								
			strcpy(task[i].description, desciption);
		}														
	}												
}

//Function Edit Task Status  
void editTaskStatus(){
	char Status[20],fake[1];
	int tasknumEdit;
	ShowTasks();							
	printf("select a task by identifier : ");							
	scanf("%d",&tasknumEdit);							
	gets(fake);							
	for(int i=0;i<namberTask;i++){							
		if(task[i].identifier==tasknumEdit){								
			printf("Give me new Status (0 for 'a realize' // 1 for 'in progress' // 2 for 'finalized') ");								
			gets(Status);
			if(strtol(Status,NULL,10)==0)
				strcpy(task[i].Status, "realize");
			else if(strtol(Status,NULL,10)==1)
				strcpy(task[i].Status, "in progress");
			else if(strtol(Status,NULL,10)==2)							
				strcpy(task[i].Status, "finalized");
			else printf("INCORRECT SELECTION");
		}														
	}												
}

//Function Edit Task DeadLine  
void editTaskDeadLine(){
	char Status[20],fake[1];
	int tasknumEdit;
	ShowTasks();							
	printf("select a task by identifier : ");							
	scanf("%d",&tasknumEdit);							
	gets(fake);							
	for(int i=0;i<namberTask;i++){							
		if(task[i].identifier==tasknumEdit){								
			printf("Give me new DeadLine : \n");								
				printf("Day of task : ");
				scanf("%d",&task[i].deadline.day);
				printf("Hour of task : ");
				scanf("%d",&task[i].deadline.hour);
				printf("Minut of task : ");
				scanf("%d",&task[i].deadline.minut);
		}														
	}
}

//Function Delit Task By Identifiant
void delitTask(){
	char fake[1];
	int tasknumEdit;
	ShowTasks();							
	printf("select a task by identifier : ");							
	scanf("%d",&tasknumEdit);							
	gets(fake);							
	for(int i=0;i<namberTask;i++)							
		if(task[i].identifier==tasknumEdit){
			for(int j=i;j<namberTask-1;j++){
				task[j]=task[j+1];
			}
			namberTask--;
			break;
		}
}

//Function Search Task By Identifiant 
void SearchTaskByIdentifiant(){
	char fake[1];
	int tasknumEdit;							
	printf("search a task by identifier : ");							
	scanf("%d",&tasknumEdit);							
	gets(fake);							
	for(int i=0;i<namberTask;i++)							
		if(task[i].identifier==tasknumEdit){
			printf("************Task Information *************\n");
			printf("*  TASK %d IDENTIFIER  : %d\n",i+1,task[i].identifier);
			printf("*  TASK %d Title       : %s\n",i+1,task[i].title);
			printf("*  TASK %d DESCRIPTION : %s\n",i+1,task[i].description);
			printf("*  TASK %d STATUS : %s\n",i+1,task[i].Status);
			printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i+1,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
			printf("******************************************\n");	
			break;
		}
}

//Function Search Task By Title
void SearchTaskByTitle(){
	char tasknumEdit[20];							
	printf("search a task by Title : ");								
	gets(tasknumEdit);							
	for(int i=0;i<namberTask;i++)							
		if(strcmp(task[i].title,tasknumEdit)==0){
			printf("************Task Information *************\n");
			printf("*  TASK %d IDENTIFIER  : %d\n",i+1,task[i].identifier);
			printf("*  TASK %d Title       : %s\n",i+1,task[i].title);
			printf("*  TASK %d DESCRIPTION : %s\n",i+1,task[i].description);
			printf("*  TASK %d STATUS : %s\n",i+1,task[i].Status);
			printf("*  TASK %d DEADLINE    : %d DAY %d HOUR %d MINUT\n",i+1,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
			printf("******************************************\n");	
			break;
		}
}

//Function For Display finalized Tasks
void showCompletTask(){
	printf("************Complete Task Information *************\n");
	int compt=0;
	for(int i=0;i<namberTask;i++)
		if(strcmp(task[i].Status,"finalized")==0) compt++;
			printf("__________________________________________________\n");
			printf("|| the total number of tasks complete is : %d     ||\n",compt);
			printf("||_______________________________________________||\n");
}

//Function For Display progress/realize Tasks
void showInCompletTask(){
	int compt=0;
	printf("************Incomplete Task Information *************\n");
	for(int i=0;i<namberTask;i++)
		if(strcmp(task[i].Status,"finalized")==1) compt++;
			printf("__________________________________________________\n");
			printf("|| the total number of tasks incomplete is : %d   ||\n",compt);
			printf("||_______________________________________________||\n");
}

//Function For Display Number Of Day Remaining Of Task
void NumberOfDaysRemaining(){
	for(int i=0;i<namberTask;i++)
		if(strcmp(task[i].Status,"finalized")!=0){
		printf("*  TASK %d IDENTIFIER                 : %d\n",i+1,task[i].identifier);
		printf("*  TASK %d Title                      : %s\n",i+1,task[i].title);
		printf("*  TASK %d Number of days remaining   : %d Day %d Hour %d Minut\n",i+1,task[i].deadline.day,task[i].deadline.hour,task[i].deadline.minut);
		printf("******************************************\n");
	}
}

//Function For Display Menu Principal
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
	// Option For Test User Selection
	char option[1];
	int optionInt;
	do{
		menu();// Test Dislpay Menu
		printf("\n********Select An Option From Menu*********\n");
		printf("\n______________: ");
		gets(option);
		system("CLS"); // clear screen
		optionInt =atoi(option);//convert a number type char to type int
		//Switch For Management User Selection  
		switch (optionInt){
			case 1 : newTask(); break; 
			case 2 : newmultipleTask(); break;
			case 3 : char option[1];
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
						optionInt = atoi(option);
						system("CLS");
						//View list of all tasks by alphabity***********************************
						if(optionInt==1) showTaskTrieAlphabity();
						//View list of all tasks by deadline************************************
						if(optionInt==2) showTaskTrieDeadLine();
						//View list of all tasks by deadline 3day left**************************
						if(optionInt==3) showTaskTrieDeadLine2();
					 }while(optionInt!=4);
				     break;
			case 4 : do{
						printf("_________________________________________________________\n");
						printf("|                                                       |\n");
						printf("|  Option 1 : Edit the description of a task            |\n"); 
						printf("|  Option 2 : Change the status of a task               |\n"); 
						printf("|  Option 3 : Change the deadline for a task            |\n");
						printf("|  Option 4 : Show all task                             |\n");
						printf("|  Option 5 : back                                      |\n");  
						printf("|_______________________________________________________|\n");
						printf("\noption : ");
						gets(option);
						optionInt = atoi(option);
						system("CLS");
						//Edit the description of a task***********************************
						if(optionInt==1) editTaskDescription();
						//Edit the Status of a task****************************************
						if(optionInt==2) editTaskStatus();
						//Edit the DeadLine of a task**************************************
						if(optionInt==3) editTaskDeadLine();
						//Display All task*************************************************
						if(optionInt==4) ShowTasks();
					 }while(optionInt!=5); 
					 break;
			case 5 : delitTask(); break; // Delit A Task By Identifiant
			case 6 : do{
				 		printf("_________________________________________________________\n");
						printf("|                                                       |\n");
						printf("|  Option 1 : Search Tasks by identifie                 |\n"); 
						printf("|  Option 2 : Search Tasks by title                     |\n"); 
				  		printf("|  Option 3 : back                                      |\n");  
						printf("|_______________________________________________________|\n");
						printf("\noption : ");
						gets(option);
						optionInt = atoi(option);
						system("CLS");
						//Search A Task Using Identfiant***********************************
						if(optionInt==1) SearchTaskByIdentifiant();
						//Search A Task Using deadline*************************************
						if(optionInt==2) SearchTaskByTitle();
				    }while(optionInt!=3);
					break;
			case 7 : do{
						printf("____________________________________________________________________\n");
						printf("|                                                                  |\n");
						printf("|  Option 1 : Show the total number of tasks                       |\n"); 
						printf("|  Option 2 : Show the number of complete tasks                    |\n"); 
						printf("|  Option 3 : Show the number of incomplete tasks                  |\n");
						printf("|  Option 4 : Number of days remaining until each task's deadline  |\n");
						printf("|  Option 5 : back                                                 |\n");  
						printf("|__________________________________________________________________|\n");
						printf("\noption : ");
						gets(option);
						optionInt = atoi(option);
						system("CLS");
						//Display Number Of Task***********************************
						if(optionInt==1){
					 		printf("________________________________________________\n");
							printf("|| the total number of tasks is : %d           ||\n",namberTask);
							printf("||____________________________________________||\n");
					 	}
					 	//Display All Task Complete***********************************
						if(optionInt==2) showCompletTask();
						//Display All Task Incomplete*********************************
						if(optionInt==3) showInCompletTask();
						//Display Number Of Day Remaining*****************************
						if(optionInt==4) NumberOfDaysRemaining();
					}while(optionInt!=5) ; 
					system("CLS"); 
					break;
			case 8 : printf("**************THANKS FOR YOUR TIME *************\n"); break;
			default: break;
				}
	}while(optionInt!=8);
	return 0;
}

