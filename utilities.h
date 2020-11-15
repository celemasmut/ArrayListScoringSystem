#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include "studentList.h"
typedef struct {
    char subject[30];
    nodo*scorelist;
} cell;

typedef struct {
   int score;
   int file;
   char LNamendName[30];
   char subject[30];
} fileRegister;

int addAdl(cell adl[],int valid,nodo*stList);
int looking4PosSubject(cell adl[],char subject[],int valid);
int addSubject(cell adl[],char subject,int valid);
int addScoreToList(cell adl[],int valid);
int registerSubject(cell adl[],char subject,int valid,nodo*stList);

#endif // UTILITIES_H_INCLUDED
