#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/patient.h"
#include "../includes/PriorityQueue.h"


int main(int argc, char ** argv)
{   
	FILE * fp = NULL;
	char test;
	int priority;
	int curTime = 1;
	char choice;
	Queue* patients = createQueue(printPatient, deletePatient, comparePatient);
	Queue* donePatients = createQueue(printPatient, deletePatient, comparePatient);
	
	//Open the file
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("Error opening file\n");
		return-1;
	}
	//Parse the input and insert it in both queues
	while(true)
	{
		char* add = malloc(sizeof(char)*50);
		char* ID = malloc(sizeof(char)*50);
		char* code = malloc(sizeof(char)*50);
		
		//Check if your at end of the file
		if((test = fgetc(fp)) == EOF) break;
		add[0] = test;
		add[1] = '\0';
		fscanf(fp, "%s", ID);
		strcat(add, ID);
		fscanf(fp, "%d", &priority);
		fscanf(fp, "%s", code);
		char* secondID = malloc(sizeof(char)*50);
		char* secondCode = malloc(sizeof(char)*50);
		strcpy(secondID, add);
		strcpy(secondCode, code);
		pInsert(patients, createPatient(add, priority, code, 0), priority);
		insert(donePatients, createPatient(secondID, priority, secondCode, 0), priority);
		free(ID);
		//Move to the next line
		while(getc(fp) != '\n')
		{
			
		}
		
	}
	while(true)
	{
		printf("Please select on of the following options: \n");
		printf("1. Add a new patient\n2. Run the simulation\n3. Exit the program\n");
		choice = getc(stdin);
		if(choice == '1')
		{
			char* ID = malloc(sizeof(char)*50);
			char* code = malloc(sizeof(char)*50);
			printf("Please enter the following information: \n");
			printf("Patient ID: ");
			scanf("%s", ID);
			printf("Patient priority: ");
			scanf("%d", &priority);
			printf("Patient symptom code: ");
			scanf("%s", code);
			char* secondID = malloc(sizeof(char)*50);
			char* secondCode = malloc(sizeof(char)*50);
			strcpy(secondID, ID);
			strcpy(secondCode, code);
			pInsert(patients, createPatient(ID, priority, code, 0), priority);
			insert(donePatients, createPatient(secondID, priority, secondCode, 0), priority);
			while(getc(stdin) != '\n')
			{
			
			}
		}
		else if(choice == '2')
		{
			while(getc(stdin) != '\n')
			{
			
			}
			break;
		}
		else if(choice == '3')
		{
			return 0;
		}
		else 
		{
			printf("Please select a valid option\n");
			while(getc(stdin) != '\n')
			{
			
			}
		}
	}
	Node* n = NULL;
	Patient* p = NULL;
	while(isEmpty(patients) != 0)
	{
		n = donePatients->list->head;
		p = peek(patients);
		if(strcmp(p->symptomCode, "CV") == 0)
		{
			curTime += 5;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "HN") == 0)
		{
			curTime += 3;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "EV") == 0)
		{
			curTime += 10;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "GI") == 0)
		{
			curTime += 2;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "MH") == 0)
		{
			curTime += 5;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "NC") == 0)
		{
			curTime += 5;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "EC") == 0)
		{
			curTime += 1;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "RC") == 0)
		{
			curTime += 1;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "SK") == 0)
		{
			curTime += 2;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "SA") == 0)
		{
			curTime += 7;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		else if(strcmp(p->symptomCode, "TR") == 0)
		{
			curTime += 4;
			while(n != NULL)
			{
				if(strcmp(getID((Patient*)n->data), p->ID) == 0)
				{
					setFinTime((Patient*)n->data, curTime);
					break;
				}
				n = n->next;
			}
			pop(patients);
		}
		//Time for the doctor to do paperwork
		curTime++;
	}
	printf("Pateint ID\tPriority\tSymptom Code\tTime Finished\n");  
	printForward(donePatients->list);
	destroy(patients);
	destroy(donePatients);
	printf("Please press enter to quit");
	getc(stdin);
	return 0;
}
	
