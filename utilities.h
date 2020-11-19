#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include "studentList.h"


typedef struct {
    char subject[30];
    nodo*scorelist;
} cell;

typedef struct {
   studentScore student;
   char subject[30];
} fileRegister;

void insertRegisterToFile();
void saveRegisterToArch(char archSubject[],fileRegister aux);
int add2adl(cell adl[],fileRegister auxFR,int valid);
int arch2Adl(cell adl[],int valid,int dim);
void showArchSubject();
void showregister(fileRegister aux);
int looking4PosSubject(cell adl[],char subject[],int valid);
int addSubject(cell adl[],char subject[],int valid);
int addScoreToList(cell adl[],int valid);
int registerSubject(cell adl[],char subject[],int valid);
int fromAdl2ArchPassed(cell adl[],int valid);
void saveRegisterPassedToArch(char archPassed[],fileRegister aux);
void showAdl(cell adl[],int valid);

#endif // UTILITIES_H_INCLUDED
