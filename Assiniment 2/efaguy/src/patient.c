#include <stdio.h>
#include <stdlib.h>
#include "../includes/patient.h"

/**
 * creates a patient
 * @param  the Patient's ID
 * @param  the priority of the Patient
 * @param  the sympton code for the Patient
 * @param  the time the Patient left
 * @return       a dynamically created Patient.
 */
Patient* createPatient(char* ID, int priorityValue, char* symptomCode, int finTime)
{
	Patient* p = malloc(sizeof(Patient));
	p->ID = ID;
	p->priorityValue = priorityValue;
	p->symptomCode = symptomCode;
	p->finTime = finTime;
	return p;
}

char* getID(Patient* p)
{
	return p->ID;
}

int getProrityValue(Patient* p)
{
		return p->priorityValue;
}

char* getSymptomCode(Patient* p)
{
	return p->symptomCode;
}

int getFinTime(Patient* p)
{
	return p->finTime;
}

void setFinTime(Patient* p, int time)
{
	p->finTime = time;
}

void printPatient(void *toBePrinted)
{
	Patient* p = (Patient*)toBePrinted;
	printf("%s\t\t%d\t\t%s\t\t%d\n",p->ID, p->priorityValue, p->symptomCode, p->finTime);
}

void deletePatient(void *toBeDeleted)
{
	Patient *p = (Patient*)toBeDeleted;
	char* ID = p->ID;
	char* code = p->symptomCode;
	free(ID);
	free(code);
	free(p);
}

int comparePatient(const void *first,const void *second)
{
	Patient* p1 = (Patient*)first;
	Patient* p2 = (Patient*)second;
	
	if(p1->priorityValue > p2->priorityValue)
	{
		return 1;
	}
	else if (p1->priorityValue < p2->priorityValue)
	{
		return -1;
	}
	else if (p1->priorityValue == p2->priorityValue)
	{
		return 0;
	}
	return 0;
} 
