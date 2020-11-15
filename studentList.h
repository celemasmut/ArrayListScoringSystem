#ifndef STUDENTLIST_H_INCLUDED
#define STUDENTLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentScore.h"

typedef struct _nodo {
   studentScore dat;
   struct _nodo *next;
} nodo;

nodo* inicList();
nodo* createNewNodo(studentScore e);
void addAtFirstDP(nodo**lista,nodo*newNodo);
void addInOrderByLnameDP(nodo**list,nodo*newNodo);
void showNodo(nodo* studentNodo);
void showRecursiveList(nodo*list);
int sumScoreRecursiveList(nodo*list);
void eraseSpecificNodoByFileDP(nodo**list, char file[]);
void eraseListaDP(nodo** list);


#endif // STUDENTLIST_H_INCLUDED
