#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct patient {
    char* ID;
	int priorityValue;
	char* symptomCode;
	int finTime;
} Patient;

/**
 * creates a patient
 * @param  the Patient's ID
 * @param  the priority of the Patient
 * @param  the sympton code for the Patient
 * @param  the time the Patient left
 * @return       a dynamically created Patient.
 */
Patient* createPatient(char* ID, int priorityValue, char* symptomCode, int finTime);

char* getID(Patient* p);

int getProrityValue(Patient* p);

char* getSymptomCode(Patient* p);

int getFinTime(Patient* p);

void setFinTime(Patient* p, int time);

void printPatient(void *toBePrinted);

void deletePatient(void *toBeDeleted);

int comparePatient(const void *first,const void *second);
 
#endif
