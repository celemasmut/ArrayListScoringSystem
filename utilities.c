#include "utilities.h"

char subjects[]="arraySubjects.bin";

char passed[]="Passed.bin";

void insertRegisterToFile()
{
    fileRegister aux;
    int valid=0;
    char option;
    do
    {
        aux.student=student();
        printf("\nSubject: ");
        fflush(stdin);
        gets(aux.subject);
        saveRegisterToArch(subjects,aux);
        fflush(stdin);
        printf("\n ESC para salir..... ");
        fflush(stdin);
        option=getch();
    }
    while(option!=27);
}

void saveRegisterToArch(char archSubject[],fileRegister aux)
{
    FILE*arch=fopen(archSubject,"ab");
    if(arch)
    {
        fwrite(&aux,sizeof(fileRegister),1,arch);
    }
    fclose(arch);
}
int add2adl(cell adl[],fileRegister auxFR,int valid)
{
    nodo*aux=inicList();
    aux=createNewNodo(auxFR.student);
    int pos = looking4PosSubject(adl,auxFR.subject,valid);
    if(pos == -1)
    {
        valid=addSubject(adl,auxFR.subject,valid);
        pos=valid-1;
    }
    addInOrderByLnameDP(&(adl[pos].scorelist),aux);
    return valid;
}
int arch2Adl(cell adl[],int valid,int dim)
{
    FILE*arch=fopen(subjects,"rb");
    if(arch)
    {
        fileRegister aux;
        while((fread(&aux,sizeof(fileRegister),1,arch))>0 && valid<dim)
        {
            valid=add2adl(adl,aux,valid);
        }
        fclose(arch);

    }

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

int addSubject(cell adl[],char subject[],int valid)
{
    strcpy(adl[valid].subject,subject);
    adl[valid].scorelist=inicList();
    valid++;
    return valid;
}



int registerSubject(cell adl[],char subject[],int valid)
{
    int pos=looking4PosSubject(adl,subject,valid);
    if(pos == -1)
    {

        valid=addSubject(adl,subject,valid);
        pos=valid-1;
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

void showArchSubject()
{
    fileRegister aux;
    FILE *regisTTer=fopen(subjects,"rb");
    while((fread(&aux,sizeof(fileRegister),1,regisTTer)) > 0)
    {
        showregister(aux);
    }
    fclose(regisTTer);
}

void showregister(fileRegister aux)
{
    showStudent(aux.student);
    printf("\nSubject: %s",aux.subject);
}
void showAdl(cell adl[],int valid)
{
    int index;
    for(index=0;index<valid;index++)
    {
        printf("\n\nSubject: %s",adl[index].subject);
        showList(adl[index].scorelist);
    }
}

int fromAdl2ArchPassed(cell adl[],int valid)
{
    int index;
    int tot=0;
    for(index=0;index<valid;index++)
    {
        nodo*auxList=adl[index].scorelist;
        while(auxList)
        {
            if(auxList->dat.score >= 6)
            {
                fileRegister aux;
                aux.student=auxList->dat;
                strcpy(aux.subject,adl[index].subject);
                saveRegisterPassedToArch(passed,aux);
                tot++;
            }
            auxList=auxList->next;
        }
    }
    return tot;
}
void saveRegisterPassedToArch(char archPassed[],fileRegister aux)
{
    FILE*arch=fopen(archPassed,"ab");
    if(arch)
    {
        fwrite(&aux,sizeof(fileRegister),1,arch);
    }
    fclose(arch);
}
