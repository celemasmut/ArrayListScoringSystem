#include "utilities.h"

int addAdl(cell adl[],int valid,nodo*stList)
{
    char op;
    char subject[20];
    do
    {
        printf("\nSubject: ");
        gets(subject);
        valid=registerSubject(adl,subject,valid,stList);
        printf("\nESC para salir");
        fflush(stdin);
        gets(op);
    }
    while(op!=27);
    return valid;
}

int looking4PosSubject(cell adl[],char subject[],int valid)
{
    int pos=-1;
    int index=0;
    while(index < valid && pos==-1)
    {
        if(strcmpi(adl[index].subject, subject)==0)
        {
            pos=index;
        }
        index++;
    }
    return pos;
}

int addSubject(cell adl[],char subject,int valid)
{
    strcpy(adl[valid].subject,subject);
    valid++;
    return valid;
}

int registerSubject(cell adl[],char subject,int valid,nodo*stList)
{
    int pos=looking4PosSubject(adl,subject,valid);
    if(pos == -1)
    {
        valid=addSubject(adl,subject,valid);
        pos=valid-1;
    }
    while(stList)
    {
        addAtFirstDP(&adl[pos].scorelist,stList);
        stList->next;
    }
    return valid;
}

int addScoreToList(cell adl[],int valid)
{
    while(adl[valid].scorelist)
    {
        showNodo(adl[valid].scorelist);
        adl[valid].scorelist->dat.score=insertScore(adl[valid].scorelist);
    }
}
